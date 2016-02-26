//*******************************************************************************
//文件名       : <BaseComponentBubble.h>
//文件实现功能  : <组件泡泡的父类>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BASE_COMPONENT_BUBBLE_H_
#define _BASE_COMPONENT_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class BubbleComponent;
    typedef cocos2d::Vector<BubbleComponent*> ComponentVector;
    class BaseComponentBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(BaseComponentBubble);
        virtual ~BaseComponentBubble();
        virtual void addBubbleComponent(BubbleComponent* component);
        ComponentVector getComponents();
        BubbleVector getTotalBubbles();
        void downFromAir() override;
    protected:
        BaseComponentBubble();
        bool init();
        void addCompletedTaskNumble();
        void addGameTaskNumble();
    private:
        ComponentVector components_;
    };
}
#endif //_BASE_COMPONENT_BUBBLE_H_