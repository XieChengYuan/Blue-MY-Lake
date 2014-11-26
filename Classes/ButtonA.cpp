#include "ButtonA.h"
#include "Animation.h"//$

//update:2014-9-26 01:59:07

bool ButtonA::init()
{
	return Button::init();
}
//�����ťͼ�����ұ��ǰ��µ�
void ButtonA::initSprite()
{
	CCTexture2D* HumanEntityTexture=CCTextureCache::sharedTextureCache()->addImage(BUTTONA_IMG_PATH);
	buttonImg=CCSprite::createWithTexture(HumanEntityTexture);
	int aa=buttonImg->getContentSize().height;
	buttonImg->setTextureRect(CCRectMake(0,0,aa,aa));
	buttonImg->setTag(IMGSP);addChild(buttonImg);
}

void ButtonA::ccTouchesBegan(CCSet* pTouches, CCEvent *pEvent)
{
	if(!enable)return;
	//�жϰ�����ťľ��
	CCPoint TouchesLocation = getTouchPos(pTouches);
	CCRect buttonRect=getBoundingBox();
	if(!buttonRect.containsPoint(TouchesLocation))return;

	//��ť������Ӧ
	int aa=buttonImg->getContentSize().height;
	buttonImg->setTextureRect(CCRectMake(aa*1,0,aa,aa));

	//����������Ӧ
	if(controllerListener!=NULL&&enable)
	{
		controllerListener->respond(0);
		if(controllerListener->hasTouchEnded())
		{
			this->setControllerListener(controllerListener->next);
			this->enableDirButton();
		}
	}
	//���û�м���������Ӣ�۾�ֹ
	else if(!hero->isHeroWalking)
	{
		CCPoint facingTile = hero->getHeroTilePos()+
			ccp((hero->move/(hero->map->getTileSize().height)).x,
			-(hero->move/(hero->map->getTileSize().height)).y);
		
		int tileGid = hero->map->layerNamed(EVENT_MLYR)->tileGIDAt(facingTile); 
		if (tileGid)
		{
			CCDictionary *properties = hero->map->propertiesForGID(tileGid);
			if (properties)
			{
				const CCString *eventScene = properties->valueForKey("atrg");
				//·���¼�
				if(!eventScene->compare("road sign"))
				{
					disableDirButton();
					this->setControllerListener(bigwindow);//
					bigwindow->load(hero->map,properties);//
				}
				//�����л��¼�inte
				else if(!eventScene->compare("change scene"))
				{
					//
					CCDirector::sharedDirector()->pushScene(StoryWorld::scene());
				}
				else if(!eventScene->compare("talkative man"))
				{
					disableDirButton();

					int manID=(properties->valueForKey("id"))->intValue();
					if(manID>MARK)manID=manID-MARK+hero->map->cturnNPC;
					ControllerListener* man=hero->map->NPCs[manID];
					diawindow->setControllerListener(man);
					man->respond(3-hero->dir);

					this->setControllerListener(diawindow);//
					diawindow->load(hero->map,properties);//
					diawindow->respond();
				}
				else if(!eventScene->compare("bloody"))
					hero->map->layerNamed(WATER_MLYR)->setVisible(false);
			}
		}
	}
	//else if(!doShrink)hero->speed=3.0f;//$
	//if(!hero->isHeroWalking&&!doShrink)hero->speed=3.0f;//$
	return;
}

void ButtonA::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent)
{
	buttonImg->setTextureRect(CCRectMake(0,0,50,50));
	//hero->speed=1.0f;//$
}

void ButtonA::setPointers(Hero* hero,DiaWindow* diawindow,BigWindow* bigwindow)
{
	this->hero=hero;
	this->diawindow=diawindow;
	this->bigwindow=bigwindow;
}

void ButtonA::disableDirButton()
{
	disaDistr=0*BUTTONA+1*DIRBUTTON;
}

void ButtonA::enableDirButton()
{
	disaDistr=0*BUTTONA+0*DIRBUTTON;
}