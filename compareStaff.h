#pragma once
#include <vector>
#include "officialStaff.h"
#include "tempStaff.h"

extern vector<Officialstaff> oStaffList;
extern vector<Tempstaff> tStaffList;

//根据正式员工编号升序排序
bool comp_num_up(const Officialstaff& s0, const Officialstaff& s1);

//重载，根据临时员工编号升序排序
bool comp_num_up(const Tempstaff& t0, const Tempstaff& t1);

//根据正式员工实发工资升序排序，若相同，则按编号升序排序
bool comp_salary_up(const Officialstaff& s0, const Officialstaff& s1);

//重载，根据临时员工实发工资升序排序
bool comp_salary_up(const Tempstaff& t0, const Tempstaff& t1);
