//*******************************************************************************
//类名称   : StageDataModule
//功能     : <关卡信息模块类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_DATA_MODULE_H_
#define _STAGE_DATA_MODULE_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "StartNumbleModule.h"
namespace bubble_second {
    typedef std::map<std::string, std::string> BubbleInfo;
    typedef std::vector<BubbleInfo> BubblesData;
    typedef std::vector<BubbleType> BubbleColorRange;
    class StageDataModule : public cocos2d::Ref
    {
    public:
        CREATE_FUNC(StageDataModule);
        ~StageDataModule();
        StageDataModule();
        bool init();
        void setBubblesData(const BubblesData& data);
        BubblesData getBubblesData();
        void setBubbleNumbleMax(int numble);
        int getBubbleNumbleMax();
        void setStartNumbleModule(StartNumbleModule module);
        StartNumbleModule getStartNumble();
        void setBubbleColorRange(const std::string& colorStr);
        BubbleColorRange getBubbleColorRange();
        void setStageType(int type);
        StageType getStageType();
        void setFallType(bool flag);
        bool isFallType();
    private:
        bool isInColorRange(char color_bit);
    private:
        BubblesData bubbles_data_;
        int bubble_numble_max_;
        StageType stage_type_;
        bool is_fall_type_ = false;
        StartNumbleModule start_numble_module_;
        BubbleColorRange bubble_color_range_;
    };
}
#endif //_STAGE_DATA_MODULE_H_