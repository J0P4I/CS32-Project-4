#include "../include/hashmap.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    //instantiate a hashmap of valuetype int
    HashMap<int> hm;

    assert(hm.size() == 0);

    hm.insert("keyone", 5);
    
    hm.insert("keyfour", 299);

    assert(*(hm.find("keyone")) == 5);
 
    cout << "Value of keyone: " << *hm.find("keyone") << endl;

    assert(hm.find("keytwo") == nullptr);

    assert(hm.find("keythree") == nullptr);


    cout << "All test cases passed!" << endl;
}
