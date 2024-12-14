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

#include "head\Place\place.h"

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
class Place;

#define NEW_ITEM(T) \
	ItemMap[#T] = []() -> Item* { return new T; }; 

#define C_ITEM(T) \
	 id = #T;

extern map<string, Item* (*)()> ItemMap;

extern map<string, Item* (*)()> ItemNameMap;



class Event
{
private:
	vector<void(*)()> event;
public:
	Event();
	~Event();
};//�����֮࣬��Ҫ���廯 -> Ҫ��ʵ��
/*
	get Item -> Itemȥע�����Ӧ���¼�
	get into water_town -> call Item.updata();
*/

class Place
{
private:
	Place* father;
	vector<Place*> son;
	Event event;
public:
	bool set_father(Place*);
	bool add(Place*);
	bool sub(Place*);
	/*virtual void enter();
	virtual void leave();*/
	Place();
	Place(Place* F, vector<Place*> S);
	~Place();
};

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
	}name;//����  

	class DES
	{
	private:
		string des;
	public:
		bool set(string come);
		string show();
		DES();
	}des;//����

	class LV
	{
	private:
		int lv;
		int slv;//��Ʒʹ�õȼ�
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
	}lv;//��Ʒ�ȼ� 

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
	}num;//��Ʒ����  

	virtual Type typeshow();

	virtual void updata();
	
	Item();
};
class Weapon :public Item
{
public:
	int atk;
	bool ifon;//�Ƿ�װ��
	virtual void on(Player*) = 0;//װ��
	virtual void down(Player*) = 0;//ж��
	virtual void fightstart() = 0;//ս����ʼ
	virtual void fightupdate() = 0;//ս��ÿ�غϸ���
	virtual void fightend() = 0;//ս������
	Weapon();
	~Weapon();
};
class Armor :public Item
{
public:
	int dfs;
	bool ifon;//�Ƿ�װ��
	virtual void on() = 0;//װ��
	virtual void down() = 0;//ж��
	virtual void fightstart() = 0;//ս����ʼ
	virtual void fightupdate() = 0;//ս��ÿ�غϸ���
	virtual void fightend() = 0;//ս������
	Armor();
	~Armor();
};
class Usitem :public Item
{
public:
	virtual void use(Player*) = 0;
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
	Armor* Ashow(string name);
	int Asize();

	void Uadd(Usitem* usitem, int come);
	void Usub(Usitem* usitem, int come);
	Usitem* Ushow(int name);
	Usitem* Ushow(string name);
	int Usize();

	void add(Item* item,int come);
	void sub(Item* item, int come);
	Item* show(string name);

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
	}name;//����

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
	}atk;//���� 

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
	}dfs;//���� 

	class HP
	{
	private:
		int hp;//Ѫ��
		int mhp;//Ѫ������ 
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
	}hp;//Ѫ��

	class LV
	{
	private:
		int lv;//�ȼ� 
		int xp;//���� 
		int mxp;//�������� 
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
	}lv;//�ȼ�

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
	}color;//��ɫ

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
	}mon;//��Ǯ 

	class GEAR
	{
	private:
		int gear;
		int maxgear;
	public:
		GEAR();
	}gear;//װ������

	
	Player();
};
extern Player p;
void ti(string come);
Player::COLOR::Color stcolor(const std::string& str);
void start(string title);
bool bfinditem(string name);//������Ʒ�Ƿ������ݿ���
Item* finditem(string name);//������Ʒ�����ݿ��е�ָ��
bool isnumber(string str);