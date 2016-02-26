//*******************************************************************************
//类名称   : GameBubbleMap
//功能     : <游戏场景中的地图容器>
//-------------------------------------------------------------------------------
//备注     :
//          
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_BUBBLE_MAP_H_
#define _GAME_BUBBLE_MAP_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "GameBubbleMapImple.h"
namespace bubble_second {
    typedef bool Empty;
    class GameBubbleMap : public cocos2d::Ref
    {
    public:
        CREATE_FUNC(GameBubbleMap);
        ~GameBubbleMap();
        //void initWithStage(const std::string& stage_str);
    public:
        //处理碰到小球
        void disposeContactBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        //处理碰到闪电
        BubbleVector disposeContactLightningBubble(const cocos2d::Vec2& contact_index);
        //处理碰到黑洞
        //void disposeContactBlackHoleBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        void disposeContactBlackHoleBubble(BaseBubble* flying_bubble, BaseBubble* blackhole_bubble);
        //处理碰到c4小球
        BubbleVector disposeContactBombBombBubble(const cocos2d::Vec2& contact_index);
        //处理buff泡泡掉落
        void disposeBuffBubbleDown(BaseBubble* bubble);
        //处理氤氲泡泡
        void disposeDarkCloudBubble(const cocos2d::Vec2& contact_index);
        //处理使用彩球炸弹
        BubbleVector disposeColorBombBubble(const cocos2d::Vec2& colorbomb_index);
        //处理使用道具球
        void disposeUsedPropertyBubble(BaseBubble* property_bubble, const cocos2d::Vec2& contact_index);
        //处理炸两圈炸弹
        BubbleVector disposeBombPropertyBubble(const cocos2d::Vec2& bomb_index);
        //进行泡泡掉落检测
        void checkAirBubbles();
        //进行泡泡map的位置调整
        void adjustGameScenePosition();
        //查找屏幕内的小球
        void findBubblesInVisibleSize();
        //处理使用小木锤
        void disposeUseWoodenHammer(BaseBubble* bubble);
        //处理使用法杖
        void disposeUseStaves(BaseBubble* bubble);
        //处理顶部消除玩法的胜利条件
        void disposeCompletedTaskNumble();
        //加载关卡信息
        void loadStageDataWithNumble(int numble);
        //胜利
        void disposeGameVictory();
        //处理游戏结果
        void disposeGameDefeat();
        //处理风车转转小球碰到边界
        void disposeWindmillBubbleContactBorder(BaseBubble* bubble);
        //处理+3特殊泡泡的道具
        void disposeUsedAddSpecialBubbleProps();
    private:
        GameBubbleMap();
        bool init();
        void runBubbleEffect(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        void eliminateBubbles(BubbleVector vector, BaseBubble* prepare_bubble = nullptr, float delay_time = 0.0f);
        //消除泡泡的时候做的remove的操作
        void disposeEliminateHandle(BubbleVector* same_bubbles, float delay_time);
        //分发自定义事件
        void dispatchCustomEvent(const std::string& eventName, void* userData = nullptr);
        //处理buff类的小球
        Empty disposeAroundBuffBubble(const cocos2d::Vec2& cling_index);
        BubbleVector disposeBuffBubble(BubbleVector vector);
        //处理彩虹泡泡
        Empty disposeRainbowSealBubble(BaseBubble* prepare_bubble);
        //派发增加连击的事件
        void dispatchAddEliminateComboEvent(cocos2d::Vec2 prepare_point);
        //判断够不够消除个数
        bool canEliminate(const BubbleVector& vector);
        //void setStageType(const StageType& type);
        //StageType getStageType();
        //bool isWindmillStage();
        void disposeClingBubble(BaseBubble* prepare_bubble, BaseBubble* cling_bubble);
        //处理大风车转转转
        void disposeWindmillRotation(BaseBubble* prepare_bubble);
        //处理粘附上去之后有没有彩虹封印或者buff泡泡之类的
        void disposeAfterClinging(BaseBubble* prepare_after_cling_bubble);
        //返回屏幕内小球
        BubbleVector getBubbleInVisibleSize();
    private:
        GameBubbleMapImple* game_bubble_map_impl_;
        std::map<BubbleType, std::function<BubbleVector(cocos2d::Vec2)>> type_to_disposed_;
        std::map<StageType, std::function<bool()>> type_to_complete_handle_;
    };
}
#endif //_GAME_BUBBLE_MAP_H_