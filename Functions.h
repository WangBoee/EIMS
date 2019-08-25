#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "tempStaff.h"
#include "officialStaff.h"

using namespace std;
using XIANGQIAOSHUN::Officialstaff;
using YUFEI::Tempstaff;

extern vector<Tempstaff> tStaffList;
extern vector<Officialstaff> oStaffList;

namespace YUFEI
{
	//将所有临时员工信息存入文件
	void writeTSL();
	//将所有正式员工信息存入文件
	void writeOSL();
	//从文件读取临时员工信息
	void readTSL();
	//从文件读取正式员工信息
	void readOSL();
};

namespace WANGBOYI {
	//输入检查
	void inputCheck(int& p_t);
	//查找正式员工
	bool findOfficialStaff(string& p_num, int* p_ret = NULL);
	//查找临时员工
	bool findTempStaff(string& p_num, int* p_ret = NULL);
	//添加新临时员工
	void newTempStaff(string& p_num);
	//添加新正式员工
	void newOfficialStaff(string& p_num);
	//确认删除临时员工
	void conformDelTemp(int& p_i);
	//确认删除正式员工
	void conformDelOfficial(int& p_i);
	//依次输出字符串所有字符
	void print(const string& p_str);
	//编辑正式员工信息
	void editOS(int& p_i);
	//编辑临时员工信息
	void editTS(int& p_i);
	//默认列表顺序列出员工信息
	void listDef();
	//根据员工编号列出员工信息
	void listNum();
	//根据员工工资列出员工信息
	void listSal();
}