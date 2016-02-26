//*******************************************************************************
//类名称   : StavesProperty
//功能     : <法杖道具>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAVES_PROPERTY_H_
#define _STAVES_PROPERTY_H_
#include "BaseProperty.h"
namespace bubble_second {
    class StavesProperty : public BaseProperty
    {
    public:
        ~StavesProperty();
        CREATE_FUNC(StavesProperty);
    protected:
        void useItem() override;
        void cancelUseItem() override;
    private:
        StavesProperty();
        bool init();
    };
}
#endif //_STAVES_PROPERTY_H_