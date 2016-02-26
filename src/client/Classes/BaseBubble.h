//*******************************************************************************
//������   : BaseBubble
//����     : <��Ϊ���ݵĻ���ʹ��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б���
//*******************************************************************************
#ifndef _BASE_BUBBLE_H_
#define _BASE_BUBBLE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ScoreWidget;
    class BaseBubble : public cocos2d::Sprite
    {
    public:   
        //bool initWithType(int type);
        BaseBubble();
        virtual ~BaseBubble();
        //CREATE_FUNC(BaseBubble);
        //static BaseBubble* createWithType(int type)
        //{ 
        //    BaseBubble *pRet = new(std::nothrow) BaseBubble();
        //    if (pRet && pRet->initWithType(type))
        //    {
        //        pRet->autorelease();
        //        return pRet;
        //    }
        //    else
        //    {
        //        delete pRet;
        //        pRet = NULL;
        //        return NULL;
        //    }
        //}

    public:
        //���Ӿ�̬����
        virtual void addBubbleStaticBody();
        //���Ӷ�̬����, Ϊ��ʹС��ӿ��е���
        virtual void addBubbleDynamicBody();
        //���Ӵ�糵����
        //virtual cocos2d::PhysicsBody* addBubbleWindmillBody();
        //������Ϊ����С��ĸ���
        //virtual void addBubblePrepareBody();
        //�ն�
        virtual void downFromAir();
        //С����������
        virtual void bubbleEliminate(int combo = 0);
        //��Ҫ�ӵ�ͼ���Ƴ�
        virtual bool needRemoveFromBubbleMap();
        //��������ǰ�Ķ���, һ������������ݲ����������
        virtual float playTheSpecialEffects();
    public:
        void setBubbleType(int type);
        void setEliminateDelayTime(float time);
        float getEliminateDelayTime();
        virtual BubbleType getBubbleType() const;
        void setBubbleIndex(cocos2d::Vec2);
        cocos2d::Vec2 getBubbleIndex() const;
        //cocos2d::Vec2 getPointInMapNode();
        //����ײ������
        void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point);
        //�Լ��������Ƿ�����ͨ�Ĳ�ɫС��
        bool isColorBubbleType();
        //�Լ������Ƿ��������ʽ
        bool isComponentBubbleType();
        //�Լ��Ƿ����ҵ�
        bool isSuspensionPoint();
        //�Ƿ�糵�����ĵ�
        bool isWindmillBubble();
        //�����Ƿ���ͬ
        bool isEqualType(BubbleType type);
        //���ӵ���¼�
        virtual void addTouchEventListener();
        virtual void removeTouchEventListener();
        //��ȡС����������
        int getBubbleComponentNumble();
        void setBubbleComponentNumble(int numble);
        //����flag , �ж��Ƿ��Ѿ���ײ����
        void hadContacted();
        bool isHadContacted();
    protected:
        //���رȽ�������Ա�ʹ��std::find
        //bool operator==(const BaseBubble& bubble);
        virtual bool init();
        virtual void setBubbleTexture(BubbleType type);
        //void setRepeatContactWidget(ScoreWidget* widget);
        void runLongContactEffect(const cocos2d::Vec2& point);
        void runShortContactEffect(const cocos2d::Vec2& point);
        //ײ����Чaction
        void runContactAction(const cocos2d::Vec2& point);
        //����ײ����Ч�ķ���
        cocos2d::Vec2 getEffectDistance(const cocos2d::Vec2& point, float distance);
        void setSupensionPoint(bool flag);
    protected:
        std::map<std::string, std::function<void(const cocos2d::Vec2& point)>> key_to_handle_effect_;
    private:
        void initHandleEffect();
    private:
        BubbleType bubble_type_;
        cocos2d::Vec2 bubble_in_map_index_;
        float run_eliminate_action_dalay_;
        bool suspension_flag_;
        int bubble_component_numble_;
        bool had_contacted_ = false;
    };
}
#endif //_BASE_BUBBLE_H_