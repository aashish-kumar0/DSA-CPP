#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0]; // Start with the first element
        int sum = nums[0];  // Start sum with the first element

        for(int i = 1; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]); // Either start a new subarray or continue
            maxi = max(maxi, sum); // Update the maximum sum found
        }

        return maxi;
    }
int main(){
vector <int> arr={-2,-3,4,-1,-2,1,5,-3};
int a=maxSubArray(arr);
cout<<a;
return 0;
}
