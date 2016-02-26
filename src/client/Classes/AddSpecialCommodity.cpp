#include "AddSpecialCommodity.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"

namespace bubble_second {
    AddSpecialCommodity::AddSpecialCommodity()
    {
    }


    AddSpecialCommodity::~AddSpecialCommodity()
    {
    }
    bool AddSpecialCommodity::init()
    {
        if (!EnterGamePropsView::init(SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_ADD_SPECIAL_BUBBLE_PROPS_PATH)))
        {
            return false;
        }
        this->addCostView(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(COMMODITY_ADD_SPECIAL_KEY));
        this->setName(ADD_SPECIAL_COMMODITY_NAME);
        return true;
    }
}