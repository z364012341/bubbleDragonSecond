//*******************************************************************************
//类名称   : BubbleSightingDevice
//功能     : <游戏泡泡的喵准器>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_SIGHTING_DEVICE_H_
#define _BUBBLE_SIGHTING_DEVICE_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleSightingPoint;
    typedef cocos2d::Vector<BubbleSightingPoint*> SightPointVector;
    class BubbleSightingDevice : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BubbleSightingDevice);
        ~BubbleSightingDevice();
        void rotateSightingDevice(const float angle, const float& max_pos_y);
        void contactWorldBorder();
        void contactBubble();
        //打开设备
        void turnOnDeviceOnce(int device_numble = 0);
        //改变颜色
        void changePointsColor(BubbleType color);
        //是否碰到顶部边界
        bool isContactTopBorder(const float& max_pos_y);
        //是否是第一台设备
        bool isFirstDevice();
        //保存第一台设备的角度用来计算顶部反弹的位置
        void setFirstDeviceAngle(const float& angle);
        float getFirstDeviceAngle() const;
        //碰到顶部反弹后让剩下的离远点
        void deviceGoAway();
    private:
        BubbleSightingDevice();
        bool init();
        //获取下一级面准线的位置
        cocos2d::Vec2 getReflectionPoint();
        //控制point的显示
        void setSightingPointsVisibled();
        //计算瞄准点的最小位置y
        float getSightingPointsMinPositionY();
        //判断是否瞄到
        bool isContactBubble();
        //判断瞄准点是否需要隐藏
        bool isSightingPointsNeedHidden(const cocos2d::Vec2& point, float min_y, float max_y);
        //targetID  {set get}
        void setTargetID(int numble);
        int getTargetID() const;
        //旋转剩余的设备
        void rotateRemainDevice(const float angle, const cocos2d::Vec2& point, const float& max_pos_y);
        void setDeviceRotationAndPosition(float angle, const cocos2d::Vec2& point);
        //计算顶部反弹的位置
        //先按普通的算法算出位置, 如果位置超过顶部, 就重新计算位置
        //第一个参数: 还没偏移过的点的位置
        //第二个参数: 顶部位置
        cocos2d::Vec2 calculateReflectTopPosition(const cocos2d::Vec2& point, const float& max_pos_y);
        void setTopReflectRotationAndPosition(float angle, const cocos2d::Vec2& point, const float& max_pos_y);
        cocos2d::Vec2 convertLocalToCsbSpace(const cocos2d::Vec2& local_point);
        //设置是否要隐藏点点
        void setHidePointEnable(bool flag);
        bool isHidePoint();
        //发射点出去
        void sightingPointMove();
        //hypotenuse_offset_ set get
        void setHypotenuseOffset(float offset);
        float getHypotenuseOffset();
        //max_top_y_ set get
        void setMaxTopY(float numble);
        float getMaxTopY();
    private:
        static float max_top_y_; //顶部的最高坐标y   这个是csb的坐标
        size_t points_index_ = 0;
        BubbleSightingDevice* sight_device_ = nullptr;
        SightPointVector sighting_points_;
        int target_id_ = 0;
        static float first_device_angle_;
        bool is_hide_point_ = false;
        float hypotenuse_offset_ = 0.0f; //斜边偏移, 让瞄准线的点有反弹效果
    };
}
#endif //_BUBBLE_SIGHTING_DEVICE_H_