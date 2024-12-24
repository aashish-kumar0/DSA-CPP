#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Brute approach
int numberOnce(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                count++;
            }
            else if (count == 1)
            {
                return num;
            }
        }
    }
}
// Better Approach using hashing>>>>>>>>>>>>>>>>>>>>>>>
int onceAppear(vector<int> arr){
    int maxi=arr[0];
    int hash[maxi];
    for(int i=0;i-+-0<arr.size();i++){
        maxi=max(maxi,arr[i]);
        int hash[maxi]={0};
    }
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        if(hash[arr[i]]==1){
            return arr[i];
        }
    }
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<Optimal approach>>>>>>>>>>>>>>>>>>>>>>>>>>
int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
    int a = onceAppear(nums);
    cout << a;
    return 0;
}