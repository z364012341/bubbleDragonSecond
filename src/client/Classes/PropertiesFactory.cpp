#include "PropertiesFactory.h"
#include "ColorBombProperty.h"
#include "BombBombProperty.h"
#include "WoodenHammerProperty.h"
#include "StavesProperty.h"
namespace bubble_second {
    PropertiesFactory::PropertiesFactory()
    {
        this->init();
    }

    PropertiesFactory::~PropertiesFactory()
    {
    }

    void PropertiesFactory::init()
    {
        //name_to_path_[PROPS_COLOR_BOMB_NAME] = PROPS_COLOR_BOMB_PATH;
        //name_to_path_[PROPS_BOMB_BOMB_NAME] = PROPS_BOMB_BOMB_PATH;
        //name_to_path_[PROPS_STAVES_NAME] = PROPS_STAVES_PATH;
        //name_to_path_[PROPS_ONEHANDED_MACES_NAME] = PROPS_ONEHANDED_MACES_PATH;

        name_to_handle_[PROPS_COLOR_BOMB_NAME] = [=]() {return ColorBombProperty::create(); };
        name_to_handle_[PROPS_BOMB_BOMB_NAME] = [=]() {return BombBombProperty::create(); };
        name_to_handle_[PROPS_WOODEN_HAMMER_NAME] = [=]() {return WoodenHammerProperty::create(); };
        name_to_handle_[PROPS_STAVES_NAME] = [=]() {return StavesProperty::create(); };
    }


    BaseProperty* PropertiesFactory::createPropertyWithName(const std::string& name)
    {
        auto handle = name_to_handle_[name];
        if (handle)
        {
            return handle();
        }
        return nullptr;
    }

    //std::string PropertiesFactory::getPathWithName(const std::string& name)
    //{
    //    return std::string();
    //}

}