## ����
��������ʹ��joker������������ǰ��Ӧ�ÿ����ĵ�  
��������������ʹ����  
����������κ����⣬��ô���Ȳ鿴�ĵ�  
���������˲�ȷ����joker�������뷢�ʼ�:GLM9527@outlook.com

## ��������{#��������}

### Դ�ļ��������� {#Դ�ļ�����}
������õ���joker��Դ�ļ�Ҳ����joker.h��.cpp��ô������  
������ǣ�����ת��[DLL��������](#DLL��������)  
  
��Ӧ��Ҫ��һ���ļ�`Item.h`Ӧ�������е���Ʒ��.h�ļ�  
������·���Ƽ�Ϊ:head\Item\Item.h  
Item.h��Ӧ����static void All_Item()����  
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
��������������Ч��  

### DLL�������� {#DLL����}
������õ���joker��DLL�ļ�Ҳ����joker.dll��.lib��.h��ô������  
������ǣ�����ת��[Դ�ļ���������](#Դ�ļ�����)

## ��δ���һ����Ʒ
### ��Ʒ
��Ҫ����һ����Ʒ���Ϳ����ڻ��������е�static void All_Item()����������  
Ȼ���������������ʹ��`NEW_ITEM(xx);`��ע��һ����Ʒ  
����Ӧ��main()�����е���  
�����뿴[��������](#��������)  
�ڸ���Ʒ��class�У������ͨ��������������ʼ������Ʒ�����ñ���  
����Ʒ��.h�ļ�Ӧ��Item.h��ͬһĿ¼��
���磺
```c++
#include<Item.h>
class wood : public Item
{
	wood()
	{
		name="ľͷ";
		...//�����ı���
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
������ͬ���̳�Usitem
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
		name="ľ��";
		...//�����ı���
	}
}
```

### ��ʹ����Ʒ
ͬ���̳�Usitem
������һ������  
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
