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

    // [] Access Operator:
    T& operator[](int index){
        if(index < 0 || index >= sz){
            throw out_of_range("Vector Index Out Of Bound");
        }
        return vec[index];
    }

    int push_back(T element){
        if(sz < capcity){
            vec[sz++] = element;
        }
        else{
            T* newVec = new T[capcity * 2];
            capcity *= 2;
            for (int i = 0; i < sz; ++i) {
                newVec[i] = vec[i];
            }
            delete[] vec;
            vec = newVec;
            newVec = nullptr;
            vec[sz++] = element;
        }
        return sz;
    }

    using iterator = T*;

    iterator begin(){
        return vec;
    }

    iterator end(){
        return vec + sz;
    }

    void erase(iterator it){
        bool flag = false;
        for (int i = 0; i < sz; ++i) {
            if(*(it) == vec[i]){
                flag = true;
                continue;
            }
            if(flag){
                vec[i-1] = vec[i];
            }
            else{
                vec[i] = vec[i];
            }
        }
        sz--;
    }

    void insert(iterator it, T element){
        T* newVec = new T[capcity];
        if((sz+1) > capcity){
            cout << "Sorry, the vector is full.\n";
        }
        else{
            sz++;
            int j = 0;
            for (int i = 0; i < sz; ++i) {
                if(it == &vec[j]){
                    newVec[i] = element;
                    j++;
                }
                else {
                    if(j == 0){
                        newVec[i] = vec[j];
                        j++;
                    }else {
                        newVec[i] = vec[j - 1];
                        j++;
                    }
                }
            }
            vec = newVec;
            newVec = nullptr;
        }
    }

    // Comparison operations:
    //overloading the operator==
    //Return true if all elements in both vectors are equal
    bool operator==(const NRVector<T>& other){
        if(sz == other.sz){
            for(int i = 0; i < sz; i++){
                if(vec[i] != other.vec[i]){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }

};
