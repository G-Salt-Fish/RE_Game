#pragma once
#include "Item.h"

class wood_sword :public Weapon
{
public:
	void on() override
	{
		p.atk.add(atk);
	}
	void down() override
	{
		p.atk.sub(atk);
	}
	void fight() override
	{

	}
	wood_sword()
	{
		name.set("ľ��");
		des.set("ľͷ���Ľ���");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		atk = 2;
		C_ITEM(wood_sword);
	}
};