#include <string.h>
void readTSL()
{
	//�ļ�tempStaffList.dat�洢��ʱԱ������
	ifstream tfp("tempStaffList.dat");
	//��λ�ļ�λ��ָ�����ļ�ͷ��
	tfp.seekg(ifstream::beg);
	//fp.open("tempStaffList.dat", ios::in);	//�ļ�tempStaffList.dat�洢��ʱԱ����Ϣ
	//ѭ����ȡ
	while (true)
	{
		//��ʱ���������ڴ洢��ʱ����
		string num;	//ְ�����
		string name;	//ְ������
		bool sex;	//Ա���Ա�
		int age;	//ְ������
		float salary;	//Ա������ְ���� 
		string home;	//Ա����ͥסַ
		float bonus;	//����
		float tax;	//����˰
		float real;	//ʵ������

		//���ļ���ȡ���ݴ�����ʱ����
		tfp >> num
			>> name
			>> sex
			>> age
			>> salary
			>> home
			>> bonus
			>> tax
			>> real;

		//�������ļ�βʱ����ѭ��
		if (tfp.eof())
			break;
		//��tfp��ȡ�����ݳ�ʼ��һ����ʱ����
		Tempstaff tmp(num, name, sex, age, salary, home, bonus, tax, real);
		//������ʱԱ���б�
		tStaffList.push_back(tmp);
	}
	tfp.close();	//�رմ򿪵��ļ�
}
