#include "BaseBubble.h"
#include "BubbleFactory.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
namespace bubble_second {
    BaseBubble::BaseBubble()
    {
        run_eliminate_action_dalay_ = 0;
        suspension_flag_ = false;
        bubble_component_numble_ = 0;
    }

    BaseBubble::~BaseBubble()
    {
    }

    bool BaseBubble::init()
    {
        if (!cocos2d::Sprite::init())
        {
            return false;
        }
        this->initHandleEffect();
        return true;
    }

    void BaseBubble::setBubbleTexture(BubbleType type)
    {
        if (type >= 0)
        {
            //this->setSpriteFrame(BubbleFactory::getInstance()->getPathWithType(type));
            SpriteTextureController::getInstance()->setSpriteTexture(BubbleFactory::getInstance()->getPathWithType(type), this);
        }
    }

    //bool BaseBubble::operator==(const BaseBubble& bubble)
    //{
    //    return bubble_in_map_index_ == bubble.bubble_in_map_index_;
    //}

    void BaseBubble::setBubbleType(int type)
    {
        bubble_type_ = (BubbleType)type;
        this->setBubbleTexture(bubble_type_);
    }

    void BaseBubble::setBubbleIndex(cocos2d::Vec2 index)
    {
        bubble_in_map_index_ = index;
    }
    cocos2d::Vec2 BaseBubble::getBubbleIndex() const
    {
        return bubble_in_map_index_;
    }
    BubbleType BaseBubble::getBubbleType() const
    {
        return bubble_type_;
    }

    //cocos2d::Vec2 BaseBubble::getPointInMapNode()
    //{
    //    cocos2d::Vec2 point = this->getPosition();
    //    point.subtract(this->getParent()->getChildByName(BUBBLE_MAP_NODE_NAME)->getPosition());
    //    return point;
    //}

