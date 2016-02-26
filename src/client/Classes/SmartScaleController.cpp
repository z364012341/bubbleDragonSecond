#include "SmartScaleController.h"
namespace bubble_second {
    SmartScaleController::SmartScaleController()
    {
        this->init();
    }


    SmartScaleController::~SmartScaleController()
    {
    }

    void SmartScaleController::init()
    {
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        float visible_aspect_ratio = visible_size.width / visible_size.height;
        float game_aspect_ratio = GAME_DESIGN_RESOLUTION_WIDTH / GAME_DESIGN_RESOLUTION_HEIGHT;
        if (visible_aspect_ratio < game_aspect_ratio)
        {
            play_area_zoom_ = visible_size.width / GAME_DESIGN_RESOLUTION_WIDTH;
        }
        else
        {
            play_area_zoom_ = visible_size.height / GAME_DESIGN_RESOLUTION_HEIGHT;
        }

        fixed_width_zoom_ = visible_size.width / GAME_DESIGN_RESOLUTION_WIDTH;
        fixed_height_zoom_ = visible_size.height / GAME_DESIGN_RESOLUTION_HEIGHT;
    }

    float SmartScaleController::getPlayAreaZoom()
    {
        return play_area_zoom_;
    }

    float SmartScaleController::getFixedWidthZoom()
    {
        return fixed_width_zoom_;
    }

    float SmartScaleController::getFixedHeightZoom()
    {
        return fixed_height_zoom_;
    }
}