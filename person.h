#ifndef PERSON_H
#define PERSON_H

#include "semestertype.h"


class Person {
    private:
        string name; 
        int age;          
        string email ;
        string gender ;
        string nationality ;
        int id ; 
        SemesterType semester;

        //count persons
        static int count; 
        

    public: 
        Person(const string& nam, int a, const string& e, const string& g, const string& nat, int i);
        ~Person(); 
        string getName() const;  
        int getAge() const;  
        string getEmail() const ;
        string getGender() const;
        string getNationality() const;
        int getId() const;
        
        void setName(const string& nam);
        void setAge(int a);
        void setEmail(const string& e);
        void setGender(const string& g);
        void setNationality(const string& nat);
        void setId(const int i);

        friend class professor;
        friend class student;

        //overloaded operator to print persons
        //friend ostream& operator<<(ostream& os, const Person& person);

       //count persons
        static int getCount(); 

        void printPersonDetails();


        // function to calculate ects for a student
        static int getTotalEcts();

};

#endif