#include "person.h"

int Person::count =0;

Person::Person(const string& nam, int a, const string& e, const string& g, const string& nat, int i)
    : name(nam), age(a), email(e), gender(g), nationality(nat), id(i) {
    count++;
    //cout << "Person created." << endl;
}


Person::~Person() {
    //reduce count if person is deleted
    count--;  
    //cout << "Person deleted" << endl ;
}

string Person::getName() const {
    return name;   
}

int Person::getAge() const {
    return age;    
} 

string Person::getEmail() const {
    return email ;
}

string Person::getGender() const {
    return gender;
}

string Person::getNationality() const {
    return nationality;
}

int Person::getId() const {
    return id;
}

int Person::getCount() {
    return count;
}
void Person::setName(const string& nam) {
    name = nam;
}

void Person::setAge(int a) {
    age = a;
}

void Person::setEmail(const string& e) {
    email = e;
}

void Person::setGender(const string& g) {
    gender = g;
}

void Person::setNationality(const string& nat) {
    nationality = nat;
}

void Person::setId(const int i) {
    id = i;
}

//void Person::printPerson(const Person& person) {
    void Person::printPersonDetails() {
    cout << "Name: " << Person::getName() << " "<< endl
        << "Age: " << Person::getAge()<< endl
        << "Email: " << Person::getEmail() << endl
        << "Gender: " << Person::getGender() << endl
        << "Nationality: " << Person::getNationality() << endl
        << "ID: " << Person::getId() << "." << endl << "-------------------------------" << endl ;
}
