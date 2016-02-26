#include "BaseWeapon.h"
//#include "BaseBubble.h"

namespace bubble_second {
    BaseWeapon::BaseWeapon()
    {
    }


    BaseWeapon::~BaseWeapon()
    {
    }

    bool BaseWeapon::inAttackRange(BubbleType color)
    {
        return true;
    }

    void BaseWeapon::attackBubble()
    {
    }

    bool BaseWeapon::init()
    {
        if (!cocos2d::Sprite::init())
        {
            return false;
        }
        //select_bubble_ = nullptr;
        return true;
    }

    //void BaseWeapon::setSelectBubble(BaseBubble* bubble)
    //{
    //    select_bubble_ = bubble;
    //    this->setPosition(select_bubble_->getPosition());
    //    select_bubble_->getParent()->addChild(this);
    //}
}