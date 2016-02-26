#include "BubbleSightingPoint.h"
#include "BubbleSecondConstant.h"
#include "SpriteTextureController.h"
#include "BubbleSightingDevice.h"
namespace bubble_second {
    BubbleSightingPoint::BubbleSightingPoint()
    {
    }


    BubbleSightingPoint::~BubbleSightingPoint()
    {
    }

    bool BubbleSightingPoint::init()
    {
        if (!cocos2d::Sprite::init())
        {
            return false;
        }
        SpriteTextureController::getInstance()->setSpriteTexture(BUBBLE_SIGHTING_POINT_PATH, this);
        this->setName(NAME_BUBBLE_SIGHTING_POINT);
        return true;
    }

    void BubbleSightingPoint::addPhysicsBodyCanntWorld()
    {
        cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createBox(cocos2d::Size(SIGHTING_POINT_BODY_RADIUS, SIGHTING_POINT_BODY_RADIUS),
            cocos2d::PhysicsMaterial(PHYSICS_SIGHTING_POINT_BODY_DENSITY, PHYSICS_SIGHTING_POINT_BODY_RESTITUTION, PHYSICS_SIGHTING_POINT_BODY_FRICTION));
        body->setDynamic(true);
        body->setCategoryBitmask(BITMASK_SIGHTING_POINT_INITIAL_CATEGORY);
        body->setCollisionBitmask(0);
        body->setContactTestBitmask(BITMASK_SIGHTING_POINT_INITIAL_CONTACTTEST);
        body->setGravityEnable(false);
        body->setGroup(BUBBLE_BODY_GROUP);
        this->setPhysicsBody(body);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.0f), cocos2d::CallFunc::create([=]() {
            body->setCategoryBitmask(BITMASK_SIGHTING_POINT_CATEGORY);
            body->setContactTestBitmask(BITMASK_SIGHTING_POINT_CONTACTTEST);
        })));
    }

    void BubbleSightingPoint::setPointEnabled(bool flag)
    {
        this->setVisible(flag);
    }

    void BubbleSightingPoint::addContactCount()
    {
        ++contact_count_;
    }

    void BubbleSightingPoint::cutContactCount()
    {
        if (contact_count_ != 0)
        {
            --contact_count_;
        }
    }
    void BubbleSightingPoint::clearContactCount()
    {
        contact_count_ = 0;
        this->setPointEnabled(true);
    }
    bool BubbleSightingPoint::isContacting()
    {
        if (0 != contact_count_)
        {
            return true;
        }
        return false;
    }

    void BubbleSightingPoint::changeSelfColor(BubbleType color)
    {
        auto controller = SpriteTextureController::getInstance();
        switch (color)
        {   
        case kBubbleYellow:
            controller->setSpriteTexture(SIGHT_POINT_YELLOW_PATH, this);
            break;
        case kBubblePurple:
            controller->setSpriteTexture(SIGHT_POINT_PURPLE_PATH, this);
            break;
        case kBubbleBlue:
            controller->setSpriteTexture(SIGHT_POINT_BLUE_PATH, this);
            break;
        case kBubbleRed:
            controller->setSpriteTexture(SIGHT_POINT_RED_PATH, this);
            break;
        case kBubbleGreen:
            controller->setSpriteTexture(SIGHT_POINT_GREEN_PATH, this);
            break;
        case kBubbleOrange:
            controller->setSpriteTexture(SIGHT_POINT_ORANGE_PATH, this);
            break;
        case kBubblePink:
            controller->setSpriteTexture(SIGHT_POINT_PINK_PATH, this);
            break;
        case kBubbleBombBombProperty:
            controller->setSpriteTexture(BUBBLE_SIGHTING_POINT_PATH, this);
            break;
        case kBubbleColorBomb:
            controller->setSpriteTexture(SIGHT_POINT_COLORFUL_PATH, this);
            break;
        default:
            assert(false);
            break;
        }
    }

}