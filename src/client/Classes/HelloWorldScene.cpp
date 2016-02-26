#include "HelloWorldScene.h"
#include "GameScene.h"
#include "StageDataManager.h"
#include "ui\UIListView.h"
#include "cocos-ext.h"
#include "GUI\CCScrollView\CCTableView.h"
#include "GUI\CCScrollView\CCTableViewCell.h"
#include "ui\UIButton.h"
#include "BubbleSecondConstant.h"
#include "SmartScaleController.h"
#include "GameStageSelectionCell.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocos2d::extension;
namespace bubble_second {
    Scene* HelloWorld::createScene()
    {
        // 'scene' is an autorelease object
        auto scene = Scene::create();

        // 'layer' is an autorelease object
        auto layer = HelloWorld::create();

        // add layer as a child to scene
        scene->addChild(layer);

        // return the scene
        return scene;
    }

    // on "init" you need to initialize your instance
    bool HelloWorld::init()
    {
        //////////////////////////////
        // 1. super init first
        if (!Layer::init())
        {
            return false;
        }
        addListView();
        return true;
    }

    void HelloWorld::addListView()
    {
        /*ListView *listview = ListView::create();
        listview->setTouchEnabled(true);
        listview->setContentSize(Size(200, 500));
        auto v = cocos2d::Director::getInstance()->getVisibleSize();
        listview->setPosition(cocos2d::Vec2(v.width*0.3, v.height*0.1));
        //listview->setDirection(SCROLLVIEW_DIR_BOTH);
        listview->setBounceEnabled(true);
        float y = 10.0f;
        for (int i = 1; i<=StageDataManager::getInstance()->getStageTotalNumble(); i++) {

            //Layout *widget = Layout::create();
            ////        widget->setTouchEnabled(true);
            char text[10];
            sprintf(text, "%d", i);
            //MenuItemAtlasFont* item = MenuItemAtlasFont::create(str, POP_SCORE_CHARMAP_PATH, POP_SCORE_CHARMAP_ITEMWIDTH, POP_SCORE_CHARMAP_ITEMHEIGHT, '.');
            //item->setCallback([=](Ref*) {
            //    cocos2d::Scene* scene = GameScene::createScene();
            //    cocos2d::Director::getInstance()->replaceScene(scene);
            //});
            //Menu* menu = Menu::createWithItem(item);
            //menu->setPosition(50, y);
            //listview->addChild(menu);
            //y = y + 30;


            Button* custom_button = Button::create("kuangdaoju.png", "kuangdaoju.png");
            //custom_button->setName("Title Button");
            custom_button->setTitleText(text);
            custom_button->setScale9Enabled(true);
            custom_button->setContentSize(custom_button->getContentSize());
            custom_button->addClickEventListener([=](Ref*) {
                    cocos2d::Scene* scene = GameScene::createScene(i);
                    cocos2d::Director::getInstance()->replaceScene(scene);
                });
            Layout *custom_item = Layout::create();
            custom_item->setContentSize(custom_button->getContentSize());
            custom_button->setPosition(Vec2(custom_item->getContentSize().width / 2.0f, custom_item->getContentSize().height / 2.0f));
            custom_item->addChild(custom_button);

            listview->addChild(custom_item);
        }
        //listview->addEventListenerListView(this, listvieweventselector(HelloWorld::listviewCallBack));
        listview->setScale(SmartScaleController::getInstance()->getPlayAreaZoom()/0.4);
        this->addChild(listview);

        //TableView* table = TableView::create();*/
        //int stage_numble = 1;
        //GameStageSelectionCell* cell = GameStageSelectionCell::create(stage_numble);
        //if (!cell)
        //{
        //    return;
        //}
        //auto v = cocos2d::Director::getInstance()->getVisibleSize();
        //cell->setPosition(cocos2d::Vec2(v.width/2, v.height/2));
        //cell->setScale(SmartScaleController::getInstance()->getFixedWidthZoom());
        //this->addChild(cell);
    }

}