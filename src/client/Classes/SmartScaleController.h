//*******************************************************************************
//类名称   : SmartScaleController
//功能     : <进行游戏中屏幕适配>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SMART_SCALE_CONTROLLER_H_
#define _SMART_SCALE_CONTROLLER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class SmartScaleController
    {
    public:
        GETINSTANCE_FUNC(SmartScaleController);
        ~SmartScaleController();
    public:
        float getPlayAreaZoom();
        float getFixedWidthZoom();
        float getFixedHeightZoom();
    private:
        SmartScaleController();
        void init();
    private:
        float play_area_zoom_;
        float fixed_width_zoom_;
        float fixed_height_zoom_;
    };
}
#endif //_SMART_SCALE_CONTROLLER_H_