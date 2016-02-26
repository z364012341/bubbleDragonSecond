#include <sstream>
#include "XMLTool.h"
#include "tinyxml2\tinyxml2.h"
#include "StageDataModule.h"
#include "StartNumbleModule.h"
namespace bubble_second {
    XMLTool::XMLTool()
    {
    }

    XMLTool::~XMLTool()
    {
    }

    StageDataModule* XMLTool::decodeStageXMLWithStageNumble(int stageNumble)
    {
        using std::map;
        using std::vector;
        using std::string;
        std::stringstream intout;
        intout << stageNumble;
        std::string str = "";
        intout >> str;
        std::string xmlPath = "res/stage" + str + ".xml";
        if (!cocos2d::CCFileUtils::getInstance()->isFileExist(xmlPath))
        {
            return nullptr;
        }
        cocos2d::Data data = cocos2d::CCFileUtils::getInstance()->getDataFromFile(xmlPath);
        tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();//创建一个xml对象
        tinyxml2::XMLError errorId = pDoc->Parse(reinterpret_cast<char*>(data.getBytes()), data.getSize());
        if (errorId != 0) {
            //xml格式错误
            //map<string, map<string, string>> error;
            return nullptr;
        }
        tinyxml2::XMLElement *rootEle = pDoc->RootElement();
        //获取第一个节点属性
        const tinyxml2::XMLAttribute *attribute = rootEle->FirstAttribute();
        //获取data的属性
        tinyxml2::XMLElement *dicEle = rootEle->FirstChildElement(STAGE_XML_FIELDS_FIRST_ELEMENT.c_str());
        tinyxml2::XMLElement *bubblesEle = dicEle->FirstChildElement(STAGE_XML_FIELDS_SECOND_ELEMENT.c_str());
        vector<map<string, string>> bubbles_data;
        while (bubblesEle) {
            map<string, string> value;
            value[STAGE_XML_FIELDS_BUBBLETYPE] = bubblesEle->Attribute(STAGE_XML_FIELDS_BUBBLETYPE.c_str());
            value[STAGE_XML_FIELDS_ROW] = bubblesEle->Attribute(STAGE_XML_FIELDS_ROW.c_str());
            value[STAGE_XML_FIELDS_COL] = bubblesEle->Attribute(STAGE_XML_FIELDS_COL.c_str());
            value[STAGE_XML_FIELDS_CLOUD] = bubblesEle->Attribute(STAGE_XML_FIELDS_CLOUD.c_str());
            value[STAGE_XML_FIELDS_PATH] = bubblesEle->Attribute(STAGE_XML_FIELDS_PATH.c_str());
            bubbles_data.push_back(value);
            bubblesEle = bubblesEle->NextSiblingElement();
        }
        StageDataModule* module = StageDataModule::create();
        module->setBubblesData(bubbles_data);
        dicEle = dicEle->NextSiblingElement();
        module->setBubbleNumbleMax(convertStringToInt(dicEle->Attribute(STAGE_XML_FIELDS_BUBBLENUM.c_str())));
        module->setStageType(convertStringToInt(dicEle->Attribute(STAGE_XML_FIELDS_STAGETYPE.c_str())));
        StartNumbleModule start_numble(convertStringToInt(dicEle->Attribute(STAGE_XML_FIELDS_START1.c_str())),
            convertStringToInt(dicEle->Attribute(STAGE_XML_FIELDS_START2.c_str())),
            convertStringToInt(dicEle->Attribute(STAGE_XML_FIELDS_START3.c_str())));
        module->setStartNumbleModule(start_numble);
        module->setBubbleColorRange(dicEle->Attribute(STAGE_XML_FIELDS_COLORS.c_str()));
        delete pDoc;
        return module;
    }

    int XMLTool::convertStringToInt(const std::string& str)
    {
        std::stringstream out;
        out << str;
        int numble = 0;
        out >> numble;
        return numble;
    }
    
}