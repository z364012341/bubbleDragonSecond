//*******************************************************************************
//类名称   : GameScoreController
//功能     : <游戏中的得分连击控制器>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SCORE_CONTROLLER_H_
#define _GAME_SCORE_CONTROLLER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameScoreController
    {
    public:
        GETINSTANCE_FUNC(GameScoreController);
        ~GameScoreController();
    public:
        int getEliminateCombo();
        void clear();
        //增加消除得分
        void addScoreWithEliminateNumble(int numble);
        //增加一次连击
        void addOneCombo();
        //连击清零
        void eliminateComboClear();
        //增加得分
        void addScoreWithNumble(int numble);
        //增加任务总数
        void addGameTaskNumble();
        void setGameTaskNumble(int numble);
        //增加已完成任务数
        void addCompletedTaskNumble();
        void setCompletedTaskNumble(int numble);
        //获取任务总数
        int getGameTaskNumble() const;
        //获取已完成任务数
        int getCompletedTaskNumble() const;
        //游戏胜利
        bool gameVictory();
        //是否失败
        bool gameDefeat();
        bool noUseBubbleCount();
        //小球使用数量
        void setBubbleUseCount(int numble);
        void addBubbleUseCount(int numble);
        int getBubbleUseCount();
        void cutBubbleUseCount();
        void setBubbleUseCountEnable(bool flag);
        bool isBubbleUseCountEnable();
        //获取分数
        int getTotalScore();
    private:
        //void addEventListenerCustom();
        //总得分初始化
        void totalScoreClear();
        //任务总数初始化
        void gameTaskNumbleClear();
        //已完成任务数初始化
        void completedTaskNumbleClear();
        //加分
        void addScore(int numble);
        //分发得分事件
        void dispatchUpdateScoreEvent();
        void dispatchUpdateCompletedTaskEvent();
        void dispatchUpdateBubbleUseCount();
    private:
        GameScoreController();
    private:
        int eliminate_combo_;
        int total_score_;
        int game_task_numble_add_;
        int game_task_numble_set_;
        int completed_task_numble_add_;
        int completed_task_numble_set_;
        int bubble_use_count_;
        bool use_count_enable_;
    };
}
#endif //_GAME_SCORE_CONTROLLER_H_