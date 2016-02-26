#include "ScoreProgressMenu.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIImageView.h"
#include "ScoreProgressStart.h"
namespace bubble_second {
    ScoreProgressMenu::ScoreProgressMenu()
    {
    }

    ScoreProgressMenu::~ScoreProgressMenu()
    {
    }

    bool ScoreProgressMenu::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->initScoreMenu();
        this->setName(GAME_TOP_INFO_NAME);
        this->getScoreProgressTimer()->setPercent(percent_);
        return true;
    }
    void ScoreProgressMenu::initScoreMenu()
    {
        score_progress_node_ = cocos2d::CSLoader::createNode(GAME_TOP_INFO_CSB);
        this->addChild(score_progress_node_);
    }

    void ScoreProgressMenu::initStartSprite()
    {
        for (auto var : this->getStartNumbleModule().getPercentModule())
        {
            ScoreProgressStart* start = ScoreProgressStart::createWithPercent(var.second);
            start->setPosition(this->getStartPositionWithPercent(var.second));
            this->addChild(start);
            start_sprite_map_.insert(var.first, start);
        }
    }

    cocos2d::Vec2 ScoreProgressMenu::getStartPositionWithPercent(float percent)
    {
        auto image = dynamic_cast<cocos2d::ui::ImageView*>(score_progress_node_->getChildByName(SCORE_PROGRESS_BORDER_NAME));
        assert(image);
        cocos2d::Rect rect = image->getBoundingBox();
        return cocos2d::Vec2(rect.size.width * percent - rect.size.width /2 + image->getPositionX(), image->getPositionY());
    }

    void ScoreProgressMenu::initialStartNumble(StartNumbleModule start_numble)
    {
        start_numble_ = start_numble;
        this->initStartSprite();
    }

    cocos2d::ui::LoadingBar* ScoreProgressMenu::getScoreProgressTimer()
    {
        return dynamic_cast<cocos2d::ui::LoadingBar*>(score_progress_node_->getChildByName(UI_NAME_SCORE_PROGRESS_TIMER));
    }

    void ScoreProgressMenu::increaseProgressTimer()
    {
        static float direction = 0.0f;
        if (this->isScheduled(GAME_SCORE_PROGRESS_SCHEDULE_KEY))
        {
            return;
        }
        float percent = getScoreProgressTimer()->getPercent();
        direction = getScoreProgressTimer()->getPercent() == 0.0f?1.0f:-1.0f;
        this->schedule([=](float) {
            getScoreProgressTimer()->setPercent(getScoreProgressTimer()->getPercent() + GAME_SCORE_PROGRESS_TIMER_PER_INCREASE_PERCENT*direction);
            this->controlStartLight(getScoreProgressTimer()->getPercent());
            if (this->isCompletedGoalPercent(getScoreProgressTimer()->getPercent()))
            {
                this->unschedule(GAME_SCORE_PROGRESS_SCHEDULE_KEY);
            }
            if (this->isCompletedBack(percent - GAME_SCORE_PROGRESS_TIMER_BACK_PERCENT))
            {
                direction = 1.0f;
            }
        }, GAME_SCORE_PROGRESS_SCHEDULE_KEY);
    }

    void ScoreProgressMenu::setGoalPercent(float percent)
    {
        percent_ = percent;
    }

    float ScoreProgressMenu::getGoalPercent()
    {
        return percent_;
    }

    void ScoreProgressMenu::setLastScore(int last_score)
    {
        last_score_ = last_score;
    }

    int ScoreProgressMenu::getLastScore()
    {
        return last_score_;
    }

    bool ScoreProgressMenu::isEqualLastScore(int score)
    {
        return last_score_ == score;
    }

    bool ScoreProgressMenu::isCompletedGoalPercent(float percent)
    {
        return percent >= this->getGoalPercent() || percent>=100.0f;
    }

    bool ScoreProgressMenu::isCompletedBack(float percent)
    {
        return getScoreProgressTimer()->getPercent() <= percent || getScoreProgressTimer()->getPercent() <= 0.0f;
    }

    StartNumbleModule ScoreProgressMenu::getStartNumbleModule()
    {
        return start_numble_;
    }

    void ScoreProgressMenu::controlStartLight(float percent)
    {
        for (auto var : start_sprite_map_)
        {
            var.second->controlLightWithPercent(percent/100);
        }
    }

    void ScoreProgressMenu::setScoreProgressTimerPercent(float score)
    {
        if (!this->isEqualLastScore(score))
        {
            this->setLastScore(score);
            this->setGoalPercent(getStartNumbleModule().getPercentWithScore(score));
            this->increaseProgressTimer();
        }
    }

    int ScoreProgressMenu::getStartOnNumble()
    {
        int numble = 0;
        for (auto var : start_sprite_map_)
        {
            if (var.second->startIsOn())
            {
                ++numble;
            }
        }
        return numble;
    }
}