#include "StartNumbleModule.h"
namespace bubble_second {
    StartNumbleModule::StartNumbleModule()
    {
        init(0.0f, 0.0f, 0.0f);
    }
    StartNumbleModule::StartNumbleModule(int numble1, int numble2, int numble3)
    {
        init((float)numble1, (float)numble2, (float)numble3);
    }

    StartNumbleModule::~StartNumbleModule()
    {
    }

    float StartNumbleModule::getPercentWithScore(float score)
    {
        return score / start_numble_[SCORE_PROGRESS_START_3_KEY] * 100.0f;
    }

    StartPercent StartNumbleModule::getPercentModule()
    {
        return start_percent_;
    }

    void StartNumbleModule::init(float numble1, float numble2, float numble3)
    {
        start_numble_[SCORE_PROGRESS_START_1_KEY] = numble1;
        start_numble_[SCORE_PROGRESS_START_2_KEY] = numble2;
        start_numble_[SCORE_PROGRESS_START_3_KEY] = numble3;
        start_percent_[SCORE_PROGRESS_START_1_KEY] = numble3 != 0 ? numble1 / numble3 : 0.0f;
        start_percent_[SCORE_PROGRESS_START_2_KEY] = numble3 != 0 ? numble2 / numble3 : 0.0f;
        start_percent_[SCORE_PROGRESS_START_3_KEY] = numble3 != 0 ? numble3 / numble3 : 0.0f;
    }
}