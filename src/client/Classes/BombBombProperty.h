//*******************************************************************************
//类名称   : BombBombProperty
//功能     : <大当量炸弹道具, 一炸炸两圈>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BOMB_BOMB_PROPERTY_H_
#define _BOMB_BOMB_PROPERTY_H_
//#include "cocos2d.h"
#include "BaseProperty.h"
namespace bubble_second {
    class BombBombProperty : public BaseProperty
    {
    public:
        CREATE_FUNC(BombBombProperty);
        ~BombBombProperty();
    protected:
        void useItem() override;
        void cancelUseItem() override;
    private:
        BombBombProperty();
        bool init();
    };
}
#endif //_BOMB_BOMB_PROPERTY_H_