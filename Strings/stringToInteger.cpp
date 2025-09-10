#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int myAtoi(string s) {
        int i=0;
        int num=0;
        int sign=1;

            //removing leading space
        while(s[i]==' '){ 
            i++;
        }
            //checking sign
        if(i< s.size() && (s[i]=='+' || s[i]=='-')){ 
            sign= s[i]=='+'? 1 : -1;
            ++i;
        }
        // checking for digit
        while(i < s.size() && isdigit(s[i])){
            if(num > INT_MAX /10 || (num == INT_MAX/10 && s[i]>'7')){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num= num * 10 + (s[i]-'0');
            i++;
        }
        
        return sign * num;
    }


int main(){
return 0;
}