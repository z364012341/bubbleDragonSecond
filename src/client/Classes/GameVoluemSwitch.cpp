#include "GameVoluemSwitch.h"
#include "BubbleSecondConstant.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "SimpleControlSwitch.h"
#include "UserDataManager.h"
namespace bubble_second {
    GameVoluemSwitch::GameVoluemSwitch()
    {
    }


    GameVoluemSwitch::~GameVoluemSwitch()
    {
    }

    void GameVoluemSwitch::setSwitchState(bool flag)
    {
        vol_switch_->setSwitchState(flag);
    }

    void GameVoluemSwitch::setMenuCallback(const cocos2d::ccMenuCallback & callback)
    {
        vol_switch_->setMenuCallback(callback);
    }

    bool GameVoluemSwitch::getSwitchState()
    {
        return vol_switch_->getSwitchState();
    }

    bool GameVoluemSwitch::init()
    {
        SpriteTextureController* sp_controller = SpriteTextureController::getInstance();
        GameTextInfo* text_controller = GameTextInfo::getInstance();
        vol_switch_ = SimpleControlSwitch::create(
            sp_controller->createGameSpriteWithPath(GAME_PAUSE_ALERT_SIMPLE_SWITCH_MASKSPRITE_PATH),
            sp_controller->createGameSpriteWithPath(GAME_PAUSE_ALERT_VOLUME_SWITCH_THUMBSPRITE_PATH),
            cocos2d::Label::createWithSystemFont(text_controller->getTextInfoWithKey(GAME_TEXT_VOLUME_ON_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE),
            cocos2d::Label::createWithSystemFont(text_controller->getTextInfoWithKey(GAME_TEXT_VOLUME_OFF_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE)
            );
        this->addChild(vol_switch_);
        cocos2d::Sprite* bg_sp = sp_controller->createGameSpriteWithPath(GAME_PAUSE_ALERT_VOLUME_SWITCH_BACKGROUND_PATH);
        this->addChild(bg_sp, -1);
        return true;
    }
}