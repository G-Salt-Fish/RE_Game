#include "joker.h"
Player p;
map<string, Item* (*)()> ItemMap;
Weapon::Weapon()
{
	atk = 0;
	ifon = false;
	type = Item::Type::Weapon;
}
Weapon::~Weapon()
{

}
Armor::Armor()
{
	dfs = 0;
	ifon = false;
	type = Item::Type::Armor;
}
Armor::~Armor()
{

}
Usitem::Usitem()
{
	type = Item::Type::Usitem;
}
bool Item::NAME::set(string come)
{
	name = come;
	return name == come;
}
string Item::NAME::show()
{
	return name;
}
Item::NAME::NAME()
{
	name = "";
}
bool Item::DES::set(string come)
{
	des = come;
	return des == come;
}
string Item::DES::show()
{
	return des;

}
Item::DES::DES()
{
	des = "";
}
bool Item::LV::set(int come)
{
	lv = come;
	return lv == come;
}
bool Item::LV::setslv(int come)
{
	slv = come;
	return slv == come;
}
bool Item::LV::add(int come)
{
	int data = lv;
	lv += come;
	return lv - come == data;
}
bool Item::LV::addslv(int come)
{
	int data = slv;
	slv += come;
	return slv - come == data;
}
bool Item::LV::sub(int come)
{
	int data = lv;
	lv -= come;
	return lv + come == data;
}
bool Item::LV::subslv(int come)
{
	int data = slv;
	slv -= come;
	return slv + come == data;
}
int Item::LV::show()
{
	return lv;
}
int Item::LV::showslv()
{
	return slv;
}
Item::LV::LV()
{
	lv = 0;
	slv = 0;
}
bool Item::NUM::set(int come)
{
	num = come;
	return num == come;
}
bool Item::NUM::add(int come)
{
	int data = num;
	num += come;
	return num - come == data;
}
bool Item::NUM::sub(int come)
{
	int data = num;
	num -= come;
	return num + come == data;
}
int Item::NUM::show()
{
	return num;
}
Item::NUM::NUM()
{
	num = 1;
}
string Item::TypeToString()
{
	switch (type)
	{
	case Item::Type::Item:
		return "Item";
		break;
	case Item::Type::Weapon:
		return "Weapon";
		break;
	case Item::Type::Armor:
		return "Armor";
		break;
	case Item::Type::Usitem:
		return "Usitem";
		break;
	default:
		return "null";
		break;
	}
}
Item::Type Item::typeshow()
{
	return type;
}
void Item::updata()
{
}
Item::Item()
{
	type = Item::Type::Item;
}
void Bag::Iadd(Item* item, int come)
{
	if (Ibag.size() == 0)
	{
		Ibag.push_back(item);
		return;
	}
	for (unsigned int i = 1; i <= Ibag.size(); i++)
	{
		Item* dio;
		dio = Ibag[i - 1];
		if (item->name.show() == dio->name.show()
			&& item->des.show() == dio->des.show()
			&& item->lv.show() == dio->lv.show()
			&& item->lv.showslv() == dio->lv.showslv())
		{
			delete item;
			dio->num.add(come);
		}
		else
		{
			Ibag.push_back(item);
		}
	}
}
void Bag::Isub(Item* item, int come = 1)
{
	for (unsigned int i = 1; i <= Ibag.size(); i++)
	{
		Item* dio;
		dio = Ibag[i - 1];
		if (item->name.show() == dio->name.show()
			&& item->des.show() == dio->des.show()
			&& item->lv.show() == dio->lv.show()
			&& item->lv.showslv() == dio->lv.showslv())
		{
			if (come >= dio->num.show())
			{
				delete dio;
				if (item != dio)
				{
					delete item;
				}
				Ibag.erase(Ibag.begin() + i - 1);
			}
			else
			{
				if (item != dio)
				{
					delete item;
				}
				dio->num.sub(come);
			}
		}
	}
}
Item* Bag::Ishow(int name)
{
	return Ibag[name];
}
Item* Bag::Ishow(string name)
{
	if (isnumber(name))
	{
		return Ibag[stoi(name)];
	}

	for (unsigned int i = 1; i <= Ibag.size(); i++)
	{
		if (Ibag[i - 1]->name.show() == name)
		{
			return Ibag[i - 1];
		}
	}

	auto it = ItemMap.find(name);
	if (it != ItemMap.end())
	{
		for (unsigned int i = 1; i <= Ibag.size(); i++)
		{
			string id = Ibag[i - 1]->id;
			if (id == name)
			{
				return Ibag[i - 1];
			}
		}
		return nullptr;
	}
	else
	{
		return nullptr;
	}


}
int Bag::Isize()
{
	return Ibag.size();
}
void Bag::Wadd(Weapon* weapon, int come)
{
	for (int i = 1; i <= come; i++)
	{
		Wbag.push_back(weapon);
	}
}
void Bag::Wsub(Weapon* weapon)
{
	vector<Weapon*>::iterator it = find(Wbag.begin(), Wbag.end(), weapon);
	if (it != Wbag.end())
	{
		delete Wbag[distance(Wbag.begin(), it)];
		Wbag.erase(remove(Wbag.begin(), Wbag.end(), weapon), Wbag.end());
	}
}
Weapon* Bag::Wshow(int name)
{
	return Wbag[name];
}
Weapon* Bag::Wshow(string name)
{
	for (unsigned int i = 1; i <= Wbag.size(); i++)
	{
		if (Wbag[i - 1]->name.show() == name)
		{
			return Wbag[i - 1];
		}
	}

	auto it = ItemMap.find(name);
	if (it != ItemMap.end())
	{
		for (unsigned int i = 1; i <= Wbag.size(); i++)
		{
			string id = Wbag[i - 1]->id;
			if (id == name)
			{
				return Wbag[i - 1];
			}
		}
		return nullptr;
	}
	else
	{
		return nullptr;
	}
}
int Bag::Wsize()
{
	return Wbag.size();
}
void Bag::Aadd(Armor* armor, int come)
{
	for (int i = 1; i <= come; i++)
	{
		Abag.push_back(armor);
	}
}
void Bag::Asub(Armor* armor)
{
	vector<Armor*>::iterator it = find(Abag.begin(), Abag.end(), armor);
	if (it != Abag.end())
	{
		delete Abag[distance(Abag.begin(), it)];
		Abag.erase(remove(Abag.begin(), Abag.end(), armor), Abag.end());
	}
}
Armor* Bag::Ashow(int name)
{
	return Abag[name];
}
Armor* Bag::Ashow(string name)
{
	for (unsigned int i = 1; i <= Abag.size(); i++)
	{
		if (Abag[i - 1]->name.show() == name)
		{
			return Abag[i - 1];
		}
	}

	auto it = ItemMap.find(name);
	if (it != ItemMap.end())
	{
		for (unsigned int i = 1; i <= Abag.size(); i++)
		{
			string id = Abag[i - 1]->id;
			if (id == name)
			{
				return Abag[i - 1];
			}
		}
		return nullptr;
	}
	else
	{
		return nullptr;
	}

}
int Bag::Asize()
{
	return Abag.size();
}
void Bag::Uadd(Usitem* usitem, int come)
{
	if (Ubag.size() == 0)
	{
		Ubag.push_back(usitem);
		return;
	}
	for (unsigned int i = 1; i <= Ubag.size(); i++)
	{
		Usitem* dio;
		dio = dynamic_cast<Usitem*>(Ibag[i - 1]);
		if (usitem->name.show() == dio->name.show()
			&& usitem->des.show() == dio->des.show()
			&& usitem->lv.show() == dio->lv.show()
			&& usitem->lv.showslv() == dio->lv.showslv())
		{
			delete usitem;
			dio->num.add(come);
		}
		else
		{
			Ibag.push_back(usitem);
		}
	}
}
void Bag::Usub(Usitem* usitem, int come)
{
	for (unsigned int i = 1; i <= Ubag.size(); i++)
	{
		Item* dio;
		dio = dynamic_cast<Usitem*>(Ubag[i - 1]);
		if (usitem->name.show() == dio->name.show()
			&& usitem->des.show() == dio->des.show()
			&& usitem->lv.show() == dio->lv.show()
			&& usitem->lv.showslv() == dio->lv.showslv())
		{
			if (come >= dio->num.show())
			{
				delete dio;
				if (usitem != dio)
				{
					delete usitem;
				}
				Ubag.erase(Ubag.begin() + i - 1);
			}
			else
			{
				if (usitem != dio)
				{
					delete usitem;
				}
				dio->num.sub(come);
			}
		}
	}
}
Usitem* Bag::Ushow(int name)
{
	return Ubag[name];
}
Usitem* Bag::Ushow(string name)
{
	for (unsigned int i = 1; i <= Ubag.size(); i++)
	{
		if (Ubag[i - 1]->name.show() == name)
		{
			return Ubag[i - 1];
		}
	}

	auto it = ItemMap.find(name);
	if (it != ItemMap.end())
	{
		for (unsigned int i = 1; i <= Ubag.size(); i++)
		{
			string id = Ubag[i - 1]->id;
			if (id == name)
			{
				return Ubag[i - 1];
			}
		}
		return nullptr;
	}
	else
	{
		return nullptr;
	}


	return nullptr;
}
int Bag::Usize()
{
	return Ubag.size();
}
void Bag::add(Item* item, int come)
{
	if (item->type == Item::Type::Weapon)
	{
		Weapon* w;
		w = dynamic_cast<Weapon*>(item);
		p.b.Wadd(w, come);
	}
	if (item->type == Item::Type::Item)
	{
		p.b.Iadd(item, come);
	}
	if (item->type == Item::Type::Armor)
	{
		Armor* a;
		a = dynamic_cast<Armor*>(item);
		p.b.Aadd(a, come);
	}
	if (item->type == Item::Type::Usitem)
	{
		Usitem* u;
		u = dynamic_cast<Usitem*>(item);
		p.b.Uadd(u, come);
	}
}
void Bag::sub(Item* item, int come)
{

}
Item* Bag::show(string name)
{
	if (isnumber(name))
	{
		return nullptr;
	}

	//从背包中通过名称查找物品
	if (p.b.Ishow(name) != nullptr)
	{
		return p.b.Ishow(name);
	}
	else if (p.b.Wshow(name) != nullptr)
	{
		return p.b.Wshow(name);
	}
	else if (p.b.Ashow(name) != nullptr)
	{
		return p.b.Ashow(name);
	}
	else if (p.b.Ushow(name) != nullptr)
	{
		return p.b.Ushow(name);
	}
	return nullptr;
}
Bag::Bag()
{

}
Bag::~Bag()
{
	for (auto item : Ibag)
	{
		delete item;
	}
	for (auto item : Wbag)
	{
		delete item;
	}
	for (auto item : Abag)
	{
		delete item;
	}
	for (auto item : Ubag)
	{
		delete item;
	}
}

