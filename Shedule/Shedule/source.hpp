#include <grpcpp/grpcpp.h>
#include "proto/shedule.grpc.pb.h"


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

enum Group { MK101, MK102, MN101, MN102, MP101, MT101, MT102, MT103 };
enum Week { EVEN, ODD };

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
        unsigned long long hours = (start + 5400) / 60 / 60,
            minuts = ((start + 5400) / 60) % 60;

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
struct Schedule
{
    Group group;
    vector<Lesson> lessons;
};


class ScheduleServer final : public schedule::ScheduleService::Service 
{
public:
    grpc::Status GetSchedule(grpc::ServerContext* context, const schedule::ScheduleRequest1* request, schedule::ScheduleInfo* response) override {
        // ���������� ������ ��������� ���������� �� ������ request � ��������� response.
        // ������:
        response->set_group(request->group());
        response->set_audit("101");
        response->set_start_time("9:00 AM");
        response->set_end_time("10:30 AM");
        response->set_lesson_name("Math");
        response->set_parity(false);
        response->set_day_of_week(request->day_of_week());
        response->set_lesson_count(1);

        return grpc::Status::OK;
    }

    grpc::Status GetScheduleForWeek(grpc::ServerContext* context, const schedule::ScheduleRequest2* request, schedule::ScheduleInfoContainer* response) override {
        // ���������� ������ ��������� ���������� �� ������ �� ������ request � ��������� response.
        // ������:

        schedule::ScheduleInfo* schedule = response->add_schedule_container();
        schedule->set_group(request->group());
        schedule->set_audit("101");
        schedule->set_start_time("9:00 AM");
        schedule->set_end_time("10:30 AM");
        schedule->set_lesson_name("Math");
        schedule->set_parity(false);
        schedule->set_day_of_week(1);
        schedule->set_lesson_count(1);
        // �������� ������ ���������, ���� ����������.

        return grpc::Status::OK;
    }

    grpc::Status SetSchedule(grpc::ServerContext* context, const schedule::ScheduleInfo* request, schedule::OperationStatus* response) override {
        // ���������� ������ ��������� ���������� �� ������ request � ���������� response.success � true,
        // ���� �������� ��������� �������, ��� � false, ���� ���� ������.
        // ������:
        // ��� ��� ��������� ���������� �����.

        Schedule 

        response->set_error_flag(false); // ������� �����������
        response->set_error("");

        return grpc::Status::OK;
    }

    grpc::Status SetScheduleForWeek(grpc::ServerContext* context, const schedule::ScheduleInfoContainer* request, schedule::OperationStatus* response) override {
        // ���������� ������ ��������� ���������� �� ������ �� ������ request � ���������� response.success � true,
        // ���� �������� ��������� �������, ��� � false, ���� ���� ������.
        // ������:
        // ��� ��� ��������� ���������� �� ������ �����.

        response->set_error_flag(false); // ������� �����������
        response->set_error("");

        return grpc::Status::OK;
    }


private:
    
};