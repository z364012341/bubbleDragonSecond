//*******************************************************************************
//类名称   : GameTextInfo
//功能     : <游戏文字信息类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_TEXT_INFO_H_
#define _GAME_TEXT_INFO_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameTextInfo
    {
    public:
        GETINSTANCE_FUNC(GameTextInfo);
        ~GameTextInfo();
        std::string getTextInfoWithKey(const std::string& key) const;
        std::string getTextInfoWithStageType(const StageType& type);
        std::string getCommodityCoinNumbleWithKey(const std::string& key) const;
        std::string getCommodityDiamondNumbleWithKey(const std::string& key) const;
        cocos2d::Value getCommodityCoinValueWithKey(const std::string& key) const;
        void plistToMap();
    private:
        GameTextInfo();
    private:
        cocos2d::ValueMap plist_map_;
        std::map<StageType, std::string> stagetype_to_key_;
        cocos2d::ValueMap commodity_map_;
    };
}
#endif //_GAME_TEXT_INFO_H_