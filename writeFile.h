#pragma once
#include <fstream>
#include <vector>
#include "tempStaff.h"
#include "officialStaff.h"

//将所有正式员工信息存入文件
void writeOSL();

//将所有临时员工信息存入文件
void writeTSL();