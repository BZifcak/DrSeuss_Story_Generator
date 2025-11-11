//
// Created by Deb on 4/12/2025.
//

#include "HashMap.h"
#include "HNode.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

hashMap::hashMap(int hfn, int cfn) {
	//the constructor for teh hashMap.
	// whichHashFn should be set to hfn, and
	// whichCollFn should be set to cfn
	whichHashFn = hfn;
	whichCollisionFn = cfn;
	first = "I"
	// the first is just the very first string used for output.  In the voice constructor
	//     I set first to "I" but you can choose any word in the input file.
	// Set teh mapSize to 57 to start with if you want to get the same ouput I got for the
	// testing data.
	mapSize = 57;
	keysCt = 0;
	// keysCt starts at 0 because there are no keys in the map to start with.
	map = new hNode*[mapSize];
	for (int i = 0; i < mapSize; i++) {
		map[i] = nullptr;
	}
	// here it gets a bit interesting:  you have to make a new map (of type hNode *) on
	// the heap.  This is an array on the heap of pointers to nodes.  Why?  Because when
	// you rehash, you don't need to delete old nodes and make new nodes.  You just need to
	// copy the address of the node from the old map to the new map in reHash.
	// Make sure you loop through and set all your initial addresses in the map array to
	// be Null or nothing will work.
	// then set your hashCollisionsCt  and your collisionsCt to 0.  These are going to
	hashCollisionsCt = 0;
	collisionsCt = 0;
	// keep track of how many collisions your hash function causes.  And, once there's a
	// collision, your collision function may also result in collisions.  We want to keep
	// track of that in the collisionsCt. THat way we can measure the efficiency of our
	// hashing and collision functions.
}
void hashMap::addKeyandValue(string k, string v) {
	// this method finds if and how we need to incorporate the key and/or its accompanying
	//value into the hash map.
	//
	// It first calls getIndex to get the index of the key using one of the hashing functions
	// (getIndex is described below).  There are then 3 possible next steps:
	int index = getIndex(k);
	// 1) If the index returned is the index of an empty location in the map, this method calls
	//    insertNewKeyandValue (described below) to insert the key and its accompanying value
	//    into the map.
	// 2) If the index returned is the location in the map where the key already in the method,
	//    the node's addValue method is called so the value is added to that key's value array.
	// 3) if the index returned is a non-empty location in the map, but that location is not
	//    where the key is located (this is a hashCollision - so increase the hashCollisionCt),
	//    it now calls the dealWithCollisions method (described below)
	//
	if (map[index] == nullptr) {
		insertNewKeyandValue(k,v);
	} else if (map[index]->key == k) {
		map[index]->addValue(v);
	} else if (map[index]->key != k) {
		collisionsCt++;
		dealWithCollisions(k, index);
	}

}

int hashMap::getIndex(string k) {
	switch (whichHashFn) {
		case(1):
			return hashFn1(k);
			break;
		case(2):
			return hashFn2(k);
			break;
		case(3):
			return hashFn3(k);
			break;
		default:
			return -1;
	}
	//This method simply uses whichHashFn to determine which hashing function to call with the key.
	// it then returns that index
}

int hashMap::dealWithCollisions(string k, int i) {
	/* this method is really short and straightforward.  It determines which collision function to
	 * call based on the whichCOllisionFn field in hashMap, then calls that collision function, and
	 * returns the index that collision function returned.  That's it.
	 * for test 1 it will call CollFn1 (the one I gave you)
	 */
	switch (whichCollisionFn) {
		case(1):
			return collFn1(k,i);
			break;
		case(2):
			return collFn2(k,i);
			break;
		case(3):
			return collFn3(k,i);
			break;
		default:
			return -1;
	}
}

int hashMap::collFn1(string k, int i) {
	// My ridiculously simple collision function that uses linear probing.
	// PLEASE write something better than this for collFn2 and collFn3...

	int ct = 0;
	while (ct < mapSize) {
		i = (i + 1)%mapSize;
		if (map[i] == NULL || map[i]->key == k) {
			collisionsCt += ct;
			return i;
		}
		ct ++;
	}
	if (ct == mapSize) {cout <<"ERROR" << endl; return -1;}
	return i;
}
/*Quadratic Probing*/
int hashMap::collFn2(string k,  int i) {
	int ct = 0;
	while (ct < mapSize) {
		i = (pow(i,2))%mapSize;
		if (map[i] == NULL || map[i]->key == k) {
			collisionsCt += ct;
			return i;
		}
		ct ++;
	}
	if (ct == mapSize) {cout <<"ERROR" << endl; return -1;}
	return i;
}
/*Double Hash (because it's cool)*/
int hashMap::collFn3(string k, int i) {
	int ct = 1;
	while (ct < mapSize) {
		i = (getIndex(k)  + ( ct * ((int)pow(k[0],3) + 1)) )% mapSize;
		if (map[i] == NULL || map[i]->key == k) {
			collisionsCt += ct -1;
			return i;
		}
		ct ++;
	}
	if (ct == mapSize) {cout <<"ERROR" << endl; return -1;}
	return i;
}


