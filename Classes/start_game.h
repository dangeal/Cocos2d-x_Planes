#ifndef __START_GAME_H__
#define __START_GAME_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "editor-support/cocostudio/CCSGUIReader.h"

using namespace cocos2d::ui;
using namespace cocostudio;
using namespace std;
USING_NS_CC;

class StartGame : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	CREATE_FUNC(StartGame);

public:
	//开始游戏按钮回调
	void start_play(Ref* ref);
};

#endif // __HELLOWORLD_SCENE_H__
