#include "StageNumble.h"
#include "StageDataManager.h"

namespace bubble_second {
    StageNumble::StageNumble()
    {
        this->clear();
    }

    void StageNumble::clear()
    {
        stage_numble_ = GAME_STAGE_NUMBLE_BEGIN;
    }


    StageNumble::~StageNumble()
    {
    }

    int StageNumble::getStageNumble() const
    {
        return stage_numble_;
    }

    void StageNumble::nextStageNumble()
    {
        ++stage_numble_;
    }

    bool StageNumble::moreThanStageTotal()
    {
        auto a = StageDataManager::getInstance()->getStageTotalNumble();
        auto b = stage_numble_ > a;
        return stage_numble_ > StageDataManager::getInstance()->getStageTotalNumble();
    }
}