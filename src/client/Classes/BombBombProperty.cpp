#include "BombBombProperty.h"
namespace bubble_second {
    BombBombProperty::BombBombProperty()
    {
    }

    bool BombBombProperty::init()
    {
        if (!BaseProperty::init())
        {
            return false;
        }
        this->setName(PROPS_BOMB_BOMB_NAME);
        this->initIconWithPath(PROPS_BOMB_BOMB_PATH);
        //cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_SHUTED_COLOR_BOMB_BUBBLE, CC_CALLBACK_1(ColorBombProperty::haveUsedColorBombBubble, this));
        return true;
    }

    BombBombProperty::~BombBombProperty()
    {
    }

    void BombBombProperty::useItem()
    {
        BaseProperty::useItem();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_BUBBLE_BOMB_PROPS, this);
    }

    void BombBombProperty::cancelUseItem()
    {
        BaseProperty::cancelUseItem();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CANCEL_BUBBLE_BOMB_PROPS, this);
    }
}