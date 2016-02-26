#include "CenteredMenuItemSprite.h"


namespace bubble_second {
    CenteredMenuItemSprite::CenteredMenuItemSprite()
    {
    }


    CenteredMenuItemSprite::~CenteredMenuItemSprite()
    {
    }

    bool CenteredMenuItemSprite::initWithNormalSprite(cocos2d::Node * normalSprite, cocos2d::Node * selectedSprite, cocos2d::Node * disabledSprite, const cocos2d::ccMenuCallback & callback)
    {
        cocos2d::MenuItemSprite::initWithNormalSprite(normalSprite, selectedSprite, disabledSprite, callback);
        cocos2d::Node* sele_image = this->getSelectedImage();
        sele_image->setAnchorPoint(cocos2d::Vec2((sele_image->getScaleX() - 1) / 2, (sele_image->getScaleY() - 1) / 2));
        return true;
    }
}