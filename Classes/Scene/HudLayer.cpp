#include "HudLayer.h"

const float PAUSE_MENU_POS_X = 460;
const float PAUSE_MENU_POS_Y = 300;

const float JOYSTICK_POS_X = 50;
const float JOYSTICK_POS_Y = 50;
const float JOYSTICK_DEAD_RADIUS = 10;
const float JOYSTICK_THRESHOLD = 0.4f;

const float BTN_A_POS_X = 430;
const float BTN_A_POS_Y = 50;

HudLayer::HudLayer()
{
	CCMenuItemSprite* btn_pause = CCMenuItemSprite::create(
		CCSprite::createWithSpriteFrameName("CloseNormal.png"), 
		CCSprite::createWithSpriteFrameName("CloseSelected.png"), 
		this, menu_selector(HudLayer::menuPauseCallback));
	btn_pause->setPosition(CCPointZero);
	CCMenu* menu_pause = CCMenu::createWithItem(btn_pause);
	menu_pause->setPosition(ccp(PAUSE_MENU_POS_X, PAUSE_MENU_POS_Y));
	this->addChild(menu_pause);

	mJoystick = NULL;
	mJoystick = new SneakyJoystick();
	mJoystick->initWithRect(CCRectZero);
	mJoystick->setAutoCenter(true);
	mJoystick->setHasDeadzone(true);
	mJoystick->setDeadRadius(JOYSTICK_DEAD_RADIUS);
	SneakyJoystickSkinnedBase* jstickSkin = new SneakyJoystickSkinnedBase();
	jstickSkin->autorelease();
	jstickSkin->init();
	jstickSkin->setBackgroundSprite(CCSprite::createWithSpriteFrameName("JoyStick-base.png"));
	jstickSkin->setThumbSprite(CCSprite::createWithSpriteFrameName("JoyStick-thumb.png"));
	//jstickSkin->getThumbSprite()->setScale(0.5f);
	jstickSkin->setPosition(ccp(JOYSTICK_POS_X, JOYSTICK_POS_Y));
	jstickSkin->setJoystick(mJoystick);
	this->addChild(jstickSkin);

	mButtonA = NULL;
	mButtonA = new SneakyButton();
	mButtonA->initWithRect(CCRectZero);
	mButtonA->setIsToggleable(false);
	mButtonA->setIsHoldable(true);
	SneakyButtonSkinnedBase* btnASkin = new SneakyButtonSkinnedBase();
	btnASkin->autorelease();
	btnASkin->init();
	btnASkin->setPosition(ccp(BTN_A_POS_X, BTN_A_POS_Y));
	btnASkin->setDefaultSprite(CCSprite::createWithSpriteFrameName("button-default.png"));
	btnASkin->setPressSprite(CCSprite::createWithSpriteFrameName("button-pressed.png"));
	btnASkin->setActivatedSprite(CCSprite::createWithSpriteFrameName("button-activated.png"));
	//btnASkin->setDisabledSprite(CCSprite::createWithSpriteFrameName("button-disabled.png"));
	btnASkin->setButton(mButtonA);
	this->addChild(btnASkin);

	init();
}

bool HudLayer::init()
{
	//CCLayer::init();
	return true;
}

HudLayer::~HudLayer()
{
	delete mButtonA;
	delete mJoystick;
}

InDirState HudLayer::getInDirLRState()
{
	bool left, right;
	CCPoint velocity = mJoystick->getVelocity();

	left = (velocity.x <= -JOYSTICK_THRESHOLD ? true : false);
	right = (velocity.x >= JOYSTICK_THRESHOLD ? true : false);

	InDirState retState = IN_DIR_NO_PRESSED;
	if (left)
		retState = IN_DIR_LEFT;
	else if (right)
		retState = IN_DIR_RIGHT;
	else
		retState = IN_DIR_NO_PRESSED;

	return retState;
}

InDirState HudLayer::getInDirUDState()
{
	bool up, down;
	CCPoint velocity = mJoystick->getVelocity();

	up = (velocity.y >= JOYSTICK_THRESHOLD ? true : false);
	down = (velocity.y <= -JOYSTICK_THRESHOLD ? true : false);

	InDirState retState = IN_DIR_NO_PRESSED;
	if (up)
		retState = IN_DIR_UP;
	else if (down)
		retState = IN_DIR_DOWN;
	else
		retState = IN_DIR_NO_PRESSED;

	return retState;

}

InBtnState HudLayer::getInBtnState()
{
	InBtnState retState = IN_BTN_NO_PRESSED;

	if (mButtonA->getIsActive())
		retState = IN_BTN_PRESSED;

	return retState;
}

void HudLayer::menuPauseCallback(CCObject* pSender)
{
}