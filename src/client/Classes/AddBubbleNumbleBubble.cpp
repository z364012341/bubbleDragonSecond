#include "AddBubbleNumbleBubble.h"
#include "cocostudio/CocoStudio.h"
#include "GameScoreController.h"
namespace bubble_second {
    AddBubbleNumbleBubble::AddBubbleNumbleBubble()
    {
    }


    AddBubbleNumbleBubble::~AddBubbleNumbleBubble()
    {
    }

    bool AddBubbleNumbleBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleAddNumbleBubble);
        return true;
    }

    void AddBubbleNumbleBubble::downFromAir()
    {
        this->bubbleEliminate();
    }

    void AddBubbleNumbleBubble::bubbleEliminate(int)
    {
        GameScoreController::getInstance()->addBubbleUseCount(3);
        this->removeFromParent();
    }

    float AddBubbleNumbleBubble::playTheSpecialEffects()
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

        //cocos2d::ScaleTo* scaleto = cocos2d::ScaleTo::create(BUBBLE_ELIMINATE_DELAY_TIME, BUBBLE_ELIMINATE_SCALETO);
        //cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(scaleto, cocos2d::CallFunc::create([=]() {
        //    this->removeFromParent();
        //}));
        //this->runAction(seq);
        return 0.5f;
    }
}
