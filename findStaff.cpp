#include "Functions.h"

void findStaff(string num)
{
	Staff* s = NULL;
	bool found = false;	//标识是否找到对应员工，默认值false

	//先在正式员工列表中查找
	for (auto x : oStaffList)
	{
		if (x.m_get_num() == num)
		{
			//x.m_display();
			s = &x;
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
				//x.m_display();
				s = &x;
				found = true;	//同时标识已找到对应员工
				break;	//找到则终止查询
			}
		}
	}
	//若在两个列表中都未找到对应员工，输出提示信息并返回主菜单
	if (!found)
		cout << "未找到相关员工!" << endl;
	else
		s->m_display(0);
}