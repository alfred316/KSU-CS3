//
//  main.cpp
//  Lab1Cipher
//
//  Created by Alfred Shaker on 9/2/14.
//  Copyright (c) 2014 Alfred Shaker. All rights reserved.
//

#include <iostream>
#include <string> 
#include <fstream>


using std::cout;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

char encrypt(char, int, int);

int main(int argc, const char * argv[])
{
    ifstream srcfile;
    ofstream tgtfile;
    
    //open file
    srcfile.open(argv[2]);
    tgtfile.open(argv[3]);
    
    
    //get the key for encryption
    int key = atoi(argv[1])%26;
    
    //puts the characters in a variable
    char x = srcfile.get();
    char y;
    
    //loop that runs throughout the file
    while (!srcfile.eof()) {
        //checks if character is an alphabet
        if(isalpha(x))
        {
            //checks if its upper or lower case
            if (isupper(x)) {
                y = encrypt(x,65, key);
                tgtfile.put(y);
            }
            
            if (islower(x)) {
                y = encrypt(x, 97, key);
                tgtfile.put(y);
            }
        }
        
        //if it's a number, do nothing to it and transfer it
        else tgtfile.put(x);
        x = srcfile.get();
    }
    
    srcfile.close();
    tgtfile.close();
    
    return 0;
}

//the function that does the cipher encryption
//it works both ways depending on the key
char encrypt(char ch, int firstCh, int key)
{
    int rem = 0;
    int lastCh = firstCh + 25;
    int chJumps = ch + key;
    
    //checks if it's going to move it beyond z or Z
    if (chJumps > lastCh) {
        rem = chJumps - lastCh;
        ch = firstCh + rem;
    }
    //or if it's negative
    else if (chJumps < firstCh) {
        rem = firstCh - chJumps;
        ch = chJumps - rem;
    }
    else
        ch = chJumps;
    
    
    return ch;
}

