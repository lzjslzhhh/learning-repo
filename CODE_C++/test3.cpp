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
        bool isPalindrome(ListNode* head) {
            ListNode *slow=head;
            ListNode *fast=head;
            ListNode *cur=new ListNode();
            ListNode *cur1=new ListNode();
            ListNode *cur2=new ListNode();
            ListNode *pre=new ListNode();
            //ListNode *tmp=new ListNode();
            while(true){
                if(fast==nullptr){
                    cur2=slow;
                    break;
                }
                if(fast->next==nullptr){
                    cur2=slow->next;
                    break;
                }
                //tmp=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            pre=nullptr;
            cur=head;
            while(cur!=slow){
                ListNode *temp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=temp;
            }
            cur1=pre;
            while(cur1&&cur2){
                if(cur1->val!=cur2->val){
                    return false;
                }
            }
            return true;
        }
    };
int main(){
Solution s;
ListNode *head=new ListNode(1);
ListNode *cur=head;
cur->next=new ListNode(2);
cur=cur->next;
cur->next=new ListNode(2);
cur=cur->next;
cur->next=new ListNode(1);
cout<<s.isPalindrome(head)<<endl;
return 0;


}