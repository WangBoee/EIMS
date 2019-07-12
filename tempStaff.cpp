#include "tempStaff.h"
#include <iostream>

//手动输入信息
void Tempstaff::m_input()
{
	cout << "请输入临时员工的编号" << endl;
	cin >> m_num;
	cout << "请输入临时员工的姓名" << endl;
	cin.get();
	getline(cin, m_name);
	cout << "请输入临时员工的性别(0.女  1.男)" << endl;
	int sex;
	cin >> sex;
	m_sex = sex ? true : false;
	cout << "请输入临时员工的年龄" << endl;
	cin >> m_age;
	cout << "请输入临时员工的基本职务工资" << endl;
	cin >> m_salary;
	cout << "请输入临时员工的家庭住址" << endl;
	cin.get();
	getline(cin, m_home);

	cout << "请输入临时员工的奖金" << endl;
	cin >> m_bonus;
	cout << "请输入临时员工的所得税" << endl;
	cin >> m_tax;
	m_calculateSalary();
}

//显示信息
void Tempstaff::m_display(int mode)
{
	//19.6.26 add
	if (mode == 1)
	{//19.7.10 add
		cout<< "编号：" << m_num << " "<< "姓名：" << m_name << " "<< "性别：" << m_sex << " "
			<< "年龄：" << m_age << " "	<< "工资：" << m_salary << " "<< "家庭住址：" << m_home << " "
			<< "奖金：" << m_bonus << " "<< "所得税：" << m_tax << " "<< "实发工资：" << m_real_salary << endl;
	}
	else if (mode == 0)
	{
		cout << "编号：" << m_num << endl
			<< "姓名：" << m_name << endl
			<< "性别：" << m_sex << endl
			<< "年龄：" << m_age << endl
			<< "工资：" << m_salary << endl
			<< "家庭住址：" << m_home << endl
			<< "奖金：" << m_bonus << endl
			<< "所得税：" << m_tax << endl
			<< "实发工资：" << m_real_salary << endl;
	}
	else
	{
		cout << "输入错误！"<<endl;
	}
}

//计算员工实发工资
void Tempstaff::m_calculateSalary()
{
	m_real_salary = m_salary + m_bonus - m_tax;
}

//void Tempstaff::operator=(const Tempstaff& tmp)
//{
//	m_num = tmp.m_num;
//	m_name = tmp.m_name;
//	m_sex = tmp.m_sex;
//	m_age = tmp.m_age;
//	m_salary = tmp.m_salary;
//	m_home = tmp.m_home;
//	m_bonus = tmp.m_bonus;
//	m_tax = tmp.m_tax;
//	m_real_salary = tmp.m_real_salary;
//}

Tempstaff::Tempstaff()
{
	;
}

//按顺序初始化参数，不包含实发工资
Tempstaff::Tempstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_bon, float p_tax)
{
	m_num = p_num;
	m_name = p_name;
	m_sex = p_sex;
	m_age = p_age;
	m_salary = p_salary;
	m_home = p_home;
	m_bonus = p_bon;
	m_tax = p_tax;
	m_calculateSalary();
}

////按顺序初始化参数，包含实发工资
Tempstaff::Tempstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_bon, float p_tax, float p_real)
{
	m_num = p_num;
	m_name = p_name;
	m_sex = p_sex;
	m_age = p_age;
	m_salary = p_salary;
	m_home = p_home;
	m_bonus = p_bon;
	m_tax = p_tax;
	m_real_salary = p_real;
}

//拷贝构造函数
Tempstaff::Tempstaff(Tempstaff& T)
{
	m_num = T.m_num;
	m_name = T.m_name;
	m_sex = T.m_sex;
	m_salary = T.m_salary;
	m_home = T.m_home;
	m_bonus = T.m_bonus;
	m_tax = T.m_tax;
	m_real_salary = T.m_real_salary;
}

//重载 = 运算符
Tempstaff& Tempstaff::operator=(Tempstaff& T)
{
	m_num = T.m_num;
	m_name = T.m_name;
	m_sex = T.m_sex;
	m_salary = T.m_salary;
	m_home = T.m_home;
	m_bonus = T.m_bonus;
	m_tax = T.m_tax;
	m_real_salary = T.m_real_salary;
}

//移动构造函数
Tempstaff::Tempstaff(Tempstaff&& T)
{
	m_num = T.m_num;
	m_name = T.m_name;
	m_sex = T.m_sex;
	m_salary = T.m_salary;
	m_home = T.m_home;
	m_bonus = T.m_bonus;
	m_tax = T.m_tax;
	m_real_salary = T.m_real_salary;
}

//析构函数
Tempstaff::~Tempstaff()
{
	;
}