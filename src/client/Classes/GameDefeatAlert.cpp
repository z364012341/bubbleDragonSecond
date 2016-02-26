#include "GameDefeatAlert.h"
#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
#include "GameTextInfo.h"
namespace bubble_second {
    GameDefeatAlert::GameDefeatAlert()
    {
    }

    GameDefeatAlert * bubble_second::GameDefeatAlert::createWithLevelNumble(int numble)
    {
        GameDefeatAlert *pRet = new(std::nothrow) GameDefeatAlert();
        if (pRet && pRet->initWithWithLevelNumble(numble))
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

    GameDefeatAlert::~GameDefeatAlert()
    {
    }

    bool GameDefeatAlert::initWithWithLevelNumble(int numble)
    {
        if (!GameBaseAlert::init())
        {
            return false;
        }
        //this->addBackground();
        this->addButtonItem();
        this->addDefeatCharactor();
        this->addTopLabel(numble);
        return true;
    }

    //void GameDefeatAlert::addBackground()
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
    void GameDefeatAlert::addButtonItem()
    {
        SpriteTextureController* sp_controller = SpriteTextureController::getInstance();
        cocos2d::Vector<cocos2d::MenuItem*> item_array;
        {
            //重玩按钮
            replay_item_ = sp_controller->createMenuItemSprite(GAME_PAUSE_ALERT_RESTART_BUTTON_PATH);
            replay_item_->setPosition(GAME_DEFEAT_ALERT_REPLAY_POSITION);
            item_array.pushBack(replay_item_);
            //商城按钮
            store_item_ = sp_controller->createMenuItemSprite(GAME_ALERT_STORE_BUTTON_PATH);
            store_item_->setPosition(GAME_DEFEAT_ALERT_STORE_POSITION);
            item_array.pushBack(store_item_);
            //{//继续按钮
            //    continue_item_ = sp_controller->createMenuItemSprite(GAME_PAUSE_ALERT_RESUME_BUTTON_PATH);
            //    continue_item_->setPositionX(GAME_PAUSE_ALERT_RESUME_BUTTON_POSITION_X);
            //    item_array.pushBack(continue_item_);
            //}
            cocos2d::Menu* menu = cocos2d::Menu::createWithArray(item_array);
            menu->setPosition(GAME_PAUSE_ALERT_BOTTOM_MENU_POSITION);
            this->addChild(menu);
        }
        {//x按钮
            //cancel_item_ = SpriteTextureController::getInstance()->createMenuItemSprite(GAME_ALERT_CANCEL_BUTTON_PATH);
            //cocos2d::Menu* menu = cocos2d::Menu::createWithItem(cancel_item_);
            //menu->setPosition(GAME_ALERT_CANCEL_BUTTON_POSITION);
            //this->addChild(menu);
            this->addCancelButton();
        }
    }

    void GameDefeatAlert::addDefeatCharactor()
    {
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_DEFEAT_ALERT_CHARACTOR_PATH);
        sp->setPosition(GAME_PAUSE_ALERT_DEFEAT_CHARACTOR_POSITION);
        sp->setScale(GAME_PAUSE_ALERT_DEFEAT_CHARACTOR_SCALE);
        this->addChild(sp);
    }

    void GameDefeatAlert::addTopLabel(int numble)
    {
        //文字
        std::string str1 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_1_KEY);
        std::string str2 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_2_KEY);
        cocos2d::Value num_val(numble);
        char str[20];
        sprintf(str, "%s  %d  %s", str1.c_str(), numble, str2.c_str());
        //std::string str = str1 + "  " + num_val.asString() + "  " + str2;
        cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(str, "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
        this->addChild(top_label);
    }

    void GameDefeatAlert::setReplayCallback(const cocos2d::ccMenuCallback & callback)
    {
        replay_item_->setCallback(callback);
    }

    //void GameDefeatAlert::setCancelCallback(const cocos2d::ccMenuCallback & callback)
    //{
    //    cancel_item_->setCallback(callback);
    //}
}