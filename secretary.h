#ifndef SECRETARY_H
#define SECRETARY_H

#include "student.h"
#include "course.h"
#include "professor.h"

class secretary {
    private:
        vector<Person*> persons;
        vector<professor*> professors;
        vector<student*> students;
        vector<Course*> courses;

    public:
        secretary();

        void addPerson(const string& name, int age, const string& email,
            const string& gender, const string& nationality, int id);
        
        //will be using a person's id to edit them
        void editPerson(int personId, const string& name, int age, const string& email,
             const string&gender, const string& nationality, int id);

        //will be using a person's id to delete them
        void deletePerson(int personId);


        void addProfessor(professor* professor);

        void editProfessor(int personId, const string&name,int age, const string& email,
            const string& gender, const string& nationality, int id);
            
        void deleteProfessor(int personId);

        //void addStudent(const string& name, int age, const string& email,
        //    const string& gender, const string& nationality, int id, SemesterType semester);

        void addStudent(student* student);

        void editStudent(student* student, const string&name,int age, const string& email,
            const string& gender, const string& nationality, int id, SemesterType semester);

        void deleteStudent(int personId);

        void addCourse(Course* course);

        void editCourse(const string& initCourseName, const string& coursename, SemesterType semester, int ects, bool mandatory);

        void deleteCourse(const string& initCourseName);

        //function to assign a professor's Id to a Course's details
        void assignProfessorToCourse(professor* professor, Course* course); 

        //using a map: with string& student->getName() as the key every enrolled course is initiallized to -1 waiting for professor grading
        void enrollStudentToCourse(student* student,Course* course);

        //assigns a grade to the map
        void gradeStudents(student* student, Course* course, professor* professor, float grade);

        //print how many students (in the vector students) have a grade>=5 in the enrolledToCourse map
        void passedCourse(Course* course);

        //calculates and prints the percentage of students that passed or failed a course
        void professorStatistics(professor* professor);

        void studentStatisticsSemester(student* student);

        void studentStatisticsGeneral(student* student);

        void printStudentsCompleted(student* student);


    ~secretary();
};

#endif