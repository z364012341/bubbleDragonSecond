#include "BombBombBubble.h"
#include "cocostudio/CocoStudio.h"

namespace bubble_second {
    BombBombBubble::BombBombBubble()
    {
    }


    BombBombBubble::~BombBombBubble()
    {
    }

    bool BombBombBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        //this->addBubbleStaticBody();
        this->setBubbleType(kBubbleBombBomb);
        return true;
    }

    void BombBombBubble::downFromAir()
    {
        this->bubbleEliminate();
    }

    void BombBombBubble::bubbleEliminate(int combo)
    {
        this->removeFromParent();
    }

    float BombBombBubble::playTheSpecialEffects()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        if (cocos2d::Node* parent = this->getParent())
        {
            Armature *armature = Armature::create(ONE_ROUND_BOMB_EFFECT_NAME);
            armature->setPosition(this->getPosition());
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    armature->removeFromParent();
                }
            });
            parent->addChild(armature);
            return ONE_ROUND_BOMB_EFFECT_DELAY_TIME;
        }
        return 0.0f;
    }
}