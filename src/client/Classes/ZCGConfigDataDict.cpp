#include "ZCGConfigDataDict.h"
#include "CommonFunc.h"
#include "tinyxml2/tinyxml2.h"
#include "platform/CCFileUtils.h"
#include <sstream>

#define XML_PATH      "res/zcgConfigData.xml"

using namespace std;

//ZCGConfigDataDict* ZCGConfigDataDict::m_dict = 0;

ZCGConfigDataDict* ZCGConfigDataDict::getInstance()
{
  //  if (!m_dict)
  //  {
		//m_dict = new ZCGConfigDataDict();
  //      m_dict->loadInfos();
  //  }
    static ZCGConfigDataDict m_dict;
    m_dict.loadInfos();
    return &m_dict;
}

ZCGConfigDataDict::ZCGConfigDataDict(void)
{
}

ZCGConfigDataDict::~ZCGConfigDataDict(void)
{
}

int ZCGConfigDataDict::loadInfos()
{


    cocos2d::Data data = cocos2d::CCFileUtils::getInstance()->getDataFromFile(XML_PATH);
    unsigned char *pBytes = data.getBytes();
    long size = data.getSize();
    if (size <= 0)
    {
        //MyGame::getInstance()->m_mainLog->printlogs(Logging::LOG_LEVEL_WARN, "load xml file:%s. error size:%d", fileName, size);
        return NULL;
    }
    tinyxml2::XMLDocument *doc = new tinyxml2::XMLDocument;
    tinyxml2::XMLError error = doc->Parse(reinterpret_cast<char*>(pBytes), size);
    if (tinyxml2::XML_NO_ERROR != error)
    {
        //MyGame::getInstance()->m_mainLog->printlogs(Logging::LOG_LEVEL_WARN, "load xml file:%s. error:%d", fileName, error);
        return NULL;
    }
    tinyxml2::XMLElement * rootNode = doc->RootElement();

    if(!rootNode){
        return 1;
    }
    tinyxml2::XMLElement * curNode = rootNode->FirstChildElement("data");
    while(curNode){
        int key = curNode->IntAttribute("key");
        string value = curNode->Attribute("value");
        m_datasMap.insert(pair<int,string>(key,value));
        curNode = curNode->NextSiblingElement("data");
    }
    delete doc;
    doc = nullptr;
    return 0;
}

const std::string ZCGConfigDataDict::getStringData(int key) const{
    map<int, string>::const_iterator iter = m_datasMap.find(key);
    if (iter == m_datasMap.end())
    {
        return "";
    }else{
        return (*iter).second;
    }
}

const int ZCGConfigDataDict::getIntData(int key) const{
	int int_temp;
	stringstream stream(getStringData(key));
	stream >> int_temp;
	return int_temp;
}

