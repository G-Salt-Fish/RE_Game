#pragma once
#include "Item.h"

class wood_sword :public Weapon
{
public:
	void on(Player* object) override
	{
		object->atk.add(atk);
	}
	void down(Player* object) override
	{
		object->atk.sub(atk);
	}
	void fightupdate() override
	{

	}
	void fightend() override
	{

	}
	void fightstart() override
	{

	}
	wood_sword()
	{
		name.set("Ä¾½£");
		des.set("Ä¾Í·×öµÄ½£¡£");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		atk = 2;
		C_ITEM(wood_sword);
	}
};