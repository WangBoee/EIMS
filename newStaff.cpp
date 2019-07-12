#include "Functions.h"

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;

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
