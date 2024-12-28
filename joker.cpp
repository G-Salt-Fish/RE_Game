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
bool NAME::set(string come)
{
	name = come;
	return name == come;
}
string NAME::show()
{
	return name;
}
NAME::NAME()
{
	name = "";
}
bool DES::set(string come)
{
	des = come;
	return des == come;
}
string DES::show()
{
	return des;

}
DES::DES()
{
	des = "";
}
bool ILV::set(int come)
{
	lv = come;
	return lv == come;
}
bool ILV::setslv(int come)
{
	slv = come;
	return slv == come;
}
bool ILV::add(int come)
{
	int data = lv;
	lv += come;
	return lv - come == data;
}
bool ILV::addslv(int come)
{
	int data = slv;
	slv += come;
	return slv - come == data;
}
bool ILV::sub(int come)
{
	int data = lv;
	lv -= come;
	return lv + come == data;
}
bool ILV::subslv(int come)
{
	int data = slv;
	slv -= come;
	return slv + come == data;
}
int ILV::show()
{
	return lv;
}
int ILV::showslv()
{
	return slv;
}
ILV::ILV()
{
	lv = 0;
	slv = 0;
}
bool NUM::set(int come)
{
	num = come;
	return num == come;
}
bool NUM::add(int come)
{
	int data = num;
	num += come;
	return num - come == data;
}
bool NUM::sub(int come)
{
	int data = num;
	num -= come;
	return num + come == data;
}
int NUM::show()
{
	return num;
}
NUM::NUM()
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

	//从背包中查找物品
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

COLOR::Color stcolor(const string& str)
{
	static map<string, COLOR::Color> enumMap =
	{
		{"bule",COLOR::Color::bule},
		{"green",COLOR::Color::green},
		{"lessgreen",COLOR::Color::lessgreen},
		{"red",COLOR::Color::red},
		{"purpel",COLOR::Color::purpel},
		{"yellow",COLOR::Color::yellow},
		{"white",COLOR::Color::white},
		{"grey",COLOR::Color::grey},
		{"lessbule",COLOR::Color::lessbule}
	};
	map<std::string, COLOR::Color>::iterator it = enumMap.find(str);
	if (it != enumMap.end())
	{
		return it->second;
	}
	else
	{
		return COLOR::Color::white;
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
	for (int i = 1; i <= p.b.Isize(); i++)
	{
		if (p.b.Ishow(i)->name.show() == name)
		{
			return p.b.Ishow(i);
		}
	}
	for (int i = 1; i <= p.b.Wsize(); i++)
	{
		if (p.b.Wshow(i)->name.show() == name)
		{
			return p.b.Wshow(i);
		}
	}
	for (int i = 1; i <= p.b.Asize(); i++)
	{
		if (p.b.Ashow(i)->name.show() == name)
		{
			return p.b.Ashow(i);
		}
	}
	for (int i = 1; i <= p.b.Usize(); i++)
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
bool isItemId(string str)
{
	auto it = ItemMap.find(str);
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
bool ATK::set(int come)
{
	atk = come;
	return atk == come;
}
bool ATK::add(int come)
{
	int data;
	data = atk;
	atk += come;
	return atk - come == data;
}
bool ATK::sub(int come)
{
	int data;
	data = atk;
	atk -= come;
	return atk + come == data;
}
int ATK::show()
{
	return atk;
}
ATK::ATK() :atk(2) {}
bool DFS::set(int come)
{
	dfs = come;
	return dfs == come;
}
bool DFS::add(int come)
{
	int data;
	data = dfs;
	dfs += come;
	return dfs - come == data;
}
bool DFS::sub(int come)
{
	int data;
	data = dfs;
	dfs -= come;
	return dfs + come == data;
}
int DFS::show()
{
	return dfs;
}
DFS::DFS() :dfs(0) {}
bool HP::setmax(int come)
{
	mhp = come;
	return mhp == come;
}
bool HP::set(int come)
{
	hp = come;
	return hp == come;
}
bool HP::addmax(int come)
{
	int data = mhp;
	mhp += come;
	return mhp - come == data;
}
bool HP::add(int come)
{
	int data = hp;
	hp += come;
	return hp - come == data;
}
bool HP::submax(int come)
{
	int data = mhp;
	mhp -= come;
	return mhp + come == data;
}
bool HP::sub(int come)
{
	int data = hp;
	hp -= come;
	return hp + come == data;
}
int HP::showmax()
{
	return mhp;
}
int HP::show()
{
	return hp;
}
HP::HP() : hp(100), mhp(100) {}
void COLOR::set(Color come)
{
	color = come;
	string dio;
	dio = "color ";
	dio += static_cast<char>(come);
	const char* cstr = dio.c_str();
	system(cstr);
}
COLOR::Color COLOR::show()
{
	return color;
}
COLOR::COLOR() :color(Color::white) {}
bool LV::set(int come)
{
	lv = come;
	return lv == come;
}
bool LV::setxp(int come)
{
	xp = come;
	return xp == come;
}
bool LV::setmxp(int come)
{
	mxp = come;
	return mxp == come;
}
bool LV::add(int come)
{
	int data = lv;
	lv += come;
	return lv - come == data;
}
bool LV::addxp(int come)
{
	int data = xp;
	xp += come;
	return xp - come == data;
}
bool LV::addmxp(int come)
{
	int data = mxp;
	mxp += come;
	return mxp - come == data;
}
bool LV::sub(int come)
{
	int data = lv;
	lv -= come;
	return lv + come == data;
}
bool LV::subxp(int come)
{
	int data = xp;
	xp -= come;
	return xp + come == data;
}
bool LV::submxp(int come)
{
	int data = mxp;
	mxp -= come;
	return mxp + come == data;
}
int LV::lvupneed()
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
bool LV::lvup()
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
int LV::show()
{
	return lv;
}
int LV::showlv()
{
	return show();
}
int LV::showxp()
{
	return xp;
}
int LV::showmxp()
{
	mxp = lvupneed();
	return mxp;
}
bool MONEY::set(int come)
{
	mon = come;
	return mon == come;
}
bool MONEY::add(int come)
{
	int data = mon;
	mon += come;
	return mon - come == data;
}
bool MONEY::sub(int come)
{
	int data = mon;
	mon -= come;
	return mon + come == data;
}
int MONEY::show()
{
	return mon;
}
MONEY::MONEY() :mon(0) {}
LV::LV() : lv(1), xp(0), mxp(10) {}
GEAR::GEAR() : gear(0),maxgear(6) {}
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
Place::Place() :father(nullptr), son() { }
Place::Place(Place* F, vector<Place*> S) :father(F), son(S) {}

Place::~Place() { }


Event::Event()
{

}

Event::~Event()
{
}

Character::Character()
{
	name.set("Mouse");
}
