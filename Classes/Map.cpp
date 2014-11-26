#include "Map.h"
#include "cocos2d.h"
USING_NS_CC;

//update:2014-10-1 03:30:49

Map* Map::create()
{
    int mapNo = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey(MAPPROCESS_RCD);
	if(mapNo==MAP11)return Map::create(MAP11_PATH);//��ȡ��ͼ��map11
	else return Map::create(MAP12_PATH);//��ȡ��ͼ��map12	
}

Map* Map::create(const char *tmxFile)
{
    Map *pRet = new Map();
    if (pRet->initWithTMXFile(tmxFile))
    {
		/*CCArray* pchildrenArray = pRet->getChildren();
		CCSpriteBatchNode *child = NULL;
		CCObject *pobject = NULL;
		CCARRAY_FOREACH(pchildrenArray,pobject)
		{
		child = (CCSpriteBatchNode *)pobject;
		if (!child)
		break;
		child->getTexture()->setAntiAliasTexParameters();
		}
		*/
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

void Map::setGameStartPos()
{
	int x,y;
	x = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey(POSITIONX_RCD);
	y = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey(POSITIONY_RCD);
	
	//���õ�ͼλ��
	CCPoint tileBirthPoint=ccp(x,y);//@��ȡ��ʼλ��63,98
	this->setPosition(humanPosForTileMove(tileBirthPoint));
}

void Map::initNPC()
{
	//NPC
	CCTMXObjectGroup* objGroup=this->objectGroupNamed(INFORMATION_GRP);
	cturnNPC=initNPCPointer(objGroup);

	if (objGroup)
	{
		//����תȦ��С��
		CCDictionary *properties = objGroup->objectNamed(TURNINGMAN_OBJ);
		if (properties)
			createNPC(properties,TURNINGMAN_ATTNUM,0);
		//����վ�ŵ�С��
		properties = objGroup->objectNamed(STANDINGMAN_OBJ);
		if (properties)
			createNPC(properties,STANDINGMAN_ATTNUM,cturnNPC);
	}
}

void Map::createNPC(CCDictionary *properties,int type,int start)
{
	//��ȡ����
	const CCString *snnpc = properties->valueForKey(NNPC_ATT);
	int npcAtt[4];	char attName[]=NPCAX_ATT;
	int innpc=snnpc->intValue();int count=start;
	for(int i=0;i<innpc;i++)
	{
		attName[4]='x';
		for(int j=0;j<type;j++)
		{
			snnpc=properties->valueForKey(attName);
			npcAtt[j]= snnpc->intValue();
			attName[4]+=1;
		}
		//�������ԭ��תȦ��NPC
		HumanEntity* man;
		if(type==3)man=TurningMan::create(npcAtt[2]);
		else man=StandingMan::create(npcAtt[2]);
		if(type==4)
		{
			man->setFaceDirection(npcAtt[3]);
			man->dir=npcAtt[3];
		}
		this->addChild(man,4);
		this->NPCs[i+start]=man;
		if(type==3)man->setTag(TURNINGMAN_START+npcAtt[2]);
		else man->setTag(STANDINGMAN_START+npcAtt[2]);
		man->setPosition(positionFromTileCoord(ccp(npcAtt[0],npcAtt[1])));
		attName[3]+=1;
	}
}

int Map::initNPCPointer(CCTMXObjectGroup* objGroup)
{
	CCDictionary *properties1 = objGroup->objectNamed(TURNINGMAN_OBJ);
	int tinnpc = properties1->valueForKey(NNPC_ATT)->intValue();
	CCDictionary *properties2 = objGroup->objectNamed(STANDINGMAN_OBJ);
	int sinnpc = properties2->valueForKey(NNPC_ATT)->intValue();
	totalNPC=tinnpc+sinnpc;
	this->NPCs=new ControllerListener* [totalNPC];
	return tinnpc;
}

void Map::removeAllChildrenWithCleanup(bool cleanup)
{
	CCTMXTiledMap::removeAllChildrenWithCleanup(cleanup);
	//delete []NPCs;
}

Map* Map::crossMap(CCPoint tileBirthPoint,int mapNo)
{
	if(mapNo==MAP11)
		tileBirthPoint=ccp(2+3,tileBirthPoint.y);
	else
		tileBirthPoint=ccp(this->getMapSize().width-3-3,tileBirthPoint.y);
	this->setPosition(this->humanPosForTileMove(tileBirthPoint));
	initNPC();
	return this;
}


//�ڲ����ߺ���Tilemap����ת2dx����
CCPoint Map::positionFromTileCoord(CCPoint tileCoord)
{
	CCPoint pos=ccp(((tileCoord.x+0.5)*this->getTileSize().width),((this->getMapSize().height-
		tileCoord.y)*this->getTileSize().height+this->getTileSize().height*3/16));//վ�ڵذ����룡
	return pos;
}
//�ڲ����ߺ���2dx����תTilemap����
CCPoint Map::tileCoordFromPosition(CCPoint position)
{
	int x=position.x/this->getTileSize().width;
	int y=(((this->getMapSize().height-1)*this->getTileSize().height)-position.y)/this->getTileSize().height;
	return ccp(x,y);
}
//��ʼ����ͼʱ��ת������
CCPoint Map::humanPosForTileMove(CCPoint tileCoord)
{
	CCPoint deltaMiddle;
	deltaMiddle.x=(int)(CCDirector::sharedDirector()->getWinSize().width/2/this->getTileSize().width);
	deltaMiddle.y=this->getMapSize().height-(int)(CCDirector::sharedDirector()->getWinSize().height/2/this->getTileSize().height)-1;
	CCPoint position=tileCoord-deltaMiddle;//ccp(7,14);
	return ccp(-position.x*this->getTileSize().width,position.y*this->getTileSize().height);
}