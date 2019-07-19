//==============员工信息管理系统==============
//开发环境：Visual Studio 2019
//调试平台：Windows 10 x64
//========================================
/*  ----Cpyright © 2019 STL真香 All Rights Reserved---- */
//========================================
/*  同目录下已生成用于存储员工数据的对应文件，同时文件中已有部分数据  */

//officialStaffList.dat:
/*
112 b 1 32 3698 home0 213 321 256 354 32 2948
110 c 0 35 3698 home1 214 322 256 351 32 2947
111 a 0 19 3546 home2 324 321 25 356 35 3133
*/

//tempStaffList.dat:
/*
123 d 0 23 32165 home3 321 1236 31250
124 e 1 23 35466 home4 325 355 35613
*/

#include "Functions.h"
#include "menu.h"

using namespace std;
using namespace YUFEI;

vector<Tempstaff> tStaffList;	//临时员工列表
vector<Officialstaff> oStaffList;	//正式员工列表

//主函数
int main(void)
{
	//分别从文件读取临时、正式员工数据
	readTSL();
	readOSL();
	//opt存储用户输入的操作，初值-1，无任何功能
	int opt = -1;
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
			;	//修改员工信息
			break;
		case 5:
			checkAllMenu();
		default:
			break;
		}
	}
	//退出程序前分别将正式、临时员工信息写入文件
	writeOSL();
	writeTSL();
	print("----Copyright @ 2019 STL真香 All Rights Reserved----");
	return 0;
}

//=======================================
//Project creatied by Boi_Wong with Visual Studio 2019 on 2019.06.22
//=======================================
//最后修改于2019.06.29