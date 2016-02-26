//*******************************************************************************
//类名称   : WoodenHammerProperty
//功能     : <小木锤道具>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _WOODEN_HAMMER_PROPERTY_H_
#define _WOODEN_HAMMER_PROPERTY_H_
#include "BaseProperty.h"
namespace bubble_second {
    class WoodenHammerProperty : public BaseProperty
    {
    public:
        CREATE_FUNC(WoodenHammerProperty);
        ~WoodenHammerProperty();
    protected:
        void useItem() override;
        void cancelUseItem() override;
    private:
        WoodenHammerProperty();
        bool init();
    };
}
#endif //_WOODEN_HAMMER_PROPERTY_H_