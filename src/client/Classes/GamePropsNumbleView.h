//*******************************************************************************
//类名称   : GamePropsNumbleView
//功能     : <道具显示右下角的数量格子>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_PROPS_NUMBLE_VIEW_H_
#define _GAME_PROPS_NUMBLE_VIEW_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class CenteredMenuItemSprite;
    class GamePropsNumbleView : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GamePropsNumbleView);
        virtual ~GamePropsNumbleView();
        void selected();
    private:
        GamePropsNumbleView();
        bool init();
        void addBackground();
        void addLabel();
        void addAdditionButton();
        void addTickTexture();
        void updateNumbleLabel();
        bool isNoProps();
    private:
        cocos2d::Value numble_value_;
        cocos2d::Sprite* background_ = nullptr;
        cocos2d::Sprite* tick_ = nullptr;
        cocos2d::Label* props_label_ = nullptr;
        bool selected_flag_ = false;
        CenteredMenuItemSprite* addition_item_ = nullptr;
    };
}
#endif //_GAME_PROPS_NUMBLE_VIEW_H_