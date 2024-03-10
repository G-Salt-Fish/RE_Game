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
#include <string>
#include <unordered_map>

#define pause system("pause")
#define cls system("cls")

using namespace std;

const string _joker_version{ "1.0.0.0" };
class Player;
class Item;
class Bag;
class Weapon;

#define NEW_ITEM(T) \
	ItemMap[#T] = []() -> Item* { return new T; };

extern map<string, Item* (*)()> ItemMap;

class Item
{
public:
	enum class Type 
	{
		Item=1,
		Weapon=2,
		Armor=3,
		Usitem=4
	};
	friend class Weapon;
	friend class Usitem;
	friend class Armor;
	friend class Bag;
private:
	Type type;
public:
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

	Item();
};
class Weapon :public Item
{
public:
	int atk;
	bool ifon;//�Ƿ�װ��
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
	bool ifon;
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

	void Wadd(Weapon* weapon, int come);
	void Wsub(Weapon* weapon);
	Weapon* Wshow(int name);

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
	};//װ������
	Player();
};
extern Player p;
void ti(string come);
Player::COLOR::Color stcolor(const std::string& str);
void start(string title);
bool bfinditem(string name);
Item* finditem(string name);