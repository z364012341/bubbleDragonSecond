//*******************************************************************************
//类名称   : WoodenHammerSprite
//功能     : <小木锤精灵>
//-------------------------------------------------------------------------------
//备注     : <用在道具图标和使用的时候显示用>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _WOODEN_HAMMER_WEAPON_H_
#define _WOODEN_HAMMER_WEAPON_H_
#include "cocos2d.h"
#include "BaseWeapon.h"
namespace bubble_second {
    class WoodenHammerWeapon : public BaseWeapon
    {
    public:
        CREATE_FUNC(WoodenHammerWeapon);
        virtual ~WoodenHammerWeapon();
        void attackBubble() override;
    private:
        WoodenHammerWeapon();
        bool init();
    };
}
#endif //_WOODEN_HAMMER_WEAPON_H_