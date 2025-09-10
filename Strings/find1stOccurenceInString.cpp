#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int strStr(string haystack, string needle) {
        int h=haystack.size();
        int n=needle.size();
        for(int i=0;i<= h-n;i++){
            int j=0;
            while(j < n && haystack[i+j]==needle[j]){
                j++;
            }
            if(n==j){
                return i;
            }
        }
        return -1;
    }

int main(){
return 0;
}