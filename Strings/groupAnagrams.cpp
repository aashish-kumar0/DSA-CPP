#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end()); // sort the string to form the key
        anagramMap[key].push_back(str);
    }

    vector<vector<string>> result;
    for (auto& pair : anagramMap) {
        result.push_back(pair.second);
    }

    return result;
    }

int main(){
return 0;
}