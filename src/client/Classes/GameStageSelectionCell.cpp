#include "GameStageSelectionCell.h"
#include "cocostudio\CocoStudio.h"
#include "StageSelectionMenu.h"
#include "StageDataManager.h"
#include "StageNumble.h"
namespace bubble_second {
    GameStageSelectionCell::GameStageSelectionCell()
    {
    }

    GameStageSelectionCell::~GameStageSelectionCell()
    {
    }

    bool GameStageSelectionCell::isInCell(int level)
    {
        return level < this->getLevelMax();
    }

    GameStageSelectionCell * bubble_second::GameStageSelectionCell::create()
    {
        GameStageSelectionCell *pRet = new(std::nothrow) GameStageSelectionCell();
        if (pRet && pRet->init())
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

    bool GameStageSelectionCell::init()
    {
        static int cellNumble = GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN;
        if (!(this->addBackground(cellNumble) && this->addSelectionMenu(cellNumble)))
        {
            StageNumble::getInstance()->clear();
            cellNumble = GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN;
            return false;
        }
        ++cellNumble;
        return true;
    }
    bool GameStageSelectionCell::addBackground(int cell_numble)
    {
        char path[20];
        sprintf(path, GAME_STAGE_NODE_CSB_FORMAT, cell_numble);
        if (!cocos2d::FileUtils::getInstance()->isFileExist(path))
        {
            return false;
        }
        background_node_ = cocos2d::CSLoader::createNode(path);
        background_node_->setScale(GAME_STAGE_SELECTION_CELL_SCALE);
        this->addChild(background_node_);
        return true;
    }
    bool GameStageSelectionCell::addSelectionMenu(int cell_numble)
    {
        int tag = GAME_STAGE_SELECTION_CELL_MENU_POSITION_NODE_TAG_BEGIN;
        cocos2d::Node* node = nullptr;
        StageSelectionMenu* menu = nullptr;
        bool result = false;
        while (true)
        {
            int stage_numble = StageNumble::getInstance()->getStageNumble();
            node = background_node_->getChildByTag(tag);
            if (node && !StageNumble::getInstance()->moreThanStageTotal())
            {
                menu = StageSelectionMenu::create(cell_numble, stage_numble, StageDataManager::getInstance()->getStageTypeWithNumble(stage_numble));
                node->addChild(menu);
                StageNumble::getInstance()->nextStageNumble();
                ++tag;
                result = true;
            }
            else
            {
                this->setLevelMax(stage_numble);
                break;
            }
        }
        return result;
    }
    void GameStageSelectionCell::setLevelMax(int level)
    {
        level_max_ = level;
    }
    int GameStageSelectionCell::getLevelMax()
    {
        return level_max_;
    }
}