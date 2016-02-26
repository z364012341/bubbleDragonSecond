#include "LightningBubble.h"
#include "GamePlayController.h"
#include "cocostudio/CocoStudio.h"
#include "GameScene.h"
namespace bubble_second {
    LightningBubble::LightningBubble()
    {
    }


    LightningBubble::~LightningBubble()
    {
    }

    bool LightningBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleLightning);
        //this->addBubbleStaticBody();
        return true;
    }

    void LightningBubble::downFromAir()
    {
        GamePlayController::getInstance()->disposeBuffBubbleDown(this);
        this->removeFromParent();
        //this->playTheSpecialEffects();
    }

    void LightningBubble::bubbleEliminate(int)
    { 
        this->removeFromParent();
        //this->playTheSpecialEffects();
    }

    float LightningBubble::playTheSpecialEffects()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        using cocostudio::MovementEventType;
        cocos2d::Node* parent = this->getParent();
        GameScene* game_scene = dynamic_cast<GameScene*>(parent->getParent()->getParent());
        if (!game_scene)
        {
            return 0.0f;
        }
        cocos2d::Vec2 convert_point = game_scene->convertMapToCsbSpace(this->getPosition());
        {
            cocos2d::LayerColor* layer_color = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0 , 0, LIGHTNING_BUBBLE_EFFECT_BLACK_EFFECT_OPACITY), 
                GAME_DESIGN_RESOLUTION_WIDTH, GAME_DESIGN_RESOLUTION_HEIGHT);
            parent->getParent()->addChild(layer_color);
            cocos2d::Sequence* seq = cocos2d::Sequence::create(cocos2d::DelayTime::create(0.2f) 
                , cocos2d::CallFunc::create([=]() {
                layer_color->setOpacity(TEXTURE_OPACITY);
                layer_color->setColor(cocos2d::Color3B::WHITE); 
            }), cocos2d::DelayTime::create(0.2f), cocos2d::CallFunc::create([=]() {
                layer_color->setOpacity(LIGHTNING_BUBBLE_EFFECT_BLACK_EFFECT_OPACITY);
                layer_color->setColor(cocos2d::Color3B::BLACK);
            }), cocos2d::DelayTime::create(0.1f),
                cocos2d::CallFunc::create([=]() { layer_color->removeFromParent(); }), nullptr);
            layer_color->runAction(seq);
        }
        {
            Armature*armature = Armature::create(LIGHTNING_BUBBLE_EFFECT_NAME);
            armature->setPosition(GAME_DESIGN_RESOLUTION_WIDTH / 2, convert_point.y);
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    armature->removeFromParent();
                }
            });
            parent->getParent()->addChild(armature);
        }
        {
            Armature*armature = Armature::create(BALL_LIGHTNING_BUBBLE_EFFECT_NAME);
            //armature->setGlobalZOrder(-10.0f);
            armature->setPosition(convert_point);
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    armature->removeFromParent();
                }
            });
            parent->getParent()->addChild(armature);
        }

        return LIGHTNING_BUBBLE_EFFECT_DELAY_TIME;
    }
}