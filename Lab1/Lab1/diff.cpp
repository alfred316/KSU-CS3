//
//  main.cpp
//  Lab1
//
//  Created by Alfred Shaker on 8/27/14.
//  Copyright (c) 2014 Alfred Shaker. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::string;

int main(int argc, const char * argv[])
{
    //P.S: disregard the commented out couts, those are for debugging
    
    //open files at the start

    std::ifstream myFile1;
    std::ifstream myFile2;
    
    myFile1.open(argv[1]);
    myFile2.open(argv[2]);
    
    //cout << "This is file 1" << endl;
    
    //2 while loops to check how many lines in each file
    
    int i = 0;
    string x;
    
    while (!myFile1.eof()) {
        getline (myFile1, x);
        i++;
        //cout << x << endl << i << endl;
    }
    //cout << "This is file 2" << endl;
    
    int j = 0;
    string y;
    
    while (!myFile2.eof()) {
        getline (myFile2, y);
        j++;
        //cout << y << endl << j << endl;
    }
    
    //check which one has more lines and put it in bigger
    
    int bigger = 0;
    
    if (i > j){
       // cout << "File 1 is bigger than file 2" << endl;
        bigger = i;
    }
    else if (j > i){
       // cout << "File 2 is bigger than file 1" << endl;
        bigger = j;
    }
    else{
       // cout << "They are the same size" << endl;
        bigger = i;
       // cout << bigger << endl;
    }
    
    //close files and open them again to reset
    //while loop to go through and check different values until its at the end of the bigger file
    
    int q = 1;
    //cout << "stuff "<<bigger << endl;
    
    myFile1.close();
    myFile2.close();
    
    myFile1.open(argv[1]);
    myFile2.open(argv[2]);
    
   
    //cout << "entering while loop " << endl;
    
    while (q <= bigger) {
        //cout << "in the while loop" << endl;
        string file1;
        string file2;
        
        getline (myFile1, file1);
        getline (myFile2, file2);
        
//        cout << file1 << endl;
//        cout << file2 << endl;
        
        if (file1 == file2)
        {
            ++q;
            continue;
        }
        else
        {
            cout << argv[1] << ": " << q << ": " << file1 << endl;
            cout << argv[2] << ": " << q << ": " << file2 << endl;
            ++q;
        }
        
    
    }
    
    
    
    
    
    
    
    
    return 0;
}

