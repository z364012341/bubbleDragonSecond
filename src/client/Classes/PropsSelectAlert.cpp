#include "PropsSelectAlert.h"
#include "SpriteTextureController.h"
#include "SmartScaleController.h"
namespace bubble_second {
    PropsSelectAlert::PropsSelectAlert()
    {
    }

    PropsSelectAlert::~PropsSelectAlert()
    {
    }

    bool PropsSelectAlert::init()
    {
        //cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        //if (!cocos2d::LayerColor::initWithColor(PROPS_SELECT_ALERT_LAYER_COLOR, GAME_DESIGN_RESOLUTION_WIDTH, GAME_DESIGN_RESOLUTION_HEIGHT))
        //{
        //    return false;
        //}
        if (!cocos2d::Node::init())
        {
            return false;
        }
       
        //cocos2d::LayerColor* layer = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, PROPS_SELECT_ALERT_BACKGROUND_OPACITY), 
        //    GAME_DESIGN_RESOLUTION_WIDTH, GAME_DESIGN_RESOLUTION_HEIGHT);
        //this->addChild(layer);
        this->initPannel();
        //this->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        return true;
    }

    void PropsSelectAlert::initPannel()
    {
        using cocos2d::Sprite;
        {
            Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_SELECT_ALERT_BACKGROUND);
            bg->setPosition(PROPS_SELECT_ALERT_BACKGROUND_POS);
            this->addChild(bg);
        }
        {
            Sprite* confirm_btn_normal = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_SELECT_ALERT_CONFIRM);
            Sprite* confirm_btn_select = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_SELECT_ALERT_CONFIRM);
            confirm_btn_select->setScale(PROPS_SELECT_ALERT_BUTTON_SELECT_SCALE);
            cocos2d::MenuItemSprite* confirm_btn = cocos2d::MenuItemSprite::create(confirm_btn_normal, confirm_btn_select, [=](cocos2d::Ref*) {
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_PROPS_SELECT_ALERT_CONFIRM);
                this->removeFromParent();
            });
            confirm_btn->setPosition(cocos2d::Vec2(PROPS_SELECT_ALERT_BUTTON_X, 0));

            Sprite* cancel_btn_normal = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_SELECT_ALERT_CANCEL);
            Sprite* cancel_btn_select = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_SELECT_ALERT_CANCEL);
            cancel_btn_select->setScale(PROPS_SELECT_ALERT_BUTTON_SELECT_SCALE);
            cocos2d::MenuItemSprite* cancel_btn = cocos2d::MenuItemSprite::create(cancel_btn_normal, cancel_btn_select, [=](cocos2d::Ref*) {
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_PROPS_SELECT_ALERT_CANCEL);
                this->removeFromParent();
            });
            cancel_btn->setPosition(cocos2d::Vec2(-1*PROPS_SELECT_ALERT_BUTTON_X, 0));
            cocos2d::Menu* menu = cocos2d::Menu::create(cancel_btn, confirm_btn, nullptr);
            menu->setPosition(PROPS_SELECT_ALERT_BACKGROUND_POS);
            this->addChild(menu);
        }
    }
}