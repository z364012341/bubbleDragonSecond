#include "WoodenHammerProperty.h"
#include "WoodenHammerWeapon.h"
namespace bubble_second {
    WoodenHammerProperty::WoodenHammerProperty()
    {
    }


    WoodenHammerProperty::~WoodenHammerProperty()
    {
    }

    bool WoodenHammerProperty::init()
    {
        if (!BaseProperty::init())
        {
            return false;
        }
        this->setName(PROPS_WOODEN_HAMMER_NAME);
        this->initIconWithPath(PROPS_WOODEN_HAMMER_PATH);
        return true;
    }

    void WoodenHammerProperty::useItem()
    {
        BaseProperty::useItem();
        WoodenHammerWeapon* hammer = WoodenHammerWeapon::create();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_SELECTION_PROPS, hammer);
    }

    void WoodenHammerProperty::cancelUseItem()
    {
        BaseProperty::cancelUseItem();
        //::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CANCEL_SELECTION_PROPS, this);
    }
}