#include "ColorBubble.h"
#include "SmartScaleController.h"
#include "BubbleFactory.h"
#include "DarkCloudBubble.h"
#include "GamePlayController.h"
#include "cocostudio\CocoStudio.h"
#include "GameScoreController.h"
#include "StageDataManager.h"
#include "GameScene.h"
namespace bubble_second {
    ColorBubble::~ColorBubble()
    {

    }
    ColorBubble::ColorBubble()
    {

    }

    bool ColorBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        return true;
    }

    bool ColorBubble::initWithType(int type)
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(type);
        this->initHandleEffect();
        return true;
    }

    bool ColorBubble::initWithTypeAndCloud(int type, int cloud)
    {
        cloud_bubble_ = dynamic_cast<DarkCloudBubble*>(BubbleFactory::getInstance()->createBubbleWithType(cloud));
        if (!this->initWithType(type))
        {
            return false;
        }
        if (cloud_bubble_)
        {
            cocos2d::Rect rect = this->getBoundingBox();
            cloud_bubble_->setPosition(cocos2d::Vec2(rect.size.width, rect.size.height) / 2);
            this->addChild(cloud_bubble_);
        }
        return true;
    }

    void ColorBubble::initHandleEffect()
    {
        key_to_handle_effect_[PREPARE_EFFECT_BUBBLE_KEY] = [=](const cocos2d::Vec2& contact_point) {dynamic_cast<ColorBubble*>(this)->runPreBubbleContactEffect(contact_point); };
    }

    void ColorBubble::runPreBubbleContactEffect(const cocos2d::Vec2& contact_point)
    {
        this->runContactAction(this->getEffectDistance(contact_point, LONG_CONTACT_EFFECT_DISTANCE)*-1);
    }

    void ColorBubble::downFromAir()
    {
        this->setTag(0);
        this->destroyDarkCloud();
        this->addBubbleDynamicBody();
        int remainder = (int)this->getBubbleIndex().y % 2;
        float zoom = SmartScaleController::getInstance()->getPlayAreaZoom();

        float impulse_x = cocos2d::random(BUBBLE_DOWN_FROM_AIR_IMPULSE_MIN_X, BUBBLE_DOWN_FROM_AIR_IMPULSE_MAX_X);
        float impulse_y = cocos2d::random(BUBBLE_DOWN_FROM_AIR_IMPULSE_MIN_Y, BUBBLE_DOWN_FROM_AIR_IMPULSE_MAX_Y);
        cocos2d::Vec2 impulse(impulse_x, impulse_y*2);
        auto body = this->getPhysicsBody();
        float torque = BUBBLE_DOWN_FROM_AIR_TORQUE;
        float angular_v = BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY;
        if (0 != remainder)
        {
            impulse.x = -impulse.x;
            angular_v = -angular_v;
        }
        body->applyImpulse(impulse*zoom);
        body->setAngularVelocity(angular_v);
        //this->delayNotCollision();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_ADD_AIR_BUBBLE_NUMBLE);
    }

    void ColorBubble::addBubbleDynamicBody()
    {
        cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BUBBLE_RADIUS,
            cocos2d::PhysicsMaterial(BUBBLE_BODY_DENSITY,
                BUBBLE_DYNAMIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));//ÃÜ¶È, »Ö¸´,Ä¦²ÁÁ¦
        body->setDynamic(true);
        body->setMass(BUBBLE_BODY_MASS);
        body->setGroup(-1);
        body->setCategoryBitmask(BITMASK_BUBBLE_DYNAMIC_CATEGORY);
        body->setCollisionBitmask(BITMASK_BUBBLE_DYNAMIC_COLLISION);
        body->setContactTestBitmask(BITMASK_BUBBLE_DYNAMIC_CONTACTTEST);
        this->setPhysicsBody(body); 
        this->delayNotCollision();
    }

    void ColorBubble::playEliminateEffect()
    {
        cocostudio::Armature* armature = cocostudio::Armature::create(COLOR_BUBBLE_ELIMINATE_EFFECT_NAME);
        armature->setPosition(this->getPosition());
        armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature* armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                armature->removeFromParent();
            }
        });
        this->getParent()->addChild(armature);

        cocos2d::ScaleTo* scaleto = cocos2d::ScaleTo::create(BUBBLE_ELIMINATE_DELAY_TIME, BUBBLE_ELIMINATE_SCALETO);
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(scaleto, cocos2d::CallFunc::create([=]() {
            this->removeFromParent();
        }));
        this->runAction(seq);
    }

    void ColorBubble::shootAfterVictory()
    {
        this->addBubbleDynamicBody();
        this->setLocalZOrder(UI_ZORDER_DOWN_AIR_BUBBLE);
        int x = cocos2d::random(-BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_X, BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_X);
        float angular_v = x >= 0 ? BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY : -BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY;
        this->getPhysicsBody()->setAngularVelocity(angular_v);
        int y = cocos2d::random(BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MIN, BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MAX);
        float zoom = SmartScaleController::getInstance()->getPlayAreaZoom();
        this->getPhysicsBody()->applyImpulse(cocos2d::Vec2(x, y)*SmartScaleController::getInstance()->getPlayAreaZoom());
        GameScoreController::getInstance()->cutBubbleUseCount();
        //this->delayNotCollision();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_ADD_AIR_BUBBLE_NUMBLE);
    }

    void ColorBubble::delayNotCollision()
    {
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(15), cocos2d::CallFunc::create([=]() {
            //this->getPhysicsBody()->setResting(false);
            int x = cocos2d::random(-BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_X, BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_X);
            float angular_v = x >= 0 ? BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY : -BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY;
            this->getPhysicsBody()->setAngularVelocity(angular_v);
            int y = cocos2d::random(BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MIN, BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MAX);
            float zoom = SmartScaleController::getInstance()->getPlayAreaZoom();
            this->getPhysicsBody()->applyImpulse(cocos2d::Vec2(x, y)*SmartScaleController::getInstance()->getPlayAreaZoom());
            GameScoreController::getInstance()->cutBubbleUseCount();
            this->delayNotCollision();
        })));
   }

    void ColorBubble::changeRandomSpecialBubble(const cocos2d::Vec2& point, StageType stage_type)
    {
        std::vector<BubbleType> color_vector;
        color_vector.push_back(kBubbleBombBomb);
        color_vector.push_back(kBubbleAddNumbleBubble);
        if (stage_type != kWindmill)
        {
            color_vector.push_back(kBubbleLightning);
        }

        int length = color_vector.size();
        int index = cocos2d::random(0, length-1);
        BubbleType color = color_vector[index];

        BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(color);
        bubble->setPosition(point);
        this->getParent()->addChild(bubble);

        cocos2d::MoveTo* move = cocos2d::MoveTo::create(ENTER_PROPS_ACTION_DURATION, this->getPosition());
        cocos2d::CallFunc* callfunc = cocos2d::CallFunc::create([=]() {
            GamePlayController::getInstance()->subtractPrepareColor(this->getBubbleType());
            this->setBubbleType(color);
            bubble->removeFromParent();
        });
        bubble->runAction(cocos2d::Sequence::createWithTwoActions(move, callfunc));
    }

    void ColorBubble::addBubblePrepareBody()
    {
        cocos2d::Sequence* seq = cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([&]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BUBBLE_RADIUS,
                cocos2d::PhysicsMaterial(BUBBLE_BODY_DENSITY,
                    BUBBLE_STATIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));
            body->setDynamic(true);
            body->setGroup(BUBBLE_BODY_GROUP);
            body->setGravityEnable(false);
            body->setCategoryBitmask(BITMASK_BUBBLE_PREPARE_CATEGORY);
            body->setCollisionBitmask(BITMASK_BUBBLE_PREPARE_COLLISION);
            body->setContactTestBitmask(BITMASK_BUBBLE_PREPARE_CONTACTTEST);
            body->setEnable(false);
            this->setPhysicsBody(body);
        }), NULL);
        this->runAction(seq);
    }

    void ColorBubble::addBubbleStaticBody()
    {
        BaseBubble::addBubbleStaticBody();
        this->setTag(COLOR_BUBBLE_TAG);
    }

    void ColorBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SHUT_BUBBLE);
    }

    void ColorBubble::bubbleEliminate(int combo)
    {
        cocos2d::ValueMap data_map;
        data_map[EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_SCORE_KEY] = SINGLE_BUBBLE_SCORE(combo);
        data_map[EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_X_KEY] = this->getPositionX();
        data_map[EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_Y_KEY] = this->getPositionY();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_ADD_ELIMINATE_SCORE_LABEL,&data_map);
        this->destroyDarkCloud();
        this->playEliminateEffect();
    }

    bool ColorBubble::isDarkCloudBubble()
    {
        if (cloud_bubble_)
        {
            return true;
        }
        return false;
    }

    void ColorBubble::destroyDarkCloud()
    {
        if (this->isDarkCloudBubble())
        {
            cloud_bubble_->bubbleEliminate();
            cloud_bubble_ = nullptr;
        }
    }

    void ColorBubble::shoot(const cocos2d::Vec2& touch_location)
    {
        this->getPhysicsBody()->setEnable(true);
        if (this->isColorBubbleType())
        {
            GameScoreController::getInstance()->cutBubbleUseCount();
        }

        this->getPhysicsBody()->applyImpulse(this->getImpulseByTouchlocation(touch_location)*SmartScaleController::getInstance()->getPlayAreaZoom());
        auto controller = GamePlayController::getInstance();
        controller->setBubbleShootEnabled(false);
        controller->setPrepareBubble(nullptr);
        this->dispatchEventAfterShooted();

        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SHOOT_PREPARE_BUBBLE);
    }


    cocos2d::Vec2 ColorBubble::getImpulseByTouchlocation(cocos2d::Vec2 touch_location)
    {
        cocos2d::Vec2 bubble_point = this->getPosition();
        cocos2d::Vec2 sub_numble = touch_location - bubble_point;
        double tan_value = sub_numble.y / sub_numble.x;
        double angle = atan(tan_value);
        if (sub_numble.x < 0)
        {
            angle = angle - PI;
        }
        return cocos2d::Vec2(cos(angle) * BUBBLE_IMPULSE, sin(angle) * BUBBLE_IMPULSE)*GamePlayController::getInstance()->getTouchDirection();
    }
}