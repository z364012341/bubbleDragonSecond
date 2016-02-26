#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {

    SpriteTextureController::SpriteTextureController()
    {
        stagetype_to_path_[kTopEliminate] = STAGETYPE_TEXTURE_TOPELIMINATE_PATH;
        stagetype_to_path_[kRescueAnimal] = STAGETYPE_TEXTURE_RESCUEANIMAL_PATH;
        stagetype_to_path_[kDestroyRainbowSeal] = STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH;
        stagetype_to_path_[kWindmill] = STAGETYPE_TEXTURE_WINDMILL_PATH;
        this->readGameSceneBackgroundFile();
    }

    void SpriteTextureController::readGameSceneBackgroundFile()
    {
        cell_to_path_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(GAME_SCENE_BACKGROUND_PATH);
    }

    SpriteTextureController::~SpriteTextureController()
    {
        removeArmatureFile();
    }

    void SpriteTextureController::setSpriteTexture(const std::string& path, cocos2d::Sprite* sprite)
    {
        if (path == "")
        {
            sprite->setTexture(path);
        }
        else
        {
            auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(path);
            sprite->setSpriteFrame(frame);
        }
    }

    cocos2d::Sprite* SpriteTextureController::createGameSpriteWithPath(const std::string& path)
    {
        cocos2d::Sprite*sp = cocos2d::Sprite::create(path);
        if (!sp)
        {
            sp = cocos2d::Sprite::createWithSpriteFrameName(path);
        }
        return sp;
    }

    CenteredMenuItemSprite * SpriteTextureController::createMenuItemSprite(const std::string & path, const cocos2d::ccMenuCallback & callback)
    {
        cocos2d::Sprite* item_select = this->createGameSpriteWithPath(path);
        item_select->setScale(GAME_MENU_SELECT_SCALE);
        cocos2d::Sprite* item_normal = this->createGameSpriteWithPath(path);
        CenteredMenuItemSprite* item = CenteredMenuItemSprite::create(item_normal, item_select, [=](cocos2d::Ref*) {
        });
        return item;
    }

    cocos2d::Sprite * SpriteTextureController::createStageTypeSprite(const StageType & type)
    {
        return this->createGameSpriteWithPath(stagetype_to_path_[type]);
    }

    cocos2d::Sprite * SpriteTextureController::createGameBackgroundSprite(int cell_numble)
    {
        char str[10];
        sprintf(str, "%d", cell_numble);
        return this->createGameSpriteWithPath(cell_to_path_[str].asString());;
    }

    void SpriteTextureController::addResourcesTexture()
    {
        /*static int numble = 0;
        auto callback = [=](cocos2d::Texture2D* texture) {
            ++numble;
            CCLOG("%d", numble);
        };
        auto cache = cocos2d::Director::getInstance()->getTextureCache();
        cache->addImageAsync(ADD_BUBBLE_NUMBLE_BUBBLE_PATH, callback);
        cache->addImageAsync(GAME_PLAYING_MENU_NORMAL_PATH, callback);
        cache->addImageAsync(PROPS_SELECT_ALERT_CONFIRM, callback);
        cache->addImageAsync(PROPS_SELECT_ALERT_CANCEL, callback);
        cache->addImageAsync(PROPS_NUMBLE_DISABLED_PATH, callback);
        cache->addImageAsync(PROPS_NUMBLE_ENABLED_PATH, callback);
        cache->addImageAsync(SIGHT_POINT_COLORFUL_PATH, callback);
        cache->addImageAsync(SIGHT_POINT_ORANGE_PATH, callback);
        cache->addImageAsync(BIG_COMBO_EFFECT_POINT_PATH, callback);
        cache->addImageAsync(PROPS_COLOR_BOMB_PATH, callback);
        cache->addImageAsync(PROPS_STAVES_PATH, callback);
        cache->addImageAsync(PROPS_WOODEN_HAMMER_PATH, callback);
        cache->addImageAsync(PROPS_BOMB_BOMB_PATH, callback);
        cache->addImageAsync(BUBBLE_SIGHTING_POINT_PATH, callback);
        cache->addImageAsync(UI_NAME_GUNSIGHT, callback);
        cache->addImageAsync(UI_NAME_PAD, callback);
        cache->addImageAsync(SIGHT_POINT_PINK_PATH, callback);
        cache->addImageAsync(SIGHT_POINT_YELLOW_PATH, callback);
        cache->addImageAsync(PROPS_ITEM_BACKGROUND_PATH, callback);
        cache->addImageAsync(BUBBLE_RAINBOW_SEAL_PATH, callback);
        cache->addImageAsync(PROPS_SELECT_ALERT_BACKGROUND, callback);
        cache->addImageAsync(SIGHT_POINT_BLUE_PATH, callback);
        cache->addImageAsync(SIGHT_POINT_GREEN_PATH, callback);
        cache->addImageAsync(BUBBLE_ORANGE_PATH, callback);
        cache->addImageAsync(BUBBLE_PINK_PATH, callback);
        cache->addImageAsync(BUBBLE_BLACKHOLE_PATH, callback);
        cache->addImageAsync(BUBBLE_RED_PATH, callback);
        cache->addImageAsync(BUBBLE_YELLOW_PATH, callback);
        cache->addImageAsync(BUBBLE_BLUE_PATH, callback);
        cache->addImageAsync(BUBBLE_GREEN_PATH, callback);
        cache->addImageAsync(BUBBLE_LIGHTNING_PATH, callback);
        cache->addImageAsync(BUBBLE_MUTIPLE_SEAL_1_PATH, callback);
        cache->addImageAsync(BUBBLE_MUTIPLE_SEAL_3_PATH, callback);
        cache->addImageAsync(BUBBLE_DARKCLOUD_PATH, callback);
        cache->addImageAsync(BUBBLE_BOMB_BOMB_PATH, callback);
        cache->addImageAsync(BUBBLE_PURPLE_PATH, callback);
        cache->addImageAsync(BIG_BLUE_BACKGROUND_EFFECT_POINT_PATH, callback);
        cache->addImageAsync(RAINBOW_CHARACTOR_BG_PATH, callback);
        cache->addImageAsync(RAINBOW_CHARACTOR_SWIRL_PATH, callback);
        cache->addImageAsync(BUBBLE_WINDMILL_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_ORANGE_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_PINK_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_RED_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_YELLOW_PATH, callback);
        cache->addImageAsync(UI_NAME_WINDMILL_BUBBLE_FLYING_BODY_PATH, callback);
        cache->addImageAsync(UI_NAME_WINDMILL_BUBBLE_FLYING_MOTIONSTREAK_PATH, callback);
        cache->addImageAsync(UI_NAME_WINDMILL_BUBBLE_FLYING_HEAD_PATH, callback);
        cache->addImageAsync(SCORE_PROGRESS_START_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_BLUE_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_GREEN_PATH, callback);
        cache->addImageAsync(GUNSIGHT_SWIRL_PURPLE_PATH, callback);                    
        cache->addImageAsync(SIGHT_POINT_PURPLE_PATH, callback); */

        //auto cache = cocos2d::Director::getInstance()->getTextureCache();
        //for (auto var : cell_to_path_)
        //{
        //    cache->addImage(var.second.asString());
        //}
        
        cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("StudioResPlist.plist");
        cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gameRes.plist");
        this->addArmatureFile();
    }

    void SpriteTextureController::addGameBackgroundTexture(int cell_numble)
    {
        char str[10];
        sprintf(str, "%d", cell_numble);
        cocos2d::Director::getInstance()->getTextureCache()->addImageAsync(cell_to_path_[str].asString(), nullptr);
    }

    void SpriteTextureController::addArmatureFile()
    {
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(SCOREWIDGET_ARMATURE_BLUE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
    }

    void SpriteTextureController::removeArmatureFile()
    {
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(SCOREWIDGET_ARMATURE_BLUE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
    }

}