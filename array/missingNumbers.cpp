#include <iostream>
using namespace std;
// Better soln>>>>>>>>>>>>>>>>>>>>>>>>>

// BRUTE APPROACH>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int misNumber(int arr[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
}
// Better approach using hashing>>>>>>>>>>>>>>>>>>>>>>>>>>>
int missNumber(int arr[], int N)
{
    int hash[N + 1] = {0};
    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= 1 && arr[i] <= N)
        {
            hash[arr[i]]++;
        }
    }
    for (int i = 1; i < N + 1; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}
// Optimal solution using SUM>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int missingNumber(int arr[], int N)
{
    int sum = (N * (N + 1)) / 2;
    int s2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        s2 += arr[i];
    }
    int ans = sum - s2;
    return ans;
}
// Optimal solution using XOR^  >>>>>>>>>>>>>>>>>>>>>>>>>>
int missingNumberXOR(int arr[], int N)
{
    int XOR1 = 0;
    int XOR2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        XOR2 = XOR2 ^ arr[i];
        XOR1 = XOR1 ^ (i + 1);
    }
    return XOR1 ^ XOR2;
}
int main()
{
    int N = 5;
    int a[] = {1, 2, 4, 5};
    int b = missingNumberXOR(a, N);
    cout << b;
    return 0;
}