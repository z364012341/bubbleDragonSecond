//*******************************************************************************
//类名称   : BubbleSightingPoint
//功能     : <游戏泡泡的喵准器发射出来的点
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_SIGHTING_POINT_H_
#define _BUBBLE_SIGHTING_POINT_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleSightingPoint : public cocos2d::Sprite
    {
    public:
        CREATE_FUNC(BubbleSightingPoint);
        ~BubbleSightingPoint();
        //void addImpulse();
        //void addPhysicsBody();
        void addPhysicsBodyCanntWorld();
        //设置显示
        void setPointEnabled(bool flag);
        //碰撞计数
        void addContactCount();
        void cutContactCount();
        void clearContactCount();
        //是否正在碰撞
        bool isContacting();
        //改变颜色
        void changeSelfColor(BubbleType color);
        //设置是否碰到顶部边界
        //void setContactTopBorder();
    private:
        BubbleSightingPoint();
        bool init();
        //cocos2d::Vec2 getPointInCsbSpace();
    private:
        //正在碰撞的总数
        int contact_count_ = 0;
    };
}
#endif //_BUBBLE_SIGHTING_POINT_H_