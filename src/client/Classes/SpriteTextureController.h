//*******************************************************************************
//������   : SpriteTextureController
//����     : <���뾫��������������߼�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б���
//*******************************************************************************
#ifndef _SPRITE_TEXTURE_CONTROLLER_H_
#define _SPRITE_TEXTURE_CONTROLLER_H_
//#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class CenteredMenuItemSprite;
    class SpriteTextureController
    {
    public:
        GETINSTANCE_FUNC(SpriteTextureController);
        ~SpriteTextureController();
        void setSpriteTexture(const std::string& path, cocos2d::Sprite* sprite);
        cocos2d::Sprite* createGameSpriteWithPath(const std::string& path);
        //std::string addGameSearchPath(const std::string& path);
        CenteredMenuItemSprite* createMenuItemSprite(const std::string& path, const cocos2d::ccMenuCallback& callback = nullptr);
        cocos2d::Sprite* createStageTypeSprite(const StageType& type);
        cocos2d::Sprite* createGameBackgroundSprite(int cell_numble);
        //��������
        void addResourcesTexture();
        void addGameBackgroundTexture(int cell_numble);
    private:
        SpriteTextureController();
        void readGameSceneBackgroundFile();
        void addArmatureFile();
        void removeArmatureFile();
    private:
        std::map<StageType, std::string> stagetype_to_path_;
        cocos2d::ValueMap cell_to_path_;
    };
}
#endif //_SPRITE_TEXTURE_CONTROLLER_H_