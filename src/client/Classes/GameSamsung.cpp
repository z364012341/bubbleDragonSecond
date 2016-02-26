#include "GameSamsung.h"
#include "ScoreProgressStart.h"
namespace bubble_second {
    GameSamsung::GameSamsung()
    {
    }

    GameSamsung::~GameSamsung()
    {
    }

    GameSamsung * bubble_second::GameSamsung::createWithNumble(int numble)
    {
        GameSamsung *pRet = new(std::nothrow) GameSamsung();
        if (pRet && pRet->initWithNumble(numble))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    bool GameSamsung::initWithNumble(int numble)
    {
        this->addStart();
        this->controlStartLight(numble);
        return true;
    }
    void GameSamsung::addStart()
    {
        this->addStartLeft();
        this->addStartMiddle();
        this->addStartRight();
    }
    void GameSamsung::addStartLeft()
    {
        ScoreProgressStart* start = ScoreProgressStart::create();
        this->addChild(start);
        start->setPosition(-GAME_SAMSUNG_TWO_SIDES_POSITION_X, 0.0f);
        start->setRotation(-GAME_SAMSUNG_TWO_SIDES_ROTATIOIN);
        start_vector_.pushBack(start);
    }
    void GameSamsung::addStartMiddle()
    {
        ScoreProgressStart* start = ScoreProgressStart::create();
        this->addChild(start);
        start->setPosition(0.0f, GAME_SAMSUNG_MIDDLE_POSITION_Y);
        start_vector_.pushBack(start);
    }
    void GameSamsung::addStartRight()
    {
        ScoreProgressStart* start = ScoreProgressStart::create();
        this->addChild(start);
        start->setPosition(GAME_SAMSUNG_TWO_SIDES_POSITION_X, 0.0f);
        start->setRotation(GAME_SAMSUNG_TWO_SIDES_ROTATIOIN);
        start_vector_.pushBack(start);
    }
    void GameSamsung::controlStartLight(int numble)
    {
        for (int i = 0; i < start_vector_.size(); i++)
        {
            start_vector_.at(i)->controlLightWithFlag(i<numble);
        }
    }
}