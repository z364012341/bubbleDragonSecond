#include "StageDataModule.h"


namespace bubble_second {
    StageDataModule::StageDataModule()
    {
    }

    bool StageDataModule::init()
    {
        return true;
    }

    StageDataModule::~StageDataModule()
    {
    }

    void StageDataModule::setBubblesData(const BubblesData & data)
    {
        bubbles_data_ = data;
    }

    BubblesData StageDataModule::getBubblesData()
    {
        return bubbles_data_;
    }

    void StageDataModule::setBubbleNumbleMax(int numble)
    {
        bubble_numble_max_ = numble;
    }

    int StageDataModule::getBubbleNumbleMax()
    {
        return bubble_numble_max_;
    }

    void StageDataModule::setStartNumbleModule(StartNumbleModule module)
    {
        start_numble_module_ = module;
    }

    StartNumbleModule StageDataModule::getStartNumble()
    {
        return start_numble_module_;
    }

    void StageDataModule::setBubbleColorRange(const std::string& colorStr)
    {
        for (size_t i = kNormalColorFirst; i <= kNormalColorLast; i++)
        {
            if (isInColorRange(colorStr[i]))
            {
                bubble_color_range_.push_back((BubbleType)i);
            }
        }
    }

    bool StageDataModule::isInColorRange(char color_bit)
    {
        return color_bit == BUBBLE_COLOR_IN_RANGE;
    }

    BubbleColorRange StageDataModule::getBubbleColorRange()
    {
        return bubble_color_range_;
    }

    void StageDataModule::setStageType(int type)
    {
        bool fall = (type & kBubbleFall) != 0;
        this->setFallType(fall);
        stage_type_ = (StageType)(type & (~kBubbleFall));
    }
    StageType StageDataModule::getStageType()
    {
        return stage_type_;
    }
    void StageDataModule::setFallType(bool flag)
    {
        is_fall_type_ = flag;
    }
    bool StageDataModule::isFallType()
    {
        return is_fall_type_;
    }
}