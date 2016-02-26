//*******************************************************************************
//文件名         : <BarrelBottom.h>
//文件实现功能  : <下方水桶ui的桶底node>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//修改记录 :
//日 期        版本     修改人              修改内容
//2015/09/15   1.0     <黄泽昊>            <新添加>
//*******************************************************************************
#ifndef _BARREL_BOTTOM_H_
#define _BARREL_BOTTOM_H_
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    typedef bool EffectEnabled;
    class BarrelBottom : public cocos2d::Node
    {
    public:      
        static BarrelBottom* createWithName(const std::string& name)
        {
            BarrelBottom *pRet = new(std::nothrow) BarrelBottom();
            if (pRet && pRet->initScoreWithName(name))
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
        void contactOnce();
    private:
        //void onEnter() override;
        //void onExit() override;
        BarrelBottom();
        virtual ~BarrelBottom();
        bool initScoreWithName(const std::string& name);
        void initPhysicsBody();
        void initScore(const std::string& name);
        //播放小球撞到的特效
        void playEffect();
        //播放待机特效
        void playStandbyEffect();
        //初始化特效间隔时间
        void initialStacdbyEffectTime();
        void setStacdbyEffectTime(int time);
    private:
        int score_;
        EffectEnabled effect_flag_;
        int standby_effect_delaytime_max_;
    };
}
#endif //_BARREL_BOTTOM_H_