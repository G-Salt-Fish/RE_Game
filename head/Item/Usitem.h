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
		name.set("ƻ��");
		des.set("�����ϳ���ƻ�������Իָ�" + std::to_string(hp) + "��������");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		hp = 2;
		C_ITEM(apple);
	}
};
