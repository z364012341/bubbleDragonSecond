#include "DarkCloudBubble.h"
namespace bubble_second {
    DarkCloudBubble::DarkCloudBubble()
    {
    }

    DarkCloudBubble::~DarkCloudBubble()
    {
    }

    bool DarkCloudBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleDarkCloud);
        //this->addBubbleStaticBody();
        return true;
    }

    void DarkCloudBubble::downFromAir()
    {
        this->removeFromParent();
    }

    void DarkCloudBubble::bubbleEliminate(int)
    {
        this->removeFromParent();
    }
}