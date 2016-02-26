//*******************************************************************************
//类名称   : PropertiesFactory
//功能     : <道具的工厂类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _PROPERTIES_FACTORY_H_
#define _PROPERTIES_FACTORY_H_
#include "cocos2d.h"
#include "BaseProperty.h"
namespace bubble_second {
    class PropertiesFactory
    {
    public:
        GETINSTANCE_FUNC(PropertiesFactory);
        ~PropertiesFactory();
    public:
        BaseProperty* createPropertyWithName(const std::string& name);
        //std::string getPathWithName(const std::string& name);
    private:
        PropertiesFactory();
        void init();
    private:
        //std::map<std::string, std::string> name_to_path_;
        std::map<std::string, std::function<BaseProperty*()>> name_to_handle_;
    };
}
#endif //_PROPERTIES_FACTORY_H_