#include "GameScene.h"
#include "BlackHoleBubble.h"
#include "GamePlayController.h"
namespace bubble_second {
    BlackHoleBubble::BlackHoleBubble()
    {
    }


    BlackHoleBubble::~BlackHoleBubble()
    {
    }

    bool BlackHoleBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        swallow_times_ = 0;
        //this->addBubbleStaticBody();
        this->setBubbleType(kBubbleBlackHole);
        return true;
    }

    void BlackHoleBubble::swallowBubble(BaseBubble* bubble)
    {
        bubble->setName(MAP_BUBBLE_NAME);
        //bubble->getPhysicsBody()->setEnable(false);
        bubble->removeFromPhysicsWorld();
        bubble->setPhysicsBody(nullptr);
        this->playAchimedeanSpiralAction(bubble);

    }

    void bubble_second::BlackHoleBubble::playAchimedeanSpiralAction(BaseBubble* bubble)
    {
        swallow_vector_.pushBack(bubble);
        //基于阿基米德螺线的实现
        cocos2d::Vec2 bubble_relative_point = this->convertToNodeSpaceAR(bubble->getParent()->convertToWorldSpaceAR(bubble->getPosition()));
        bubble->retain();
        bubble->removeFromParent();
        bubble->setPosition(bubble_relative_point);
        this->addChild(bubble, 2);
        bubble->release();

        float distance = bubble_relative_point.distance(cocos2d::Vec2::ZERO);
        float a = 1.0f;
        float b = (distance - a) / BLACKHOLE_BUBBLE_SWALLOW_DEGREE;
        float offs = 0.0f;
        if (bubble_relative_point.x<0)
        {
            offs = 180;
        }
        float end_theta = CC_RADIANS_TO_DEGREES(atan(bubble_relative_point.y / bubble_relative_point.x)) + offs;
        float begin_theta = end_theta - BLACKHOLE_BUBBLE_SWALLOW_DEGREE;
        cocos2d::PointArray* point_array = cocos2d::PointArray::create(BLACKHOLE_BUBBLE_SWALLOW_DEGREE);
        for (int theta = 0; theta != abs(BLACKHOLE_BUBBLE_SWALLOW_DEGREE); ++theta)
        {
            float local_theta = BLACKHOLE_BUBBLE_SWALLOW_DIRECTION*theta;
            float r = a + b*local_theta;
            cocos2d::Vec2 point = cocos2d::Vec2(r*cos(CC_DEGREES_TO_RADIANS(local_theta + begin_theta)), r*sin(CC_DEGREES_TO_RADIANS(local_theta + begin_theta)));
            point_array->insertControlPoint(point, 0);
            //cocos2d::log("x:%f, y:%f", point.x, point.y);
        }
        cocos2d::CardinalSplineTo* achimedeanSpiralAction = cocos2d::CardinalSplineTo::create(BLACKHOLE_BUBBLE_SWALLOW_TIME, point_array, 0);
        cocos2d::EaseOut* ease = cocos2d::EaseOut::create(achimedeanSpiralAction, 1.5f);
        cocos2d::ScaleTo* scaleto = cocos2d::ScaleTo::create(BLACKHOLE_BUBBLE_SWALLOW_TIME, 0.1f);
        cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(BLACKHOLE_BUBBLE_SWALLOW_TIME, BLACKHOLE_BUBBLE_SWALLOW_DEGREE);
        cocos2d::Spawn* spawn = cocos2d::Spawn::create(ease, scaleto, rotate, nullptr);
        cocos2d::Vector<cocos2d::FiniteTimeAction*> action_vector;
        action_vector.pushBack(spawn);
        action_vector.pushBack(cocos2d::CallFunc::create([=]() {
            bubble->removeFromParent();
        }));
        cocos2d::Sequence* seq = cocos2d::Sequence::create(action_vector);
        bubble->runAction(seq);
        this->swallowBubbleOnce();
    }

    cocos2d::Vec2 BlackHoleBubble::getControlPointWithVectors(const cocos2d::Vec2& this_bubble_point, const cocos2d::Vec2& point_2)
    {
        cocos2d::Vec2 point = this_bubble_point - point_2;
        return this_bubble_point + point / 2;
    }

    void BlackHoleBubble::bubbleEliminate(int combo)
    {
        for (auto var : swallow_vector_)
        {
            var->removeFromParent();
        }
        this->removeFromParent();
    }

    void BlackHoleBubble::downFromAir()
    {
        this->removeFromParent();
    }

    void BlackHoleBubble::swallowBubbleOnce( )
    {
        this->addSwallowTimes();
        if (this->isNeedEliminate())
        {
            this->bubbleEliminate();
        }
    }

    void BlackHoleBubble::addSwallowTimes()
    {
        ++swallow_times_;
        if (swallow_times_ == 1)
        {
            this->playFirstAction();
        }
    }

    void BlackHoleBubble::setBubbleTexture(BubbleType)
    {   
        this->getTexture();
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        armature_ = Armature::create(BLACK_HOLE_BUBBLE_EFFECT_NAME);
        armature_->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        armature_->getAnimation()->setSpeedScale(1.3f);
        this->addChild(armature_, 1);
    }

    bool BlackHoleBubble::isNeedEliminate()
    {
        return swallow_times_ >= BLACKHOLE_BUBBLE_SWALLOW_NUMBLE_MAX;
    }

    bool BlackHoleBubble::needRemoveFromBubbleMap()
    {
        this->addSwallowTimes();
        return this->isNeedEliminate();
    }

    void BlackHoleBubble::forceEliminate()
    {
        swallow_times_ = BLACKHOLE_BUBBLE_SWALLOW_NUMBLE_MAX;
    }

    void BlackHoleBubble::addTouchEventListener()
    {
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchSelectBubble, GamePlayController::getInstance());
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this->getChildByName(BLACK_HOLE_BUBBLE_EFFECT_NAME));
    }

    void BlackHoleBubble::removeTouchEventListener()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this->getChildByName(BLACK_HOLE_BUBBLE_EFFECT_NAME));
    }

    void BlackHoleBubble::playFirstAction()
    {
        cocos2d::ScaleTo* scale_1 = cocos2d::ScaleTo::create(BLACKHOLE_BUBBLE_SCALETO_TIME, BLACKHOLE_BUBBLE_SCALETO_PER);
        cocos2d::ScaleTo* scale_2 = cocos2d::ScaleTo::create(BLACKHOLE_BUBBLE_SCALETO_TIME, 1.0f);
        cocos2d::EaseInOut * ease_1 = cocos2d::EaseInOut::create(scale_1, 1.5f);
        cocos2d::EaseInOut * ease_2 = cocos2d::EaseInOut::create(scale_2, 1.5f);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(ease_1, ease_2, nullptr);
        armature_->runAction(cocos2d::RepeatForever::create(seq));
    }

}