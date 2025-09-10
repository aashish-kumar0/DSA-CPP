#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};
// brute approach
vector<pair<int, int>> findPairsWithGivenSumBrute(Node *head, int target)
{
    // code here
    Node *temp = head;
    vector<pair<int, int>> ans;
    while (temp != NULL)
    {
        Node *front = temp->next;
        while (front != NULL)
        {
            if (temp->data + front->data == target)
            {
                ans.push_back({temp->data, front->data});
                front = front->next;
            }
            else if (temp->data + front->data > target)
            {
                break;
            }
            else
            {
                front = front->next;
            }
        }
        temp = temp->next;
    }
    return ans;
}
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here
    Node *left = head;
    Node *right = head;
    vector<pair<int, int>> ans;
    if (head == NULL || head->next == NULL)
    {
        return ans;
    }
    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left->data < right->data)
    {
        if (left->data + right->data == target)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        if (left->data + right->data > target)
        {
            right = right->prev;
        }
        if (left->data + right->data < target)
        {
            left = left->next;
        }
    }
    return ans;
}
int main()
{
    return 0;
}