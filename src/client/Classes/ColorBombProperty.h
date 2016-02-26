//*******************************************************************************
//类名称   : ColorBombProperty
//功能     : <彩球道具类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _COLOR_BOMB_PROPERTY_H_
#define _COLOR_BOMB_PROPERTY_H_
#include "cocos2d.h"
#include "BaseProperty.h"
namespace bubble_second {
    class ColorBombProperty : public BaseProperty
    {
    public:
        CREATE_FUNC(ColorBombProperty);
        ~ColorBombProperty();
    protected:
        void useItem() override;
        void cancelUseItem() override;
        bool init();
        //void haveUsedProperty(cocos2d::EventCustom*) override; 
    private:
        //void haveUsedColorBombBubble(cocos2d::EventCustom*);
    private:
        ColorBombProperty();

    };
}
#endif //_COLOR_BOMB_PROPERTY_H_