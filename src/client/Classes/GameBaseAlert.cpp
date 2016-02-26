#include "GameBaseAlert.h"
#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
namespace bubble_second {
    GameBaseAlert::GameBaseAlert()
    {
    }


    GameBaseAlert::~GameBaseAlert()
    {
    }

    bool GameBaseAlert::init()
    {
        //this->addCancelButton();
        this->setName(GAME_BASE_ALERT_NAME);
        this->addBackground();
        this->addBlackMask();

        return true;
    }

    void GameBaseAlert::addCancelButton()
    {
        cancel_item_ = SpriteTextureController::getInstance()->createMenuItemSprite(GAME_ALERT_CANCEL_BUTTON_PATH);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(cancel_item_);
        menu->setPosition(GAME_ALERT_CANCEL_BUTTON_POSITION);
        this->addChild(menu);
        this->setCancelCallback([=](cocos2d::Ref* ref) {
            this->cancelButtonCallback(ref);
            this->removeFromParent();
        });
    }

    void GameBaseAlert::setCancelCallback(const cocos2d::ccMenuCallback & callback)
    {
        cancel_item_->setCallback(callback);
    }

    void GameBaseAlert::addBlackMask()
    {
        cocos2d::Sprite* item_select = cocos2d::Sprite::create();
        item_select->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::Sprite* item_normal = cocos2d::Sprite::create();
        item_normal->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        CenteredMenuItemSprite* item = CenteredMenuItemSprite::create(item_normal, item_select, [=](cocos2d::Ref*) {
        });
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(item);
        //menu->setPosition(GAME_DESIGN_RESOLUTION_WIDTH / -2, GAME_DESIGN_RESOLUTION_HEIGHT / -2);
        menu->setPosition(0, 0);
        this->addChild(menu, UI_ZORDER_MENU_MASK_NULL_BUTTON);
        cocos2d::LayerColor* layer = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, 100), GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT);
        layer->setPosition(-GAME_ALERT_MASK_WIDTH/2, -GAME_ALERT_MASK_HEIGHT/2);
        this->addChild(layer, UI_ZORDER_MENU_MASK_COLOR_LAYER);
        //cocos2d::Size win_size = cocos2d::Director::getInstance()->getWinSize();
        //cocos2d::RenderTexture *screen_texture = cocos2d::RenderTexture::create(win_size.width, win_size.height);
        //cocos2d::Scene *scene = cocos2d::Director::getInstance()->getRunningScene();
        //screen_texture->begin();
        //scene->visit();//将当前的整个scene绘出来 
        //screen_texture->end();
        //cocos2d::Sprite* sp = cocos2d::Sprite::createWithTexture(screen_texture->getSprite()->getTexture());
        ////cocos2d::Sprite* sp = cocos2d::Sprite::create("bg01_hd.jpg");
        //sp->setFlippedY(true);
        //this->addChild(sp, UI_ZORDER_MENU_MASK_BLUR_SPRITE);

        //cocos2d::CallFunc* func = cocos2d::CallFunc::create([=]() {
        //    sp->setScale(1 / this->getScale());
        //    auto fileUtiles = cocos2d::FileUtils::getInstance();
        //    std::string fragmentFullPath = fileUtiles->fullPathForFilename(BLUR_FSH_PATH);
        //    std::string fragSource = fileUtiles->getStringFromFile(fragmentFullPath);
        //    cocos2d::GLProgram* shader_program = cocos2d::GLProgram::createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, fragSource.c_str());
        //    cocos2d::GLProgramState* program_state = cocos2d::GLProgramState::getOrCreateWithGLProgram(shader_program);
        //    cocos2d::Size size = sp->getTexture()->getContentSizeInPixels();
        //    program_state->setUniformVec2("resolution", size);
        //    program_state->setUniformFloat("blurRadius", 8.0f);
        //    program_state->setUniformFloat("sampleNum", 2.0f);
        //    sp->setGLProgramState(program_state);
        //});
        //this->runAction(func);
    }

    void GameBaseAlert::addBackground()
    {
        addBigBackground();
        addTopBackground();
    }
    void GameBaseAlert::addBigBackground()
    {
        //背后的大背景
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH);
        bg->setTag(GAME_ALERT_BIG_BACKGROUND_TAG);
        this->addChild(bg);
    }
    void GameBaseAlert::addTopBackground()
    {
        //上面的小背景
        cocos2d::Sprite* top_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH);
        cocos2d::Rect rect = this->getChildByTag(GAME_ALERT_BIG_BACKGROUND_TAG)->getBoundingBox();
        top_bg->setPosition(0.0f, rect.size.height / 2);
        top_bg->setTag(GAME_ALERT_TOP_BACKGROUND_TAG);
        this->addChild(top_bg);
    }
    void GameBaseAlert::cancelButtonCallback(cocos2d::Ref*)
    {
    }
}