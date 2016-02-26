#include "GameBubbleMap.h"
#include "ColorBubble.h"
#include "StageDataManager.h"
#include "StageDataModule.h"
#include "GamePlayController.h"
#include "BlackHoleBubble.h"
#include "RainbowSealBubble.h"
#include "BubbleComponent.h"
#include "GameScoreController.h"
#include "BubbleColorRender.h"
#include "GameScoreController.h"
#include "StartNumbleModule.h"
namespace bubble_second {
    GameBubbleMap::GameBubbleMap()
    {
        //this->initBubbleSpriteVetctor(stage_str);
        //this->init();
    }

    GameBubbleMap::~GameBubbleMap()
    {
        if (game_bubble_map_impl_)
        {
            delete game_bubble_map_impl_;
            game_bubble_map_impl_ = nullptr;
        }
    }

    bool GameBubbleMap::init()
    {
        game_bubble_map_impl_ = new GameBubbleMapImple();
        type_to_disposed_[kBubbleLightning] = [=](const cocos2d::Vec2& buff_index) {
            return this->disposeContactLightningBubble(buff_index); 
        };

        type_to_disposed_[kBubbleBombBomb] = [=](const cocos2d::Vec2& buff_index) {
            return this->disposeContactBombBombBubble(buff_index); 
        };

        type_to_disposed_[kBubbleColorBomb] = [=](const cocos2d::Vec2& bomb_index) {
            return this->disposeColorBombBubble(bomb_index);
        };

        type_to_disposed_[kBubbleBombBombProperty] = [=](const cocos2d::Vec2& bomb_index) {
            return this->disposeBombPropertyBubble(bomb_index);
        };

        type_to_disposed_[kBubbleAddNumbleBubble] = [=](const cocos2d::Vec2& buff_index) {
            BubbleVector vector(1);
            vector.pushBack(game_bubble_map_impl_->getSpriteWithIndex(buff_index));
            return vector;
        };

        type_to_disposed_[kBubbleComponent] = [=](const cocos2d::Vec2& component_index) {
            BubbleComponent* bubble = dynamic_cast<BubbleComponent*>(game_bubble_map_impl_->getSpriteWithIndex(component_index));
            BaseComponentBubble* core_bubble = dynamic_cast<BaseComponentBubble*>(bubble->getCoreBubble());
            return core_bubble->getTotalBubbles();
        };

        auto seal_func = [=](const cocos2d::Vec2& seal_index) {
            BaseComponentBubble* core_bubble = dynamic_cast<BaseComponentBubble*>(game_bubble_map_impl_->getSpriteWithIndex(seal_index));
            return core_bubble->getTotalBubbles();
        };

        type_to_disposed_[kBubbleRainbowSeal] = seal_func;

        type_to_disposed_[kBubbleMutipleSeal] = seal_func;

        type_to_complete_handle_[kTopEliminate] = [=]() {
            int null_bubble_numble = game_bubble_map_impl_->getTopRowNullBubbleNumble();
            GameScoreController::getInstance()->setCompletedTaskNumble(null_bubble_numble<= TOP_ELIMINATE_GAME_TASK_NUMBLE ? null_bubble_numble : TOP_ELIMINATE_GAME_TASK_NUMBLE);
            return false;
        };

        type_to_complete_handle_[kWindmill] = [=]() {
            BubbleVector vector = game_bubble_map_impl_->getAllBubblesFromMap();
            if (vector.size() <= 1)
            {
                this->eliminateBubbles(vector);
                return true;
            }
            return false;
        };

        return true;
    }

