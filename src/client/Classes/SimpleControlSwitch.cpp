#include "SimpleControlSwitch.h"
#include "base\base64.h"
const float SWITCH_EASEOUT_RATE = 2.5f;
namespace bubble_second {
    SimpleControlSwitch::SimpleControlSwitch()
    {
    }


    SimpleControlSwitch::~SimpleControlSwitch()
    {
    }

    void SimpleControlSwitch::setSwitchState(bool flag)
    {
        if (flag)
        {
            switchSprite_->setPosition(right_point);
        }
        else
        {
            switchSprite_->setPosition(left_point);
        }
        switch_state_ = flag;
    }

    bool SimpleControlSwitch::getSwitchState()
    {
        return switch_state_;
    }

    void SimpleControlSwitch::setMenuCallback(const cocos2d::ccMenuCallback & callback)
    {
        menu_callback_ = callback;
    }

    SimpleControlSwitch* bubble_second::SimpleControlSwitch::create(cocos2d::Sprite* backgroundSprite, cocos2d::Sprite* switchSprite, cocos2d::Label* onLabel, cocos2d::Label* offLabel)
    {
        SimpleControlSwitch *pRet = new(std::nothrow) SimpleControlSwitch();
        if (pRet && pRet->init(backgroundSprite, switchSprite, onLabel, offLabel))
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

    bool bubble_second::SimpleControlSwitch::init(cocos2d::Sprite * backgroundSprite, cocos2d::Sprite * switchSprite, cocos2d::Label * onLabel, cocos2d::Label * offLabel)
    {
        CCASSERT(backgroundSprite, "backgroundSprite must not be nil.");
        CCASSERT(switchSprite, "switchSprite must not be nil.");
        backgroundSprite_ = backgroundSprite;
        switchSprite_ = switchSprite;
        cocos2d::Sprite * selectSprite = cocos2d::Sprite::createWithSpriteFrame(backgroundSprite_->getSpriteFrame());
        selectSprite->setColor(cocos2d::Color3B::GRAY);
        cocos2d::MenuItemSprite* item = cocos2d::MenuItemSprite::create(backgroundSprite_, selectSprite, [=](cocos2d::Ref* ref) {
            this->moveSwitch();
            switch_state_ = !switch_state_;
            if (menu_callback_)
            {
                menu_callback_(ref);
            }
        });
        
        switchMenu_ = cocos2d::Menu::createWithItem(item);
        switchMenu_->setPosition(cocos2d::Vec2::ZERO);
        onLabel_ = onLabel;
        offLabel_ = offLabel;

        this->addChild(switchSprite_, 1);
        this->addChild(switchMenu_, -1);
        if (onLabel_)
        {
            this->addChild(onLabel_);
        }
        if (offLabel_)
        {
            this->addChild(offLabel_);
        }
        this->needsLayout();
        return true;
    }

    void SimpleControlSwitch::needsLayout()
    {
        right_point = cocos2d::Vec2((backgroundSprite_->getContentSize().width - switchSprite_->getContentSize().width) / 2, 0.0f);
        left_point = right_point*-1;
        switchSprite_->setPosition(right_point);
        if (onLabel_)
        {
            onLabel_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
            onLabel_->setPosition(switchSprite_->getPositionX()*-1, 0.0f);
        }
        if (offLabel_)
        {
            offLabel_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
            offLabel_->setPosition(switchSprite_->getPositionX(), 0.0f);
        }
    }

    void SimpleControlSwitch::moveSwitch()
    {
        if (move_flag_)
        {
            return;
        }
        move_flag_ = true;
        cocos2d::Vec2 point = switchSprite_->getPosition();
        cocos2d::MoveTo* move = cocos2d::MoveTo::create(abs(point.x) / move_speed_, point*-1);
        cocos2d::EaseOut* ease = cocos2d::EaseOut::create(move, SWITCH_EASEOUT_RATE);
        switchSprite_->runAction(cocos2d::Sequence::createWithTwoActions(ease, cocos2d::CallFunc::create([=]() {
            move_flag_ = false;
        })));
    }
}