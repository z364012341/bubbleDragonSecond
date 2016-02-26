//*******************************************************************************
//类名称   : StageDataManager
//功能     : <游戏关卡信息管理类>
//-------------------------------------------------------------------------------
//备注     : <场景控制类,负责碰撞和触摸的回调>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_DATA_MANAGER_H_
#define _STAGE_DATA_MANAGER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageDataModule;
    class StageDataManager
    {
    public:
        GETINSTANCE_FUNC(StageDataManager);
        ~StageDataManager();
        void initStageData();
        StageDataModule* getStageDataWithNumble(int numble);
        //获取总关卡数
        int getStageTotalNumble();
        //获取关卡的类型
        StageType getStageTypeWithNumble(int numble);
        //是否是关卡数
        bool isInStageNumbleRange(int numble);
    private:
        StageDataManager();
        void addStageDataModule(StageDataModule* module);
    private:
        cocos2d::Vector<StageDataModule*> stage_data_map_;
    };
}
#endif //_STAGE_DATA_MANAGER_H_