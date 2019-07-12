#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "tempStaff.h"
#include "officialStaff.h"

using namespace std;

void menu();
//查看员工信息
void checkInfo();
//修改员工信息
void editInfo();
//添加新员工
void newStaff();
//删除员工 
void deleteStaff();
//将所有临时员工信息存入文件
void writeTSL();
//将所有正式员工信息存入文件
void writeOSL();
//从文件读取临时员工信息
void readTSL();
//从文件读取正式员工信息
void readOSL();

void print(const string& str);
