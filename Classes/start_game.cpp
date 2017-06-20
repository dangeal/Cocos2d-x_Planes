#include "start_game.h"
#include "main_game.h"
#include "select_plane_scene.h"

cocos2d::Scene* StartGame::createScene()
{
	auto scene = Scene::create();

	auto layer = StartGame::create();

	scene->addChild(layer);
	return scene;
}

bool StartGame::init()
{
	if (!Layer::init())
		return false;
	//��Ϸ���ڴ�С
	auto size = Director::getInstance()->getWinSize();

	//��Ϸ�ı���
	auto spr_bg = Sprite::create("ui/bg.png");
	spr_bg->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(spr_bg);

	//��ȡxml
	auto dic = Dictionary::createWithContentsOfFile("fonts/text.xml");
	auto str = (String*)(dic->objectForKey("title"));


	//��Ϸ�ı���
	TTFConfig config("fonts/DFPShaoNvW5-GB.ttf",40);
	auto title = Label::createWithTTF(config, "plane shooting",TextHAlignment::LEFT);
	title->setPosition(ccp(size.width / 2, size.height - title->getContentSize().height));
	title->setColor(ccc3(160,32,240));
	this->addChild(title);

	//����֡����
	auto animation = Animation::create();
	for (int i = 1; i <= 4; ++i)
	{
		auto spr_name = String::createWithFormat("ui/start%d.png", i);
		animation->addSpriteFrameWithFile(spr_name->getCString());
	}
	animation->setDelayPerUnit(0.3f);
	animation->setLoops(-1);

	//��������
	auto sprite = Sprite::create("ui/start1.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2 ));
	this->addChild(sprite);
	sprite->runAction(Animate::create(animation));

	//��ӿ�ʼ��Ϸ��ť
	str = (String*)(dic->objectForKey("play"));
	auto btn_label = Label::create();
	btn_label->setString(str->getCString());
	btn_label->setSystemFontSize(40);
	 
	/*��ӿ�ʼ��Ϸ��ť*/
	/*auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("beganBtn_1.ExportJson");
	UI->setPosition(Point(10, 100));
	this->addChild(UI);

	Button* begin_btn = (Button*)Helper::seekWidgetByName(UI, "beganBtn0.png");
	begin_btn->addTouchEventListener(this, toucheventselector(StartGame::start_play));*/
 

	auto start_menu = MenuItemLabel::create(btn_label, CC_CALLBACK_1(StartGame::start_play, this));

	auto menu = Menu::create(start_menu, NULL);
	menu->setPosition(ccp(size.width / 2, size.height *0.3));
	this->addChild(menu);



	return true;
}

void StartGame::start_play(Ref* ref)
{
	//����ѡ�����
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, SelectPlaneScene::create()));

}
