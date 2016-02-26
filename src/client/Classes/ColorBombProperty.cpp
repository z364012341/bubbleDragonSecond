#include "ColorBombProperty.h"
#include "SpriteTextureController.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    ColorBombProperty::ColorBombProperty()
    {
    }


    ColorBombProperty::~ColorBombProperty()
    {
    }

    void ColorBombProperty::useItem()
    {
        BaseProperty::useItem();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_BUBBLE_BOMB_PROPS, this);
    }

    void ColorBombProperty::cancelUseItem()
    {
        BaseProperty::cancelUseItem();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CANCEL_BUBBLE_BOMB_PROPS, this);
    }

    //void ColorBombProperty::haveUsedColorBombBubble(cocos2d::EventCustom*)
    //{
    //    this->setPropsState(kNotUsed);
    //}

    bool ColorBombProperty::init()
    {
        if (!BaseProperty::init())
        {
            return false;
        }
        this->setName(PROPS_COLOR_BOMB_NAME);
        this->initIconWithPath(PROPS_COLOR_BOMB_PATH);    
        return true;
    }
}