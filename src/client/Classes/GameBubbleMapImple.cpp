#include "GameBubbleMapImple.h"
#include "XMLTool.h"
#include "ColorBubble.h"
#include "BubbleFactory.h"
#include "GameScene.h"
#include "BaseComponentBubble.h"
#include "BubbleComponent.h"
#include "GameScoreController.h"
#include "StageDataManager.h"
#include "BubbleColorRender.h"
namespace bubble_second{
    GameBubbleMapImple::GameBubbleMapImple():special_bubble_(nullptr)
    {
        auto top_suspension_func = [=]() {
            cocos2d::Map<int, BaseBubble*> sprite_map;
            for (int i = 0; i != MAP_ODD_ROW_MAX; i++)
            {
                BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(kBubbleNull,
                    cocos2d::Vec2(MAP_TOP_ROW_INDEX, i),
                    this->convertIndexToPoint(cocos2d::Vec2(MAP_TOP_ROW_INDEX, i)));
                sprite_map.insert(i, bubble);
                this->addSuspensionPointToVector(bubble);
            }
            bubble_sprite_map_[MAP_TOP_ROW_INDEX] = sprite_map;
        };
        stagetype_to_handle_[kTopEliminate] = [=]() {
            top_suspension_func();
            GameScoreController::getInstance()->setGameTaskNumble(TOP_ELIMINATE_GAME_TASK_NUMBLE);
        };
        stagetype_to_handle_[kRescueAnimal] = [=]() {
            top_suspension_func();
        };
        stagetype_to_handle_[kDestroyRainbowSeal] = [=]() {
            top_suspension_func();
        };
        stagetype_to_handle_[kWindmill] = [=]() {
            this->setSpecialBubble();
        };
    }

    GameBubbleMapImple::~GameBubbleMapImple()
    {
    }

    BubbleSpriteMap GameBubbleMapImple::initBubbleSpriteVetctor(BubbleColorRender* render, const BubblesData& stage_info, const StageType& stage_type)
    {
        BaseBubble* bubble = nullptr;
        for (auto var: stage_info)
        {
            bubble = this->convertBubbleDataToBubble(render, var);
            if (bubble)
            {
                this->addBubbleToBubbleMap(bubble);
                if (bubble->getBubbleComponentNumble() != 0)
                {
                    this->addBubbleComponentByBubble(bubble);
                }
                this->disposeAddSuspensionPoint(bubble);
            }
        }
        this->stageTypeFunc(stage_type);
        return bubble_sprite_map_;        
    }

    void GameBubbleMapImple::stageTypeFunc(const StageType& stage_type)
    {
        //auto handle = stagetype_to_handle_[stage_type];
        if (auto handle = stagetype_to_handle_[stage_type])
        {
            handle();
        }
    }

