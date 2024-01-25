#include "person.h"

class student : public Person {
    private:
        SemesterType semester;

    public:
        student(const string&name, int age, const string&email, 
        const string& gender, const string& nationality, int id, SemesterType semester);

        SemesterType getSemester() const ;
        void setSemester(SemesterType s);

        map<string,float> enrolledCourses;
        map<string,float> passedCourses;

        ~student();

        static int ectsCount ;
        static int mandatoryCourses;

};