//*******************************************************************************
//类名称   : ScoreProgressStart
//功能     : <游戏场景顶部的分数进度条上面的星星>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SCORE_PROGRESS_START_H_
#define _SCORE_PROGRESS_START_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ScoreProgressStart : public cocos2d::Sprite
    {
    public:
        static ScoreProgressStart* createWithPercent(float percent);
        //static ScoreProgressStart* createWithSwitchFlag(bool flag);
        CREATE_FUNC(ScoreProgressStart);
        ~ScoreProgressStart(); 
        void controlLightWithPercent(float percent);
        void controlLightWithFlag(bool flag);
        bool startIsOn();
    private:
        bool initWithPercent(float percent);
        //bool initWithSwitchFlag(bool flag);
        bool init();
        void startTurnOn();
        void startTurnOff();
        ScoreProgressStart();
        void setStartPercent(float percent);
        float getStartPercent();
        void setStartSpriteShader(const std::string& shader_path);
        bool isNeedTurnOn(float percent);
    private:
        float start_percent_ = 0.0f;
        bool start_on_flag_ = true;
    };
}
#endif