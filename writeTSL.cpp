void writeTSL()
{
	fstream tfp;
	//��׷��д�뷽ʽ���ļ�
	tfp.open("tempStaffList.dat", ios::out | ios::trunc);
	//д����ʱԱ�����ݣ�ÿ��Ա������ռһ��
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
	tfp.close();	//�ر��ļ�
}
