## ����
��������ʹ��joker������������ǰ��Ӧ�ÿ����ĵ�  
��������������ʹ����  
����������κ����⣬��ô���Ȳ鿴�ĵ�  
��Դ�뵱�е�cheat.h��������ʹ��ʾ��������������

## ��������{#��������}

���ȣ�����Ҫһ��֧��c++14����ߵİ汾�ı����������ƺ��Ƿϻ�����������������Dev�϶��ǲ��е�  
��Σ�Ӧ��������Դ��Ĵ�Ÿ�ʽ��д���룬�����㶮����κ���������ļ����Լ��˽�����ļ���������ʲô  



### Դ�ļ��������� {#Դ�ļ�����}
  
��Ӧ��Ҫ��һ���ļ�`Item.h`Ӧ�������е���Ʒ��.h�ļ�  
������·���Ƽ�Ϊ:head\Item\Item.h  
Item.h��Ӧ����`satic void All_Item()`����  
����Ϊ�˷����ڿ�ʼʱͳһ������Ʒ  
���磺
```C++
#pragma once
#include "..\..\joker.h"
#include "wood.h"

static void All_Item()
{
	NEW_ITEM(wood);//������Ʒ��ע��
}
```
��ʵ�ϣ������Ƽ�һ����Ʒ��Ӧһ��.h�ļ�  
��������������Ч�ʣ�����Ҳ̫Java��  

## ��δ���һ����Ʒ
### ��Ʒ
��Ҫ����һ����Ʒ��Ҫ`��static void All_Item()`����ʹ��`NEW_ITEM(xx);`��ע��һ����Ʒ  
������main()�����е���`All_Item()_`  
�����뿴[��������](#��������)  
�ڸ���Ʒ��class�У������ͨ��������������ʼ������Ʒ�����ñ���������Ҫʹ��`C_ITEM(xx);_`���ٴ�ע��id  
����Ʒ��.h�ļ�Ӧ��Item.h��ͬһĿ¼��
���磺
```c++
#include<Item.h>
class wood : public Item
{
	wood()
	{
		name.set("ľͷ");
		//�˴������ֲ����ô�����
		des.set("ľͷ��ľͷ��ľͷ��");
		lv.set(1);
		lv.setslv(1);
		num.set(1);
		C_ITEM(wood);
	}
}
```

### ����
ͬ��ֻ��̳�Weapon�������  
����������3������  
void on() ��װ������ʱ����
void down() ��ж������ʱ����
void fight() ������ʱ����
���磺
```c++
class wood_sword : public Weapon
{
	void on() override
	{
		p.atk.add(this -> atk);
	}
	...//��������
	wood()
	{
		name="ľ��";
		atk=2;
		...//�����ı���
	}
}
```

### ����
������ͬ���̳�Armor
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
		name="ľ��";
		...//�����ı���
	}
}
```

### ��ʹ����Ʒ
�̳�Usitem
�����Item����һ������  
void use() ��ʹ��ʱ���õĺ���
```c++
class apple : public Usitem
{
	void use() override
	{
	}
	wood()
	{
		name="ƻ��";
		...//�����ı���
	}
}
```
