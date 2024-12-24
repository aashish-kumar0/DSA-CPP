#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Dutch National Flag Algorithm>>>>>>>>>>>>>>>>>>>>
void sortArray(vector<int> &arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[mid] == 0)
        {
            Swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid == 2])
        {
            Swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    // vector<int> arr={}
    return 0;
}