//*******************************************************************************
//类名称   : RainbowCharactor
//功能     : <彩虹封印里面的人物>
//-------------------------------------------------------------------------------
//备注     :
//          
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _RAINBOW_CHARACTOR_H_
#define _RAINBOW_CHARACTOR_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio/CocoStudio.h"
namespace bubble_second {
    class RainbowSealBubble;
    class BaseBubble;
    class RainbowCharactor : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(RainbowCharactor);
        static RainbowCharactor* createWithFile(const std::string& path)
        {
            RainbowCharactor *pRet = new(std::nothrow) RainbowCharactor();
            if (pRet && pRet->initWithFile(path))
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
        ~RainbowCharactor();
        //开始封印
        void beginSealingCharactor(RainbowSealBubble* bubble);
        //封印转移
        void moveSealintCharactor(RainbowSealBubble* bubble, const cocos2d::Vec2& from_point);
        //改变封印的颜色(改变托着的小球颜色)
        void setRainbowColor(BubbleType color);
        //设置动画的路径
        void setArmaturePath(const std::string& path);
        std::string getArmaturePath();
    private:
        RainbowCharactor();
        //bool init();
        bool initWithFile(const std::string& path);
        void initTexture();
        void setSealedBubble(BaseBubble* bubble);
        BaseBubble* getSealedBubble();
        void addCharactorArmature();
        //void runFlyingAnimation(RainbowSealBubble* bubble, const cocos2d::Vec2& armature_point, bool armature_point_need_convert = true);
    private:
        //里面人物手上托的球
        BaseBubble* sealed_bubble_;
        cocos2d::Sprite* rainbow_swirl_;
        cocos2d::Sprite* rainbow_background_;
        std::string armature_path_;
    };
}
#endif //_RAINBOW_CHARACTOR_H_