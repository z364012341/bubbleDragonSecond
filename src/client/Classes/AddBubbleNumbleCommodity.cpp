#include "AddBubbleNumbleCommodity.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
namespace bubble_second {
    AddBubbleNumbleCommodity::AddBubbleNumbleCommodity()
    {
    }


    AddBubbleNumbleCommodity::~AddBubbleNumbleCommodity()
    {
    }

    bool AddBubbleNumbleCommodity::init()
    {
        if (!EnterGamePropsView::init(SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_ADD_BUBBLE_PROPS_PATH)))
        {
            return false;
        }
        this->addCostView(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(COMMODITY_ADD_10_BUBBLE_KEY));
        this->setName(ADD_BUBBLE_NUMBLE_COMMODITY_NAME);
        return true;
    }
}