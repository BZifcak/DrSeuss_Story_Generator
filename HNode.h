//
// Created by Deb on 4/12/2025.
//

#ifndef HNODE_H
#define HNODE_H

#include <iostream>
using namespace std;

class hNode {
    friend class hashMap;
    string key;
    string *valueArr;
    int valuesCt;
    int size;
public:
    hNode();
    // constructor that initializes the key to an empty string, the valueArray to be
    // null, the ValuesCt to be 0, and the Size to be 0;
    ~hNode();
    // the destructor. Deletes the valuesArr (and mine prints out: "destroying <key>")
    hNode(string s);
    // constructor that initializes the key to s, makes a valuesArr of strings (I set mine to be
    // 450 long, sets the valuesCt to 0, and the Size to be whatever length you made the
    // valuesArr (e.g., 450).
    hNode(string s, string v);
    // constructor that initializes the key to s, makes a valuesArr of strings (I set mine to be
    // 450 long, sets the first value in the valuesArr to be v, sets the valuesCt to 1, and the
    // Size to be whatever length you set the valuesArr to be (e.g., 450).
    void addValue(string v);
    // this adds the string v to the value array at valuesCt and increases the count of valuesCt
    // if valuesCt gets bigger than size it will print a warning and stop adding values to the
    // valuesArr (in my tests, I never had an instance where there were more values than 150)
    string getRandValue();
    // this method generates a random index (less than the ValuesCt), goes to that index in the
    // valuesArr, and then returns the string (aka word) that is at that index.
};



#endif //HNODE_H
