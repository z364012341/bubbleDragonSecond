//*******************************************************************************
//类名称   : LoadingScene
//功能     : <loading界面>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _LOADING_SCENE_H_
#define _LOADING_SCENE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class LoadingScene : public cocos2d::Layer
    {
    public:
        static cocos2d::Scene* createScene();
        CREATE_FUNC(LoadingScene);
        LoadingScene();
        ~LoadingScene();
        bool init();
        void beginLoading();
        void addBackground();
    };
}
#endif //_LOADING_SCENE_H_