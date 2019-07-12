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
