#include "BaseProperty.h"
#include "GamePlayController.h"
namespace bubble_second {
    BaseProperty::BaseProperty()
    {
    }

    BaseProperty::~BaseProperty()
    {
    }

    //bool BaseProperty::initWithName(const std::string& name)
    //{
    //    if (!Sprite::init())
    //    {
    //        return false;
    //    }
    //    //this->setName(name);
    //    //SpriteTextureController::getInstance()->setSpriteTexture("", this);
    //    return true;
    //}
    void BaseProperty::onExit()
    {
        Sprite::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_HAVE_USED_PROPS);
    }

    void BaseProperty::useItem()
    {
        use_state_ = kUsing;
    }

    void BaseProperty::cancelUseItem()
    {
        use_state_ = kNotUsed;
    }

    void BaseProperty::setPropsState(PropsState state)
    {
        use_state_ = state;
    }

    PropsState BaseProperty::getPropsState()
    {
        return use_state_;
    }

    void BaseProperty::touchItem()
    {
        auto handle = state_to_handle_[this->getPropsState()];
        if (handle && touch_flag_)
        {
            handle();
        }
    }

    bool BaseProperty::init()
    {
        if (!Sprite::init())
        {
            return false;
        }
        use_state_ = kNotUsed;
        touch_flag_ = true;
        SpriteTextureController::getInstance()->setSpriteTexture(PROPS_ITEM_BACKGROUND_PATH, this);
        this->addNumbleButton();
        this->initHandle();
        this->addTouchEventListener();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_HAVE_USED_PROPS, 
            CC_CALLBACK_1(BaseProperty::haveUsedProperty, this));
        return true;
    }

    void BaseProperty::actionBegan()
    {
        touch_flag_ = false;
    }

    void BaseProperty::actionEnded()
    {
        touch_flag_ = true;
    }

    isUsing BaseProperty::itemIsUsing()
    {
        return use_state_ == kUsing;
    }

    void BaseProperty::setPropertyEnabled(bool flag)
    {
        //if (flag)
        //{
        //    this->addTouchEventListener();
        //}
        //else
        //{
        //    this->removeTouchEventListener();
        //}
        touch_enable_ = flag;
        menu_->setEnabled(flag);
    }

    bool BaseProperty::isPropertyEnabled()
    {
        return touch_enable_;
    }

    void BaseProperty::removeTouchEventListener()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    }

    void BaseProperty::addNumbleButton()
    {
        cocos2d::Sprite* normal_sprite = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_NUMBLE_ENABLED_PATH);
        cocos2d::Sprite* select_sprite = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_NUMBLE_ENABLED_PATH);
        select_sprite->setScale(PROPS_BUTTON_SELECT_SCALE);
        cocos2d::Sprite* disabled_sprite = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_NUMBLE_DISABLED_PATH);
        button_ = cocos2d::MenuItemSprite::create(normal_sprite, select_sprite, disabled_sprite);
        button_->setScale(PROPS_BUTTON_SPRITE_SCALE);
        menu_ = cocos2d::Menu::createWithItem(button_);
        menu_->setPosition(cocos2d::Vec2(PROPS_BUTTON_POS_X, PROPS_BUTTON_POS_Y));
        this->addChild(menu_, 1);
        //button_->setEnabled(false);
    }

    void BaseProperty::initHandle()
    {
        state_to_handle_[kUsing] = [=]() {this->cancelUseItem(); };
        state_to_handle_[kNotUsed] = [=]() {this->useItem(); };
    }

    void BaseProperty::addTouchEventListener()
    {
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        GamePlayController* game_controller = GamePlayController::getInstance();
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchPropertyBegan, game_controller);
        listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::touchPropertyMoved, game_controller);
        listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::touchPropertyEnded, game_controller);
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }

    void BaseProperty::initIconWithPath(const std::string& path)
    {
        cocos2d::Sprite* iter_sprite = SpriteTextureController::getInstance()->createGameSpriteWithPath(path);
        cocos2d::Size size = this->getBoundingBox().size;
        iter_sprite->setPosition(cocos2d::Vec2(size.width / 2, size.height / 2));
        this->addChild(iter_sprite);
    }

    void BaseProperty::haveUsedProperty(cocos2d::EventCustom*)
    {
        this->setPropsState(kNotUsed);
    }
}