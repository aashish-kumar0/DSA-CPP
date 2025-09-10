#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{
    int pos = s.find(part);
    while (pos != string::npos)
    {
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

// optimal code
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string ans = "";
        int i = 0;
        int j;
        int m = part.size();
        while (i < s.size())
        {
            ans.push_back(s[i]);
            j = ans.size() - 1;
            if (ans.size() >= m)
            {
                if (ans.substr(ans.size() - m, m) == part)
                {
                    ans.erase(ans.size() - m, m);
                }
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}