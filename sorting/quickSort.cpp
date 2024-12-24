#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int Partition(vector <int>&arr,int low, int high){
    // int n= sizeof(arr)/sizeof(arr[0]);
    /*low=0;
    high=arr.size()-1;*/
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int t=arr[low];
    arr[low]=arr[j];
    arr[j]=t;
    return j;
}

void quickSort(vector <int> &arr,int low, int high){
    if(low<high){
        int pivotIndex = Partition(arr,low,high); 
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}
   
int main(){
    vector <int> arr={4,6,2,5,7,9,1,3};
    int low=0;
    int high= arr.size()-1;
    /*Partition(arr,low,high);
    quickSort(arr,low,high);*/
    quickSort(arr, low, high);
    for(int i=0; i<=arr.size()-1;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}