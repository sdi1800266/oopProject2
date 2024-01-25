#include "secretary.h"


int main() {

    //Person *Diamantopoulos_Thodoris = new Person("Diamantopoulos Thodoris", 24, "tdiamantopoulos@uoa.gr", "male", "greek", 1800266);
    //Person Vasou_Maria("Vasou Maria", 19, "mvasou@uoa.gr", "female", "greek", 2200263);
    student Ioannidis_Fotis("Ioannidis Fotis", 18, "fioannidis@uoa.gr", "male", "greek", 2300148, FALL2);
    student Diamantopoulos_Thodoris("Diamantopoulos Thodoris", 24, "tdiamantopoulos@uoa.gr", "male", "greek", 1800266, EPIPTYXIW);
    student Vasou_Maria("Vasou Maria", 19, "mvasou@uoa.gr", "female", "greek", 2200263, FALL2);
    professor Lygizou_Anastasia("Lygizou Anastasia", 31, "alygizou@di.gr", "female", "greek", 1011);
    Course Object_Oriented_Programming("Object Oriented Programming", FALL2, 8, true);
    Course Calculus1("Calculus I", SPRING1, 8, true);
    Course Operating_Systems("Operating Systems", FALL3, 8, true);

    secretary *Secretary = new secretary();

    /*
    Secretary->addPerson("Diamantopoulos Thodoris", 24, "tdiamantopoulos@uoa.gr", "male", "greek", 1800266);
    Secretary->editPerson(1800266,"Diamantopoulos Thodoris", 24, "tdiamantopoulos@uoa.gr", "male", "greek", 1800267);
    Secretary->deletePerson(1800266);
    Secretary->deletePerson(1800267);
    */
    //cout << "Number of Persons: " << Person::getCount() << endl;
   
    //Diamantopoulos_Thodoris->printPersonDetails();
    //delete Diamantopoulos_Thodoris;
    
    //Vasou_Maria.printPersonDetails();

    //Diamantopoulos_Thodoris.editPerson(Diamantopoulos_Thodoris.getId(),"Diamantopoulos Thodoris", 25, "tdiamantopoulos@uoa.gr", "male", "greek", 1800266 );
    //cout << "Number of Persons: " << Person::getCount() << endl;

    //Object_Oriented_Programming.printCourseDetails();
    //Object_Oriented_Programming.moveCourseToSemester(SPRING2);
    Secretary->addStudent(&Ioannidis_Fotis);
    Secretary->addStudent(&Diamantopoulos_Thodoris);
    Secretary->addStudent(&Vasou_Maria);
    Secretary->addProfessor(&Lygizou_Anastasia);
    Secretary->addCourse(&Object_Oriented_Programming);
    Secretary->assignProfessorToCourse(&Lygizou_Anastasia,&Object_Oriented_Programming);
    Secretary->assignProfessorToCourse(&Lygizou_Anastasia,&Calculus1);
    Secretary->assignProfessorToCourse(&Lygizou_Anastasia,&Operating_Systems);
    Secretary->addCourse(&Calculus1);
    Secretary->addCourse(&Operating_Systems);
    

    Secretary->enrollStudentToCourse(&Ioannidis_Fotis, &Object_Oriented_Programming);
    Secretary->enrollStudentToCourse(&Ioannidis_Fotis, &Calculus1);
    Secretary->enrollStudentToCourse(&Diamantopoulos_Thodoris, &Object_Oriented_Programming);
    Secretary->enrollStudentToCourse(&Vasou_Maria,&Object_Oriented_Programming);
    Secretary->enrollStudentToCourse(&Diamantopoulos_Thodoris,&Operating_Systems);

    Secretary->gradeStudents(&Ioannidis_Fotis, &Object_Oriented_Programming,&Lygizou_Anastasia, 5.1);
    Secretary->gradeStudents(&Diamantopoulos_Thodoris,&Object_Oriented_Programming,&Lygizou_Anastasia, 8);
    Secretary->gradeStudents(&Vasou_Maria,&Object_Oriented_Programming,&Lygizou_Anastasia, 4.9);
    Secretary->gradeStudents(&Ioannidis_Fotis,&Calculus1,&Lygizou_Anastasia,4.5);
    Secretary->gradeStudents(&Diamantopoulos_Thodoris,&Operating_Systems,&Lygizou_Anastasia,10);

    Secretary->passedCourse(&Object_Oriented_Programming);
    Secretary->professorStatistics(&Lygizou_Anastasia);
    
    //Secretary->studentStatisticsSemester(&Ioannidis_Fotis);
    Secretary->studentStatisticsSemester(&Diamantopoulos_Thodoris);
    //Secretary->studentStatisticsSemester(&Vasou_Maria);
    Secretary->studentStatisticsGeneral(&Diamantopoulos_Thodoris);

    delete Secretary;

    return 0;
}

