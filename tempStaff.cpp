#include "tempStaff.h"
#include <iostream>

namespace YUFEI {
	Tempstaff::Tempstaff()
	{
		m_num = "-1";
		m_name = "";
		m_sex = 1;
		m_age = 0;
		m_salary = 0;
		m_home = "";
		m_bonus = 0;
		m_tax = 0;
		m_real_salary = 0;
		cout << "成功创建临时员工对象" << endl;
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
	Tempstaff::Tempstaff(const Tempstaff& T)
	{
		m_num = T.m_num;
		m_name = T.m_name;
		m_sex = T.m_sex;
		m_age = T.m_age;
		m_salary = T.m_salary;
		m_home = T.m_home;
		m_bonus = T.m_bonus;
		m_tax = T.m_tax;
		m_real_salary = T.m_real_salary;
	}

	//重载 = 运算符
	Tempstaff& Tempstaff::operator=(const Tempstaff& T)
	{
		m_num = T.m_num;
		m_name = T.m_name;
		m_sex = T.m_sex;
		m_age = T.m_age;
		m_salary = T.m_salary;
		m_home = T.m_home;
		m_bonus = T.m_bonus;
		m_tax = T.m_tax;
		m_real_salary = T.m_real_salary;
		return *this;
	}

	//重载Tempstaff类的<<输出运算符
	ostream& operator<<(ostream& os, Tempstaff& T)
	{
		os << "编号：" << T.m_get_num() << endl
			<< "姓名：" << T.m_get_name() << endl
			<< "性别：" << (T.m_get_sex() ? "男" : "女") << endl
			<< "年龄：" << T.m_get_age() << endl
			<< "工资：" << T.m_get_salary() << endl
			<< "家庭住址：" << T.m_get_home() << endl
			<< "奖金：" << T.m_get_bonus() << endl
			<< "所得税：" << T.m_get_tax() << endl
			<< "实发工资：" << T.m_get_real_salary() << endl << endl;
		return os;
	}

	//手动输入信息
	void Tempstaff::m_input()
	{
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
		m_calculateSalary();	//计算实发工资
	}

	//显示信息
	void Tempstaff::m_display(int p_mode)
	{
		if (p_mode == 1)
		{	//横向输出员工信息
			cout << "编号：" << m_num << " " << "姓名：" << m_name << " " << "性别：" << (m_sex ? "男" : "女") << " "
				<< "年龄：" << m_age << " " << "工资：" << m_salary << " " << "家庭住址：" << m_home << " "
				<< "奖金：" << m_bonus << " " << "所得税：" << m_tax << " " << "实发工资：" << m_real_salary << endl << endl;
		}
		else if (p_mode == 0)
		{	//纵向输出员工信息
			cout << "编号：" << m_num << endl
				<< "姓名：" << m_name << endl
				<< "性别：" << (m_sex ? "男" : "女") << endl
				<< "年龄：" << m_age << endl
				<< "工资：" << m_salary << endl
				<< "家庭住址：" << m_home << endl
				<< "奖金：" << m_bonus << endl
				<< "所得税：" << m_tax << endl
				<< "实发工资：" << m_real_salary << endl << endl;
		}
		else
			cout << "输入错误！" << endl;
	}

	//计算员工实发工资
	void Tempstaff::m_calculateSalary()
	{
		m_real_salary = m_salary + m_bonus - m_tax;
	}

	//析构函数
	Tempstaff::~Tempstaff() {}
}