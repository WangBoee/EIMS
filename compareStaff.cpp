#include "compareStaff.h"

//根据正式员工编号升序排序
bool comp_num(Officialstaff& s0, Officialstaff& s1)
{
	if (s0.m_get_num() < s1.m_get_num())
		return true;
	return false;
}

//重载，根据临时员工编号升序排序
bool comp_num(Tempstaff& t0, Tempstaff& t1)
{
	if (t0.m_get_num() < t1.m_get_num())
		return true;
	return false;
}

//根据正式员工实发工资升序排序，若相同，则按编号升序排序
bool comp_salary(Officialstaff& s0, Officialstaff& s1)
{
	if (s0.m_get_salary() == s1.m_get_salary())
		return(s0.m_get_num() < s1.m_get_num());
	else
		return (s0.m_get_salary() < s1.m_get_salary());
}

//重载，根据临时员工实发工资升序排序
bool comp_salary(Tempstaff& t0, Tempstaff& t1)
{
	if (t0.m_get_salary() == t1.m_get_salary())
		return(t0.m_get_num() < t1.m_get_num());
	else
		return(t0.m_get_salary() < t1.m_get_salary());
}
