#pragma once
#include <string>

using namespace std;

namespace WANGBOYI {
	//基类
	class Staff
	{
	protected:
		string m_num;	//职工编号
		string m_name;		//职工姓名
		bool m_sex;	//员工性别,True表示男，False表示女
		int m_age;	//职工年龄
		float m_salary;	//员工基本职务工资 
		string m_home;	//员工家庭住址
	public:
		Staff();
		virtual void m_input() = 0;	//虚函数，输入数据
		virtual void m_display(int mode) = 0;	//虚函数，显示数据
		virtual void m_calculateSalary() = 0;	//虚函数，计算实际工资
	};
};