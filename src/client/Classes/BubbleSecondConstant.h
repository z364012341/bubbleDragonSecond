//*******************************************************************************
//文件名         : <BubbleSecondConstant.h>
//文件实现功能  : <定义项目用到的常量>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//修改记录 :
//日 期        版本     修改人              修改内容
//2015/09/15   1.0     <黄泽昊>            <新添加>
//*******************************************************************************
#ifndef _BUBBLE_SECOND_CONSTANT_H_
#define _BUBBLE_SECOND_CONSTANT_H_
#include "cocos2d.h"
#define GETINSTANCE_FUNC(__TYPE__) \
    static __TYPE__* getInstance() \
    { \
        static __TYPE__ instance_; \
        return &instance_; \
    } \
    __TYPE__ & operator = (const __TYPE__ &) = delete;
#define SINGLE_BUBBLE_SCORE(_COMBO_)          (5*(_COMBO_)+5)                                  //单个小球的消除得分
#define BUBBLE_ELIMINATE_FORMULA(_NUM_,_COMBO_) ((_NUM_)*SINGLE_BUBBLE_SCORE(_COMBO_))             //消除得分计算公式
#define RANDOM_DECIMALS(_MIN_, _MAX_) (cocos2d::random(_MIN_, _MAX_) + cocos2d::rand_0_1()) //生成一个一位随机小数
#define GAME_STAGE_NODE_CSB_FORMAT "StageNode%d.csb"
//资源路径
const std::string GAME_SCENE = "GameScene";
const std::string GAME_LAYER_CSB = "GameLayer.csb";
const std::string GAME_TOP_INFO_NAME = "TopUINode"; 
const float GAME_TOP_INFO_SCALE = 0.8f; //初始的放大倍率
const float GAME_TOP_INFO_POS_Y_PERCENT = 0.75f; //y的位置百分比
const std::string GAME_TOP_INFO_CSB = "TopUINode.csb";
const std::string GAME_RIGHT_INFO_NAME = "right_UI_node";
const float GAME_RIGHT_STAGE_SPRITE_POS_X = -90.0f; //关卡类型图标位置
const std::string GAME_RIGHT_INFO_CSB = "Node1.csb";
const std::string BUBBLE_NO_COLOR_PATH = ""; //无色             
const std::string BUBBLE_YELLOW_PATH = "paopaohuang.PNG"; //黄
const std::string BUBBLE_PURPLE_PATH = "paopaozi.PNG"; //紫
const std::string BUBBLE_BLUE_PATH = "paopaolan.PNG"; //蓝
const std::string BUBBLE_RED_PATH = "paopaohong.PNG"; //红
const std::string BUBBLE_GREEN_PATH = "paopaolv.PNG"; //绿
const std::string BUBBLE_ORANGE_PATH = "paopaocheng.PNG"; //橙
const std::string BUBBLE_PINK_PATH = "paopaofen.PNG";//粉
const std::string BUBBLE_LIGHTNING_PATH = "paopaoshandian.PNG"; //闪电泡泡
const std::string BUBBLE_DARKCLOUD_PATH = "paopaoyun.PNG";      //阴云泡泡
const std::string BUBBLE_BLACKHOLE_PATH = "paopaoheidong.PNG"; //黑洞泡泡
const std::string BUBBLE_BOMB_BOMB_PATH = "paopaozhadan.PNG"; //炸弹泡泡
const std::string BUBBLE_RAINBOW_SEAL_PATH = "kuangliubianxing.PNG"; //彩虹封印泡泡
const std::string BUBBLE_MUTIPLE_SEAL_1_PATH = "paopaotouming.PNG"; //一重封印泡泡
const std::string BUBBLE_MUTIPLE_SEAL_3_PATH = "paopaotoumingsanjiao.PNG"; //二重封印泡泡
const std::string BUBBLE_MUTIPLE_SEAL_7_PATH = BUBBLE_RAINBOW_SEAL_PATH; //七重封印泡泡
const std::string BUBBLE_WINDMILL_PATH = "windmill_bubble.png"; //风车泡泡
const std::string POP_SCORE_CHARMAP_PATH = "popscore.png";   //弹出分数的艺术数字用的图片
const std::string TOP_UI_BACKGROUND_PATH = "uishang.PNG";   //上边ui的背景
const std::string BOTTOM_UI_BACKGROUND_PATH = "uixia.PNG";    //下边ui的背景
const std::string GAME_PLAYING_MENU_NORMAL_PATH = "anniucaidan.PNG"; //游戏场景左下角的菜单图片资源
const std::string PROPS_ITEM_BACKGROUND_PATH = "kuangdaoju.png";  //道具item的背景
const std::string GUNSIGHT_SWIRL_RED_PATH = "X-hong.png";  //发射台上的旋风红
const std::string GUNSIGHT_SWIRL_PINK_PATH = "X-fen.png";  //发射台上的旋风粉
const std::string GUNSIGHT_SWIRL_PURPLE_PATH = "X-purple.png";  //发射台上的旋风紫
const std::string GUNSIGHT_SWIRL_ORANGE_PATH = "X-cheng.png";  //发射台上的旋风橙
const std::string GUNSIGHT_SWIRL_BLUE_PATH = "X-lan.png";  //发射台上的旋风蓝
const std::string GUNSIGHT_SWIRL_YELLOW_PATH = "X-huang.png";  //发射台上的旋风黄
const std::string GUNSIGHT_SWIRL_GREEN_PATH = "X-lv.png";  //发射台上的旋风绿
const std::string RAINBOW_CHARACTOR_PATH = "be_sealed_charactor.png"; //彩虹封印里面的人物
const std::string ADD_BUBBLE_NUMBLE_BUBBLE_PATH = "addBubbleNumble.png"; //+3特殊泡泡
//得分挂件
const std::string SCORE_WIDGET_BONE_HEAD_NAME = "Layer11"; //骨骼名字
const std::string SCORE_WIDGET_BONE_BODY_NAME = "Layer10";
const std::string SCORE_WIDGET_BONE_BG_NAME = "Layer21";
const std::string SCORE_WIDGET_BONE_EAR1_NAME = "Layer13";
const std::string SCORE_WIDGET_BONE_EAR2_NAME = "Layer12";
const std::string SCORE_WIDGET_RES_PATH = "score_widget_res/"; //资源的相对路径
const std::string SCORE_WIDGET_HEAD_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-tou.png"; //蓝色的头的路径
const std::string SCORE_WIDGET_HEAD_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-tou.png"; 
const std::string SCORE_WIDGET_HEAD_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-tou.png";

const std::string SCORE_WIDGET_BODY_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-shenti.png";
const std::string SCORE_WIDGET_BODY_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-shenti.png";
const std::string SCORE_WIDGET_BODY_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-shenti.png";

const std::string SCORE_WIDGET_BG_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-guang.png";
const std::string SCORE_WIDGET_BG_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-guang.png";
const std::string SCORE_WIDGET_BG_GREEN_PATH = SCORE_WIDGET_RES_PATH + "L-H-guang.png";

const std::string SCORE_WIDGET_EAR1_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-r01.png";
const std::string SCORE_WIDGET_EAR1_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-r01.png";
const std::string SCORE_WIDGET_EAR1_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-r01.png";

