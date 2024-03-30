#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
    bool isAlphabet(char ch)
    {
        return (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A');
    }

    void swap(char* c1, char* c2)
    {
        char tmp = *c1;
        *c1 = *c2;
        *c2 = tmp;
    }

    string reverseOnlyLetters(string s) {
        int begin = 0;
        int end = s.length() - 1;

        while (begin < end)
        {
            while (!isAlphabet(s[begin]) && begin < end)
                begin++;

            while (!isAlphabet(s[end]) && begin < end)
                end--;

            swap(&s[begin], &s[end]);
            begin++;
            end--;
        }

        return s;
    }
};