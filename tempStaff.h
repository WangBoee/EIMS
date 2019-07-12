#pragma once
#include "Staff.h"
class Tempstaff :
	public Staff
{
public:
	float m_bonus;	//奖金
	float m_tax;	//所得税
	float m_real_salary;	//实际工资，计算所得，不要求输入
public:
	//构造函数
	Tempstaff();	//默认构造函数
	Tempstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_bon, float p_tax);	//按顺序初始化参数，不包含实发工资
	Tempstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_bon, float p_tax, float p_real);	//按顺序初始化参数，包含实发工资
	Tempstaff(const Tempstaff& T);	//拷贝构造函数
	//Tempstaff(Tempstaff&& T);	//移动构造函数//undone
	Tempstaff& operator=(const Tempstaff& T);	//重载 = 运算符

	void m_input();	//手动输入数据
	void m_display(int mode=0);	//显示信息，0表示纵向(默认)，1表示横向
	void m_calculateSalary();	//计算员工实发工资

	string m_get_num();		//获取员工编号
	string m_get_name();	//获取员工姓名
	//析构函数
	~Tempstaff();
};