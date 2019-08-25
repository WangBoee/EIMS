#include <vector>
#include <fstream>
#include "officialStaff.h"
#include "tempStaff.h"

using XIANGQIAOSHUN::Officialstaff;
using YUFEI::Tempstaff;

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;

namespace YUFEI {
	//从文件读取临时员工信息
	void readTSL()
	{//文件tempStaffList.dat存储临时员工数据
		ifstream tfp("tempStaffList.dat");
		tfp.seekg(ifstream::beg);	//定位文件位置指针于文件头部
		while (true)
		{//临时变量，用于存储临时数据
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
			tfp >> num >> name >> sex >> age >> salary >> home >> bonus >> tax >> real;
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
	//从文件读取正式员工信息
	void readOSL()
	{//文件officialStaffList.dat存储所有正式员工信息
		ifstream ofp("officialStaffList.dat");
		ofp.seekg(ifstream::beg);	//定位文件位置指针于文件头部
		while (true)
		{//临时变量
			string Num;	//职工编号
			string Name;	//职工姓名
			bool Sex;	//员工性别
			int Age;	//职工年龄
			float Salary;	//员工基本职务工资 
			string Home;	//员工家庭住址
			float Allowance;	//津贴
			float Annuity;	//养老金
			float HousingFund;	//住房公积金
			float Tax;	//所得税
			float MedicalInsurance;	//医疗保险
			float realS;	//实发工资

			//从文件读取数据存入临时变量
			ofp >> Num >> Name >> Sex >> Age >> Salary >> Home >> Allowance
				>> Annuity >> HousingFund >> Tax >> MedicalInsurance >> realS;
			//读到文件尾跳出循环
			if (ofp.eof())
				break;
			//用ofp读取的数据初始化一个临时对象
			Officialstaff tmp(Num, Name, Sex, Age, Salary, Home, Allowance, Annuity, HousingFund, Tax, MedicalInsurance, realS);
			oStaffList.push_back(tmp);	//存入正式员工列表
		}
		ofp.close();	//关闭打开的文件
	}
};
