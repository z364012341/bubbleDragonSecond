//*******************************************************************************
//类名称   : StageNumble
//功能     : <关卡数>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_NUMBLE_H_
#define _STAGE_NUMBLE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageNumble
    {
    public:
        GETINSTANCE_FUNC(StageNumble);
        ~StageNumble();
        int getStageNumble() const;
        void nextStageNumble();
        bool moreThanStageTotal();
        void clear();
    private:
        StageNumble();
    private:
        int stage_numble_;
    };
}
#endif //_STAGE_NUMBLE_H_