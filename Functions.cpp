#include "officialStaff.h"
#include "Staff.h"
#include "tempStaff.h"
#include <iostream>
#include <Windows.h>
#include "Functions.h"
using namespace std;

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;	//正式员工列表

//主菜单界面
void meanu()
{
	/*	TO DO:void menu()
	0.添加修改员工信息选项（功能）
	*/
	cout << endl
		<< "1.查看员工信息" << endl
		<< "2.录入员工信息" << endl
		<< "3.删除员工信息" << endl
		<< "0.退出" << endl
		<< "输入选项：";
}

//查看员工信息
void checkInfo()
{
	/*	TO DO:
	0.以不同方式显示员工信息（横向、纵向）
	1.列出所有员工信息
	2.完善查找逻辑
	*/
	cout << "========查询员工信息=======" << endl << endl;
	
	//TEST list all staffs info
	//for (auto x : oStaffList)
	//{
	//	cout << "OfficialList" << endl;
	//	x.m_display();
	//	cout << endl;
	//}

	//for (auto x : tStaffList)
	//{
	//	cout << "TempList" << endl;
	//	x.m_display();
	//	cout << endl;
	//}

	string num;	//临时存储输入编号
	bool found = false;	//标识是否找到对应员工，默认值false
	cout << "输入员工编号:";
	cin >> num;

	//先在正式员工列表中查找
	for (auto x : oStaffList)
	{
		if (x.m_num == num)
		{
			x.m_display(0);	//找到则输出员工信息
			found = true;	//同时标识已找到对应员工
			break;	//找到则终止查询
		}
	}
	//若已找到则不会在临时员工列表中查找
	if (!found)
	{
		//在临时员工列表中查找
		for (auto x : tStaffList)
		{
			if (x.m_num == num)
			{
				x.m_display();	//找到则输出员工信息
				found = true;	//同时标识已找到对应员工
				break;	//找到则终止查询
			}
		}
	}
	//若在两个列表中都未找到对应员工，输出提示信息并返回主菜单
	if (!found)
		cout << "未找到相关信息!" << endl;
	else
	{
		
	}
	system("pause");
}

void editInfo()
{
	//TO DO
}

//添加新员工
void newStaff()
{
	/*	TO DO:
	0.查询到列出员工信息  √
	1.查询员工是否已存在列表
	2.输入容错处理
	*/

	//提示信息
	cout << "========录入新的员工=======" << endl << endl
		<< "0.临时员工\n1.正式员工\n";

	while (true)
	{
		int typ;	//临时存储员工类型，0表示临时员工，1表示正式员工
		cout << "输入员工类型:";
		cin >> typ;
		if (typ == 0)
		{
			Tempstaff ts;	//临时员工的临时对象
			ts.m_input();	//输入临时员工信息
			ts.m_display(0);//debug
			system("pause");
			tStaffList.push_back(ts);	//将此临时对象插入列表
			break;
		}
		else if (typ == 1)
		{
			Officialstaff ost;	//正式员工的临时对象
			ost.m_input();	//输入正式员工信息
			ost.m_display();//debug
			system("pause");
			oStaffList.push_back(ost);	//将此临时对象插入列表
			break;
		}
		else
		{	//错误输入提示，并要求重新输入直到正确输入
			cout << "输入错误，请重新输入!\n";
		}
	}
}

