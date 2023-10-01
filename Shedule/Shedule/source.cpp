#include "source.hpp"


// ===== Shedule =====
// mk401
// нечетна€
// -- lesson --
//		421
//		13:15
//		Java language
// 
// ---- ¬ходные данные
// group(MK401), audit(421), lesson_name(Java language), 
// week_numb(1), day_of_week(1), numb(1), start(13:15), end(14:45)



int Server::SetShedule(const vector<Shedule> sh_box)
{

	return 0;
}

int Server::SetShedule(const Shedule& sh)
{
	// insert into lesso(numb, start, end, name, day_of_week, week_numb) values(1, 13:15, 14 : 45, 'java languge', 1, 1);
	// insert into groups(name) values(MK401);
	// inset into audit(aud_num) values(421);



	return 0;
}

int Server::GetSheduleForWeek(Group& gr)
{
	// select  'all'
	//	from schedule s
	//	join groups g on s.group_id = g.id
	//	join lesson l on s.lesson_id = l.id
	//	join audit a on s.audit_id = a.id
	// where g.name = group, lesson.week_numb = week_numb, lesson.day_of_week = day_of_week;
	
	
	return 0;
}

int Server::GetSheduleForDay(vector<Group>& gr)
{
	return 0;
}