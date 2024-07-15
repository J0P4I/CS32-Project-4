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

    //INSERT METHOD TESTS HERE:

    hm.insert("keyone", 8);

    cout << "Value of keyone (after insertion): " << *hm.find("keyone") << endl;

    assert(*hm.find("keyone") == 8);

    //BRACKET TESTS HERE:

    int value_one = hm["keyone"];
    int value_two = hm["Not a Key!"];
    hm["newkey"] = 10;

    assert(value_one == 8);
    assert(value_two == 0);
    assert(*hm.find("newkey") == 10);

    cout << "All test cases passed!" << endl;
}
