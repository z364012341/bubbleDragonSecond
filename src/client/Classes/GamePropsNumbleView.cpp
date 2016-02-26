#include "GamePropsNumbleView.h"
#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
namespace bubble_second {
    GamePropsNumbleView::GamePropsNumbleView()
    {
    }


    GamePropsNumbleView::~GamePropsNumbleView()
    {
    }

    void GamePropsNumbleView::selected()
    {
        //background_->setVisible(false);
        if (this->isNoProps())
        {
            return;
        }
        props_label_->setVisible(selected_flag_);
        selected_flag_ = !selected_flag_;
        tick_->setVisible(selected_flag_);
        //this->updateNumbleLabel();
    }

    bool GamePropsNumbleView::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        numble_value_ = 1;
        this->addBackground();
        this->addLabel();
        this->addTickTexture();
        this->addAdditionButton();
        this->updateNumbleLabel();
        //this->selected();
        return true;
    }
    void GamePropsNumbleView::addBackground()
    {
        background_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_NUMBLE_DISABLED_PATH);
        background_->setScale(GAME_PROPS_NUMBLE_VIEW_BACKGROUND_SCALE);
        this->addChild(background_);
    }
    void GamePropsNumbleView::addLabel()
    {   
        props_label_ = cocos2d::Label::createWithSystemFont(numble_value_.asString(), "", ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE);
        this->addChild(props_label_);
    }
    void GamePropsNumbleView::addAdditionButton()
    {
        addition_item_ = SpriteTextureController::getInstance()->createMenuItemSprite(PROPS_NUMBLE_ENABLED_PATH);
        addition_item_->setScale(GAME_PROPS_NUMBLE_VIEW_BACKGROUND_SCALE);
        //addition_item_->setCallback([=](cocos2d::Ref*) {
        //    CCLOG("!!!!!!!!!!!!!!!!!!!!!!");
        //});
        addition_item_->setPosition(-2.0f, 1.7f);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(addition_item_);
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu, 1);
    }
    void GamePropsNumbleView::addTickTexture()
    {
        tick_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PROPS_NUMBLE_VIEW_TICK_PATH);
        tick_->setPositionY(GAME_PROPS_NUMBLE_VIEW_TICK_POS_Y);
        this->addChild(tick_);
        tick_->setVisible(selected_flag_);
    }
    void GamePropsNumbleView::updateNumbleLabel()
    {
        props_label_->setString(numble_value_.asString());
        bool flag = isNoProps();
        addition_item_->setVisible(flag);
        background_->setVisible(!flag);
        //props_label_->setVisible(!flag);
        //tick_->setVisible(!flag);
    }
    bool GamePropsNumbleView::isNoProps()
    {
        return numble_value_.asInt() == 0;
    }
}