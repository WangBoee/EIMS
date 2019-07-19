#include "menu.h"
#include "Functions.h"

//主菜单
void mainMenu()
{
	cout << endl
		<< "\t1.查看员工信息" << endl
		<< "\t2.录入员工信息" << endl
		<< "\t3.删除员工信息" << endl
		<< "\t4.修改员工信息" << endl
		<< "\t5.统计所有信息" << endl
		<< "\t      0.退出" << endl
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
		if (!findOfficialStaff(num, NULL))
			cout << "未找到!\n";	//正式员工查找
		break;
	case 1:
		if (!findTempStaff(num, NULL))
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
	while (true)
	{
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
			if (findTempStaff(num, NULL))
			{	//检查是否已存在对应员工
				cout << "员工已存在!\n";
				continue;
			}
			Tempstaff* ts = new Tempstaff;	//临时员工的临时对象
			ts->m_set_num(num);	//设置员工编号
			ts->m_input();	//输入临时员工信息
			ts->m_display(0);
			system("pause");
			tStaffList.push_back(*ts);	//将此临时对象插入列表
			delete ts;
			break;
		}
		else if (type == 1)
		{
			if (findOfficialStaff(num, NULL))
			{
				cout << "员工已存在!\n";
				continue;
			}
			Officialstaff* ost = new Officialstaff;	//正式员工的临时对象
			ost->m_set_num(num);	//设置员工编号
			ost->m_input();	//输入正式员工信息
			ost->m_display(0);
			system("pause");
			oStaffList.push_back(*ost);	//将此临时对象插入列表
			delete ost;
			break;
		}
	}
	system("pause");	//暂停，显示信息等待用户按键确认
}

//删除员工菜单
void deleteStaffMenu()
{
	int type;	//1表示正式员工，0表示临时员工
	int opt = 0;	//让用户确认是否删除，默认不删除
	int i = 0;	//i标记查找到的员工位置
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
		if (findTempStaff(num, &i))	//函数查找临时员工
		{	//若找到对应员工，再次确认是否删除
			cout << "\n确认删除员工" << (tStaffList.begin() + i)->m_get_name() << "?\n\n0.取消\t1.确认\n";
			cin >> opt;
			inputCheck(opt);
			if (opt == 1)
			{	//确认删除
				tStaffList.erase(tStaffList.begin() + i);
				cout << "已删除!" << endl;
				system("ping 127.1 -n 2 >nul");	//暂停显示2秒
			}
			else if (opt == 0)
			{	//取消删除
				cout << "已取消!" << endl;
				system("ping 127.1 -n  >nul");	//暂停显示2秒
			}
		}
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
		if (findOfficialStaff(num, &i))	//函数查找正式员工
		{	//找到对应员工，再次确认是否删除
			cout << "\n确认删除员工" << (oStaffList.begin() + i)->m_get_name()
				<< "?\n\n0.取消\t1.确认\n";	//显示员工姓名
			cin >> opt;
			inputCheck(opt);
			if (opt == 1)
			{	//根据i的值确定需要删除的员工位置
				oStaffList.erase(oStaffList.begin() + i);
				cout << "已删除!" << endl;
				system("ping 127.1 -n 2 >nul");	//暂停显示2秒
			}
			else if (opt == 0)
			{
				cout << "已取消!" << endl;
				system("ping 127.1 -n 2 >nul");	//暂停显示2秒
			}
		}
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

//列出所有员工信息
void checkAllMenu()
{
	int type(-1);
	system("cls");
	cout << "0.纵向显示员工信息\n1.横向显示员工信息\n默认纵向(0)\n";
	cin >> type;
	inputCheck(type);	//输入检查
	//根据输入确定显示方式
	if (type == 0)	//纵向显示每个员工信息
	{
		//显示正式员工信息
		cout << endl << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			it->m_display();
		}
		//显示临时员工信息
		cout << endl << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			it->m_display();
		}
	}
	else if (type == 1)	//横向显示每个员工信息
	{
		//显示正式员工信息
		cout << "正式员工：\n";
		for (auto it = oStaffList.begin(); it != oStaffList.end(); it++)
		{
			it->m_display(1);
		}
		//显示临时员工信息
		cout << "临时员工：\n";
		for (auto it = tStaffList.begin(); it != tStaffList.end(); it++)
		{
			it->m_display(1);
		}
	}
	system("pause");
}