#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <SQLiteCpp/SQLiteCpp.h>


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

struct Lesson {
	string name;
	unsigned number;
	unsigned week_num;
	unsigned day_of_week;
	unsigned type;
	unsigned audit_id;
	unsigned lecturer_id;
};


class DataBase {
public:
	DataBase(const string& db_name);

	~DataBase()
	{

	};

	void insertData(const vector<Day>& l_d, Group group);

	void insertLecturers(const vector<Lecturer>& l_v);
	void insertAudits(const vector<string>& l_a);
	void insertLessons(const vector<Lesson>& l_l);
	void insertGroups(const vector<string>& l_gr);
	void insertGenereal();

	vector<Day> getSchedule(string group, Week week)
	{
		return vector<Day>();
	}

private:
	SQLite::Database db;
	//-----------------------------------------------
	//		Методы работы с БД PostgreSQL
	//

	vector<Day> getSchedule2(string group, Week week);
	
};