//*******************************************************************************
//文件名       : <MutipleSealBubble.h>
//文件实现功能  : <此泡泡自带多重封印, 可以让他失去挂点解除封印>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _MUTIPLE_SEAL_BUBBLE_H_
#define _MUTIPLE_SEAL_BUBBLE_H_
#include "BaseComponentBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class MutipleSealBubble : public BaseComponentBubble
    {
    public:
        static MutipleSealBubble* createWithComponentNumble(int numble)
        {
            MutipleSealBubble *pRet = new(std::nothrow) MutipleSealBubble();
            if (pRet && pRet->initWithComponentNumble(numble))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~MutipleSealBubble();
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        void setBubbleTexture(BubbleType type) override;
        void addBubbleStaticBody() override;
    private:
        MutipleSealBubble();
        bool initWithComponentNumble(int numble);
        cocostudio::Armature *armature_;
    };
}
#endif //_MUTIPLE_SEAL_BUBBLE_H_