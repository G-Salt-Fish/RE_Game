## 契子
这是在你使用joker帮助开发工具前最应该看的文档  
这里面包含着如何使用它  
如果遇到了任何问题，那么请先查看文档  
如果解决不了并确定是joker的问题请发邮件:GLM9527@outlook.com

## 环境配置{#环境配置}

### 源文件环境配置 {#源文件配置}
如果你用的是joker的源文件也就是joker.h及.cpp那么看这里  
如果不是，请跳转到[DLL环境配置](#DLL环境配置)  
  
你应该要有一个文件`Item.h`应包含所有的物品的.h文件  
并且其路径推荐为:head\Item\Item.h  
Item.h中应包含static void All_Item()函数  
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
这样会拖慢编译效率  

### DLL环境配置 {#DLL配置}
如果你用的是joker的DLL文件也就是joker.dll及.lib及.h那么看这里  
如果不是，请跳转到[源文件环境配置](#源文件配置)

## 如何创建一个物品
### 物品
想要创建一个物品，就可以在环境配置中的static void All_Item()函数来进行  
然后再在这个函数中使用`NEW_ITEM(xx);`来注册一个物品  
并且应在main()函数中调用  
具体请看[环境配置](#环境配置)  
在该物品的class中，你必须通过构建函数来初始化该物品的所用变量  
该物品的.h文件应和Item.h在同一目录下
例如：
```c++
#include<Item.h>
class wood : public Item
{
	wood()
	{
		name="木头";
		...//其他的变量
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
与武器同理，继承Usitem
```c++
class wood_shield : public Usitem
{
	void on() override
	{
		p.dfs.add(this -> dfs);
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
同理，继承Usitem
但多了一个函数  
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
