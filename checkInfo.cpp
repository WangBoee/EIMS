#include "Functions.h"

void checkInfo()
{
	string num;	//临时存储输入编号
	int type(-1);
	cout << "========查询员工信息=======" << endl << endl;
	cout << "0.按照员工类型查找\n1.列出所有员工信息\n\n";

	cin >> type;
	inputCheck(type);	//输入检查
	switch (type)
	{
	case 0:	//按员工类型查找
		system("cls");
		cout << "按员工类型查找\n\n0.正式员工\n1.临时员工\n输入员工类型及编号(如:0 100):";
		cin >> type >> num;
		inputCheck(type);	//输入检查
		switch (type)
		{
		case 0:
			findOfficialStaff(num);	//正式员工查找
			break;
		case 1:
			findTempStaff(num);	//临时员工查找
			break;
		}
		break;
	case 1:
		showAll();
		break;
	}
}
