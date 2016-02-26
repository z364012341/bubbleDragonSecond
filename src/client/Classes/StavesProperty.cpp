#include "StavesProperty.h"
#include "StavesWeapon.h"

namespace bubble_second {
    StavesProperty::StavesProperty()
    {
    }

    bool StavesProperty::init()
    {
        if (!BaseProperty::init())
        {
            return false;
        }
        this->setName(PROPS_STAVES_NAME);
        this->initIconWithPath(PROPS_STAVES_PATH);
        return true;
    }

    StavesProperty::~StavesProperty()
    {
    }

    void StavesProperty::useItem()
    {
        BaseProperty::useItem();
        StavesWeapon* staves = StavesWeapon::create();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_SELECTION_PROPS, staves);
    }

    void StavesProperty::cancelUseItem()
    {
        BaseProperty::cancelUseItem();
    }
}