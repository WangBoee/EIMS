#pragma once
#include <vector>
#include "officialStaff.h"
#include "tempStaff.h"

using XIANGQIAOSHUN::Officialstaff;
using YUFEI::Tempstaff;

extern vector<Officialstaff> oStaffList;
extern vector<Tempstaff> tStaffList;

namespace XIANGQIAOSHUN {
	//根据正式员工编号升序排序
	bool comp_num_o(Officialstaff& p_p_s0, Officialstaff& p_p_s1);
	//重载，根据临时员工编号升序排序
	bool comp_num_t(Tempstaff& p_t0, Tempstaff& p_t1);
	//根据正式员工实发工资升序排序，若相同，则按编号升序排序
	bool comp_salary_o(Officialstaff& p_s0, Officialstaff& p_s1);
	//重载，根据临时员工实发工资升序排序
	bool comp_salary_t(Tempstaff& p_t0, Tempstaff& p_t1);
	//根据正式员工编号降序排序
	bool comp_num_down_o(Officialstaff& p_s0, Officialstaff& p_s1);
	//重载，根据临时员工编号降序排序
	bool comp_num_down_t(Tempstaff& p_t0, Tempstaff& p_t1);
	//根据正式员工实发工资降序排序，若相同，则按编号降序排序
	bool comp_salary_down_o(Officialstaff& p_s0, Officialstaff& p_s1);
	//重载，根据临时员工实发工资降序排序
	bool comp_salary_down_t(Tempstaff& p_t0, Tempstaff& p_t1);
}