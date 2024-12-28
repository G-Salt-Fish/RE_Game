#pragma once
#include "Item.h"

class apple : public Usitem
{

private:
	int hp;

public:

	void use(Player* object) override
	{
		object->hp.add(hp);
	}

	apple()
	{
		hp = 2;
		name.set("苹果");
		des.set("橡树上长的苹果，可以恢复" + std::to_string(hp) + "点生命。");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		C_ITEM(apple);
	}
};
