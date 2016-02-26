//*******************************************************************************
//类名称   : BubbleColorPicker
//功能     : <发射泡泡的取色器>
//-------------------------------------------------------------------------------
//备注     : <用来存放当前地图中剩余泡泡的颜色>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_COLOR_PICKER_H_
#define _BUBBLE_COLOR_PICKER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleColorPicker
    {
    public:
        BubbleColorPicker();
        ~BubbleColorPicker();
        void init();
    public:
        void addColorWithBubbleColor(BubbleType color);
        void subtractColorWithBubbleColor(BubbleType color);
        BubbleType getBubbleColorFromPicker();
        //判断这个颜色是不是没有了
        bool needChangeBubbleType(BubbleType color);
        //设置这一把的颜色范围
        void setColorPickerRange();
        BubbleType getBubbleColorInRange();
    private:
        //判断是不是一个普通小球的类型
        bool isColorBubbleType(BubbleType color);
        std::vector<BubbleType> getColorPickerVector();
        //添加事件监听
        //void addEventListenerCustom();
        //void addColorWithEvent(cocos2d::EventCustom* event);
        //void subtractColorWithEvent(cocos2d::EventCustom* event);
    private:
        std::map<BubbleType, int> color_picker_;
        std::vector<BubbleType> color_range_;
        int color_total_;
    };
}
#endif //_BUBBLE_COLOR_PICKER_H_