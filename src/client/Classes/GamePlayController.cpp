#include<math.h>
#include "GamePlayController.h"
#include "GameScoreController.h"
#include "GameBubbleMap.h"
#include "ScoreWidget.h"
#include "BarrelBottom.h"
#include "BubbleColorPicker.h"
#include "SmartScaleController.h"
#include "BaseBubble.h"
#include "BlackHoleBubble.h"
#include "GameCharacter.h"
#include "BaseProperty.h"
#include "ColorBubble.h"
#include "GameScene.h"
#include "BubbleSightingDevice.h"
#include "BubbleSightingPoint.h"
namespace bubble_second {
    GamePlayController::GamePlayController()
    {
        this->initHandleMap();
        prepare_bubble_ = nullptr;
        select_bubble_ = nullptr;
        direction_ = 0;
    }

    GamePlayController::~GamePlayController()
    {
        if (bubble_map_)
        {
            bubble_map_->release();
        }
        if (color_picker_)
        {
            delete color_picker_;
            color_picker_ = nullptr;
        }
    }

    void GamePlayController::initHandleMap()
    {
        key_to_handle_map_[kBubbleNull] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleYellow] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubblePurple] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleBlue] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleRed] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleGreen] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleOrange] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubblePink] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleLightning] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleAddNumbleBubble] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleBlackHole] = &GamePlayController::disposeContactWithBlackHoleBubble;
        key_to_handle_map_[kBubbleBombBomb] = &GamePlayController::disposeContactWithColorBubble;
        props_to_handle_[kBubbleColorBomb] = &GamePlayController::disposeUsingPropertyBubble;
        props_to_handle_[kBubbleBombBombProperty] = &GamePlayController::disposeUsingPropertyBubble;
        key_to_handle_map_[kBubbleComponent] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleRainbowSeal] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleMutipleSeal] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleWindmill] = &GamePlayController::disposeContactWithColorBubble;

        name_to_contact_handle_[PREPARE_BUBBLE_NAME][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBubble(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][PREPARE_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBubble(nodeB, nodeA); };
       
        name_to_contact_handle_[BARREL_BOTTOM_NAME][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBarrelBottom(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][BARREL_BOTTOM_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBarrelBottom(nodeB, nodeA); };
       
        name_to_contact_handle_[SCORE_WIDGET_NAME][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithScoreWidget(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][SCORE_WIDGET_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithScoreWidget(nodeB, nodeA); };
        
        name_to_contact_handle_[COLOR_BOMB_BUBBLE_NAME][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBubble(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][COLOR_BOMB_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBubble(nodeB, nodeA); };
    
        name_to_contact_handle_[PROPS_BOMB_BOMB_NAME][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBubble(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][PROPS_BOMB_BOMB_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeContactWithBubble(nodeB, nodeA); };
    
        name_to_contact_handle_[WOODEN_HAMMER_CAST_NODE_NAME][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeBubbleCast(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][WOODEN_HAMMER_CAST_NODE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeBubbleCast(nodeB, nodeA); };

        name_to_contact_handle_[NAME_BUBBLE_SIGHTING_POINT][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeSightingPointContactBubble(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][NAME_BUBBLE_SIGHTING_POINT] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeSightingPointContactBubble(nodeB, nodeA); };

        name_to_contact_handle_[NAME_BUBBLE_SIGHTING_POINT][MAP_PHYSICS_BORDER_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeSightingPointContactBorder(nodeA, nodeB); };
        name_to_contact_handle_[MAP_PHYSICS_BORDER_NAME][NAME_BUBBLE_SIGHTING_POINT] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeSightingPointContactBorder(nodeB, nodeA); };

        name_to_contact_handle_[UI_NAME_WINDMILL_BORDER][PREPARE_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeWindmillBubbleBorder(nodeA, nodeB); };
        name_to_contact_handle_[PREPARE_BUBBLE_NAME][UI_NAME_WINDMILL_BORDER] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeWindmillBubbleBorder(nodeB, nodeA); };
    
        name_to_contact_handle_[UI_NAME_WINDMILL_BORDER][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeWindmillBubbleBorder(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][UI_NAME_WINDMILL_BORDER] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeWindmillBubbleBorder(nodeB, nodeA); };

        name_to_contact_handle_[UI_NAME_WINDMILL_BORDER][PROPS_BOMB_BOMB_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {nodeB->removeFromParent(); };
        name_to_contact_handle_[PROPS_BOMB_BOMB_NAME][UI_NAME_WINDMILL_BORDER] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {nodeA->removeFromParent();  };

        name_to_contact_handle_[UI_NAME_WINDMILL_BORDER][COLOR_BOMB_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {nodeB->removeFromParent(); };
        name_to_contact_handle_[COLOR_BOMB_BUBBLE_NAME][UI_NAME_WINDMILL_BORDER] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {nodeA->removeFromParent(); };


        name_to_contact_handle_[UI_NAME_FALL_BOTTOM_BORDER][MAP_BUBBLE_NAME] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeFallBubbleBorder(nodeA, nodeB); };
        name_to_contact_handle_[MAP_BUBBLE_NAME][UI_NAME_FALL_BOTTOM_BORDER] = [=](cocos2d::Node* nodeA, cocos2d::Node* nodeB) {this->disposeFallBubbleBorder(nodeB, nodeA); };

    }

    bool GamePlayController::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    {   
        if (!this->getBubbleShootEnabled())
        {
            return false;
        }
        auto touch_point = touch->getLocation();
        this->setTouchDirection(touch_point);
        this->disposeSightingDevice(touch_point);
        return true;
    }
    void GamePlayController::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    {
        this->disposeSightingDevice(touch->getLocation());
    }
    void GamePlayController::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        if (nullptr == prepare_bubble_)
        {
            return;
        }
        const cocos2d::Vec2 touch_location = this->convertGLToNodeSpace(touch->getLocation(), event->getCurrentTarget()->getChildByName(UI_NAME_GAME_PLAY_AREA_NODE));
        if (this->canShootingBubble(touch_location))
        { 
            this->shootPrepareBubble(touch_location);
        }
        this->turnOffSightingDevice();
    }

    bool GamePlayController::canShootingBubble(const cocos2d::Vec2& touch_location)
    {
        bool isCanShoot = this->isShootBubbleEnable(touch_location) && !this->exchangePrepareEnabled(touch_location);
        return isCanShoot;
    }

    void GamePlayController::setGameSceneDelegate(GameScene * scene_delegate)
    {
        game_scene_delegate_ = scene_delegate;
    }

    bool GamePlayController::onContactBegin(cocos2d::PhysicsContact& contact)
    {
        auto sprite_1 = dynamic_cast<cocos2d::Node*>(contact.getShapeA()->getBody()->getNode());
        auto sprite_2 = dynamic_cast<cocos2d::Node*>(contact.getShapeB()->getBody()->getNode());
        if (sprite_1 && sprite_2 && sprite_1->getPhysicsBody() && sprite_2->getPhysicsBody())
        {
            assert(name_to_contact_handle_[sprite_1->getName()][sprite_2->getName()]);
            auto contact_handle = name_to_contact_handle_[sprite_1->getName()][sprite_2->getName()];
            contact_handle(sprite_1, sprite_2);
        }
        return true;
    }

    void GamePlayController::onContactSeparate(cocos2d::PhysicsContact& contact)
    {
        auto sprite_1 = dynamic_cast<cocos2d::Node*>(contact.getShapeA()->getBody()->getNode());
        auto sprite_2 = dynamic_cast<cocos2d::Node*>(contact.getShapeB()->getBody()->getNode());
        if (!sprite_1 || !sprite_2)
        {
            return;
        }
        if (sprite_1->getName() != NAME_BUBBLE_SIGHTING_POINT && sprite_2->getName() != NAME_BUBBLE_SIGHTING_POINT)
        {
            return;
        }
        if (!dynamic_cast<BaseBubble*>(sprite_1) && !dynamic_cast<BaseBubble*>(sprite_2))
        {
            return;
        }
        auto vector = this->separateContactNodeWithName(MAP_BUBBLE_NAME, sprite_1, sprite_2);
        BubbleSightingPoint* point = dynamic_cast<BubbleSightingPoint*>(vector.back());
        if (point && vector.front()->getName() == MAP_BUBBLE_NAME)
        {
            point->cutContactCount();
        }
    }

    bool GamePlayController::isShootBubbleEnable(const cocos2d::Vec2& touch_location)
    {
        return this->getBubbleShootEnabled() &&this->isInShootArea(touch_location);
    }

    bool GamePlayController::isInShootArea(const cocos2d::Vec2& touch_location)
    {
        float angle = this->getPrepareBubbleAngle(touch_location);
        //分别看方向是在上面还是在下面
        return (getTouchDirection() == kUpside && angle > SHOOT_BUBBLE_ENABLED_DEGREE) || (getTouchDirection() == kUnderside && angle<SHOOT_BUBBLE_ENABLED_DEGREE*kUnderside);
    }

    float GamePlayController::getAngleWithVectors(const cocos2d::Vec2& point_1, const cocos2d::Vec2& point_2)
    {
        return CC_RADIANS_TO_DEGREES(asin((point_2.y - point_1.y) / point_1.distance(point_2)));
    }

    float GamePlayController::getPrepareBubbleAngle(const cocos2d::Vec2& point)
    {
        return this->getAngleWithVectors(prepare_bubble_->getPosition(), point);
    }

    void GamePlayController::disposeContactWithBubble(cocos2d::Node* flying_node, cocos2d::Node * contact_node)
    {
        BaseBubble* flying_bubble = dynamic_cast<BaseBubble*>(flying_node);
        if (flying_bubble->isHadContacted())
        {
            return;
        }
        flying_bubble->hadContacted();
        BaseBubble* contact_bubble = dynamic_cast<BaseBubble*>(contact_node);
        if (auto props_handle = props_to_handle_[flying_bubble->getBubbleType()])
        {//优先处理道具的球
            (this->*props_handle)(flying_bubble, contact_bubble);
        }
        else if (auto bubble_handle = key_to_handle_map_[contact_bubble->getBubbleType()])
        {
            (this->*bubble_handle)(flying_bubble, contact_bubble);
        }
    }

    void GamePlayController::disposeContactWithBarrelBottom(cocos2d::Node* barrel_node, cocos2d::Node* bubble_node)
    {
        if (bubble_node->getParent())
        {
            bubble_node->removeFromParent();
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CUT_AIR_BUBBLE_NUMBLE);
            dynamic_cast<BarrelBottom*>(barrel_node)->contactOnce();
        }
    }

    void GamePlayController::disposeContactWithScoreWidget(cocos2d::Node * widget_node, cocos2d::Node * bubble_node)
    {  
        ScoreWidget* contact_widget = dynamic_cast<ScoreWidget*>(widget_node);
        contact_widget->contactOnce();
    }

    void GamePlayController::setPrepareBubble(BaseBubble* color_bubble)
    {
        prepare_bubble_ = color_bubble;
    }

    void GamePlayController::clearPrepareBubble()
    {
        prepare_bubble_ = nullptr;
    }

    BaseBubble* GamePlayController::getPrepareBubble()
    {
        return prepare_bubble_;
    }

    void GamePlayController::shootPrepareBubble(const cocos2d::Vec2& touch_location)
    {
        dynamic_cast<ColorBubble*>(prepare_bubble_)->shoot(touch_location);
    }

    void GamePlayController::loadStageMap(int numble)
    {
        prepare_bubble_ = nullptr;
        select_bubble_ = nullptr;
        if (color_picker_)
        {
            delete color_picker_;
        }
        color_picker_ = new BubbleColorPicker();
        if (bubble_map_)
        {
            bubble_map_->release();
        }
        bubble_map_ = GameBubbleMap::create();
        bubble_map_->retain();
        bubble_map_->loadStageDataWithNumble(numble);
    }

    void GamePlayController::disposeContactWithColorBubble(BaseBubble* flying_bubble, BaseBubble* contacted_bubble)
    {
        bubble_map_->disposeContactBubble(flying_bubble, contacted_bubble->getBubbleIndex());      
    }

    void GamePlayController::setBubbleShootEnabled(bool flag)
    {
        shoot_bubble_enabled_ = flag;
    }

    bool GamePlayController::getBubbleShootEnabled()
    {
        return shoot_bubble_enabled_;
    }

    cocos2d::Vector<cocos2d::Node*> GamePlayController::separateContactNodeWithName(const std::string & name, 
        cocos2d::Node* node_a, cocos2d::Node* node_b)
    {//0索引的是跟参数名字一样的小球
        cocos2d::Vector<cocos2d::Node*> node_vector;
        node_vector.pushBack(node_a->getName() == name ? node_a : node_b);
        node_vector.pushBack(node_a->getName() != name ? node_a : node_b);
        return node_vector;
    }

    cocos2d::Vector<cocos2d::Node*> GamePlayController::separateContactNodeWithTag(int tag, cocos2d::Node * node_a, cocos2d::Node * node_b)
    {
        cocos2d::Vector<cocos2d::Node*> node_vector;
        node_vector.pushBack(node_a->getTag() == tag ? node_a : node_b);
        node_vector.pushBack(node_a->getTag() != tag ? node_a : node_b);
        return node_vector;
    }

    void GamePlayController::addPrepareColor(BubbleType color)
    {
        color_picker_->addColorWithBubbleColor(color);
    }

    void GamePlayController::subtractPrepareColor(BubbleType color)
    {
        color_picker_->subtractColorWithBubbleColor(color);
    }

    BubbleType GamePlayController::getBubbleColorFromPicker()
    {
        return color_picker_->getBubbleColorFromPicker();
    }

    void GamePlayController::setBubbleColorRange()
    {
        color_picker_->setColorPickerRange();
    }

    bool GamePlayController::exchangePrepareBubbleOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        return true;
    }

    void GamePlayController::exchangePrepareBubbleOnTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {

    }

    void GamePlayController::exchangePrepareBubbleOnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        const cocos2d::Vec2& touch_location = this->convertGLToNodeSpace(touch->getLocation(), event->getCurrentTarget()->getParent());
        bool exchange_flag = this->exchangePrepareEnabled(touch_location);
        if (needExchangePrepareBubble(exchange_flag))
        {
            this->setBubbleShootEnabled(!exchange_flag);
            cocos2d::EventCustom event(EVENT_EXCHANGE_BUBBLE);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
        }
    }

    bool bubble_second::GamePlayController::needExchangePrepareBubble(bool exchange_flag)
    {
        return this->getBubbleShootEnabled() && this->getBubbleShootEnabled() == exchange_flag;
    }

    bool GamePlayController::exchangePrepareEnabled(const cocos2d::Vec2& touch_point)
    {
        return this->touchInGunsight(touch_point) || this->touchInGrass(touch_point);
    }

    bool bubble_second::GamePlayController::touchInGunsight(const cocos2d::Vec2 & touch_point)
    {
        float distance = touch_point.distance(game_scene_delegate_->getGunsight()->getPosition());
        return  distance <= GUNSIGHT_EXCHANGE_DISTANCE;
    }

    bool bubble_second::GamePlayController::touchInGrass(const cocos2d::Vec2 & touch_point)
    {
        float distance = touch_point.distance(game_scene_delegate_->getGrass()->getPosition());
        return  distance <= GRASS_EXCHANGE_DISTANCE;
    }

    void GamePlayController::disposeSightingPointContactBubble(cocos2d::Node* sight_node, cocos2d::Node* other_node)
    {
        auto sight_point = dynamic_cast<BubbleSightingPoint*>(sight_node);
        sight_point->addContactCount();
        if (BubbleSightingDevice* device = dynamic_cast<BubbleSightingDevice*>(sight_node->getParent()))
        {
            device->contactBubble();
        }
    }

    void GamePlayController::disposeSightingPointContactBorder(cocos2d::Node* sight_node, cocos2d::Node* other_node)
    {
        if (BubbleSightingDevice* device = dynamic_cast<BubbleSightingDevice*>(sight_node->getParent()))
        {
            device->contactWorldBorder();
        }
    }

    void GamePlayController::disposeWindmillBubbleBorder(cocos2d::Node * border_node, cocos2d::Node * other_node)
    {
        cocos2d::Node* bubble_node = this->separateContactNodeWithTag(COLOR_BUBBLE_TAG, border_node, other_node).front();
        bubble_map_->disposeWindmillBubbleContactBorder(dynamic_cast<BaseBubble*>(bubble_node));
    }

    void GamePlayController::disposeFallBubbleBorder(cocos2d::Node * border_node, cocos2d::Node * other_node)
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_DEFEAT);
    }

    cocos2d::Vec2 GamePlayController::convertGLToNodeSpace(const cocos2d::Vec2& touch_location, cocos2d::Node* node)
    {
        return node->convertToNodeSpace(touch_location);
    }

    void GamePlayController::disposeContactWithBlackHoleBubble(BaseBubble* flying_node, BaseBubble* blackhole_node)
    {
        bubble_map_->disposeContactBlackHoleBubble(flying_node, blackhole_node);
    }

    void GamePlayController::disposeUsingPropertyBubble(BaseBubble* flying_node, BaseBubble* contacted_bubble)
    {
        if (contacted_bubble->isEqualType(kBubbleBlackHole))
        {
            this->disposeContactWithBlackHoleBubble(flying_node, contacted_bubble);
            return;
        }
        bubble_map_->disposeUsedPropertyBubble(flying_node, contacted_bubble->getBubbleIndex());
    }

    void GamePlayController::prepareBubbleChangeType(BaseBubble* bubble)
    {
        if (bubble&&color_picker_->needChangeBubbleType(bubble->getBubbleType()))
        {
            bubble->setBubbleType(color_picker_->getBubbleColorFromPicker());
        }
        if (prepare_bubble_&&color_picker_->needChangeBubbleType(prepare_bubble_->getBubbleType()))
        {
            prepare_bubble_->setBubbleType(color_picker_->getBubbleColorFromPicker());
        }
    }

    void GamePlayController::disposeBuffBubbleDown(BaseBubble* bubble)
    {
        bubble_map_->disposeBuffBubbleDown(bubble);
    }

    void GamePlayController::disposeDarkCloudBubble(const cocos2d::Vec2& contact_index)
    {
        bubble_map_->disposeDarkCloudBubble(contact_index);
    }

    void GamePlayController::checkAirBubbles()
    {
        bubble_map_->checkAirBubbles();
    }

    void GamePlayController::adjustGameScenePosition()
    {
        bubble_map_->adjustGameScenePosition();
    }

    bool GamePlayController::touchPropertyBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto sprite = dynamic_cast<BaseProperty*>(event->getCurrentTarget());
        return this->touchOnIt(touch->getLocation(), sprite);
    }

    void GamePlayController::touchPropertyMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }

    void GamePlayController::touchPropertyEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto sprite = dynamic_cast<BaseProperty*>(event->getCurrentTarget());
        if (this->touchOnIt(touch->getLocation(), sprite) && sprite->isPropertyEnabled())
        {
            sprite->touchItem();
        }
    }

    bool GamePlayController::touchSelectBubble(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto node = dynamic_cast<cocos2d::Node*>(event->getCurrentTarget());
        if (this->touchOnIt(touch->getLocation(), node))
        {
            auto bubble = dynamic_cast<BaseBubble*>(node);
            if (!bubble)
            {
                bubble = dynamic_cast<BaseBubble*>(node->getParent());
            }
            this->setSelectBubble(bubble);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SELECT_BUBBLE, bubble);
            return true;
        }
        return false;
    }

    bool GamePlayController::touchOnIt(const cocos2d::Vec2& point, cocos2d::Node* sprite)
    {
        const cocos2d::Vec2 touch_location = this->convertGLToNodeSpace(point, sprite->getParent());
        if (sprite->getBoundingBox().containsPoint(touch_location))
        {
            return true;
        }
        return false;
    }

    void GamePlayController::disposeBubbleCast(cocos2d::Node* cast_node, cocos2d::Node* bubble_node)
    {
        auto weapon_box = dynamic_cast<WeaponBox*>(bubble_node);
        if (weapon_box && !(weapon_box->isEqualType(kBubbleNull) || weapon_box->isEqualType(kBubbleWindmill)))
        {
            this->setSelectBubble(weapon_box);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_RECENT_BUBBLE_CAST, select_bubble_);
        }
    }

    void GamePlayController::findBubblesInVisibleSize()
    {
        bubble_map_->findBubblesInVisibleSize();
    }

    void GamePlayController::disposeUseWoodenHammer()
    {
        bubble_map_->disposeUseWoodenHammer(select_bubble_);
        this->setSelectBubble(nullptr);
    }
    void GamePlayController::setSelectBubble(WeaponBox* bubble)
    {
        select_bubble_ = bubble;
    }

    void GamePlayController::disposeUseStaves()
    {
        bubble_map_->disposeUseStaves(select_bubble_);
        this->setSelectBubble(nullptr);
    }

    void GamePlayController::disposeSightingDevice(const cocos2d::Vec2& touch_point)
    {
        static int numble = 0;
        if (numble >= 5)
        {//减少触发次数以提高性能
            ++numble;
            return;
        }
        numble = 0;
        if (this->canShootingBubble(touch_point))
        {
            float angle = this->getSightingDeviceAngle(this->convertGLToNodeSpace(touch_point, prepare_bubble_->getParent()));
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_ROTATE_SIGHTING_DEVICE, &angle);
            this->turnOnSightingDevice();
        }
        else
        {
            this->turnOffSightingDevice();
        }
    }

    void GamePlayController::disposeVictory()
    {
        this->setBubbleShootEnabled(false);
        bubble_map_->disposeGameVictory();
    }

    void GamePlayController::disposeDefeat()
    {
        this->setBubbleShootEnabled(false);
    }

    void GamePlayController::usedAddSpecialBubbleProps()
    {
        bubble_map_->disposeUsedAddSpecialBubbleProps();
    }

    float GamePlayController::getSightingDeviceAngle(const cocos2d::Vec2& touch_location)
    {
        float angle = this->getPrepareBubbleAngle(touch_location);
        cocos2d::Vec2 pre_point = prepare_bubble_->getPosition();
        int direction = touch_location.x > pre_point.x? 1: -1;
        float device_angle = (90 - angle)*direction;
        if (this->isTouchUnderside())
        {
            device_angle = device_angle - 180 * direction;
        }
        return device_angle;
    }

    bool bubble_second::GamePlayController::isTouchUnderside()
    {
        return this->getTouchDirection() == kUnderside;
    }

    void GamePlayController::setTouchDirection(const cocos2d::Vec2& touch_point)
    {
        if (this->getBubbleShootEnabled())
        {
            cocos2d::Vec2 bubble_point = prepare_bubble_->getPosition();
            cocos2d::Vec2 sub_numble = this->convertGLToNodeSpace(touch_point, prepare_bubble_->getParent()) - bubble_point;
            this->setTouchDirection(sub_numble.y < 0 ? kUnderside : kUpside);//方向系数
        }
    }

    void GamePlayController::setTouchDirection(TouchDirection direction)
    {
        direction_ = direction;
    }

    TouchDirection GamePlayController::getTouchDirection()
    {
        return direction_;
    }

    void GamePlayController::turnOnSightingDevice()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_TURN_ON_SIGHTING_DEVICE);
    }

    void GamePlayController::turnOffSightingDevice()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_TURN_OFF_SIGHTING_DEVICE);
    }

}                                                              