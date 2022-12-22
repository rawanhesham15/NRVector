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

    //copy constructor :Initialize with a copy:
    NRVector (const NRVector& v){
        capcity = v.capcity;
        sz = v.sz;
        vec = new T[capcity];
        for(int i = 0; i < sz; i++){
            vec[i] = v.vec[i];
        }
    }

    // Delete allocated memory:
    ~NRVector(){
        delete[] vec;
    }

    // Copy Assignment Operator:
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

    // Move Assignment Operator:
    NRVector &operator= (const NRVector&& v){
        if(this != &v) {
            capcity = 0;
            sz = 0;
            delete this->vec;
            capcity = v.capcity;
            sz = v.size;
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

    // Push elements in Vector:
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

    // Remove and return last element in vec :
    T pop_back(){
        if(sz == 0){
            throw out_of_range("Vector Is Empty");
        }
        sz--;
        return vec[sz];
    }

    // Iterators //Supports *, + and ++ operations at least // Can use: typedef T* iterator // Or u can use std::iterator so you can
    // apply STL algorithms on NRVector
    //iterator begin() // Return an iterator (T*)
    //iterator end() // Return an iterator (T*)
    using iterator = T*;

    iterator begin(){
        return vec;
    }

    iterator end(){
        return vec + sz;
    }

    // Remove items between iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range
    void erase(iterator it1, iterator it2){
        if(it1 < vec || it1 > vec + sz || it2 < vec || it2 > vec + sz){
            throw out_of_range("Iterator Out Of Range");
        }
        if(it1 > it2){
            throw out_of_range("Iterator 1 Must Be Less Than Iterator 2");
        }
        int index1 = it1 - vec;
        int index2 = it2 - vec;
        int diff = index2 - index1;
        for(int i = index1; i < sz - diff; i++){
            vec[i] = vec[i + diff];
        }
        sz -= diff;
    }
    //void erase(iterator it1, iterator it2){
    //        if(it1 < vec || it1 > vec + sz || it2 < vec || it2 > vec + sz){
    //            throw out_of_range("Iterator Out Of Range");
    //        }
    //        if(it1 > it2){
    //            throw out_of_range("Iterator 1 Must Be Less Than Iterator 2");
    //        }
    //        int diff = it2 - it1;
    //        T* newVec = new T[capcity];
    //        int j = 0;
    //        for(int i = 0; i < sz; i++){
    //            if(vec + i < it1 || vec + i >= it2){
    //                newVec[j++] = vec[i];
    //            }
    //        }
    //        delete[] vec;
    //        vec = newVec;
    //        newVec = nullptr;
    //        sz -= diff;
    //    }

    // Erase one element of the vector.
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

    // Insert element in the vector.
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


    //Delete all vector content
    void clear(){
        sz = 0;
        T* newVec = new T[capcity];
        vec = newVec;
        newVec = nullptr;
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

    // Overloading the operator<
    // Compares item by item and Return true if the first different item in this is < in other:
    bool operator< (const NRVector<T>& other){
        if(sz < other.sz){
            return true;
        }
        else if(sz > other.size()){
            return false;
        }
        else {
            int minSize = min(sz, other.sz);
            for (int i = 0; i < minSize; i++) {
                if (vec[i] > other.vec[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Capacity operations
    // Return current size of vec:
    int size() const{
        return sz;
    }

    // Return size of current allocated array:
    int capacity() const{
        return capcity;
    }

    // Relocate to bigger space:
    int resize(){
        T* newVec = new T[capcity * 2];
        capcity *= 2;
        for (int i = 0; i < sz; ++i) {
            newVec[i] = vec[i];
        }
        delete[] vec;
        vec = newVec;
        newVec = nullptr;
        return capcity;
    }

    // Return true if size is 0:
    bool empty(){
        if (sz == 0){
            return true;
        }
    }

    // Friends :overloading the operator << :
    friend ostream& operator << (ostream& out, NRVector<T> v){
        for (int i = 0; i < v.sz; ++i) {
            out << v.vec[i] << " ";
        }
        return out;
    }
};
