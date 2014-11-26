#include "TurningMan.h"

bool TurningMan::init()
{
	return true;
}

//����û��id�޷���ʼ����������setID�г�ʼ��
TurningMan* TurningMan::create(int id)
{
	TurningMan* man=create();
	man->setID(id);
	man->initSprite();
	man->initAnim(0);
	man->goWalking(0);
	return man;
}

void TurningMan::initAnim(int dir)
{
	CCAnimation* animation=createAnimationForDirection(-1);
	CCAnimate* anim=CCAnimate::create(animation);
	forever=CCRepeatForever::create(anim);
}

void TurningMan::goWalking(float dt)
{
	sprite->runAction(forever);
}

void TurningMan::respond(int dir)
{
	setFaceDirection(dir);
	sprite->stopAllActions();
}

void TurningMan::endRespond()
{
	sprite->resumeSchedulerAndActions();
}