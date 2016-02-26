//*******************************************************************************
//类名称   : BaseWeapon
//功能     : <游戏中武器的基类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BASE_WEAPON_H_
#define _BASE_WEAPON_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    //class BaseBubble;
    class BaseWeapon : public cocos2d::Sprite
    {
    public:
        CREATE_FUNC(BaseWeapon);
        BaseWeapon();
        virtual ~BaseWeapon();
        //void setSelectBubble(BaseBubble* bubble);
        virtual bool inAttackRange(BubbleType color);
        virtual void attackBubble();
    protected:
        bool init();
    //private:
    //    BaseBubble* select_bubble_;
    };
}
#endif //_BASE_WEAPON_H_