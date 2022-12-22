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

    // Parameterized Constructor taking array and size of array:
    NRVector (T* arr, int  n){
        capcity = n*2;
        sz = n;
        vec = new T[n];
        for(int i = 0; i < n; i++){
            vec[i] = arr[i];
        }
    }

    NRVector &operator= (const NRVector& v){
        if(this != &v) {
            capcity = 0;
            sz = 0;
            delete this->vec;
            capcity = v.capcity;
            sz = v.sz;
            vec = new T[capcity];
            for (int i = 0; i < sz; ++i) {
                vec[i] = v.vec[i];
            }
        }
        else{
            cout << "Sorry, Can Not Delete My Self" << endl;
        }
        return *this;
    }
};
