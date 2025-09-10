#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
*/
string reverseOnlyLetters(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (((s[l] >= 'A' && s[l] <= 'Z') ||
                 (s[l] >= 'a' && s[l] <= 'z')) &&
                ((s[r] >= 'A' && s[r] <= 'Z') ||
                 (s[r] >= 'a' && s[r] <= 'z'))) {
                    swap(s[l],s[r]);
                    l++;
                    r--;
            }
            if(!isalpha(s[l])){
                l++;
            }
            if(!isalpha(s[r])){
                r--;
            }
        }
        return s;
    }

int main(){
return 0;
}