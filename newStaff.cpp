#include <iostream>
void newStaff()
{
	/*	TO DO:
	0.��ѯ���г�Ա����Ϣ  ��
	1.��ѯԱ���Ƿ��Ѵ����б�
	2.�����ݴ���
	*/

	//��ʾ��Ϣ
	cout << "========¼���µ�Ա��=======" << endl << endl
		<< "0.��ʱԱ��\n1.��ʽԱ��\n";

	while (true)
	{
		int typ;	//��ʱ�洢Ա�����ͣ�0��ʾ��ʱԱ����1��ʾ��ʽԱ��
		cout << "����Ա������:";
		cin >> typ;
		if (typ == 0)
		{
			Tempstaff ts;	//��ʱԱ������ʱ����
			ts.m_input();	//������ʱԱ����Ϣ
			ts.m_display(0);//debug
			system("pause");
			tStaffList.push_back(ts);	//������ʱ��������б�
			break;
		}
		else if (typ == 1)
		{
			Officialstaff ost;	//��ʽԱ������ʱ����
			ost.m_input();	//������ʽԱ����Ϣ
			ost.m_display();//debug
			system("pause");
			oStaffList.push_back(ost);	//������ʱ��������б�
			break;
		}
		else
		{	//����������ʾ����Ҫ����������ֱ����ȷ����
			cout << "�����������������!\n";
		}
	}
}
