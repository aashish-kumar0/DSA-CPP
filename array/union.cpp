#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// <<<<<<<<<<BRUTE APPROACH>>>>>>>>>>>>>>>>>>>>
vector<int> unionArray(int arr1[], int arr2[])
{
    int n1;
    int n2;
    set<int> st;
    for (int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
        ;
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(arr2[i]);
    }
    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
    }
    return temp;
}
// OPTIMAL SOLUTION?>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
vector<int> unionSortedArray(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }

            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
         if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
    }
    while(j<n2){
                    if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;

    }
    return unionArr;
}
    int main(){
        vector <int> v1 = {1, 1, 2, 3, 4, 5};
        vector <int> v2 = {2, 3, 4, 4, 5, 6};
        int n1 = v1.size();
        int n2 = v2.size();
        vector<int> op = unionSortedArray(v1,v2);
        for (int i = 0; i < 6; i++)
        {
            cout << op[i] << " ";
        }

        return 0;
    }