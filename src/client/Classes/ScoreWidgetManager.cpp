#include "ScoreWidgetManager.h"
#include "ScoreWidget.h"
#include "GameScoreController.h"
namespace bubble_second {
    ScoreWidgetManager::ScoreWidgetManager():widget_total_(0)
    {
        //this->addEventListenerCustom();
        combo_to_type_[0] = kScoreWidgetBlue;
        combo_to_type_[1] = kScoreWidgetBlue;
        combo_to_type_[2] = kScoreWidgetBlue;
        combo_to_type_[3] = kScoreWidgetBlue;
        combo_to_type_[4] = kScoreWidgetPink;
        combo_to_type_[5] = kScoreWidgetPink;
        combo_to_type_[6] = kScoreWidgetGreen;
        widget_update_sequence_.push_back(kScoreWidgetBlue);
        widget_update_sequence_.push_back(kScoreWidgetPink);
        //widget_update_sequence_.push_back(kScoreWidgetGreen);
        widget_remove_sequence_.push_back(kScoreWidgetGreen);
        widget_remove_sequence_.push_back(kScoreWidgetPink);
        widget_remove_sequence_.push_back(kScoreWidgetBlue);


        std::map<ScoreWidgetType, std::string> type_to_head;
        type_to_head[kScoreWidgetBlue] = SCORE_WIDGET_HEAD_BLUE_PATH;
        type_to_head[kScoreWidgetPink] = SCORE_WIDGET_HEAD_PINK_PATH;
        type_to_head[kScoreWidgetGreen] = SCORE_WIDGET_HEAD_GREEN_PATH;

        std::map<ScoreWidgetType, std::string> type_to_body;
        type_to_body[kScoreWidgetBlue] = SCORE_WIDGET_BODY_BLUE_PATH;
        type_to_body[kScoreWidgetPink] = SCORE_WIDGET_BODY_PINK_PATH;
        type_to_body[kScoreWidgetGreen] = SCORE_WIDGET_BODY_GREEN_PATH;

        std::map<ScoreWidgetType, std::string> type_to_bg;
        type_to_bg[kScoreWidgetBlue] = SCORE_WIDGET_BG_BLUE_PATH;
        type_to_bg[kScoreWidgetPink] = SCORE_WIDGET_BG_PINK_PATH;
        type_to_bg[kScoreWidgetGreen] = SCORE_WIDGET_BG_GREEN_PATH;

        std::map<ScoreWidgetType, std::string> type_to_ear_1;
        type_to_ear_1[kScoreWidgetBlue] = SCORE_WIDGET_EAR1_BLUE_PATH;
        type_to_ear_1[kScoreWidgetPink] = SCORE_WIDGET_EAR1_PINK_PATH;
        type_to_ear_1[kScoreWidgetGreen] = SCORE_WIDGET_EAR1_GREEN_PATH;

        std::map<ScoreWidgetType, std::string> type_to_ear_2;
        type_to_ear_2[kScoreWidgetBlue] = SCORE_WIDGET_EAR2_BLUE_PATH;
        type_to_ear_2[kScoreWidgetPink] = SCORE_WIDGET_EAR2_PINK_PATH;
        type_to_ear_2[kScoreWidgetGreen] = SCORE_WIDGET_EAR2_GREEN_PATH;

        bonename_to_map_[SCORE_WIDGET_BONE_HEAD_NAME] = type_to_head;
        bonename_to_map_[SCORE_WIDGET_BONE_BODY_NAME] = type_to_body;
        bonename_to_map_[SCORE_WIDGET_BONE_BG_NAME] = type_to_bg;
        bonename_to_map_[SCORE_WIDGET_BONE_EAR1_NAME] = type_to_ear_1;
        bonename_to_map_[SCORE_WIDGET_BONE_EAR2_NAME] = type_to_ear_2;
    }

    ScoreWidgetManager::~ScoreWidgetManager()
    {
    }

    void ScoreWidgetManager::clear()
    {
        for (auto iter_1 = score_widget_map_.begin(); iter_1 != score_widget_map_.end(); ++iter_1)
        {
            iter_1->second.clear();
        }
        widget_total_ = 0;
    }

    void ScoreWidgetManager::removeTwoScoreWidget()
    {
        //关闭用以测试
        int time = 0;
        //for (auto iter_1 = score_widget_vector_.begin(); iter_1 != score_widget_vector_.end(); ++iter_1)
        //{
        //    for (auto iter = iter_1->begin(); iter != iter_1->end(); )
        //    {
        //        if (time != SCORE_WIDGET_NOT_COMBO_NUMBLE)
        //        {
        //            (*iter)->removeScoreWidget();
        //            iter = iter_1->erase(iter);
        //            --widget_total_;
        //            ++time;
        //            continue;
        //        }
        //        return;   
        //    }
        //}
        for (auto var : widget_remove_sequence_)
        {
            for (auto iter = score_widget_map_[var].begin(); iter != score_widget_map_[var].end(); )
            {
                if (time != SCORE_WIDGET_NOT_COMBO_NUMBLE)
                {
                    (*iter)->removeScoreWidget();
                    iter = score_widget_map_[var].erase(iter);
                    --widget_total_;
                    ++time;
                    continue;
                }
                return;
            }
        }
    }

