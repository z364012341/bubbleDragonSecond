//*******************************************************************************
//类名称   : ColorBubble
//功能     : <普通的彩色泡泡类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _COLOR_BUBBLE_H_
#define _COLOR_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
namespace bubble_second {
    class DarkCloudBubble;
    class ColorBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(ColorBubble);
        static ColorBubble* createWithType(int type, int cloud)
        {
            ColorBubble *pRet = new(std::nothrow) ColorBubble();
            if (pRet && pRet->initWithTypeAndCloud(type, cloud))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
    public:
        //播放撞击动画
        //void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point);
        ////计算撞击特效的方向
        //cocos2d::Vec2 getEffectDistance(const cocos2d::Vec2& point, float distance);
        //添加作为发射小球的刚体
        virtual void addBubblePrepareBody();
        void addBubbleStaticBody() override;
        //发射小球
        void shoot(const cocos2d::Vec2& touch_location);
        //发射小球后发送自定义事件
        virtual void dispatchEventAfterShooted();
        void bubbleEliminate(int combo) override;
        bool isDarkCloudBubble();
        void destroyDarkCloud();
        //单独播放消除特效
        void playEliminateEffect();
        //胜利后喷射
        void shootAfterVictory();
        //延迟不碰撞
        void delayNotCollision();
        //变成随机特殊泡泡
        void changeRandomSpecialBubble(const cocos2d::Vec2& point, StageType stage_type);
    protected:
        ColorBubble();
        bool initWithTypeAndCloud(int type, int cloud = kBubbleNoCloud);
        virtual ~ColorBubble();
        //从空中掉落
        void downFromAir() override;
    private:
        bool init();
        bool initWithType(int type);
        void initHandleEffect();
        void runPreBubbleContactEffect(const cocos2d::Vec2& contact_point);
        //添加动态刚体, 为了使小球从空中掉落
        virtual void addBubbleDynamicBody() override;
        //根据点击的位置获取发射的冲量
        cocos2d::Vec2 getImpulseByTouchlocation(cocos2d::Vec2 touch_location);
    private:
        DarkCloudBubble* cloud_bubble_;
    };
}
#endif //_COLOR_BUBBLE_H_