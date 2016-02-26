//*******************************************************************************
//类名称   : GameSettingAlert
//功能     : <游戏设置面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SETTING_ALERT_H_
#define _GAME_SETTING_ALERT_H_
#include "GameBaseAlert.h"
#include "ui\UITextField.h"
namespace bubble_second {
    class GameSettingAlert : public GameBaseAlert
    {
    public:
        CREATE_FUNC(GameSettingAlert);
        virtual ~GameSettingAlert();
        void onExit() override;
    private:
        GameSettingAlert();
        bool init();
        void addVolumeItem();
        void addTopLabel();
        void addNicknameInput();
        void addHelpInfo();
        //void cancelButtonCallback(cocos2d::Ref* ref) override;
    private:
        cocos2d::ui::TextField* nickname_textfield = nullptr;
    };
}
#endif //_GAME_SETTING_ALERT_H_