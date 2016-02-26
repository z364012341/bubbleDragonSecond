//*******************************************************************************
//类名称   : BubbleFactory
//功能     : <泡泡工厂类..负责创建各种泡泡的实例化对象>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_FACTORY_H_
#define _BUBBLE_FACTORY_H_
#include "BaseBubble.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ColorBubble;
    class BubbleFactory
    {
    public:
        GETINSTANCE_FUNC(BubbleFactory);
        //根据输入的类型来创建并返回泡泡
        BaseBubble* createBubbleWithType(int type, int cloud=-1);
        BaseBubble* createBubbleWithType(int type, cocos2d::Vec2 index, cocos2d::Vec2 point, int cloud = kBubbleNoCloud);
    public:
        std::string getPathWithType(int type);
    private:
        BubbleFactory();
        ~BubbleFactory();
        //表驱动容器初始化
        void initHandleMap();
        void initBubblePath();
    private:
        //表驱动容器
        //typedef ColorBubble*(*pHandle)(int);
        std::map<int, std::function<BaseBubble*(int, int)>> key_to_handle_map_;
        std::map<int, std::string> key_to_path;
    };
}
#endif //_BUBBLE_FACTORY_H_