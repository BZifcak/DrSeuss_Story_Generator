//
// Created by Deb on 4/12/2025.
//

#include "voice.h"
#include "HashMap.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

voice::voice(string f1,string f2, int hashfn, int collfn) {
    ht = new hashMap(hashfn, collfn);
    ht->first = "I";
    newfile = f2;
    fn = f1;
    //cout << "hello from voice constructor" << endl;
 //   readFile();
 //   writeFile();
}
voice::~voice() {
    delete ht;
}
void voice::readFile() {
    ifstream infile(fn.c_str(),ios::in);     // open file
    string key;
    string value;
    infile>> key;
    infile >> key;

    while (infile >> value) {          // loop getting single characters
        //cout << key <<": " << value << endl;
        ht->addKeyandValue(key,value);
        //cout << " here in read " << endl;
        key = value;
        value = "";
      //  cout << " in read " << endl;
    }
    ht->addKeyandValue(key,value);
    cout << endl;
    cout<< "finished reading " << fn << " with hashfn: "<< ht->whichHashFn <<" and collfn: " << ht->whichCollisionFn << endl;

    infile.close();
}
void voice::writeFile() {
    ofstream outfile(newfile.c_str(),ios::out);
    outfile << "Hash Function Collisions: " << ht->hashCollisionsCt << ", " << "Collision count: " << ht->collisionsCt << endl;
    outfile << ht->first << " ";
    string key = "";
    //cout << "ht->first:" << ht->first << "findKeyIndex returned: "<< ht->findKeyIndex(ht->first) << endl;
    string value = ht->map[ht->findKeyIndex(ht->first)]->getRandValue();
    int ct = 0;
    int len = 0;
    while (ct < 500 &&  value != "") {
        key = value;
        outfile << key << " ";
        if (len == 11) {
            outfile << "\n";
            len = 0;
        }
        else len++;
        int index = ht->findKeyIndex(key);
        //std::cout << "found "<<key<<" at index: " << index << std::endl;

        if (index < 0 || index >= ht->mapSize || ht->map[index] == nullptr) {
            //std::cout << "dereferencing null from writeFile for key: " << key << std::endl;
            value = ht->first; // soft exits error
            continue;
        } else {
            value = ht->map[index]->getRandValue();
        }
        //cout << "made it past dereferencing" << endl;
        ct++;

    }
    cout<< "finished writing " << newfile << endl;
    outfile.close();
}