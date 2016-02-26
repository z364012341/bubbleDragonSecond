#include "GameCharacter.h"
#include "GameCharacterFactory.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
namespace bubble_second {
    GameCharacter::GameCharacter()
    {
        charactor_armature_ = nullptr;
    }


    GameCharacter::~GameCharacter()
    {
    }

    //void GameCharacter::onEnter()
    //{
    //    Sprite::onEnter();
    //}

    //void GameCharacter::onExit()
    //{
    //    Sprite::onExit();
    //    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    //}

    //bool GameCharacter::initWithName(const std::string& name)
    //{
    //    if (!Sprite::init())
    //    {
    //        return false;
    //    }
    //    this->setTypeWithName(name);

    //    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    //    listener->setSwallowTouches(true);
    //    listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchToChangeTexture, GamePlayController::getInstance());
    //    listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::touchToMoveCharecter, GamePlayController::getInstance());
    //    cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    //    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    //    return true;
    //}

    //void GameCharacter::setTypeWithName(const std::string& name)
    //{
    //    SpriteTextureController::getInstance()->setSpriteTexture(GameCharacterFactory::getInstance()->getPathWithName(name), this);
    //    this->setName(name);
    //}

    //bool GameCharacter::touchToChangeTexture(cocos2d::Touch* touch, cocos2d::Event* event)
    //{   
    //    //auto sprite = dynamic_cast<cocos2d::Sprite*>(event->getCurrentTarget());
    //    auto gamescene = dynamic_cast<GameScene*>(this->getParent()->getParent());
    //    if (cocos2d::Rect(touch->getLocation(), cocos2d::Size(0.0f, 0.0f)).intersectsRect(this->getSelfRect()))
    //    {
    //        this->setTypeWithName(GameCharacterFactory::getInstance()->getChangePathWithName(this->getName()));
    //        return true;
    //    }

    //    return false;
    //}
    //void GameCharacter::changeTexture()
    //{
    //    //this->setTypeWithName(GameCharacterFactory::getInstance()->getChangePathWithName(this->getName()));
    //}
    bool GameCharacter::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addCharacterArmature();
        this->playStandbyAnimation();
        return true;
    }
    void GameCharacter::addCharacterArmature()
    {
        charactor_armature_ = cocostudio::Armature::create(GAME_CHARACTER_ARMATURE_NAME);
        this->addChild(charactor_armature_);
    }
    void GameCharacter::playStandbyAnimation()
    {
        //auto armature = this->getCharactorArmature();
        //armature->getAnimation()->play(GAME_CHARACTER_ANIMATION_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        this->playLoopAnimationWithName(GAME_CHARACTER_ANIMATION_STANDBY_NAME);
    }
    void GameCharacter::playShootBubbleAnimation()
    {
        this->playNotLoopAnimationWithName(GAME_CHARACTER_ANIMATION_SHOOT_BUBBLE_NAME);
    }
    void GameCharacter::playLegendaryAnimation()
    {
        this->playNotLoopAnimationWithName(GAME_CHARACTER_ANIMATION_LEGENDARY_NAME);
    }
    void GameCharacter::playVictoryAnimation()
    {
        this->playLoopAnimationWithName(GAME_CHARACTER_ANIMATION_VICTORY_NAME);
    }
    void GameCharacter::playDefeatAnimation()
    {
        auto armature = this->getCharactorArmature();
        armature->getAnimation()->stop();
        this->setDefeatFlag(true);
        armature->getAnimation()->play(GAME_CHARACTER_ANIMATION_DEFEAT_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
    }
    cocostudio::Armature * GameCharacter::getCharactorArmature()
    {
        return charactor_armature_;
    }
    void GameCharacter::playNotLoopAnimationWithName(const std::string& name)
    {
        auto armature = this->getCharactorArmature();
        armature->getAnimation()->stop();
        armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE && !isDefeat())
            {
                this->playStandbyAnimation();
            }
        });
    }
    void GameCharacter::playLoopAnimationWithName(const std::string & name)
    {
        auto armature = this->getCharactorArmature();
        armature->getAnimation()->stop();
        armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, true);
    }

    void GameCharacter::setDefeatFlag(bool flag)
    {
        defeat_flag_ = flag;
    }

    bool GameCharacter::isDefeat()
    {
        return defeat_flag_;
    }
}