    void GameBubbleMap::disposeContactBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index)
    {
        this->runBubbleEffect(prepare_bubble, contact_index);
        this->disposeWindmillRotation(prepare_bubble);
        //先粘附上去, 然后再进行消除判断
        BaseBubble* prepare_after_cling_bubble = game_bubble_map_impl_->clingBubble(prepare_bubble, contact_index);
        BubbleVector same_bubble_map = game_bubble_map_impl_->getSametypeBubbleWithIndex(prepare_after_cling_bubble->getBubbleIndex());
        if (this->canEliminate(same_bubble_map))
        {
            game_bubble_map_impl_->removeSpriteFromeMapWithIndex(prepare_after_cling_bubble->getBubbleIndex());
            same_bubble_map.eraseObject(prepare_after_cling_bubble);
            this->disposeRainbowSealBubble(prepare_after_cling_bubble);
            this->eliminateBubbles(same_bubble_map, prepare_bubble, BUBBLE_ELIMINATE_DELAY_TIME);
            this->disposeAroundBuffBubble(prepare_after_cling_bubble->getBubbleIndex());
            this->dispatchAddEliminateComboEvent(prepare_after_cling_bubble->getPosition());
        } //(same_bubble_map.size() >= 2)
        else
        {
            this->disposeDarkCloudBubble(prepare_after_cling_bubble->getBubbleIndex());
            this->disposeClingBubble(prepare_bubble, prepare_after_cling_bubble);
            this->disposeAfterClinging(prepare_after_cling_bubble);
        }
    }

    void GameBubbleMap::disposeClingBubble(BaseBubble* prepare_bubble, BaseBubble* cling_bubble)
    {
        BubbleVector bubble_vector;
        bubble_vector.pushBack(prepare_bubble);
        bubble_vector.pushBack(cling_bubble);
        this->dispatchCustomEvent(EVENT_BUBBLE_CLING, &bubble_vector);
    }

    bool GameBubbleMap::canEliminate(const BubbleVector& vector)
    {
        return vector.size() >= 3;
    }

    //void GameBubbleMap::setStageType(const StageType & type)
    //{
    //    stage_type_ = type;
    //}

    //StageType GameBubbleMap::getStageType()
    //{
    //    return stage_type_;
    //}

    //bool GameBubbleMap::isWindmillStage()
    //{
    //    return this->getStageType() == kWindmill;
    //}

    Empty GameBubbleMap::disposeRainbowSealBubble(BaseBubble* prepare_bubble)
    {
        BubbleVector components = game_bubble_map_impl_->getAroundComponentBubbleWithIndex(prepare_bubble->getBubbleIndex());
        if (components.empty())
        {
            return true;
        }
        BubbleVector vector(0);
        BubbleVector repeat_vector(0);
        for (auto var : components)
        {
            if (var->isEqualType(kBubbleComponent))
            {
                BubbleComponent* bubble = dynamic_cast<BubbleComponent*>(var);
                RainbowSealBubble* core_bubble = dynamic_cast<RainbowSealBubble*>(bubble->getCoreBubble());
                if (core_bubble && !game_bubble_map_impl_->isExistInVector(repeat_vector, core_bubble))
                {
                    BubbleVector dispose_vector = core_bubble->disposeRainbowSeal(prepare_bubble->getBubbleType());
                    repeat_vector.pushBack(core_bubble);
                    if (dispose_vector.empty())
                    {
                        continue;
                    }
                    game_bubble_map_impl_->mergeTwoBubbleVector(&vector, dispose_vector);
                }
            } //if (var->getBubbleType
        }
        if (vector.empty())
        {
            return true;
        }
        this->eliminateBubbles(vector);
        return false;
    }

    BubbleVector GameBubbleMap::disposeContactLightningBubble(const cocos2d::Vec2& buff_index)
    {
        auto row_vector = game_bubble_map_impl_->getSameRowBubblesWithIndex(buff_index);
        return row_vector;
    }

    void GameBubbleMap::runBubbleEffect(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index)
    {
        //播放撞击动画
        BubbleVectorMap effect_bubbles = game_bubble_map_impl_->getEffectBubbles(prepare_bubble, contact_index);
        //assert(effect_bubbles.size() != 0);
        if (effect_bubbles.size() != 0)
        {
            this->dispatchCustomEvent(EVENT_BUBBLE_RUN_EFFECT, &effect_bubbles);
        }
    }

    void GameBubbleMap::eliminateBubbles(BubbleVector same_bubbles, BaseBubble* prepare_bubble, float delay_time)
    {
        game_bubble_map_impl_->removeSpriteFromeMap(same_bubbles);
        //注释原因: 暂时改为道具球炸到黑洞直接消除
        //for (auto iter = same_bubbles.begin(); iter != same_bubbles.end();)
        //{
        //    if ((*iter)->needRemoveFromBubbleMap())
        //    {
        //        game_bubble_map_impl_->removeSpriteFromeMapWithIndex((*iter)->getBubbleIndex());
        //        ++iter;
        //    }
        //    else
        //    {
        //        iter = same_bubbles.erase(iter);
        //    }
        //}
        if (prepare_bubble)
        {
            same_bubbles.insert(0, prepare_bubble);
        }
        if (same_bubbles.empty())
        {
            this->dispatchCustomEvent(EVENT_BUBBLE_ELIMINATED, &same_bubbles);
            return;
        }
        this->disposeEliminateHandle(&same_bubbles, delay_time);
        this->dispatchCustomEvent(EVENT_BUBBLE_ELIMINATED, &same_bubbles);
    }

    void GameBubbleMap::disposeEliminateHandle(BubbleVector* same_bubbles, float delay_time)
    {
        float percent = 1 / same_bubbles->size();
        float time = 1;
        for (auto iter = same_bubbles->begin(); iter != same_bubbles->end();)
        {
            if ((*iter)->isEqualType(kBubbleNull))
            {
                iter = same_bubbles->erase(iter);
            }
            else
            {
                (*iter)->setEliminateDelayTime(delay_time*(time - percent));
                time = time - percent;
                if (!(*iter)->getPhysicsBody())
                {
                    iter++;
                    continue;
                }
                (*iter)->getPhysicsBody()->removeFromWorld();
                //(*iter)->setPhysicsBody(nullptr);
                game_bubble_map_impl_->disposeRemoveSuspensionPoint(*iter);
                iter++;
            }

        }
    }

    void bubble_second::GameBubbleMap::disposeContactBlackHoleBubble(BaseBubble * flying_bubble, BaseBubble * blackhole_bubble)
    {
        if (BlackHoleBubble* black_bubble = dynamic_cast<BlackHoleBubble*>(blackhole_bubble))
        {
            black_bubble->swallowBubble(flying_bubble);
            if (black_bubble->isNeedEliminate())
            {
                game_bubble_map_impl_->removeSpriteFromeMapWithIndex(black_bubble->getBubbleIndex());
                this->checkAirBubbles();
            }
            this->dispatchCustomEvent(EVENT_CUT_ELIMINATE_COMBO);
        }
    }

    BubbleVector GameBubbleMap::disposeContactBombBombBubble(const cocos2d::Vec2& buff_index)
    {
        BubbleVector around_bubble = game_bubble_map_impl_->getAroundBubbleWithIndex(buff_index);
        around_bubble.pushBack(game_bubble_map_impl_->getSpriteWithIndex(buff_index));
        return around_bubble;
    }

    Empty GameBubbleMap::disposeAroundBuffBubble(const cocos2d::Vec2& cling_index)
    {
        BubbleVector around_bubble = game_bubble_map_impl_->getAroundBubbleExceptComponentWithIndex(cling_index);
        BubbleVector local_bubbles = this->disposeBuffBubble(around_bubble);
        if (local_bubbles.empty())
        {
            return true;
        }
        else
        {
            this->eliminateBubbles(local_bubbles);
            return false;
        }
    }

    BubbleVector GameBubbleMap::disposeBuffBubble(BubbleVector vector)
    {
        std::vector<BubbleVector> local_vector;
        local_vector.push_back(vector);
        local_vector.push_back(BubbleVector(0));
        for (int i = 0; i != local_vector.size(); ++i)
        {
            for (int j = 0; j != local_vector.at(i).size(); ++j)
            {
                BaseBubble* bubble = local_vector.at(i).at(j);
                //auto disposed_handle = type_to_disposed_[bubble->getBubbleType()];
                if (auto disposed_handle = type_to_disposed_[bubble->getBubbleType()])
                {
                    game_bubble_map_impl_->mergeTwoBubbleVector(&local_vector.at(1), disposed_handle(bubble->getBubbleIndex()));
                } //if (disposed_handle)
            } //for (int j
        } //for (int i
        return local_vector.at(1);
    }

    void GameBubbleMap::dispatchAddEliminateComboEvent(cocos2d::Vec2 prepare_point)
    {
        this->dispatchCustomEvent(EVENT_ADD_ELIMINATE_COMBO, &prepare_point);
    }

    void GameBubbleMap::dispatchCustomEvent(const std::string& eventName, void* userData)
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(eventName, userData);
    }

    void GameBubbleMap::adjustGameScenePosition()
    {
        if (game_bubble_map_impl_->isWindmillStage())
        {
            return;
        }
        
        float min_pos = game_bubble_map_impl_->getBubblesMinPosition();
        if (game_bubble_map_impl_->isFallStage())
        {
            this->dispatchCustomEvent(EVENT_FALL_STAGE_ADJUST_MAP_POSITION, &min_pos);
        }
        else
        {
            this->dispatchCustomEvent(EVENT_ADJUST_MAP_POSITION, &min_pos);
        }
    }

    void GameBubbleMap::findBubblesInVisibleSize()
    {
        BubbleVector bubbles = getBubbleInVisibleSize();
        this->dispatchCustomEvent(EVENT_FIND_BUBBLES_IN_VISIBLESIZE, &bubbles);
    }

    void GameBubbleMap::checkAirBubbles()
    {
        BubbleVector air_vector = game_bubble_map_impl_->disposeAirBubbleAfterEliminate();
        this->dispatchCustomEvent(EVENT_BUBBLE_Air, &air_vector);
        this->disposeCompletedTaskNumble();
    } 

    void GameBubbleMap::disposeBuffBubbleDown(BaseBubble* buff_bubble)
    {
        BubbleVector vector = type_to_disposed_[buff_bubble->getBubbleType()](buff_bubble->getBubbleIndex());
        vector.pushBack(this->disposeBuffBubble(vector));//因为这个泡泡是掉在空中的, 已经从地图里面删除, 所以要手动加进去
        this->eliminateBubbles(vector);
    }

    void GameBubbleMap::disposeDarkCloudBubble(const cocos2d::Vec2& contact_index)
    {
        cocos2d::Vector<ColorBubble*> vector = game_bubble_map_impl_->getAroundDarkCloudBubbleWithIndex(contact_index);
        this->dispatchCustomEvent(EVENT_DESTROY_BUBBLE_CLOUD, &vector);
    }

    BubbleVector GameBubbleMap::disposeColorBombBubble(const cocos2d::Vec2& colorbomb_index)
    {
        BubbleVector around_bubbles = game_bubble_map_impl_->getAroundBubbleWithIndex(colorbomb_index);
        BubbleVector around_Color_bubbles = game_bubble_map_impl_->getAroundColorBubblesWithIndex(colorbomb_index);
        BubbleVector eliminate_bubbles(around_bubbles);
        for (auto var_1 : around_Color_bubbles)
        {
            BubbleVector same_bubbles = game_bubble_map_impl_->getSametypeBubbleWithIndex(var_1->getBubbleIndex());
            if (same_bubbles.size() >=2)
            {
                game_bubble_map_impl_->mergeTwoBubbleVector(&eliminate_bubbles, same_bubbles);
            }
        }
        eliminate_bubbles.pushBack(game_bubble_map_impl_->getSpriteWithIndex(colorbomb_index));
        return eliminate_bubbles;
    }

    void GameBubbleMap::disposeUsedPropertyBubble(BaseBubble* property_bubble, const cocos2d::Vec2& contact_index)
    {
        this->runBubbleEffect(property_bubble, contact_index);
        this->disposeWindmillRotation(property_bubble);
        BaseBubble* bubble = game_bubble_map_impl_->clingBubble(property_bubble, contact_index);
        auto handle = type_to_disposed_[bubble->getBubbleType()];
        if (!handle)
        {
            return;
        }
        BubbleVector eliminate_bubbles = handle(bubble->getBubbleIndex());
        BubbleVector after_buff_bubbles = this->disposeBuffBubble(eliminate_bubbles);
        cocos2d::Vec2 cling_index = bubble->getBubbleIndex();
        cocos2d::Vec2 cling_point = bubble->getPosition();
        after_buff_bubbles.eraseObject(bubble);
        game_bubble_map_impl_->removeSpriteFromeMapWithIndex(cling_index);
        this->eliminateBubbles(after_buff_bubbles, property_bubble, BUBBLE_ELIMINATE_DELAY_TIME);
        this->dispatchAddEliminateComboEvent(cling_point);
    }

    BubbleVector GameBubbleMap::disposeBombPropertyBubble(const cocos2d::Vec2& bomb_index)
    {
        BubbleVector eliminate_bubbles = game_bubble_map_impl_->getTwoAroundBubbleWithIndex(bomb_index);
        eliminate_bubbles.pushBack(game_bubble_map_impl_->getSpriteWithIndex(bomb_index));
        return eliminate_bubbles;
    }

    void GameBubbleMap::disposeUseWoodenHammer(BaseBubble* bubble)
    {
        BubbleVector vector(1);
        cocos2d::Vec2 bubble_point = bubble->getPosition();
        auto handle = type_to_disposed_[bubble->getBubbleType()];
        if (handle)
        {
            vector = handle(bubble->getBubbleIndex());
            this->eliminateBubbles(this->disposeBuffBubble(vector));
            this->dispatchAddEliminateComboEvent(bubble_point);
            return;
        }
        vector.pushBack(bubble);
        this->eliminateBubbles(vector);
        this->dispatchAddEliminateComboEvent(bubble_point);
    }

    void GameBubbleMap::disposeUseStaves(BaseBubble* bubble)
    {
        BubbleVector bubbles = game_bubble_map_impl_->getBubblesInVisibleSize();
        BubbleType color = bubble->getBubbleType();
        cocos2d::Vec2 bubble_point = bubble->getPosition();
        for (auto iter = bubbles.begin(); iter < bubbles.end(); )
        {
            if (color != (*iter)->getBubbleType())
            {
                iter = bubbles.erase(iter);
                continue;
            }
            ++iter;
        }
        this->dispatchAddEliminateComboEvent(bubble_point);
        this->eliminateBubbles(bubbles);  
    }

    void GameBubbleMap::disposeCompletedTaskNumble()
    {
        auto handle = type_to_complete_handle_[game_bubble_map_impl_->getStageType()];
        if (handle && handle())
        {
            return;
        }
        disposeGameDefeat();
    }

    void GameBubbleMap::loadStageDataWithNumble(int numble)
    {
        StageDataModule* data = StageDataManager::getInstance()->getStageDataWithNumble(numble);
        game_bubble_map_impl_->setStageType(data->getStageType());
        game_bubble_map_impl_->setFallFlag(data->isFallType());
        GameScoreController::getInstance()->setBubbleUseCount(data->getBubbleNumbleMax());
        BubbleColorRender* render = new BubbleColorRender(data->getBubbleColorRange());
        BubbleSpriteMap bubble_map = game_bubble_map_impl_->initBubbleSpriteVetctor(render, data->getBubblesData(), game_bubble_map_impl_->getStageType());
        if (game_bubble_map_impl_->isWindmillStage())
        {
            this->dispatchCustomEvent(EVENT_WINDMILL_MAP_BORDER_LOADED);
        }
        else if (game_bubble_map_impl_->isFallStage())
        {
            this->dispatchCustomEvent(EVENT_FALL_MAP_BORDER_LOADED);
        }
        this->adjustGameScenePosition();
        this->dispatchCustomEvent(EVENT_MAP_LOADED, &bubble_map);
        StartNumbleModule start_numbles = data->getStartNumble();
        this->dispatchCustomEvent(EVENT_INITIAL_START_NUMBLES, &start_numbles);
        CC_SAFE_DELETE(render);
    }

    void GameBubbleMap::disposeGameVictory()
    {
        BubbleVector vector = game_bubble_map_impl_->getAllBubblesFromMap();
        this->dispatchCustomEvent(EVENT_BUBBLE_Air, &vector);
    }

    void GameBubbleMap::disposeGameDefeat()
    {
        if (GameScoreController::getInstance()->gameDefeat())
        {
            this->dispatchCustomEvent(EVENT_GAME_DEFEAT);
        }
    }

    void GameBubbleMap::disposeWindmillBubbleContactBorder(BaseBubble* bubble)
    {
        game_bubble_map_impl_->removeSpriteFromeMapWithIndex(bubble->getBubbleIndex());
        dynamic_cast<ColorBubble*>(bubble)->playEliminateEffect();
        this->disposeCompletedTaskNumble();
        if (bubble->getName() == PREPARE_BUBBLE_NAME)
        {
            this->dispatchCustomEvent(EVENT_CAN_USED_PROPS);
        }
    }

    void GameBubbleMap::disposeWindmillRotation(BaseBubble * prepare_bubble)
    {
        if (game_bubble_map_impl_->isWindmillStage())
        {
            float angle = game_bubble_map_impl_->getWindmillRotationAngle(prepare_bubble);
            this->dispatchCustomEvent(EVENT_WINDMILL_ROTATION, &angle);
        }
    }

    void GameBubbleMap::disposeAfterClinging(BaseBubble * prepare_after_cling_bubble)
    {
        Empty rainbow_empty = this->disposeRainbowSealBubble(prepare_after_cling_bubble);
        Empty buff_empty = this->disposeAroundBuffBubble(prepare_after_cling_bubble->getBubbleIndex());
        if (buff_empty && rainbow_empty)
        {
            this->disposeCompletedTaskNumble();
            this->dispatchCustomEvent(EVENT_CUT_ELIMINATE_COMBO);
            this->adjustGameScenePosition();
        }
        else
        {
            this->dispatchAddEliminateComboEvent(prepare_after_cling_bubble->getPosition());
        }
    }

    BubbleVector GameBubbleMap::getBubbleInVisibleSize()
    {
        BubbleVector bubbles(0);
        if (!game_bubble_map_impl_->isWindmillStage())
        {
            bubbles = game_bubble_map_impl_->getBubblesInVisibleSize();
        }
        else
        {
            bubbles = game_bubble_map_impl_->getAllBubblesFromMap();
        }                                                                          
        return bubbles;
    }

    void GameBubbleMap::disposeUsedAddSpecialBubbleProps()
    {
        BubbleVector bubbles = getBubbleInVisibleSize();
        for (auto iter = bubbles.begin(); iter < bubbles.end();)
        {
            if (!(*iter)->isColorBubbleType())
            {
                iter = bubbles.erase(iter);
            }
            else
            {
                iter++;
            }
        }
        std::random_shuffle(bubbles.begin(), bubbles.end());
        BubbleVector three_bubble(3);
        for (int i = 0; i < bubbles.size() && i<3; i++)
        {
            three_bubble.pushBack(bubbles.at(i));
        }
        this->dispatchCustomEvent(EVENT_FIND_THREE_BUBBLE, &three_bubble);
    }

}