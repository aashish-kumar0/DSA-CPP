#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& cardPoints, int k) {
        int len= cardPoints.size();
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++){
            lsum=lsum + cardPoints[i];
        }
        int maxSum=lsum;
        int rindex=len-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum - cardPoints[i];
            rsum=rsum + cardPoints[rindex];
            rindex--;
            maxSum=max(maxSum,lsum + rsum);
        }
        return maxSum;
    }
int main(){
return 0;
}