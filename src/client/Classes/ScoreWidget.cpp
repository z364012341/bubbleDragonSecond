#include "ScoreWidget.h"
#include "ScoreWidgetManager.h"
#include "GameScoreController.h"
#include "SmartScaleController.h"
#include <sstream>
namespace bubble_second {
    ScoreWidget::ScoreWidget() :widget_combo_(0), armature_(nullptr)
    {
        type_update_to_type_[kScoreWidgetBlue] = kScoreWidgetPink;
        type_update_to_type_[kScoreWidgetPink] = kScoreWidgetGreen;
        type_update_to_type_[kScoreWidgetGreen] = kScoreWidgetGreen;
        type_to_score_[kScoreWidgetBlue] = SCORE_WIDGET_BLUE_SCORE;
        type_to_score_[kScoreWidgetPink] = SCORE_WIDGET_YELLOW_SCORE;
        type_to_score_[kScoreWidgetGreen] = SCORE_WIDGET_GREEN_SCORE;
    }

    ScoreWidget::~ScoreWidget()
    {
        this->unscheduleAllCallbacks();
    }

    bool ScoreWidget::initWithType(const ScoreWidgetType& type)
    {
        if (!cocos2d::Sprite::init())
        {
            return false;
        }
        pop_score_label_ = nullptr;
        this->addArmature();
        this->setType(type);
        this->setName(SCORE_WIDGET_NAME);
        return true;
    }

    void ScoreWidget::removeScoreWidget()
    {
        auto body = this->getPhysicsBody();
        if (body)
        {
            body->removeFromWorld();
        }
        cocos2d::MoveBy* move = cocos2d::MoveBy::create(SCOREWIDGET_FLY_OUT_TIME,
            cocos2d::Vec2(0, cocos2d::Director::getInstance()->getVisibleSize().height) / SmartScaleController::getInstance()->getPlayAreaZoom());
        cocos2d::Sequence* seq = cocos2d::Sequence::create(move, cocos2d::CallFunc::create([=]() {
            this->removeFromParent();
        }), nullptr);
        this->runAction(seq);
    }
    void ScoreWidget::setType(const ScoreWidgetType& type)
    {
        type_ = type;
        for (auto var : ScoreWidgetManager::getInstance()->getWidgetBonePathMap())
        {
            armature_->getBone(var.first)->changeDisplayWithIndex((int)type, true);
        }
    }

