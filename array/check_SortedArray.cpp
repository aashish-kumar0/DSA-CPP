#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Array can be a rotated array by k place
bool check(vector<int> &arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] > arr[i+1]% arr.size()){
            count++;
        }
    }
    return count<=1;
}
int main(){
    vector<int>arr={3,4,5,1,2};
    check(arr);
return 0;
}