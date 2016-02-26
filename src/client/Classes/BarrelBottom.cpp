#include "BarrelBottom.h"
#include "BubbleSecondConstant.h"
#include "SmartScaleController.h"
#include "cocos2d.h"
#include "GameScoreController.h"
namespace bubble_second {
    BarrelBottom::BarrelBottom()
    {
    }

    BarrelBottom::~BarrelBottom()
    {
    }

    //void BarrelBottom::onEnter()
    //{
    //    cocos2d::Node::onEnter();

    //}

    //void BarrelBottom::onExit()
    //{
    //    cocos2d::Node::onExit();
    //    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(UI_NAME_BIG_COMBO_ELIMINATE);
    //}

    bool BarrelBottom::initScoreWithName(const std::string& name)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        effect_flag_ = true;
        this->initialStacdbyEffectTime();
        this->setName(BARREL_BOTTOM_NAME);
        this->initScore(name);
        this->initPhysicsBody();
        this->playStandbyEffect();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(UI_NAME_BIG_COMBO_ELIMINATE, [=](cocos2d::EventCustom*) {
            dynamic_cast<cocostudio::Armature*>(this->getChildByName(BARREL_BOTTOM_STANDBY_EFFECT_NAME))->getAnimation()->setSpeedScale(BARREL_BOTTOM_STANDBY_EFFECT_SPEED_SCALE);
            standby_effect_delaytime_max_ = BARREL_BOTTOM_STANDBY_BIG_EFFECT_DELAYTIME_MAX;
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CUT_ELIMINATE_COMBO, [=](cocos2d::EventCustom*) {
            dynamic_cast<cocostudio::Armature*>(this->getChildByName(BARREL_BOTTOM_STANDBY_EFFECT_NAME))->getAnimation()->setSpeedScale(1.0f);
            this->initialStacdbyEffectTime();
        });
        return true;
    }

    void BarrelBottom::initScore(const std::string& name)
    {
        if (UI_NAME_BARREL_BOTTOM_FIRST == name)
        {
            score_ = BARREL_BOTTOM_SCORE_FIRST;
        }
        else if (UI_NAME_BARREL_BOTTOM_SECOND == name)
        {
            score_ = BARREL_BOTTOM_SCORE_SECOND;
        }
        else if (UI_NAME_BARREL_BOTTOM_THIRD == name)
        {
            score_ = BARREL_BOTTOM_SCORE_THIRD;
        }
        else if (UI_NAME_BARREL_BOTTOM_FOURTH == name)
        {
            score_ = BARREL_BOTTOM_SCORE_FOURTH;
        }
        else if (UI_NAME_BARREL_BOTTOM_FIFTH == name)
        {
            score_ = BARREL_BOTTOM_SCORE_FIFTH;
        }
    }

    void BarrelBottom::playEffect()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        if (effect_flag_)
        {
            effect_flag_ = false;
            Armature* armature = Armature::create(BARREL_BOTTOM_EFFECT_NAME);
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature->getAnimation()->setMovementEventCallFunc([=](Armature* armature, cocostudio::MovementEventType type, const std::string&) {
                if (type == cocostudio::COMPLETE)
                {
                    armature->removeFromParent();
                    effect_flag_ = true;
                }
            });
            //armature->setPositionY(BARREL_BOTTOM_EFFECT_POSITION_Y);
            //armature->setPosition(-20, -20);
            this->addChild(armature);
        }
    }

    void BarrelBottom::playStandbyEffect()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature* armature = Armature::create(BARREL_BOTTOM_STANDBY_EFFECT_NAME);
        //armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        auto call_func = [=](Armature* armature, cocostudio::MovementEventType type, const std::string&) {
            if (type == cocostudio::COMPLETE)
            {
                armature->setVisible(false);
                float time = RANDOM_DECIMALS(0, standby_effect_delaytime_max_);
                armature->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(time), cocos2d::CallFunc::create(
                    [=]() {
                    armature->setVisible(true);
                    armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
                })));
            }
        };
        armature->getAnimation()->setMovementEventCallFunc(call_func);
        call_func(armature, cocostudio::COMPLETE, "");
        armature->setPositionY(BARREL_BOTTOM_STANDBY_EFFECT_POS_Y);
        //armature->setPosition(-50, 50);
        this->addChild(armature);
    }

    void BarrelBottom::initialStacdbyEffectTime()
    {
        standby_effect_delaytime_max_ = BARREL_BOTTOM_STANDBY_EFFECT_DELAYTIME_MAX;
    }

    void BarrelBottom::setStacdbyEffectTime(int time)
    {
        standby_effect_delaytime_max_ = time;
    }

    void BarrelBottom::initPhysicsBody()
    {
        auto body = cocos2d::PhysicsBody::createEdgeBox(PHYSICS_BARREL_BOTTOM_BODY_SIZE,
            cocos2d::PhysicsMaterial(PHYSICS_BARREL_BOTTOM_BODY_DENSITY, PHYSICS_BARREL_BOTTOM_BODY_RESTITUTION,
                PHYSICS_WORLD_FRICTION), PHYSICS_BARREL_BOTTOM_BORDER*SmartScaleController::getInstance()->getPlayAreaZoom());
        body->setCategoryBitmask(BITMASK_BARRELBOTTOM_CATEGORY);
        body->setCollisionBitmask(BITMASK_BARRELBOTTOM_COLLISION);
        body->setContactTestBitmask(BITMASK_BARRELBOTTOM_CONTACTTEST);
        this->setPhysicsBody(body);
    }

    void BarrelBottom::contactOnce()
    {
        //cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SCORE_ADD, &score_);
        GameScoreController::getInstance()->addScoreWithNumble(score_);
        this->playEffect();
    }
}