#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>


using std::string;
using std::to_string;
using std::stoi;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;


enum Group {MK101, MK102, MN101, MN102, MP101, MT101, MT102, MT103};
enum Week {EVEN, ODD};

struct LessonTime
{
	// Number of seconds since 0:00
	unsigned long long start;

	string GetStartTime()
	{
		int h_start = start / 60 / 60,
			m_start = (start / 60) % 60;

		string time = to_string(h_start);
		time += ":" + to_string(m_start);

		return time;
	};

	string GetEndTime()
	{
		unsigned long long hours = (start+5400) / 60 / 60,
			minuts = ((start+5400) / 60) % 60;
		
		string time = to_string(hours);
		time += ":" + to_string(minuts);

		return time;
	};

	// format: 13:15 like (int)1315
	void SetTime(string start_time)
	{
		string temp = start_time.substr(0, 2);
		start = stoi(temp) * 60 * 60;
		temp = start_time.substr(3, 2);
		start += stoi(temp) * 60;

		return;
	}
};

struct Lesson
{
	string audit;
	LessonTime time;
	string name;
	int numb;
	int day_of_week;
	Week week;
};


// ���������� ����� ������ �� ���� ���� 
struct Shedule
{
	Group group;
	vector<Lesson> lessons;
};


class Server {
public:
	Server()
	{

	};
	~Server()
	{

	};
	

private:
	// Response_1 ���������� ��������� �������� ���������� �� ��� ������
	// void Response_1();

	// Response_2 ���������� ��������� ���������� �� ���� ����
	// void Response_2();

	
	//-----------------------------------------------
	//		������ ������ � �� PostgreSQL
	//

	// �������� ���������� ��� ������
	int GetSheduleForWeek(Group& gr);
	int GetSheduleForDay(vector<Group>& gr);

	// �������� ������ � ���������� 
	int SetShedule(const Shedule& sh);
	int SetShedule(const vector<Shedule> sh_box);

	
};