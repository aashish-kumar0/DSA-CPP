#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(int i=0; i< timePoints.size(); i++){
            string time=timePoints[i];
            int hr=stoi(time.substr(0,2));
            int mn=stoi(time.substr(3,2));
            int total= (hr*60) + mn;
            minutes.push_back(total);
        }
        sort(minutes.begin(),minutes.end());
        int minT=INT_MAX;
        for(int i=1;i<minutes.size();i++){
            int curr=i;
            int prev=i-1;
            minT=min(minT,abs(minutes[curr]-minutes[prev]));
        }
        int circDiff= (1440 +minutes[0]) - minutes[minutes.size()-1];
        minT=min(minT,circDiff); 
        return minT;
    }

int main(){
    vector<string>timePoints = {"23:59","00:00"};
    cout<<findMinDifference(timePoints);
return 0;
}