// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 3
// Program Name: NRVector
// Last Modification Date: 20/12/2022
// Author1 and ID and Group: Rawan Hesham Hamdy  ID: 20211040
// Author2 and ID and Group: Nourhan Mahmoud Eldesoky  ID: 20211107
/*
description: we developed our own version of vector in c++, and create it's main functions.
 */


#include <iostream>
#include <exception>
#include "NRVectorClass.h"

using namespace std;


int main(){
    int* arr1 = new int[3] {1, 2, 3};
    int* arr2 = new int[5] {4, 5, 6, 7, 8};
    int* arr3 = new int[3] {1, 2, 3};

    NRVector<int> vec1(arr1, 3);
    NRVector<int> vec2(arr2, 5);
    NRVector<int> vec3(arr3, 3);

    cout << "vec1 = " << vec1 << endl;
    cout << "vec2 = " << vec2 << endl;
    vec1 = vec2;
    cout << "After making vec1 = vec2\n";
    cout << "vec1 = " << vec1 << endl;
    cout << "vec2 = " << vec2 << endl;

    cout << "Size vec1 before pushing: "<< vec1.size() << endl;
    cout << "Capacity vec1 before pushing: "<< vec1.capacity() << endl;
    vec1.push_back(10);
    vec1.push_back(16);
    cout << "After pushing 10 and 16 to vec1\n";
    cout << "Size vec1 after pushing: "<< vec1.size() << endl;
    cout << "Capacity vec1 after pushing: "<< vec1.capacity() << endl;
    cout << "vec1 = " << vec1 << endl;

    vec1.push_back(17);
    vec1.push_back(18);
    vec1.push_back(19);
    cout << "After pushing 17 and 18 and 19 to vec1\n";
    cout << "Size vec1 after pushing: "<< vec1.size() << endl;
    cout << "Capacity vec1 after pushing: "<< vec1.capacity() << endl;
    cout << "vec1 = " << vec1 << endl;

    vec1.push_back(20);
    cout << "After pushing 20 to vec1\n";
    cout << "Size vec1 after pushing: "<< vec1.size() << endl;
    cout << "Capacity vec1 after pushing: "<< vec1.capacity() << endl;
    cout << "vec1 = " << vec1 << endl;

    vec1.pop_back();
    cout << "After pop from vec1\n";
    cout << "vec1 = " << vec1 << endl;

    cout << "Size vec1: "<< vec1.size() << endl;
    cout << "Capacity vec1: "<< vec1.capacity() << endl;

    int* arr4 = new int[4] {1, 2, 3, 5};
    int* arr5 = new int[3] {1, 2, 3};
    NRVector<int> vec4(arr4, 4);
    NRVector<int> vec5(arr5, 3);
    cout << "vec4 = " << vec4 << endl;
    cout << "vec5 = " << vec5 << endl;

    cout << "Comparison between vec4 and vec5\n";
    if (vec4 == vec5){
        cout << "Equal" << endl;
    }
    else{
        cout << "Not Equal" << endl;
        if (vec4 < vec5){
            cout << "vec4 < vec5" << endl;
        }
        else{
            cout << "vec4 > vec5" << endl;
        }
    }

    int* begin = vec4.begin()+1;
    vec4.erase(begin);
    cout << "After erase the element at index 1 in vec4\n";
    cout << "vec4 = " << vec4 << endl;

    int* begin1 = vec5.begin()+1;
    vec5.insert(begin1, 4);
    cout << "After insert '4' at index 1 in vec5\n";
    cout << "vec5 = " << vec5 << endl;

    int* begin2 = vec5.begin()+1;
    int* end2 = vec5.begin()+3;
    vec5.erase(begin2, end2);
    cout << "After erase element from index 1 to index 3 in vec5\n";
    cout << "vec5 = " << vec5 << endl;

    vec1.clear();
    cout << "After clear vec1\n";
    cout << "vec1 = " << vec1 << endl;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
}
