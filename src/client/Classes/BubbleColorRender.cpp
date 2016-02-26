#include "BubbleColorRender.h"

namespace bubble_second {
    bubble_second::BubbleColorRender::BubbleColorRender(const std::vector<BubbleType>& color_vector)
    {
        this->initWithColorVector(color_vector);
        this->mixBubbleColor(color_vector);
    }

    BubbleColorRender::~BubbleColorRender()
    {
    }

    void BubbleColorRender::initWithColorVector(const std::vector<BubbleType>& color_vector)
    {
        for (auto var : color_vector)
        {
            color_to_color_[var] = var;
        }
    }

    void BubbleColorRender::mixBubbleColor(const std::vector<BubbleType>& color_vector)
    {
        std::vector<BubbleType> vector = color_vector;
        std::random_shuffle(vector.begin(), vector.end());
        for (auto iter = color_to_color_.begin(); iter != color_to_color_.end(); iter++)
        {
            iter->second = vector.at(vector.size()-1);
            vector.pop_back();
        }
    }

    BubbleType BubbleColorRender::getRandomColorWithColor(BubbleType color)
    {
        BubbleType result_color = color;
        if (color_to_color_.find(color) != color_to_color_.end())
        {
            result_color = color_to_color_[color];
        }
        else if (color == kBubbleRandomColor)
        {
            BubbleType random_color = (BubbleType)cocos2d::random((int)kNormalColorFirst, (int)kNormalColorLast);
            result_color = color_to_color_[random_color];
        }
        return result_color;
    }
}