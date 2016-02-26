#include "BaseComponentBubble.h"
#include "BubbleComponent.h"
#include "GameScoreController.h"
namespace bubble_second {
    BaseComponentBubble::BaseComponentBubble()
    {
    }

    bool bubble_second::BaseComponentBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        return true;
    }

    BaseComponentBubble::~BaseComponentBubble()
    {
    }

    void BaseComponentBubble::addBubbleComponent(BubbleComponent* component)
    {
        components_.pushBack(component);
        assert(components_.size() <= BUBBLE_REABOW_SEAL_COMPONENT_NUMBLE);
    }

    ComponentVector BaseComponentBubble::getComponents()
    {
        return components_;
    }

    BubbleVector BaseComponentBubble::getTotalBubbles()
    {
        BubbleVector vector(0);
        for (auto var : this->getComponents())
        {
            vector.pushBack(var);
        }
        vector.pushBack(this);
        return vector;
    }

    void BaseComponentBubble::downFromAir()
    {
        this->removeFromParent();
    }

    void BaseComponentBubble::addCompletedTaskNumble()
    {
        GameScoreController::getInstance()->addCompletedTaskNumble();
    }

    void BaseComponentBubble::addGameTaskNumble()
    {
        GameScoreController::getInstance()->addGameTaskNumble();
    }
}