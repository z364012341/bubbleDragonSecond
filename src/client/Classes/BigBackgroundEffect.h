#ifndef _BIG_BACKGROUND_EFFECT_H_
#define _BIG_BACKGROUND_EFFECT_H_
#include "cocos2d.h"
namespace bubble_second {
    class BigBackgroundEffect : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BigBackgroundEffect);
        BigBackgroundEffect();
        ~BigBackgroundEffect();
    private:
        bool init();
        void playBackgroundEffect();
        void playEffect();
        void playPointEffect();
    };
}
#endif //_BIG_BACKGROUND_EFFECT_H_