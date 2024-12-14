#pragma once
#include "Item.h"

class wood_shield:public Armor
{
public:
	void on() override
	{

	}

	void down() override
	{

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
	wood_shield()
	{
		dfs = 2;
		name.set("Ä¾¶Ü");
		des.set("Ä¾Í·×öµÄ¶Ü¡£");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		C_ITEM(wood_shield);
	}
};