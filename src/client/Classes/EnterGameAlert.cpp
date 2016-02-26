#include "EnterGameAlert.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "CenteredMenuItemSprite.h"
#include "GameScene.h"
#include "EnterPropsViewManager.h"
namespace bubble_second {
    EnterGameAlert * EnterGameAlert::create(int cell_numble, int level, const StageType & type)
    {
        EnterGameAlert *pRet = new(std::nothrow) EnterGameAlert();
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
    EnterGameAlert::EnterGameAlert()
    {
    }

    EnterGameAlert::~EnterGameAlert()
    {
    }

    void EnterGameAlert::onExit()
    {
        GameBaseAlert::onExit();
        cocos2d::Director::getInstance()->getTextureCache()->removeUnusedTextures();
    }

    void EnterGameAlert::setBeginCallback(const cocos2d::ccMenuCallback & callback)
    {
        begin_item_->setCallback(callback);
    }
    bool EnterGameAlert::init(int cell_numble, int level, const StageType & type)
    {
        if (!GameBaseAlert::init())
        {
            return false;
        }
        //this->addBackground();
        this->addTopLabel(level);
        this->addStageTypeLabel(type);
        this->addCharactor();
        this->addPropsShow();
        this->addButtonItem();
        this->setBeginCallback([=](cocos2d::Ref*) {
            cocos2d::Scene* scene = GameScene::createScene(cell_numble, level);
            cocos2d::Director::getInstance()->replaceScene(scene);
        });
        this->setCancelCallback([=](cocos2d::Ref*) {
            this->removeFromParent();
        });

        SpriteTextureController::getInstance()->addGameBackgroundTexture(cell_numble);
        return true;
    }
    //void EnterGameAlert::addBackground()
    //{
    //    //背后的大背景
    //    cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH);
    //    this->addChild(bg);
    //    //上面的小背景
    //    cocos2d::Sprite* top_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH);
    //    cocos2d::Rect rect = bg->getBoundingBox();
    //    top_bg->setPosition(0.0f, rect.size.height / 2);
    //    top_bg->setTag(GAME_ALERT_TOP_BACKGROUND_TAG);
    //    this->addChild(top_bg);
    //}
    void EnterGameAlert::addTopLabel(int level)
    {
        //文字
        std::string str1 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_1_KEY);
        std::string str2 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_2_KEY);
        char str[20];
        sprintf(str, "%s  %d  %s", str1.c_str(), level, str2.c_str());
        cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(str, "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
        this->addChild(top_label);
    }
    void EnterGameAlert::addStageTypeLabel(const StageType & type)
    {
        //文字
        std::string str = GameTextInfo::getInstance()->getTextInfoWithStageType(type);
        cocos2d::Label* type_label = cocos2d::Label::createWithSystemFont(str, "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        type_label->setTextColor(GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_COLOR);
        cocos2d::Node* top_node = this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG);
        float x = top_node->getPositionX();
        float y = top_node->getPositionY() - top_node->getBoundingBox().size.height*0.75f;
        type_label->setPosition(x, y);
        this->addChild(type_label);
    }
    void EnterGameAlert::addCharactor()
    {
        {
            cocos2d::Sprite* charactor_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_VICTORY_ALERT_FLASH_LIGHT_BACKGROUND_PATH);
            this->addChild(charactor_bg);
        }
        {
            cocos2d::Sprite* charactor_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_ALERT_CHARACTOR_PATH);
            //cocos2d::Rect rect = charactor_sp->getBoundingBox();
            //charactor_sp->setTextureRect(cocos2d::Rect(0.0f, 0.0f, rect.size.width, rect.size.height*0.7f));
            charactor_sp->setPosition(ENTER_GAME_ALERT_CHARACTOR_POSITION);
            charactor_sp->setTag(ENTER_GAME_ALERT_CHARACTOR_TAG);
            this->addChild(charactor_sp);
        }
    }
    void EnterGameAlert::addPropsShow()
    {
        //背景
        cocos2d::Sprite* props_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_ALERT_PROPS_BACKGROUND_PATH);
        cocos2d::Node* node = this->getChildByTag(ENTER_GAME_ALERT_CHARACTOR_TAG);
        float y = node->getPositionY() - node->getBoundingBox().size.height / 6 - props_bg->getBoundingBox().size.height / 2.15f;
        props_bg->setPosition(node->getPositionX(), y);
        this->addChild(props_bg, 1);
        //选择道具 的背景
        cocos2d::Sprite* props_label_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_ALERT_PROPS_LABEL_BACKGROUND_PATH);
        props_label_bg->setScale(0.35f);
        props_label_bg->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
        cocos2d::Rect rect = props_bg->getBoundingBox();
        props_label_bg->setPosition(rect.origin.x, rect.origin.y + rect.size.height*0.95);
        this->addChild(props_label_bg);
        //选择道具 字
        cocos2d::Label* props_label = cocos2d::Label::createWithSystemFont(
            GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_SELECT_PROPS_LABEL_KEY), "", ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE);
        props_label->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
        props_label->setPosition(rect.origin.x+10.0f, rect.origin.y + rect.size.height);
        this->addChild(props_label);
        //道具展示
        //EnterGamePropsView* sight_props = EnterGamePropsView::create(SpriteTextureController::getInstance()->createGameSpriteWithPath("fzx.png"));
        //sight_props->setPosition(rect.origin.x + rect.size.width*0.2f, rect.origin.y + rect.size.height*0.6f);
        //this->addChild(sight_props, 3);
        cocos2d::Node* props_node = EnterPropsViewManager::getInstance()->createEnterPropsAlert();
        props_node->setPosition(-10.0f, rect.origin.y + rect.size.height*0.6f);
        this->addChild(props_node, 1);
    }

    void EnterGameAlert::addButtonItem()
    {
        {//x按钮
            this->addCancelButton();
        }
        {//开始按钮
            begin_item_ = SpriteTextureController::getInstance()->createMenuItemSprite(ENTER_GAME_ALERT_BEGIN_BUTTON_PATH);
            cocos2d::Menu* menu = cocos2d::Menu::createWithItem(begin_item_);
            menu->setPosition(this->getChildByTag(ENTER_GAME_ALERT_CHARACTOR_TAG)->getPositionX(), ENTER_GAME_ALERT_BEGIN_BUTTON_POSITION_Y);
            this->addChild(menu);
        }
    }
}