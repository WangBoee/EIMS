#include <string.h>
void readOSL()
{
	//�ļ�officialStaffList.dat�洢������ʽԱ����Ϣ
	ifstream ofp("officialStaffList.dat");
	//��λ�ļ�λ��ָ�����ļ�ͷ��
	ofp.seekg(ifstream::beg);
	//fp.open("tempStaffList.dat", ios::in);	//�ļ�tempStaffList.dat�洢��ʽԱ����Ϣ
	//ѭ����ȡ����
	while (true)
	{
		//��ʱ����
		string Num;	//ְ�����
		string Name;	//ְ������
		bool Sex;	//Ա���Ա�
		int Age;	//ְ������
		float Salary;	//Ա������ְ���� 
		string Home;	//Ա����ͥסַ
		float Allowance;	//����
		float Annuity;	//���Ͻ�
		float HousingFund;	//ס��������
		float Tax;	//����˰
		float MedicalInsurance;	//ҽ�Ʊ���
		float realS;	//ʵ������

		//���ļ���ȡ���ݴ�����ʱ����
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

		//�����ļ�β����ѭ��
		if (ofp.eof())
			break;
		//��ofp��ȡ�����ݳ�ʼ��һ����ʱ����
		Officialstaff tmp(Num, Name, Sex, Age, Salary, Home, Allowance, Annuity
			, HousingFund, Tax, MedicalInsurance, realS);
		//������ʽԱ���б�
		oStaffList.push_back(tmp);
	}
	ofp.close();	//�رմ򿪵��ļ�
}
