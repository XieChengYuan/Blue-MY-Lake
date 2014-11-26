#include "HelloWorldScene.h"
USING_NS_CC;

//last:20140924.2031
//update:20140925.2257
CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
	layer->setTag(HELLOWORLDLAYER);
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
        return false;

	//��ʼ��
	Map* map=initMap();
	initControlPanel(map);
	
	return true;
}






//��ʼ��Ӣ�ۺ͵�ͼ
Map* HelloWorld::initMap()
{
	//������ͼ
	Map* map=Map::create();
	map->setGameStartPos();
	map->initNPC();

	CCLayer* mapLayer=CCLayer::create();
	map->setTag(MAP);
	mapLayer->addChild(map);
	mapLayer->setTag(MAPLAYER);
	this->addChild(mapLayer);
	return map;
}

void HelloWorld::initControlPanel(Map* map)
{
	ControlPanel* panel=ControlPanel::create(map);
	panel->hero->setTag(HERO);
	this->getChildByTag(MAPLAYER)->addChild(panel->hero,3);
	this->addChild(panel,15);
}

