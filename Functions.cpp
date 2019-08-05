#include "officialStaff.h"
#include "Staff.h"
#include "tempStaff.h"
#include "Functions.h"
#include <Windows.h>

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
	//在正式员工列表中查找
	bool findOfficialStaff(string& num, int* ret)
	{
		for (auto x : oStaffList)
		{
			if (ret != NULL)
				* ret += 1;
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
	bool findTempStaff(string& num, int* ret)
	{
		for (auto x : tStaffList)
		{
			if (ret != NULL)
				* ret += 1;
			if (x.m_get_num() == num)
			{
				cout << "找到员工：" << endl;
				x.m_display();
				return true;
			}
		}
		return false;
	}
	//添加新临时员工
	void newTempStaff(string& num)
	{
		Tempstaff* ts = new Tempstaff;	//临时员工的临时对象
		ts->m_set_num(num);	//设置员工编号
		ts->m_input();	//输入临时员工信息
		ts->m_display(0);
		tStaffList.push_back(*ts);	//将此临时对象插入列表
		delete ts;
	}
	//添加新正式员工
	void newOfficialStaff(string& num)
	{
		Officialstaff* ost = new Officialstaff;	//正式员工的临时对象
		ost->m_set_num(num);	//设置员工编号
		ost->m_input();	//输入正式员工信息
		ost->m_display(0);
		oStaffList.push_back(*ost);	//将此临时对象插入列表
		delete ost;
	}
	//确认删除临时员工
	void conformDelTemp(int& i)
	{
		int opt;
		cout << "\n确认删除员工" << (tStaffList.begin() + i)->m_get_name() << "?\n\n0.取消\t1.确认\n";
		cin >> opt;
		inputCheck(opt);
		if (opt == 0)	//取消删除
			cout << "已取消!" << endl;
		else
		{	//确认删除
			tStaffList.erase(tStaffList.begin() + i);
			cout << "已删除!" << endl;
		}
		system("pause");
	}
	//确认删除正式员工
	void conformDelOfficial(int& i)
	{
		int opt;
		cout << "\n确认删除员工" << (oStaffList.begin() + i)->m_get_name()
			<< "?\n\n0.取消\t1.确认\n";	//显示员工姓名
		cin >> opt;
		inputCheck(opt);
		if (opt == 0)
			cout << "已取消!" << endl;
		else
		{	//根据i的值确定需要删除的员工位置
			oStaffList.erase(oStaffList.begin() + i);
			cout << "已删除!" << endl;
		}
		system("pause");
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
}
