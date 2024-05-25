#pragma once
#include"Item.h"
class wood :public Item
{
public:
	wood()
	{
		name.set("木头");
		des.set("木头，木头，木头。");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		C_ITEM(wood);
	}
};
