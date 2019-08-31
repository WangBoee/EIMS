//==============员工信息管理系统==============
//开发环境：Visual Studio 2019
//调试平台：Windows 10 x64
//========================================
/*  ----Copyright © 2019 STL真香 All Rights Reserved---- */
//========================================

#include "Functions.h"
#include "menu.h"

using namespace YUFEI;
using namespace WANGBOYI;
using namespace XIANGQIAOSHUN;

vector<Tempstaff> tStaffList;	//临时员工列表
vector<Officialstaff> oStaffList;	//正式员工列表

//主函数
int main(void)
{	//分别从文件读取临时、正式员工数据
	readTSL();
	readOSL();
	int opt = -1;	//opt存储用户输入的操作，初值-1，无任何功能
	while (opt != 0)
	{
		system("cls");	//清屏
		print("========员工工资管理系统=======");
		mainMenu();	//显示主菜单
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			searchMenu();	//查询员工信息菜单
			break;
		case 2:
			system("cls");
			newStaffMenu();	//录入新的员工菜单
			break;
		case 3:
			system("cls");
			deleteStaffMenu();	//删除员工信息菜单
			break;
		case 4:
			system("cls");
			editMenu();	//修改员工信息菜单
			break;
		case 5:
			system("cls");
			checkAllMenu();	//所有员工信息菜单
		default:
			break;
		}
	}
	writeOSL();	//退出程序前分别将正式、临时员工信息写入文件
	writeTSL();
	print("----Copyright @ 2019 STL真香 All Rights Reserved----");
	Sleep(1000);
	return 0;
}

//=======================================
//Project creatied by Boi_Wong with Visual Studio 2019 on 2019.06.22
//=======================================
//最后修改于2019.08.25