//删除员工 
void deleteStaff()
{
	/*	TO DO:
	0.补全注释
	1.容错处理
	2.根据多种方式查找（编号，姓名）
	3.员工类型输入错误 处理逻辑
	*/

	short typ;	//1表示正式员工，0表示临时员工
	int opt = 0;	//让用户确认是否删除，默认不删除
	string num;	//临时存储输入编号
	bool found = false;	//标识是否找到对应员工，默认值false

	cout << "========删除员工信息=======" << endl << endl;

	cout << "输入员工类型:";
	cin >> typ;

	if (typ == 0)
	{
		cout << "输入员工编号:";
		cin >> num;
		for (vector<Tempstaff>::iterator it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			if (it->m_num == num)
			{
				found = true;
				cout << "找到对应员工\n";
				it->m_display();
				cout << "\n确认删除员工" << it->m_name << "?\n\n0.取消\t1.确认\n";
				cin >> opt;
				if (opt)
				{
					tStaffList.erase(it);
					cout << "已删除!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "已取消!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "未找到该员工!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else if (typ == 1)
	{
		cout << "输入员工编号:";
		cin >> num;
		for (vector<Officialstaff>::iterator it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			if (it->m_num == num)
			{
				found = true;
				cout << "找到对应员工\n";
				//TO DO: 横向、纵向显示员工信息
				{

				}
				it->m_display();
				cout << "\n确认删除员工" << it->m_name << "?\n\n0.取消\t1.确认\n";
				cin >> opt;
				if (opt)
				{
					oStaffList.erase(it);
					cout << "已删除!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "已取消!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "未找到该员工!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else
	{
		cout << "输入错误，即将返回主菜单!" << endl;
		system("ping 127.1 -n 3 >nul");
	}
}

//从文件读取临时员工信息
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

//将所有临时员工信息存入文件
void writeTSL()
{
	fstream tfp;
	//以追加写入方式打开文件
	tfp.open("tempStaffList.dat", ios::out | ios::trunc);
	//写入临时员工数据，每个员工数据占一行
	for (int i = 0; i < tStaffList.size(); i++)
	{
		tfp << tStaffList[i].m_num << " "
			<< tStaffList[i].m_name << " "
			<< tStaffList[i].m_sex << " "
			<< tStaffList[i].m_age << " "
			<< tStaffList[i].m_salary << " "
			<< tStaffList[i].m_home << " "
			<< tStaffList[i].m_bonus << " "
			<< tStaffList[i].m_tax << " "
			<< tStaffList[i].m_real_salary << endl;
	}
	tfp.close();	//关闭文件
}

//从文件读取正式员工信息
void readOSL()
{
	//文件officialStaffList.dat存储所有正式员工信息
	ifstream ofp("officialStaffList.dat");
	//定位文件位置指针于文件头部
	ofp.seekg(ifstream::beg);
	//fp.open("tempStaffList.dat", ios::in);	//文件tempStaffList.dat存储正式员工信息
	//循环读取数据
	while (true)
	{
		//临时变量
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
		ofp >> Num
			>> Name
			>> Sex
			>> Age
			>> Salary
			>> Home
			>> Allowance
			>> Annuity
			>> HousingFund
			>> Tax
			>> MedicalInsurance
			>> realS;

		//读到文件尾跳出循环
		if (ofp.eof())
			break;
		//用ofp读取的数据初始化一个临时对象
		Officialstaff tmp(Num, Name, Sex, Age, Salary, Home, Allowance, Annuity
			, HousingFund, Tax, MedicalInsurance, realS);
		//存入正式员工列表
		oStaffList.push_back(tmp);
	}
	ofp.close();	//关闭打开的文件
}

//将所有正式员工信息存入文件
void writeOSL()
{
	fstream ofp;
	//以追加写入方式打开文件
	ofp.open("officialStaffList.dat", ios::out | ios::trunc);
	//写入临时员工数据，每个员工数据占一行
	for (int i = 0; i < oStaffList.size(); i++)
	{
		ofp << oStaffList[i].m_num << " "
			<< oStaffList[i].m_name << " "
			<< oStaffList[i].m_sex << " "
			<< oStaffList[i].m_age << " "
			<< oStaffList[i].m_salary << " "
			<< oStaffList[i].m_home << " "
			<< oStaffList[i].m_allowance << " "
			<< oStaffList[i].m_annuity << " "
			<< oStaffList[i].m_fund << " "
			<< oStaffList[i].m_tax << " "
			<< oStaffList[i].m_medical << " "
			<< oStaffList[i].m_real_salary << endl;
	}
	ofp.close();	//关闭文件
}

void print(const string& str)
{
	for (auto i : str)
	{
		cout << i;
		Sleep(35);
	}
}