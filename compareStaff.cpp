#include "compareStaff.h"

using YUFEI::Tempstaff;
using XIANGQIAOSHUN::Officialstaff;

namespace XIANGQIAOSHUN {
	//根据正式员工编号升序排序
	bool comp_num_o(Officialstaff& p_s0, Officialstaff& p_s1)
	{	//p_s0的编号小于p_s1编号，返回true，反之
		return (p_s0.m_get_num() < p_s1.m_get_num());
	}

	//重载，根据临时员工编号升序排序
	bool comp_num_t(Tempstaff& p_t0, Tempstaff& p_t1)
	{
		return (p_t0.m_get_num() < p_t1.m_get_num());
	}

	//根据正式员工实发工资升序排序，若相同，则按编号升序排序
	bool comp_salary_o(Officialstaff& p_s0, Officialstaff& p_s1)
	{
		if (p_s0.m_get_salary() == p_s1.m_get_salary())
			return(p_s0.m_get_num() < p_s1.m_get_num());
		else
			return (p_s0.m_get_salary() < p_s1.m_get_salary());
	}

	//重载，根据临时员工实发工资升序排序
	bool comp_salary_t(Tempstaff& p_t0, Tempstaff& p_t1)
	{
		if (p_t0.m_get_salary() == p_t1.m_get_salary())
			return (p_t0.m_get_num() < p_t1.m_get_num());
		else
			return (p_t0.m_get_salary() < p_t1.m_get_salary());
	}

	//根据正式员工编号降序排序
	bool comp_num_down_o(Officialstaff& p_s0, Officialstaff& p_s1)
	{
		return (p_s0.m_get_num() > p_s1.m_get_num());
	}

	//重载，根据临时员工编号降序排序
	bool comp_num_down_t(Tempstaff& p_t0, Tempstaff& p_t1)
	{
		return (p_t0.m_get_num() > p_t1.m_get_num());
	}

	//根据正式员工实发工资升序排序，若相同，则按编号降序排序
	bool comp_salary_down_o(Officialstaff& p_s0, Officialstaff& p_s1)
	{
		if (p_s0.m_get_salary() == p_s1.m_get_salary())
			return (p_s0.m_get_num() > p_s1.m_get_num());
		else
			return (p_s0.m_get_salary() > p_s1.m_get_salary());
	}

	//重载，根据临时员工实发工资升序排序
	bool comp_salary_down_t(Tempstaff& p_t0, Tempstaff& p_t1)
	{
		if (p_t0.m_get_salary() == p_t1.m_get_salary())
			return (p_t0.m_get_num() > p_t1.m_get_num());
		else
			return (p_t0.m_get_salary() > p_t1.m_get_salary());
	}
}