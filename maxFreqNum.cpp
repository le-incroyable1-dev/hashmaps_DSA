/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number 
which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
*/

#include <unordered_map>
#include <string>
#include <climits>

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map <int , int> mymap;
    
    for(int i = 0; i < n; i++)
    {
        if(mymap.count(arr[i]) > 0)
            mymap[arr[i]]++;
        else
        {
            pair <int, int> p(arr[i], 1);
            mymap.insert(p);
        }
    }
    
    
    int max = arr[0];
    
    for(int i = 0; i < n; i++)
    {
        if(mymap[arr[i]] > mymap[max])
            max = arr[i];
    }

    return max;
    
}
