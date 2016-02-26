//*******************************************************************************
//类名称   : GamePauseAlert
//功能     : <游戏设置菜单>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_PAUSE_ALERT_H_
#define _GAME_PAUSE_ALERT_H_
#include "GameBaseAlert.h"
namespace bubble_second {
    class GamePauseAlert : public GameBaseAlert
    {
    public:
        CREATE_FUNC(GamePauseAlert);
        ~GamePauseAlert();
        void setReturnCallback(const cocos2d::ccMenuCallback& callback);
        void setReplayCallback(const cocos2d::ccMenuCallback& callback);
        void setContinueCallback(const cocos2d::ccMenuCallback& callback);
    private:
        GamePauseAlert();
        bool init();
        void addVolumeItem();
        void addButtonItem();
        void addBigBackground() override;
        void addTopLabel();
    private:
        cocos2d::MenuItem* return_item_ = nullptr;
        cocos2d::MenuItem* replay_item_ = nullptr;
        cocos2d::MenuItem* continue_item_ = nullptr;
    };
}
#endif //_GAME_PAUSE_ALERT_H_