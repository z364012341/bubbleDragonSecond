//*******************************************************************************
//类名称   : BubbleColorRender
//功能     : <泡泡颜色随机>
//-------------------------------------------------------------------------------
//备注     : <场景控制类,负责碰撞和触摸的回调>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_COLOR_RENDER_H_
#define _BUBBLE_COLOR_RENDER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleColorRender
    {
    public:
        BubbleColorRender(const std::vector<BubbleType>& color_vector);
        ~BubbleColorRender();
        BubbleType getRandomColorWithColor(BubbleType color);
    private:
        void initWithColorVector(const std::vector<BubbleType>& color_vector);
        void mixBubbleColor(const std::vector<BubbleType>& color_vector);
    private:
        std::map<BubbleType, BubbleType> color_to_color_;
    };
}
#endif //_BUBBLE_COLOR_RENDER_H_