const std::string SCORE_WIDGET_EAR2_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-r02.png";
const std::string SCORE_WIDGET_EAR2_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-r02.png";
const std::string SCORE_WIDGET_EAR2_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-r02.png";
//瞄准线点path
const std::string SIGHT_POINT_COLORFUL_PATH = "caisedian.png";  //彩色的
const std::string SIGHT_POINT_ORANGE_PATH = "chengdian.png";
const std::string SIGHT_POINT_PINK_PATH = "fendian.png";
const std::string SIGHT_POINT_RED_PATH = "hongdian.png";
const std::string SIGHT_POINT_YELLOW_PATH = "huangdian.png";
const std::string SIGHT_POINT_BLUE_PATH = "landian.png";
const std::string SIGHT_POINT_GREEN_PATH = "lvdian.png";
const std::string SIGHT_POINT_PURPLE_PATH = "zidian.png";
////角色
const std::string ROLE_GENJYO_SANZO_NAME = "GenJyo_Sanzo";  //玄奘三蔵
//const std::string ROLE_GENJYO_SANZO_PATH = "tangseng.png";  //玄奘三蔵
//const std::string ROLE_CHO_GONO_NAME = "Cho_Gono"; //八戒
//const std::string ROLE_CHO_GONO_PATH = "bajie.png";  //八戒的过去很悲惨……他的恋人很不幸地是在不同的孤儿院里长大的姐姐。原本两人在村子里可以平静地生活，花喃却被百眼魔王抓走了。他为了救花喃，杀光了百眼魔王府上大大小小上上下下全部的妖怪一个不剩。然而，花喃因为已经怀有百眼魔王的骨肉而在他面前自杀了……他由于淋了一千只妖怪的血而自己也变成了妖怪。由于身上有伤且深受刺激，后来倒在路边，是悟净救了他。最后，在逮捕他的三藏帮助下，他的罪被三佛神赦免，改名“八戒”，开始新的生活。
//const std::string ROLE_SON_GOKU_NAME = "Son_Goku";  //孙悟空
//const std::string ROLE_SON_GOKU_PATH = "wukong.png";  //孙悟空
////宠物
//const std::string PET_SHAKURYU_NAME = "Shakuryu";  //白龙
//const std::string PET_SHAKURYU_PATH = "baima.png";  //白龙
//const std::string PET_MONKEY_NAME = "monkey";  //猴子
//const std::string PET_MONKEY_PATH = "xiaohou.png";  //猴子
//道具item
const std::string PROPS_NUMBLE_ENABLED_PATH = "anniutianjia.PNG"; //右上角的按++钮
const std::string PROPS_NUMBLE_DISABLED_PATH = "anniushuliang.PNG";
const float PROPS_BUTTON_POS_X = 95.0f;
const float PROPS_BUTTON_POS_Y = 95.0f;
const float PROPS_BUTTON_SPRITE_SCALE = 0.8f;
const float PROPS_BUTTON_SELECT_SCALE = 1.2f;
const int PROPS_BUTTON_ZORDER = 1;
//道具
const std::string PROPS_COLOR_BOMB_NAME = "props_color_bomb"; //彩球
const std::string PROPS_COLOR_BOMB_PATH = "daojucaiqiu.PNG";
const std::string PROPS_BOMB_BOMB_NAME = "props_bomb_bomb"; //炸弹
const std::string PROPS_BOMB_BOMB_PATH = "daojuzhadan.PNG";
const std::string PROPS_STAVES_NAME = "props_staves"; //法杖
const std::string PROPS_STAVES_PATH = "daojumofabang.PNG";
const std::string WEAPON_STAVES_NAME = "props_staves"; //选择泡泡时候上面的法杖图标
const std::string PROPS_WOODEN_HAMMER_NAME = "props_maces"; //单手锤
const std::string WEAPON_WOODEN_HAMMER_NAME = "props_maces"; //选择泡泡时候上面的单手锤
const std::string PROPS_WOODEN_HAMMER_PATH = "daojumuchui.PNG";
//木锤和法杖的选择面板
const std::string PROPS_SELECT_ALERT_BACKGROUND = "kuangshiyongdaoju.PNG";
const std::string PROPS_SELECT_ALERT_CONFIRM = "anniuqueding.PNG";
const std::string PROPS_SELECT_ALERT_CANCEL = "anniuquxiao.PNG";
const std::string PROPS_SELECT_ALERT_LAYERCOLOR_NAME = "select_alert_name";
const int PROPS_SELECT_ALERT_BACKGROUND_OPACITY = 80;
const cocos2d::Color4B PROPS_SELECT_ALERT_LAYER_COLOR = cocos2d::Color4B(0, 0, 0, PROPS_SELECT_ALERT_BACKGROUND_OPACITY);
const float PROPS_SELECT_ALERT_BUTTON_SELECT_SCALE = 1.1f;
const cocos2d::Vec2 PROPS_SELECT_ALERT_BACKGROUND_POS = cocos2d::Vec2(375.0f, 300.0f);
const float PROPS_SELECT_ALERT_BUTTON_X = 140.0f;
//射线检测
const std::string WOODEN_HAMMER_CAST_NODE_NAME = "bubble_cast";
const float CAST_BODY_DENSITY = 0.0f; //检测刚体的密度
const float RECENT_BUBBLE_CAST_IMPULSE_Y = 3000.0f; //最近小球检测的冲量
//屏幕适配
const float GAME_DESIGN_RESOLUTION_WIDTH = 750.0f;//设计分辨率宽
const float GAME_DESIGN_RESOLUTION_HEIGHT = 1334.0f;//设计分辨率高
const float GAME_ALERT_MASK_WIDTH = GAME_DESIGN_RESOLUTION_WIDTH*2;//alert后面的屏蔽宽
const float GAME_ALERT_MASK_HEIGHT = GAME_DESIGN_RESOLUTION_HEIGHT*2;//高
const float GAME_PLAY_HEIGHT = 1140.0f;//除去上下菜单的高度
const float BOTTOM_UI_BACKGROUND_HEIGHT = 105.0f; //游戏场景下面ui的背景图需要的高度
const float GAME_PROPS_BACKGROUND_PERCENT_Y = 0.0525f;  //道具item背景的y坐标百分比                        
const float PROPS_BACKGROUND_PERCENT_X_FIRST = 0.3158f;//道具item_1背景的X坐标百分比
const float PROPS_BACKGROUND_PERCENT_X_SECOND = 0.5076f; //道具item_1背景的X坐标百分比
const float PROPS_BACKGROUND_PERCENT_X_THIRD = 0.6994f; //道具item_1背景的X坐标百分比
const float PROPS_BACKGROUND_PERCENT_X_FOURTH = 0.8931f; //道具item_1背景的X坐标百分比
const float GAME_SCORE_PERCENT_X = 0.1747f; //得分的label的x坐标百分比
const float GAME_RIGHT_LABEL_PERCENT_X = 0.8636f; //右边的胜利条件的label的x坐标百分比
//常量参数
const cocos2d::Vec2 RECENT_BUBBLE_CAST_SHAPE[] = { cocos2d::Vec2(0.0f, 100.0f),
cocos2d::Vec2(GAME_DESIGN_RESOLUTION_WIDTH / 2, 0.0f), cocos2d::Vec2(GAME_DESIGN_RESOLUTION_WIDTH / -2, 0.0f) };
const float BUBBLE_IMPULSE = 900000.0f; //发射的冲量
const int BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_X = 30000; //胜利后发射小球的冲量随机值
const int BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MIN = 80000;
const int BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MAX = 100000;
const float GAME_MENU_SELECT_SCALE = 0.8f;    //菜单点击时的放大比例
const float PI = 3.14f; //圆周率
const float SQRT3 = 1.732f;//根号3
const int MAP_MAX_ROW_IN_SCREEN = 10; //屏幕内的小球的行数
const int DISTANCE_LINE_NUMBER = 6;   //发射台与面板间隔的小球行数
const int FALL_DISTANCE_LINE_OFFSET_NUMBER = 5;   //掉落模式的行数偏移
const int MAP_TOP_ROW_INDEX = -1;      //地图最上面的那行泡泡的索引
const int MAP_EVEN_ROW_MAX = 11;  //地图偶数行最大小球个数
const int MAP_ODD_ROW_MAX = 10;   //地图奇数行最大小球个数
//const int MAP_TOP_ROW_INDEX = -1;     //边界小球的索引行
const float MAP_BUBBLE_RADIUS = 34.0f;     //地图的小球间隔半径, 是贴图的半径, 碰撞刚体半径在下面
const float MAP_BUBBLE_DIAMETER = MAP_BUBBLE_RADIUS * 2;  //直径
const float SIGHTING_POINT_RADIUS = 9.0f; //瞄准线点的半径
const float SIGHTING_POINT_REFLECTION_OFFSET = 3.0f; //瞄准线反射点位置偏移
const float SIGHTING_POINT_REFLECTION_WIDTH = /*700.0f;*/GAME_DESIGN_RESOLUTION_WIDTH - MAP_BUBBLE_DIAMETER;
const float BUBBLE_RADIUS = 22.0f;      //小球刚体半径
const int CAST_BODY_RADIUS = MAP_BUBBLE_RADIUS * 5;
const float MIN_MAP_DISTANCE = (MAP_BUBBLE_RADIUS * SQRT3 * DISTANCE_LINE_NUMBER);//发射台与面板间隔的距离

const float FALL_MIN_MAP_OFFSET_DISTANCE = (MAP_BUBBLE_RADIUS * SQRT3 * FALL_DISTANCE_LINE_OFFSET_NUMBER);//掉落模式的距离偏移
const float MAP_MOVE_SPEED = 500.0f;  //地图面板移动速度
//const float BUBBLE_DOWN_DELAY_TIME = 0.03f;  //小球掉落延迟
const float BUBBLE_ELIMINATE_DELAY_TIME = 0.03f;  //小球消除的延迟
const float BUBBLE_ELIMINATE_SCALETO = 1.5f;  //小球消除的放大
const cocos2d::Vec2 PHYSICS_WORLD_GRAVITY_VEC2 = cocos2d::Vec2(0, -750);  //物理世界重力
//const cocos2d::Vec2 BUBBLE_DOWN_FROM_AIR_IMPULSE_VEC2 = cocos2d::Vec2(30000, 0); //泡泡下落时候添加的冲量
const int BUBBLE_DOWN_FROM_AIR_TORQUE = 1000000.0f; //力矩
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MAX_X = 20000; //泡泡下落时候添加的最大冲量
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MIN_X = 10000; //泡泡下落时候添加的最小冲量
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MAX_Y = -5000; //泡泡下落时候添加的最大冲量
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MIN_Y = -10000; //泡泡下落时候添加的最小冲量
const float BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY = 5.0f;   //角速度
const int LONG_CONTACT_EFFECT_DISTANCE = 15;   //大幅度的撞击小球动作的距离
const int SHORT_CONTACT_EFFECT_DISTANCE = 5;    //小幅度的撞击小球动作的距离
const float BUBBLE_CONTACT_TIME = 0.1f;   //大幅度的撞击小球动作的动作时间, 大小幅度同一时间
const float TWO_SCORE_WIDGET_DISTANCE = 100.0f; //两个得分挂件的最小距离
const float SCORE_WIDGET_POSITION_OFFS = 20.0f;  //得分挂件的位置偏移
const int SCORE_WIDGET_MAX_COMBO = 12;     //得分挂件的最大连击数
const int SCORE_WIDGET_BLUE_SCORE = 25;     //蓝色挂件一次得分
const int SCORE_WIDGET_YELLOW_SCORE = 50;     //黄色挂件一次得分
const int SCORE_WIDGET_GREEN_SCORE = 100;     //绿色挂件一次得分
const float SCORE_WIDGET_COMBO_DELAY = 1.0f;  //得分挂件时间内连击
const int SCORE_WIDGET_NOT_COMBO_NUMBLE = 2;      //挂件不连击时移除的数量
const int BARREL_BOTTOM_SCORE_FIRST = 100;     //左起第1个桶底的得分
const int BARREL_BOTTOM_SCORE_SECOND = 500;    //左起第2个桶底的得分
const int BARREL_BOTTOM_SCORE_THIRD = 1000;   //左起第3个桶底的得分
const int BARREL_BOTTOM_SCORE_FOURTH = 500;   //左起第4个桶底的得分
const int BARREL_BOTTOM_SCORE_FIFTH = 100;    //左起第5个桶底的得分
const float ADD_PHYSICASBODY_DELAYTIME = 0.02f; //添加刚体的延迟时间
const float PREPARE_RELOAD_MOVE_TIME = 0.2f;  //小球装填时移动的时间
const float AFTER_VECTORY_PREPARE_RELOAD_MOVE_TIME = 0.1f;  //胜利后喷射小球装填时移动的时间
const float AFTER_VECTORY_PREPARE_REPEAT_DELAY_TIME = AFTER_VECTORY_PREPARE_RELOAD_MOVE_TIME+0.05f;  //胜利后喷射小球间隔时间
const float POP_SCORE_INITIAL_SCALE = 0.1f;  //弹出分数的初始缩放
const float POP_SCORE_SCALETO_1_TIME = 0.3f;  //第一次缩放的时间
const float POP_SCORE_SCALETO_1_NUMBLE = 1.0f;  //第一次缩放的比例
const float POP_SCORE_SCALETO_2_TIME = 0.1f;
const float POP_SCORE_SCALETO_2_NUMBLE = 0.8f;
const float POP_SCORE_SCALETO_3_TIME = 0.2f;
const float POP_SCORE_SCALETO_3_NUMBLE = 1.2f;
const float POP_SCORE_SCALETO_4_TIME = 0.2f;
const float POP_SCORE_SCALETO_4_NUMBLE = 0.8f;
const float POP_SCORE_SCALETO_5_TIME = 0.2f;
const float POP_SCORE_SCALETO_5_NUMBLE = 1.2f;
const cocos2d::Vec2 POP_SCORE_ANCHORPOINT = cocos2d::Vec2(0.5f, 0.5f);
const float POP_SCORE_MOVEBY_TIME = POP_SCORE_SCALETO_1_TIME + POP_SCORE_SCALETO_2_TIME + POP_SCORE_SCALETO_3_TIME
    + POP_SCORE_SCALETO_4_TIME + POP_SCORE_SCALETO_5_TIME;      //移动的时间
