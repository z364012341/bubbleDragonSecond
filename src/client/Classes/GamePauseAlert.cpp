#include "GamePauseAlert.h"
#include "SpriteTextureController.h"
#include "BubbleSecondConstant.h"
#include "GameTextInfo.h"
#include "CenteredMenuItemSprite.h"
#include "GameVolControlView.h"
namespace bubble_second {
    GamePauseAlert::GamePauseAlert()
    {
    }

    GamePauseAlert::~GamePauseAlert()
    {
    }

    bool GamePauseAlert::init()
    {
        if (!GameBaseAlert::init())
        {
            return false;
        }
        this->addVolumeItem();
        this->addButtonItem();
        this->addTopLabel();
        return true;
    }

    void GamePauseAlert::addVolumeItem()
    {
        GameVolControlView* view = GameVolControlView::create();
        view->setPositionY(GAME_PAUSE_ALERT_VOL_POS_Y);
        this->addChild(view);
    }

    void GamePauseAlert::addButtonItem()
    {
        SpriteTextureController* sp_controller = SpriteTextureController::getInstance();
        cocos2d::Vector<cocos2d::MenuItem*> item_array;
        {//退出按钮
            return_item_ = sp_controller->createMenuItemSprite(GAME_PAUSE_ALERT_BACK_BUTTON_PATH);
            return_item_->setPositionX(GAME_PAUSE_ALERT_BACK_BUTTON_POSITION_X);
            item_array.pushBack(return_item_);
        }
        {//重玩按钮
            replay_item_ = sp_controller->createMenuItemSprite(GAME_PAUSE_ALERT_RESTART_BUTTON_PATH);
            item_array.pushBack(replay_item_);
        }
        {//继续按钮
            continue_item_ = sp_controller->createMenuItemSprite(GAME_PAUSE_ALERT_RESUME_BUTTON_PATH);
            continue_item_->setPositionX(GAME_PAUSE_ALERT_RESUME_BUTTON_POSITION_X);
            item_array.pushBack(continue_item_);
        }
        cocos2d::Menu* menu = cocos2d::Menu::createWithArray(item_array);
        menu->setPosition(GAME_PAUSE_ALERT_BOTTOM_MENU_POSITION);
        this->addChild(menu);
    }

    void GamePauseAlert::addBigBackground()
    {
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH);
        bg->setTag(GAME_ALERT_BIG_BACKGROUND_TAG);
        bg->setScaleY(GAME_PAUSE_ALERT_BACKGROUND_SCALE_Y);
        this->addChild(bg);
    }

    void GamePauseAlert::addTopLabel()
    {
        //文字
        cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_PAUSE_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
        this->addChild(top_label);
    }

    void GamePauseAlert::setReturnCallback(const cocos2d::ccMenuCallback & callback)
    {
        return_item_->setCallback(callback);
    }

    void GamePauseAlert::setReplayCallback(const cocos2d::ccMenuCallback & callback)
    {
        replay_item_->setCallback(callback);
    }

    void GamePauseAlert::setContinueCallback(const cocos2d::ccMenuCallback & callback)
    {
        continue_item_->setCallback(callback);
    }

    //void GamePauseAlert::addBackground()
    //{
    //    //背后的大背景
    //    cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_BACKGROUND_PATH);
    //    bg->setScaleY(GAME_PAUSE_ALERT_BACKGROUND_SCALE_Y);
    //    this->addChild(bg);
    //    //上面的小背景
    //    cocos2d::Sprite* top_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH);
    //    cocos2d::Rect rect = bg->getBoundingBox();
    //    top_bg->setPosition(0.0f, rect.size.height / 2);
    //    this->addChild(top_bg);
    //    //文字
    //    cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_PAUSE_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
    //    top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
    //    top_label->setPosition(top_bg->getPosition());
    //    this->addChild(top_label);
    //}

}