//*******************************************************************************
//类名称   : GameScene
//功能     : <游戏的战斗场景>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "ui\UITextAtlas.h"
namespace bubble_second {
    class BaseProperty;
    class BaseWeapon;
    class BubbleSightingDevice;
    class GameCharacter;
    class ScoreProgressMenu;
    //struct StageData
    //{
    //    int cell_numble = 0;
    //    int level_numble = 0;
    //};
    class GameScene : public cocos2d::Layer
    {
    public:
        static cocos2d::Scene* createScene(int cell_numble, int numble);
        static GameScene* createWithStageNumble(StageData stage_data);
        bool initWithStageNumble(StageData stage_data);
        GameScene();
        ~GameScene();
    public:
        void onEnter() override;
        void onExit() override;
    public:
        //map中的小球坐标转换成cabnode中的坐标
        cocos2d::Vec2 convertMapToCsbSpace(const cocos2d::Vec2& point);
        //把csb的坐标转成map的
        cocos2d::Vec2 convertCsbToMapSpace(const cocos2d::Vec2& point);
        //获取发射台
        cocos2d::Sprite* getGunsight();
        //获取小草
        cocos2d::Sprite* getGrass();
        int getPresentStageNumble();
        void setPresentStageData(StageData numble);
        int getPresentStageCellNumble();
        StageData getPresentStageData();
        //游戏暂停开始
        void gamePause();
        void gameResume();
    private:
        //初始化地图数据,参数是关卡
        void initBubbleMap(int stage_numble);
        //初始化控件层级
        void initUIZOrder();
        //初始化水桶
        void initBarrels();
        //对控件进行屏幕适配调整
        void initChildren();
        //初始化开场的得分挂件
        void initScoreWidget();
        //获取顶部信息node
        //cocos2d::Node* getTopInfoUI();
        //添加角色
        void initCharacter();
        //添加表驱动
        void initHandle();
        //初始化桶上面分数标签的
        void initBarrelScoreLabel();
        //添加换球的监听
        //void addExchangeBubbleListener();
        //移除换球的监听
        //void removeExchangeBubbleListener();
        //加载特效文件
        void addArmatureFile();
        void removeArmatureFile();
        //加入瞄准器
        void addBubbleSightingDevice();
        //清理控制和管理类
        void clearController();
        //胜利之后喷射剩余的球
        void shootBubblesAfterVictory();
        //重玩本关
        void replayGame();
        //处理进场前使用的道具
        void usedEnterProps();
        //添加键盘事件
        void addKeyboardEventListener();
    private:
        //获取分数子控件
        cocos2d::Node* getScoreUI();
        //获取最下位置的小球的y坐标
        float getBubbleMinPositionY();
        //计算地图面板调整的位置
        float getAdjustMapDistance(float map_min_pos);
        //获取发射台的位置
        cocos2d::Vec2 getGunsightPosition();
        //获取小球地图向下调整的距离
        float getAdjustMapDownwardDistance(float distance);
        //获取小球地图向上调整的距离
        float getAdjustMapUpwardDistance(float distance);
        //获取地图面板原始位置
        cocos2d::Vec2 getBubbleMapOrigin();
        //获取发射小球
        BaseBubble* getPrepareBubble();
        //获取第二备用小球
        BaseBubble* getSecondPrepareBubble();
        //添加准备发射小球
        void addPrepareBubble();
        //获取得分挂件的位置
        //cocos2d::Vec2 getScoreWidgetPosition();
        //获取第二发射台位置
        cocos2d::Vec2 getGrassPosition();
        //通过名字获取精灵的位置
        cocos2d::Vec2 getNodePositionWithName(const std::string& child_name);
        //获取瞄准设备
        BubbleSightingDevice* getBubbleSightingDevice();
        //获取已完成任务的label
        cocos2d::ui::TextAtlas* getCompletedTaskLabel();
        //获取胜利任务数
        cocos2d::ui::TextAtlas* getGameTaskLabel();
        //获取小球发射数
        cocos2d::ui::TextAtlas* getBubbleUseCountLabel();
        //获取人物
        GameCharacter* getGameCharacter();
        //获取分数进度条
        ScoreProgressMenu* getScoreProgressMenu();
        //关卡类型
        void setStageType(StageType type);
        StageType getStageType();
    private:
        //添加背景
        void addGameBackground(int cell_numble);
        //添加全部桶盖边缘刚体
        void addBarrelheadsPhysicsBody();
        //添加单个桶盖边缘刚体
        void addBarrelheadPhysicsBodyWithName(const std::string& child_name);
        //添加全部桶底部
        void addBarrelBottoms();
        //添加单个桶底部
        void addBarrelBottomWithName(const std::string& child_name);
        //初始化物理世界
        void addTouchEventListener();
        //void addBubbleWithPoint(BaseBubble* bubble, cocos2d::Vec2 point);
        void addBubblePhysicsBodyToMap(BaseBubble* bubble);
        //加遮罩
        //void addClippingNode();
        //设置控件的层级
        void setUIZOrderWithNameAndNumber(const std::string& child_name, int localZOrder);
        //添加第二发射小球
        BaseBubble* addSecondPrepareBubble();
        //创建准备小球, 没有位置和名字信息的
        BaseBubble* createPrepareBubble();
        //根据名字获取顶部UI的控件
        //cocos2d::Node* getTopUIChildWithName(const std::string& child_name);
        //处理消除后的发射小球的颜色, 让小球颜色跟剩余的小球颜色一致
        void disposedPrepareBubbleType();
        //设置是否可以点击交换小球
        void addExchangeBubbleListener();
        void removeExchangeBubbleListener();
        //发射了道具小球之后事件响应
        void haveShootPropsBubble(BaseProperty* property);
        //设置道具图标是否能点击
        void setPropertyTouchEnabled(bool flag);
        //设置包括菜单都不能点
        void setMenuTouchEnabled(bool flag);
        //发射检测刚体
        void  recentbubbleCast();
        //改变旋风的颜色
        void changeSwirlColor();
        //播放泡泡的动画返回动画的最长时间
        float playBubblesEffects(BubbleVector bubbles);
        //设置武器的位置
        void setPropsWeaponPosition(const cocos2d::Vec2& point);
        //添加一个得分挂件
        void addScoreWidget(const cocos2d::Vec2& point);
        //抖动下面的锅
        void startShakeBarrel();
        void stopShakeBarrel();
        //改变瞄准线颜色
        void changeSightingDeviceColor();
        //更新总的目标任务数
        void updateGameTaskLabel();
        //地图移动完之后的func
        void doSomethingAfterFirstAdjustMap();
        //是否只剩下一个备用小球
        bool isOnlyBubbleUseCount();
        //是否在显示桶上面的分数
        bool isBarrelScoreLabelDisplay();
        void setBarrelScoreLabelDisplay(bool flag);
        //对桶上面的分数进行操作
        void handleBarrelScoreLabel(std::function<void(const std::string& name)> func);
        int getTotalAirBubblesNumble();
        //是否需要显示
        bool isNeedNotDisplayedBarrelScoreLabel();
        //显示桶上面分数label
        void displayBarrelScoreLabel();
        //不显示
        void notDisplayedBarrelScoreLabel();
        //胜利
        void victory();
        //失败
        void defeat();
        void popDefeatBuyAlert();
        void popDefeatAlert();
        void popVictoryAlert();
        void popPauseAlert();
        //获取map最高点
        float getMapMaxPositionY();
        //使用+10数量道具
        void usedAddBubbleNumbleProps();
        //是否是第一次
        bool isFirstHandle();
        void setFirstHandleFlag(bool flag);
        //地图缓慢下落模式
        void mapFallingBegin();
        //获取下落moveby
        cocos2d::MoveBy* getMapFallingAction();
        //移动地图
        void moveMapWithDistance(float moveby_distance);
        //计算移动距离
    private:
        //添加自定义事件监听
        void addEventListenerCustom();
        void removeEventListenerCustom();
        //消除小球
        void eliminateSprites(cocos2d::EventCustom* event);
        //掉落小球
        void spritesDownFromAir(cocos2d::EventCustom* event);
        //小球run撞击特效
        void runBubbleContactEffect(cocos2d::EventCustom* event);
        //添加小球地图
        void addBubbleMapUI(cocos2d::EventCustom* event);
        //添加风车地图
        void addWindmillBorder(cocos2d::EventCustom*);
        void addWindmillBorderFunc(cocos2d::Size size, cocos2d::Vec2 point, int test_bitmask = BITMASK_WINDMILL_BORDER_CONTACTTEST);
        //附着小球
        void clingBubble(cocos2d::EventCustom* event);
        //风车玩法旋转
        void windmillBubbleRotation(cocos2d::EventCustom* event);
        //增加消除连击
        void addEliminateCombo(cocos2d::EventCustom*);
        //没有消除使得挂件飞了
        void removeTwoScoreWidget(cocos2d::EventCustom*);
        //更新分数标签
        void scoreTextUpdate(cocos2d::EventCustom* event);
        //把小球弹药装填到发射台
        void reloadPrepareBubble(cocos2d::EventCustom*);
        //交换准备小球
        void exchangePrepareBubble(cocos2d::EventCustom*);
        //击破云层
        void destroyBubbleDarkCloud(cocos2d::EventCustom* event);
        //调整地图棉面板的位置
        void adjustMapPosition(cocos2d::EventCustom* event);
        //下落的调整地图面板
        void fallAdjustMapPosition(cocos2d::EventCustom* event);
        //使用了彩球道具
        void useBubbleBombProps(cocos2d::EventCustom* event);
        //取消使用彩球或者是炸弹道具
        void cancelUsedBubbleBombProps(cocos2d::EventCustom* event);
        //使用完道具之后回调
        void haveUsedProps(cocos2d::EventCustom* event);
        //添加道具选择面板
        void addPropsSelectAlert(cocos2d::EventCustom* event);
        //移除道具选择面板
        void removePropsSelectAlert(cocos2d::EventCustom*);
        //选中小球
        void selectBubble(cocos2d::EventCustom* event);
        //给屏幕中的小球加触摸事件
        void addListenerForBubblesInVisibleSize(cocos2d::EventCustom* event);
        //删除小球的触摸事件
        void removeListenerForBubblesInVisibleSize();
        //确认使用选择系道具
        void useSelectProperties(cocos2d::EventCustom*);
        //判断检测的小球是否正确
        void recentlyBubbleCast(cocos2d::EventCustom* event);
        //旋转炮台和喵准器
        void rotateSightingDevice(cocos2d::EventCustom* event);
        //播放六连消特效
        void playBigEliminateEffect(cocos2d::EventCustom*);
        //停止6连消的特效
        void stopBigEliminateEffect(cocos2d::EventCustom*);
        //更新已完成的目标label
        void updateCompletedTaskLabel(cocos2d::EventCustom*);
        //更新小球数的label
        void updateBubbleUseCountLabel(cocos2d::EventCustom*);
        //增加1空坠泡泡数量
        void addOneAirBubblesNumble(cocos2d::EventCustom*);
        //减一
        void cutOneAirBubblesNumble(cocos2d::EventCustom*);
        //找到3个普通小球来变成特殊泡泡
        void findThreeBubble(cocos2d::EventCustom* event);
        //增加下落功能
        void addFallBorder(cocos2d::EventCustom*);
        //处理fall模式的东西
        void fallStageHandle();
        void setFallStageFlag(bool flag);
        bool isFallStage();
        //添加消除得分label
        void addEliminateScoreLabel(cocos2d::EventCustom* event);
    private:
        //防止刚体穿透
        //void updateStart(float delta);
        //void update(float delta);
        cocos2d::PhysicsWorld* getScenePhysicsWorld();
        //调整物理世界
        void setPhysicsWorldBody();
        //void addWindmillPhysicsJoints(BaseBubble* bubble);
    private:
        cocos2d::Node* edge_shape_node_;
        cocos2d::Node* csb_node_;
        cocos2d::Node* bubble_map_node_;
        BaseBubble* property_bubble_;
        std::map<std::string, std::function<void(BaseProperty* property)>> props_name_to_handle_;
        std::map<std::string, BubbleType> props_name_to_color_;
        BaseProperty* color_bomb_property_;
        BaseProperty* bomb_bomb_property_;
        BaseProperty* wooden_hammer_property_;
        BaseProperty* staves_property_;
        std::map<BubbleType, std::string> bubblecolor_to_swirl_;
        BaseWeapon* props_weapon_;
        bool first_flag_;
        bool barrel_score_display_flag_;
        GameCharacter* game_character_;
        //int present_stage_numble_ = 0;
        StageData stage_data_;
        int total_air_bubbles_numble_ = 0;
        StageType stage_type_;
        bool is_fall_stage_ = false;
    };
}
#endif //_GAME_SCENE_H_
