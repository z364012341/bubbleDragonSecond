#include "CommonFunc.h"
#include "platform/CCFileUtils.h"
#include <ctime>
#include <sstream>
#include <sys\timeb.h>
#define  ANDROID_SD_ROOT_PATH  "/mnt/sdcard/";
using namespace tinyxml2;

using namespace cocos2d;

CommonFunc::CommonFunc(void)
{

}

CommonFunc::~CommonFunc(void)
{
}

bool CommonFunc::stringEqual(const char* first, const char* second, int cycleCount)
{
    int count = 0;
    if (first == second)
    {
        return true;
    }
    while(*first != '\0' && *second != '\0' && *first == *second && count < cycleCount)
    {
        ++first;
        ++second;
        ++count;
    }
    if (count == cycleCount || (*first == 0 && *second == 0))
    {
        return true;
    }
    return false;
}
bool CommonFunc::writeToNativePlace(char *pContent, const char * pFileName){
    std::string path = cocos2d::CCFileUtils::getInstance()->getWritablePath() + pFileName;
    FILE* file = fopen(path.c_str(), "w");  
    if (file) {  
        fputs(pContent, file);  
        fclose(file);
        return true;
    }  
    return false;  
}

void CommonFunc::parseStringToIntArray(std::vector<int>& array, const char* str, char signal)
{
    int result = 0;
    char spiltStr[sizeof(str)];
    memset(spiltStr, 0 , sizeof(spiltStr));
    int count = 0;
    while (*str !='\0')
    {
        if (*str == signal)
        {
            spiltStr[count] = '\0';
            result = atoi(spiltStr);
            array.push_back(result);
            memset(spiltStr, 0 , sizeof(spiltStr));
            count = 0;
        }else{
            spiltStr[count] = *str;
            count++;
        }
        ++str;
    }
    if (count > 0)
    {
        spiltStr[count] = '\0';
        result = atoi(spiltStr);
        array.push_back(result);
    }
}

//×Ö·û´®·Ö¸îº¯Êý
void CommonFunc::split(std::vector<std::string>& array, std::string str, std::string pattern)
{
    std::string::size_type pos;
    str+=pattern;//À©Õ¹×Ö·û´®ÒÔ·½±ã²Ù×÷
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if((int)pos<size)
        {
            std::string s=str.substr(i,pos-i);
            array.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
}

std::string CommonFunc::getCurTimeStr()
{
	struct tm *tm;
	time_t timep;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
	time(&timep);
#else  
	struct timeval now;
    gettimeofday(&now, NULL);
	timep = now.tv_sec;
#endif  
	tm = localtime(&timep);
	int year = tm->tm_year + 1900;
	int month = tm->tm_mon + 1;
	int day = tm->tm_mday;
	int hour = tm->tm_hour;
	std::ostringstream curTime;
	curTime << year << month << day << hour;
	return curTime.str();
}
