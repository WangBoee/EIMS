#include "compareStaff.h"

namespace XIANGQIAOSHUN {
	//根据正式员工编号升序排序
	bool comp_num_up(Officialstaff& s0, Officialstaff& s1)
	{
		return (s0.m_get_num() < s1.m_get_num());
	}

	//重载，根据临时员工编号升序排序
	bool comp_num_up(Tempstaff& t0, Tempstaff& t1)
	{
		return (t0.m_get_num() < t1.m_get_num());
	}

	//根据正式员工实发工资升序排序，若相同，则按编号升序排序
	bool comp_salary_up(Officialstaff& s0, Officialstaff& s1)
	{
		if (s0.m_get_salary() == s1.m_get_salary())
			return(s0.m_get_num() < s1.m_get_num());
		else
			return (s0.m_get_salary() < s1.m_get_salary());
	}

	//重载，根据临时员工实发工资升序排序
	bool comp_salary_up(Tempstaff& t0, Tempstaff& t1)
	{
		if (t0.m_get_salary() == t1.m_get_salary())
			return (t0.m_get_num() < t1.m_get_num());
		else
			return (t0.m_get_salary() < t1.m_get_salary());
	}

	//根据正式员工编号降序排序
	bool comp_num_down(Officialstaff& s0, Officialstaff& s1)
	{
		return (s0.m_get_num() > s1.m_get_num());
	}

	//重载，根据临时员工编号降序排序
	bool comp_num_down(Tempstaff& t0, Tempstaff& t1)
	{
		return (t0.m_get_num() > t1.m_get_num());
	}

	//根据正式员工实发工资升序排序，若相同，则按编号降序排序
	bool comp_salary_down(Officialstaff& s0, Officialstaff& s1)
	{
		if (s0.m_get_salary() == s1.m_get_salary())
			return (s0.m_get_num() > s1.m_get_num());
		else
			return (s0.m_get_salary() > s1.m_get_salary());
	}

	//重载，根据临时员工实发工资升序排序
	bool comp_salary_down(Tempstaff& t0, Tempstaff& t1)
	{
		if (t0.m_get_salary() == t1.m_get_salary())
			return (t0.m_get_num() > t1.m_get_num());
		else
			return (t0.m_get_salary() > t1.m_get_salary());
	}
}