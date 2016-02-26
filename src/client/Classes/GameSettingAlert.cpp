#include "GameSettingAlert.h"
#include "GameVolControlView.h"
#include "GameTextInfo.h"
#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
#include "UserDataManager.h"
namespace bubble_second {
    GameSettingAlert::GameSettingAlert()
    {
    }


    GameSettingAlert::~GameSettingAlert()
    {
    }

    void GameSettingAlert::onExit()
    {
        GameBaseAlert::onExit();
        UserDataManager::getInstance()->setUserNickname(nickname_textfield->getString());
        UserDataManager::getInstance()->saveUserData();
    }

    bool GameSettingAlert::init()
    {
        if (!GameBaseAlert::init())
        {
            return false;
        }
        this->addCancelButton();
        this->addVolumeItem();
        this->addTopLabel();
        this->addNicknameInput();
        this->addHelpInfo();
        return true;
    }
    void GameSettingAlert::addVolumeItem()
    {
        GameVolControlView* view = GameVolControlView::create();
        this->addChild(view);
    }
    void GameSettingAlert::addTopLabel()
    {
        //文字
        cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_SETTING_KEY), "",
            GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
        top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
        this->addChild(top_label);
    }

    void GameSettingAlert::addNicknameInput()
    { //临时功能
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_SETTING_ALERT_TEXTFIELD_BACKGROUND_PATH);
        bg->setPositionX(120.0);

        using cocos2d::ui::TextField;
        nickname_textfield = TextField::create();
        nickname_textfield->setPlaceHolder(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_NICKNAME_KEY));
        nickname_textfield->setFontSize(GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
        nickname_textfield->setMaxLength(5);
        nickname_textfield->setMaxLengthEnabled(true);
        nickname_textfield->setPosition(bg->getPosition());
        nickname_textfield->setString(UserDataManager::getInstance()->getUserNickname());
        cocos2d::Sprite* portrait = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_SETTING_ALERT_PORTRAIT_PATH);
        portrait->setPositionX(-120.0);

        cocos2d::Node* node = cocos2d::Node::create();
        node->addChild(bg);
        node->addChild(portrait);
        node->addChild(nickname_textfield);
        node->setPositionY(225.0f);
        this->addChild(node);
    }
    void GameSettingAlert::addHelpInfo()
    {
        auto sp_controller = SpriteTextureController::getInstance();
        cocos2d::Sprite* bg = sp_controller->createGameSpriteWithPath(GAME_SETTING_ALERT_HELP_MENU_BACKGROUND_PATH);
        bg->setPositionY(-230.0f);
        this->addChild(bg);
        cocos2d::MenuItem* item_help = sp_controller->createMenuItemSprite(GAME_SETTING_ALERT_HELP_MENU_PATH);
        cocos2d::Rect rect = bg->getBoundingBox();
        item_help->setPosition(rect.size.width/-3.0f, 0.0f);

        cocos2d::MenuItem* item_props = sp_controller->createMenuItemSprite(GAME_SETTING_ALERT_PROPS_MENU_PATH);
        item_props->setPosition(cocos2d::Vec2::ZERO);

        cocos2d::MenuItem* item_about = sp_controller->createMenuItemSprite(GAME_SETTING_ALERT_ABOUT_MENU_PATH);
        item_about->setPosition(rect.size.width / 3.0f, 0.0f);

        cocos2d::Menu* menu = cocos2d::Menu::create(item_help, item_props, item_about, nullptr);
        menu->setPosition(rect.size.width/2, rect.size.height/2);
        bg->addChild(menu);
    }
    //void GameSettingAlert::cancelButtonCallback(cocos2d::Ref* ref)
    //{
    //    UserDataManager::getInstance()->setUserNickname(nickname_textfield->getString());
    //    UserDataManager::getInstance()->saveUserData();
    //}
}