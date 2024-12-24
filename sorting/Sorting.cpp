#include<iostream>
#include<array>
using namespace std ;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;

    }
}
void bubbleSort(int arr[],int n){
    //n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++){
            int didSwap=0;
            if(arr[j]>arr[j+1]){
                int temp;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                didSwap=1;
                
            }
            else if(didSwap==0){
                break;
            }
            cout<<"Runs\n";
        }
    }
}
void insertionSort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-i]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
int main(){
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Element at "<<i<<" index is :"<<endl;
        cin>>arr[i];
    }
    // insertionSort(arr,n);
     bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   
    return 0;
}
