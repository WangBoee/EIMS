#include <vector>
#include <fstream>
#include "officialStaff.h"
#include "tempStaff.h"
#include "Functions.h"

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;

//命名空间俞非
namespace YUFEI
{
	//将所有临时员工信息存入文件
	void writeTSL()
	{
		fstream tfp;
		tfp.open("tempStaffList.dat", ios::out | ios::trunc);	//以覆盖写入方式打开文件
		for (int i = 0; i < tStaffList.size(); i++)
		{	//写入临时员工数据，每个员工数据占一行
			tfp << tStaffList[i].m_get_num() << " " << tStaffList[i].m_get_name() << " "
				<< tStaffList[i].m_get_sex() << " " << tStaffList[i].m_get_age() << " "
				<< tStaffList[i].m_get_salary() << " " << tStaffList[i].m_get_home() << " "
				<< tStaffList[i].m_get_bonus() << " " << tStaffList[i].m_get_tax() << " "
				<< tStaffList[i].m_get_real_salary() << endl;
		}
		tfp.close();	//关闭文件
	}

	//将所有正式员工信息存入文件
	void writeOSL()
	{
		fstream ofp;
		ofp.open("officialStaffList.dat", ios::out | ios::trunc);	//以覆盖写入方式打开文件
		for (int i = 0; i < oStaffList.size(); i++)
		{	//写入临时员工数据，每个员工数据占一行
			ofp << oStaffList[i].m_get_num() << " " << oStaffList[i].m_get_name() << " "
				<< oStaffList[i].m_get_sex() << " " << oStaffList[i].m_get_age() << " "
				<< oStaffList[i].m_get_salary() << " " << oStaffList[i].m_get_home() << " "
				<< oStaffList[i].m_get_allowance() << " " << oStaffList[i].m_get_annuity() << " "
				<< oStaffList[i].m_get_fund() << " " << oStaffList[i].m_get_tax() << " "
				<< oStaffList[i].m_get_medical() << " " << oStaffList[i].m_get_real_salary() << endl;
		}
		ofp.close();	//关闭文件
	}
};