    void ScoreWidget::addPhysicsBody()
    {
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([&]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(SCORE_WIDGET_BODY_RADIUS,
                cocos2d::PhysicsMaterial(PHYSICS_SCORE_WIDGET_BODY_DENSITY,
                    PHYSICS_SCORE_WIDGET_BODY_RESTITUTION, PHYSICS_SCORE_WIDGET_BODY_FRICTION));
            body->setDynamic(false);
            body->setGravityEnable(false);
            body->setCategoryBitmask(BITMASK_SCORE_WIDGET_CATEGORY);
            body->setCollisionBitmask(BITMASK_SCORE_WIDGET_COLLISION);
            body->setContactTestBitmask(BITMASK_SCORE_WIDGET_CONTACTTEST);
            this->setPhysicsBody(body);
        }), NULL));
    }

    void ScoreWidget::updateScoreWidgetType()
    {
        this->setType(type_update_to_type_[type_]);
        this->comboClear();
    }

    ScoreWidgetType ScoreWidget::getType()
    {
        return type_;
    }

    void ScoreWidget::addOneCombo()
    {
        if (combo_flag_)
        {
            ++widget_combo_;
            if (widget_combo_ > SCORE_WIDGET_MAX_COMBO)
            {
                this->comboClear();
            }
			this->unschedule(CC_SCHEDULE_SELECTOR(ScoreWidget::turnOffCombo));
        }
        else
        {
            this->comboClear();
            combo_flag_ = true;
        }
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(ScoreWidget::turnOffCombo), SCORE_WIDGET_COMBO_DELAY);
    }

    void ScoreWidget::turnOffCombo(float)
    {
        combo_flag_ = false;
    }

    cocos2d::LabelAtlas * ScoreWidget::getPopScoreLabel()
    {
        return pop_score_label_;
    }

    void ScoreWidget::setPopScoreLabel(cocos2d::LabelAtlas* label)
    {
        pop_score_label_ = label;
    }

    void ScoreWidget::comboClear()
    {
        widget_combo_ = ScoreWidgetManager::getInstance()->getScoreWidgetTotalWithType(type_);
        combo_flag_ = false;
    }

    void ScoreWidget::contactOnce()
    {        
        this->addOneCombo();
        int score = this->getContactScore();
        GameScoreController::getInstance()->addScoreWithNumble(score);
        this->runContactAction(score);
    }

    int ScoreWidget::getContactScore()
    {
        return type_to_score_[type_]*widget_combo_;
    }

    void ScoreWidget::runContactAction(int score)
    {  
        auto b = canPlayingContactAnimation();
        if (canPlayingContactAnimation())
        {
            this->updatePopScoreLabel(score);
            this->setPlayContactAnimationEnabled(false);
            armature_->getAnimation()->play(SCOREWIDGET_ANIMATION_CONTACT_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    this->setPlayContactAnimationEnabled(true);
                }
            });
        }
        else
        {
            auto label = this->getPopScoreLabel();
            if (label)
            {
                std::string str = label->getString();
                std::stringstream out;
                out << str;
                int score = 0;
                out >> score;
                this->updatePopScoreLabel(score);
            }
        }
    }

    void ScoreWidget::addArmature()
    {
        armature_ = cocostudio::Armature::create(SCOREWIDGET_ARMATURE_BLUE_NAME);
        this->addChild(armature_);
        for (auto var1: ScoreWidgetManager::getInstance()->getWidgetBonePathMap())
        {
            for (auto var2 : var1.second)
            {
                cocostudio::Skin *skin = cocostudio::Skin::create(var2.second);
                armature_->getBone(var1.first)->addDisplay(skin, (int)var2.first);
            }
        }
    }

    void ScoreWidget::playFlyingAnimation(float duration)
    {
        armature_->getAnimation()->play(SCOREWIDGET_ANIMATION_FLYING_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(duration), cocos2d::CallFunc::create([=]() {
            armature_->getAnimation()->stop();
            armature_->getAnimation()->play(SCOREWIDGET_ANIMATION_FLYING_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        }));
        armature_->runAction(seq);
    }

    void ScoreWidget::updatePopScoreLabel(int score)
    {
        std::stringstream out;
        out << score;
        std::string str = "";
        out >> str;
        auto score_label = this->getPopScoreLabel();
        if (score_label)
        {
            score_label->setString(str);
        }
        else
        {
            score_label = cocos2d::LabelAtlas::create(
                str, POP_SCORE_CHARMAP_PATH, POP_SCORE_CHARMAP_ITEMWIDTH, POP_SCORE_CHARMAP_ITEMHEIGHT, '.');
            score_label->setAnchorPoint(POP_SCORE_ANCHORPOINT);
            score_label->setPosition(0.0f, 30.0f);
            score_label->setScale(POP_SCORE_INITIAL_SCALE);
            this->addChild(score_label);
            cocos2d::ScaleTo* scaleto_1 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_1_TIME, POP_SCORE_SCALETO_1_NUMBLE);
            cocos2d::ScaleTo* scaleto_2 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_2_TIME, POP_SCORE_SCALETO_2_NUMBLE);
            cocos2d::ScaleTo* scaleto_3 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_3_TIME, POP_SCORE_SCALETO_3_NUMBLE);
            cocos2d::ScaleTo* scaleto_4 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_4_TIME, POP_SCORE_SCALETO_4_NUMBLE);
            cocos2d::ScaleTo* scaleto_5 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_5_TIME, POP_SCORE_SCALETO_5_NUMBLE);
            cocos2d::MoveBy* move = cocos2d::MoveBy::create(POP_SCOREWIDGET_SCORE_MOVE_TIME, POP_SCOREWIDGET_SCORE_MOVE_VEC2);
            cocos2d::Sequence* seq_1 = cocos2d::Sequence::create(move, cocos2d::CallFunc::create([=]() {
                score_label->removeFromParent();
                this->setPopScoreLabel(nullptr);
            }), NULL);
            cocos2d::Sequence* seq_2 = cocos2d::Sequence::create(scaleto_1, scaleto_2, scaleto_3, scaleto_4, scaleto_5, NULL);
            cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(seq_1, seq_2);
            score_label->runAction(spawn);
            this->setPopScoreLabel(score_label);
        }
    }

    bool ScoreWidget::canPlayingContactAnimation()
    {
        return action_flag_;
    }

    void ScoreWidget::setPlayContactAnimationEnabled(bool flag)
    {
        action_flag_ = flag;
    }

    void ScoreWidget::runEnterAction()
    {
        cocos2d::ccBezierConfig config;
        config.endPosition = this->getSelfPosition();
        config.controlPoint_1 = this->getPosition();
        config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
        this->runAction(cocos2d::Sequence::createWithTwoActions(bezier, cocos2d::CallFunc::create([=]() {
            this->addPhysicsBody();
        })));
        this->playFlyingAnimation(SCORE_WIDGET_BEZIER_FLYING_DURATION);
    }

    void ScoreWidget::runFirstEnterActioin()
    {
        auto self_position = this->getSelfPosition();
        auto size = cocos2d::Director::getInstance()->getVisibleSize() / SmartScaleController::getInstance()->getPlayAreaZoom();
        if (self_position.x > 0.0f)
        {
            this->setPosition(size.width / 2, INITIAL_SCORE_WIDGET_POS_Y);
        }
        else
        {
            this->setPosition(size.width / -2, INITIAL_SCORE_WIDGET_POS_Y);
        }
        cocos2d::ccBezierConfig config;
        config.endPosition = self_position;
        config.controlPoint_1 = this->getPosition();
        config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
        this->runAction(bezier);
        this->playFlyingAnimation(SCORE_WIDGET_BEZIER_FLYING_DURATION);
        this->addPhysicsBody();
    }

    void ScoreWidget::setSelfPosition(const cocos2d::Vec2& point)
    {
        self_position_ = point;
    }

    cocos2d::Vec2 ScoreWidget::getSelfPosition()
    {
        return self_position_;
    }
}