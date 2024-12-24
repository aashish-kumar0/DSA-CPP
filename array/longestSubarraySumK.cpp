#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// brute solution?>>>>>>>>>>>>>>>>>>>>>>>>>>T.C.=O(n^3)>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int largestSubarray(int arr[], int num,int size)
{
    int n = size;
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            for (int l = i; l < j; l++)
            {
                sum += arr[j];
                if (sum == num)
                {
                    length = max(length, j - i + 1);
                }
            }
        }
    }
    return length;
}
int main()
{
    int ar[]={1,2,3,1,1,1,1,4,2,3};
     int size=sizeof(ar)/sizeof(ar[0]);
    int num=3;
    int a=largestSubarray(ar,num,size);
    cout<<a;
    return 0;
}