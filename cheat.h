#pragma once
#include "joker.h"

void cheat()
{
	ti("控制台");
	while (true)
	{
		cout << endl;
		cout << '>';
		string cmd1;
		cin >> cmd1;
		if (cmd1 == "exit")
		{
			return;
		}
		else if (cmd1 == "cmd")
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
		else if (cmd1 == "color")
		{
			string cmd2;
			cin >> cmd2;
			Player::COLOR::Color temp;
			temp = p.color.show();
			p.color.set(stcolor(cmd2));
			if (p.color.show() != temp)
			{
				cout << "操作成功！";
			}
			else
			{
				cout << "操作失败！";
			}
		}
		else if (cmd1 == "player")
		{
			string cmd2;
			cin >> cmd2;
			if (cmd2 == "name")
			{
				string cmd3;
				cin >> cmd3;
				if (cmd3 == "set")
				{
					string cmd4;
					cin >> cmd4;
					if (p.name.set(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "show")
				{
					cout << p.name.show();
				}
				else
				{
					cout << "命令未找到！";
				}
			}
			else if (cmd2 == "atk")
			{
				string cmd3;
				cin >> cmd3;
				if (cmd3 == "set")
				{
					int cmd4;
					cin >> cmd4;
					if (p.atk.set(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "add")
				{
					int cmd4;
					cin >> cmd4;
					if (p.atk.add(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "sub")
				{
					int cmd4;
					cin >> cmd4;
					if (p.atk.sub(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "show")
				{
					cout << p.atk.show();
				}
				else
				{
					cout << "命令未找到！";
				}
			}
			else if (cmd2 == "dfs")
			{
				string cmd3;
				cin >> cmd3;
				if (cmd3 == "set")
				{
					int cmd4;
					cin >> cmd4;
					if (p.dfs.set(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "add")
				{
					int cmd4;
					cin >> cmd4;
					if (p.dfs.add(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "sub")
				{
					int cmd4;
					cin >> cmd4;
					if (p.dfs.sub(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "show")
				{
					cout << p.dfs.show();
				}
				else
				{
					cout << "命令未找到！";
				}
			}
			else if (cmd2 == "hp")
			{
				string cmd3;
				if (cmd3 == "set")
				{
					int cmd4;
					cin >> cmd4;
					if (p.hp.set(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "setmax")
				{
					int cmd4;
					cin >> cmd4;
					if (p.hp.setmax(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "add")
				{
					int cmd4;
					cin >> cmd4;
					if (p.hp.add(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "addmax")
				{
					int cmd4;
					cin >> cmd4;
					if (p.hp.addmax(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "sub")
				{
					int cmd4;
					cin >> cmd4;
					if (p.hp.sub(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "submax")
				{
					int cmd4;
					cin >> cmd4;
					if (p.hp.submax(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "show")
				{
					cout << p.hp.show() << endl;
				}
				else if (cmd3 == "show")
				{
					cout << p.hp.showmax() << endl;
				}
			}
			else if (cmd2 == "lv")
			{
				string cmd3;
				cin >> cmd3;
				if (cmd3 == "set")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.set(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "setxp")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.setxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "setmxp")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.setmxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "add")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.add(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "addxp")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.addxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "addmxp")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.addmxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "sub")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.sub(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "sub")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.sub(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "subxp")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.subxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "submxp")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.submxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "lvupneed")
				{
					int cmd4;
					cin >> cmd4;
					cout << p.lv.lvupneed() << endl;
				}
				else if (cmd3 == "lvup")
				{
					int cmd4;
					cin >> cmd4;
					if (p.lv.submxp(cmd4))
					{
						cout << "操作成功！";
					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "show")
				{
					cout << p.lv.show() << endl;
				}
				else if (cmd3 == "showxp")
				{
					cout << p.lv.showxp() << endl;
				}
				else if (cmd3 == "showmxp")
				{
					cout << p.lv.showmxp() << endl;
				}
			}
			else if (cmd2 == "bag")
			{
				string cmd3;
				cin >> cmd3;
				if (cmd3 == "add")
				{
					string cmd4;
					cin >> cmd4;
					if (bfinditem(cmd4))
					{
						p.b.add(finditem(cmd4), 1);

					}
					else
					{
						cout << "操作失败！";
					}
				}
				else if (cmd3 == "show")
				{
					cout << p.b.Ishow(0)->name.show();
				}
			}
		}
		else if (cmd1 == "version")
		{
			cout << _joker_version;
		}
		else
		{
			cout << "命令未找到！";
		}
	}
}
