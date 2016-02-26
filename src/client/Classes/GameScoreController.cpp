 #include "GameScoreController.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    GameScoreController::GameScoreController():bubble_use_count_(0)
    {
        this->clear();
        //this->addEventListenerCustom();
    }

    GameScoreController::~GameScoreController()
    {
    }

    //void GameScoreController::addEventListenerCustom()
    //{
    //    cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    //    auto /*listener = cocos2d::EventListenerCustom::create(EVENT_ADD_ELIMINATE_COMBO, CC_CALLBACK_1(GameScoreController::addOneCombo, this));
    //    dispatcher->addEventListenerWithFixedPriority(listener, 2);   */
    //    listener = cocos2d::EventListenerCustom::create(EVENT_CUT_ELIMINATE_COMBO, CC_CALLBACK_1(GameScoreController::eliminateComboClear, this));
    //    dispatcher->addEventListenerWithFixedPriority(listener, 1);
    //    listener = cocos2d::EventListenerCustom::create(EVENT_SCORE_ADD, CC_CALLBACK_1(GameScoreController::addScoreWithNumble, this));
    //    dispatcher->addEventListenerWithFixedPriority(listener, 1);
    //    //listener = cocos2d::EventListenerCustom::create(EVENT_BUBBLE_ELIMINATED, CC_CALLBACK_1(GameScoreController::addScoreWithEliminateNumble, this));
    //    //dispatcher->addEventListenerWithFixedPriority(listener, 2);
    //}

    void GameScoreController::clear()
    {
        this->eliminateComboClear();
        this->totalScoreClear();
        this->gameTaskNumbleClear();
        this->completedTaskNumbleClear();
    }

    void GameScoreController::eliminateComboClear()
    {
        eliminate_combo_ = 0;
    }

    void GameScoreController::addOneCombo()
    {
        ++eliminate_combo_;
        if (eliminate_combo_ == BIG_COMBO_ELIMINATE_NUMBLE)
        {
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(UI_NAME_BIG_COMBO_ELIMINATE);
        }
    }

    int GameScoreController::getEliminateCombo()
    {
        return eliminate_combo_;
    }

    void GameScoreController::totalScoreClear()
    {
        total_score_ = 0;
        use_count_enable_ = true;
        //this->dispatchUpdateScoreEvent();
    }

    void GameScoreController::gameTaskNumbleClear()
    {
        game_task_numble_add_ = 0;
        game_task_numble_set_ = 0;
    }

    void GameScoreController::completedTaskNumbleClear()
    {
        completed_task_numble_add_ = 0;
        completed_task_numble_set_ = 0;
    }

    void GameScoreController::addScoreWithNumble(int numble)
    {
        //auto numble = static_cast<int*>(event->getUserData());
        this->addScore(numble);
    }

    void GameScoreController::addGameTaskNumble()
    {
        game_task_numble_add_++;
    }

    int GameScoreController::getGameTaskNumble() const
    {
        return game_task_numble_set_ + game_task_numble_add_;
    }

    int GameScoreController::getCompletedTaskNumble() const
    {
        return completed_task_numble_add_ + completed_task_numble_set_;
    }

    void GameScoreController::addScoreWithEliminateNumble(int numble)
    {
        this->addScore(BUBBLE_ELIMINATE_FORMULA(numble, eliminate_combo_));
    }

    void GameScoreController::addScore(int numble)
    {
        total_score_ = MAX(0, total_score_ + numble);
        this->dispatchUpdateScoreEvent();
    }

    void GameScoreController::dispatchUpdateScoreEvent()
    {
        cocos2d::EventCustom event(EVENT_SCORE_TEXT_UPDATE);
        event.setUserData(&total_score_);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
    }

    void GameScoreController::dispatchUpdateCompletedTaskEvent()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_UPDATE_COMPLETED_TASK_LABEL);
    }

    void GameScoreController::dispatchUpdateBubbleUseCount()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_UPDATE_BUBBLE_USE_COUNT_LABEL);
    }

    bool GameScoreController::gameVictory()
    {
        return this->getCompletedTaskNumble() >= this->getGameTaskNumble();
    }

    bool GameScoreController::gameDefeat()
    {
        return noUseBubbleCount() && !this->gameVictory();
    }

    bool GameScoreController::noUseBubbleCount()
    {
        return this->getBubbleUseCount() == 0;
    }

    void GameScoreController::setBubbleUseCount(int numble)
    {
        if (this->isBubbleUseCountEnable())
        {
            bubble_use_count_ = numble;
            dispatchUpdateBubbleUseCount();
        }
    }

    void GameScoreController::addBubbleUseCount(int numble)
    {
        this->setBubbleUseCount(this->getBubbleUseCount() + numble);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_UPDATE_SECOND_BUBBLE);
    }

    int GameScoreController::getBubbleUseCount()
    {
        return bubble_use_count_;
    }

    void GameScoreController::cutBubbleUseCount()
    {
        this->setBubbleUseCount(MAX(0, getBubbleUseCount()-1));
    }

    void GameScoreController::setBubbleUseCountEnable(bool flag)
    {
        use_count_enable_ = flag;
        if (!flag)
        {
            bubble_use_count_ = 10;
        }
    }

    bool GameScoreController::isBubbleUseCountEnable()
    {
        return use_count_enable_;
    }

    int GameScoreController::getTotalScore()
    {
        return total_score_;
    }

    void GameScoreController::setGameTaskNumble(int numble)
    {
        game_task_numble_set_ = numble;
    }

    void GameScoreController::addCompletedTaskNumble()
    {
        completed_task_numble_add_++;
        this->dispatchUpdateCompletedTaskEvent();
    }

    void GameScoreController::setCompletedTaskNumble(int numble)
    {
        completed_task_numble_set_ = numble;
        this->dispatchUpdateCompletedTaskEvent();
    }
}