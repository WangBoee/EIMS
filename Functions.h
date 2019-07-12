#pragma once

void menu();
//查看员工信息
void checkInfo();
//修改员工信息
void editInfo();
//添加新员工
void newStaff();
//删除员工 
void deleteStaff();
//从文件读取临时员工信息
void readTSL();
//将所有临时员工信息存入文件
void writeTSL();
//从文件读取正式员工信息
void readOSL();
//将所有正式员工信息存入文件
void writeOSL();

void print(const string& str);
