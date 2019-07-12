#include "officialStaff.h"
#include <iostream>
#include <fstream>
#include <vector>

//手动输入信息
void Officialstaff::m_input()
{
	cout << "请输入正式员工的编号" << endl;
	cin >> m_num;
	cout << "请输入正式员工的姓名" << endl;
	cin.get();
	getline(cin, m_name);
	cout << "请输入正式员工的性别(0.女  1.男)" << endl;
	int sex;
	cin >> sex;
	m_sex = sex ? true : false;
	cout << "请输入正式员工的年龄" << endl;
	cin >> m_age;
	cout << "请输入正式员工的基本职务工资" << endl;
	cin >> m_salary;
	cout << "请输入正式员工的家庭住址" << endl;
	cin.get();
	getline(cin, m_home);

	cout << "请输入正式员工的津贴" << endl;
	cin >> m_allowance;
	cout << "请输入正式员工的养老金" << endl;
	cin >> m_annuity;
	cout << "请输入正式员工的住房公积金" << endl;
	cin >> m_fund;
	cout << "请输入正式员工的所得税" << endl;
	cin >> m_tax;
	cout << "请输入正式员工的医疗保险" << endl;
	cin >> m_medical;
	m_calculateSalary();
}

//显示信息
void Officialstaff::m_display(int mode)
{
	//19.6.26 add
	if (mode == 1)
	{//29.7.10 add
		cout << "编号：" << m_num << " " << "姓名：" << m_name << " " << "性别：" << m_sex << " "
			<< "年龄：" << m_age << " " << "工资：" << m_salary << " " << "家庭住址：" << m_home << " "
			<< "津贴：" << m_allowance << " " << "养老金：" << m_annuity << " " << "住房公积金：" << m_fund << " "
			<< "所得税：" << m_tax << " " << "医疗保险：" << m_medical << " " << "实发工资：" << m_real_salary << endl;
	}
	else if (mode == 0)
	{
		cout << "编号：" << m_num << endl
			<< "姓名：" << m_name << endl
			<< "性别：" << m_sex << endl
			<< "年龄：" << m_age << endl
			<< "工资：" << m_salary << endl
			<< "家庭住址：" << m_home << endl
			<< "津贴：" << m_allowance << endl
			<< "养老金：" << m_annuity << endl
			<< "住房公积金：" << m_fund << endl
			<< "所得税：" << m_tax << endl
			<< "医疗保险：" << m_medical << endl
			<< "实发工资：" << m_real_salary << endl;
	}
	else
	{
		cout << "输入错误！" << endl;
	}
}

//默认构造函数
Officialstaff::Officialstaff()
{
	m_num = "-1";
	m_name = "none";
	m_sex = 1;
	m_age = 0;
	m_salary = 0;
	m_home = "none";
	m_allowance = 0;
	m_annuity = 0;
	m_fund = 0;
	m_tax = 0;
	m_medical = 0;
	m_real_salary = 0;;
}

//按顺序初始化参数，不包含实发工资
Officialstaff::Officialstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_all, float p_ann, float p_hou, float p_tax, float p_med)
{
	m_num = p_num;
	m_name = p_name;
	m_sex = p_sex;
	m_age = p_age;
	m_salary = p_salary;
	m_home = p_home;
	m_allowance = p_all;
	m_annuity = p_ann;
	m_fund = p_hou;
	m_tax = p_tax;
	m_medical = p_med;
	m_calculateSalary();
}

//按顺序初始化参数，包含实发工资
Officialstaff::Officialstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_all, float p_ann, float p_hou, float p_tax, float p_med, float p_real)
{
	m_num = p_num;
	m_name = p_name;
	m_sex = p_sex;
	m_age = p_age;
	m_salary = p_salary;
	m_home = p_home;
	m_allowance = p_all;
	m_annuity = p_ann;
	m_fund = p_hou;
	m_tax = p_tax;
	m_medical = p_med;
	m_real_salary = p_real;
}

//拷贝构造函数
Officialstaff::Officialstaff(const Officialstaff& T)
{
	m_num = T.m_num;
	m_name = T.m_name;
	m_sex = T.m_sex;
	m_age = T.m_age;
	m_salary = T.m_salary;
	m_home = T.m_home;
	m_allowance = T.m_allowance;
	m_annuity = T.m_annuity;
	m_fund = T.m_fund;
	m_tax = T.m_tax;
	m_medical = T.m_medical;
	m_real_salary = T.m_real_salary;
}

//移动构造函数
//Officialstaff::Officialstaff(const Officialstaff&& T)
//{
//	m_num = T.m_num;
//	m_name = T.m_name;
//	m_sex = T.m_sex;
//	m_age = T.m_age;
//	m_salary = T.m_salary;
//	m_home = T.m_home;
//	m_allowance = T.m_allowance;
//	m_annuity = T.m_annuity;
//	m_fund = T.m_fund;
//	m_tax = T.m_tax;
//}

//重载 = 运算符
Officialstaff& Officialstaff::operator=(const Officialstaff& T)
{
	m_num = T.m_num;
	m_name = T.m_name;
	m_sex = T.m_sex;
	m_age = T.m_age;
	m_salary = T.m_salary;
	m_home = T.m_home;
	m_allowance = T.m_allowance;
	m_annuity = T.m_annuity;
	m_fund = T.m_fund;
	m_tax = T.m_tax;
	m_medical = T.m_medical;
	m_real_salary = T.m_real_salary;
	return *this;
}

//计算员工实发工资
void Officialstaff::m_calculateSalary()
{
	m_real_salary = m_allowance + m_salary - m_annuity - m_fund - m_tax - m_medical;
}

//获取员工编号
string Officialstaff::m_get_num()
{
	return m_num;
}

//获取员工姓名
string Officialstaff::m_get_name()
{
	return m_name;
}

//析构函数
Officialstaff::~Officialstaff()
{
}
