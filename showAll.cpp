#include "Functions.h"

//列出所有员工信息
void showAll()
{
	int type(-1);
	system("cls");
	cout << "0.纵向显示员工信息\n1.横向显示员工信息\n默认纵向(0)\n";
	cin >> type;
	while (type != 0 && type != 1)
	{
		cout << "输入错误，请重新输入：";
		cin >> type;
	}
	//根据输入确定显示方式
	if (type == 0)
	{
		//显示正式员工信息
		cout << endl << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			it->m_display();
		}
		//显示临时员工信息
		cout << endl << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			it->m_display();
		}
	}
	else if (type == 1)	//横向显示每个员工信息
	{
		//显示正式员工信息
		cout << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			it->m_display(1);
		}
		//显示临时员工信息
		cout << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			it->m_display(1);
		}
	}
}