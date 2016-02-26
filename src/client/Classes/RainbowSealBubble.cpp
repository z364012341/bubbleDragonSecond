#include "RainbowSealBubble.h"
#include "BubbleComponent.h"
#include "GamePlayController.h"
#include "RainbowSealManager.h"
#include "BubbleFactory.h"
#include "RainbowCharactor.h"
namespace bubble_second {
    RainbowSealBubble::RainbowSealBubble()
    {
        first_flag_ = true;
        sealed_charactor_ = nullptr;
    }

    RainbowSealBubble::~RainbowSealBubble()
    {
    }

    bool RainbowSealBubble::init()
    {
        if (!BaseComponentBubble::init())
        {
            return false;
        }
        this->addStandbyAnimation();
        this->setBubbleType(kBubbleRainbowSeal);
        this->setRainbowColor(kBubbleNull);
        this->setSupensionPoint(true);
        this->setBubbleComponentNumble(BUBBLE_REABOW_SEAL_COMPONENT_NUMBLE);
        this->addGameTaskNumble();
        RainbowSealManager::getInstance()->addRainbowSealBubble(this);
        return true;
    }

    bool RainbowSealBubble::isEqualRainbowColor(BubbleType color)
    {
        return color == this->getRainbowColor();
    }

    bool RainbowSealBubble::isSealing()
    {
        return this->getSealedCharactor()!=nullptr;
    }

    BubbleVector RainbowSealBubble::disposeRainbowSeal(BubbleType color)
    {
        //BubbleVector vector(0);
        if (this->isEqualRainbowColor(color))
        {   
            return this->getTotalBubbles();
        }
        else
        {
            this->changeRainbowColor();
        }
        return BubbleVector(0);
    }

    BubbleType RainbowSealBubble::getRainbowColor()
    {
        return rainbow_color_;
    }

    void RainbowSealBubble::changeRainbowColor()
    {
        if (this->isSealing())
        {
            BubbleType color = this->getRainbowColor();
            do
            {
                color = GamePlayController::getInstance()->getBubbleColorFromPicker();
            } while (color == this->getRainbowColor());
            this->setRainbowColor(color);
        }
    }

    void RainbowSealBubble::setRainbowColor(BubbleType color)
    {
        GamePlayController::getInstance()->addPrepareColor(color);
        GamePlayController::getInstance()->subtractPrepareColor(getRainbowColor());
        rainbow_color_ = color;
        if (this->isSealing())
        {
            this->getSealedCharactor()->setRainbowColor(rainbow_color_);
        }
    }

    void RainbowSealBubble::setSealedCharactor(RainbowCharactor* charactor)
    {
        sealed_charactor_ = charactor;
    }

    RainbowCharactor * RainbowSealBubble::getSealedCharactor()
    {
        return sealed_charactor_;
    }

    void RainbowSealBubble::bubbleEliminate(int combo)
    {
        this->addCompletedTaskNumble();
        RainbowSealManager::getInstance()->moveSealedCharactor(this);
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature *armature = Armature::create(RAINBOW_BUBBLE_ARMATURE_NAME);
        armature->setScale(0.87f);
        armature->setPosition(-13.0f, -2.0f);
        armature->getAnimation()->play(RAINBOW_BUBBLE_ARMATURE_BOMB_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->removeFromParent();
            }
        });
        this->addChild(armature, 1);
    }

    void RainbowSealBubble::downFromAir()
    {
        //this->bubbleEliminate();
    }

    void RainbowSealBubble::addStandbyAnimation()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature *armature = Armature::create(RAINBOW_BUBBLE_ARMATURE_NAME);
        armature->setScale(0.87f);
        armature->setPosition(-13.0f, -2.0f);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::START)
            {
                armature->setVisible(true);
            }
            if (movementType == cocostudio::COMPLETE)
            {
                armature->setVisible(false);
            }
        });
        this->addChild(armature, -1);
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(10.0f), cocos2d::CallFunc::create([=]() {
            if (this->isSealing())
            {
                armature->getAnimation()->play(RAINBOW_BUBBLE_ARMATURE_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            }

        }));
        armature->runAction(cocos2d::RepeatForever::create(seq));
    }
    
}