#include "GameVictoryAlert.h"
#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
#include "GameTextInfo.h"  
#include "GameSamsung.h"
namespace bubble_second {
    GameVictoryAlert::GameVictoryAlert()
    {
    }

    GameVictoryAlert::~GameVictoryAlert()
    {
    }

    GameVictoryAlert * bubble_second::GameVictoryAlert::create(int level, int score, int start_numble)
    {
        GameVictoryAlert *pRet = new(std::nothrow) GameVictoryAlert();
        if (pRet && pRet->init(level, score, start_numble))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    bool GameVictoryAlert::init(int level, int score, int start_numble)
    {
        if (!GameBaseAlert::init())
        {
            return false;
        }
        //this->addBackground();
        this->addButtonItem();
        this->addRewardsShow();
        this->addTopLabel(level);
        this->addFlashLight();
        this->setNextCallback([=](cocos2d::Ref*) {
        });
        this->addSamsung(start_numble);
        this->addScoreLabel(score);
        return true;
    }

    //void GameVictoryAlert::addBackground()
    //{
    //    //背后的大背景
    //    cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH);
    //    this->addChild(bg);
    //    //上面的小背景
    //    cocos2d::Sprite* top_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH);
    //    cocos2d::Rect rect = bg->getBoundingBox();
    //    top_bg->setPosition(0.0f, rect.size.height / 2);
    //    top_bg->setTag(GAME_ALERT_TOP_BACKGROUND_TAG);
    //    this->addChild(top_bg);
    //}

    void GameVictoryAlert::addButtonItem()
    {
        SpriteTextureController* sp_controller = SpriteTextureController::getInstance();
        cocos2d::Vector<cocos2d::MenuItem*> item_array;
        {//重玩按钮
            replay_item_ = sp_controller->createMenuItemSprite(GAME_PAUSE_ALERT_RESTART_BUTTON_PATH);
            replay_item_->setPosition(GAME_VICTOR_ALERT_REPLAY_POSITION);
            item_array.pushBack(replay_item_);
        }
        {//商城按钮
            store_item_ = sp_controller->createMenuItemSprite(GAME_ALERT_STORE_BUTTON_PATH);
            store_item_->setPosition(GAME_VICTOR_ALERT_STORE_POSITION);
            item_array.pushBack(store_item_);
        }
        {//继续按钮
            next_item_ = sp_controller->createMenuItemSprite(GAME_VICTORY_ALERT_NEXT_BUTTON_PATH);
            next_item_->setPosition(GAME_VICTOR_ALERT_NEXT_POSITION);
            item_array.pushBack(next_item_);
        }
        cocos2d::Menu* menu = cocos2d::Menu::createWithArray(item_array);
        menu->setPosition(GAME_PAUSE_ALERT_BOTTOM_MENU_POSITION);
        this->addChild(menu, 1);
    }

    void GameVictoryAlert::addRewardsShow()
    {
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH);
        bg->setPosition(GAME_VICTORY_ALERT_REWARDS_BACKGROUND_POSITION);
        this->addChild(bg, 1);

        cocos2d::Size bg_size = bg->getContentSize();
        //奖励:
        cocos2d::Label* rewards_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_REWARDS_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        rewards_label->setPosition(bg_size.width*GAME_TEXT_REWARDS_LABEL_POSITION_PERCENT_X, bg_size.height / 2);
        rewards_label->setOpacity(GAME_TEXT_REWARDS_LABEL_OPACITY);
        bg->addChild(rewards_label);

        cocos2d::Sprite* coin = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_COIN_PATH);
        coin->setPosition(bg_size.width*GAME_VICTORY_ALERT_COIN_POSITION_PERCENT_X, bg_size.height / 2);
        bg->addChild(coin);

        cocos2d::Sprite* fatigue = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_FATIGUE_PATH);
        fatigue->setPosition(bg_size.width*GAME_VICTORY_ALERT_FATIGUE_POSITION_PERCENT_X, bg_size.height / 2);
        bg->addChild(fatigue);

        cocos2d::Label* add_score_label = cocos2d::Label::createWithSystemFont("180", "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        add_score_label->setPosition(bg_size.width*GAME_VICTORY_ALERT_ADD_SCORE_LABEL_POSITION_PERCENT_X, bg_size.height / 2);
        bg->addChild(add_score_label);

        cocos2d::Label* add_fatigue_label = cocos2d::Label::createWithSystemFont("+1", "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        add_fatigue_label->setPosition(bg_size.width*GAME_VICTORY_ALERT_ADD_FATIGUE_LABEL_POSITION_PERCENT_X, bg_size.height / 2);
        bg->addChild(add_fatigue_label);
    }

    void GameVictoryAlert::addTopLabel(int numble)
    {
        //文字
        std::string str1 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_1_KEY);
        std::string str2 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_2_KEY);
        char str[20];
        sprintf(str, "%s  %d  %s", str1.c_str(), numble, str2.c_str());
        cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(str, "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
        this->addChild(top_label);
    }

    void GameVictoryAlert::addFlashLight()
    {
        cocos2d::Sprite* flash_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_VICTORY_ALERT_FLASH_LIGHT_BACKGROUND_PATH);
        this->addChild(flash_bg);

        cocos2d::Sprite* flash_light = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_VICTORY_ALERT_FLASH_LIGHT_PATH);
        this->addChild(flash_light);
        cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(GAME_VICTORY_ALERT_FLASH_LIGHT_ROTATEBY_DURATION, GAME_VICTORY_ALERT_FLASH_LIGHT_ROTATEBY_DELTAANGLE);
        flash_light->runAction(cocos2d::RepeatForever::create(rotate));
    }

    void GameVictoryAlert::addSamsung(int numble)
    {
        GameSamsung* samsung = GameSamsung::createWithNumble(numble);
        samsung->setPosition(GAME_VICTORY_ALERT_SAMSUNG_POSITION);
        this->addChild(samsung);
    }

    void GameVictoryAlert::addScoreLabel(int score)
    {
        cocos2d::Node* node = cocos2d::Node::create();
        node->setPosition(GAME_VICTORY_ALERT_SCORE_LABEL_POSITION);
        this->addChild(node);
        char str[20];
        sprintf(str, "%d", score);
        cocos2d::Label* score_label = cocos2d::Label::createWithSystemFont(str, "", GAME_VICTORY_ALERT_SCORENUMBLE_LABEL_FONTSIZE);
        score_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        //score_label->setPositionY(-50);
        node->addChild(score_label);

        cocos2d::Label* text_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_SCORE_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        text_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        text_label->setPosition(GAME_VICTORY_ALERT_SCORE_LABEL_TEXT_POSITION);
        node->addChild(text_label);
    }

    void GameVictoryAlert::setReplayCallback(const cocos2d::ccMenuCallback & callback)
    {
        replay_item_->setCallback(callback);
    }

    void GameVictoryAlert::setNextCallback(const cocos2d::ccMenuCallback & callback)
    {
        next_item_->setCallback(callback);
    }
}