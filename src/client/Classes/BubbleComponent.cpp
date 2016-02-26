#include "BubbleComponent.h"
#include "BaseComponentBubble.h"
namespace bubble_second {
    BubbleComponent::BubbleComponent()
    {
    }


    BubbleComponent::~BubbleComponent()
    {
    }

    bool BubbleComponent::initWithCore(BaseBubble* bubble)
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setCoreBubble(bubble);
        //this->addBubbleStaticBody();
        this->setBubbleType(kBubbleComponent);
        return true;
    }

    void BubbleComponent::setCoreBubble(BaseBubble * bubble)
    {
        core_bubble_ = bubble;
    }

    BaseBubble* BubbleComponent::getCoreBubble()
    {
        return core_bubble_;
    }

    BubbleVector BubbleComponent::getTotalBubbles()
    {
        BaseComponentBubble* bubble = dynamic_cast<BaseComponentBubble*>(this->getCoreBubble());
        if (!bubble)
        {
            return BubbleVector(0);
        }
        return bubble->getTotalBubbles();
    }

    void BubbleComponent::bubbleEliminate(int combo)
    {
        this->removeFromParent();
    }

    void BubbleComponent::downFromAir()
    {
        this->bubbleEliminate();
    }

}