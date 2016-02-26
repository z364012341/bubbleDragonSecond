//*******************************************************************************
//类名称   : EnterGamePropsView
//功能     : <道具显示右下角的数量格子>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _ENTER_GAME_PROPS_VIEW_H_
#define _ENTER_GAME_PROPS_VIEW_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GamePropsNumbleView;
    class EnterGamePropsView : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(EnterGamePropsView);
        //传入道具的展示
        static EnterGamePropsView* create(cocos2d::Sprite* props);
        void addCostView(const cocos2d::Value& value);
        virtual ~EnterGamePropsView();
        void addMenuCallback(const cocos2d::ccMenuCallback& callback);
    protected:
        EnterGamePropsView();
        bool init(cocos2d::Sprite* props);
    private:
        void addBackground();
        void addPropsTexture(cocos2d::Sprite* props);
        void addPropsNumbleView();
    private:
        cocos2d::MenuItemSprite* background_ = nullptr;
        GamePropsNumbleView* props_numble_view_ = nullptr;
        cocos2d::Value props_value_;
        cocos2d::ccMenuCallback menu_callback_ = nullptr;
    };
}
#endif //_ENTER_GAME_PROPS_VIEW_H_