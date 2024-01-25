#include "professor.h"

professor::professor(const string& nam, int a, const string& e, const string& g, const string& nat, int i)
    : Person((nam), (a), (e), (g), (nat), (i)) {
        //cout << "Professor created." << endl;
    }

professor::~professor(){
    //cout << "Professor deleted" << endl;
}