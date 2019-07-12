#include "Functions.h"
//修正编码
extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;

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
		if (x.m_num == num)
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
			if (x.m_num == num)
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
