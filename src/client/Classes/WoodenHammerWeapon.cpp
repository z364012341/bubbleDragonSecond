#include "WoodenHammerWeapon.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
namespace bubble_second {
    WoodenHammerWeapon::WoodenHammerWeapon()
    {
    }

    WoodenHammerWeapon::~WoodenHammerWeapon()
    {
    }

    void WoodenHammerWeapon::attackBubble()
    {
        GamePlayController::getInstance()->disposeUseWoodenHammer();
    }

    bool WoodenHammerWeapon::init()
    {
        if (!BaseWeapon::init())
        {
            return false;
        }
        SpriteTextureController::getInstance()->setSpriteTexture(PROPS_WOODEN_HAMMER_PATH, this);
        this->setName(WEAPON_WOODEN_HAMMER_NAME);
        return true;
    }
}