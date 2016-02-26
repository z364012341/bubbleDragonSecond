#include "GameVolControlView.h"
#include "SpriteTextureController.h"
#include "GameVoluemSwitch.h"
#include "UserDataManager.h"
namespace bubble_second {
    GameVolControlView::~GameVolControlView()
    {
    }
    void GameVolControlView::onExit()
    {
        cocos2d::Node::onExit();
        UserDataManager::getInstance()->setSoundEffect(effect_switch_->getSwitchState());
        UserDataManager::getInstance()->setGameMusicEnable(music_switch_->getSwitchState());
    }
    GameVolControlView::GameVolControlView()
    {
    }

    bool GameVolControlView::init()
    {
        this->addVolumeSwitch();
        return true;
    }

    void GameVolControlView::addVolumeSwitch()
    {
        SpriteTextureController* sp_controller = SpriteTextureController::getInstance();
        {
            //音效声音的图标
            cocos2d::Sprite* effect_icon = sp_controller->createGameSpriteWithPath(GAME_PAUSE_ALERT_EFFECT_ICON_PATH);
            effect_icon->setPosition(GAME_PAUSE_ALERT_EFFECT_ICON_POSITION);
            this->addChild(effect_icon);
            //音效开关
            effect_switch_ = GameVoluemSwitch::create();
            effect_switch_->setPosition(GAME_PAUSE_ALERT_EFFECT_SWITCH_POSITION_X, effect_icon->getPositionY());
            this->addChild(effect_switch_);
            effect_switch_->setSwitchState(UserDataManager::getInstance()->isSoundEffectEnable());
            //effect_switch_->setMenuCallback([=](cocos2d::Ref*) {
            //    //UserDataManager::getInstance()->setSoundEffect(effect_switch_->getSwitchState());
            //});
        }
        {
            //音乐图标
            cocos2d::Sprite* music_icon = sp_controller->createGameSpriteWithPath(GAME_PAUSE_ALERT_MUSIC_ICON_PATH);
            music_icon->setPosition(GAME_PAUSE_ALERT_EFFECT_ICON_POSITION.x, -GAME_PAUSE_ALERT_EFFECT_ICON_POSITION.y);
            this->addChild(music_icon);
            //音乐开关
            music_switch_ = GameVoluemSwitch::create();
            music_switch_->setPosition(GAME_PAUSE_ALERT_EFFECT_SWITCH_POSITION_X, music_icon->getPositionY());
            this->addChild(music_switch_);
            music_switch_->setSwitchState(UserDataManager::getInstance()->isGameMusicEnable());
            //music_switch_->setMenuCallback([=](cocos2d::Ref*) {
            //    /*UserDataManager::getInstance()->setGameMusicEnable(music_switch_->getSwitchState());*/
            //});
        }
    }

}