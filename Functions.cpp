#include "officialStaff.h"
#include "Staff.h"
#include "tempStaff.h"
#include "Functions.h"
#include <Windows.h>
using namespace std;

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;	//正式员工列表

//主菜单界面
void menu()
{
	/*	TO DO:
	0.添加修改员工信息选项（功能）
	*/
	cout << endl
		<< "1.查看员工信息" << endl
		<< "2.录入员工信息" << endl
		<< "3.删除员工信息" << endl
		<< "0.退出" << endl
		<< "输入选项：";
}

//查看员工信息
void checkInfo()
{
	/*	TO DO:
	0.以不同方式显示员工信息（横向、纵向）
	1.列出所有员工信息
	2.完善查找逻辑
	*/
	cout << "========查询员工信息=======" << endl << endl;
	
	//TEST list all staffs info
	//for (auto x : oStaffList)
	//{
	//	cout << "OfficialList" << endl;
	//	x.m_display();
	//	cout << endl;
	//}

	//for (auto x : tStaffList)
	//{
	//	cout << "TempList" << endl;
	//	x.m_display();
	//	cout << endl;
	//}

	string num;	//临时存储输入编号
	bool found = false;	//标识是否找到对应员工，默认值false
	cout << "输入员工编号:";
	cin >> num;

	//先在正式员工列表中查找
	for (auto x : oStaffList)
	{
		if (x.m_get_num() == num)
		{
			x.m_display(0);	//找到则输出员工信息
			found = true;	//同时标识已找到对应员工
			break;	//找到则终止查询
		}
	}
	//若已找到则不会在临时员工列表中查找
	if (!found)
	{
		//在临时员工列表中查找
		for (auto x : tStaffList)
		{
			if (x.m_get_num() == num)
			{
				x.m_display();	//找到则输出员工信息
				found = true;	//同时标识已找到对应员工
				break;	//找到则终止查询
			}
		}
	}
	//若在两个列表中都未找到对应员工，输出提示信息并返回主菜单
	if (!found)
		cout << "未找到相关信息!" << endl;
	else
	{
		
	}
	system("pause");
}

void editInfo()
{
	//TO DO
}

//添加新员工
void newStaff()
{
	/*	TO DO:
	0.查询到列出员工信息  √
	1.查询员工是否已存在列表
	2.输入容错处理
	*/

	//提示信息
	cout << "========录入新的员工=======" << endl << endl
		<< "0.临时员工\n1.正式员工\n";

	while (true)
	{
		int typ;	//临时存储员工类型，0表示临时员工，1表示正式员工
		cout << "输入员工类型:";
		cin >> typ;
		if (typ == 0)
		{
			Tempstaff ts;	//临时员工的临时对象
			ts.m_input();	//输入临时员工信息
			ts.m_display(0);//debug
			system("pause");
			tStaffList.push_back(ts);	//将此临时对象插入列表
			break;
		}
		else if (typ == 1)
		{
			Officialstaff ost;	//正式员工的临时对象
			ost.m_input();	//输入正式员工信息
			ost.m_display();//debug
			system("pause");
			oStaffList.push_back(ost);	//将此临时对象插入列表
			break;
		}
		else
		{	//错误输入提示，并要求重新输入直到正确输入
			cout << "输入错误，请重新输入!\n";
		}
	}
}

//删除员工 
void deleteStaff()
{
	/*	TO DO:
	0.补全注释
	1.容错处理
	2.根据多种方式查找（编号，姓名）
	3.员工类型输入错误 处理逻辑
	*/

	short typ;	//1表示正式员工，0表示临时员工
	int opt = 0;	//让用户确认是否删除，默认不删除
	string num;	//临时存储输入编号
	bool found = false;	//标识是否找到对应员工，默认值false

	cout << "========删除员工信息=======" << endl << endl;

	cout << "输入员工类型:";
	cin >> typ;

	if (typ == 0)
	{
		cout << "输入员工编号:";
		cin >> num;
		for (vector<Tempstaff>::iterator it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			if (it->m_get_num() == num)
			{
				found = true;
				cout << "找到对应员工\n";
				it->m_display(1);
				cout << "\n确认删除员工" << it->m_get_name() << "?\n\n0.取消\t1.确认\n";
				cin >> opt;
				if (opt)
				{
					tStaffList.erase(it);
					cout << "已删除!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "已取消!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "未找到该员工!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else if (typ == 1)
	{
		cout << "输入员工编号:";
		cin >> num;
		for (vector<Officialstaff>::iterator it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			if (it->m_get_num() == num)
			{
				found = true;
				cout << "找到对应员工\n";
				//TO DO: 横向、纵向显示员工信息
				{

				}
				it->m_display();
				cout << "\n确认删除员工" << it->m_get_name() << "?\n\n0.取消\t1.确认\n";
				cin >> opt;
				if (opt)
				{
					oStaffList.erase(it);
					cout << "已删除!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "已取消!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "未找到该员工!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else
	{
		cout << "输入错误，即将返回主菜单!" << endl;
		system("ping 127.1 -n 3 >nul");
	}
}

void print(const string& str)
{
	for (auto i : str)
	{
		cout << i;
		Sleep(35);
	}
}