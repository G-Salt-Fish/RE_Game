#pragma once
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib> 
#include<chrono>
#include<thread>
#include<fstream> 
#include<conio.h>
#include<vector>
#include<utility>
#include<stdexcept> 
#include<map>
#include<string>
#include<unordered_map>
#include<sstream>
#include<cctype>
#include<algorithm>

#define pause system("pause")
#define cls system("cls")
using Unint = unsigned int;
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;
using std::fstream;
using std::ios;
using std::endl;
using std::istringstream;

const string _joker_version{ "1.0.0.0" };
class Player;
class Item;
class Bag;
class Weapon;
class Event;

#define NEW_ITEM(T) \
	ItemMap[#T] = []() -> Item* { return new T; }; 

#define C_ITEM(T) \
	 id = #T;

extern map<string, Item* (*)()> ItemMap;

class Event
{
private:
	vector<void(*)()> event;
public:
	Event();
	~Event();
};//抽象类，之后要具体化 -> 要有实例
/*
	get Item -> Item去注册进对应的事件
	get into water_town -> call Item.updata();
*/
class Item
{
public:
	enum class Type
	{
		Item = 1,
		Weapon = 2,
		Armor = 3,
		Usitem = 4
		
	};
	string TypeToString();
	friend class Weapon;
	friend class Usitem;
	friend class Armor;
	friend class Bag;
private:
	Type type;
	
public:
	string id;
	class NAME
	{
	private:
		string name;
	public:
		bool set(string come);
		string show();
		NAME();
	}name;//名字  

	class DES
	{
	private:
		string des;
	public:
		bool set(string come);
		string show();
		DES();
	}des;//描述

	class LV
	{
	private:
		int lv;
		int slv;//物品使用等级
	public:
		bool set(int come);
		bool setslv(int come);
		bool add(int come);
		bool addslv(int come);
		bool sub(int come);
		bool subslv(int come);
		int show();
		int showslv();
		LV();
	}lv;//物品等级 

	class NUM
	{
	private:
		int num;
	public:
		bool set(int come);
		bool add(int come);
		bool sub(int come);
		int show();
		NUM();
	}num;//物品数量  

	virtual Type typeshow();

	void updata();
	
	Item();
};
class Weapon :public Item
{
public:
	int atk;
	bool ifon;//是否装备
	virtual void on() = 0;
	virtual void down() = 0;
	virtual void fight() = 0;
	Weapon();
	~Weapon();
};
class Armor :public Item
{
public:
	int dfs;
	bool ifon;//是否装备
	virtual void on() = 0;
	virtual void down() = 0;
	virtual void fight() = 0;
	Armor();
	~Armor();
};
class Usitem :public Item
{
	virtual void use() = 0;
	Usitem();
};
class Bag
{
private:
	vector<Item*> Ibag;
	vector<Weapon*> Wbag;
	vector<Armor*> Abag;
	vector<Usitem*> Ubag;
public:
	void Iadd(Item* item, int come);
	void Isub(Item* item, int come);
	Item* Ishow(int name);
	Item* Ishow(string name);
	int Isize();

	void Wadd(Weapon* weapon, int come);
	void Wsub(Weapon* weapon);
	Weapon* Wshow(int name);
	Weapon* Wshow(string name);
	int Wsize();

	void Aadd(Armor* armor, int come);
	void Asub(Armor* armor);
	Armor* Ashow(int name);

	void Uadd(Usitem* usitem, int come);
	void Usub(Usitem* usitem, int come);
	Usitem* Ushow(int name);

	void add(Item* item,int come);
	void sub(Item* item, int come);
	void show(Item* item);
	void show(string name);

	Bag();
	~Bag();
};
class Player
{
public:
	Bag b;
	class NAME
	{
	private:
		string name;
	public:
		bool set(string come);
		string show();
		NAME();
	}name;//名字

	class ATK
	{
	private:
		int atk;
	public:
		bool set(int come);
		bool add(int come);
		bool sub(int come);
		int show();
		ATK();
	}atk;//攻击 

	class DFS
	{
	private:
		int dfs;
	public:
		bool set(int come);
		bool add(int come);
		bool sub(int come);
		int show();
		DFS();
	}dfs;//防御 

	class HP
	{
	private:
		int hp;//血量
		int mhp;//血量上限 
	public:
		bool setmax(int come);
		bool set(int come);
		bool addmax(int come);
		bool add(int come);
		bool submax(int come);
		bool sub(int come);
		int showmax();
		int show();
		HP();
	}hp;//血量

	class LV
	{
	private:
		int lv;//等级 
		int xp;//经验 
		int mxp;//升级经验 
	public:
		bool set(int come);
		bool setxp(int come);
		bool setmxp(int come);
		bool add(int come);
		bool addxp(int come);
		bool addmxp(int come);
		bool sub(int come);
		bool subxp(int come);
		bool submxp(int come);
		int lvupneed();
		bool lvup();
		int show();
		int showlv();
		int showxp();
		int showmxp();
		LV();
	}lv;//等级

	class COLOR
	{
	public:
		enum class Color :char
		{
			bule = '9',
			green = 'a',
			lessgreen = '2',
			red = '4',
			purpel = '5',
			yellow = '6',
			white = '7',
			grey = '8',
			lessbule = 'b'
		};
	private:
		Color color;
	public:
		void set(Color come);
		Color show();
		COLOR();
	}color;//颜色

	class MONEY
	{
	private:
		int mon;
	public:
		bool set(int come);
		bool add(int come);
		bool sub(int come);
		int show();
		MONEY();
	}mon;//金钱 

	class GEAR
	{
	private:
		int gear;
		int maxgear;
	public:
		GEAR();
	}gear;//装备数量

	
	Player();
};
extern Player p;
void ti(string come);
Player::COLOR::Color stcolor(const std::string& str);
void start(string title);
bool bfinditem(string name);
Item* finditem(string name);
bool isnumber(string str);