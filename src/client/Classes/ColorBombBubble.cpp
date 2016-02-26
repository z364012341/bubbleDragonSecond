#include "ColorBombBubble.h"
#include "cocostudio\CocoStudio.h"

namespace bubble_second {
    ColorBombBubble::ColorBombBubble()
    {
    }


    ColorBombBubble::~ColorBombBubble()
    {
    }

    void ColorBombBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_HAVE_USED_PROPS, this);
    }

    void ColorBombBubble::bubbleEliminate(int)
    {
        this->removeFromParent();
    }

    bool ColorBombBubble::init()
    {
        if (!ColorBubble::initWithTypeAndCloud(kBubbleColorBomb))
        {
            return false;
        }
        this->setName(COLOR_BOMB_BUBBLE_NAME);
        this->addBubblePrepareBody();
        return true;
    }

    float ColorBombBubble::playTheSpecialEffects()
    {
        cocos2d::Node* parent_node = this->getParent();
        if (!parent_node)
        {
            return 0.0;
        }
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature *armature = Armature::create(ONE_ROUND_BOMB_EFFECT_NAME);
        armature->setPosition(this->getPosition());
        armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                armature->removeFromParent();
            }
        });
        parent_node->addChild(armature);
        return ONE_ROUND_BOMB_EFFECT_DELAY_TIME;
    }
    void ColorBombBubble::downFromAir()
    {
        this->bubbleEliminate();
    }
}