#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int romanToInt(string s) {
        vector<pair<int, string>> list = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        int num = 0;
        int l = 0;
        int r = 1;
        while (l < s.size() && r < s.size()) {
            int cnt = 0;
            string temp = s.substr(l, r - l + 1);
            for (int j = 0; j < list.size(); j++) {
                int t = list[j].first;
                string str = list[j].second;
                if (temp == str) {
                    num = num + t;
                    l = r + 1;
                    r = l + 1;
                    cnt++;
                    break;
                }
            }
            if (cnt == 0) {
                r--;
            }
        }
        if (l < s.size() && r >= s.size()) {
            string st = s.substr(l, 1);
            for (int i = 0; i < list.size(); i++) {
                int t = list[i].first;
                string str = list[i].second;
                if (st == str) {
                    num += t;
                    break;
                }
            }
        }
        return num;
    }

int main(){
    string s ="MCMXCI";
    cout<<romanToInt(s);
return 0;
}