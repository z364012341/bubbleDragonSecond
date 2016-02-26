//*******************************************************************************
//类名称   : ScoreWidget
//功能     : <得分挂件.,. 就是泡泡女巫里面的蜘蛛啦>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SCORE_WIDGET_H_
#define _SCORE_WIDGET_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class ScoreWidget : public cocos2d::Sprite
    {
    public:
        static ScoreWidget* createWithType(const ScoreWidgetType& type)
        {
            ScoreWidget *pRet = new(std::nothrow) ScoreWidget();
            if (pRet && pRet->initWithType(type))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~ScoreWidget();
    public:
        void contactOnce();
    public:
        void addPhysicsBody();
        void removeScoreWidget();
        //升级挂件
        void updateScoreWidgetType();
        ScoreWidgetType getType();
        void addOneCombo();
        void comboClear();
        //进场动画
        void runEnterAction();
        //第一次的进场动画
        void runFirstEnterActioin();
        //设置管理分发给自己的位置
        void setSelfPosition(const cocos2d::Vec2& point);
        cocos2d::Vec2 getSelfPosition();
    private:
        ScoreWidget();
        bool initWithType(const ScoreWidgetType& type);
        void setType(const ScoreWidgetType& type);
        //获取撞击增加的分数
        int getContactScore();
        void turnOffCombo(float);
        //分数标签
        cocos2d::LabelAtlas* getPopScoreLabel();
        void setPopScoreLabel(cocos2d::LabelAtlas* label);
        //撞击特效
        void runContactAction(int score);
        //添加动画
        void addArmature();
        //播放飞行动画
        void playFlyingAnimation(float duration);
        //更新分数标签
        void updatePopScoreLabel(int score);
        //是否在播放撞击动画
        bool canPlayingContactAnimation();
        void setPlayContactAnimationEnabled(bool flag);
    private:
        ScoreWidgetType type_;
        bool action_flag_ = true;
        //std::map<ScoreWidgetType, std::string> type_to_path_;
        //std::map<ScoreWidgetType, std::string> type_to_armature_name_;
        std::map<ScoreWidgetType, ScoreWidgetType> type_update_to_type_;
        std::map<ScoreWidgetType, int> type_to_score_;
        int widget_combo_;
        bool combo_flag_;
        cocos2d::LabelAtlas* pop_score_label_;
        cocos2d::Vec2 self_position_;
        cocostudio::Armature* armature_;
    };
}
#endif //_SCORE_WIDGET_H_