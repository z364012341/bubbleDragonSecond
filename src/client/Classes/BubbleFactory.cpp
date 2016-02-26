#include "BubbleFactory.h"
#include "LightningBubble.h"
#include "ColorBubble.h"
#include "DarkCloudBubble.h"
#include "BlackHoleBubble.h"
#include "BombBombBubble.h"
#include "ColorBombBubble.h"
#include "BombPropertyBubble.h"
#include "NullBubble.h"
#include "RainbowSealBubble.h"
#include "MutipleSealBubble.h"
#include "WindmillBubble.h"
#include "AddBubbleNumbleBubble.h"
namespace bubble_second {
    BubbleFactory::BubbleFactory()
    {
        this->initHandleMap();
        this->initBubblePath();
    }
    BubbleFactory::~BubbleFactory()
    {
    }

    void BubbleFactory::initHandleMap()
    {
        //key_to_handle_map_[kBubbleNull] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubbleYellow] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubblePurple] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubbleBlue] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubbleRed] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubbleGreen] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubbleOrange] = &ColorBubble::createWithType;
        //key_to_handle_map_[kBubblePink] = &ColorBubble::createWithType;

        key_to_handle_map_[kBubbleNull] = [=](int type, int cloud) {return NullBubble::create(); };
        key_to_handle_map_[kBubbleYellow] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubblePurple] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubbleBlue] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubbleRed] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubbleGreen] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubbleOrange] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubblePink] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        key_to_handle_map_[kBubbleLightning] = [=](int, int) {return LightningBubble::create(); };
        key_to_handle_map_[kBubbleDarkCloud] = [=](int, int) {return DarkCloudBubble::create(); };
        key_to_handle_map_[kBubbleBlackHole] = [=](int, int) {return BlackHoleBubble::create(); };
        key_to_handle_map_[kBubbleBombBomb] = [=](int, int) {return BombBombBubble::create(); };
        key_to_handle_map_[kBubbleColorBomb] = [=](int, int) {return ColorBombBubble::create(); };
        key_to_handle_map_[kBubbleBombBombProperty] = [=](int, int) {return BombPropertyBubble::create(); };
        key_to_handle_map_[kBubbleRainbowSeal] = [=](int, int) {return RainbowSealBubble::create(); };
        key_to_handle_map_[kBubbleMutipleSeal1] = [=](int, int) {return MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1); };
        key_to_handle_map_[kBubbleMutipleSeal3] = [=](int, int) {return MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3); };
        key_to_handle_map_[kBubbleMutipleSeal7] = [=](int, int) {return MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7); };
        key_to_handle_map_[kBubbleWindmill] = [=](int, int) {return  WindmillBubble::create(); };
        key_to_handle_map_[kBubbleAddNumbleBubble] = [=](int, int) {return  AddBubbleNumbleBubble::create(); };
    }

    void bubble_second::BubbleFactory::initBubblePath()
    {
        key_to_path[kBubbleNull] = BUBBLE_NO_COLOR_PATH;
        key_to_path[kBubbleYellow] = BUBBLE_YELLOW_PATH;
        key_to_path[kBubblePurple] = BUBBLE_PURPLE_PATH;
        key_to_path[kBubbleBlue] = BUBBLE_BLUE_PATH;
        key_to_path[kBubbleRed] = BUBBLE_RED_PATH;
        key_to_path[kBubbleGreen] = BUBBLE_GREEN_PATH;
        key_to_path[kBubbleOrange] = BUBBLE_ORANGE_PATH;
        key_to_path[kBubblePink] = BUBBLE_PINK_PATH;
        key_to_path[kBubbleLightning] = BUBBLE_LIGHTNING_PATH;
        key_to_path[kBubbleDarkCloud] = BUBBLE_DARKCLOUD_PATH;
        key_to_path[kBubbleBlackHole] = BUBBLE_BLACKHOLE_PATH;
        key_to_path[kBubbleBombBomb] = BUBBLE_BOMB_BOMB_PATH;
        key_to_path[kBubbleColorBomb] = PROPS_COLOR_BOMB_PATH;
        key_to_path[kBubbleBombBombProperty] = PROPS_BOMB_BOMB_PATH;
        key_to_path[kBubbleRainbowSeal] = BUBBLE_RAINBOW_SEAL_PATH;
        key_to_path[kBubbleComponent] = BUBBLE_NO_COLOR_PATH;
        key_to_path[kBubbleMutipleSeal1] = BUBBLE_MUTIPLE_SEAL_1_PATH;
        key_to_path[kBubbleMutipleSeal3] = BUBBLE_MUTIPLE_SEAL_3_PATH;
        key_to_path[kBubbleMutipleSeal7] = BUBBLE_MUTIPLE_SEAL_7_PATH;
        key_to_path[kBubbleWindmill] = BUBBLE_WINDMILL_PATH;
        key_to_path[kBubbleAddNumbleBubble] = ADD_BUBBLE_NUMBLE_BUBBLE_PATH;

    }

    BaseBubble* BubbleFactory::createBubbleWithType(int type, int cloud)
    {
        BaseBubble* bubble = nullptr;
        auto temp = key_to_handle_map_[type];
        if (temp)
        {
            bubble = temp(type, cloud);
        }
        return bubble;
    }

    BaseBubble* BubbleFactory::createBubbleWithType(int type, cocos2d::Vec2 index, cocos2d::Vec2 point, int cloud)
    {
        BaseBubble* bubble = this->createBubbleWithType(type, cloud);
        if (!bubble)
        {
            return nullptr;
        }
        bubble->setBubbleIndex(index);
        bubble->setPosition(point);
        return bubble;
    }

    std::string BubbleFactory::getPathWithType(int type)
    {
        return key_to_path[type];
    }
}