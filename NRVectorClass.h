// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 3
// Program Name: NRVector
// Last Modification Date: 20/12/2022
// Author1 and ID and Group: Rawan Hesham Hamdy  ID: 20211040
// Author2 and ID and Group: Nourhan Mahmoud Eldesoky  ID: 20211107
/*
description: we developed our own version of vector in c++, and create it's main functions.
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

using namespace std;


template <class T>
class NRVector {
private:
    T* vec;
    int sz;
    int capcity;
public:
    // Default Constructor:
    NRVector(): capcity(0), sz(0){}

    // Parameterized Constructor taking capacity:
    NRVector(int c = 0): capcity(c), sz(0){
        vec = new T[capcity];
    }
};
