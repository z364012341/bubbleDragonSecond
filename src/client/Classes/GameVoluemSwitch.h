//*******************************************************************************
//类名称   : GameVoluemSwitch
//功能     : <游戏设置菜单声音开关>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_VOLUEM_SWITCH_H_
#define _GAME_VOLUEM_SWITCH_H_
#include "cocos2d.h"
namespace bubble_second {
    class SimpleControlSwitch;
    class GameVoluemSwitch : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVoluemSwitch);
        ~GameVoluemSwitch();
        void setSwitchState(bool flag);
        void setMenuCallback(const cocos2d::ccMenuCallback& callback);
        bool getSwitchState();
    private:
        GameVoluemSwitch();
        bool init();
    private:
        SimpleControlSwitch* vol_switch_ = nullptr;
    };
}
#endif //_GAME_VOLUEM_SWITCH_H_