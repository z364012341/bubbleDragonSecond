#include "GameStageSelectionScene.h"
#include "SpriteTextureController.h"
#include "GameStageSelectionCell.h"
#include "SmartScaleController.h"
#include "UserDataManager.h"
#include "StageDataManager.h"
#include "EnterGameAlert.h"
#include "GameSettingAlert.h"
#include "cocostudio\CocoStudio.h"
//#include "cocos-ext.h"
#include "StageNumble.h"
namespace bubble_second {
    cocos2d::Vec2 GameStageSelectionScene::scrollview_offset_ = cocos2d::Vec2::ZERO;
    GameStageSelectionScene::GameStageSelectionScene()
    {
    }
    GameStageSelectionScene::~GameStageSelectionScene()
    {
    }

    void GameStageSelectionScene::scrollViewDidScroll(ScrollView * view)
    {
        auto layout = view->getContainer();    
        float currentY = layout->getPositionY();     
        if (currentY > scrollview_bottom_height_) 
        { 
            view->setContentOffset(cocos2d::Vec2(0.0f, scrollview_bottom_height_)); 
        }
        if (-currentY > layout->getContentSize().height - view->getViewSize().height) 
        {
            view->setContentOffset(cocos2d::Vec2(0, -layout->getContentSize().height + view->getViewSize().height));
        }
        scrollview_offset_ = view->getContentOffset();
    }

    cocos2d::Vec2 GameStageSelectionScene::getScorllViewOffset(int cell_numble)
    {
        float pos_y = (-cell_vector_.at(cell_numble)->getPositionY() + GAME_STAGE_SCROLLVIEW_CELL_OFFSET_OFFSET)*scale_zoom_;
        cocos2d::Vec2 point = cocos2d::Vec2(0.0f, pos_y);
        return point;
    }

    void GameStageSelectionScene::onEnter()
    {
        cocos2d::Layer::onEnter();
        this->addEventListenerCustom();
        this->addMouseEventListener();
        this->addKeyboardEventListener();
    }

    void GameStageSelectionScene::onExit()
    {
        cocos2d::Layer::onExit();
        this->removeEventListenerCustom();
    }