Player::COLOR::Color stcolor(const string& str)
{
	static map<string, Player::COLOR::Color> enumMap =
	{
		{"bule",Player::COLOR::Color::bule},
		{"green",Player::COLOR::Color::green},
		{"lessgreen",Player::COLOR::Color::lessgreen},
		{"red",Player::COLOR::Color::red},
		{"purpel",Player::COLOR::Color::purpel},
		{"yellow",Player::COLOR::Color::yellow},
		{"white",Player::COLOR::Color::white},
		{"grey",Player::COLOR::Color::grey},
		{"lessbule",Player::COLOR::Color::lessbule}
	};
	map<std::string, Player::COLOR::Color>::iterator it = enumMap.find(str);
	if (it != enumMap.end())
	{
		return it->second;
	}
	else
	{
		return Player::COLOR::Color::white;
	}
}
bool bfinditem(string name) 
{
	auto it = ItemMap.find(name);
	if (it != ItemMap.end())
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
Item* finditem(string name)
{
	auto t = ItemMap[name];
	if (t)
	{
		return t();
	}
	else
	{
		return nullptr;
	}
}
Item* bagfinditem(string name)
{
	//从背包中通过名称查找物品
	for (unsigned int i = 1; i <= p.b.Isize(); i++)
	{
		if (p.b.Ishow(i)->name.show() == name)
		{
			return p.b.Ishow(i);
		}
	}
	for (unsigned int i = 1; i <= p.b.Wsize(); i++)
	{
		if (p.b.Wshow(i)->name.show() == name)
		{
			return p.b.Wshow(i);
		}
	}
	for (unsigned int i = 1; i <= p.b.Asize(); i++)
	{
		if (p.b.Ashow(i)->name.show() == name)
		{
			return p.b.Ashow(i);
		}
	}
	for (unsigned int i = 1; i <= p.b.Usize(); i++)
	{
		if (p.b.Ushow(i)->name.show() == name)
		{
			return p.b.Ushow(i);
		}
	}

	return nullptr;
}
bool isnumber(string str)
{
	if (str.empty())
	{
		return false;
	}
	return std::all_of(str.begin(), str.end(), [](unsigned char c) 
		{
			return std::isdigit(c);
		});
}
bool Player::NAME::set(string come)
{
	name = come;
	return name == come;
}
string Player::NAME::show()
{
	return name;
}
Player::NAME::NAME() :name("G-Salt-Fish") {}
bool Player::ATK::set(int come)
{
	atk = come;
	return atk == come;
}
bool Player::ATK::add(int come)
{
	int data;
	data = atk;
	atk += come;
	return atk - come == data;
}
bool Player::ATK::sub(int come)
{
	int data;
	data = atk;
	atk -= come;
	return atk + come == data;
}
int Player::ATK::show()
{
	return atk;
}
Player::ATK::ATK() :atk(2) {}
bool Player::DFS::set(int come)
{
	dfs = come;
	return dfs == come;
}
bool Player::DFS::add(int come)
{
	int data;
	data = dfs;
	dfs += come;
	return dfs - come == data;
}
bool Player::DFS::sub(int come)
{
	int data;
	data = dfs;
	dfs -= come;
	return dfs + come == data;
}
int Player::DFS::show()
{
	return dfs;
}
Player::DFS::DFS() :dfs(0) {}
bool Player::HP::setmax(int come)
{
	mhp = come;
	return mhp == come;
}
bool Player::HP::set(int come)
{
	hp = come;
	return hp == come;
}
bool Player::HP::addmax(int come)
{
	int data = mhp;
	mhp += come;
	return mhp - come == data;
}
bool Player::HP::add(int come)
{
	int data = hp;
	hp += come;
	return hp - come == data;
}
bool Player::HP::submax(int come)
{
	int data = mhp;
	mhp -= come;
	return mhp + come == data;
}
bool Player::HP::sub(int come)
{
	int data = hp;
	hp -= come;
	return hp + come == data;
}
int Player::HP::showmax()
{
	return mhp;
}
int Player::HP::show()
{
	return hp;
}
Player::HP::HP() : hp(100), mhp(100) {}
void Player::COLOR::set(Color come)
{
	color = come;
	string dio;
	dio = "color ";
	dio += static_cast<char>(come);
	const char* cstr = dio.c_str();
	system(cstr);
}
Player::COLOR::Color Player::COLOR::show()
{
	return color;
}
Player::COLOR::COLOR() :color(Color::white) {}
bool Player::LV::set(int come)
{
	lv = come;
	return lv == come;
}
bool Player::LV::setxp(int come)
{
	xp = come;
	return xp == come;
}
bool Player::LV::setmxp(int come)
{
	mxp = come;
	return mxp == come;
}
bool Player::LV::add(int come)
{
	int data = lv;
	lv += come;
	return lv - come == data;
}
bool Player::LV::addxp(int come)
{
	int data = xp;
	xp += come;
	return xp - come == data;
}
bool Player::LV::addmxp(int come)
{
	int data = mxp;
	mxp += come;
	return mxp - come == data;
}
bool Player::LV::sub(int come)
{
	int data = lv;
	lv -= come;
	return lv + come == data;
}
bool Player::LV::subxp(int come)
{
	int data = xp;
	xp -= come;
	return xp + come == data;
}
bool Player::LV::submxp(int come)
{
	int data = mxp;
	mxp -= come;
	return mxp + come == data;
}
int Player::LV::lvupneed()
{
	string path = "data\\lvupneednum.ini";
	fstream f(path, ios::in);
	int need = 0;
	for (int i = 1; i <= lv; i++)
	{
		f >> need;
	}
	f.close();
	return need;
}
bool Player::LV::lvup()
{
	bool ifup = false;
	mxp = lvupneed();
	if (xp >= mxp)
	{
		lv++;
		ifup = true;
	}
	return ifup;
}
int Player::LV::show()
{
	return lv;
}
int Player::LV::showlv()
{
	return show();
}
int Player::LV::showxp()
{
	return xp;
}
int Player::LV::showmxp()
{
	mxp = lvupneed();
	return mxp;
}
bool Player::MONEY::set(int come)
{
	mon = come;
	return mon == come;
}
bool Player::MONEY::add(int come)
{
	int data = mon;
	mon += come;
	return mon - come == data;
}
bool Player::MONEY::sub(int come)
{
	int data = mon;
	mon -= come;
	return mon + come == data;
}
int Player::MONEY::show()
{
	return mon;
}
Player::MONEY::MONEY() :mon(0) {}
Player::LV::LV() : lv(1), xp(0), mxp(10) {}
Player::GEAR::GEAR() : gear(0),maxgear(6) {}
Player::Player() {}
void ti(string come)
{
	string jojo;
	jojo = "-----" + come + "-----";
	cout << jojo;
}
void start(string title)
{
	string dio;
	dio = "title ";
	dio += static_cast<string>(title);
	const char* cstr = dio.c_str();
	system(cstr);
}

bool Place::set_father(Place* object)
{
	this->father = object;
	return father == object;
}

bool Place::add(Place* object)
{
	son.push_back(object);
	return son[son.size()-1] == object;
}

bool Place::sub(Place* object)
{
	auto it = remove(son.begin(), son.end(), object);
	son.erase(it, son.end());

	return false;
}
Place::Place() { }
Place::Place(Place* F, vector<Place*> S) :father(F), son(S) {}

Place::~Place() { }


Event::Event()
{

}

Event::~Event()
{
}
