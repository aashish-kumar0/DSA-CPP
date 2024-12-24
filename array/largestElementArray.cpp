#include <iostream>
using namespace std;
void largestInArray(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << largest << endl;
}
void secondLargestInArray(int arr[], int n)
{
    // BRUTE SOLUTION>>>>>>>>ARRAY MUST BE SORTED>>>>>>>>>>>>>>>>>>>>>>>>
    int largest = arr[n - 1];
    for (int i = n - 2; i >= 1; i--)
    {
        if (arr[i] < largest)
        {
            int secondLrg = arr[i];
            cout << secondLrg;
            break;
        }
    }
}
void second_largest(int arr[], int n)
{
    // better Solution>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    int scndLrgst = -1;
    for (int i = 0; i < n; i++)
    {
        if (scndLrgst < arr[i] && arr[i] != largest)
        {
            scndLrgst = arr[i];
        }
    }
    cout << scndLrgst << endl;
}
// OPTIMAL SOLUTION>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int secondLargest(int arr[],int n){
    int Largest=arr[0];
    int second_largest=-1;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>Largest){
            second_largest=Largest;
            Largest=arr[i];
        }
        else if(arr[i]< Largest && arr[i]>second_largest){
            second_largest=arr[i];
        }
    }
    return second_largest;
}
// <<<<<<<<<<OPTIMAL SOLN FOR SECOND SMALLEST ELEMENT IN AN ARRAY>>>>>>>>>>>>>>>>>>>>>>
int second_Smallest(int arr[],int n){
    int n=sizeof(arr)/sizeof(arr[0]);
    int Smallest=arr[0];
    int second_Smallest= INT16_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]< Smallest){
            second_Smallest=Smallest;
            Smallest=arr[i];
        }
        else if(arr[i]!=Smallest && arr[i]<second_Smallest){
            second_Smallest=arr[i];
        }
    }
    return second_Smallest;


}
int main()
{
    int arr[] = {1, 2, 4, 7, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    largestInArray(arr, n);
    second_largest(arr, n);
    return 0;
}