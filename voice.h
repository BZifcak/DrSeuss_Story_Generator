//
// Created by Deb on 4/12/2025.
//

#ifndef VOICE_H
#define VOICE_H

#include "HashMap.h"
#include <iostream>
using namespace std;

class voice {
public:
        hashMap *ht;
        string fn;
        string newfile;
        voice();
        ~voice();
        voice(string file,string outfile, int hashfn, int collfn);
        void readFile();
        void writeFile();
};
#endif //VOICE_H
