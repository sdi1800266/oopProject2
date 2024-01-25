#ifndef COURSE_H
#define COURSE_H

#include "person.h"

class Course {
    private:
        string coursename ;
        SemesterType semester ;
        int ects ;
        bool mandatory ;
    
    public:
        int idProfessor;

        Course(const string& coursenam, SemesterType s, int ect, const bool mand) ;
        
        ~Course() ;

        string getCourseName() const ;
        SemesterType getSemester() const ;
        int getEcts() const ;
        bool getisMandatory() const ;

        void setCourseName(const string& name);
        void setSemester(SemesterType s);
        void setEcts(const int e);
        void setMandatory(bool man);
        
        //overloading the << operator to print objects of type Course
        friend ostream& operator << (ostream& os, const Course& c) ;

        //function to move a course to a different semester
        void moveCourseToSemester(SemesterType newSemester) ;
        
        //function to print course details
        void printCourseDetails() ;

};

#endif