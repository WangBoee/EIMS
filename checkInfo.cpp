#include <iostream>
#include <string.h>
void checkInfo()
{
	/*	TO DO:
	0.�Բ�ͬ��ʽ��ʾԱ����Ϣ����������
	1.�г�����Ա����Ϣ
	2.���Ʋ����߼�
	*/
	cout << "========��ѯԱ����Ϣ=======" << endl << endl;

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

	string num;	//��ʱ�洢������
	bool found = false;	//��ʶ�Ƿ��ҵ���ӦԱ����Ĭ��ֵfalse
	cout << "����Ա�����:";
	cin >> num;

	//������ʽԱ���б��в���
	for (auto x : oStaffList)
	{
		if (x.m_num == num)
		{
			x.m_display(0);	//�ҵ������Ա����Ϣ
			found = true;	//ͬʱ��ʶ���ҵ���ӦԱ��
			break;	//�ҵ�����ֹ��ѯ
		}
	}
	//�����ҵ��򲻻�����ʱԱ���б��в���
	if (!found)
	{
		//����ʱԱ���б��в���
		for (auto x : tStaffList)
		{
			if (x.m_num == num)
			{
				x.m_display();	//�ҵ������Ա����Ϣ
				found = true;	//ͬʱ��ʶ���ҵ���ӦԱ��
				break;	//�ҵ�����ֹ��ѯ
			}
		}
	}
	//���������б��ж�δ�ҵ���ӦԱ���������ʾ��Ϣ���������˵�
	if (!found)
		cout << "δ�ҵ������Ϣ!" << endl;
	else
	{

	}
	system("pause");
}
