#include "EnterPropsViewManager.h"
#include "EnterGamePropsView.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "AimingLineCommodity.h"
#include "AddSpecialCommodity.h"
#include "AddBubbleNumbleCommodity.h"
namespace bubble_second {
    EnterPropsViewManager::EnterPropsViewManager()
    {
    }

    EnterPropsViewManager::~EnterPropsViewManager()
    {
    }

    cocos2d::Node* EnterPropsViewManager::createEnterPropsAlert()
    {
        cocos2d::Node* node = cocos2d::Node::create();
        EnterGamePropsView* sight_props = AimingLineCommodity::create();
        sight_props->setPosition(ENTER_GAME_PROPS_VIEW_LEFT_POS_X, 0.0f);
        this->setPropsSwitch(sight_props->getName());
        sight_props->addMenuCallback([=](cocos2d::Ref*) {
            this->setPropsSwitch(sight_props->getName(), !this->getPropsSwitchEnable(sight_props->getName()));
        });
        node->addChild(sight_props);

        EnterGamePropsView* add_special_bubble_props = AddSpecialCommodity::create();
        node->addChild(add_special_bubble_props);
        this->setPropsSwitch(add_special_bubble_props->getName());
        add_special_bubble_props->addMenuCallback([=](cocos2d::Ref*) {
            this->setPropsSwitch(add_special_bubble_props->getName(), !this->getPropsSwitchEnable(add_special_bubble_props->getName()));
        });

        EnterGamePropsView* add_bubble_props = AddBubbleNumbleCommodity::create();
        add_bubble_props->setPosition(-sight_props->getPositionX(), 0.0f);
        node->addChild(add_bubble_props);
        this->setPropsSwitch(add_bubble_props->getName());
        add_bubble_props->addMenuCallback([=](cocos2d::Ref*) {
            this->setPropsSwitch(add_bubble_props->getName(), !this->getPropsSwitchEnable(add_bubble_props->getName()));
        });

        return node;
    }
    void EnterPropsViewManager::setPropsSwitch(const std::string & props, bool pros_switch)
    {
        props_switch_[props] = pros_switch;
    }
    bool EnterPropsViewManager::getPropsSwitchEnable(const std::string & props)
    {
        return props_switch_.at(props);
    }
    int EnterPropsViewManager::getAddBubbleNumblePropsNumble()
    {
        return ADD_BUBBLE_NUMBLE_PROPS_NUMBLE;
    }
}