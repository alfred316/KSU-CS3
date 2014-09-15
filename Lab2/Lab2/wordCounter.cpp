//
//  main.cpp
//  Lab2
//
//  Created by Alfred Shaker on 9/10/14.
//  Copyright (c) 2014 Alfred Shaker. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "wordCounter.h"

using std::cout;
using std::string;
using std::getline;
using std::endl;

int main(int argc,const char * argv[])
{

    // insert code here...

    //open file
    
    std::ifstream inputFile;
    inputFile.open(argv[1]);
    
    
    if(!inputFile.is_open())
    {
        cout << argv[1] << " was not open" << endl;
        return 1;
    }
    
    if (inputFile.is_open()) {
        
        cout << argv[1] << " is open!" << endl;
    }
    //declare the strings to use
    string  inputString;
    string buffer;
    
    //declare object needed
    WordList nameList;
    
    //get the stuff from the file
    getline(inputFile, inputString);
    //cout << "done reading in" << endl;
    
    //loop to check for the code being at the end of the file
    while (!inputFile.eof()) {

        //cout << "in the while loop " << end;
        //loops over the whole input string
        for(int i = 0; i < inputString.length(); ++i)
        {
            //checks for letters and characters
            for (int k = i; isalpha(inputString[k]) && inputString[k] != ','; ++k, ++i)
            {
                buffer += inputString[k];
            }
            
            //adds words
            //cout << " adding words " << endl;
            nameList.addWord(buffer);
            buffer.clear();
        }
        
        getline (inputFile, inputString);
    }
    
    //cout<<"out of while loop" << endl;
    
    //sorts the words in decending order
    buffer.clear();
    //cout << "sorting stuff " << endl;
    nameList.wordSort();
    //cout << "done sorting stuff " << endl;
    inputFile.close();
    //cout << "file closed " << endl;
    
    return 0;
}

