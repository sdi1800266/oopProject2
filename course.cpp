#include "course.h"

Course::Course(const string& coursenam, SemesterType s, int ect, const bool mand)
    :coursename(coursenam), semester(s), ects(ect), mandatory(mand) {
        //cout << "Course created." << endl;
    }

Course::~Course(){
    //cout << "Course deleted." << endl;
}

string Course::getCourseName() const {
    return coursename;
}

SemesterType Course::getSemester() const {
    return semester;
}

int Course::getEcts() const {
    return ects;
}

bool Course::getisMandatory() const {
    return mandatory;
}

void Course::setCourseName(const string& coursenam) {
    coursename = coursenam;
}

void Course::setSemester(SemesterType s) {
    semester = s;
}

void Course::setEcts(const int e) {
    ects = e;
}

void Course::setMandatory(bool man) {
    mandatory = man;
}

void Course::moveCourseToSemester(SemesterType newSemester) {
    semester = newSemester;
    cout << "Course " << Course::getCourseName() << " moved to " << " semester " << newSemester << "." << endl;
}

void Course::printCourseDetails() {
    cout << "Course's Name: " << Course::getCourseName() << " " << endl
        << "Course's Semester: " << Course::getSemester() << " " << endl
        << "Course's Ects: " << Course::getEcts() << " " << endl
        << "Is Course Mandatory: " << (Course::getisMandatory() ? "yes" : "no") << endl;
 }