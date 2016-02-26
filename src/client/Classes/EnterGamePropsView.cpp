#include "EnterGamePropsView.h"
#include "SpriteTextureController.h"
#include "GamePropsNumbleView.h"
#include "GameTextInfo.h"
namespace bubble_second {
    EnterGamePropsView * EnterGamePropsView::create(cocos2d::Sprite * props)
    {
        EnterGamePropsView *pRet = new(std::nothrow) EnterGamePropsView();
        if (pRet && pRet->init(props))
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
    EnterGamePropsView::EnterGamePropsView()
    {
    }

    EnterGamePropsView::~EnterGamePropsView()
    {
    }

    void EnterGamePropsView::addMenuCallback(const cocos2d::ccMenuCallback & callback)
    {
        menu_callback_ = callback;
    }

    bool bubble_second::EnterGamePropsView::init(cocos2d::Sprite* props)
    {
        this->addBackground();
        this->addPropsTexture(props);
        this->addPropsNumbleView();
        return true;
    }

    void EnterGamePropsView::addBackground()
    {
        cocos2d::Sprite* normal_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_BACKGROUND_PATH);
        cocos2d::Sprite* select_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_BACKGROUND_PATH);
        background_ = cocos2d::MenuItemSprite::create(normal_sp, select_sp);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(background_);
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu);
    }

    void EnterGamePropsView::addPropsTexture(cocos2d::Sprite * props)
    {
        //props->setContentSize(background_->getContentSize());
        //cocos2d::Rect rect = background_->getBoundingBox();
        //props->setPosition(rect.size.width/2, rect.size.height/2);;
        this->addChild(props);
    }

    void EnterGamePropsView::addPropsNumbleView()
    {
        props_numble_view_ = GamePropsNumbleView::create();
        //cocos2d::Rect rect = background_->getBoundingBox();
        props_numble_view_->setPosition(50.0, -40.0);
        this->addChild(props_numble_view_);
        background_->setCallback([=](cocos2d::Ref* ref) {
            props_numble_view_->selected(); 
            //EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), !EnterPropsViewManager::getInstance()->getPropsSwitchEnable(this->getName()));
            if (menu_callback_)
            {
                menu_callback_(ref);
            }
        });
    }

    void EnterGamePropsView::addCostView(const cocos2d::Value& value)
    {
        props_value_ = value;
        cocos2d::Sprite* coin = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_COIN_PATH);
        coin->setPosition(-50.0f, -80.0f);
        this->addChild(coin);

        cocos2d::Label* cost_label = cocos2d::Label::createWithSystemFont(props_value_.asString(), "", ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE);
        cost_label->setPosition(10.0f, coin->getPositionY()+5);
        this->addChild(cost_label);
    }

}