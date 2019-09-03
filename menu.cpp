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
		int type(-1);	//默认值，无意义
		cout << "========查询员工信息=======" << endl << endl;
		cout << "0.临时员工\n1.正式员工\n\n输入员工类型:";
		cin >> type;
		inputCheck(type);	//输入检查
		cout << "输入编号：";
		cin >> num;
		switch (type)
		{
		case 0:	//临时员工查找
			if (!findTempStaff(num))	//调用临时员工查找函数
				cout << "未找到!\n";
			break;
		case 1:	//正式员工查找
			if (!findOfficialStaff(num))	//调用查找函数
				cout << "未找到!\n";
			break;
		}
		system("pause");	//暂停，等待用户按下任意键
	}

	//添加员工菜单
	void newStaffMenu()
	{
		int type;	//临时存储员工类型，0表示临时员工，1表示正式员工
		string num;	//存储输入的编号
		system("cls");
		cout << "========录入新的员工=======" << endl << endl
			<< "0.临时员工\n1.正式员工\n";
		cout << "输入员工类型:";
		cin >> type;	//存储员工类型
		inputCheck(type);	//输入检查
		cout << "输入编号：";
		cin >> num;
		if (type == 0)
		{
			if (findTempStaff(num))	//检查是否已存在对应员工
				cout << "员工已存在!\n";
			else
				newTempStaff(num);	//不存在则添加新员工
		}
		else
		{
			if (findOfficialStaff(num))	//检查是否已存在对应员工
				cout << "员工已存在!\n";
			else
				newOfficialStaff(num);	//不存在则添加新员工
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
			if (findTempStaff(num, &i))	//传入参数为编号和标记位置的 i
				conformDelTemp(i);	//若找到对应员工，再次确认是否删除
			else
			{	//未找到相应员工
				cout << "未找到该员工!" << endl;
				system("ping 127.1 -n 3 >nul");	//暂停3秒后返回主菜单
			}
		}
		else if (type == 1)
		{	//查找删除正式员工
			cout << "输入员工编号:";
			cin >> num;
			if (findOfficialStaff(num, &i))	//传入参数为编号和标记位置的 i
				conformDelOfficial(i);	//找到对应员工，再次确认是否删除
			else
			{	//未找到相应员工
				cout << "未找到该员工!" << endl;
				system("ping 127.1 -n 3 >nul");	//暂停3秒后返回主菜单
			}
		}
	}

	//编辑员工菜单
	void editMenu() {
		int type, i = -1;	//type临时存储员工类型，0表示临时员工，1表示正式员工
		string num;	//存储输入的编号
		system("cls");
		cout << "========修改员工信息=======" << endl << endl
			<< "0.临时员工\n1.正式员工\n";
		cout << "输入员工类型:";
		cin >> type;	//存储员工类型
		inputCheck(type);	//输入检查
		cout << "输入编号：";
		cin >> num;
		switch (type)
		{
		case 0:
			if (findTempStaff(num, &i))	//传入参数为编号和标记位置的 i
				editTS(i);	//编辑临时员工
			else
				cout << "员工不存在！\n";
			system("pause");
			break;
		case 1:
			if (findOfficialStaff(num, &i))	//传入参数为编号和标记位置的 i
				editOS(i);	//编辑正式员工
			else
				cout << "员工不存在！\n";
			system("pause");
			break;
		}
	}

	//所有信息菜单
	void checkAllMenu()
	{
		int type(0);
		system("cls");
		cout << "========所有员工信息=======" << endl << endl
			<< "0.默认列表顺序列出所有员工信息\n"
			<< "1.根据员工编号列出所有员工信息\n"
			<< "2.根据员工工资列出所有员工信息\n"
			<< "输入选择：";
		cin >> type;
		switch (type)
		{
		case 0:
			listDef();	//默认列表顺序列出员工信息
			break;
		case 1:
			listNum();	//根据员工编号列出员工信息
			break;
		case 2:
			listSal();	//根据员工工资列出员工信息
			break;
		default:
			cout << "输入错误\n";
			break;
		}
		system("pause");
	}
}