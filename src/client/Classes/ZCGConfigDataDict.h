#ifndef __ZCG_CONFIG_DATA_DICT_H__
#define __ZCG_CONFIG_DATA_DICT_H__
#include <map>
#include <string>

class ZCGConfigDataDict
{
public:
    static const int KEY_FRAME_WIDTH = 1001;
	static const int KEY_FRAME_HEIGHT = 1002;
    static const int KEY_OPEN_CMD_SHOW = 1003;
	static const int KEY_GAME_VERSION = 1004;
	static ZCGConfigDataDict* getInstance();
    const std::string getStringData(int key) const;
	const int getIntData(int key) const;
protected:
	ZCGConfigDataDict(void);
	~ZCGConfigDataDict(void);
    int loadInfos();
	//static ZCGConfigDataDict* m_dict;
    std::map<int, std::string> m_datasMap;
};
#endif 

