#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool  pRet = false;
    do {
        
        CC_BREAK_IF(!CCLayer::init());
//              CCLabelTTF 每次调用 setString （即改变文字）的时候，一个新的OPENGL 纹理将会被创建.。这意味着setString 和创建一个新的标签一样慢。
        
//          所以，当你需要频繁的更新它们的时候，尽可能的不用去使用标签对象。  而应该使用CCLabelAtlas或者是CCLabelBMFont。
        CCLabelTTF* label = CCLabelTTF::create("LabelTTF", "Marker Felt", 21);
        label->setPosition(ccp(100, 400));
        this->addChild(label);
        
//         CCLabelBMFont  相当于每次改变只改变了图片坐标，而CCLabelTTF要重新渲染.这个类使用之前，需要添加好字体文件，包括一个图片文件 (**.png) 和一个 字体坐标文件 （**.fnt）。
        CCLabelBMFont* label2 = CCLabelBMFont::create("CCLabelBMFont", "font_red_14.fnt");
        label2->setPosition(ccp(200, 400));
        this->addChild(label2);
        
//          因为帧率一直在变，使用CCLabelTTF的话效率太低，因为只是数字所以也犯不上使用 CCLabelBMFont 加载那么大的文字图像，所以使用这个比较合适。
        CCLabelAtlas* label3 = CCLabelAtlas::create("0.0", "fps_images.png", 16, 24, '.');
        label3->setPosition(ccp(200, 300));
        this->addChild(label3);

        
        pRet =true;
    } while (0);
    
    
    
    
    
    return pRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
