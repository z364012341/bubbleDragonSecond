//#include "CsbNodeManager.h"
//#include "cocostudio\CocoStudio.h"
//#include "BubbleSecondConstant.h"
//namespace bubble_second {
//    CsbNodeManager::CsbNodeManager()
//    {
//    }
//
//    void CsbNodeManager::addCsbNode(cocos2d::Layer* layer, const std::string& csbname)
//    {
//        cocos2d::Node* node = cocos2d::CSLoader::createNode(csbname);
//        node->setName(csbname);
//        if (!node)
//        {
//            throw;
//        }
//        layer->addChild(node);
//    }
//
//    cocos2d::Node* CsbNodeManager::getNodeChildByTag(cocos2d::Layer* layer, int tag, const std::string& node_name)
//    {
//        cocos2d::Node* node = layer->getChildByName(node_name);
//        if (!node)
//        {
//            throw;
//        }
//        return node->getChildByTag(tag);
//    }
//}