const cocos2d::Vec2 POP_SCORE_MOVEBY_VEC2 = cocos2d::Vec2(0.0f, 20.0f); //移动的距离
const float POP_SCORE_DELAYTIME = 0.3f;                     //最后的延迟
const float SCOREWIDGET_FLY_OUT_TIME = 1.0f;   //挂件飞走时候移动的时间
const int POP_SCORE_CHARMAP_ITEMWIDTH = 28;   //弹出的分数艺术数字的item宽
const int POP_SCORE_CHARMAP_ITEMHEIGHT = 38;    //弹出的分数艺术数字的item宽
const float POP_SCOREWIDGET_SCORE_SCALETO_1_TIME = 0.05f;  //撞到得分挂件弹出分数第一次缩放的时间
const float POP_SCOREWIDGET_SCORE_SCALETO_1_NUMBLE = 0.7f;     //第一次缩放的比例
const float POP_SCOREWIDGET_SCORE_SCALETO_2_TIME = 0.1f;
const float POP_SCOREWIDGET_SCORE_SCALETO_2_NUMBLE = 1.3f;
const float POP_SCOREWIDGET_SCORE_SCALETO_3_TIME = 0.05f;
const float POP_SCOREWIDGET_SCORE_SCALETO_3_NUMBLE = 1.0f;
const float POP_SCOREWIDGET_SCORE_MOVE_TIME = 2.0f;    //挂件飞出屏幕的时间
const cocos2d::Vec2 POP_SCOREWIDGET_SCORE_MOVE_VEC2 = cocos2d::Vec2(0.0f, 40.0f);  //挂件弹出分数移动的距离
const int SHOOT_BUBBLE_ENABLED_DEGREE = 20;     //点击发射小球所允许的发射角度
const float GUNSIGHT_EXCHANGE_DISTANCE = 80.0f;  //喵准器的区域半径
const float GRASS_EXCHANGE_DISTANCE = 50.0f;  //小草的区域半径
const int BLACKHOLE_BUBBLE_SWALLOW_DIRECTION = 1;
const int BLACKHOLE_BUBBLE_SWALLOW_DEGREE = 360* BLACKHOLE_BUBBLE_SWALLOW_DIRECTION; //吸入黑洞小球的旋转角度
const float BLACKHOLE_BUBBLE_SWALLOW_TIME = 1.5f; //吸入黑洞小球的旋转时间
const int BLACKHOLE_BUBBLE_SWALLOW_NUMBLE_MAX = 3; //黑洞小球吸收最大次数
const float BLACKHOLE_BUBBLE_SCALETO_TIME = 0.4f; //黑洞小球放大动作时间
const float BLACKHOLE_BUBBLE_SCALETO_PER = 1.2f; //黑洞小球缩放的幅度
const int INITIAL_SCORE_WIDGET_NUMBLE = 2; //进场时的蜘蛛数量
const float INITIAL_SCORE_WIDGET_POS_Y = 200.0f; //进场的y高度
const float UI_SWIRL_ROTATIEBY_TIME = 2; //旋风旋转的时间
const float UI_SWIRL_ROTATIEBY_DEGREE = 360; //旋风一次action的角度
//const int UI_SWIRL_OPACITY = 100; //旋风的透明度
const int BIG_COMBO_ELIMINATE_NUMBLE = 6; //出现爆发的连笑次数
const float BUBBLS_ADJUST_MAP_DELAYETIME = 1.3f; //移动面板的最少延长时间
const int BUBBLE_REABOW_SEAL_COMPONENT_NUMBLE = 6; //彩虹封印泡的组件数量
const int BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1 = 0;
const int BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3 = 2;
const int BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7 = 6;
const cocos2d::Vec2 BUBBLE_MUTIPLE_SEAL_3_ANCHORPOINT(0.5, 0.75); //三重封印贴图的锚点
const cocos2d::Vec2 BUBBLE_IN_RAINBOW_BUBBLE_POS(-50, 20); //彩虹封印里面小球的位置
const float BUBBLE_IN_RAINBOW_BUBBLE_SCALE = 0.7f; //封印里面小球的缩放
const float SCORE_WIDGET_BEZIER_FLYING_DURATION = 1.0f; //得分挂件的赛贝尔运动时间
const float BARREL_SCORE_LABEL_OFFS_Y = 100.0f;//酒桶分数的y偏移
const float BARREL_SCORE_LABEL_MOVEBY_OFFS_Y = 5.0f;
const int BARREL_SCORE_LABEL_ACTION_TAG = 101; //动作的tag人直
const float BARREL_SCORE_LABEL_MOVEBY_Y = BARREL_SCORE_LABEL_OFFS_Y + BARREL_SCORE_LABEL_MOVEBY_OFFS_Y; //酒桶分数的移动时候的y偏移
const float BARREL_SCORE_LABEL_MOVEBY_1_DURATION = 1.0f;
const float BARREL_SCORE_LABEL_MOVEBY_2_DURATION = 0.1f;
const float BARREL_SCORE_LABEL_DELAYTIME_DURATION = 0.3f;
const int WINDMILL_BUBBLE_TAG = 243; //风车小球的tag
const int TOP_ELIMINATE_GAME_TASK_NUMBLE = 6; //顶部消除玩法的目标数量
const float WINDMILL_BUBBLE_ROTATION_FACTOR = 30.0f; //风车转转转的速度系数
const float WINDMILL_ROTATION_ACTIONS_DURATION = 1.0f; //动作的时间
const int WINDMILL_ROTATION_CARDINAL_SPLINE_POINT_NUMBLE = 51; //曲线轨迹用51个点
const float WINDMILL_ROTATION_EASE_RATE = 2.0f; //EASE动作的系数
const int WINDMILL_ROTATION_ACTION_TAG = 234;
const float WINDMILL_ROTATION_SPEED_SPEED = 2.0f;
const int COLOR_BUBBLE_TAG = 235; //彩色小球的tag
const float AFTER_VICTORY_SHOOT_BUBBLE_DELAYTIME = 0.7f;
const float TEXTURE_SCALE = 0.4f;//精致贴图的缩放
const std::string GAME_SCENE_SHOOT_BUBBLES_AFTER_VICTORY_SCHEDULE_KEY = "GAME_SCENE_SHOOT_BUBBLES_AFTER_VICTORY_SCHEDULE_KEY";
//关卡xml解析
const char BUBBLE_COLOR_IN_RANGE = '1';
const std::string STAGE_XML_FIELDS_FIRST_ELEMENT = "bubbles";
const std::string STAGE_XML_FIELDS_SECOND_ELEMENT = "data";
const std::string STAGE_XML_FIELDS_BUBBLETYPE = "type";
const std::string STAGE_XML_FIELDS_ROW = "row";
const std::string STAGE_XML_FIELDS_COL = "col";
const std::string STAGE_XML_FIELDS_CLOUD = "cloud";
const std::string STAGE_XML_FIELDS_PATH = "path";
const std::string STAGE_XML_FIELDS_BUBBLENUM = "bubbleNum";
const std::string STAGE_XML_FIELDS_STAGETYPE = "type";
const std::string STAGE_XML_FIELDS_START1 = "start1";
const std::string STAGE_XML_FIELDS_START2 = "start2";
const std::string STAGE_XML_FIELDS_START3 = "start3";
const std::string STAGE_XML_FIELDS_COLORS = "colors";
//特效
const std::string LIGHTNING_BUBBLE_EFFECT_PATH = "SD-TX/SD-TX.ExportJson"; //闪电特效的路径
const std::string LIGHTNING_BUBBLE_EFFECT_NAME = "SD-TX"; //闪电特效的名字
const std::string BALL_LIGHTNING_BUBBLE_EFFECT_PATH = "SDQ-TX/SDQ-TX.ExportJson"; //闪电球特效的路径
const std::string BALL_LIGHTNING_BUBBLE_EFFECT_NAME = "SDQ-TX"; //闪电球特效的名字
const float LIGHTNING_BUBBLE_EFFECT_WHITE_EFFECT_TIME = 0.1f;   //白色背景时间
const int LIGHTNING_BUBBLE_EFFECT_BLACK_EFFECT_OPACITY = 200;
const int SPECIAL_BUBBLE_EFFECT_DURATION = -1; //播放特效的durationTo参数
const float LIGHTNING_BUBBLE_EFFECT_DELAY_TIME = 0.5f;   //用作返回的参数
const std::string ONE_ROUND_BOMB_EFFECT_PATH = "zhadan-TX/zhadan-TX.ExportJson"; //炸一圈特效的路径
const std::string ONE_ROUND_BOMB_EFFECT_NAME = "zhadan-TX"; //炸一圈特效的名字
const float ONE_ROUND_BOMB_EFFECT_DELAY_TIME = 0.1f;   //用作返回的参数
const std::string TWO_ROUND_BOMB_EFFECT_PATH = "zhadan02-TX/zhadan02-TX.ExportJson"; //炸2圈特效的路径
const std::string TWO_ROUND_BOMB_EFFECT_NAME = "zhadan02-TX"; //炸2圈特效的名字
const float TWO_ROUND_BOMB_EFFECT_RIPPLE2D_DURATION = 0.8f; //时间
const float TWO_ROUND_BOMB_EFFECT_RIPPLE2D_RADIUS = 120.0f; //半径
const int TWO_ROUND_BOMB_EFFECT_RIPPLE2D_WAVES = 1; //波浪数
const float TWO_ROUND_BOMB_EFFECT_RIPPLE2D_AMPLITUDE = 100.0f; //幅度
const cocos2d::Size ACTION_3DGRID(64, 48);
const float TWO_ROUND_BOMB_EFFECT_DELAY_TIME = LIGHTNING_BUBBLE_EFFECT_DELAY_TIME;   //用作返回的参数
const std::string BLACK_HOLE_BUBBLE_EFFECT_PATH = "HD-XT/HD-XT.ExportJson"; //黑洞特效的路径
const std::string BLACK_HOLE_BUBBLE_EFFECT_NAME = "HD-XT"; //黑洞特效的名字
//const GLubyte BLACK_HOLE_SWALLOW_OPACITY_CUT = 50;
const GLubyte TEXTURE_OPACITY = 255;
const std::string BARREL_BOTTOM_EFFECT_PATH = "diaoluo-TX/diaoluo-TX.ExportJson"; //小球掉到桶消除特效的路径
const std::string BARREL_BOTTOM_EFFECT_NAME = "diaoluo-TX"; //小球掉到桶消除特效的名字
//const float BARREL_BOTTOM_EFFECT_POSITION_Y = 0.0f;
const std::string COLOR_BUBBLE_ELIMINATE_EFFECT_PATH = "PPX-TX/PPX-TX.ExportJson"; //普通小球消除特效的路径
const std::string COLOR_BUBBLE_ELIMINATE_EFFECT_NAME = "PPX-TX"; //普通小球消除特效的路径
const std::string BARREL_BOTTOM_STANDBY_EFFECT_PATH = "PPP-TX/PPP-TX.ExportJson"; //桶底冒泡特效的路径
const std::string BARREL_BOTTOM_STANDBY_EFFECT_NAME = "PPP-TX"; //桶底冒泡特效的名字
const int BARREL_BOTTOM_STANDBY_EFFECT_SPEED_SCALE = 1.7f; //超大特效的时候动画的速度改变
const float BARREL_BOTTOM_STANDBY_EFFECT_POS_Y = 90.0f; //位置
const int BARREL_BOTTOM_STANDBY_EFFECT_DELAYTIME_MAX = 10;
const int BARREL_BOTTOM_STANDBY_BIG_EFFECT_DELAYTIME_MAX = 1; //超大特效的时候动画的两个动画的最大间隔
const std::string BIG_COMBO_EFFECT_FIRE_ONCE_PATH = "6L-TX01/6L-TX01.ExportJson"; //大连消后面一次的火特效
const std::string BIG_COMBO_EFFECT_FIRE_ONCE_NAME = "6L-TX01";
const cocos2d::Vec2 BIG_COMBO_EFFECT_FIRE_ONCE_POSITION(300, 50); //位置
const float BIG_COMBO_EFFECT_FIRE_ONCE_SPEED = 0.5f; //动画播放速度
const std::string BIG_COMBO_EFFECT_FIRE_REPEAT_PATH = "6L-tx/6L-tx.ExportJson"; //大连消后面连续的火特效
const std::string BIG_COMBO_EFFECT_FIRE_REPEAT_NAME = "6L-tx";
const cocos2d::Vec2 BIG_COMBO_EFFECT_FIRE_REPEAT_POSITION(375, 50); //位置
const std::string BIG_COMBO_EFFECT_POINT_PATH = "dahuo-09.png"; //大连消后面连续的火特效
const std::string BIG_COMBO_EFFECT_POINT_NAME = "big_combo_effect_point"; //大连消后面连续的火特效
const float BIG_COMBO_EFFECT_POINT_TIEM = 0.5f; //小点点特效的时间
const float BIG_COMBO_EFFECT_POINT_DELAYTIEM = 0.01f; //小点点特效的时间
const float BIG_COMBO_EFFECT_POINT_SCALETO = 0.3f; //小点点特效的时间
const float BIG_COMBO_EFFECT_POINT_MOVEBY_Y = 300.0f; //小点点特效的时间
const float BIG_COMBO_EFFECT_POINT_POS_X_MIN = 0.0f;  //随机的位置范围
const float BIG_COMBO_EFFECT_POINT_POS_X_MAX = 750.0f; //随机的位置范围
const float BIG_COMBO_EFFECT_POINT_POS_Y_MIN = -50.0f; //随机的位置范围
const float BIG_COMBO_EFFECT_POINT_POS_Y_MAX = 50.0f;  //随机的位置范围
const std::string BIG_COMBO_EFFECT_UNDER_FIRE_PATH = "DX-TX/DX-TX.ExportJson"; //大连消后面一次的火特效
const std::string BIG_COMBO_EFFECT_UNDER_FIRE_NAME = "DX-TX";
const cocos2d::Vec2 BIG_COMBO_EFFECT_UNDER_FIRE_POSITION(375, 50); //位置
const float BARREL_SHAKE_MOVEBY_DISTANCE_X = 0.5f; //下面的抖动幅度
const float BARREL_SHAKE_MOVEBY_DISTANCE_Y = 1.5f; //下面的抖动幅度
const float BARREL_SHAKE_MOVEBY_DISTANCE_TIME = 0.05f; //下面的抖动单次位移时间
const float BIG_BACKGROUND_EFFECT_TIME = 2.0f; //蓝色背景的大特效的时间
const cocos2d::Color4B BIG_BACKGROUND_EFFECT_BLACK_COLOR(0, 0, 0, 200); //一开始的黑色层的颜色
const cocos2d::Color4B BIG_BACKGROUND_EFFECT_BLUE_COLOR(40, 143, 212, 255); //蓝色层的颜色
const cocos2d::Color4B BIG_BACKGROUND_EFFECT_SMALL_BLUE_COLOR(107, 240, 255, 178); //蓝色小条的颜色
const int BIG_BACKGROUND_EFFECT_BLACK_ZORDER = 1;//黑色层的zorder
const int BIG_BACKGROUND_EFFECT_BLACK_FADE_TAG = 101;//黑色层的fade的特效的tag
const float BIG_BACKGROUND_EFFECT_BLACK_TO_WHITE_TIME = 0.3f;//黑白效果的时间
const float BIG_BACKGROUND_EFFECT_LEFT_TO_RIGHT_MOVE_X = -500.0f;//小蓝条移动的x距离
const float BIG_BACKGROUND_EFFECT_RIGHT_TO_LEFT_MOVE_X = 500.0f;
const float BIG_BACKGROUND_EFFECT_LEFT_TO_RIGHT_POSX = -40.0f;//小蓝条x初始位置
const float BIG_BACKGROUND_EFFECT_RIGHT_TO_LEFT_POSX = 30.0f;
const int BIG_BACKGROUND_EFFECT_SMALL_BLUE_MIN_WIDTH = 10; //小蓝条最小宽度
const int BIG_BACKGROUND_EFFECT_SMALL_BLUE_MAX_WIDTH = 100; //小蓝条最大宽度
const std::string RAINBOW_CHARACTOR_BG_PATH = "rainbow_charactor_bg.png";
const std::string RAINBOW_CHARACTOR_SWIRL_PATH = "rainbow_charactor_swirl.png";
const std::string BIG_BLUE_BACKGROUND_EFFECT_POINT_PATH = "Q-01.png"; //蓝背景特效上的椭圆点
const std::string RAINBOW_CHARACTOR_ARMATURE_PATH = "WuChang/WuChang.ExportJson"; //彩虹封印的人物
const std::string RAINBOW_CHARACTOR_ARMATURE_NAME = "WuChang";
const float RAINBOW_CHARACTOR_ARMATURE_POS_X = -20;
const float RAINBOW_CHARACTOR_ARMATURE_ENTER_FROM_LEFT_POS_X = -150.0f;
const cocos2d::Vec2 RAINBOW_CHARACTOR_ARMATURE_ENTER_FROM_LEFT_POS(-150.0f, GAME_DESIGN_RESOLUTION_HEIGHT);
const cocos2d::Vec2 RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_CONTROLLPOINT_2_OFFS(-300.0f, 0.0f);
const float RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_DURATION = 2.0f; //第一次进场的时候的时间
const float RAINBOW_CHARACTOR_ARMATURE_MOVE_DURATION = 1.3f; //封印转移时候的时间
const std::string RAINBOW_CHARACTOR_ANIMATIOIN_STANDBY_NAME = "daiji";
const std::string RAINBOW_CHARACTOR_ANIMATIOIN_FLYING_NAME = "feixing";
const std::string RAINBOW_BUBBLE_ARMATURE_PATH = "RainbowAnimation/RainbowAnimation.ExportJson"; //彩虹封印球的动画
const std::string RAINBOW_BUBBLE_ARMATURE_NAME = "RainbowAnimation";
const std::string RAINBOW_BUBBLE_ARMATURE_STANDBY_NAME = "gaoguang";
const std::string RAINBOW_BUBBLE_ARMATURE_BOMB_NAME = "baozha";
const std::string MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH = "qingwa/qingwa.ExportJson"; //多重封印球的动画
const std::string MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_NAME = "qingwa";
const std::string MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_STANDBY_NAME = "zhayan";
const std::string MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_ELIMINATE_NAME = "tiaochu";
const std::string MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH = "DaGou/DaGou.ExportJson"; //多重封印球的动画
const std::string MUTIPLE_SEAL_BUBBLE_ARMATURE_DOG_NAME = "DaGou";
const std::string SCOREWIDGET_ARMATURE_BLUE_PATH = "L-H-TX/L-H-TX.ExportJson"; //得分挂件的动画
const std::string SCOREWIDGET_ARMATURE_BLUE_NAME = "L-H-TX";
const std::string SCOREWIDGET_ANIMATION_FLYING_NAME = "tanchu"; //飞的动画
const std::string SCOREWIDGET_ANIMATION_CONTACT_NAME = "tanchu_Copy1"; //碰到的动画
const std::string GAME_CHARACTER_ARMATURE_PATH = "T-TX/T-TX.ExportJson"; //人物的动画
const std::string GAME_CHARACTER_ARMATURE_NAME = "T-TX";
const std::string GAME_CHARACTER_ANIMATION_STANDBY_NAME = "daiji";
const std::string GAME_CHARACTER_ANIMATION_SHOOT_BUBBLE_NAME = "faqiu";
const std::string GAME_CHARACTER_ANIMATION_LEGENDARY_NAME = "liulianji";
const std::string GAME_CHARACTER_ANIMATION_VICTORY_NAME = "shengli";
const std::string GAME_CHARACTER_ANIMATION_DEFEAT_NAME = "shibai";
const std::string WINDMILL_BUBBLE_DEMON_ARMATURE_PATH = "xiaoyao/xiaoyao.ExportJson"; //风车妖精的动画
const std::string WINDMILL_BUBBLE_DEMON_ARMATURE_NAME = "xiaoyao";
//小球刚体
const int BUBBLE_BODY_MASS = 100;    //小球质量
const float BUBBLE_BODY_DENSITY = 0.5f;  //小球密度
const float BUBBLE_STATIC_BODY_RESTITUTION = 1.0f;  //小球反弹力
const float BUBBLE_DYNAMIC_BODY_RESTITUTION = 0.7f;  //小球反弹力
const float BUBBLE_BODY_FRICTION = 300.0f;  //小球摩擦力
const int BUBBLE_BODY_GROUP = -1;
//世界边界刚体
const float PHYSICS_WORLD_BODY_DENSITY = 0.0f; //世界边界密度
const float PHYSICS_WORLD_BODY_RESTITUTION = 1.0f; //世界边界反弹力
const float PHYSICS_WORLD_FRICTION = 0.0f; //世界边界摩擦力
const float PTM_RATIO = 32.0f; //物理世界像素和厘米换算
const float PHYSICS_WORLD_BODY_BORDER = 3;   //世界边界的宽度
//const int PHYSICS_WORLD_BODY_TAG = 233;   //世界边界的宽度
//风车边界缸体
const float PHYSICS_WINDMILL_BORDER_BODY_WIDTH = PHYSICS_WORLD_BODY_BORDER;
const float PHYSICS_WINDMILL_BORDER_BODY_HEIGHT = GAME_DESIGN_RESOLUTION_HEIGHT;
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_LEFT_SIZE(PHYSICS_WINDMILL_BORDER_BODY_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_HEIGHT);
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_RIGHT_SIZE(PHYSICS_WINDMILL_BORDER_BODY_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_HEIGHT);
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_TOP_SIZE(GAME_DESIGN_RESOLUTION_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_WIDTH);
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE(GAME_DESIGN_RESOLUTION_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_WIDTH);

