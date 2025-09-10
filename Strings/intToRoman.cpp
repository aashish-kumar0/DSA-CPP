#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
        vector<pair<int, string>> list = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
            
            string ans="";

            while(num != 0){
                for(int i=0;i<list.size();i++){
                    int t=list[i].first;
                    string str=list[i].second;
                    if(num >= t){
                        ans=ans + str;
                        num=num-t;
                        break;
                    }
                    
                }
            }
            return ans;
    }

int main(){
return 0;
}