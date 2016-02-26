#include "GameDefeatBuyPropsAlert.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "CenteredMenuItemSprite.h"
namespace bubble_second {
    GameDefeatBuyPropsAlert::GameDefeatBuyPropsAlert()
    {
    }


    GameDefeatBuyPropsAlert::~GameDefeatBuyPropsAlert()
    {
    }

    void GameDefeatBuyPropsAlert::setContinueCallback(const cocos2d::ccMenuCallback & callback)
    {
        continue_item_->setCallback(callback);
    }

    bool GameDefeatBuyPropsAlert::init()
    {
        if (!GameBaseAlert::init())
        {
            return false;
        }
        this->addTopLabel();
        this->addButtonItem();
        this->addPropsItem();
        this->addDescriptionLabel();
        return true;
    }
    void GameDefeatBuyPropsAlert::addTopLabel()
    {
        //文字
        cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_BUY_BUBBLE_KEY), "Arial", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
        this->addChild(top_label);
    }
    //void GameDefeatBuyPropsAlert::addBackground()
    //{
    //    //背后的大背景
    //    cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_BACKGROUND_PATH);
    //    this->addChild(bg);
    //    //上面的小背景
    //    cocos2d::Sprite* top_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH);
    //    cocos2d::Rect rect = bg->getBoundingBox();
    //    top_bg->setPosition(0.0f, rect.size.height / 2);
    //    this->addChild(top_bg);
    //    //文字
    //    cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_BUY_BUBBLE_KEY), "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
    //    top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
    //    top_label->setPosition(top_bg->getPosition());
    //    this->addChild(top_label);
    //}
    void GameDefeatBuyPropsAlert::addButtonItem()
    {
        {//x按钮
            this->addCancelButton();
        }
        //继续旋钮
        {
            continue_item_ = SpriteTextureController::getInstance()->createMenuItemSprite(GAME_ALERT_CONTINUE_BUTTON_PATH);
            cocos2d::Menu* menu = cocos2d::Menu::createWithItem(continue_item_);
            menu->setPosition(0.0f, -200.0f);
            this->addChild(menu);
        }
    }
    void GameDefeatBuyPropsAlert::addPropsItem()
    {
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH);
        this->addChild(bg);

        cocos2d::Size bg_size = bg->getContentSize();
        cocos2d::Sprite* item = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_COMMODITY_TEN_BUBBLE_PATH);
        item->setPosition(bg_size.width*0.3f, bg_size.height/2);
        bg->addChild(item);

        cocos2d::Sprite* price_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_ALERT_COMMODITY_TEN_BUBBLE_PRICE_BACKGROUND_PATH);
        price_bg->setPosition(bg_size.width*0.6f, bg_size.height / 2);
        price_bg->setOpacity(180);
        price_bg->setScaleY(0.8f);
        price_bg->setColor(cocos2d::Color3B::GRAY);
        bg->addChild(price_bg);

        cocos2d::Size price_bg_size = price_bg->getContentSize();
        cocos2d::Sprite* diamond = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_DIAMOND_PATH);
        diamond->setPosition(price_bg_size.width*0.3f, price_bg_size.height / 2);
        diamond->setScaleY(2 - price_bg->getScaleY());
        price_bg->addChild(diamond);

        cocos2d::Label* numble_label = cocos2d::Label::createWithSystemFont(
            GameTextInfo::getInstance()->getCommodityDiamondNumbleWithKey(COMMODITY_ADD_10_BUBBLE_KEY), "Arial", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        numble_label->setPosition(price_bg_size.width*0.65f, price_bg_size.height / 2);
        numble_label->setScaleY(2 - price_bg->getScaleY());
        price_bg->addChild(numble_label);
    }

    void GameDefeatBuyPropsAlert::addDescriptionLabel()
    {
        cocos2d::Label* numble_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_BUY_BUBBLE_LABEL_KEY), "",
            GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_FONTSIZE, GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_DIMENSIONS, cocos2d::TextHAlignment::CENTER);
        numble_label->setTextColor(GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_COLOR);
        numble_label->setPosition(GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_POSITION);
        this->addChild(numble_label);
    }
}