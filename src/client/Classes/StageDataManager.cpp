#include "StageDataManager.h"
#include "StageDataModule.h"
#include "XMLTool.h"
namespace bubble_second {
    StageDataManager::StageDataManager()
    {
    }

    StageDataManager::~StageDataManager()
    {
    }

    void StageDataManager::initStageData()
    {
        XMLTool* xml = new XMLTool;
        int numble = 1;
        StageDataModule* module = nullptr;
        while (true)
        {
            module = xml->decodeStageXMLWithStageNumble(numble);
            if (module)
            {
                this->addStageDataModule(module);
                numble++;
            }
            else
            {
                break;
            }
        }
        CC_SAFE_DELETE(xml);
    }

    StageDataModule* StageDataManager::getStageDataWithNumble(int numble)
    {
        ssize_t i = numble - 1;
        return stage_data_map_.at(i);
    }

    int StageDataManager::getStageTotalNumble()
    {
        return stage_data_map_.size();
    }

    StageType StageDataManager::getStageTypeWithNumble(int numble)
    {
        return this->getStageDataWithNumble(numble)->getStageType();
    }

    bool StageDataManager::isInStageNumbleRange(int numble)
    {
        return numble <= stage_data_map_.size();
    }

    void StageDataManager::addStageDataModule(StageDataModule* module)
    {
        stage_data_map_.pushBack(module);
    }
}