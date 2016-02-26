#ifndef __COMMON_FUCTION_H__
#define __COMMON_FUCTION_H__
#include "tinyxml2\tinyxml2.h"
#include "cocos2d.h"
class CommonFunc
{
public:
    CommonFunc(void);
    ~CommonFunc(void);
    //static tinyxml2::XMLElement * loadInnerDictFile(const char * fileName);
    static bool stringEqual(const char* first, const char* second, int cycleCount = INT_MAX);
    static void parseStringToIntArray(std::vector<int>& array, const char* str, char signal);
    static bool writeToNativePlace(char *pContent, const char * pFileName);
    static void split(std::vector<std::string>& array, std::string str, std::string pattern);
	static std::string getCurTimeStr();
};


#endif //__COMMON_FUCTION_H__