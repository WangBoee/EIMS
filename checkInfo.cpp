#include "Functions.h"
//修正编码


void checkInfo()
{
	/*	TO DO:
	0.以不同方式显示员工信息（横向、纵向）
	1.列出所有员工信息
	2.完善查找逻辑
	*/
	string num;	//临时存储输入编号
	int type(-1);
	cout << "========查询员工信息=======" << endl << endl;
	cout << "0.按员工类型查找\n1.列出所有临时员工信息\n\n";

	cin >> type;
	while (type != 0 && type != 1)
	{
		cout << "输入错误，请重新输入：";
		cin >> type;
	}

	switch (type)
	{
	case 0:
		cout << "输入员工编号:";
		cin >> num;
		findStaff(num);
		break;
	case 1:
		showAll();
		break;
	}

	system("pause");
}
