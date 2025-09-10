#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int r = s.size() - 1;

    while (s[r] == ' ')
    {
        r--;
    }
    string ans = "";
    while (r >= 0)
    {
        string temp = "";
        int l = r;
        while (r >= 0 && s[r] != ' ')
        {
            r--;
        }
        temp = s.substr(r + 1, l - (r + 1) + 1);
        ans += temp + " ";
        while (r >= 0 && s[r] == ' ')
        {
            r--;
        }
    }
    if (!ans.empty())
    {
        ans.pop_back(); // Remove trailing space
    }

    return ans;
}

int main()
{
    return 0;
}