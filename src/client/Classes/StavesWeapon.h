//*******************************************************************************
//类名称   : StavesWeapon
//功能     : <法杖武器>
//-------------------------------------------------------------------------------
//备注     : <法杖的选择图标>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAVES_WEAPON_H_
#define _STAVES_WEAPON_H_
#include "BaseWeapon.h"
namespace bubble_second {
    class StavesWeapon : public BaseWeapon
    {
    public:
        CREATE_FUNC(StavesWeapon);
        virtual ~StavesWeapon();
        void attackBubble() override;
        bool inAttackRange(BubbleType color);
    private:
        StavesWeapon();
        bool init();
    //private:
    //    std::map<BubbleType, bool> color_to_range_;
    };
}
#endif //_STAVES_WEAPON_H_