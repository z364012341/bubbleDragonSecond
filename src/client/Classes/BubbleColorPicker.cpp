#include "BubbleColorPicker.h"
namespace bubble_second {
    BubbleColorPicker::BubbleColorPicker()
    {
        this->init();
        //this->addEventListenerCustom();
    }


    BubbleColorPicker::~BubbleColorPicker()
    {
    }

    //void BubbleColorPicker::addEventListenerCustom()
    //{
    //}

    void BubbleColorPicker::init()
    {
        color_picker_[kBubbleYellow] = 0;
        color_picker_[kBubblePurple] = 0;
        color_picker_[kBubbleBlue] = 0;
        color_picker_[kBubbleRed] = 0;
        color_picker_[kBubbleGreen] = 0;
        color_picker_[kBubbleOrange] = 0;
        color_picker_[kBubblePink] = 0;
        color_total_ = 0;
    }

    void BubbleColorPicker::addColorWithBubbleColor(BubbleType color)
    {
        if (isColorBubbleType(color))
        {
            color_picker_[color] = color_picker_[color] + 1;
            ++color_total_;
        } 
    }

    void BubbleColorPicker::subtractColorWithBubbleColor(BubbleType color)
    {
        if (isColorBubbleType(color))
        {
            color_picker_[color] = color_picker_[color] - 1;
            --color_total_;
        }
    }

    bool BubbleColorPicker::isColorBubbleType(BubbleType color)
    {
        if (color<= kNormalColorLast && color >= kNormalColorFirst)
        {
            return true;
        }
        return false;
    }

    std::vector<BubbleType> BubbleColorPicker::getColorPickerVector()
    {
        std::vector<BubbleType> picker;
        for (auto var : color_picker_)
        {
            if (var.second > 0)
            {
                picker.push_back(var.first);
            }
        }
        return picker;
    }

    //void BubbleColorPicker::subtractColorWithEvent(cocos2d::EventCustom* event)
    //{

    //}

    BubbleType BubbleColorPicker::getBubbleColorFromPicker()
    {
        std::vector<BubbleType> picker = this->getColorPickerVector();
        if (picker.empty())
        {
            return getBubbleColorInRange();
        }
        int size = picker.size();
        int random_numble = cocos2d::random(0, size-1);
        return picker.at(random_numble);
    }

    bool BubbleColorPicker::needChangeBubbleType(BubbleType color)
    {
        if (this->isColorBubbleType(color) && !this->getColorPickerVector().empty())
        {
            return color_picker_[color] == 0;
        }
        return false;
    }

    void BubbleColorPicker::setColorPickerRange()
    {
        for (auto var : color_picker_)
        {
            if (var.second != 0)
            {
                color_range_.push_back(var.first);
            }
        }
    }

    BubbleType BubbleColorPicker::getBubbleColorInRange()
    {
        int index = cocos2d::random(0, (int)color_range_.size()-1);
        return color_range_.at(index);
    }

    //bool BubbleColorPicker::isRemainColor()
    //{
    //    return color_picker_.empty();
    //}
}