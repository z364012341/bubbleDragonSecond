//*******************************************************************************
//类名称   : SimpleControlSwitch
//功能     : <简单开关>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _CENTERED_MENU_ITEM_SPRITE_H_
#define _CENTERED_MENU_ITEM_SPRITE_H_
#include "cocos2d.h"
namespace bubble_second {
    class CenteredMenuItemSprite : public cocos2d::MenuItemSprite
    {
    public:
        static CenteredMenuItemSprite * create(cocos2d::Node* normalSprite, cocos2d::Node* selectedSprite, const cocos2d::ccMenuCallback& callback)
        {
            CenteredMenuItemSprite *ret = new (std::nothrow) CenteredMenuItemSprite();
            ret->initWithNormalSprite(normalSprite, selectedSprite, nullptr, callback);
            ret->autorelease();
            return ret;
        }
        ~CenteredMenuItemSprite();
    private:
        CenteredMenuItemSprite();
        bool initWithNormalSprite(cocos2d::Node* normalSprite, cocos2d::Node* selectedSprite, cocos2d::Node* disabledSprite, const cocos2d::ccMenuCallback& callback);
    };
}
#endif //_CENTERED_MENU_ITEM_SPRITE_H_