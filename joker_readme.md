## 契子
这是在你使用joker帮助开发工具前最应该看的文档  
这里面包含着如何使用它  
如果遇到了任何问题，那么请先查看文档  
在源码当中的cheat.h中有许多的使用示例，但并不完善

## 环境配置{#环境配置}

首先，你需要一个支持c++14或更高的版本的编译器（这似乎是废话），像我们著名的Dev肯定是不行的  
其次，应尽量按照源码的存放格式来写代码，除非你懂得如何合理的利用文件夹以及了解这个文件的作用是什么  



### 源文件环境配置 {#源文件配置}
  
你应该要有一个文件`Item.h`应包含所有的物品的.h文件  
并且其路径推荐为:head\Item\Item.h  
Item.h中应包含`satic void All_Item()`函数  
这是为了方便在开始时统一加载物品  
例如：
```C++
#pragma once
#include "..\..\joker.h"
#include "wood.h"

static void All_Item()
{
	NEW_ITEM(wood);//这是物品的注册
}
```
事实上，并不推荐一个物品对应一个.h文件  
这样会拖慢编译效率，而且也太Java了  

## 如何创建一个物品
### 物品
想要创建一个物品需要`在static void All_Item()`函数使用`NEW_ITEM(xx);`来注册一个物品  
并且在main()函数中调用`All_Item()_`  
具体请看[环境配置](#环境配置)  
在该物品的class中，你必须通过构建函数来初始化该物品的所用变量，还需要使用`C_ITEM(xx);_`来再次注册id  
该物品的.h文件应和Item.h在同一目录下
例如：
```c++
#include<Item.h>
class wood : public Item
{
	wood()
	{
		name.set("木头");
		//此处的名字不能用纯数字
		des.set("木头，木头，木头。");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		C_ITEM(wood);
	}
}
```

### 武器
同理，只需继承Weapon类就行了  
但武器多了3个函数  
void on() 当装备武器时调用
void down() 当卸下武器时调用
void fight() 当攻击时调用
例如：
```c++
class wood_sword : public Weapon
{
	void on() override
	{
		p.atk.add(this -> atk);
	}
	...//其他函数
	wood()
	{
		name="木剑";
		atk=2;
		...//其他的变量
	}
}
```

### 防具
与武器同理，继承Armor
```c++
class wood_shield : public Armor
{
	void on() override
	{
		p.dfs.add(this -> dfs);
	}
	void donw() override
	{
		...
	}
	void fight() override
	{
		...
	}
	wood()
	{
		dfs=2;
		name="木盾";
		...//其他的变量
	}
}
```

### 可使用物品
继承Usitem
但相较Item多了一个函数  
void use() 当使用时调用的函数
```c++
class apple : public Usitem
{
	void use() override
	{
	}
	wood()
	{
		name="苹果";
		...//其他的变量
	}
}
```
