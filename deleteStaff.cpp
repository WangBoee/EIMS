#include "Functions.h"

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;

void deleteStaff()
{
	/*	TO DO:
	2.根据多种方式查找（编号，姓名
	*/

	int type;	//1表示正式员工，0表示临时员工
	int opt = 0;	//让用户确认是否删除，默认不删除
	string num;	//临时存储输入编号
	bool found = false;	//标识是否找到对应员工，默认值false

	cout << "========删除员工信息=======" << endl << endl;

	cout << "输入员工类型:";
	cin >> type;
	inputCheck(type);
	if (type == 0)
	{
		cout << "输入员工编号:";
		cin >> num;
		for (vector<Tempstaff>::iterator it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			if (it->m_get_num() == num)
			{
				found = true;
				cout << "找到对应员工\n";
				it->m_display();
				cout << "\n确认删除员工" << it->m_get_name() << "?\n\n0.取消\t1.确认\n";
				cin >> opt;
				if (opt)
				{
					tStaffList.erase(it);	//删除找到的对应元素
					cout << "已删除!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "已取消!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "未找到该员工!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
	else if (type == 1)
	{
		cout << "输入员工编号:";
		cin >> num;
		for (vector<Officialstaff>::iterator it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			if (it->m_get_num() == num)
			{
				found = true;
				cout << "找到对应员工\n";
				//TO DO: 横向、纵向显示员工信息
				{

				}
				it->m_display();
				cout << "\n确认删除员工" << it->m_get_name() << "?\n\n0.取消\t1.确认\n";
				cin >> opt;
				if (opt)
				{
					oStaffList.erase(it);	//删除找到的对应元素
					cout << "已删除!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				else
				{
					cout << "已取消!" << endl;
					system("ping 127.1 -n 3 >nul");
				}
				break;
			}
		}
		if (!found)
		{
			cout << "未找到该员工!" << endl;
			system("ping 127.1 -n 3 >nul");
		}
	}
}
