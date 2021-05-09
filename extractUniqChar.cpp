/*
Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain 
each character only once. The respective order of characters should remain same, as in the input string.
*/


#include <unordered_map>
#include <string>

string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);
 
    return s;  
}
 

string uniqueChar(string str) {
	// Write your code here
    unordered_map<char, int> mymap;
    
    string res = getString(str[0]);
    mymap[str[0]] = 1;
    
    for(int i = 1; i < str.length(); i++)
    {
        if(mymap[str[i]])
            continue;
        else
        {
            mymap[str[i]] = 1;
            res += str[i];
        }
    }
    
    return res;
    
}
