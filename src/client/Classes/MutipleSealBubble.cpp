#include "MutipleSealBubble.h"
#include "SpriteTextureController.h"
#include "BubbleFactory.h"

namespace bubble_second {
    MutipleSealBubble::MutipleSealBubble()
    {
        armature_ = nullptr;
    }


    MutipleSealBubble::~MutipleSealBubble()
    {
    }

    bool MutipleSealBubble::initWithComponentNumble(int numble)
    {
        if (!BaseComponentBubble::init())
        {
            return false;
        }
        this->setBubbleComponentNumble(numble);
        this->setBubbleType(kBubbleMutipleSeal);
        this->addGameTaskNumble();
        return true;
    }

    void MutipleSealBubble::bubbleEliminate(int combo)
    {
        this->setLocalZOrder(1);
        armature_->getAnimation()->play(MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_ELIMINATE_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature_->setLocalZOrder(1);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->addCompletedTaskNumble();
                this->removeFromParent();
            }
        });

        //this->removeFromParent();
    }

    void MutipleSealBubble::downFromAir()
    {
        this->bubbleEliminate();
    }

    void MutipleSealBubble::setBubbleTexture(BubbleType)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        BubbleType type = kBubbleMutipleSeal;
        auto func = [=](const std::string& path) {            
            armature_ = Armature::create(path);
            armature_->getAnimation()->play(MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
            auto rect = this->getBoundingBox();
            armature_->setPosition(rect.size.width / 2, rect.size.height / 2);
            this->addChild(armature_, -1);
        };
        switch (this->getBubbleComponentNumble())
        {
        case BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1:
        {
            type = kBubbleMutipleSeal1;
            BaseComponentBubble::setBubbleTexture(type);
            func(MUTIPLE_SEAL_BUBBLE_ARMATURE_DOG_NAME);
            break;
        }
        case BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3:
        {
            type = kBubbleMutipleSeal3;
            BaseComponentBubble::setBubbleTexture(type);
            func(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_NAME);
            this->setAnchorPoint(BUBBLE_MUTIPLE_SEAL_3_ANCHORPOINT);
            armature_->setScale(0.95f);
            break;
        }
        case BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7:
        {
            type = kBubbleMutipleSeal7;
            BaseComponentBubble::setBubbleTexture(type);
            func(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_NAME);
            break;
        }
        default:
            assert(false);
            break;
        }
    }

    void MutipleSealBubble::addBubbleStaticBody()
    {
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([&]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BUBBLE_RADIUS,
                cocos2d::PhysicsMaterial(BUBBLE_BODY_DENSITY,
                    BUBBLE_STATIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));
            body->setDynamic(false);
            body->setGravityEnable(false);
            body->setMass(BUBBLE_BODY_MASS);
            body->setCategoryBitmask(BITMASK_BUBBLE_STATIC_CATEGORY);
            body->setCollisionBitmask(BITMASK_BUBBLE_STATIC_COLLISION);
            body->setContactTestBitmask(BITMASK_BUBBLE_STATIC_CONTACTTEST);
            if (this->getBubbleComponentNumble() == BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3)
            {
                body->setPositionOffset(cocos2d::Vec2(0.0f, 15.0f));
            }
            this->setPhysicsBody(body);
        }), NULL));
    }
}
