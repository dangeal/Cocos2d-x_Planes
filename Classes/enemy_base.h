#ifndef __ENEMY_BASE_H__
#define __ENEMY_BASE_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class EenmyBase : public cocos2d::Sprite
{

public:
	EenmyBase();
	~EenmyBase();
public:

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(EenmyBase);

	void onEnterTransitionDidFinish();
	void onExit();

	virtual void update(float delta);

public:
	//��ʼ���л���
	void initEnemy(int index = 1);
	//��ը����
	void enemy_death();

	//ɾ���Լ�
	void remove_enemy();

	//�л�Ѫ��
	void set_hp(int hp);
	int get_hp(){ return enemy_hp_; }
public:
	//�л�����
	int enemy_index_;
	//�л� Ѫ��
	int enemy_hp_;
	//�Ƿ�ը
	bool is_death_;

};

#endif // __ENEMY_BASE_H__
