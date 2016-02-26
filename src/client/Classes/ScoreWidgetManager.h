//*******************************************************************************
//类名称   : ScoreWidgetManager
//功能     : <游戏中得分挂件(蜘蛛.*.)管理>
//-------------------------------------------------------------------------------
//备注     :
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SCORE_WIDGET_MANAGER_H_
#define _SCORE_WIDGET_MANAGER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    typedef cocos2d::Vector<cocos2d::Node*> WidgetPointsSeed;
    typedef std::map<std::string, std::map<ScoreWidgetType, std::string>> WidgetBonePathMap;
    class ScoreWidget;
    class ScoreWidgetManager
    {
    public: 
        ~ScoreWidgetManager();
        GETINSTANCE_FUNC(ScoreWidgetManager);
    public:
        ScoreWidget* getNewScoreWidget(); 
        //cocos2d::Vec2 getScoreWidgetPositionWithVector(const cocos2d::Vector<cocos2d::Node*>& vector);
        cocos2d::Vec2 getScoreWidgetPosition();
        int getScoreWidgetTotal();
        int getScoreWidgetTotalWithType(const ScoreWidgetType& type);
        //按顺序移除移除2个挂件
        void removeTwoScoreWidget();
        void clear();
        //位置种子
        void setWidgetPointsSeed(WidgetPointsSeed seed);
        WidgetPointsSeed getWidgetPointsSeed();
        const WidgetBonePathMap& getWidgetBonePathMap();
    private:
        ScoreWidgetManager();
        //添加时间监听
        //void addEventListenerCustom();
        //判断这个点是否在以上场的挂件附近
        bool isNearbyExistence(const cocos2d::Vec2& point);
        bool isNearByBorder(const cocos2d::Vec2& point);
    private:
        std::map<ScoreWidgetType, cocos2d::Vector<ScoreWidget*>> score_widget_map_;
        std::vector<ScoreWidgetType> widget_update_sequence_;
        std::vector<ScoreWidgetType> widget_remove_sequence_;
        int widget_total_;
        //多少连击加的什么总类的蜘蛛
        //ScoreWidgetType ComboToScoreWidgetType[6] =
        //{
        //    kScoreWidgetBlue,
        //    kScoreWidgetBlue,
        //    kScoreWidgetBlue,
        //    kScoreWidgetPink,
        //    kScoreWidgetPink,
        //    kScoreWidgetGreen
        //};
        std::map<int, ScoreWidgetType> combo_to_type_;
        //位置种子
        WidgetPointsSeed widget_points_seed_;
        WidgetBonePathMap bonename_to_map_;
    };
}
#endif //_SCORE_WIDGET_MANAGER_H_