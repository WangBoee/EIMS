#include <string.h>
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
