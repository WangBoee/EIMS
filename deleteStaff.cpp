#include <iostream>
#include <string.h>
void deleteStaff()
{
	/*	TO DO:
	0.��ȫע��
	1.�ݴ���
	2.���ݶ��ַ�ʽ���ң���ţ�������
	3.Ա������������� �����߼�
	*/

	short typ;	//1��ʾ��ʽԱ����0��ʾ��ʱԱ��
	int opt = 0;	//���û�ȷ���Ƿ�ɾ����Ĭ�ϲ�ɾ��
	string num;	//��ʱ�洢������
	bool found = false;	//��ʶ�Ƿ��ҵ���ӦԱ����Ĭ��ֵfalse

	cout << "========ɾ��Ա����Ϣ=======" << endl << endl;

	cout << "����Ա������:";
	cin >> typ;

	if (typ == 0)
	{
		cout << "����Ա�����:";
		cin >> num;
		for (vector<Tempstaff>::iterator it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			if (it->m_num == num)
			{
				found = true;
				cout << "�ҵ���ӦԱ��\n";
				it->m_display();
				cout << "\nȷ��ɾ��Ա��" << it->m_name << "?\n\n0.ȡ��\t1.ȷ��\n";
				cin >> opt;
				if (opt)
				{
					tStaffList.erase(it);
					cout << "��ɾ��!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "��ȡ��!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "δ�ҵ���Ա��!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else if (typ == 1)
	{
		cout << "����Ա�����:";
		cin >> num;
		for (vector<Officialstaff>::iterator it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			if (it->m_num == num)
			{
				found = true;
				cout << "�ҵ���ӦԱ��\n";
				//TO DO: ����������ʾԱ����Ϣ
				{

				}
				it->m_display();
				cout << "\nȷ��ɾ��Ա��" << it->m_name << "?\n\n0.ȡ��\t1.ȷ��\n";
				cin >> opt;
				if (opt)
				{
					oStaffList.erase(it);
					cout << "��ɾ��!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "��ȡ��!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "δ�ҵ���Ա��!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else
	{
		cout << "������󣬼����������˵�!" << endl;
		system("ping 127.1 -n 3 >nul");
	}
}