void hashMap::insertNewKeyandValue(string k, string v, int ind) {
	map[ind] = new hNode(k,v);
	keysCt++;
	ckIfNeedToRehash();
	//This is a short method that adds the new key and value to the map by creating a new Node,
	// then inserting at the index ind sent in as a parameter
	//
	// It increases the number of keys in the map (aka keysCt)
	//
	// and then it calls ckIfNeedToRehash()
}

/*Yarrington Default*/
int hashMap::hashFn1(string k) {
	// ridiculously simple hash fn that just converts each char to an int, adds the char's ints,
	// mods by the map size, and returns the index found.
	// Again, when you write yours, please do better!!!
	int h_index = 0;
	int len = k.length();
	for (int i = 0; i < len; i++) {
		h_index = h_index + (int)k[i];
	}
	cout << "hash index " << (h_index%mapSize) << endl;
	return h_index%mapSize;
}
/*Hash Function 2
 * Key: sum of the sequence of values squared from 0 to ascii value for each character in k
 * and then of course, mod by mapSize
 */
int hashMap::hashFn2(string k) {
	int h_index = 0;
	int len = k.length();
	for (int i = 0; i < len; i++) {
		int charL = (int)k[i];
		while (charL > 0) {
			h_index += ((int)pow(charL,2)%mapSize);
			charL--;
		}
	}
	cout << "hash index " << (h_index%mapSize) << endl;
	return h_index%mapSize;
}
/*Hash function 3*/
int hashMap::hashFn3(string k) {
	int h_index = 0;
	for (int i = k.length()-1; i >= 0; i--) {
		h_index += pow(i,2)* (((int)k[i])/2);
	}
	cout << "hash index " << (h_index%mapSize) << endl;
	return h_index%mapSize;
}

void hashMap::ckIfNeedToRehash() {
	int percentFull = (keysCt*100) / (mapSize*100)
	if (percentFull >= 70) {
		reHash();
	}
	// this is the function that checks to see if the map is 70% full or more.  If it's over 70%
	// full, it should call the rehash function.
	// BIG Mistake I see a lot: dividing an int by an int to see if it's .7 or greater.
	// int/int results in a floored int.  so 7/10 will be 0, not .7

}

int hashMap::getClosestPrime() {
	int newSize = mapSize*2;
	for ( int i = 0; i < primeSize; i++) {
		if (newSize <= primes[i]) {
			return primes[i];
		}
	}
	return -1;
	// function that determines the new map Size.  It doubles the current mapSize, and then finds
	// the closest prime to that doubled number.  It then returns that prime number
}

int hashMap::findKeyIndex(string k) {
	// this method is used by the writeFile method.  It takes as input a word (the key)
	// and, using the appropriate hashing function (and, if necessary, the appropriate
	// collision function) returns the index of where the key is located in the
	// map.
	int index = getIndex(k);
	if (map[index]->key = k) {
		return index;
	} else {
		return dealWithCollisions(k,index);
	}
	// PLEASE NOTE:  the entire point of hashmaps is to be able to FIND quickly!!!
	// IF you start at index 0 of the map and loop through every value looking for k,
	// you will lose 50% of your grade on this project because that is the exact opposite
	// of the point of a hashmap.
}
void hashMap::reHash() {
	// This is a challenging method.
	int oldMapSize = mapSize;
	mapSize = getClosestPrime();
	hNode** newMap = new hNode*[mapSize];
	for (int i = 0; i < mapSize; i++) {
		newMap[i] = nullptr;
	}
	for (int i = 0; i < oldMapSize; i++) {
		newMap[getIndex[map[i]->key]] =  map[i];
	}
	map = newMap;
	// you're doubling the hashmap size and then taking the size up to the nearest prime.
	// to do that, you need to create a new map on the heap, and initialize all the nodes
	// in the map to NULL (make sure you don't lose track of the old map!)
	// Once done, you'll need to find where to insert each of the nodes from the old map
	// into your newly created map.  You can use the function(s) you've already written
	// for this.
}
hashMap::~hashMap() {
	for (int i = 0; i < mapSize; i++) {
		delete [] map[i];
	}

}

void hashMap::printMap() {
	cout << "In printMap(): Included for testing purposes!!! MapSize: " << mapSize << ", KeysCt: " <<keysCt <<endl;
	for (int i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL) {
			cout << map[i]->key << " ("<< i << "): ";
			for (int j = 0; j < map[i]->valuesCt;j++) {
				cout << map[i]->valueArr[j] << ", ";
			}
			cout << endl;
		}
	}
}
