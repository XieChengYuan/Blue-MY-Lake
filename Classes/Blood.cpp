﻿#include "GlobalPath.h"
#include "Blood.h"
USING_NS_CC;

bool Blood::init()
{
	return true;
}

void Blood::setBloodSlider()
{
	this->bloodSlider = CCControlSlider::create(CCSprite::create(BLOOD_BG_IMG_PATH),
										  CCSprite::create(BLOOD_IMG_PATH),
										  CCSprite::create(SLIDERTHUMB_IMG_PATH));
	this->addChild(bloodSlider,2);
	bloodSlider->setTouchEnabled(false);
}

void Blood::setSliderPosition(CCPoint pos)
{
	bloodSlider->setPosition(ccp(pos.x,pos.y));
}

void Blood::setTotalBlood(float total)
{
	bloodSlider->setMaximumValue(total);
	bloodSlider->setMinimumValue(0);
}

void Blood::setCurrentBlood(float currentHp)
{
	bloodSlider->setValue(currentHp);
}
