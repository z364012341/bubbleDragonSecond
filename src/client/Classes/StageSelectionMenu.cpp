#include "StageSelectionMenu.h"
#include "SpriteTextureController.h"
#include "GameSamsung.h"
#include "SmartScaleController.h"
#include "UserDataManager.h"
#include "ZCGConfigDataDict.h"
#include "GameStageSelectionScene.h"
namespace bubble_second {
    StageSelectionMenu::StageSelectionMenu()
    {
    }

    StageSelectionMenu::~StageSelectionMenu()
    {
    }

    StageSelectionMenu * bubble_second::StageSelectionMenu::create(int cell_numble, int level, const StageType& type)
    {
        StageSelectionMenu *pRet = new(std::nothrow) StageSelectionMenu();
        if (pRet && pRet->init(cell_numble, level, type))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    bool StageSelectionMenu::init(int cell_numble, int level, const StageType& type)
    {
        this->addButton(cell_numble, level, type);
        this->addSamsung(UserDataManager::getInstance()->getStartNumbleWithLevel(level));
        this->addStageLabel(level); 
        this->setScale(STAGE_SELECTION_MENU_SCALE);
        this->addStageTypeTexture(type);
        this->setMenuState(cell_numble, level);
        return true;
    }

    void StageSelectionMenu::setMenuState(int cell_numble, int level)
    {
        static bool debugFlag = ZCGConfigDataDict::getInstance()->getIntData(ZCGConfigDataDict::KEY_OPEN_CMD_SHOW) == 1;
        int newest_stage_numble = UserDataManager::getInstance()->getStagePassCount()+1;
        if (level == newest_stage_numble)
        {
            this->turnOnBlink();
            UserDataManager::getInstance()->setPresentCell(cell_numble);
        }
        else if (UserDataManager::getInstance()->isCompletedGame())
        {
            UserDataManager::getInstance()->setPresentCell(cell_numble);
        }
        if (level <= newest_stage_numble || debugFlag)
        {
            this->setSelectionMenuEnable(true);
        }
        else
        {
            this->setSelectionMenuEnable(false);
        }
    }

    void StageSelectionMenu::addButton(int cell_numble, int level, const StageType& type)
    {
        button_sp_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_STAGE_SELECTION_MENU_PURPLE_PATH);
        this->addChild(button_sp_);
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(false);
        listener->onTouchBegan = [=](cocos2d::Touch *touch, cocos2d::Event *event) {
            touch_begin_position_ = touch->getLocation();
            this->setButtonEnable(true);
            cocos2d::Vec2 point = button_sp_->convertTouchToNodeSpaceAR(touch);
            cocos2d::Rect rect = button_sp_->getBoundingBox();
            return rect.containsPoint(point);
        };
        listener->onTouchMoved = [=](cocos2d::Touch *touch, cocos2d::Event *event) {
            if (touch_begin_position_.distance(touch->getLocation())>10.0f)
            {
                this->setButtonEnable(false);
            }
        };
        listener->onTouchEnded = [=](cocos2d::Touch *touch, cocos2d::Event *event) {
            if (this->isButtonEnable())
            {
                //EnterGameAlert* alert = EnterGameAlert::create(cell_numble, level, type);
                //cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
                //alert->setPosition(visibleSize.width/2, visibleSize.height/2);
                //alert->setScale(SmartScaleController::getInstance()->getFixedWidthZoom());
                //this->getSelectionLayer()->addChild(alert);

                StageData userData;
                userData.cell_numble = cell_numble;
                userData.level_numble = level;
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_POP_ENTER_GAME_ALERT, &userData);
            }
        };
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, button_sp_);
    }
    void StageSelectionMenu::addSamsung(int start_numble)
    {
        samsung_ = GameSamsung::createWithNumble(start_numble);
        samsung_->setScale(STAGE_SELECTION_MENU_SAMSUNG_SCALE);
        samsung_->setPosition(STAGE_SELECTION_MENU_SAMSUNG_POSITION);
        this->addChild(samsung_);
    }
    void StageSelectionMenu::addStageLabel(int level)
    {
        char str[10];
        sprintf(str, "%d", level);
        cocos2d::Label* label = cocos2d::Label::createWithSystemFont(str, "", STAGE_SELECTION_MENU_STAGE_LABEL_FONTSIZE);
        label->setPosition(STAGE_SELECTION_MENU_STAGE_LABEL_POSITION);
        this->addChild(label, 1);
    }
    void StageSelectionMenu::setButtonEnable(bool flag)
    {
        touch_enable_ = flag;
    }
    bool StageSelectionMenu::isButtonEnable()
    {
        return touch_enable_ && menu_enable_;
    }
    void StageSelectionMenu::addStageTypeTexture(const StageType& type)
    {
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createStageTypeSprite(type);
        sp->setPosition(STAGE_SELECTION_MENU_STAGETYPE_TEXTURE_POSITION);
        this->addChild(sp, 1);
    }
    void StageSelectionMenu::halfMoonSlash(const HalfMoonSlashDirection& direction)
    {
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(STAGE_SELECTION_MENU_HALFMOONSLASH_PATH);
        //sp->setPosition(60.0f, 15.0f);
        if (direction == kLeft)
        {
            sp->setFlippedX(true);
        }
        sp->setOpacity(120);
        cocos2d::ScaleTo* scale = cocos2d::ScaleTo::create(STAGE_SELECTION_MENU_HALFMOONSLASH_ACTION_DURATION, 3.0f);
        cocos2d::MoveBy* move = cocos2d::MoveBy::create(STAGE_SELECTION_MENU_HALFMOONSLASH_ACTION_DURATION, cocos2d::Vec2(15.0f*direction, 0.0f));
        cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(scale, move);
        cocos2d::CallFunc* func1 = cocos2d::CallFunc::create([=]() {
            sp->setVisible(true);
            sp->setPosition(STAGE_SELECTION_MENU_HALFMOONSLASH_POSITION_X*direction, STAGE_SELECTION_MENU_HALFMOONSLASH_POSITION_Y);
            sp->setScale(1.5f);
        });
        cocos2d::CallFunc* func2 = cocos2d::CallFunc::create([=]() {
            sp->setVisible(false);
        });
        cocos2d::DelayTime* time = cocos2d::DelayTime::create(STAGE_SELECTION_MENU_HALFMOONSLASH_DELAYTIME);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(func1, spawn, func2, time, nullptr);
        this->addChild(sp);
        sp->runAction(cocos2d::RepeatForever::create(seq));
    }
    cocos2d::Node * StageSelectionMenu::getSelectionLayer()
    {
        cocos2d::Node* parent = this->getParent();
        while (parent->getName() != GAME_STAGE_SELECTION_SCENE_NAME)
        {
            parent = parent->getParent();
        }
        return parent;
    }
    void StageSelectionMenu::turnOnBlink()
    {
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_STAGE_SELECTION_MENU_ORANGE_PATH);
        this->addChild(sp);
        cocos2d::FadeOut* fadeout = cocos2d::FadeOut::create(STAGE_SELECTION_MENU_THE_BLINK_FADE_DURATION);
        cocos2d::FadeIn* fadein = cocos2d::FadeIn::create(STAGE_SELECTION_MENU_THE_BLINK_FADE_DURATION);
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(fadeout, fadein);
        sp->runAction(cocos2d::RepeatForever::create(seq));
        this->halfMoonSlash(kLeft);
        this->halfMoonSlash(kRight);
    }
    void StageSelectionMenu::setSelectionMenuEnable(bool flag)
    {
        menu_enable_ = flag;
        if (flag)
        {
            SpriteTextureController::getInstance()->setSpriteTexture(GAME_STAGE_SELECTION_MENU_PURPLE_PATH, button_sp_);
        }
        else
        {
            SpriteTextureController::getInstance()->setSpriteTexture(GAME_STAGE_SELECTION_MENU_GRAY_PATH, button_sp_);
        }
    }
}