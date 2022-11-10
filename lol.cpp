#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

class Solution {
public:
    int setValue (string a){
        int val;
        if ( a == "I")
        {
            val = 1;
        }
        if (a == "V")
        {
          val = 5;
        }
        if (a == "X")
           val = 10;
        if (a == "L")
            val = 50;
        if (a == "C")
           val = 100;
        if (a == "D")
            val = 500;
        if (a == "M")
            val = 1000;
    }
    bool checkSequence (string c)
    {
        vector <int> b;
        for (int i = 0; i < c.size(); i++)
        {
            b.push_back(setValue(c[i]));
        }
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] > b[i+1])
            {
                return true;
            }
        else
        {
            return false;
        }
          }
    }
    int romanToInt(string s)
    {
      vector <int> b;
        if (checkSequence(s) == true)
        {
            int sumRoman;
            for (int i = 0; i < b.size(); i++)
            {
                sumRoman += b[i];
            }
            return sumRoman;
        }
        else
        {
            int sumRoman2;
            for (int i = b.size()-1; i > 0; i --)
            {
                sumRoman2 = sumRoman2 - b[i];
            }
            return sumRoman2;
        }
    }
};
