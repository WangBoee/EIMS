void writeOSL()
{
	fstream ofp;
	//��׷��д�뷽ʽ���ļ�
	ofp.open("officialStaffList.dat", ios::out | ios::trunc);
	//д����ʱԱ�����ݣ�ÿ��Ա������ռһ��
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
	ofp.close();	//�ر��ļ�
}
