#include "AimingLineCommodity.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
namespace bubble_second {
    AimingLineCommodity::AimingLineCommodity()
    {
    }

    AimingLineCommodity::~AimingLineCommodity()
    {
    }

    bool AimingLineCommodity::init()
    {
        if (!EnterGamePropsView::init(SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_SIGHT_PROPS_PATH)))
        {
            return false;
        }
        this->addCostView(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(COMMODITY_AIMING_LINE_KEY));
        this->setName(AIMING_LINE_COMMODITY_NAME);
        return true;
    }
}