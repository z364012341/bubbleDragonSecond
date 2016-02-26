#include "UserDataManager.h"
#include "StageDataManager.h"

namespace bubble_second {
    UserDataManager::UserDataManager()
    {
    }

    UserDataManager::~UserDataManager()
    {
    }
    void UserDataManager::readStageFile()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getStageDataPath();
        if (file_utils->isFileExist(path))
        {
            stage_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    void UserDataManager::readUserDataFile()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getUserDataPath();
        if (file_utils->isFileExist(path))
        {
            user_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    int UserDataManager::getStartNumbleWithLevel(int level)
    {
        char levelStr[10];
        sprintf(levelStr, "%d", level);
        if (stage_data_.find(levelStr) != stage_data_.end())
        {
            return stage_data_.at(levelStr).asInt();
        }
        return 0;
    }
    void UserDataManager::setPresentCell(int cell_numble)
    {
        present_cell_ = cell_numble;
    }
    int UserDataManager::getPresentCell()
    {
        return present_cell_;
    }
    void UserDataManager::setUserNickname(const std::string & name)
    {
        user_data_[USER_DATA_NICKNAME_KEY] = name;
    }
    std::string UserDataManager::getUserNickname() const
    {
        if (user_data_.find(USER_DATA_NICKNAME_KEY) != user_data_.end())
        {
            return user_data_.at(USER_DATA_NICKNAME_KEY).asString();
        }
        return "";
    }
    void UserDataManager::setGameMusicEnable(bool flag)
    {
        user_data_[USER_DATA_MUSIC_KEY] = flag;
    }
    bool UserDataManager::isGameMusicEnable()
    {
        if (user_data_.find(USER_DATA_MUSIC_KEY) != user_data_.end())
        {
            return user_data_.at(USER_DATA_MUSIC_KEY).asBool();
        }
        return false;
    }
    void UserDataManager::setSoundEffect(bool flag)
    {
        user_data_[USER_DATA_SOUND_EFFECT_KEY] = flag;
    }
    bool UserDataManager::isSoundEffectEnable()
    {
        if (user_data_.find(USER_DATA_SOUND_EFFECT_KEY) != user_data_.end())
        {
            return user_data_.at(USER_DATA_SOUND_EFFECT_KEY).asBool();
        }
        return false;
    }
    void UserDataManager::saveUserData()
    {
        std::string path = getUserDataPath();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(user_data_, path);
    }
    bool UserDataManager::isCompletedGame()
    {
        return this->getStagePassCount() == StageDataManager::getInstance()->getStageTotalNumble();
    }
    void UserDataManager::writeStageDataToFile()
    {
        std::string path = getStageDataPath();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(stage_data_, path);
    }
    void UserDataManager::updateStageData(int level, int start_numble)
    {
        char levelStr[10];
        sprintf(levelStr, "%d", level);
        if (stage_data_.find(levelStr) != stage_data_.end() && stage_data_[levelStr].asInt() >= start_numble)
        {
            return;
        }
        if (level-1 == stage_data_.size())
        {
            stage_data_[levelStr] = cocos2d::Value(start_numble);
            this->writeStageDataToFile();
        }
    }
    void UserDataManager::readDataFile()
    {
        this->readStageFile();
        this->readUserDataFile();
    }
    std::string UserDataManager::getStageDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_STAGE_DATA_PATH;
    }
    std::string UserDataManager::getUserDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_USER_DATA_PATH;
    }
    int UserDataManager::getStagePassCount()
    {
        return stage_data_.size();
    }
}