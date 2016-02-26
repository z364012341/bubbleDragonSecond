//*******************************************************************************
//类名称   : GameStageSelectionScene
//功能     : <游戏的关卡选择场景>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_STAGE_SELECTION_SCENE_H_
#define _GAME_STAGE_SELECTION_SCENE_H_
#include "BubbleSecondConstant.h"
#include "cocos-ext.h"
#include "GUI\CCScrollView\CCScrollView.h"
namespace bubble_second {
    using cocos2d::extension::ScrollView;
    class GameStageSelectionCell;
    class GameStageSelectionScene : public cocos2d::Layer, public cocos2d::extension::ScrollViewDelegate
    {
    public:
        static cocos2d::Scene* createScene();
        static cocos2d::Scene* createSceneWithStageData(StageData data);
        CREATE_FUNC(GameStageSelectionScene);
        ~GameStageSelectionScene();
        void scrollViewDidScroll(ScrollView* view) override;
        cocos2d::Vec2 getScorllViewOffset(int cell_numble);
        void onEnter() override;
        void onExit() override;
    private:
        GameStageSelectionScene();
        bool init();
        //增加关卡单元
        void addStageCell();
        //增加自定义事件
        void addEventListenerCustom();
        void removeEventListenerCustom();
        //增加鼠标事件
        void addMouseEventListener();
        //键盘事件
        void addKeyboardEventListener();
        //弹出进入alert
        void popEnterGameAlert(StageData data);
        //过关后进入下一关的接口
        void enterNextStage(StageData data);
        //设置按钮
        void addSettingMenu();
        void popSettingAlert();
        //进入场景调整滚动视图位置
        void adjustingScrollviewPosition();
        //创建滚动内容
        cocos2d::Layer* createScrollViewContentLayer();
    private:
        float scrollview_bottom_height_ = 0.0f;
        cocos2d::Vector<GameStageSelectionCell*> cell_vector_;
        //记录滚动条的位置
        static cocos2d::Vec2 scrollview_offset_;
        float scale_zoom_ = 1.0f;
        ScrollView* scrollview_ = nullptr;
    };
}
#endif //_GAME_STAGE_SELECTION_SCENE_H_