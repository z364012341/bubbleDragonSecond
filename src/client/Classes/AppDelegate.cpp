#include <sstream>
#include "AppDelegate.h"
#include "LoadingScene.h"
#include "ZCGConfigDataDict.h"
USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);
static cocos2d::Size gameSize = cocos2d::Size(750, 1334);

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        //glview = GLViewImpl::createWithRect("bubbleDragonSecond", Rect(0, 0, gameSize.width/1.8, gameSize.height/2));
        //auto rect = bubble_second::XMLTool::getInstance()->getViewSizeFromXML();

        auto dict = ZCGConfigDataDict::getInstance();
        float frameWidth = dict->getIntData(ZCGConfigDataDict::KEY_FRAME_WIDTH);
        float frameHeight = dict->getIntData(ZCGConfigDataDict::KEY_FRAME_HEIGHT);
        cocos2d::Rect rect(0, 0, frameWidth, frameHeight);
        //glview = GLViewImpl::createWithRect("bubbleDragonSecond", rect);
        glview = GLViewImpl::create("bubbleDragonSecond");
        glview->setFrameSize(frameWidth, frameHeight);
#else
        glview = GLViewImpl::create("bubbleDragonSecond");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 50.0f);

    // Set the design resolution
    //glview->setDesignResolutionSize(gameSize.width, gameSize.height, ResolutionPolicy::UNKNOWN);
    //// if the frame's height is larger than the height of medium size.
    //if (frameSize.height > mediumResolutionSize.height)
    //{        
    //    director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    //}
    //// if the frame's height is larger than the height of small size.
    //else if (frameSize.height > smallResolutionSize.height)
    //{        
    //    director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    //}
    //// if the frame's height is smaller than the height of medium size.
    //else
    //{        
    //    director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    //}
    register_all_packages();
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    FileUtils::getInstance()->addSearchPath("ui/", false);
    FileUtils::getInstance()->addSearchPath("ui/daochu/", false);
    //FileUtils::getInstance()->addSearchPath("ui/menu/", false);
#endif
    srand((unsigned)time(NULL));
    // create a scene. it's an autorelease object
    // run
    director->runWithScene(bubble_second::LoadingScene::createScene());
    //bubble_second::LayerManager::getInstance()->replaceLayerByName(GAME_SCENE);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
