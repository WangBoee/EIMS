#include "menu.h"
#include "Functions.h"
#include "compareStaff.h"

namespace WANGBOYI {
	//主菜单
	void mainMenu()
	{
		cout << endl
			<< "\t1.查看员工信息" << endl
			<< "\t2.录入员工信息" << endl
			<< "\t3.删除员工信息" << endl
			<< "\t4.修改员工信息" << endl
			<< "\t5.统计所有信息" << endl
			<< "\t   0.退出" << endl
			<< "输入选项：";
	}

	//查找员工菜单
	void searchMenu()
	{
		string num;	//临时存储输入编号
		int type(-1);
		cout << "========查询员工信息=======" << endl << endl;
		cout << "0.临时员工\n1.正式员工\n\n输入员工类型:";
		cin >> type;
		inputCheck(type);	//输入检查
		cout << "输入编号：";
		cin >> num;
		switch (type)
		{
		case 0:
			if (!findTempStaff(num))
				cout << "未找到!\n";	//正式员工查找
			break;
		case 1:
			if (!findOfficialStaff(num))
				cout << "未找到!\n";	//临时员工查找
			break;
		}
		system("pause");
	}

	//添加员工菜单
	void newStaffMenu()
	{
		int type;	//临时存储员工类型，0表示临时员工，1表示正式员工
		string num;
		system("cls");
		cout << "========录入新的员工=======" << endl << endl
			<< "0.临时员工\n1.正式员工\n";
		cout << "输入员工类型:";
		cin >> type;
		inputCheck(type);
		cout << "输入编号：";
		cin >> num;
		if (type == 0)
		{
			if (findTempStaff(num))	//检查是否已存在对应员工
				cout << "员工已存在!\n";
			else
				newTempStaff(num);
		}
		else
		{
			if (findOfficialStaff(num))	//检查是否已存在对应员工
				cout << "员工已存在!\n";
			else
				newOfficialStaff(num);
		}
		system("pause");	//暂停，显示信息等待用户按键确认
	}

	//删除员工菜单
	void deleteStaffMenu()
	{
		int type;	//1表示正式员工，0表示临时员工
		int i = -1;	//i标记查找到的员工位置
		string num;	//临时存储输入编号
		cout << "========删除员工信息=======" << endl << endl
			<< "0.临时员工\t1.正式员工" << endl;
		cout << "输入员工类型:";
		cin >> type;
		inputCheck(type);	//输入检查
		if (type == 0)
		{	//查找删除临时员工
			cout << "输入员工编号:";
			cin >> num;
			if (findTempStaff(num, &i))	//若找到对应员工，再次确认是否删除
				conformDelTemp(i);
			else
			{	//未找到相应员工
				cout << "未找到该员工!" << endl;
				system("ping 127.1 -n 3 >nul");
			}
		}
		else if (type == 1)
		{	//查找删除正式员工
			cout << "输入员工编号:";
			cin >> num;
			if (findOfficialStaff(num, &i))	//找到对应员工，再次确认是否删除
				conformDelOfficial(i);
			else
			{	//未找到相应员工
				cout << "未找到该员工!" << endl;
				system("ping 127.1 -n 3 >nul");
			}
		}
	}

	//编辑员工菜单
	void editMenu() {
		//TO DO
		;
	}

	//所有信息菜单
	void checkAllMenu()
	{
		int type(-1);
		system("cls");
		cout << "0.纵向显示员工信息\n1.横向显示员工信息\n默认纵向(0)\n";
		cin >> type;
		inputCheck(type);
		//根据输入确定显示方式
		cout << endl << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{	//显示正式员工信息
			it->m_display(type);
		}
		cout << endl << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{	//显示临时员工信息
			it->m_display(type);
		}
		system("pause");
	}
}