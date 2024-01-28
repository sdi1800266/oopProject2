#include "secretary.h"

secretary::secretary(){
    //cout << "Secretary has been created" << endl;
}

secretary::~secretary() {
    //cout << "Secretary has been deleted" << endl ;
}

void secretary::addPerson(const string& name, int age, const string& email,
    const string& gender, const string& nationality, int id) {

    Person* newPerson = new Person(name, age, email, gender, nationality, id);
    persons.push_back(newPerson);
}

void secretary::editPerson(int personId, const string& name, int age, const string& email,
    const string& gender, const string& nationality, int id) {
    
    for (auto& person : persons) {
        //if there is an ID corresponding to a person
        if (person->getId() == personId) {
            person->setName(name);
            person->setAge(age);
            person->setEmail(email);
            person->setGender(gender);
            person->setNationality(nationality);
            person->setId(id);
            return;
        }
    }
    cout << "Person with ID: " << personId << "  not found." << endl;
}

void secretary::deletePerson(int personId) {
    for (auto& person : persons) {
        if (person->getId() == personId) {
            cout << "Person with ID: " << personId << " deleted." << endl;
            delete person;
            return;
        }
    }
    cout << "Person with ID: " << personId << " not found." << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////

void secretary::addProfessor(professor* professor) {

    professors.push_back(professor);
    cout << "Professor: " << professor->getName() << " created." << endl; 
}

void secretary::editProfessor(int personId, const string& name, int age, const string& email,
    const string& gender, const string& nationality, int id) {

        for (auto& professor : professors) {
            if (professor->getId() == personId) {
                professor->setName(name);
                professor->setAge(age);
                professor->setEmail(email);
                professor->setGender(gender);
                professor->setNationality(nationality);
                professor->setId(id);
                return;
            }
        }
}

void secretary::deleteProfessor(int personId) {
    for (auto& professor : professors) {
        if (professor->getId() == personId) {
            cout << "Professor with ID: " << personId << " deleted." << endl;
            delete professor;
            return;
        }
    }
    cout << "Professor with ID: " << personId << " not found." << endl;
}

//void secretary::addStudent(const string& name, int age, const string& email,
//      const string& gender, const string& nationality, int id, SemesterType semester) {
    
void secretary::addStudent(student* student) {
            
//            student* newStudent = new student(name, age, email, gender, nationality, id, semester);
            students.push_back(student);
            cout << "Student: " << student->getName() << " added." << endl;
}

void secretary::editStudent(student* student, const string& name, int age, const string& email,
        const string& gender, const string& nationality, int id, SemesterType semester) {
               
                    student->setName(name);
                    student->setAge(age);
                    student->setEmail(email);                    
                    student->setGender(gender);
                    student->setNationality(nationality);
                    student->setId(id);
}

void secretary::deleteStudent(int personId) {
    for (auto& student : students) {
        if (student->getId() == personId) {
            cout << "Student with ID: " << personId << " deleted." << endl;                    delete student;
            delete student;
            return;
        }
    }
    cout << "Student with ID: " << personId << " not found." << endl;
}

void secretary::addCourse(Course* course) {
    courses.push_back(course);
    cout << "Course: " << course->getCourseName() << " has been created." << endl;
}

void secretary::editCourse(const string& initCoursename, const string& coursename, SemesterType semester, int ects, bool mandatory) {

    for (auto& course : courses) {
        if (course->getCourseName() == initCoursename){
            course->setCourseName(coursename);
            course->setSemester(semester);
            course->setEcts(ects);
            course->setMandatory(mandatory);
            return;
        }
    }
}

void secretary::deleteCourse(const string& initCoursename) {
    for (auto& course : courses) {
        if (course->getCourseName() == initCoursename) {
            cout <<"Course: " << initCoursename << " deleted." << endl;
            delete course;
            return;
        }
    }
}


void secretary::assignProfessorToCourse(professor* professor, Course* course){
        course -> idProfessor = professor->getId();
        cout << "Professor: " << professor->getName() << " assigned to teach " << course->getCourseName() << " course." << endl;
};


void secretary::enrollStudentToCourse(student* student,Course* course) {
    if ((student->getSemester()) >= (course->getSemester())){
        if ((student->getSemester() <= SPRING4) && ((course->getSemester() % 2) == (student->getSemester()) % 2) ) {
            student->enrolledCourses[course->getCourseName()] = -1;
            cout << "Student: " << student->getName() << " succesfully enrolled to " << course->getCourseName() << " course." << endl;
        }
    }
    else {
        cout << "Student: " << student->getName() << " cannot enroll to Course: " << course->getCourseName() << " due to their semester." << endl;
    }
}

void secretary::gradeStudents(student* student,Course* course, professor* professor, float grade) {
    if (professor->getId() == course->idProfessor) {
        student->enrolledCourses[course->getCourseName()] = grade ;
        cout << "Professor: " << professor->getName() << " graded Student: " << student->getName() << " with a " << grade << " for Course: " << course->getCourseName() << "." << endl;
        if (student->enrolledCourses[course->getCourseName()] >=5) {
        student->passedCourses[course->getCourseName()] = grade;
        student->ectsCount += course->getEcts();
            if (course->getisMandatory()){
            student->mandatoryCourses++;
            }
        }
    }
    else {
        cout << "Professor: " << professor->getName() << " is not teaching " << course->getCourseName() << "." << endl;
    }
}

//create a .txt file inputing the students that passed the course in the semester
void secretary::passedCourse(Course* course) {
    ofstream outfile("Students that passed Course: " + course->getCourseName() + " in Semester: " + to_string(course->getSemester()) + ".txt");
        
        if (!outfile.is_open()){
            cerr << "Unable to open the file." << endl;
            return;
        }

        for (auto& student : students ) {
            if ((student->enrolledCourses[course->getCourseName()]) >= 5.0) {
                cout << "Student: " << student->getName() << " passed Course: " << course->getCourseName() << " with grade " << (student->enrolledCourses[course->getCourseName()]) << "." << endl;
                if (outfile.is_open()){
                    outfile << "Student: " << student->getName() << " passed Course: " << course->getCourseName() << " with grade " << (student->enrolledCourses[course->getCourseName()]) << "." << endl;
                }
            }
        }
    outfile.close();
}

void secretary::professorStatistics(professor* professor) {
    float sumPassed,sumFailed;
    for (auto& course : courses) {
        sumPassed = 0;
        sumFailed = 0;
        if (professor->getId() == course->idProfessor) {
            for (auto& student : students) {
                //iterate student->enrolledCourses to check if student is enrolled
                if (student->enrolledCourses.find(course->getCourseName()) != student->enrolledCourses.end()) {
                    if (student->enrolledCourses[course->getCourseName()] >=5.0) {
                        sumPassed++;
                    }
                    else if (student->enrolledCourses[course->getCourseName()] != -1) {
                        sumFailed++;
                        cout << "STUDENT " << student->getName() << " FAILED COURSE " << course->getCourseName() << " WITH GRADE::: " << student->enrolledCourses[course->getCourseName()] << "!!!" << endl;
                    }
                }
            }
        cout << "Statistics for Professor's: " << professor->getName() << " Course: " << course->getCourseName() << " :" << endl 
            << "Students Passed: " << sumPassed << endl << "Students Failed: " << sumFailed << endl 
            << "Percentage is: " << sumPassed/(sumFailed+sumPassed) * 100 << "%" << endl;
        }
    }
}

//current semester courses are the ones that have been enrolled
void secretary::studentStatisticsSemester(student* student) {
    SemesterType currentSemester;
    currentSemester = (student->getSemester());
    int coursesEnrolled = 0;
    int coursesPassed = 0;

    for (auto& course : courses) {
        if (student->enrolledCourses.find(course->getCourseName()) != student->enrolledCourses.end()) {
            if (currentSemester == course->getSemester()) {
                cout << "Grade for Student: " << student->getName() << " for Course: " << course->getCourseName() << " in Semester: " << currentSemester  
                << " is: " << student->enrolledCourses[course->getCourseName()] << "." << endl;
                coursesEnrolled++;
                if (student->enrolledCourses[course->getCourseName()] >= 5.0){
                    coursesPassed++;
                }
            }
            //else { cout << "Course not in semester." << endl;}
        }
    }
    cout << "Student: " << student->getName() << " passed " << coursesPassed << " out of " << coursesEnrolled << " courses." << endl;
}

void secretary::studentStatisticsGeneral(student* student) {
    if (student->passedCourses.empty()) {
        cout << "Student: " << student->getName() << "hasn't passed any courses yet." << endl;
    }
    else{
    cout << "Student: " << student->getName() << " has passed the following courses throughout his academic career: " << endl;
        float sumGrade = 0;
        int sumCourses = 0;
        for (auto& course : student->passedCourses) {
            //course.first is the course's name AND course.second is the course's grade
            cout << "     * " << course.first << " with grade: " << course.second << "." << endl;
            sumCourses++;
            sumGrade += course.second;
        }
        cout << "Courses passed: " << sumCourses << "." << endl 
        << "Average grade: " << sumGrade/sumCourses << "." << endl ;
    }
}

void secretary::printStudentsCompleted(student* student) {
    for (auto& student : students) {
        if ((student->ectsCount >= 50) && (student->mandatoryCourses == 5)){
            cout << "Student: " << student->getName() << " can get his degree!!!" << endl;
        }
    }
}