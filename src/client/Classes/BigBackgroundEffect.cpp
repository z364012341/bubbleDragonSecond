#include "BigBackgroundEffect.h"
#include "SpriteTextureController.h"

namespace bubble_second {
    BigBackgroundEffect::BigBackgroundEffect()
    {
    }


    BigBackgroundEffect::~BigBackgroundEffect()
    {
    }

    bool BigBackgroundEffect::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        //auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        //cocos2d::LayerColor* layer_color = cocos2d::LayerColor::create(cocos2d::Color4B(40, 143, 212, 255), visible_size.width, visible_size.height);
        //this->addChild(layer_color, -1);
        this->playBackgroundEffect();
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(BIG_BACKGROUND_EFFECT_TIME), cocos2d::CallFunc::create([=]() {this->removeFromParent(); })));
        return true;
    }

    void BigBackgroundEffect::playBackgroundEffect()
    {
        auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        cocos2d::LayerColor* layer_color = cocos2d::LayerColor::create(BIG_BACKGROUND_EFFECT_BLACK_COLOR, visible_size.width, visible_size.height);
        this->addChild(layer_color, BIG_BACKGROUND_EFFECT_BLACK_ZORDER);
        cocos2d::FadeOut* fade = cocos2d::FadeOut::create(1);
        fade->setTag(BIG_BACKGROUND_EFFECT_BLACK_FADE_TAG);
        layer_color->runAction(fade);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(cocos2d::DelayTime::create(BIG_BACKGROUND_EFFECT_BLACK_TO_WHITE_TIME), cocos2d::CallFunc::create([=]() {
            layer_color->stopActionByTag(BIG_BACKGROUND_EFFECT_BLACK_FADE_TAG);
            layer_color->setColor(cocos2d::Color3B::WHITE);
            layer_color->setOpacity(TEXTURE_OPACITY);
        }), cocos2d::DelayTime::create(BIG_BACKGROUND_EFFECT_BLACK_TO_WHITE_TIME), cocos2d::CallFunc::create([=]() {
            layer_color->removeFromParent();
            this->playEffect();
            this->playPointEffect();
        }), nullptr);
        layer_color->runAction(seq);
    }

    void BigBackgroundEffect::playEffect()
    {
        auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        cocos2d::LayerColor* layer_color = cocos2d::LayerColor::create(BIG_BACKGROUND_EFFECT_BLUE_COLOR, visible_size.width, visible_size.height);
        this->addChild(layer_color, -1);
        cocos2d::BlendFunc bf = { GL_SRC_ALPHA , GL_SRC_ALPHA };
        auto small_blue_func = [=](float original_x, float move_x) {
            float x = original_x;//³õÊ¼µÄx×ø±ê
            for (int i = 0; i < 5; i++)
            {
                float width = RANDOM_DECIMALS(1, 40);
                cocos2d::LayerColor* layer = cocos2d::LayerColor::create(BIG_BACKGROUND_EFFECT_SMALL_BLUE_COLOR, width, visible_size.height);
                x = x + cocos2d::random(BIG_BACKGROUND_EFFECT_SMALL_BLUE_MIN_WIDTH, BIG_BACKGROUND_EFFECT_SMALL_BLUE_MAX_WIDTH);
                layer->setPosition(x, 0.0f);
                layer->setBlendFunc(bf);
                this->addChild(layer);
                float time = RANDOM_DECIMALS(1, 5);
                cocos2d::MoveBy* move = cocos2d::MoveBy::create(time, cocos2d::Vec2(move_x, 0));
                cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(move, cocos2d::CallFunc::create([=]() { layer->removeFromParent(); }));
                layer->runAction(seq);
            }
        };
        small_blue_func(BIG_BACKGROUND_EFFECT_LEFT_TO_RIGHT_POSX, BIG_BACKGROUND_EFFECT_LEFT_TO_RIGHT_MOVE_X);
        small_blue_func(BIG_BACKGROUND_EFFECT_RIGHT_TO_LEFT_POSX, BIG_BACKGROUND_EFFECT_RIGHT_TO_LEFT_MOVE_X);
    }

    void BigBackgroundEffect::playPointEffect()
    {
        cocos2d::CallFunc* call_func = cocos2d::CallFunc::create([=]()
        {
            cocos2d::Sprite* point = SpriteTextureController::getInstance()->createGameSpriteWithPath(BIG_BLUE_BACKGROUND_EFFECT_POINT_PATH);
            auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
            int x = cocos2d::random(0, (int)visible_size.width);
            //int y = cocos2d::random(-100, 0);
            point->setPosition(x, 0);
            this->addChild(point);
            float time = RANDOM_DECIMALS(0, 1);
            cocos2d::MoveBy* move = cocos2d::MoveBy::create(time, cocos2d::Vec2(0, visible_size.height));
            cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(move, cocos2d::CallFunc::create([=]() {
                point->removeFromParent();
            }));
            point->runAction(seq);
        });
        cocos2d::Sequence* sequence = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.1f), call_func);
        this->runAction(cocos2d::RepeatForever::create(sequence));
    }
}