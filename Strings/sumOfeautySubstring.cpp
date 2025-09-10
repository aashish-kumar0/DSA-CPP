#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int beautySum(string s) {
        if (s.size() <= 1) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> arr(26, 0);
            for (int j = i; j < s.size(); j++) {
                arr[s[j] - 'a']++;
                int maxf = 0;
                int minf = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (arr[k] > 0) {
                        maxf = max(maxf, arr[k]);
                        minf = min(minf, arr[k]);
                    }
                }
                ans += maxf- minf;
            }
        }
        return ans;
    }

int main(){
return 0;
}