#include "NullBubble.h"


namespace bubble_second {
    NullBubble::NullBubble()
    {
    }


    NullBubble::~NullBubble()
    {
    }
    void NullBubble::bubbleEliminate(int combo)
    {
        return;
    }
    bool NullBubble::needRemoveFromBubbleMap()
    {
        return false;
    }
    bool NullBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleNull);
        this->setSupensionPoint(true);
        return true;
    }
}