    BaseBubble* GameBubbleMapImple::convertBubbleDataToBubble(BubbleColorRender* render, const BubbleInfo& info)
    {
        XMLTool* tool= new XMLTool;
        int type = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_BUBBLETYPE));
        type = render->getRandomColorWithColor((BubbleType)type);
        int row = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_ROW));
        int col = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_COL));
        int cloud = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_CLOUD));
        BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(type, cocos2d::Vec2(row, col),
            this->convertIndexToPoint(cocos2d::Vec2(row, col)), cloud);
        CC_SAFE_DELETE(tool);
        return bubble;
    }

    void GameBubbleMapImple::disposeAddSuspensionPoint(BaseBubble* bubble)
    {
        if (bubble->isSuspensionPoint())
        {
            this->addSuspensionPointToVector(bubble);
        }
    }

    void GameBubbleMapImple::disposeRemoveSuspensionPoint(BaseBubble* bubble)
    {
        if (bubble->isSuspensionPoint())
        {
            this->removeSuspensionPointFromVector(bubble);
        }
    }

    void GameBubbleMapImple::addSuspensionPointToVector(BaseBubble* bubble)
    {
        suspension_points_.pushBack(bubble);
    }

    void GameBubbleMapImple::removeSuspensionPointFromVector(BaseBubble* bubble)
    {
        suspension_points_.eraseObject(bubble);
    }

    cocos2d::Vec2 GameBubbleMapImple::convertIndexToPoint(const cocos2d::Vec2& index)
    {
        int row = index.x;
        int col = index.y;
        float posX = (abs(row) % 2 + 1) * (MAP_BUBBLE_RADIUS)+col * MAP_BUBBLE_RADIUS * 2;
        float posY = 0 - MAP_BUBBLE_RADIUS - row * (MAP_BUBBLE_RADIUS  * SQRT3);
        return cocos2d::Vec2(posX, posY);
    }

    BubbleIndexVector GameBubbleMapImple::getAroundIndexWithIndex(const cocos2d::Vec2& index)
    {
        if (isWindmillStage())
        {
            return getAroundIndexWithIndexWithoutCondition(index);
        }
        using cocos2d::Vec2;
        BubbleIndexVector index_vector;
        int special = abs((int)index.x % 2);
        if (special != 0 || index.y != 0.0f)
        {
            index_vector.push_back(Vec2(index.x - 1, index.y + (special - 1)));//左上
            if (special != 1 || index.y != 0.0f)
            {
                index_vector.push_back(Vec2(index.x, index.y - 1));//左
            }
            index_vector.push_back(Vec2(index.x + 1, index.y + (special - 1)));//左下
        }

        if (special != 0 || index.y != MAP_EVEN_ROW_MAX - 1)
        {
            index_vector.push_back(Vec2(index.x + 1, index.y + special));//右下
            if (special != 1 || index.y != MAP_ODD_ROW_MAX - 1)
            {
                index_vector.push_back(Vec2(index.x, index.y + 1));//右
            }
            index_vector.push_back(Vec2(index.x - 1, index.y + special));//右上
        }
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getAroundIndexWithIndexWithoutCondition(const cocos2d::Vec2 & index)
    {
        using cocos2d::Vec2;
        BubbleIndexVector index_vector;
        int special = abs((int)index.x % 2);
        index_vector.push_back(Vec2(index.x - 1, index.y + (special - 1)));//左上
        index_vector.push_back(Vec2(index.x, index.y - 1));//左
        index_vector.push_back(Vec2(index.x + 1, index.y + (special - 1)));//左下
        index_vector.push_back(Vec2(index.x + 1, index.y + special));//右下
        index_vector.push_back(Vec2(index.x, index.y + 1));//右
        index_vector.push_back(Vec2(index.x - 1, index.y + special));//右上
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getSecondAroundIndexWithIndex(const cocos2d::Vec2& index)
    {
        using cocos2d::Vec2;
        int special = abs((int)index.x % 2);
        BubbleIndexVector index_vector;
        index_vector.push_back(Vec2(index.x - 2, index.y - 1)); //左上左上
        index_vector.push_back(Vec2(index.x - 1, index.y - 2 + special)); //左上左
        index_vector.push_back(Vec2(index.x, index.y - 2)); //左左
        index_vector.push_back(Vec2(index.x+1, index.y - 2 + special)); //左左下
        index_vector.push_back(Vec2(index.x + 2, index.y - 1)); //左下左下
        index_vector.push_back(Vec2(index.x + 2, index.y)); //下下
        index_vector.push_back(Vec2(index.x + 2, index.y + 1)); //右下右下
        index_vector.push_back(Vec2(index.x + 1, index.y + 1 + special)); //右下右
        index_vector.push_back(Vec2(index.x, index.y + 2)); //右右
        index_vector.push_back(Vec2(index.x - 1, index.y + 1 + special)); //右上右
        index_vector.push_back(Vec2(index.x - 2, index.y + 1)); //右上右上
        index_vector.push_back(Vec2(index.x - 2, index.y)); //右右
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getUnderTwoIndexByIndex(const cocos2d::Vec2& index)
    {
        using cocos2d::Vec2;
        BubbleIndexVector index_vector;
        int special = abs((int)index.x % 2);
        if (special != 0 || index.y != 0.0)
        {
            index_vector.push_back(Vec2(index.x + 1, index.y + (special - 1)));//左下
        }
        if (special != 0 || index.y != MAP_EVEN_ROW_MAX - 1)
        {
            index_vector.push_back(Vec2(index.x + 1, index.y + special));//右下
        }
        return index_vector;
    }

    cocos2d::Vec2 GameBubbleMapImple::convertGameSceneCsbToMapSpaceWithBubble(cocos2d::Node* bubble)
    {
        GameScene* gamescene = dynamic_cast<GameScene*>(bubble->getParent()->getParent());
        return gamescene->convertCsbToMapSpace(bubble->getPosition());
    }

    cocos2d::Vec2 GameBubbleMapImple::convertGameSceneMapToCsbSpaceWithBubble(cocos2d::Node* bubble)
    {
        GameScene* gamescene = dynamic_cast<GameScene*>(bubble->getParent()->getParent()->getParent());
        return gamescene->convertMapToCsbSpace(bubble->getPosition());
    }

    BubbleIndexVector GameBubbleMapImple::getComponentIndexByIndexAndNumble(const cocos2d::Vec2& index, int numble)
    {
        BubbleIndexVector index_vector(0);
        switch (numble)
        {
        case 2:
            index_vector = this->getUnderTwoIndexByIndex(index);
            break;
        case 6:
            index_vector = this->getAroundIndexWithIndex(index);
            break;
        default:
            assert(false);
            break;
        }
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getTwoAroundIndexWithIndex(const cocos2d::Vec2& index)
    {
        using cocos2d::Vec2;
        BubbleIndexVector first_vector = this->getAroundIndexWithIndex(index);
        //std::vector<Vec2> second_vector = this->getSecondAroundIndexWithIndex(index);
        for (auto var : this->getSecondAroundIndexWithIndex(index))
        {
            first_vector.push_back(var);
        }
        return first_vector;
    }

    BubbleVector GameBubbleMapImple::getAroundBubbleWithIndex(const cocos2d::Vec2& index)
    {
        return this->getBubbleVectorWithIndexVector(this->getAroundIndexWithIndex(index));
    }

    BubbleVector GameBubbleMapImple::getAroundBubbleExceptComponentWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector vector = this->getAroundBubbleWithIndex(index);
        for (auto iter = vector.begin(); iter < vector.end();)
        {
            if ((*iter)->isComponentBubbleType())
            {
                iter = vector.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        return vector;
    }

    BubbleVector GameBubbleMapImple::getAroundComponentBubbleWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector vector = this->getAroundBubbleWithIndex(index);
        for (auto iter = vector.begin(); iter < vector.end();)
        {
            if (!(*iter)->isComponentBubbleType())
            {
                iter = vector.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        return vector;
    }

    BubbleVector GameBubbleMapImple::getTwoAroundBubbleWithIndex(const cocos2d::Vec2 & index)
    {
        return this->getBubbleVectorWithIndexVector(this->getTwoAroundIndexWithIndex(index));
    }

    BubbleVector GameBubbleMapImple::getAroundColorBubblesWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector around_color_bubble;
        for (auto var : this->getAroundBubbleWithIndex(index))
        {
            if (var->isColorBubbleType() || var->isEqualType(kBubbleBlackHole))
            {
                around_color_bubble.pushBack(var);
            }
        }
        return around_color_bubble;
    }

    BubbleVector GameBubbleMapImple::getAroundSametypeBubbleWithIndexAndType(const cocos2d::Vec2& index)
    {
        BubbleVector same_bubble_vector;
        BaseBubble* bubble = this->getSpriteWithIndex(index);
        for (auto iter : this->getAroundBubbleWithIndex(index))
        {
            if (bubble->isEqualType(iter->getBubbleType()))
            {
                same_bubble_vector.pushBack(iter);
            }
        }
        return same_bubble_vector;
    }

    BubbleVector GameBubbleMapImple::getSametypeBubbleWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector same_vector;
        same_vector.pushBack(this->getSpriteWithIndex(index));
        this->traverseBubbles(&same_vector, CC_CALLBACK_1(GameBubbleMapImple::getAroundSametypeBubbleWithIndexAndType, this));
        return same_vector;
    }

    BaseBubble* GameBubbleMapImple::getSpriteWithIndex(const cocos2d::Vec2& index)
    {
        return bubble_sprite_map_[index.x].at(index.y);;
    }

    BaseBubble* GameBubbleMapImple::clingBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index)
    {
        cocos2d::Vec2 bubble_should_index = this->getTheNearestEmptyIndex(this->convertGameSceneCsbToMapSpaceWithBubble(prepare_bubble),
            contact_index);
        BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(prepare_bubble->getBubbleType(),
            bubble_should_index, this->convertIndexToPoint(bubble_should_index));
        bubble_sprite_map_;
        this->addBubbleToBubbleMap(bubble);
        return bubble;
    }

    void GameBubbleMapImple::removeSpriteFromeMap(const BubbleVector& vector)
    {
        for (auto var : vector)
        {
            this->removeSpriteFromeMapWithIndex(var->getBubbleIndex());
        }
    }

    void GameBubbleMapImple::removeSpriteFromeMapWithIndex(const cocos2d::Vec2& index)
    {
        bubble_sprite_map_[index.x].erase(index.y);
    }

    std::vector<cocos2d::Vec2> GameBubbleMapImple::getAroundEmptyIndexWithIndex(const cocos2d::Vec2& index)
    {
        std::vector<cocos2d::Vec2> index_vector = this->getAroundIndexWithIndex(index);
        for (auto iter = index_vector.begin(); iter != index_vector.end();)
        {
            if (bubble_sprite_map_[iter->x].at(iter->y))
            {
                iter = index_vector.erase(iter);
                break;
            }
            ++iter;
        }
        return index_vector;
    }

    BubbleVector GameBubbleMapImple::getBubbleVectorWithIndexVector(const BubbleIndexVector& index_vector)
    {
        cocos2d::Vector<BaseBubble*> vector;
        BaseBubble* basebubble = nullptr;
        for (auto iter : index_vector)
        {
            basebubble = this->getSpriteWithIndex(iter);
            if (basebubble)
            {
                vector.pushBack(basebubble);
            }
        }
        return vector;
    }

    cocos2d::Vec2 GameBubbleMapImple::getTheNearestEmptyIndex(const cocos2d::Vec2& point, const cocos2d::Vec2& index)
    {
        std::vector<cocos2d::Vec2> index_vector = this->getAroundEmptyIndexWithIndex(index);
        return this->getIndexMindistanceWithVector(point, index_vector);
    }

    cocos2d::Vec2 GameBubbleMapImple::getIndexMindistanceWithVector(const cocos2d::Vec2& point, 
        std::vector<cocos2d::Vec2> index_vector)
    {
        cocos2d::Vec2 nearest_index = index_vector.at(0);
        float distance = point.distance(index_vector.at(0));
        float compare_distance = 0;
        for (auto iter : index_vector)
        {
            compare_distance = point.distance(this->convertIndexToPoint(iter));
            if (compare_distance < distance)
            {
                nearest_index = iter;
                distance = compare_distance;
            }
        }
        return nearest_index;
    }

    void GameBubbleMapImple::addBubbleToBubbleMap(BaseBubble* bubble)
    {
        cocos2d::Vec2 index = bubble->getBubbleIndex();
        bubble_sprite_map_[index.x].insert(index.y, bubble);
    }

    void GameBubbleMapImple::addBubbleComponentByBubble(BaseBubble* bubble)
    {
        int component_numble = bubble->getBubbleComponentNumble();
        if (component_numble == 0)
        {
            return;
        }
        BaseComponentBubble* component_bubble = dynamic_cast<BaseComponentBubble*>(bubble);
        BubbleIndexVector index_vector = this->getComponentIndexByIndexAndNumble(bubble->getBubbleIndex(), component_numble);
        for (int i = 0; i < component_numble; i++)
        {
            BubbleComponent* component = BubbleComponent::createWithCore(bubble);
            auto index = index_vector.at(i);
            component->setBubbleIndex(index);
            component->setPosition(this->convertIndexToPoint(index));
            component_bubble->addBubbleComponent(component);
            this->addBubbleToBubbleMap(component);
        }
    }

    BubbleVector GameBubbleMapImple::disposeAirBubbleAfterEliminate()
    {
        BubbleVector vector = this->getInTheAirBubbles();
        this->removeSpriteFromeMap(vector);
        return vector;
    }

    BubbleVector GameBubbleMapImple::getNotInTheAirBubbles()
    {
        BubbleVector vector;
        cocos2d::Vec2 vec2;
        for (auto var : suspension_points_)
        {
            vec2 = var->getBubbleIndex();
            vector.pushBack(var);
        }
        this->traverseBubbles(&vector, CC_CALLBACK_1(GameBubbleMapImple::getAroundBubbleWithIndex, this));
        return vector;
    }

    BubbleVector GameBubbleMapImple::getInTheAirBubbles()
    {
        BubbleVector not_air_vector = this->getNotInTheAirBubbles();
        BubbleVector air_vector;
        for (auto var_1 : bubble_sprite_map_)
        {
            for (auto var_2 : var_1.second)
            {
                if (this->isExistInVector(not_air_vector, var_2.second))
                {
                    continue;
                }
                air_vector.pushBack(var_2.second);
            }
        }
        return air_vector;
    }

    void GameBubbleMapImple::traverseBubbles(BubbleVector* seed,
        std::function<BubbleVector(const cocos2d::Vec2& index)> func)
    {
        int map_size = 0;
        do
        {//有配套流程图
            map_size = seed->size();
            BubbleVector map_clone = *seed;
            for (auto iter_1 : map_clone)
            {
                this->mergeTwoBubbleVector(seed, func(iter_1->getBubbleIndex()));
            } //for (auto iter_1 : map_clone)
        } while (map_size != seed->size());
    }

    bool GameBubbleMapImple::isExistInVector(const BubbleVector& vector, BaseBubble* bubble)
    {
        auto iter = std::find(vector.begin(), vector.end(), bubble);
        return iter != vector.end();
    }

    BubbleVector GameBubbleMapImple::getAllBubblesFromMap()
    {
        BubbleVector vector(0);
        for (auto row_var : bubble_sprite_map_)
        {
            for (auto col_var : row_var.second)
            {
                if (col_var.second->getBubbleType() != kBubbleNull)
                {
                    vector.pushBack(col_var.second);
                }
            }
        }
        return vector;
    }

    BubbleVector GameBubbleMapImple::separateWindmillBubble()
    {
        BubbleVector vector(0);
        BaseBubble* bubble = nullptr;
        for (auto row_var : bubble_sprite_map_)
        {
            for (auto col_var : row_var.second)
            {
                if (col_var.second->getBubbleType() != kBubbleWindmill)
                {
                    vector.pushBack(col_var.second);
                }
                else
                {
                    bubble = col_var.second;
                }
            }
        }
        vector.insert(0, bubble);
        return vector;
    }

    float GameBubbleMapImple::getWindmillRotationAngle(BaseBubble* prepare_bubble)
    {
        float angle = getWindmillContactVelocity(prepare_bubble)/ (WINDMILL_BUBBLE_ROTATION_FACTOR-20); //切线的速度
        return angle;
    }

    int GameBubbleMapImple::getWindmillRotationDirection(const cocos2d::Vec2 & contact_vector, const cocos2d::Vec2 & angle_vector)
    {
        int direction = 0;
        if ((contact_vector.x > 0 && angle_vector.y<0) || (contact_vector.x < 0 && angle_vector.y>0))
        {
            direction = 1;
        }
        else
        {
            direction = -1;
        }
        return direction;
    }

    float GameBubbleMapImple::getWindmillContactVelocity(BaseBubble * prepare_bubble)
    {
        cocos2d::Vec2 windmill_pos = this->convertGameSceneMapToCsbSpaceWithBubble(this->getSpecialBubble());
        cocos2d::Vec2 contact_vector = prepare_bubble->getPosition() - windmill_pos;
        float x = contact_vector.x;
        float y = (0 - x*contact_vector.x) / contact_vector.y;
        cocos2d::Vec2 tangent_line_vector = cocos2d::Vec2(x, y).getNormalized();
        cocos2d::Vec2 angle_velocity = prepare_bubble->getPhysicsBody()->getVelocityAtWorldPoint(windmill_pos);
        cocos2d::Vec2 angle_vector = angle_velocity.project(tangent_line_vector); //切线速度的方向
        float velocity = sqrt(pow(angle_vector.x, 2) + pow(angle_vector.y, 2)); //切线的速度
        return velocity * getWindmillRotationDirection(contact_vector, angle_vector);
    }

    void GameBubbleMapImple::mergeTwoBubbleVector(BubbleVector* first_vector, 
        const BubbleVector& second_vector)
    {
        first_vector->pushBack(this->getDifferentInTwoBubbleVector(*first_vector, second_vector));
    }

    BubbleVector GameBubbleMapImple::getDifferentInTwoBubbleVector(const BubbleVector& first_vector,
        const BubbleVector& second_vector)
    {
        BubbleVector different_vector;
        for (auto iter_2 : second_vector)
        {
            if (this->isExistInVector(first_vector, iter_2))
            {
                continue;
            }
            different_vector.pushBack(iter_2);
        }
        return different_vector;
    }

    BubbleVectorMap GameBubbleMapImple::getEffectBubbles(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index)
    {
        BaseBubble* bubble = getSpriteWithIndex(contact_index);
        if (!bubble)
        {
            return BubbleVectorMap();
        }
        assert(bubble);
        cocos2d::Vec2 pre_convert_pos = this->convertGameSceneCsbToMapSpaceWithBubble(prepare_bubble);
        cocos2d::Vec2 nearest_index = this->getIndexNearestContactBubble(pre_convert_pos, contact_index);
        BubbleVector contact_around = this->getAroundBubbleWithIndex(contact_index);
        BubbleVector nearest_around = this->getAroundBubbleWithIndex(nearest_index);
        BubbleVector long_bubbles;
        long_bubbles.pushBack(this->getSpriteWithIndex(contact_index));
        BaseBubble* nearest_bubble = this->getSpriteWithIndex(nearest_index);
        if (nearest_bubble != nullptr)
        {
            long_bubbles.pushBack(nearest_bubble);
        }
        BubbleVectorMap effect_bubbles;
        effect_bubbles[LONG_EFFECT_BUBBLE_KEY] = long_bubbles;
        BubbleVector short_bubbles;
        short_bubbles.pushBack(this->getDifferentInTwoBubbleVector(long_bubbles, contact_around));
        short_bubbles.pushBack(this->getDifferentInTwoBubbleVector(long_bubbles, nearest_around));
        effect_bubbles[SHORT_EFFECT_BUBBLE_KEY] = short_bubbles;
        BubbleVector prepare_vector;
        prepare_vector.pushBack(prepare_bubble);
        effect_bubbles[PREPARE_EFFECT_BUBBLE_KEY] = prepare_vector;
        return effect_bubbles;
    }

    cocos2d::Vec2 GameBubbleMapImple::getIndexNearestContactBubble(const cocos2d::Vec2& prepare_point,
        const cocos2d::Vec2& contact_index)
    {
        std::vector<cocos2d::Vec2> around_index = this->getAroundIndexWithIndex(contact_index);
        return this->getIndexMindistanceWithVector(prepare_point, around_index);
    }

    BubbleVector GameBubbleMapImple::getSameRowBubblesWithIndex(const cocos2d::Vec2& index)
    {
        cocos2d::Map<int, BaseBubble*> row_map = bubble_sprite_map_[index.x];
        BubbleVector same_row_bubbles;
        for (auto iter = row_map.begin(); iter != row_map.end(); ++iter)
        {                              
            same_row_bubbles.pushBack(iter->second);
        }
        return same_row_bubbles;
    }

    cocos2d::Vector<ColorBubble*> GameBubbleMapImple::getAroundDarkCloudBubbleWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector around_bubbles = this->getAroundBubbleWithIndex(index);
        cocos2d::Vector<ColorBubble*> cloud_bubbles;
        for (auto var : around_bubbles)
        {
            ColorBubble* colorbubble = dynamic_cast<ColorBubble*>(var);
            if (colorbubble && colorbubble->isDarkCloudBubble())
            {
                cloud_bubbles.pushBack(colorbubble);
            }
        }
        return cloud_bubbles;
    }

    float GameBubbleMapImple::getBubblesMinPosition()
    {
        for (int i = bubble_sprite_map_.size()+ MAP_TOP_ROW_INDEX - 1; i != MAP_TOP_ROW_INDEX; i--)
        {
            if (bubble_sprite_map_[i].size()!=0)
            {
                return this->convertIndexToPoint(cocos2d::Vec2(i, 0)).y;
            }
        }
        return 0.0f;
    }

    BubbleVector GameBubbleMapImple::getBubblesInVisibleSize()
    {
        BubbleVector bubbles(0);
        int line_numble = 0;
        for (int i = bubble_sprite_map_.size(); i != MAP_TOP_ROW_INDEX && line_numble<MAP_MAX_ROW_IN_SCREEN; i--)
        {
            cocos2d::Map<int, BaseBubble*> map = bubble_sprite_map_[i];
            if (map.size() != 0)
            {
                for (auto iter : map)
                {
                    bubbles.pushBack(iter.second);
                }
                line_numble++;
            }
        }
        return bubbles;
    }

    int GameBubbleMapImple::getTopRowNullBubbleNumble()
    {
        return MAP_EVEN_ROW_MAX - bubble_sprite_map_[0].size();
    }

    void GameBubbleMapImple::setSpecialBubble()
    {
        for (auto var_row : bubble_sprite_map_)
        {
            for (auto var_col : var_row.second)
            {
                if (var_col.second->isWindmillBubble())
                {
                    special_bubble_ = var_col.second;
                    break;
                }
            }
        }
    }

    BaseBubble* GameBubbleMapImple::getSpecialBubble()
    {
        return special_bubble_;
    }

    void GameBubbleMapImple::setStageType(const StageType & type)
    {
        stage_type_ = type;
    }

    StageType GameBubbleMapImple::getStageType()
    {
        return stage_type_;
    }

    bool GameBubbleMapImple::isWindmillStage()
    {
        return this->getStageType() == kWindmill;
    }

    void GameBubbleMapImple::setFallFlag(bool flag)
    {
        is_fall_type_ = flag;
    }

    bool GameBubbleMapImple::isFallStage()
    {
        return is_fall_type_;
    }
}