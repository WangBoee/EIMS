#include "Functions.h"

using namespace std;

//先在正式员工列表中查找
void findOfficialStaff(string num)
{
	bool found = false;	//标识是否找到对应员工，默认值false
	for (auto x : oStaffList)
	{
		if (x.m_get_num() == num)
		{
			x.m_display();
			found = true;	//同时标识已找到对应员工
			break;	//找到则终止查询
		}
	}
	//若在列表中都未找到对应员工，输出提示信息并返回主菜单
	if (!found)
		cout << "未找到相关员工!" << endl;
	system("pause");
}


//在临时员工列表中查找
void findTempStaff(string num)
{
	bool found = false;	//标识是否找到对应员工，默认值false
	for (auto x : tStaffList)
	{
		if (x.m_get_num() == num)
		{
			x.m_display();
			found = true;	//同时标识已找到对应员工
			break;	//找到则终止查询
		}
	}
	if (!found)
		cout << "未找到相关员工!" << endl;
	system("pause");
}