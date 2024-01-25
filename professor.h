#include "person.h"

class professor : public Person {
    public:
        professor(const string& name, int age, const string& email, 
        const string& gender, const string& nationality, int id);

        ~professor();
};