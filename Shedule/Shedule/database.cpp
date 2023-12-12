#include "database.hpp"


class postgredb
{
private:
	friend class scheduleserver;

};

DataBase::DataBase(const string& db_name) : db(db_name, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) {
    /*db.exec("PRAGMA foreign_keys = ON;");
    initializeDatabase();*/
}


void DataBase::insertData(const vector<Day>& l_d, Group group) {

}

void DataBase::insertLecturers(const vector<Lecturer>& l_v) {
    try {
        for (auto lecturer : l_v) {

            SQLite::Statement query(db, "INSERT INTO Lecturers (first_name TEXT, last_name TEXT, middle_name TEXT) VALUES (" + lecturer.first_name + ", " + lecturer.last_name + ", " + lecturer.middle_name + ");");
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Insertion error: " << e.what() << std::endl;
    }
}


void DataBase::insertGroups(const vector<string>& l_gr) {
    try {
        for (auto group : l_gr) {

            SQLite::Statement query(db, "INSERT INTO Groups (group_name TEXT) VALUES (" + group + ");");
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Insertion error: " << e.what() << std::endl;
    }
}

void DataBase::insertAudits(const vector<string>& l_a) {
    try {
        for (auto audit : l_a) {

            SQLite::Statement query(db, "INSERT INTO Groups (number TEXT) VALUES (" + audit + ");");
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Insertion error: " << e.what() << std::endl;
    }
}

void DataBase::insertLessons(const vector<Lesson>& l_l) {
    try {
        for (auto lesson : l_l) {

            SQLite::Statement query(db, "INSERT INTO Groups (number TEXT) VALUES (" + lesson.name + ", " + std::to_string(lesson.number) + ", " + std::to_string(lesson.day_of_week)+ ", " + std::to_string(lesson.lecturer_id) + ", " + std::to_string(lesson.audit_id) + ", " +  std::to_string(lesson.week_num) + ", " + std::to_string(lesson.type) + ");");
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Insertion error: " << e.what() << std::endl;
    }
}
