#include "WindmillBubble.h"
#include "cocostudio\CocoStudio.h"
#include "SpriteTextureController.h"
#include "BubbleFactory.h"
#include "GameScene.h"
#include "GameScoreController.h"
namespace bubble_second {
    WindmillBubble::WindmillBubble()
    {
    }

    WindmillBubble::~WindmillBubble()
    {
    }
    
    bool WindmillBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleWindmill);
        this->setSupensionPoint(true);
        this->setTag(WINDMILL_BUBBLE_TAG);
        GameScoreController::getInstance()->addGameTaskNumble();
        return true;
    }

    void WindmillBubble::setBubbleTexture(BubbleType type)
    {
    }

    cocos2d::Node* WindmillBubble::getFlyingTexture()
    {
        cocos2d::Sprite* head = SpriteTextureController::getInstance()->createGameSpriteWithPath(UI_NAME_WINDMILL_BUBBLE_FLYING_HEAD_PATH);
        head->setPositionY(WINDMILL_BUBBLE_FLYING_HEAD_POS_Y);
        cocos2d::Sprite* body = SpriteTextureController::getInstance()->createGameSpriteWithPath(UI_NAME_WINDMILL_BUBBLE_FLYING_BODY_PATH);
        body->setPositionY(WINDMILL_BUBBLE_FLYING_BODY_POS_Y);
        cocos2d::Node* node = cocos2d::Node::create();
        node->addChild(head,1);
        node->addChild(body);
        node->setScale(WINDMILL_BUBBLE_FLYING_INITIAL_SCALE);
        return node;
    }

    cocos2d::Action * WindmillBubble::getFlyingAction()
    {

        cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, -WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA);
        cocos2d::ScaleTo* scale = cocos2d::ScaleTo::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, WINDMILL_BUBBLE_FLYING_FINAL_SCALE);
        cocos2d::Spawn* seq = cocos2d::Spawn::create(this->getArchimedeanSpiralAction(), rotate, scale, nullptr);
        return seq;
    }

    cocos2d::CardinalSplineBy* WindmillBubble::getArchimedeanSpiralAction()
    {
        float begin_theta = 0.0f;
        float a = WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_A;
        float b = WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_B;
        cocos2d::PointArray* point_array = cocos2d::PointArray::create(WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA);
        for (int theta = 0; theta != abs(WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA); ++theta)
        {
            float local_theta = WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_DIRECTION*theta;
            float r = a + b*local_theta;
            cocos2d::Vec2 point = cocos2d::Vec2(r*cos(CC_DEGREES_TO_RADIANS(local_theta + begin_theta)), r*sin(CC_DEGREES_TO_RADIANS(local_theta + begin_theta)));
            point_array->addControlPoint(point);
        }
        cocos2d::CardinalSplineBy* action = cocos2d::CardinalSplineBy::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, point_array, 0);
        return action;
    }

    void WindmillBubble::setParent(cocos2d::Node* parent)
    {
        BaseBubble::setParent(parent);
        if (parent)
        {
            sp_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(BubbleFactory::getInstance()->getPathWithType(kBubbleWindmill));
            cocos2d::Vec2 point = dynamic_cast<GameScene*>(parent->getParent()->getParent())->convertMapToCsbSpace(this->getPosition());
            sp_->setPosition(point);
            parent->getParent()->addChild(sp_);
        }
    }

    void WindmillBubble::bubbleEliminate(int combo)
    {
        GameScoreController::getInstance()->addCompletedTaskNumble();

        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        cocos2d::Node* parent_node = sp_->getParent();
        Armature *armature = Armature::create(WINDMILL_BUBBLE_DEMON_ARMATURE_NAME);
        armature->setPosition(sp_->getPosition());
        armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->removeFromParent();
                armature->removeFromParent();
            }
        });
        parent_node->addChild(armature);

        cocos2d::FadeOut* fade = cocos2d::FadeOut::create(1);
        sp_->runAction(cocos2d::Sequence::createWithTwoActions(fade, cocos2d::CallFunc::create([=]() {
            cocos2d::Node* node = this->getFlyingTexture();
            node->setPosition(sp_->getPosition());
            parent_node->addChild(node);
            node->runAction(this->getFlyingAction());
            cocos2d::MotionStreak* motion = cocos2d::MotionStreak::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, 10.0f, 50.0f, cocos2d::Color3B::WHITE, UI_NAME_WINDMILL_BUBBLE_FLYING_MOTIONSTREAK_PATH);
            motion->setPosition(sp_->getPosition());
            parent_node->addChild(motion);
            motion->runAction(this->getArchimedeanSpiralAction());
            sp_->removeFromParent(); 
        })));
    }
}