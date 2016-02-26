//*******************************************************************************
//类名称   : GameVolControlView
//功能     : <声音控制组件>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_VOL_CONTROL_VIEW_H_
#define _GAME_VOL_CONTROL_VIEW_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameVoluemSwitch;
    class GameVolControlView : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVolControlView);
        ~GameVolControlView();
        void onExit() override;
    private:
        GameVolControlView();
        bool init();
        void addVolumeSwitch();
    private:
        GameVoluemSwitch* effect_switch_ = nullptr;
        GameVoluemSwitch* music_switch_ = nullptr;
    };
}
#endif //_GAME_VOL_CONTROL_VIEW_H_