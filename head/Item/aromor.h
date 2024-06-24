#pragma once
#include "Item.h"

class wood_shield:public Armor
{
	void on() override
	{

	}

	void updata()
	{
		cout << "this is wood_shield" << endl;
	}
};