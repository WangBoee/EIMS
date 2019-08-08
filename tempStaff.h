#pragma once
#include "Staff.h"

using WANGBOYI::Staff;

namespace YUFEI {
	class Tempstaff :
		public Staff
	{
		float m_bonus;	//奖金
		float m_tax;	//所得税
		float m_real_salary;	//实际工资，计算所得，不要求输入
	public:
		Tempstaff();	//默认构造函数
		Tempstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_bon, float p_tax);	//按顺序初始化参数，不包含实发工资
		Tempstaff(string p_num, string p_name, bool p_sex, int p_age, float p_salary, string p_home, float p_bon, float p_tax, float p_real);	//按顺序初始化参数，包含实发工资
		Tempstaff(const Tempstaff& T);	//拷贝构造函数
		Tempstaff& operator=(const Tempstaff& T);	//重载 = 运算符
		friend ostream& operator<<(ostream& os, Tempstaff& T);	//重载<<输出运算符

		void m_input();	//手动输入数据
		void m_display(int mode = 0);	//显示信息，0表示纵向(默认)，1表示横向
		void m_calculateSalary();	//计算员工实发工资

		//获取各成员变量值
		string m_get_num() { return m_num; }		//获取员工编号
		string m_get_name() { return m_name; }	//获取员工姓名
		bool m_get_sex() { return m_sex; }	//获取员工性别
		int m_get_age() { return m_age; }	//获取员工年龄
		float m_get_salary() { return m_real_salary; }		//获取员工基本工资
		string m_get_home() { return m_home; }		//获取家庭住址
		float m_get_bonus() { return m_bonus; }	//获取奖金
		float m_get_tax() { return m_tax; }	//获取所得税
		float m_get_real_salary() { return m_real_salary; }		//获取实发工资

		//设置各成员变量值
		void m_set_num(string& p_num) { m_num = p_num; }	//修改编号
		void m_set_name(string& p_name) { m_name = p_name; }    //修改姓名
		void m_set_sex(int& p_sex) { m_sex = p_sex ? true : false; }    //修改性別
		void m_set_age(int& p_age) { m_age = p_age; }    //修改年龄
		void m_set_salary(float& p_salary) { m_real_salary = p_salary; }    //修改基本工资
		void m_set_home(string& p_home) { m_home = p_home; }    //修改家庭住址
		void m_set_bonus(float& p_bouns) { m_bonus = p_bouns; }	//修改奖金
		void m_set_tax(float& p_tax) { m_tax = p_tax; }    //修改所得税
		void m_set_real_salary(float& p_real_salary) { m_real_salary = p_real_salary; }    //修改实发工资

		//析构函数
		~Tempstaff();
	};
};