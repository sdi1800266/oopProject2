#include "secretary.h"
#include "studentinput.h"
#include "professorinput.h"
#include "courseinput.h"

void update_professor_info(secretary *Secretary){
    std::ofstream outFile("professorinput_new.h");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file for writing.\n";
        return;
    }
    else {
        for (auto& professor : Secretary->professors){
            string profName = professor->getName();
            char *ptr;
            char *charArray;
            const char *delimiter = " ";

            strcpy(charArray, profName.c_str());
            ptr = strtok(charArray, delimiter); 
            char *firstName = ptr;
            char *lastName = strtok(NULL, charArray);

            outFile << "professor " << firstName << '_' << lastName
                    << '("' << profName << '", ' << professor->getAge() << '", "'
                    << professor->getNationality() << '", ' << professor->getId() << ');\n';
        }
    }
    
}


int main() {

    secretary *Secretary = new secretary();

    string name, email, gender, nationality;
    int age, id, professorId,personId, semestertemp;
    bool found;
    SemesterType semester;

    cout << "Welcome to Universtiy of Athens!" << endl;
    int proceed = -1;

    while (proceed != 0){

        //add Professor
        cout << "How would you like to proceed(press 0(zero) to terminate): " << endl
        << "To add a Professor press (1)" << endl 
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

        switch (proceed){
            case 0: {
                //program termination
                return 0;
            }
            case 1: {//add Professor

                cout << "Enter Professor name: " << endl;
                cin >> name;
                cout << "Enter Professor age: " << endl;
                cin >> age;
                cout << "Enter Professor email: " << endl;
                cin >> email;
                cout << "Enter Professor gender: " << endl;
                cin >> gender;
                cout << "Enter Professor nationality: " << endl;
                cin >> nationality;
                cout << "Enter Professor ID: " << endl;
                cin >> id;

                Secretary->addProfessor(new professor(name, age, email, gender, nationality, id));
                proceed = -1;
                //update_professor_info(Secretary);
                break;
            }

            case 2: { //edit Professor
                cout << "Enter ID of the professor you want to edit: " << endl;
                cin >> professorId;

                // find professor based on ID
                found = false;
                for (auto& professor : Secretary->professors) {
                    if (professor->getId() == professorId) {
                        found = true;
                        // edit new professor details
                        cout << "Enter new Professor's details:" << endl;
                        cout << "Professor's new Name: " << endl;
                        cin >> name;
                        cout << "Professor's new Age: " << endl;
                        cin >> age;
                        cout << "Professor's new Email: " << endl;
                        cin >> email;
                        cout << "Professor's new Gender: " << endl;
                        cin >> gender;
                        cout << "Professor's new Nationality: " << endl;
                        cin >> nationality;
                        cout << "Professor's new ID: " << endl;
                        cin >> id;
                        Secretary->editProfessor(professorId,name,age,email,gender,nationality,id);
                        cout << "Professor details updated successfully." << endl;
                    }
                }
                if (found == false) cout << "Professor with ID " << professorId << " not found." << endl;
                proceed = -1;
                break;
            }
                
            case 3: { //delete professor
                cout << "Enter ID of the professor you want to delete: " << endl;
                cin >> professorId;
                found = false;
                for (auto& professor : Secretary->professors){
                    if (professor->getId() == professorId) {
                        found = true;
                        Secretary->deleteProfessor(professorId);
                        cout << "Professor deleted successfully." << endl;
                    }
                }
                if (found == false) cout << "Professor with ID " << professorId << " not found." << endl;
                proceed = -1;
                break;
            }
            
            case 4: {//add student
                cout << "Enter student's name: " << endl;
                cin >> name;
                cout << "Enter student's age: " << endl;
                cin >> age;
                cout << "Enter student's email: " << endl;
                cin >> email;
                cout << "Enter student's gender: " << endl;
                cin >> gender;
                cout << "Enter student's nationality: " << endl;
                cin >> nationality;
                cout << "Enter student's ID: " << endl;
                cin >> id;
                cout << "Enter student's semester (FALL, SPRING): " << endl;
                cin >> semestertemp;

                SemesterType semester = static_cast<SemesterType>(semestertemp);
                Secretary->addStudent(new student(name,age,email,gender,nationality,id,semester));
                cout << "Student " << name << " added succesfully." << endl;

                proceed = -1;
                break;
            }

            case 5: {//edit student
                cout << "Enter ID Of student you want to edit: " << endl;
                cin >> personId;
                found = false;
                for (auto& student : Secretary->students) {
                    if (personId == student->getId()) {
                        found = true;
                        cout << "Enter Student's new name: " << endl;
                        cin >> name;
                        cout << "Enter Student's new age: " << endl;
                        cin >> age;
                        cout << "Enter Student's new email: " << endl;
                        cin >> email;
                        cout << "Enter Student's new gender: " << endl;
                        cin >> gender;
                        cout << "Enter Student's new nationality: " << endl;
                        cin >> nationality;
                        cout << "Enter Student's new ID: " << endl;
                        cin >> id;
                        cout << "Enter Student's new semester (FALL, SPRING, SUMMER): " << endl;
                        cin >> semestertemp;
                        personId = id;
                    }
                }
                SemesterType semester = static_cast<SemesterType>(semestertemp);
                //Secretary->editStudent(student,name,age,email,gender,nationality,id,semester);
                proceed = -1;
                break;
            }

            default: {
                cout << "Wrong input.Please try again." << endl;
                break;
            }   
        }
    proceed = -1;
    }
    return 0;
}
    

