#include "officialStaff.h"
#include "Staff.h"
#include "tempStaff.h"
#include "Functions.h"
#include <Windows.h>

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;	//正式员工列表

namespace WANGBOYI {
	//输入检查
	void inputCheck(int& t)
	{
		while (t != 0 && t != 1)
		{
			cout << "输入错误，请重新输入：";
			cin >> t;
		}
	}
	//依次输出字符串所有字符
	void print(const string& str)
	{
		for (auto i : str)
		{
			cout << i;
			Sleep(35);
		}
	}
	//先在正式员工列表中查找
	bool findOfficialStaff(string& num, int* ret = NULL)
	{
		for (auto x : oStaffList)
		{
			if (ret != NULL)
			{
				*ret += 1;
			}
			if (x.m_get_num() == num)
			{
				cout << "找到员工：\n" << endl;
				x.m_display();
				return true;
			}
		}
		return false;
	}
	//在临时员工列表中查找
	bool findTempStaff(string& num, int* ret = NULL)
	{
		for (auto x : tStaffList)
		{
			if (ret != NULL)
			{
				*ret += 1;
			}
			if (x.m_get_num() == num)
			{
				cout << "找到员工：" << endl;
				x.m_display();
				return true;
			}
		}
		return false;
	}
}