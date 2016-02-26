//#include "GameCharacterFactory.h"
//namespace bubble_second {
//    GameCharacterFactory::GameCharacterFactory()
//    {
//        this->init();
//    }
//
//
//    GameCharacterFactory::~GameCharacterFactory()
//    {
//    }
//
//    void GameCharacterFactory::init()
//    {
//        name_to_path_[ROLE_GENJYO_SANZO_NAME] = ROLE_GENJYO_SANZO_PATH;
//        name_to_path_[ROLE_CHO_GONO_NAME] = ROLE_CHO_GONO_PATH;
//        name_to_path_[ROLE_SON_GOKU_NAME] = ROLE_SON_GOKU_PATH;
//        name_to_path_[PET_SHAKURYU_NAME] = PET_SHAKURYU_PATH;
//        name_to_path_[PET_MONKEY_NAME] = PET_MONKEY_PATH;
//
//        //test
//        change_texture_[ROLE_GENJYO_SANZO_NAME] = ROLE_CHO_GONO_NAME;
//        change_texture_[ROLE_CHO_GONO_NAME] = ROLE_SON_GOKU_NAME;
//        change_texture_[ROLE_SON_GOKU_NAME] = ROLE_GENJYO_SANZO_NAME;
//
//        change_texture_[PET_SHAKURYU_NAME] = PET_MONKEY_NAME;
//        change_texture_[PET_MONKEY_NAME] = PET_SHAKURYU_NAME;
//    }
//
//    GameCharacter* GameCharacterFactory::createCharacterWithName(const std::string& name)
//    {
//        GameCharacter* character = GameCharacter::createWithName(name);
//        return character;
//    }
//
//    std::string GameCharacterFactory::getPathWithName(const std::string& name)
//    {
//        return name_to_path_[name];
//    }
//
//    std::string GameCharacterFactory::getChangePathWithName(const std::string& name)
//    {
//        return change_texture_[name];
//    }
//}