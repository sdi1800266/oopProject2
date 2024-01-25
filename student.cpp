#include "student.h"

int student::ectsCount = 0;
int student::mandatoryCourses = 0;

student::student(const string& nam, int a, const string& e, const string& g, const string& nat, int i, SemesterType s)
    : Person((nam), (a), (e), (g), (nat), (i)), semester(s) {
        //cout << "Student created." << endl;
    }

student::~student() {
    //cout << "Student has deleted" << endl;
}

SemesterType student::getSemester() const{
    return semester;
}

void student::setSemester(SemesterType s) {
    semester = s;
}