    //void ScoreWidgetManager::addEventListenerCustom()
    //{
    //    cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    //    auto listener = cocos2d::EventListenerCustom::create(EVENT_MAP_LOADED, CC_CALLBACK_1(ScoreWidgetManager::clear, this));
    //    dispatcher->addEventListenerWithFixedPriority(listener, 1);
    //}

    ScoreWidget* ScoreWidgetManager::getNewScoreWidget()
    {
        if (widget_total_ < 6)
        {
            ++widget_total_;
            const ScoreWidgetType& type = combo_to_type_[GameScoreController::getInstance()->getEliminateCombo()];
            ScoreWidget* widget = ScoreWidget::createWithType(type);
            widget->setSelfPosition(this->getScoreWidgetPosition());
            score_widget_map_[type].pushBack(widget);
            return widget;
        }
        else
        {
            //for (auto iter_1 = score_widget_vector_.begin(); iter_1 != --score_widget_vector_.end(); ++iter_1)
            //{//最高级的不用升级
            //    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2)
            //    {
            //        ScoreWidget* widget = *iter_2;
            //        iter_1->erase(iter_2);              
            //        score_widget_vector_[widget->getType()].pushBack(widget);
            //        //先移动vector里面的元素在升级, 因为升级会初始化连击次数
            //        widget->updateScoreWidgetType();
            //        return nullptr;
            //    }
            //}
            ScoreWidget* widget = nullptr;
            for (auto var : widget_update_sequence_)
            {
                for (auto iter = score_widget_map_[var].begin(); iter != score_widget_map_[var].end(); ++iter)
                {
                    widget = *iter;
                    score_widget_map_[var].erase(iter);
                    widget->updateScoreWidgetType();
                    score_widget_map_[widget->getType()].pushBack(widget);
                    widget = nullptr;
                    return nullptr;
                }
            }
        }
        return nullptr;
    }

    //cocos2d::Vec2 ScoreWidgetManager::getScoreWidgetPositionWithVector(const cocos2d::Vector<cocos2d::Node*>& vector)
    //{
    //    int vector_size = vector.size();
    //    cocos2d::Vec2 point;
    //    int numble = 0;
    //    do
    //    {
    //        point = vector.at(cocos2d::random(0, vector_size - 1))->getPosition()
    //            + cocos2d::Vec2(cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS),
    //                cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS));
    //        ++numble;
    //    } while (this->isNearbyExistence(point)/* && numble < 999*/);
    //    return point;
    //}

    cocos2d::Vec2 ScoreWidgetManager::getScoreWidgetPosition()
    {
        int vector_size = this->getWidgetPointsSeed().size();
        cocos2d::Vec2 point;
        int numble = 0;
        do
        {
            point = this->getWidgetPointsSeed().at(cocos2d::random(0, vector_size - 1))->getPosition()
                + cocos2d::Vec2(cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS),
                    cocos2d::random(SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS*2));
            ++numble;
        } while (this->isNearbyExistence(point)/* && numble < 999*/);
        return point;
    }

    bool ScoreWidgetManager::isNearbyExistence(const cocos2d::Vec2& point)
    {
        for (auto var_1 : score_widget_map_)
        {
            for (auto var_2 : var_1.second)
            {
                //cocos2d::log("score_distance: %f", var_2->getSelfPosition().distance(point));
                if (var_2->getSelfPosition().distance(point) < TWO_SCORE_WIDGET_DISTANCE || this->isNearByBorder(point))
                {    
                    return true;
                }
            }
        }
        return false;
    }

    bool ScoreWidgetManager::isNearByBorder(const cocos2d::Vec2 & point)
    {
        float right_max = GAME_DESIGN_RESOLUTION_WIDTH - BUBBLE_RADIUS - SCORE_WIDGET_BODY_RADIUS+20;
        float right_min = GAME_DESIGN_RESOLUTION_WIDTH - (BUBBLE_RADIUS * 2 + SCORE_WIDGET_BODY_RADIUS)-15;
        float left_max = right_min * -1;
        float left_min = right_max * -1;
        return (left_min<point.x && point.x<left_max) || (right_min<point.x && point.x<right_max);
    }

    int ScoreWidgetManager::getScoreWidgetTotal()
    {
        return widget_total_;
    }

    int ScoreWidgetManager::getScoreWidgetTotalWithType(const ScoreWidgetType& type)
    {
        return score_widget_map_[type].size();
    }

    void ScoreWidgetManager::setWidgetPointsSeed(WidgetPointsSeed seed)
    {
        widget_points_seed_ = seed;
    }

    WidgetPointsSeed ScoreWidgetManager::getWidgetPointsSeed()
    {
        return widget_points_seed_;
    }

    const WidgetBonePathMap& ScoreWidgetManager::getWidgetBonePathMap()
    {
        return bonename_to_map_;
    }
}