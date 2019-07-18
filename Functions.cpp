#include "officialStaff.h"
#include "Staff.h"
#include "tempStaff.h"
#include "Functions.h"
#include <Windows.h>

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;	//正式员工列表

void inputCheck(int& t)
{
	while (t != 0 && t != 1)
	{
		cout << "输入错误，请重新输入：";
		cin >> t;
	}
}

inline void print(const string& str)
{
	for (auto i : str)
	{
		cout << i;
		Sleep(35);
	}
}