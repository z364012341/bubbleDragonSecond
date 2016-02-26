//*******************************************************************************
//类名称   : StartNumbleModule
//功能     : <关卡三星信息模块类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_NUMBLE_MODULE_H_
#define _STAGE_NUMBLE_MODULE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    typedef std::map<std::string, float> StartNumble;
    typedef std::map<std::string, float> StartPercent;
    class StartNumbleModule
    {
    public:

        StartNumbleModule();
        StartNumbleModule(int numble1, int numble2, int numble3);
        ~StartNumbleModule();
        float getPercentWithScore(float score);
        StartPercent getPercentModule();
    private:
        void init(float numble1, float numble2, float numble3);
    private:
        StartNumble start_numble_;
        StartPercent start_percent_;
    };
}
#endif