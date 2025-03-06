#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode *dummy=new ListNode();
            dummy->next=head;
            ListNode *slow=dummy;
            ListNode *pre=dummy;
            ListNode *cur=dummy->next;
            if(cur->val<x) slow=dummy->next;
            while(cur!=nullptr){
                if(cur->val<x){
                    ListNode *tmp=cur->next;
                    cur->next=slow->next;
                    slow->next=cur;
                    cur=tmp;
                    pre->next=cur;
                }else{
                    pre=cur;
                    cur=cur->next;
                }
            }
            return dummy->next;
        }
    };

int main(){
    Solution s;
    ListNode *head=new ListNode(1);
    head->next=new ListNode(4);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(2);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(2);
    ListNode *res=s.partition(head,3);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}