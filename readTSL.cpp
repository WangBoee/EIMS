#include <string.h>
void readTSL()
{
	//文件tempStaffList.dat存储临时员工数据
	ifstream tfp("tempStaffList.dat");
	//定位文件位置指针于文件头部
	tfp.seekg(ifstream::beg);
	//fp.open("tempStaffList.dat", ios::in);	//文件tempStaffList.dat存储临时员工信息
	//循环读取
	while (true)
	{
		//临时变量，用于存储临时数据
		string num;	//职工编号
		string name;	//职工姓名
		bool sex;	//员工性别
		int age;	//职工年龄
		float salary;	//员工基本职务工资 
		string home;	//员工家庭住址
		float bonus;	//奖金
		float tax;	//所得税
		float real;	//实发工资

		//从文件读取数据存入临时变量
		tfp >> num
			>> name
			>> sex
			>> age
			>> salary
			>> home
			>> bonus
			>> tax
			>> real;

		//当读到文件尾时跳出循环
		if (tfp.eof())
			break;
		//用tfp读取的数据初始化一个临时对象
		Tempstaff tmp(num, name, sex, age, salary, home, bonus, tax, real);
		//存入临时员工列表
		tStaffList.push_back(tmp);
	}
	tfp.close();	//关闭打开的文件
}
