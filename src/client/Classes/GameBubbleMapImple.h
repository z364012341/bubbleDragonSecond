//*******************************************************************************
//类名称   : GameBubbleMapImple
//功能     : <游戏场景中的地图容器的数据隐藏>
//-------------------------------------------------------------------------------
//备注     : <存放泡泡索引以及屏幕中的位置,单行11个,双行10个球>
//           <检测小球和寻找同色小球有流程图,>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_BUBBLE_MAP_IMPLEMENTATION_H_
#define _GAME_BUBBLE_MAP_IMPLEMENTATION_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "StageDataModule.h"
namespace bubble_second {
    //typedef std::map<int, cocos2d::Map<int, BaseBubble*>> BubbleSpriteMap;
    //typedef cocos2d::Vector<BaseBubble*> BubbleVector;
    //typedef std::map<std::string, BubbleVector> BubbleVectorMap;
    class ColorBubble;
    class BubbleColorRender;
    class GameBubbleMapImple
    {
    public:
        GameBubbleMapImple();
        ~GameBubbleMapImple();
    public:
        //TODO根据关卡数来初始化泡泡容器,参数需要输入string类型
        BubbleSpriteMap initBubbleSpriteVetctor(BubbleColorRender* render, const BubblesData& stage_info, const StageType& stage_type);
        //碰撞后获取颜色相同的小球, 参数是附着后的发射小球的索引
        BubbleVector getSametypeBubbleWithIndex(const cocos2d::Vec2& index);
        //根据传入的vector来消除bubble_sprite_map_中的小球
        void removeSpriteFromeMap(const BubbleVector& vector);
        //根据索引来删除bubble_sprite_map_
        void removeSpriteFromeMapWithIndex(const cocos2d::Vec2& index);
        //把小球粘附上去
        BaseBubble* clingBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        //获取需要播放撞击特效的小球
        BubbleVectorMap getEffectBubbles(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        //处理消除后的悬空小球
        BubbleVector disposeAirBubbleAfterEliminate();
        //获取传入的x索引的所在的那一行小球, 
        BubbleVector getSameRowBubblesWithIndex(const cocos2d::Vec2& index);
        //获取传入的索引周围的阴云泡泡
        cocos2d::Vector<ColorBubble*> getAroundDarkCloudBubbleWithIndex(const cocos2d::Vec2& index);
        //根据索引获取容器里的小球
        BaseBubble* getSpriteWithIndex(const cocos2d::Vec2& index);
        //获取四周6个小球
        BubbleVector getAroundBubbleWithIndex(const cocos2d::Vec2& index);
        //获取周围除了组件的小球
        BubbleVector getAroundBubbleExceptComponentWithIndex(const cocos2d::Vec2& index);
        //获取周围的组件小球
        BubbleVector getAroundComponentBubbleWithIndex(const cocos2d::Vec2& index);
        //获取周围两圈的18个位置的小球
        BubbleVector getTwoAroundBubbleWithIndex(const cocos2d::Vec2& index);
        //获取四周的普通小球
        BubbleVector getAroundColorBubblesWithIndex(const cocos2d::Vec2& index);
        //获取最下面的泡泡的位置
        float getBubblesMinPosition();
        //获取屏幕内的小球
        BubbleVector getBubblesInVisibleSize();
        //添加泡泡的组件
        void addBubbleComponentByBubble(BaseBubble* bubble);
        //增加挂点
        void disposeAddSuspensionPoint(BaseBubble* bubble);
        void addSuspensionPointToVector(BaseBubble* bubble);
        //移除挂点容器
        void disposeRemoveSuspensionPoint(BaseBubble* bubble);
        void removeSuspensionPointFromVector(BaseBubble* bubble);
        //检查顶部0行索引空泡泡数量
        int getTopRowNullBubbleNumble();
        //合并两个BubbleVector, 重复的不要
        void mergeTwoBubbleVector(BubbleVector* first_vector, const BubbleVector& second_vector);
        //确认容器的元素是否存在
        bool isExistInVector(const BubbleVector& vector, BaseBubble* bubble);
        //获取容器内的剩余元素
        BubbleVector getAllBubblesFromMap();
        //分离风车泡泡
        BubbleVector separateWindmillBubble();
        //获取风车旋转的角度 
        float getWindmillRotationAngle(BaseBubble* prepare_bubble);
        int getWindmillRotationDirection(const cocos2d::Vec2& contact_vector, const cocos2d::Vec2& angle_vector);
        float getWindmillContactVelocity(BaseBubble* prepare_bubble);
        //关卡类型
        void setStageType(const StageType& type);
        StageType getStageType();
        //是否是风车类型
        bool isWindmillStage();
        //是否是下落类型
        void setFallFlag(bool flag);
        bool isFallStage();
    private:
        //获取一关的关卡信息
        //BubblesData getStageInfoByStageNum(int numble);
    private:
        //获取一个索引的四周索引
        BubbleIndexVector getAroundIndexWithIndex(const cocos2d::Vec2& index);
        BubbleIndexVector getAroundIndexWithIndexWithoutCondition(const cocos2d::Vec2& index);
        //获取一个索引外第二圈的索引
        BubbleIndexVector getSecondAroundIndexWithIndex(const cocos2d::Vec2& index);
        //获取一个索引旁边两圈的缩影
        BubbleIndexVector getTwoAroundIndexWithIndex(const cocos2d::Vec2& index);
        //把单个索引转换成坐标
        cocos2d::Vec2 convertIndexToPoint(const cocos2d::Vec2& index);
        //获取四周与参数类型相同的小球
        BubbleVector getAroundSametypeBubbleWithIndexAndType(const cocos2d::Vec2& index);
        //获取索引四周没有小球的索引的坐标
        BubbleIndexVector getAroundEmptyIndexWithIndex(const cocos2d::Vec2& index);
        //把坐标集转化为小球集合
        BubbleVector getBubbleVectorWithIndexVector(const BubbleIndexVector& index_vector);
        //获取组件的坐标
        BubbleIndexVector getComponentIndexByIndexAndNumble(const cocos2d::Vec2& index, int numble);
        //获取一个坐标下面两个的坐标
        BubbleIndexVector getUnderTwoIndexByIndex(const cocos2d::Vec2& index);
        //转换map到csb的坐标
        cocos2d::Vec2 convertGameSceneCsbToMapSpaceWithBubble(cocos2d::Node* bubble);
        cocos2d::Vec2 convertGameSceneMapToCsbSpaceWithBubble(cocos2d::Node* bubble);
    private:
        //获取最近的位置的坐标
        cocos2d::Vec2 getTheNearestEmptyIndex(const cocos2d::Vec2& point, const cocos2d::Vec2& index);
        //把小球加到地图中去
        void addBubbleToBubbleMap(BaseBubble* bubble);
        //寻找未悬空小球
        BubbleVector getNotInTheAirBubbles();
        //获取悬空的小球
        BubbleVector getInTheAirBubbles();
        //传入种子和function
        void traverseBubbles(BubbleVector* seed, std::function<BubbleVector(const cocos2d::Vec2& index)> func);
        //测试函数  打印所有小球的索引
        //void printAllIndex();
        //计算距离最短的索引
        cocos2d::Vec2 getIndexMindistanceWithVector(const cocos2d::Vec2& point, std::vector<cocos2d::Vec2> index_vector);
        //获取离撞击点最近的一个索引
        cocos2d::Vec2 getIndexNearestContactBubble(const cocos2d::Vec2& prepare_point,
            const cocos2d::Vec2& contact_index);
        //查找两个BubbleVector中不重复的
        BubbleVector getDifferentInTwoBubbleVector(const BubbleVector& first_vector,
            const BubbleVector& second_vector);
        //根据string信息生成泡泡
        BaseBubble* convertBubbleDataToBubble(BubbleColorRender* render, const BubbleInfo& info);
        //关卡类型处理
        void stageTypeFunc(const StageType& stage_type);
    private:
        void setSpecialBubble();
        BaseBubble* getSpecialBubble();
    private:
        BubbleSpriteMap bubble_sprite_map_;
        BubbleVector suspension_points_;
        std::map<StageType, std::function<void()>> stagetype_to_handle_;
        //存储特殊泡泡类似风车啊boss这种
        BaseBubble* special_bubble_;
        StageType stage_type_;
        bool is_fall_type_ = false;
    };
}
#endif //_GAME_BUBBLE_MAP_IMPLEMENTATION_H_