    cocos2d::Scene * bubble_second::GameStageSelectionScene::createScene()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        scene->addChild(layer);
        return scene;
    }
    cocos2d::Scene * GameStageSelectionScene::createSceneWithStageData(StageData data)
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        layer->enterNextStage(data);
        scene->addChild(layer);
        return scene;
    }
    bool GameStageSelectionScene::init()
    {
        scale_zoom_ = SmartScaleController::getInstance()->getFixedWidthZoom();
        this->setName(GAME_STAGE_SELECTION_SCENE_NAME);
        this->addStageCell();
        this->addSettingMenu();
        return true;
    }

    void GameStageSelectionScene::addStageCell()
    {
        int stage_numble = GAME_STAGE_NUMBLE_BEGIN;
        //int cell_numbel = GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN;
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        float cell_x = visibleSize.width / 2;
        float cell_y = GAME_STAGE_SCROLLVIEW_CELL_HEIGHT /2;
        float scrollview_height = 0.0;
        cocos2d::Layer *slayer = cocos2d::Layer::create();
        //StageNumble::getInstance()->clear();
        GameStageSelectionCell *cell = nullptr;
        while (true)
        {
            cell = GameStageSelectionCell::create();
            if (!cell)
            {
                break;
            }
            cell->setPosition(cell_x, cell_y*scale_zoom_);
            cell->setScale(scale_zoom_);
            slayer->addChild(cell);
            //++cell_numbel;
            cell_y += GAME_STAGE_SCROLLVIEW_CELL_HEIGHT;
            scrollview_height += GAME_STAGE_SCROLLVIEW_CELL_HEIGHT;
            cell_vector_.pushBack(cell);
        }
        cocos2d::Sprite* bottom_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_STAGE_SCROLLVIEW_BOTTOM_PATH);
        bottom_sp->setScale(scale_zoom_);
        scrollview_bottom_height_ = bottom_sp->getBoundingBox().size.height;
        bottom_sp->setPosition(cell_x, scrollview_bottom_height_/-2);
        slayer->addChild(bottom_sp);

        scrollview_ = ScrollView::create(visibleSize, slayer);
        this->adjustingScrollviewPosition();
        //false自己写touch事件  
        //scrollview_->setTouchEnabled(true);
        scrollview_->setDelegate(this);
        //滚动方向  
        scrollview_->setDirection(ScrollView::Direction::VERTICAL);
        scrollview_->setBounceable(true);
        scrollview_->setContentSize(cocos2d::Size(visibleSize.width, scrollview_height*scale_zoom_));
        this->addChild(scrollview_);
        scrollViewDidScroll(scrollview_);
    }
    cocos2d::Layer * bubble_second::GameStageSelectionScene::createScrollViewContentLayer()
    {
        return nullptr;
    }
    void GameStageSelectionScene::addEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        auto listener = cocos2d::EventListenerCustom::create(EVENT_POP_ENTER_GAME_ALERT, [=](cocos2d::EventCustom* event) {
            StageData data = *static_cast<StageData*>(event->getUserData());
            this->popEnterGameAlert(data);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
    }
    void GameStageSelectionScene::removeEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->removeCustomEventListeners(EVENT_POP_ENTER_GAME_ALERT);
    }
    void GameStageSelectionScene::addMouseEventListener()
    {
        // 创建监听器
        auto mouseListener = cocos2d::EventListenerMouse::create();
        mouseListener->onMouseScroll = [=](cocos2d::Event *event){
            cocos2d::EventMouse* event_mouse = (cocos2d::EventMouse*)event;
            float offs_y = MIN(0.0f, scrollview_->getContentOffset().y + event_mouse->getScrollY()*MOUSE_SCROLL_Y_SENSITIVITY);
            scrollview_->setContentOffset(cocos2d::Vec2(0.0f, offs_y));
        };
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
    }
    void GameStageSelectionScene::addKeyboardEventListener()
    {
        auto listener = cocos2d::EventListenerKeyboard::create();
        listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*) {
            if (code == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE)
            {
                if (cocos2d::Node* alert = this->getChildByName(GAME_BASE_ALERT_NAME))
                {
                    alert->removeFromParent();
                }
                else
                {
                    cocos2d::Director::getInstance()->end();
                }
            }
        };
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    }
    void GameStageSelectionScene::popEnterGameAlert(StageData data)
    {
        if (!StageDataManager::getInstance()->isInStageNumbleRange(data.level_numble))
        {
            return;
        }
        StageType type = StageDataManager::getInstance()->getStageTypeWithNumble(data.level_numble);
        EnterGameAlert* alert = EnterGameAlert::create(data.cell_numble, data.level_numble, type);
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        alert->setScale(scale_zoom_);
        this->addChild(alert, UI_ZORDER_MENU);
    }
    void GameStageSelectionScene::enterNextStage(StageData data)
    {
        StageData next_data;
        if (cell_vector_.at(data.cell_numble)->isInCell(data.level_numble))
        {
            next_data.cell_numble = data.cell_numble;   
        }
        else
        {
            next_data.cell_numble = data.cell_numble + 1;
        }
        next_data.level_numble = data.level_numble + 1;
        this->popEnterGameAlert(next_data);
    }
    void GameStageSelectionScene::addSettingMenu()
    {
        cocos2d::Sprite* item_select = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PLAYING_MENU_NORMAL_PATH);
        item_select->setScale(GAME_MENU_SELECT_SCALE);
        cocos2d::Sprite* item_normal = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PLAYING_MENU_NORMAL_PATH);
        cocos2d::MenuItemSprite* item = cocos2d::MenuItemSprite::create(item_normal, item_select, [=](cocos2d::Ref*) {
            this->popSettingAlert();
        });
        item->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(item);
        menu->setName(UI_NAME_GAME_PLAYING_MENU);
        menu->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        menu->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu, UI_ZORDER_MENU);
    }
    void GameStageSelectionScene::popSettingAlert()
    {
        GameSettingAlert* alert = GameSettingAlert::create();
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        alert->setScale(scale_zoom_);
        this->addChild(alert, UI_ZORDER_MENU);
    }
    void GameStageSelectionScene::adjustingScrollviewPosition()
    {
        static bool fire_flag = true;
        if (fire_flag)
        {//第一次要移动到最新的关卡
            scrollview_->setContentOffset(getScorllViewOffset(UserDataManager::getInstance()->getPresentCell()));
            fire_flag = false;
        }
        else
        {
            scrollview_->setContentOffset(scrollview_offset_);
        }
    }
}