#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
int main()
{
    // HASHING FOR INTEGER
    //  int n;
    //  cout<<"Enter n:"<<endl;
    //  cin>>n;
    //  int arr[n];
    //  for(int i=0;i<n;i++){
    //  cout<<"Enter "<<i<<"element :"<<endl;
    //      cin>>arr[i];
    //  }
    //  int hash[13]={0};
    //  for(int i=0;i<n;i++){
    //      hash[arr[i]]+=1;
    //  }
    //  int q;
    //  while(q--){
    //      int number;
    //      cout<<"Enter number"<<endl;
    //      cin>>number;
    //      cout<<"Number of times "<<number<<" is present in the array is :"<<hash[number]<<endl;
    //  }

    // Hashing for Character
    //  string s;
    //  cout<<"Enter a string:"<<endl;
    //  cin>>s;
    //  int hash[26]={0};
    //  for(int i=0; i<s.size();i++){
    //       hash[s[i]-'a']=hash[s[i]-'a']+1;
    //  }

    // int q;
    // cout<<"Enter q:"<<endl;
    // cin>>q;
    // while(q--){
    //     char c;
    // cout<<"Enter a character:"<<endl;
    //    cin>>c;
    //    cout<<"No of times "<<c<<" is present is "<<hash[c-'a']<<endl;

    // }

    //<<<<<<<<<<<<<<<<<<<<<HASHING FOR MAPS OF INTEGER>>>>>>>>>>>>>>>>>>
    // int n;
    // cout << "Enter n:" << endl;
    // cin>>n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter " << i << " element:" << endl;
    //     cin >> arr[i];
    // }
    // int q;
    // cout << "Enter q:" << endl;
    // cin >> q;
    // // pre compute
    // map<int, int> mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     mpp[arr[i]] = mpp[arr[i]] + 1;
    // }
    // while (q--)
    // {
    //     int number;
    //     cout << "Enter number:" << endl;
    //     cin >> number;
    //     cout << "Number of times " << number << " is present is" << mpp[number] << endl;
    // }

    // <<<<<<<<<<<<<<<<<<<<<HASHING FOR STRINGS USING MAPS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int n;
    cout<<"ENter n:"<<endl;
    cin>>n;
    string s;
    cout<<"Enter a string:"<<endl;
    cin>>s;
    int q;
    cout<<"Enter q:"<<endl;
    cin>>q;
    map<char,int>mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]=mpp[s[i]]+1;
    }
    while(q--){
        char c;
        cout<<"Enter a character:"<<endl;
        cin>>c;
        cout<<"Character "<<c<<"  is present "<<mpp[c]<<" times in string"<<endl;
    }
    return 0;
}