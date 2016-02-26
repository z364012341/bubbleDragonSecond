//*******************************************************************************
//类名称   : GameBaseAlert
//功能     : <游戏弹出面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_BASE_ALERT_H_
#define _GAME_BASE_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameBaseAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameBaseAlert);
        GameBaseAlert();
        virtual ~GameBaseAlert();
        void setCancelCallback(const cocos2d::ccMenuCallback& callback);
    protected:
        bool init();
        void addCancelButton();
        void addBlackMask();
        virtual void addBackground();
        virtual void addBigBackground();
        virtual void addTopBackground();
        virtual void cancelButtonCallback(cocos2d::Ref*);
    private:
        //cocos2d::Label* top_label_ = nullptr;
        cocos2d::MenuItem* cancel_item_ = nullptr;
    };
}
#endif // _GAME_BASE_ALERT_H_