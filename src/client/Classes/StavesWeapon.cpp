#include "StavesWeapon.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
namespace bubble_second {
    StavesWeapon::StavesWeapon()
    {
    }

    bool bubble_second::StavesWeapon::init()
    {
        if (!BaseWeapon::init())
        {
            return false;
        }
        SpriteTextureController::getInstance()->setSpriteTexture(PROPS_STAVES_PATH, this);
        this->setName(WEAPON_STAVES_NAME);
        return true;
    }


    StavesWeapon::~StavesWeapon()
    {
    }

    void bubble_second::StavesWeapon::attackBubble()
    {
        GamePlayController::getInstance()->disposeUseStaves();
    }
    bool StavesWeapon::inAttackRange(BubbleType color)
    {
        return color>=kNormalColorFirst && color <=kNormalColorLast;
    }
}