//
// Created by Deb on 4/12/2025.
//

#include "HNode.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

hNode::hNode(string s){
    key = s;
    size = 450;
    valueArr = new string[450];
    valuesCt = 0;
    // this constructor sets the key in the node to be s, sets the size of the node's
    // value array to be 450 (yes, this isn't a terribly space-efficient way to store the
    // values.  You're learning hashmaps in this lab.  Stay focused people.)
    // you should then create a new valueArr of size 450 on the heap.
    // since there are no values in the value array yet, it's valuesCt should be set to 0
}
hNode::hNode(){
    key = "";
    size = 0;
    valueArr = nullptr;
    valuesCt = 0;
}
hNode::hNode(string s, string v){
    // this constructor sets the key in the node to be s,
    // sets the size of the node's value array to be 450 (yes, this isn't a terribly space-efficient way to store the
    // values.  You're learning hashmaps in this lab.  Stay focused people.)
    // you should then create a new valueArr of size 450 on the heap.
    // Then set the first value in the valueArr to be v
    // and the valuesCt to be 1 (since you just added a value)
    key = s;
    size = 450;
    valueArr = new string[450];
    valueArr[0] = v;
    valuesCt = 1;


}
void hNode::addValue(string v) {
    if (valuesCt >=450) {
        std::cout<<"Attempted to add more values than originally allocated for"<<std::endl;
        return;
    }
    valuesCt++;
    valueArr[valuesCt-1] = v;
    // this method is short - you just add v to the end of the values in the valueArr and
    // then increase the valuesCt.
    // I put in a warning for if you have more values in the valueArr than the size of the
    // array.

}
string hNode::getRandValue() {
    if (valuesCt = 0) {
        return "";
    }
    int random = rand() % (valuesCt -1);
    return valueArr[random];
    // this is another short method - just generates a random number less than the
    // count of the values in teh valueArr, and then returns the word at that index
    // in the valueArr.  If the valueArr is empty, it returns an empty string.

}
hNode::~hNode() {
    delete [] valueArr;
}