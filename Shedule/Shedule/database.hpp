#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>


using std::string;
using std::to_string;
using std::stoi;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::set;
using std::pair;

enum Group { none = 0, MK101, MK102, MN101, MN102, MP101, MT101, MT102, MT103 };
enum Week { ODD = 1, EVEN };




struct TimeOfDay
{
	int hour;
	int minut;
};

struct TimeRange
{
	TimeOfDay start;
	TimeOfDay end;
};

struct Lecturer
{
	string first_name;
	string last_name;
	string middle_name;
};

struct Subject {
	enum SubjectType { LECTURE = 0, PRACTICE, LAB };
	string name;
	string room;
	int number;
	SubjectType s_type;
	Lecturer lecturer;
	TimeRange time_range;
};


struct Day
{
	int weekday;
	vector<Subject> subjects;
};


class DataBase {
public:
	DataBase()
	{

	};
	~DataBase()
	{

	};

	vector<Day> getSchedule(string group, Week week)
	{
		return vector<Day>();
	}

private:
	
	//-----------------------------------------------
	//		Ìועמהû נאבמעû ס ÁÄ PostgreSQL
	//

	
};