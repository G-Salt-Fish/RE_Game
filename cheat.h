#pragma once
#include "joker.h"

void cheat_bagshow(Item* item);

void cheat()
{
	ti("����̨");
	while (true)
	{
		cin.clear();
		cout << endl;
		cout << '>';
		string args;
		vector<string> cmd;
		getline(cin, args);
		istringstream iss(args);
		while (std::getline(iss, args, ' ')) {
			cmd.push_back(args);
		}
		int size = cmd.size();
		if (size >= 1 && cmd[0] == "exit")
		{
			return;
		}
		else if (size >= 1 && cmd[0] == "cmd")
		{
			while (true)
			{
				cout << ">>";
				string cmdd;
				getline(cin, cmdd);
				if (cmdd == "exit")
				{
					break;
				}
				const char* cstr = cmdd.c_str();
				system(cstr);
			}
		}
		else if (size >= 1 && cmd[0] == "color")
		{
			if (size >= 2)
			{
				
				
				
				COLOR::Color temp;
				temp = p.color.show();
				p.color.set(stcolor(cmd[1]));
				if (p.color.show() != temp)
				{
					cout << "�����ɹ���";
				}
				else
				{
					cout << "����ʧ�ܣ�";
				}
			}
			else
			{
				cout << "�������Ӧ��ɫ��";
			}

		}
		else if (size >= 1 && cmd[0] == "player")
		{
			if (size >= 2 && cmd[1] == "name")
			{
				if (size >= 3 && cmd[2] == "set")
				{
					if (size >= 4)
					{
						if (p.name.set(cmd[3]))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
				}
				else if (size >= 3 && cmd[2] == "show")
				{
					cout << p.name.show();
				}
				else
				{
					cout << "����δ�ҵ���";
				}
			}
			else if (size >= 2 && cmd[1] == "atk")
			{
				if (size >= 3 && cmd[2] == "set")
				{
					if (size >= 4)
					{
						if (p.atk.set(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "add")
				{
					if (size >= 4)
					{
						if (p.atk.add(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "sub")
				{
					if (size >= 4)
					{
						if (p.atk.sub(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "show")
				{
					cout << p.atk.show();
				}
				else
				{
					cout << "����δ�ҵ���";
				}
			}
			else if (size >= 2 && cmd[1] == "dfs")
			{
				if (size >= 3 && cmd[2] == "set")
				{
					if (size >= 4)
					{
						if (p.dfs.set(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "add")
				{
					if (size >= 4)
					{
						if (p.dfs.add(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "sub")
				{
					if (size >= 4)
					{
						if (p.dfs.sub(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "show")
				{
					cout << p.dfs.show();
				}
				else
				{
					cout << "����δ�ҵ���";
				}
			}
			else if (size >= 2 && cmd[1] == "hp")
			{
				if (size >= 3 && cmd[2] == "set")
				{
					if (size >= 4)
					{
						if (p.hp.set(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "setmax")
				{
					if (size >= 4)
					{
						if (p.hp.setmax(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "add")
				{
					if (size >= 4)
					{
						if (p.hp.add(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "addmax")
				{
					if (size >= 4)
					{
						if (p.hp.addmax(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "sub")
				{
					if (size >= 4)
					{
						if (p.hp.sub(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "submax")
				{
					if (size >= 4)
					{
						if (p.hp.submax(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "show")
				{
					cout << p.hp.show();
				}
				else if (size >= 3 && cmd[2] == "showmax")
				{
					cout << p.hp.showmax();
				}
			}
			else if (size >= 2 && cmd[1] == "lv")
			{
				if (size >= 3 && cmd[2] == "set")
				{
					if (size >= 4)
					{
						if (p.lv.set(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "setxp")
				{
					if (size >= 4)
					{
						if (p.lv.setxp(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "setmxp")
				{
					if (size >= 4)
					{
						if (p.lv.setmxp(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "add")
				{
					if (size >= 4)
					{
						if (p.lv.add(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "addxp")
				{
					if (size >= 4)
					{
						if (p.lv.addxp(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "addmxp")
				{
					if (size >= 4)
					{
						if (p.lv.addmxp(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "sub")
				{
					if (size >= 4)
					{
						if (p.lv.sub(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "subxp")
				{
					if (size >= 4)
					{
						if (p.lv.subxp(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "submxp")
				{
					if (size >= 4)
					{
						if (p.lv.submxp(stoi(cmd[3])))
						{
							cout << "�����ɹ���";
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "����δ�ҵ���";
					}
				}
				else if (size >= 3 && cmd[2] == "lvupneed")
				{
					cout << p.lv.lvupneed() << endl;
				}
				else if (size >= 3 && cmd[2] == "lvup")
				{
					if (p.lv.lvup())
					{
						cout << "�����ɹ���";
					}
					else
					{
						cout << "����ʧ�ܣ�";
					}
				}
				else if (size >= 3 && cmd[2] == "show")
				{
					cout << p.lv.show();
				}
				else if (size >= 3 && cmd[2] == "showxp")
				{
					cout << p.lv.showxp();
				}
				else if (size >= 3 && cmd[2] == "showmxp")
				{
					cout << p.lv.showmxp();
				}
			}
			else if (size >= 2 && cmd[1] == "bag")
			{
				if (size >= 3 && cmd[2] == "add")
				{
					if (size >= 4)
					{
						if (bfinditem(cmd[3]))
						{
							p.b.add(finditem(cmd[3]), 1);
						}
						else
						{
							cout << "����ʧ�ܣ�";
						}
					}
					else
					{
						cout << "��������Ʒ����";
					}
				}
				if (size >= 3 && cmd[2] == "sub")
				{
					if (size >= 4)
					{
						if (bfinditem(cmd[3]))
						{
							Item::Type type;
							type = finditem(cmd[3])->typeshow();
							switch (type)
							{
							case Item::Type::Item:
								p.b.Isub(p.b.Ishow(cmd[3]), 1);
								break;
							case Item::Type::Weapon:
								p.b.Wsub(p.b.Wshow(cmd[3]));
								break;
							case Item::Type::Armor:
								p.b.Asub(p.b.Ashow(cmd[3]));
								break;
							case Item::Type::Usitem:
								break;
							default:
								break;
							}
						}
					}
				}
				else if (size >= 3 && cmd[2] == "show")
				{
					if (size == 3)
					{
						cout << "��ͨ" << endl;
						if (p.b.Isize() <= 0)
						{
							cout << "����Ʒ��" << endl;
						}
						else
						{
							for (int i = 1; i <= p.b.Isize(); i++)
							{
								cout << p.b.Ishow(i - 1)->name.show() << '(' << p.b.Ishow(i - 1)->id << ')' << p.b.Ishow(i - 1)->num.show() << '\n';
							}
						}
						cout << "����" << endl;
						if (p.b.Wsize() <= 0)
						{
							cout << "��������" << endl;
						}
						else
						{
							for (int i = 1; i <= p.b.Wsize(); i++)
							{
								cout << p.b.Wshow(i - 1)->name.show() << '(' << p.b.Wshow(i - 1)->id << ')' << '\n';

							}
						}
						cout << "����" << endl;
						if (p.b.Asize() <= 0)
						{
							cout << "�޷��ߣ�" << endl;
						}
						else
						{
							for (int i = 1; i <= p.b.Asize(); i++)
							{
								cout << p.b.Ashow(i - 1)->name.show() << '(' << p.b.Ashow(i - 1)->id << ')' << '\n';
							}
						}
						cout << "��ʹ����Ʒ" << endl;
						if (p.b.Usize() <= 0)
						{
							cout << "�޿�ʹ����Ʒ��" << endl;
						}
						else
						{
							for (int i = 1; i <= p.b.Usize(); i++)
							{
								cout << p.b.Ushow(i - 1)->name.show() << '(' << p.b.Ushow(i - 1)->id << ')' << '\n';
							}
						}
					}
					else if (size == 4)
					{
						if (p.b.show(cmd[3]) != nullptr)
						{
							cheat_bagshow(p.b.show(cmd[3]));
						}
						else
						{
							cout << "δ�ҵ���Ʒ��" << endl;
						}
						
					}
					else if (size == 5)
					{
						if (cmd[3] == "Item")
						{

						}
					}
				}
			}
		}
		else if (size >= 1 && cmd[0] == "version")
		{
			cout << _joker_version;
		}
		else
		{
			cout << "����δ�ҵ���";
		}
	}
}


void cheat_bagshow(Item* item)
{
	Item::Type type;
	type = item->typeshow();
	switch (type)
	{
	case Item::Type::Item:
	{
		Item* i;
		i = item;
		cout << "��Ʒ����" << i->name.show() << '\n'
			<< "������" << i->des.show() << '\n'
			<< "������" << i->num.show() << '\n'
			<< "��Ʒ�ȼ���" << i->lv.show() << '\n'
			<< "ʹ�õȼ���" << i->lv.showslv() << endl;

		cout << "���еĲ�����" << '\n'
			<< " 1.����\n 0.�˳�\n";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:

		default:
			cout << "��Ч������" << endl;
		}
	}
	break;
	case Item::Type::Weapon:
	{
		Weapon* i;
		i = dynamic_cast<Weapon*>(item);
		cout << "��������" << i->name.show() << '\n'
			<< "������" << i->des.show() << '\n'
			<< "��������" << i->atk << '\n'
			<< "�����ȼ���" << i->lv.show() << '\n'
			<< "ʹ�õȼ���" << i->lv.showslv() << endl;
	}
		break;
	case Item::Type::Armor:
	{
		Armor* i;
		i = dynamic_cast<Armor*>(item);
		cout << "��������" << i->name.show() << '\n'
			<< "������" << i->des.show() << '\n'
			<< "��������" << i->dfs << '\n'
			<< "���ߵȼ���" << i->lv.show() << '\n'
			<< "ʹ�õȼ���" << i->lv.showslv() << endl;
	}
		break;
	case Item::Type::Usitem:
	{
		Usitem* i;
		i = dynamic_cast<Usitem*>(item);
		cout << "��Ʒ����" << i->name.show() << '\n'
			<< "������" << i->des.show() << '\n'
			<< "��Ʒ�ȼ���" << i->lv.show() << '\n'
			<< "ʹ�õȼ���" << i->lv.showslv() << endl;
	}
		break;
	default:
		break;
	}

}

/*
* Item::Type type;
type = finditem(cmd[3])->typeshow();
switch (type)
{
case Item::Type::Item:
{
				if (p.b.Ishow(cmd[3]) != nullptr)
				{
								Item* i;
								i = p.b.Ishow(cmd[3]);
								cout << "��Ʒ����" << i->name.show() << '\n'
									<< "������" << i->des.show() << '\n'
									<< "������" << i->num.show() << '\n'
									<< "��Ʒ�ȼ���" << i->lv.show() << '\n'
									<< "ʹ�õȼ���" << i->lv.showslv();

								cout << "���еĲ�����" << '\n'
									<< " 1.����\n 0.�˳�\n";
								int choise;
								cin >> choise;
								switch (choise)
								{
								case 1:

								default:
									cout << "��Ч������" << endl;

								}
				}
				else
				{
								cout << "δ�ҵ���Ʒ��" << endl;;
				}

}
break;
case Item::Type::Weapon:
{
				if (p.b.Wshow(cmd[3]) != nullptr)
				{
								Weapon* i;
								i = p.b.Wshow(cmd[3]);
								cout << "��������" << i->name.show() << '\n'
									<< "������" << i->des.show() << '\n'
									<< "��������" << i->atk << '\n'
									<< "�����ȼ���" << i->lv.show() << '\n'
									<< "ʹ�õȼ���" << i->lv.showslv() << endl;
				}
				else
				{
								cout << "δ�ҵ���Ʒ��" << endl;
				}
}
break;
case Item::Type::Armor:
				if (p.b.Ashow(cmd[3]) != nullptr)
				{
								Armor* i;
								i = p.b.Ashow(cmd[3]);
								cout << "��������" << i->name.show() << '\n'
									<< "������" << i->des.show() << '\n'
									<< "��������" << i->dfs << '\n'
									<< "���ߵȼ���" << i->lv.show() << '\n'
									<< "ʹ�õȼ���" << i->lv.showslv() << endl;
				}
				else
				{
								cout << "δ�ҵ���Ʒ��" << endl;
				}
				break;
case Item::Type::Usitem:
				if (p.b.Ushow(cmd[3]) != nullptr)
				{
								Usitem* i;
								i = p.b.Ushow(cmd[3]);
								cout << "��Ʒ����" << i->name.show() << '\n'
									<< "������" << i->des.show() << '\n'
									<< "��Ʒ�ȼ���" << i->lv.show() << '\n'
									<< "ʹ�õȼ���" << i->lv.showslv() << endl;
				}
				break;
default:
				break;
}
*/ 