const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_LEFT_POSITION(0.0f, 710.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_RIGHT_POSITION(GAME_DESIGN_RESOLUTION_WIDTH, 720.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_TOP_POSITION(GAME_DESIGN_RESOLUTION_WIDTH / 2, 1165.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_POSITION(GAME_DESIGN_RESOLUTION_WIDTH / 2, 290.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_BOTTOM2_POSITION(GAME_DESIGN_RESOLUTION_WIDTH / 2, 220.0f);
//桶边刚体
const float PHYSICS_BARRELHEADEDGE_BODY_DENSITY = 0.0f;   //桶边刚体密度
const float PHYSICS_BARRELHEADEDGE_BODY_RESTITUTION = 1.2f; //桶边刚体反弹力
const float PHYSICS_BARRELHEADEDGE_BODY_FRICTION = 0.0f; //桶边刚体摩擦力
const int BARRELHEADEDGE_BODY_RADIUS = 10;  //桶边刚体半径
//桶底部刚体
const cocos2d::Size PHYSICS_BARREL_BOTTOM_BODY_SIZE = cocos2d::Size(120, 5);
const int PHYSICS_BARREL_BOTTOM_BORDER = 2;
const float PHYSICS_BARREL_BOTTOM_BODY_DENSITY = 0.0f; //桶边刚体密度
const float PHYSICS_BARREL_BOTTOM_BODY_RESTITUTION = 0.0f;   //桶边刚体反弹力
const float PHYSICS_BARREL_BOTTOM_BODY_FRICTION = 50000.0f; //桶边刚体摩擦力
//得分挂件刚体
const float PHYSICS_SCORE_WIDGET_BODY_DENSITY = 0.0f;  //得分挂件刚体密度
const float PHYSICS_SCORE_WIDGET_BODY_RESTITUTION = 1.2f;   //得分挂件刚体反弹力
const float PHYSICS_SCORE_WIDGET_BODY_FRICTION = 10.0f;   //得分挂件刚体摩擦力
const int SCORE_WIDGET_BODY_RADIUS = 15;  //得分挂件刚体半径
//瞄准点刚体
const float PHYSICS_SIGHTING_POINT_BODY_DENSITY = 0.0f;  //刚体密度
const float PHYSICS_SIGHTING_POINT_BODY_RESTITUTION = 1.0f;   //刚体反弹力
const float PHYSICS_SIGHTING_POINT_BODY_FRICTION = 0.0f;   //刚体摩擦力
const float SIGHTING_POINT_BODY_RADIUS = BUBBLE_RADIUS+25;  //刚体半径
//const float SIGHTING_POINT_BODY_RADIUS = MAP_BUBBLE_DIAMETER;  //刚体半径
//自定义事件的名字
const std::string EVENT_MAP_LOADED = "map_loaded";       //加载完小球地图
const std::string EVENT_WINDMILL_MAP_BORDER_LOADED = "event_windmill_map_border_loaded";       //加载风车地图边界
const std::string EVENT_FALL_MAP_BORDER_LOADED = "EVENT_FALL_MAP_BORDER_LOADED";       //加载下落地图边界
const std::string EVENT_INITIAL_START_NUMBLES = "event_initial_start_numbles"; //初始化星星的分数
const std::string EVENT_BUBBLE_ELIMINATED = "bubble_shoule_eliminated"; //需要消除小球
const std::string EVENT_BUBBLE_CLING = "bubble_should_cling";  //附着小球
const std::string EVENT_WINDMILL_ROTATION = "windmill_rotation";  //风车转
const std::string EVENT_CAN_USED_PROPS = "EVENT_CAN_USED_PROPS"; //可以使用道具啦
const std::string EVENT_BUBBLE_Air = "bubble_is_in_the_air";  //这些小球要掉下来
const std::string EVENT_BUBBLE_RUN_EFFECT = "bubble_run_effect";  //小球跑撞击特效
//const std::string EVENT_SCORE_ADD = "score_add";  //增加得分
const std::string EVENT_SCORE_TEXT_UPDATE = "score_text_update";   //分数标签更新
const std::string EVENT_SHUT_BUBBLE = "shoot_bubble";   //发射小球
const std::string EVENT_EXCHANGE_BUBBLE = "exchange_bubble";  //交换准备小球
const std::string EVENT_DESTROY_BUBBLE_CLOUD = "destroy_bubble_cloud"; //移除泡泡上的阴云
const std::string EVENT_CHANGE_PREPARE_TYPE = "change_prepare_bubble_type"; //更改发射小球颜色
const std::string EVENT_BLACKHOLE_BUBBLE_ELIMINATED = "black_bubble_eliminated"; //更改发射小球颜色
const std::string EVENT_ADJUST_MAP_POSITION = "adjust_map_position"; //更改发射小球颜色
const std::string EVENT_FALL_STAGE_ADJUST_MAP_POSITION = "event_fall_stage_adjust_map_position";
const std::string EVENT_ADD_ELIMINATE_COMBO = "add_eliminate_combo"; //增加消除连击
const std::string EVENT_CUT_ELIMINATE_COMBO = "cut_eliminate_combo"; //清除消除连击
const std::string EVENT_HAVE_USED_PROPS = "hanve_used_props"; //使用完道具
const std::string EVENT_USE_BUBBLE_BOMB_PROPS = "use_props_bomb"; //点击使用彩球道具
const std::string EVENT_CANCEL_BUBBLE_BOMB_PROPS = "cancel_use_colorbomb"; //点击取消使用彩球道具
const std::string EVENT_PROPS_SELECT_ALERT_CANCEL = "props_alert_cancel"; //道具选择面板取消
const std::string EVENT_PROPS_SELECT_ALERT_CONFIRM = "props_alert_confirm"; //道具选择面板取消
const std::string EVENT_USE_SELECTION_PROPS = "use_selection_props";  //使用选择系的道具
const std::string EVENT_SELECT_BUBBLE = "select_bubble"; //选中泡泡
const std::string EVENT_FIND_BUBBLES_IN_VISIBLESIZE = "find_bubbles_in_visible"; //查找屏幕中的小球
const std::string EVENT_RECENT_BUBBLE_CAST = "evnet_recent_bubble_cast"; //检测最近小球
const std::string EVENT_ROTATE_SIGHTING_DEVICE = "rotate_sighting_device"; //旋转喵准器
const std::string EVENT_TURN_ON_SIGHTING_DEVICE = "turn_on_sighting_device"; //开启喵准器
const std::string EVENT_TURN_OFF_SIGHTING_DEVICE = "turn_off_sighting_device"; //关闭喵准器
const std::string EVENT_SIGHTING_POINT_CONTACT_WORLD = "sighting_point_contact_world"; //喵准点碰到边界
const std::string EVENT_UPDATE_COMPLETED_TASK_LABEL = "update_completed_task_label"; //更新已完成任务label
const std::string EVENT_UPDATE_BUBBLE_USE_COUNT_LABEL = "update_bubble_use_count_label"; //更新小球使用数label
const std::string EVENT_SHOOT_PREPARE_BUBBLE = "shoot_prepare_bubble"; //发射球出去
const std::string EVENT_ADD_AIR_BUBBLE_NUMBLE = "add_air_bubble_numble"; //增加空中小球掉落数统计
const std::string EVENT_CUT_AIR_BUBBLE_NUMBLE = "cut_air_bubble_numble"; //--空中小球掉落数统计
const std::string EVENT_GAME_DEFEAT = "event_game_defeat"; //游戏失败
const std::string EVENT_POP_ENTER_GAME_ALERT = "event_pop_enter_game_alert"; //弹出进入游戏的面板
const std::string EVENT_FIND_THREE_BUBBLE = "EVENT_FIND_THREE_BUBBLE";  //使用加3道具
const std::string EVENT_UPDATE_SECOND_BUBBLE = "EVENT_UPDATE_SECOND_BUBBLE"; //更新第二小球
const std::string EVENT_DEFEAT = "EVENT_DEFEAT"; //失败
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL = "EVENT_ADD_ELIMINATE_SCORE_LABEL"; //添加消除的分数label
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_SCORE_KEY = "score_text";
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_X_KEY = "pos_x";
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_Y_KEY = "pos_y";
//选择特效的key
const std::string LONG_EFFECT_BUBBLE_KEY = "long_effect";     //大幅度特效
const std::string SHORT_EFFECT_BUBBLE_KEY = "short_effect";    //小幅度特效
const std::string PREPARE_EFFECT_BUBBLE_KEY = "prepare_effect";    //准备小球的特效key
//字符串常量                                      
const std::string BUBBLE_MAP_NODE_NAME = "bubble_map_node";  //地图node
const std::string SCORE_WIDGET_NODE_NAME = "ProjectNode_1";  //得分挂件的node名字
const std::string PREPARE_BUBBLE_NAME = "prepare_bubble";  //准备小球
const std::string COLOR_BOMB_BUBBLE_NAME = "color_bomb_bubble";  //道具彩球
const std::string SECOND_PREPARE_BUBBLE_NAME = "second_bubble";  //备选小球
const std::string BARREL_BOTTOM_NAME = "BARREL_BOTTOM_NAME";//桶底
const std::string SCORE_WIDGET_NAME = "SCORE_WIDGET";    //得分撞击配件
const std::string MAP_BUBBLE_NAME = ""; //地图上的小球名字
const std::string MAP_PHYSICS_BORDER_NAME = "map_physics_border_name"; //地图上边界body名字
const std::string SCORE_PROGRESS_START_1_KEY = STAGE_XML_FIELDS_START1; //楼上的分数进度天伤的星星key
const std::string SCORE_PROGRESS_START_2_KEY = STAGE_XML_FIELDS_START2; //楼上的分数进度天伤的星星key
const std::string SCORE_PROGRESS_START_3_KEY = STAGE_XML_FIELDS_START3; //楼上的分数进度天伤的星星key
const std::string SCORE_PROGRESS_START_1_SPRITE_KEY = SCORE_PROGRESS_START_1_KEY;
const std::string SCORE_PROGRESS_START_2_SPRITE_KEY = SCORE_PROGRESS_START_2_KEY;
const std::string SCORE_PROGRESS_START_3_SPRITE_KEY = SCORE_PROGRESS_START_3_KEY;
const std::string SCORE_PROGRESS_START_1_NAME = "xingxing_24"; //楼上的分数进度天伤的星星
const std::string SCORE_PROGRESS_START_2_NAME = "xingxing_24_0"; //楼上的分数进度天伤的星星
const std::string SCORE_PROGRESS_START_3_NAME = "xingxing_24_1"; //楼上的分数进度天伤的星星
const std::string SCORE_PROGRESS_BORDER_NAME = "Image_2"; //楼上的分数进度天伤的边框
const std::string SCORE_PROGRESS_START_PATH = "xingxing.png"; //楼上的分数进度天伤的星星
//shader
const std::string GREY_SCALE_FSH_PATH = "shader/example_GreyScale.fsh";
const std::string NORMAL_FSH_PATH = "shader/example_Normal.fsh";
const std::string BLUR_FSH_PATH = "shader/example_Blur.fsh";
//喵准器
const std::string NAME_BUBBLE_SIGHTING_POINT = "bubble_sighting_point"; //名字
const std::string NAME_BUBBLE_SIGHTING_DEVICE = "bubble_sighting_device"; //名字
const std::string BUBBLE_SIGHTING_POINT_PATH = "dian.png";
const cocos2d::Vec2 BUBBLE_SIGHTING_POINT_IMPULSE(0.0f, 100.0f);
const float BUBBLE_SIGHTING_POINT_DELAYTIME = 0.5f;
const int BUBBLE_SIGHTING_POINT_NUMBLE = 15;
const float BUBBLE_SIGHTING_POINT_MOVEBY_Y = 1334.0f;
const float BUBBLE_SIGHTING_POINT_TOP_MOVEBY_Y = MAP_BUBBLE_DIAMETER;  //瞄准线碰到顶部只反弹2颗
const float BUBBLE_SIGHTING_POINT_MOVEBY_TIME = 12.0f; 
const float BUBBLE_SIGHTING_POINT_CONTACT_VISIBLE_OFFSET = 140.0f; //碰到小球之后的可视计算时候位置误差
const int BUBBLE_SIGHTING_DEVICE_TOTAL = 4; //一共有5条线
const int BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL = 1; //不使用道具, 一共2条
const float BUBBLE_SIGHTING_DEVICE_GO_AWAY_Y = 2000.0f; //走远了
const float BUBBLE_SIGHTING_DEVICE_MAX_POS_Y_OFFSET = 22.0f; //偏移误差
//ui控件的名字
const std::string UI_NAME_GAME_PLAY_AREA_NODE = "csb_node";
const std::string UI_NAME_GUNSIGHT = "fashetaishang_38"; //喵准器
const std::string UI_NAME_TOP_PANEL = "uishang_5";     //顶部信息栏
const std::string UI_NAME_PAD = "fashetaixia_27";    //喵准器下面的基台
const std::string UI_NAME_GRASS = "yezi_7";        //喵准器旁边的小草
const std::string UI_NAME_SCORE_TEXT = "AtlasLabel_2";    //游戏场景中的分数标签
const std::string UI_NAME_SCORE_PROGRESS_TIMER = "LoadingBar_1"; //游戏场景中的分数进度条
const std::string UI_NAME_TOP_UI_BACKGROUND = "top_ui_bg";     //顶部ui的背景
const std::string UI_NAME_PROPS_BACKGROUND_FIRST = "props_1_bg";      //道具1的背景
const std::string UI_NAME_PROPS_BACKGROUND_SECOND = "props_2_bg";      //道具2的背景
const std::string UI_NAME_PROPS_BACKGROUND_THIRD = "props_3_bg";      //道具3的背景
const std::string UI_NAME_PROPS_BACKGROUND_FOURTH = "props_4_bg";      //道具4的背景
const std::string UI_NAME_GAME_PLAYING_MENU = "game_play_menu";      //游戏场景的左下角菜单
const std::string UI_NAME_GUNSIGHT_SWIRL = "gunsight_swirl";      //发射台上的旋风
const std::string UI_NAME_BIG_COMBO_ELIMINATE = "big_combo_eliminate";      //六连消
const std::string UI_NAME_WINDMILL_PIN_NODE = "windmill_pin_node"; //风车的关节pin的node
const std::string UI_NAME_GAME_VICTORY_ALERT = "UI_NAME_GAME_VICTORY_ALERT"; //胜利面板的名字
//下面部分的ui名字
const std::string UI_NAME_BARRELHEAD_FIRST = "Image_14";        //从左数第一个桶盖
const std::string UI_NAME_BARRELHEAD_SECOND = "Image_12";
const std::string UI_NAME_BARRELHEAD_THIRD = "Image_6";
const std::string UI_NAME_BARRELHEAD_FOURTH = "Image_8";
const std::string UI_NAME_BARRELHEAD_FIFTH = "Image_10";       //从左数第五个桶盖
const std::string UI_NAME_BARRELHEAD_BORDER_FIRST = "Node_7";       //从左数第1个桶边节点
const std::string UI_NAME_BARRELHEAD_BORDER_SECOND = "Node_8";        //从左数第2个桶边节点
const std::string UI_NAME_BARRELHEAD_BORDER_THIRD = "Node_9";       //从左数第3个桶边节点
const std::string UI_NAME_BARRELHEAD_BORDER_FOURTH = "Node_10";       //从左数第4个桶边节点
const std::string UI_NAME_BARRELHEAD_BORDER_FIFTH = "Node_11";      //从左数第5个桶边节点
const std::string UI_NAME_BARRELHEAD_BORDER_SIXTH = "Node_12";      //从左数第6个桶边节点
const std::string UI_NAME_BARREL_BOTTOM_FIRST = "Node_1";       //左起第1个桶底
const std::string UI_NAME_BARREL_BOTTOM_SECOND = "Node_2";       //左起第2个桶底
const std::string UI_NAME_BARREL_BOTTOM_THIRD = "Node_3";        //左起第3个桶底
const std::string UI_NAME_BARREL_BOTTOM_FOURTH = "Node_4";        //左起第4个桶底
const std::string UI_NAME_BARREL_BOTTOM_FIFTH = "Node_5";        //左起第5个桶底
const std::string UI_NAME_BARREL_FIRST = "Image_13"; //左数第一的桶身体
const std::string UI_NAME_BARREL_SECOND = "Image_11"; //左数第2的桶身体
const std::string UI_NAME_BARREL_THIIRD = "Image_5"; //左数第3的桶身体
const std::string UI_NAME_BARREL_FOURTH = "Image_7"; //左数第4的桶身体
const std::string UI_NAME_BARREL_FIFTH = "Image_9"; //左数第5的桶身体
const std::string UI_NAME_BARREL_NUMBLE_FIRST = "AtlasLabel_3"; //左数第一的桶上的数字
const std::string UI_NAME_BARREL_NUMBLE_SECOND = "AtlasLabel_3_0"; //左数第2的桶数字
const std::string UI_NAME_BARREL_NUMBLE_THIIRD = "AtlasLabel_3_0_0"; //左数第3的桶数字
const std::string UI_NAME_BARREL_NUMBLE_FOURTH = "AtlasLabel_3_0_1"; //左数第4的桶数字
const std::string UI_NAME_BARREL_NUMBLE_FIFTH = "AtlasLabel_3_1"; //左数第5的桶数字
const std::string UI_NAME_BARREL_NUMBLES[5] = { UI_NAME_BARREL_NUMBLE_FIRST , UI_NAME_BARREL_NUMBLE_SECOND, 
UI_NAME_BARREL_NUMBLE_THIIRD,UI_NAME_BARREL_NUMBLE_FOURTH,UI_NAME_BARREL_NUMBLE_FIFTH };
const std::string UI_NAME_COMPLETED_TASK = "AtlasLabel_1";//已完成目标的label
const std::string UI_NAME_GAME_TASK = "AtlasLabel_2";//胜利任务目标的label
const std::string UI_NAME_BUBBLE_USE_COUNT = "AtlasLabel_1";//小球使用数的label
const std::string UI_NAME_WINDMILL_BORDER = "windmill_border";//风车地图的边界
const std::string UI_NAME_FALL_BOTTOM_BORDER = "UI_NAME_FALL_BOTTOM_BORDER";//下落模式底部的边界
//风车小妖
const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_HEAD_PATH = "XiaoYao-tou.png";
const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_BODY_PATH = "XiaoYao-body.png";
const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_MOTIONSTREAK_PATH = "XiaoYao-streak.png";
const float WINDMILL_BUBBLE_FLYING_HEAD_POS_Y = 40.0f;
const float WINDMILL_BUBBLE_FLYING_BODY_POS_Y = -40.0f;
const float WINDMILL_BUBBLE_FLYING_INITIAL_SCALE = 0.3f; //初始大小
const float WINDMILL_BUBBLE_FLYING_FINAL_SCALE = 1.3f; //最后大小
const float WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_A = 10.0f; //公式的参数a
const float WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_B = 1.0f;
const int WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA = 430;
const int WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_DIRECTION = 1; //方向
const float WINDMILL_BUBBLE_FLYING_ACTION_DURATION = 1.5f;
//分数进度条的
const float GAME_SCORE_PROGRESS_TIMER_PER_INCREASE_PERCENT = 1.5f; // 每帧增加的百分比
const float GAME_SCORE_PROGRESS_TIMER_BACK_PERCENT = 3.0f;
const std::string GAME_SCORE_PROGRESS_SCHEDULE_KEY = "increase_progress";
//游戏暂停面板
const std::string GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH = "kuang.png"; //弹出来的背景 大尺寸
const std::string GAME_PAUSE_ALERT_BACKGROUND_PATH = GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH; //弹出来的背景
const float GAME_PAUSE_ALERT_BACKGROUND_SCALE_Y = 0.83f;
const std::string GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH = "guanka.png"; //顶部暂停的背景
const int GAME_ALERT_TOP_BACKGROUND_TAG = 123;
const int GAME_ALERT_BIG_BACKGROUND_TAG = 122;
const cocos2d::Color4B GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR(35, 157, 142, 255);
const float GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE = 50.0f; //字体大小
const float GAME_VICTORY_ALERT_SCORENUMBLE_LABEL_FONTSIZE = 80.0f; //字体大小
const std::string GAME_PAUSE_ALERT_MUSIC_ICON_PATH = "yinyue.png"; //音乐图标
//const float GAME_PAUSE_ALERT_MUSIC_ICON_POSITION_Y = -38.48f;
const std::string GAME_PAUSE_ALERT_EFFECT_ICON_PATH = "yinxiao.png"; //音效图标
const cocos2d::Vec2 GAME_PAUSE_ALERT_EFFECT_ICON_POSITION(-120.0f, 70.0f);
const std::string GAME_PAUSE_ALERT_VOLUME_SWITCH_BACKGROUND_PATH = "vol_switch_bg.png";
const std::string GAME_PAUSE_ALERT_SIMPLE_SWITCH_MASKSPRITE_PATH = "yinxk.png";
const std::string GAME_PAUSE_ALERT_VOLUME_SWITCH_THUMBSPRITE_PATH = "yinxan.png";
const float GAME_PAUSE_ALERT_EFFECT_SWITCH_POSITION_X = 92.66f;  //音效开关的x坐标
const std::string GAME_PAUSE_ALERT_BACK_BUTTON_PATH = "guanb.png"; //返回按钮
const float GAME_PAUSE_ALERT_BACK_BUTTON_POSITION_X = -166.51f;  //返回按钮x坐标
const std::string GAME_PAUSE_ALERT_RESTART_BUTTON_PATH = "chongw.png"; //重玩按钮
const std::string GAME_PAUSE_ALERT_RESUME_BUTTON_PATH = "jixu.png"; //返回按钮
const float GAME_PAUSE_ALERT_RESUME_BUTTON_POSITION_X = 166.51f;  //返回按钮x坐标
const cocos2d::Vec2 GAME_PAUSE_ALERT_BOTTOM_MENU_POSITION(0.0f, -179.0f);
const std::string GAME_ALERT_CANCEL_BUTTON_PATH = "guanbi.png"; //取消按钮
const cocos2d::Vec2 GAME_ALERT_CANCEL_BUTTON_POSITION(270.0f, 350.0f);
const std::string GAME_ALERT_STORE_BUTTON_PATH = "shangc.png"; //商城按钮
const std::string GAME_DEFEAT_ALERT_CHARACTOR_PATH = "shibai.png"; //失败面板上的人物按钮
const cocos2d::Vec2 GAME_PAUSE_ALERT_DEFEAT_CHARACTOR_POSITION(0.0f, 50.0f);
const float GAME_PAUSE_ALERT_DEFEAT_CHARACTOR_SCALE = 0.7f;
const cocos2d::Vec2 GAME_DEFEAT_ALERT_REPLAY_POSITION(100.0f, -70.0f);
const cocos2d::Vec2 GAME_DEFEAT_ALERT_STORE_POSITION(-100.0f, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const std::string GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH = "djkuang.png"; //中间的小面板
const cocos2d::Vec2 GAME_VICTORY_ALERT_REWARDS_BACKGROUND_POSITION(10.0f, -100.0f);
const std::string GAME_COMMODITY_TEN_BUBBLE_PATH = "j10p.png";
const std::string GAME_ALERT_CONTINUE_BUTTON_PATH = "jixu1.png";
const std::string GAME_ALERT_COMMODITY_TEN_BUBBLE_PRICE_BACKGROUND_PATH = GAME_PAUSE_ALERT_VOLUME_SWITCH_BACKGROUND_PATH; //价格下面的北京
const std::string GAME_DIAMOND_PATH = "zuans.png"; //砖石
const std::string GAME_COIN_PATH = "jinb.png"; //金币
const float GAME_VICTORY_ALERT_COIN_POSITION_PERCENT_X = 0.4f;
const std::string GAME_FATIGUE_PATH = "xin.png"; //疲劳
const float GAME_VICTORY_ALERT_FATIGUE_POSITION_PERCENT_X = 0.7f;
const float GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_FONTSIZE = 40.0f;
const float GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_NUMBER_OF_LINES = 11.0f;
const cocos2d::Size GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_DIMENSIONS = cocos2d::Size(GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_FONTSIZE*GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_NUMBER_OF_LINES, 0.0f);
const cocos2d::Color4B GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_COLOR(1, 94, 208, 255);
const cocos2d::Vec2 GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_POSITION(0.0f, 180.0f);
const cocos2d::Vec2 GAME_VICTOR_ALERT_REPLAY_POSITION(GAME_PAUSE_ALERT_BACK_BUTTON_POSITION_X, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const cocos2d::Vec2 GAME_VICTOR_ALERT_STORE_POSITION(0.0f, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const cocos2d::Vec2 GAME_VICTOR_ALERT_NEXT_POSITION(GAME_PAUSE_ALERT_RESUME_BUTTON_POSITION_X, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const std::string GAME_VICTORY_ALERT_NEXT_BUTTON_PATH = GAME_PAUSE_ALERT_RESUME_BUTTON_PATH; //下一关按钮
const std::string GAME_VICTORY_ALERT_FLASH_LIGHT_BACKGROUND_PATH = "dikuang.png"; //闪光后面的北京
const std::string GAME_VICTORY_ALERT_FLASH_LIGHT_PATH = "guang.png"; //闪光
const float GAME_VICTORY_ALERT_FLASH_LIGHT_ROTATEBY_DURATION = 5.0f;
const float GAME_VICTORY_ALERT_FLASH_LIGHT_ROTATEBY_DELTAANGLE = 360.0f;
const cocos2d::Vec2 GAME_VICTORY_ALERT_SCORE_LABEL_POSITION(0.0f, 30.0f); //奖励分数位置
const cocos2d::Vec2 GAME_VICTORY_ALERT_SCORE_LABEL_TEXT_POSITION(0.0f, 100.0f); //奖励: DE位置
const cocos2d::Vec2 GAME_VICTORY_ALERT_SAMSUNG_POSITION(0.0f, 180.0f); //三星位置
const float GAME_VICTORY_ALERT_ADD_SCORE_LABEL_POSITION_PERCENT_X = 0.5f; //+180金币
const float GAME_VICTORY_ALERT_ADD_FATIGUE_LABEL_POSITION_PERCENT_X = 0.8f; //+1体力
const float GAME_SAMSUNG_MIDDLE_POSITION_Y = 50.0f;
const float GAME_SAMSUNG_TWO_SIDES_POSITION_X = 130.0f;
const float GAME_SAMSUNG_TWO_SIDES_ROTATIOIN = 25.0f;
//关卡按钮
const std::string GAME_STAGE_SELECTION_MENU_PURPLE_PATH = "anniu1.png";
const std::string GAME_STAGE_SELECTION_MENU_GRAY_PATH = "anniu3.png";
const std::string GAME_STAGE_SELECTION_MENU_ORANGE_PATH = "anniu2.png";
//GameBaseAlert
const std::string GAME_BASE_ALERT_NAME = "GAME_BASE_ALERT_NAME";
//GamePauseAlert
const float GAME_PAUSE_ALERT_VOL_POS_Y = 60.0f;
//StageSelectionMenu
const float STAGE_SELECTION_MENU_SCALE = 0.7f;
const float STAGE_SELECTION_MENU_SAMSUNG_SCALE = 0.5f;
const cocos2d::Vec2 STAGE_SELECTION_MENU_SAMSUNG_POSITION(0.0f, 80.0f);
const cocos2d::Vec2 STAGE_SELECTION_MENU_STAGE_LABEL_POSITION(0.0f, -50.0f);
const float STAGE_SELECTION_MENU_STAGE_LABEL_FONTSIZE = 60.0f;
const cocos2d::Vec2 STAGE_SELECTION_MENU_STAGETYPE_TEXTURE_POSITION(0.0f, 20.0f);
const float STAGE_SELECTION_MENU_THE_BLINK_FADE_DURATION = 0.75f;
const float STAGE_SELECTION_MENU_HALFMOONSLASH_POSITION_X = 60.0f;
const float STAGE_SELECTION_MENU_HALFMOONSLASH_POSITION_Y = 15.0f;
const float STAGE_SELECTION_MENU_HALFMOONSLASH_ACTION_DURATION = 0.5f;
const float STAGE_SELECTION_MENU_HALFMOONSLASH_DELAYTIME = 2.0f;
const std::string STAGE_SELECTION_MENU_HALFMOONSLASH_PATH = "kuosan.png";
//GameStageSelectionCell
const int GAME_STAGE_SELECTION_CELL_MENU_POSITION_NODE_TAG_BEGIN = 1;  //tage从1开始
const int GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN = 0; //cell从0开始
const int GAME_STAGE_NUMBLE_BEGIN = 1; //关卡从1开始
const float GAME_STAGE_SELECTION_CELL_SCALE = 0.73f;
//GameStageSelectionScene
const std::string GAME_STAGE_SELECTION_SCENE_NAME = "game_stage_selection_scene";
const float GAME_STAGE_SCROLLVIEW_CELL_HEIGHT = 745.0f;
const std::string GAME_STAGE_SCROLLVIEW_BOTTOM_PATH = "StageSelectRes/episode000_hd.jpg";
const float GAME_STAGE_SCROLLVIEW_CELL_BACKGROUND_HEIGHT = 1024.0f;
const float GAME_STAGE_SCROLLVIEW_CELL_OFFSET_OFFSET = GAME_DESIGN_RESOLUTION_HEIGHT - GAME_STAGE_SCROLLVIEW_CELL_BACKGROUND_HEIGHT;
//EnterGameAlert
const std::string ENTER_GAME_ALERT_CHARACTOR_PATH = "juese.png";
const int ENTER_GAME_ALERT_CHARACTOR_TAG = 124;
const cocos2d::Vec2 ENTER_GAME_ALERT_CHARACTOR_POSITION(5.0f, 84.0f);
const std::string ENTER_GAME_ALERT_PROPS_BACKGROUND_PATH = "djk.png";
const std::string ENTER_GAME_ALERT_BEGIN_BUTTON_PATH = "kaishi.png";
const float ENTER_GAME_ALERT_BEGIN_BUTTON_POSITION_Y = -240.0f;
const std::string ENTER_GAME_ALERT_PROPS_LABEL_BACKGROUND_PATH = GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH;
const float ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE = 35.0f;
const float MOUSE_SCROLL_Y_SENSITIVITY = 50.0f; //鼠标滚动系数
//UserDataManager
const std::string GAME_STAGE_DATA_PATH = "stageData.plist";
const std::string GAME_USER_DATA_PATH = "userData.plist";
const std::string USER_DATA_NICKNAME_KEY = "user_nickname";
const std::string USER_DATA_MUSIC_KEY = "GAME_MUSIC";
const std::string USER_DATA_SOUND_EFFECT_KEY = "SOUND_EFFECT"; 
const std::string AIMING_LINE_COMMODITY_NAME = "AimingLineCommodity";
const std::string ADD_SPECIAL_COMMODITY_NAME = "AddSpecialCommodity";
const std::string ADD_BUBBLE_NUMBLE_COMMODITY_NAME = "AddBubbleNumbleCommodity";
//EnterGamePropsView
const std::string ENTER_GAME_PROPS_VIEW_SIGHT_PROPS_PATH = "fzx.png"; //瞄准线
const std::string ENTER_GAME_PROPS_VIEW_ADD_SPECIAL_BUBBLE_PROPS_PATH = "yaoshui.png"; //加特殊泡泡
const std::string ENTER_GAME_PROPS_VIEW_ADD_BUBBLE_PROPS_PATH = GAME_COMMODITY_TEN_BUBBLE_PATH; //加特殊泡泡
const float ENTER_GAME_PROPS_VIEW_LEFT_POS_X = -150.0f;
const std::string ENTER_GAME_PROPS_VIEW_BACKGROUND_PATH = "daojd.png";
//每个场景对应的游戏背景
const std::string GAME_SCENE_BACKGROUND_PATH = "res/gameBackground.plist";
//GameSettingAlert
const std::string GAME_SETTING_ALERT_TEXTFIELD_BACKGROUND_PATH = "shurk.png";
const std::string GAME_SETTING_ALERT_PORTRAIT_PATH = "touxiang.png";
const std::string GAME_SETTING_ALERT_HELP_MENU_BACKGROUND_PATH = GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH;
const std::string GAME_SETTING_ALERT_HELP_MENU_PATH = "bangz.png";
const std::string GAME_SETTING_ALERT_PROPS_MENU_PATH = "daoju.png";
const std::string GAME_SETTING_ALERT_ABOUT_MENU_PATH = "guanyu.png";
//GamePropsNumbleView
const std::string GAME_PROPS_NUMBLE_VIEW_TICK_PATH = "duigou.png";
const float GAME_PROPS_NUMBLE_VIEW_TICK_POS_Y = 5.0f;
const float GAME_PROPS_NUMBLE_VIEW_BACKGROUND_SCALE = 0.65f;
//GameTextInfo
const std::string GAME_TEXT_INFO_PLIST_CHINESE_PATH = "res/zh.plist";
const std::string GAME_TEXT_INFO_PLIST_ENGLISH_PATH = "res/en.plist";
const std::string GAME_COMMODITY_PLIST_PATH = "res/commodity.plist";
const std::string GAME_TEXT_PAUSE_KEY = "pause";
const std::string GAME_TEXT_SETTING_KEY = "setting";
const std::string GAME_TEXT_NICKNAME_KEY = "nickname";  //昵称
const std::string GAME_TEXT_VOLUME_ON_KEY = "volume_on";
const std::string GAME_TEXT_VOLUME_OFF_KEY = "volume_off";
const std::string GAME_TEXT_LEVEL_NUMBLE_1_KEY = "alert_level_1";
const std::string GAME_TEXT_LEVEL_NUMBLE_2_KEY = "alert_level_2";
const std::string GAME_TEXT_BUY_BUBBLE_KEY = "add_ten_bubble";
const std::string GAME_TEXT_BUY_BUBBLE_LABEL_KEY = "buy_ten_bubble_label";
const std::string GAME_TEXT_REWARDS_KEY = "rewards_label";
const int GAME_TEXT_REWARDS_LABEL_OPACITY = 180;
const float GAME_TEXT_REWARDS_LABEL_POSITION_PERCENT_X = 0.2f;
const std::string GAME_TEXT_SCORE_KEY = "score_label";
const std::string GAME_TEXT_TOP_ELIMINATE = "kTopEliminate";      //消除顶部泡泡
const std::string GAME_TEXT_RESCUE_ANIMAL = "kRescueAnimal";                   //解救动物
const std::string GAME_TEXT_BEAT_THE_ROBBER = "kDestroyRainbowSeal";                     //击败强盗
const std::string GAME_TEXT_RESCUE_GHOST = "kWindmill";                                           //解救幽灵
const std::string COMMODITY_COIN_KEY = "coin";
const std::string COMMODITY_DIAMOND_KEY = "diamond";
const std::string COMMODITY_ADD_10_BUBBLE_KEY = "add_10_bubble";   //加10个球
const std::string GAME_TEXT_SELECT_PROPS_LABEL_KEY = "choose_props";
const std::string COMMODITY_AIMING_LINE_KEY = "aiming_line"; //瞄准线道具
const std::string COMMODITY_ADD_SPECIAL_KEY = "add_special_bubble"; //加3个特殊泡泡
//ColorBubble
const float ENTER_PROPS_ACTION_DURATION = 1.0f; //进场道具的动画时间
//EnterPropsViewManager
const int ADD_BUBBLE_NUMBLE_PROPS_NUMBLE = 10;
//ui控件的zorder
const int UI_ZORDER_BACKGROUND = -4;                       //背景  
const int UI_ZORDER_MAP_BUBBLE = -2;  //小球地图 csb_node
const int UI_ZORDER_DOWN_AIR_BUBBLE = UI_ZORDER_MAP_BUBBLE + 1;    //下落小球
const int UI_ZORDER_PROPS_SELECT_ALERT = UI_ZORDER_MAP_BUBBLE - 1; //道具选择面板
const int UI_ZORDER_PREPARE_BUBBLE = UI_ZORDER_PROPS_SELECT_ALERT - 1;   //准备小球
const int UI_ZORDER_SWIRL = UI_ZORDER_PREPARE_BUBBLE - 1; //旋风
const int UI_ZORDER_GUNSIGHT = UI_ZORDER_SWIRL - 1;   //喵准器
const int UI_ZORDER_SIGHTING_DEVICE = UI_ZORDER_GUNSIGHT - 1; //瞄准导线
const int UI_ZORDER_PAD = UI_ZORDER_GUNSIGHT;      //喵准器下面的基台
const int UI_ZORDER_GRASS = UI_ZORDER_GUNSIGHT;      //小草
const int UI_ZORDER_BARRELBOTTOM = UI_ZORDER_DOWN_AIR_BUBBLE - 1;
const int UI_ZORDER_BARRELHEAD_FIRST = UI_ZORDER_BARRELBOTTOM - 1;   //桶盖从左数第一
const int UI_ZORDER_BARRELHEAD_SECOND = UI_ZORDER_BARRELHEAD_FIRST;
const int UI_ZORDER_BARRELHEAD_THIRD = UI_ZORDER_BARRELHEAD_FIRST;
const int UI_ZORDER_BARRELHEAD_FOURTH = UI_ZORDER_BARRELHEAD_FIRST;
const int UI_ZORDER_BARRELHEAD_FIFTH = UI_ZORDER_BARRELHEAD_FIRST;    //从左数第五个桶盖
const int UI_ZORDER_MENU = 1;    //菜单和按钮
const int UI_ZORDER_MENU_INFO = 1;    //分数信息之类的
const int UI_ZORDER_GUNSIGHT_SWIRL = UI_ZORDER_GUNSIGHT + 1; //炮台上的旋风
const int UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_ONCE = UI_ZORDER_BACKGROUND; //六连消时候后面的播放一次的特效
const int UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_REPEAT = UI_ZORDER_MENU; //六连消时候后面的连续播放的特效
const int UI_ZORDER_RAINBOW_SEALED_CHARACTOR = -1; //彩虹封印里面的人物
//const float UI_GLOBALZORDER_LIGHTING_EFFECT_BACKGROUND = 1.1f; //闪电特效的黑色背景
//const float UI_GLOBALZORDER_LIGHTING_EFFECT = 10.5f; //闪电特效
const int UI_ZORDER_MENU_MASK_NULL_BUTTON = -1; //ALERT的空白按钮
const int UI_ZORDER_MENU_MASK_COLOR_LAYER = UI_ZORDER_MENU_MASK_NULL_BUTTON -1; //黑色蒙版
const int UI_ZORDER_MENU_MASK_BLUR_SPRITE = UI_ZORDER_MENU_MASK_COLOR_LAYER - 1; //截图精灵
//碰撞掩码
const int BITMASK_BUBBLE_STATIC_CATEGORY = 0x10001; //小球静态刚体的种类掩码
const int BITMASK_BUBBLE_STATIC_COLLISION = 0x0001; //小球静态刚体的碰撞掩码
const int BITMASK_BUBBLE_STATIC_CONTACTTEST = 0x10001; //小球静态刚体的事件掩码
                                             
const int BITMASK_BUBBLE_DYNAMIC_CATEGORY = 0x0010; //小球动态刚体的种类掩码
const int BITMASK_BUBBLE_DYNAMIC_COLLISION = 0x0100; //小球动态刚体的碰撞掩码
const int BITMASK_BUBBLE_DYNAMIC_CONTACTTEST = 0x0100; //小球动态刚体的事件掩码

const int BITMASK_BUBBLE_PREPARE_CATEGORY = 0x100001; //准备小球刚体的种类掩码
const int BITMASK_BUBBLE_PREPARE_COLLISION = 0x0001; //准备小球刚体的碰撞掩码
const int BITMASK_BUBBLE_PREPARE_CONTACTTEST = 0x10001; //准备小球刚体的事件掩码

const int BITMASK_BARRELHEADEDGE_CATEGORY = 0x0100; //桶盖边刚体的种类掩码
const int BITMASK_BARRELHEADEDGE_COLLISION = 0x0010; //桶盖边刚体的碰撞掩码
const int BITMASK_BARRELHEADEDGE_CONTACTTEST = 0x0001; //桶盖边刚体的事件掩码

const int BITMASK_BARRELBOTTOM_CATEGORY = 0x0100;//桶底刚体的种类掩码
const int BITMASK_BARRELBOTTOM_COLLISION = 0x0000; //桶底刚体的碰撞掩码
const int BITMASK_BARRELBOTTOM_CONTACTTEST = 0x0010;//桶底刚体的事件掩码

const int BITMASK_SCORE_WIDGET_CATEGORY = 0x0100; //得分挂件刚体的种类掩码
const int BITMASK_SCORE_WIDGET_COLLISION = 0x0010;//得分挂件刚体的碰撞掩码
const int BITMASK_SCORE_WIDGET_CONTACTTEST = 0x0010;//得分挂件刚体的事件掩码

const int BITMASK_PHYSICS_WORLD_CONTACTTEST = 0x1000;//世界刚体的事件掩码

const int BITMASK_WINDMILL_BORDER_CATEGORY = 0x10000;//风车地图边界的种类掩码
const int BITMASK_WINDMILL_BORDER_COLLISION = 0x00000; //风车地图边界的碰撞掩码
const int BITMASK_WINDMILL_BORDER_CONTACTTEST = 0x10000;//风车地图边界的事件掩码
const int BITMASK_WINDMILL_BOTTOM_BORDER_CONTACTTEST = 0x100000;//下边风车地图边界的事件掩码

const int BITMASK_SIGHTING_POINT_INITIAL_CATEGORY = 0x0001; //瞄准点刚体的种类掩码
const int BITMASK_SIGHTING_POINT_INITIAL_CONTACTTEST = 0x0001;//瞄准点刚体的事件掩码
const int BITMASK_SIGHTING_POINT_CATEGORY = 0x1001; //瞄准点刚体的种类掩码
const int BITMASK_SIGHTING_POINT_CONTACTTEST = 0x1001;//瞄准点刚体的事件掩码

const int BITMASK_FALL_BOTTOM_BORDER_CONTACTTEST = 0x10000;//下落模式底部边界的事件掩码

namespace bubble_second {
    class BaseBubble;
    typedef std::map<int, cocos2d::Map<int, BaseBubble*>> BubbleSpriteMap;
    typedef cocos2d::Vector<BaseBubble*> BubbleVector;
    typedef std::vector<cocos2d::Vec2> BubbleIndexVector;
    typedef std::map<std::string, BubbleVector> BubbleVectorMap;
    struct StageData
    {
        int cell_numble = 0;
        int level_numble = 0;
    };
}

enum BubbleType
{//颜色泡泡的颜色数字
    kBubbleNull = -9, //空类型的泡泡
    kBubbleNoCloud = -1,
    kBubbleYellow = 0,
    kNormalColorFirst = kBubbleYellow,
    kBubblePurple,
    kBubbleBlue,
    kBubbleRed,
    kBubbleGreen,
    kBubbleOrange,
    kBubblePink = 6,
    kNormalColorLast = kBubblePink,
    kBubbleLightning = 7,
    kBubbleDarkCloud = 8,
    kBubbleBlackHole = 9,
    kBubbleBombBomb = 10,
    kBubbleColorBomb = 11,
    kBubbleBombBombProperty =12,
    kBubbleRainbowSeal = 13,
    kBubbleComponentFirst = kBubbleRainbowSeal,
    kBubbleComponent,
    kBubbleMutipleSeal = 15,
    kBubbleMutipleSeal1, //16
    kBubbleMutipleSeal3, //17
    kBubbleMutipleSeal7 = 18,
    kBubbleComponentLast = kBubbleMutipleSeal7,
    kBubbleRandomColor,
    kBubbleWindmill,
    kBubbleAddNumbleBubble
};

enum ScoreWidgetType
{//挂件种类
    kScoreWidgetBlue = 0,
    kScoreWidgetPink,
    kScoreWidgetGreen,
    kScoreWidgetTypeTotal
};

enum StageType
{
    kTopEliminate = 1<<0,
    kRescueAnimal = 1<<1,
    kDestroyRainbowSeal = 1 << 2,
    kWindmill = 1 << 3,
    kBubbleFall = 1 << 4
};
const std::string STAGETYPE_TEXTURE_TOPELIMINATE_PATH = "wanftb3.png";
const std::string STAGETYPE_TEXTURE_RESCUEANIMAL_PATH = "wanftb2.png";
const std::string STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH = "wanftb4.png";
const std::string STAGETYPE_TEXTURE_WINDMILL_PATH = "wanftb1.png";
#endif //_BUBBLE_SECOND_CONSTANT_H_