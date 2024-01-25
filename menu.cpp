#include "secretary.h"
#include "menu.h"

int main() {
    
cout << "Welcome to Universtiy of Athens!" << endl;

cout << "How would you like to proceed(to terminate press X): " << endl;

while (exitProgram != 'X'){

    //add Professor
    cout << "To add a Professor press (1)" << endl 
        << "To edit a Professor press (2)" << endl 
        << "To delete a Professor press (3)" << endl
        << "To add a Student press (4)" << endl
        << "To edit a Student press (5)" <<endl
        << "To delete a Student press (6)" << endl
        << "To add a Course press (7)" << endl
        << "To edit a Course press (8)" << endl 
        << "To delete a Course press (9)" << endl
        << "To assign a Professor to a Course press (10)" << endl
        << "To enroll a Student to a Course press (11)" << endl
        << "To print all Students that passed a Course in a semester press (12)" << endl
        << "To print a Professor's statistics in a semester for all their Courses press (13)" << endl
        << "To print a Student's grades for the current semester press (14)" << endl
        << "To print a Student's grader for their whole academic carreer so far press (15)" << endl
        << "To print all students eligible to get their degree press (16)." << endl;
    cin >> proceed;

    if (proceed == 1) {
        cout << "Please insert Professor's details" << endl;
    } 
     
}

return 0;
}

