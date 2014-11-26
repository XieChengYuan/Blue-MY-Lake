#ifndef _HUMAN_ENTITY_H_
#define _HUMAN_ENTITY_H_

#include "cocos2d.h"
#include "Entity.h"
#include "ControllerListener.h"
#include "AppMacros.h"
using namespace cocos2d;

//update 20140925.2316

class HumanEntity : public Entity, public ControllerListener
{
public:
	void setID(int id);
public:
	virtual void initSprite();
	virtual void setFaceDirection(int dir);
	virtual CCAnimation* createAnimationForDirection(int dirc);
	virtual void initAnim(int dir);
	virtual void goWalking(float dt);
	virtual void respond(int dir);
	static void IntToAddrForPNG(char addr[],int len,int n);
public:
	int id;
	int dir;
};

//��ʼ��id
//�Զ�initSprite��Animation��Anim
//goWalking������NPC����������ʼ���˶�״̬
//id����������ͼ


#endif