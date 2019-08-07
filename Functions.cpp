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
		{	//若输入值不为0或1,继续循环
			cout << "输入错误，请重新输入：";
			cin >> t;
		}
	}

	//在正式员工列表中查找
	bool findOfficialStaff(string& num, int* ret)
	{	//第二参数为默认参数，删除时用于标记查找的对象位置
		for (auto x : oStaffList)
		{	//遍历正式员工数组
			if (ret != NULL)
				* ret += 1;	//若第二参数不为NULL则自加1
			if (x.m_get_num() == num)
			{
				cout << "找到员工：\n" << endl;
				x.m_display();	//查找到对应员工并显示其信息
				return true;	//查找到返回true
			}
		}
		return false;
	}

	//在临时员工列表中查找
	bool findTempStaff(string& num, int* ret)
	{	//第二参数为默认参数，删除时用于标记查找的对象位置
		for (auto x : tStaffList)
		{	//遍历临时员工数组
			if (ret != NULL)
				* ret += 1;	//若第二参数不为NULL则自加1
			if (x.m_get_num() == num)
			{
				cout << "找到员工：" << endl;
				x.m_display();	//查找到对应员工并显示其信息
				return true;	//查找到返回true
			}
		}
		return false;	//遍历完数组仍未找到则返回false
	}

	//添加新临时员工
	void newTempStaff(string& num)
	{
		Tempstaff* ts = new Tempstaff;	//临时员工的临时对象
		ts->m_set_num(num);	//设置员工编号
		ts->m_input();	//输入临时员工信息
		ts->m_display(0);	//显示新员工信息
		tStaffList.push_back(*ts);	//将此临时对象插入列表
		delete ts;
	}

	//添加新正式员工
	void newOfficialStaff(string& num)
	{
		Officialstaff* ost = new Officialstaff;	//正式员工的临时对象
		ost->m_set_num(num);	//设置员工编号
		ost->m_input();	//输入正式员工信息
		ost->m_display(0);	//显示新员工信息
		oStaffList.push_back(*ost);	//将此临时对象插入列表
		delete ost;
	}

	//确认删除临时员工
	void conformDelTemp(int& i)
	{	//参数 i 即为要删除的对象所在位置
		int opt;
		cout << "\n确认删除员工" << (tStaffList.begin() + i)->m_get_name() 	//显示员工姓名
			<< "?\n\n0.取消\t1.确认\n";
		cin >> opt;
		inputCheck(opt);	//输入检查
		if (opt == 0)	//取消删除
			cout << "已取消!" << endl;
		else
		{	//确认删除
			tStaffList.erase(tStaffList.begin() + i);	//用erase方法删除，参数类型为迭代器
			cout << "已删除!" << endl;
		}
		system("pause");	//暂停，显示信息等待用户按键确认
	}

	//确认删除正式员工
	void conformDelOfficial(int& i)
	{	//参数 i 为要删除的对象所在位置
		int opt;
		cout << "\n确认删除员工" << (oStaffList.begin() + i)->m_get_name()	//显示员工姓名
			<< "?\n\n0.取消\t1.确认\n";
		cin >> opt;
		inputCheck(opt);	//输入检查
		if (opt == 0)
			cout << "已取消!" << endl;
		else
		{	//根据i的值确定需要删除的员工位置
			oStaffList.erase(oStaffList.begin() + i);	//用erase方法删除，参数类型为迭代器
			cout << "已删除!" << endl;
		}
		system("pause");	//暂停，显示信息等待用户按键确认
	}

	//依次输出字符串所有字符
	void print(const string& str)
	{
		for (auto i : str)
		{	//遍历每个字符
			cout << i;
			Sleep(35);	//每个字符输出间隔35毫秒
		}
	}
}
