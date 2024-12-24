#include<iostream>
using namespace std;
int removeDuplicate(int arr[],int n){
    int i=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){

    return 0;
}