    void BaseBubble::bubbleEliminate(int combo)
    {
        if (this->getParent())
        {
            cocos2d::ScaleTo* scaleto = cocos2d::ScaleTo::create(0.02f, 1.3f);
            cocos2d::Sequence* seq_2 = cocos2d::Sequence::create(scaleto,
                cocos2d::CallFunc::create([=]() {
                char score_text[10];
                sprintf(score_text, "%d", SINGLE_BUBBLE_SCORE(combo));
                cocos2d::LabelAtlas* pop_score_label = cocos2d::LabelAtlas::create(
                    score_text, POP_SCORE_CHARMAP_PATH, POP_SCORE_CHARMAP_ITEMWIDTH, POP_SCORE_CHARMAP_ITEMHEIGHT, '.');
                pop_score_label->setAnchorPoint(POP_SCORE_ANCHORPOINT);
                pop_score_label->setScale(POP_SCORE_INITIAL_SCALE);
                pop_score_label->setPosition(this->getPosition());
                cocos2d::ScaleTo* scaleto_1 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_1_TIME, POP_SCORE_SCALETO_1_NUMBLE);
                cocos2d::ScaleTo* scaleto_2 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_2_TIME, POP_SCORE_SCALETO_2_NUMBLE);
                cocos2d::ScaleTo* scaleto_3 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_3_TIME, POP_SCORE_SCALETO_3_NUMBLE);
                cocos2d::ScaleTo* scaleto_4 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_4_TIME, POP_SCORE_SCALETO_4_NUMBLE);
                cocos2d::ScaleTo* scaleto_5 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_5_TIME, POP_SCORE_SCALETO_5_NUMBLE);
                cocos2d::MoveBy* move = cocos2d::MoveBy::create(POP_SCORE_MOVEBY_TIME, POP_SCORE_MOVEBY_VEC2);
                cocos2d::Sequence* seq = cocos2d::Sequence::create(scaleto_1, scaleto_2, scaleto_3, scaleto_4, scaleto_5,
                    cocos2d::DelayTime::create(POP_SCORE_DELAYTIME),
                    cocos2d::CallFunc::create([=]() {pop_score_label->removeFromParent(); }), NULL);
                cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(move, seq);
                this->getParent()->addChild(pop_score_label);
                pop_score_label->runAction(spawn);
                this->removeFromParent();
            }), NULL);
            this->runAction(seq_2);
        }
    }

    void BaseBubble::addBubbleStaticBody()
    {
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([=]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BUBBLE_RADIUS,
                cocos2d::PhysicsMaterial(BUBBLE_BODY_DENSITY,
                    BUBBLE_STATIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));
            body->setDynamic(false);
            body->setGravityEnable(false);
            body->setMass(BUBBLE_BODY_MASS);
            body->setCategoryBitmask(BITMASK_BUBBLE_STATIC_CATEGORY);
            body->setCollisionBitmask(BITMASK_BUBBLE_STATIC_COLLISION);
            body->setContactTestBitmask(BITMASK_BUBBLE_STATIC_CONTACTTEST);
            this->setPhysicsBody(body);
        }), NULL));
    }

    void BaseBubble::addBubbleDynamicBody()
    {
    }

    //cocos2d::PhysicsBody * BaseBubble::addBubbleWindmillBody()
    //{
    //    cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BUBBLE_RADIUS,
    //        cocos2d::PhysicsMaterial(0.0,
    //            0.0, 0.0));
    //    body->setDynamic(true);
    //    body->setGravityEnable(false);
    //    body->setGroup(-2);
    //    body->setMass(0);
    //    body->setLinearDamping(0.7);
    //    body->setAngularDamping(0.7);
    //    body->setCategoryBitmask(BITMASK_BUBBLE_STATIC_CATEGORY);
    //    body->setCollisionBitmask(BITMASK_BUBBLE_STATIC_COLLISION);
    //    body->setContactTestBitmask(BITMASK_BUBBLE_STATIC_CONTACTTEST);
    //    //this->runAction(cocos2d::CallFunc::create([=]()
    //    //{
    //        this->setPhysicsBody(body);
    //    //}));
    //    return this->getPhysicsBody();
    //}

    void BaseBubble::downFromAir()
    {
    }

    void BaseBubble::initHandleEffect()
    {
        key_to_handle_effect_[LONG_EFFECT_BUBBLE_KEY] = [=](const cocos2d::Vec2& point) {this->runLongContactEffect(point); };
        key_to_handle_effect_[SHORT_EFFECT_BUBBLE_KEY] = [=](const cocos2d::Vec2& point) {this->runShortContactEffect(point); };
    }

    //std::map<std::string, std::function<void(const cocos2d::Vec2&point)>> bubble_second::BaseBubble::getEffectHandleMap()
    //{
    //    return std::map<std::string, std::function<void(const cocos2d::Vec2&point)>>();
    //}

    void BaseBubble::runBubbleEffect(const std::string& name, const cocos2d::Vec2& point)
    {
        (key_to_handle_effect_[name])(point);

    }

    void BaseBubble::runLongContactEffect(const cocos2d::Vec2& point)
    {
        this->runContactAction(this->getEffectDistance(point, LONG_CONTACT_EFFECT_DISTANCE));
    }

    void BaseBubble::runShortContactEffect(const cocos2d::Vec2& point)
    {
        this->runContactAction(this->getEffectDistance(point, SHORT_CONTACT_EFFECT_DISTANCE));
    }

    void BaseBubble::runContactAction(const cocos2d::Vec2& point)
    {
        cocos2d::MoveBy* moveby = cocos2d::MoveBy::create(BUBBLE_CONTACT_TIME, point);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(moveby, moveby->reverse(), NULL);
        this->runAction(seq);
    }

    cocos2d::Vec2 BaseBubble::getEffectDistance(const cocos2d::Vec2& point, float distance)
    {
        cocos2d::Vec2 pos = this->getPosition();
        float s = pos.distance(point);
        float rad = asin((pos.x - point.x) / s);
        float x_offs = distance * sin(rad);
        float y_offs = distance * cos(rad);
        return cocos2d::Vec2(x_offs, y_offs);
    }

    void BaseBubble::setSupensionPoint(bool flag)
    {
        suspension_flag_ = flag;
    }

    void BaseBubble::setEliminateDelayTime(float time)
    {
        run_eliminate_action_dalay_ = time;
    }

    float BaseBubble::getEliminateDelayTime()
    {
        return run_eliminate_action_dalay_;
    }

    bool BaseBubble::isColorBubbleType()
    {
        if (this->getBubbleType()>= kNormalColorFirst && this->getBubbleType()<= kNormalColorLast)
        {
            return true;
        }
        return false;
    }

    bool BaseBubble::isComponentBubbleType()
    {
        BubbleType color = this->getBubbleType();
        if (color >= kBubbleComponentFirst && color <= kBubbleComponentLast)
        {
            return true;
        }
        return false;
    }

    bool BaseBubble::isSuspensionPoint()
    {
        return suspension_flag_;
    }

    bool BaseBubble::isWindmillBubble()
    {
        return this->getBubbleType() == kBubbleWindmill;
    }

    bool BaseBubble::isEqualType(BubbleType type)
    {
        return this->getBubbleType() == type;
    }

    void BaseBubble::addTouchEventListener()
    {
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        //listener->onTouchBegan = [=](cocos2d::Touch* ,cocos2d::Event*) {
        //    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SELECT_BUBBLE, this);
        //    return true;
        //};
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchSelectBubble, GamePlayController::getInstance());
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }

    void BaseBubble::removeTouchEventListener()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    }

    int BaseBubble::getBubbleComponentNumble()
    {
        return bubble_component_numble_;
    }

    void BaseBubble::setBubbleComponentNumble(int numble)
    {
        bubble_component_numble_ = numble;
    }

    void BaseBubble::hadContacted()
    {
        had_contacted_ = true;
    }

    bool BaseBubble::isHadContacted()
    {
        return had_contacted_;
    }

    bool BaseBubble::needRemoveFromBubbleMap()
    {
        return true;
    }

    float BaseBubble::playTheSpecialEffects()
    {
        return 0.0f;
    }

}
