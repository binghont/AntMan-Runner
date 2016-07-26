#include "MainMenuScene.h"
#include "OptionScene.h"
#include "Definitions.h"

USING_NS_CC;


Scene* OptionScene::createScene()
{
    auto scene = Scene::create();
    auto layer = OptionScene::create();
    scene->addChild(layer);
    return scene;
}

//Initial 
bool OptionScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //setbackGround
    auto backgroundSprite = Sprite::create("pic/Background.png");
    backgroundSprite->setPosition( Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(backgroundSprite);
    
    //setTitle
   // auto titleSprite = Sprite::create("pic/Title.png");
   // titleSprite->setPosition( Point( visibleSize.width/2 + origin.x,
    //visibleSize.height - titleSprite->getContentSize( ).height));
    //this->addChild(titleSprite);
    

    //setPlayItem
    auto playItem = MenuItemImage::create("pic/menu.png", "pic/menupress.png",
                                          CC_CALLBACK_1(OptionScene::GoToMainMenuScene, this));
    playItem->setPosition(Point(visibleSize.width*1/8 + origin.x, visibleSize.height*7/8 + origin.y));

    //setMenu
    auto menu = Menu::create( playItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true;
}

// JumpToGameScene
void OptionScene::GoToMainMenuScene( cocos2d::Ref *sender)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance( )->replaceScene( TransitionFade::create(TRANSITION_TIME, scene));
}
