#include "officialStaff.h"
#include "Staff.h"
#include "tempStaff.h"
#include "Functions.h"
#include "compareStaff.h"
#include <Windows.h>
#include <algorithm>

using namespace XIANGQIAOSHUN;

namespace WANGBOYI {
	//输入检查
	void inputCheck(int& p_t)
	{
		while (p_t != 0 && p_t != 1)
		{	//若输入值不为0或1,继续循环
			cout << "输入错误，请重新输入：";
			cin >> p_t;
		}
	}

	//在正式员工列表中查找
	bool findOfficialStaff(string& p_num, int* p_ret)
	{	//第二参数为默认参数，删除时用于标记查找的对象位置
		for (auto x : oStaffList)
		{	//遍历正式员工数组
			if (p_ret != NULL)
				* p_ret += 1;	//若第二参数不为NULL则自加1
			if (x.m_get_num() == p_num)
			{
				cout << "找到员工：\n" << endl;
				x.m_display();	//查找到对应员工并显示其信息
				return true;	//查找到返回true
			}
		}
		return false;
	}

	//在临时员工列表中查找
	bool findTempStaff(string& p_num, int* p_ret)
	{	//第二参数为默认参数，删除时用于标记查找的对象位置
		for (auto x : tStaffList)
		{	//遍历临时员工数组
			if (p_ret != NULL)
				* p_ret += 1;	//若第二参数不为NULL则自加1
			if (x.m_get_num() == p_num)
			{
				cout << "找到员工：" << endl;
				x.m_display();	//查找到对应员工并显示其信息
				return true;	//查找到返回true
			}
		}
		return false;	//遍历完数组仍未找到则返回false
	}

	//添加新临时员工
	void newTempStaff(string& p_num)
	{
		Tempstaff* ts = new Tempstaff;	//临时员工的临时对象
		ts->m_set_num(p_num);	//设置员工编号
		ts->m_input();	//输入临时员工信息
		ts->m_display(0);	//显示新员工信息
		tStaffList.push_back(*ts);	//将此临时对象插入列表
		delete ts;
	}

	//添加新正式员工
	void newOfficialStaff(string& p_num)
	{
		Officialstaff* ost = new Officialstaff;	//正式员工的临时对象
		ost->m_set_num(p_num);	//设置员工编号
		ost->m_input();	//输入正式员工信息
		ost->m_display(0);	//显示新员工信息
		oStaffList.push_back(*ost);	//将此临时对象插入列表
		delete ost;
	}

	//确认删除临时员工
	void conformDelTemp(int& p_i)
	{	//参数 p_i 即为要删除的对象所在位置
		int opt;
		cout << "\n确认删除员工" << (tStaffList.begin() + p_i)->m_get_name() 	//显示员工姓名
			<< "?\n\n0.取消\t1.确认\n";
		cin >> opt;
		inputCheck(opt);	//输入检查
		if (opt == 0)	//取消删除
			cout << "已取消!" << endl;
		else
		{	//确认删除
			tStaffList.erase(tStaffList.begin() + p_i);	//用erase方法删除，参数类型为迭代器
			cout << "已删除!" << endl;
		}
		system("pause");	//暂停，显示信息等待用户按键确认
	}

	//确认删除正式员工
	void conformDelOfficial(int& p_i)
	{	//参数 p_i 为要删除的对象所在位置
		int opt;
		cout << "\n确认删除员工" << (oStaffList.begin() + p_i)->m_get_name()	//显示员工姓名
			<< "?\n\n0.取消\t1.确认\n";
		cin >> opt;
		inputCheck(opt);	//输入检查
		if (opt == 0)
			cout << "已取消!" << endl;
		else
		{	//根据p_i的值确定需要删除的员工位置
			oStaffList.erase(oStaffList.begin() + p_i);	//用erase方法删除，参数类型为迭代器
			cout << "已删除!" << endl;
		}
		system("pause");	//暂停，显示信息等待用户按键确认
	}

	//依次输出字符串所有字符
	void print(const string& p_str)
	{
		for (auto i : p_str)
		{	//遍历每个字符
			cout << i;
			Sleep(35);	//每个字符输出间隔35毫秒
		}
	}

	//编辑正式员工信息
	void editOS(int& p_i)
	{
		Officialstaff temp;	//创建临时员工对象用于重新输入数据
		cout << "重新输入员工" << (oStaffList.begin() + p_i)->m_get_name() << "(编号：" << (oStaffList.begin() + p_i)->m_get_num() << ")信息\n";
		temp.m_input();
		*(oStaffList.begin() + p_i) = temp;	//将重新输入的数据复制给原员工
		cout << "完成!\n";
	}

	//编辑临时员工信息
	void editTS(int& p_i)
	{
		Tempstaff temp;	//创建临时员工对象用于重新输入数据
		cout << "重新输入员工" << (tStaffList.begin() + p_i)->m_get_name() << "(编号：" << (tStaffList.begin() + p_i)->m_get_num() << ")信息\n";
		temp.m_input();
		*(tStaffList.begin() + p_i) = temp;	//将重新输入的数据复制给原员工
		cout << "完成!\n";
	}

	//默认列表顺序列出员工信息
	void listDef()
	{
		int type(0);
		cout << "0.纵向显示员工信息\n1.横向显示员工信息\n默认纵向(0)\n";
		cin >> type;
		inputCheck(type);
		cout << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{	//显示正式员工信息
			it->m_display(type);	//根据输入确定显示方式
		}
		cout << endl << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{	//显示临时员工信息
			it->m_display(type);	//根据输入确定显示方式
		}
	}

	//根据员工编号列出员工信息
	void listNum()
	{
		int type(0);
		cout << "0.按员工编号升序显示\n1.按员工编号降序显示\n默认升序(0)\n\n输入选择：";
		cin >> type;
		inputCheck(type);
		if (type == 1)
		{	//根据员工编号对正式员工和临时员工列表进行降序排序
			sort(oStaffList.begin(), oStaffList.begin() + oStaffList.size(), comp_num_down_o);
			sort(tStaffList.begin(), tStaffList.begin() + tStaffList.size(), comp_num_down_t);
		}
		else
		{	//根据员工编号对正式员工和临时员工列表进行升序排序
			sort(oStaffList.begin(), oStaffList.begin() + oStaffList.size(), comp_num_o);
			sort(tStaffList.begin(), tStaffList.begin() + tStaffList.size(), comp_num_t);
		}
		cout << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{	//显示正式员工信息
			it->m_display(1);	//横向显示
		}
		cout << endl << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{	//显示临时员工信息
			it->m_display(1);	//横向显示
		}
	}

	//根据员工工资列出员工信息
	void listSal()
	{
		int type(0);
		cout << "0.按员工工资升序显示\n1.按员工工资降序显示\n默认升序(0)\n\n输入选择：";
		cin >> type;
		inputCheck(type);
		if (type == 1)
		{	//根据员工工资对正式员工和临时员工列表进行降序排序
			sort(oStaffList.begin(), oStaffList.begin() + oStaffList.size(), comp_salary_down_o);
			sort(tStaffList.begin(), tStaffList.begin() + tStaffList.size(), comp_salary_down_t);
		}
		else
		{	//根据员工工资对正式员工和临时员工列表进行升序排序
			sort(oStaffList.begin(), oStaffList.begin() + oStaffList.size(), comp_salary_o);
			sort(tStaffList.begin(), tStaffList.begin() + tStaffList.size(), comp_salary_t);
		}
		cout << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
			it->m_display(1);	//横向显示
		cout << endl << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
			it->m_display(1);	//横向显示
	}
}
