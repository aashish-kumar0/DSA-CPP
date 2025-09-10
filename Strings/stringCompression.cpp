#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
        if (chars.size() == 0 || chars.size() == 1)
            return chars.size();
        string ans = "";
        int l = 0;
        int r = 0;
        while (l < chars.size()) {
            int len = 0;
            while (r  < chars.size() && chars[l] == chars[r] ) {
                len = r - l + 1;
                r++;
            }
            ans.push_back(chars[l]);

            if (len > 1) {
                string temp = to_string(len);
                for (int i = 0; i < temp.size(); i++) {
                    ans.push_back(temp[i]);
                }
            }
            l = r;
        }
        for (int i = 0; i < ans.size(); ++i) {
            chars[i] = ans[i];
        }
        return ans.size();
    }

int main(){
return 0;
}