#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>zigzag(numRows);
        int i=0;
        int row=0;
        bool direction=1;

        while(true){
            if(direction){
                while(row < numRows && i< s.size()){
                    zigzag[row++].push_back(s[i++]);
                }
                row=numRows-2;
            }
            else{
                while(row >= 0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row=1;
            }
            if(i >= s.size())break;
            direction= !direction;
        }
        string ans="";
        for(int j=0;j<zigzag.size();j++){
            ans += zigzag[j];
        }
        return ans;
    }

int main(){
return 0;
}