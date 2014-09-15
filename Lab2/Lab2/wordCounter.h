//
//  wordCounter.h
//  Lab2
//
//  Created by Alfred Shaker on 9/10/14.
//  Copyright (c) 2014 Alfred Shaker. All rights reserved.
//


#ifndef Lab2_wordCounter_h
#define Lab2_wordCounter_h

#include <string>
using std::string;
using std::cout;
using std::endl;

class WordOccurrence {
public:
    WordOccurrence(){word_=" "; num_ = 0;};
    WordOccurrence operator= (WordOccurrence& org){word_ = org.word_;
                                                    num_ = org.num_;
                                                    return *this;};
    bool operator== (WordOccurrence&);
    WordOccurrence(const string& word, int num=0){word_ =  word; num_=1;};
    bool matchWord(const string &); // returns true if word matches stored
    void increment(void){++num_;}; // increments number of occurences
    string getWord(void) const{return word_;};
    int getNum(void) const{return num_;};
    
private:
    string word_;
    int num_;
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList ();
    WordList(const WordList& org);
    WordList operator= (WordList const &org);
    ~WordList(){delete [] wordArray_;};
    void wordSort(); //sort it in decending order
    void addWord(const string &);
    void printList(void);
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
    // may or may not be sorted
    int size_;
};


//WordOccurance function definitions

bool WordOccurrence::operator==(WordOccurrence& org)
{
    if((word_==org.word_) && (num_ == org.num_))
        return true;
    return false;
}

bool WordOccurrence::matchWord(const string &word)
{
    if (word_ == word)
        return true;
    else
        return false;
}

//WordList function definitions

WordList::WordList()
{
    size_ = 0;
    wordArray_ = new WordOccurrence [size_];
}

WordList::WordList (const WordList &org)
{
    size_ = org.size_;
    wordArray_ = new WordOccurrence[size_];
    
    for (int i =0; i <= (size_ - 1); ++i)
        wordArray_[i] = org.wordArray_[i];
}


WordList WordList::operator=(WordList const &org)
{
    WordList tmp(org);
    std::swap(wordArray_, tmp.wordArray_);
    std::swap(size_, tmp.size_);
    return *this;
}



void WordList::addWord(const string &word)
{
    for (int i = 0; i < size_; ++i)
    {
        if(wordArray_[i].matchWord(word))
        {
            wordArray_[i].increment();
            return;
        }
    }
    
    ++size_;
    
    WordOccurrence word2(word);
    WordOccurrence *tmp = new WordOccurrence[size_];
    
    int x = 0;
    while (x < (size_ - 1))
    {
        tmp[x] = wordArray_[x];
        ++x;
    }
    
    tmp[x] = word2;
    
    delete [] wordArray_;
    wordArray_ = new WordOccurrence[size_];
    
    for (int q = 0; q <= (size_ - 1); ++q)
    {
        wordArray_[q] = tmp[q];
    }
    
    delete [] tmp;
    
}

void WordList::printList()
{
    string tmp;
    int tmpNum;
    for (int i = 0; i < size_; ++i)
    {
        tmp =  wordArray_[i].getWord();
        tmpNum = wordArray_[i].getNum();
        cout << "Num: " << tmpNum << " Word: " << tmp << endl;
    }
}

void WordList::wordSort()
{
    WordOccurrence tmp;
    WordList tmpList(*this);
    int biggest = wordArray_[0].getNum();
    for (int i = 1; i < size_; ++i) {
        if (wordArray_[i].getNum()>biggest) {
            biggest = wordArray_[i].getNum();
        }
    }
    
        int count = 0;
        while (count < size_) {
            for (int j = 0; j < size_; ++j)
            {
                if(wordArray_[j].getNum() ==  biggest)
                {
                    tmpList.wordArray_[count] = wordArray_[j];
                    ++count;
                }
            }
            
            --biggest;
        }
    
    
    tmpList.printList();
}






#endif
