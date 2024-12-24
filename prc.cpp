#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int secondLargest(int arr[],int n){
    int Largest= arr[0];
    int sLargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>Largest ){
            sLargest=Largest;
            Largest=arr[i];
        }
        else if(arr[i]<Largest && arr[i]>sLargest){
            sLargest=arr[i];
        }
    }
    return sLargest;
}
int secondSmallest(int arr[],int n){
    int Smallest= arr[0];
    int secSmallest;
    for(int i=1;i<n;i++){
        if(Smallest<arr[i]){
            secSmallest=Smallest;
            Smallest= arr[i];
        }
        else if(arr[i]!=Smallest && arr[i]< secSmallest){
            secSmallest=arr[i];
        }
    }
    return secSmallest;
}
int main(){
    int arr[6]={5,9,6,11,7,15};
    int n= sizeof(arr)/sizeof(arr[0]);
    int secondlargest=secondLargest(arr,n);
    cout<<secondlargest<<endl;
    int secSmallest=secondSmallest(arr,n);
    cout<<secSmallest;
    

    return 0;
}