//*******************************************************************************
//类名称   : StageSelectionMenu
//功能     : <关卡的选择按钮>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_SELECTION_MENU_H_
#define _STAGE_SELECTION_MENU_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameSamsung;
    enum HalfMoonSlashDirection
    {
      kLeft = -1,
      kRight = 1
    };
    class StageSelectionMenu : public cocos2d::Node
    {
    public:
        static StageSelectionMenu* create(int cell_numble, int level, const StageType& type);
        ~StageSelectionMenu();
        void turnOnBlink();
        //设置选择按钮能不能点
        void setSelectionMenuEnable(bool flag);
    private:
        StageSelectionMenu();
        bool init(int cell_numble, int level, const StageType& type);
        void addButton(int cell_numble, int level, const StageType& type);
        //设置状态
        void setMenuState(int cell_numble, int level);
        void setButtonEnable(bool flag);
        void addSamsung(int start_numble);
        void addStageLabel(int level);
        bool isButtonEnable();
        void addStageTypeTexture(const StageType& type);
        //两边的半月斩
        void halfMoonSlash(const HalfMoonSlashDirection& direction);
        //计算父类layer
        cocos2d::Node* getSelectionLayer();
    private:
        GameSamsung* samsung_ = nullptr;
        cocos2d::Sprite* button_sp_ = nullptr;
        cocos2d::Vec2 touch_begin_position_;
        bool touch_enable_ = true;
        bool menu_enable_ = true;
        int cell_numble_ = 0;
        int level_numble_ = 0;
    };
}
#endif //_STAGE_SELECTION_MENU_H_