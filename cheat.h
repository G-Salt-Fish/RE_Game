#pragma once
#include "joker.h"

void cheat()
{
	ti("����̨");
	while (true)
	{
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
		if (size>=1&&cmd[0] == "exit")
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
				Player::COLOR::Color temp;
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
					cout << p.hp.show() << endl;
				}
				else if (size >= 3 && cmd[2] == "showmax")
				{
					cout << p.hp.showmax() << endl;
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
					cout << p.lv.show() << endl;
				}
				else if (size >= 3 && cmd[2] == "showxp")
				{
					cout << p.lv.showxp() << endl;
				}
				else if (size >= 3 && cmd[2] == "showmxp")
				{
					cout << p.lv.showmxp() << endl;
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
				else if (size >= 3 && cmd[2] == "show")
				{
					if (size == 3)
					{

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

void _cheat()
{
	ti("����̨");
	while (true)
	{
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
		cout << '<';
		
		if (cmd[0] == "exit")
		{
			return;
		}
		else if (cmd[0] == "cmd")
		{
			while (true)
			{
				cout << ">>";
				string cmd2;
				getline(cin, cmd2);
				if (cmd2 == "exit")
				{
					break;
				}
				const char* cstr = cmd2.c_str();
				system(cstr);
			}
		}
		else if (cmd[0] == "color")
		{
			Player::COLOR::Color temp;
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
		else if (cmd[0] == "player")
		{

		}
		
		cout << endl;
	}
}