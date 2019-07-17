#pragma once
#include "Staff.h"

class Officialstaff :
	public Staff
{
public:
	float m_allowance;	//津贴
	float m_annuity;	//养老金
	float m_fund;	//住房公积金
	float m_tax;	//所得税
	float m_medical;	//医疗保险
	float m_real_salary;	//实发工资，计算所得，不要求输入
public:
	Officialstaff();	//默认构造函数
	Officialstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_all, float p_ann, float p_hou, float p_tax, float p_med);	//按顺序初始化参数，不包含实发工资
	Officialstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_all, float p_ann, float p_hou, float p_tax, float p_med, float p_real);	//按顺序初始化参数，包含实发工资
	Officialstaff(const Officialstaff& T);	//拷贝构造函数
	//Officialstaff(const Officialstaff&& T);	//移动构造函数
	Officialstaff& operator=(const Officialstaff& T);	//重载 = 运算符

	void m_input();	//手动输入数据
	void m_display(int mode = 0);	//显示信息，0表示纵向(默认)，1表示横向
	void m_calculateSalary();	//计算员工实发工资

	string m_get_num();		//获取员工编号
	string m_get_name();	//获取员工姓名
	float m_get_salary();		//获取员工实发工资

	//析构函数
	~Officialstaff();
};