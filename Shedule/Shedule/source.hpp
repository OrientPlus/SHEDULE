#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/completion_queue.h>
#include "proto/schedule.grpc.pb.h"

#include "database.hpp"



using std::string;
using std::to_string;
using std::stoi;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;



class ScheduleServer final : public schedule::SheduleService::Service
{
public:
    grpc::Status GetSchedule(grpc::ServerContext* context, const schedule::ScheduleRequest* request, schedule::ScheduleResponse* response) override
    {
        // ��������� 
        vector<Day> even_week = db.getSchedule(request->group(), Week::EVEN);
        for (auto it : even_week)
        {
            // ��������� ���� ��� �������� ������
            schedule::Day* day = response->add_evenweek();
            day->set_weekday(it.weekday);

            // ��������� �������
            for (auto subj_it : it.subjects)
            {
                schedule::Subject* subj = day->add_subjects();
                subj->set_name(subj_it.name);
                subj->set_number(subj_it.number);
                subj->set_room(subj_it.room);

                Subject::SubjectType st = subj_it.s_type;
                subj->set_type(schedule::Subject_SubjectType(st));

                // ��������� �������������
                schedule::Lecturer* lec = subj->mutable_lecturer();
                lec->set_firstname(subj_it.lecturer.first_name);
                lec->set_lastname(subj_it.lecturer.last_name);
                lec->set_middlename(subj_it.lecturer.middle_name);
                subj->set_allocated_lecturer(lec);

                // ��������� ��������� ���������� ��������
                schedule::TimeRange* tr = subj->mutable_timerange();
                // ��������� TimeOfDay ���� ��� ���������� ����������
                schedule::TimeOfDay *time_of_day_start = tr->mutable_start();
                schedule::TimeOfDay* time_of_day_end = tr->mutable_end();
                time_of_day_start->set_hour(subj_it.time_range.start.hour);
                time_of_day_start->set_minut(subj_it.time_range.start.minut);
                time_of_day_end->set_hour(subj_it.time_range.end.hour);
                time_of_day_end->set_minut(subj_it.time_range.end.minut);
                tr->set_allocated_start(time_of_day_start);
                tr->set_allocated_end(time_of_day_end);
                subj->set_allocated_timerange(tr);
            }
        }

        vector<Day> odd_week = db.getSchedule(request->group(), Week::ODD);
        for (auto it : odd_week)
        {
            // ��������� ���� ��� ������ ������
            schedule::Day* day = response->add_oddweek();
            day->set_weekday(it.weekday);

            // ��������� �������
            for (auto subj_it : it.subjects)
            {
                schedule::Subject* subj = day->add_subjects();
                subj->set_name(subj_it.name);
                subj->set_number(subj_it.number);
                subj->set_room(subj_it.room);

                Subject::SubjectType st = subj_it.s_type;
                subj->set_type(schedule::Subject_SubjectType(st));

                // ��������� �������������
                schedule::Lecturer* lec = subj->mutable_lecturer();
                lec->set_firstname(subj_it.lecturer.first_name);
                lec->set_lastname(subj_it.lecturer.last_name);
                lec->set_middlename(subj_it.lecturer.middle_name);
                subj->set_allocated_lecturer(lec);

                // ��������� ��������� ���������� ��������
                schedule::TimeRange* tr = subj->mutable_timerange();
                // ��������� TimeOfDay ���� ��� ���������� ����������
                schedule::TimeOfDay* time_of_day_start = tr->mutable_start();
                schedule::TimeOfDay* time_of_day_end = tr->mutable_end();
                time_of_day_start->set_hour(subj_it.time_range.start.hour);
                time_of_day_start->set_minut(subj_it.time_range.start.minut);
                time_of_day_end->set_hour(subj_it.time_range.end.hour);
                time_of_day_end->set_minut(subj_it.time_range.end.minut);
                tr->set_allocated_start(time_of_day_start);
                tr->set_allocated_end(time_of_day_end);
                subj->set_allocated_timerange(tr);
            }
        }


        return grpc::Status::OK;
    }

    // "0.0.0.0:1010"
    void run(string address);


private:
    DataBase db;
};