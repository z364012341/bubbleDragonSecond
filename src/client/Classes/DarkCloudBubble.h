//*******************************************************************************
//文件名         : <DarkCloudBubble.h>
//文件实现功能  : <阴云泡泡, 遮盖泡泡的真实类型>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//修改记录 :
//日 期        版本     修改人              修改内容
//2015/09/15   1.0     <黄泽昊>            <新添加>
//*******************************************************************************
#ifndef _DARK_CLOUD_BUBBLE_H_
#define _DARK_CLOUD_BUBBLE_H_
#include "BaseBubble.h"
#include "cocos2d.h"
namespace bubble_second {
    class DarkCloudBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(DarkCloudBubble);
        ~DarkCloudBubble();
    public:
        void downFromAir() override;
        void bubbleEliminate(int unused_combo = 0) override;
    private:
        DarkCloudBubble();
        bool init();
    };
}
#endif //_DARK_CLOUD_BUBBLE_H_