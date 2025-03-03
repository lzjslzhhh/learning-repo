#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        // 默认构造函数
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val):val(val),next(nullptr){}
        // 双参数构造函数
        ListNode(int val, ListNode* next) : val(val), next(next) {}

};
class MyLinkedList {
    public:
        MyLinkedList() {
            ListNode *head = new ListNode();
        }
        
        int get(int index) {
            ListNode *cur=head->next;
            for(int i=0;cur!=nullptr&&i<index;i++){
                cur=cur->next;
            }
            if(cur==nullptr) return -1;
            else return cur->val;
        }
        
        void addAtHead(int val) {
            ListNode *cur=new ListNode();
            cur->next=head->next;
            cur->val=val;
            head->next=cur;
        }
        
        void addAtTail(int val) {
            ListNode *cur=head;
            while(cur->next!=nullptr) cur=cur->next;
            ListNode *tmp=new ListNode();
            tmp->val=val;
            cur->next=tmp;
        }
        
        void addAtIndex(int index, int val) {
            if(index==0) addAtHead(val);
            ListNode *cur=head->next;
            for(int i=0;cur!=nullptr&&i<index-1;i++){
                cur=cur->next;
            }
            if(cur==nullptr) return;
            ListNode *tmp=new ListNode();
            tmp->next=cur->next;
            cur->next=tmp;
            tmp->val=val;
        }
        
        void deleteAtIndex(int index) {
            int i;
            ListNode *cur=head->next;
            for(i=0;cur!=nullptr&&cur->next!=nullptr&&i<index-1;i++){
                cur=cur->next;
            }
            if(i==index-1){
                ListNode *tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;
            }else{
                return;
            }
        }
        ListNode *head;
    };
    
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */

int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    cout<<obj->get(1)<<endl;
    obj->deleteAtIndex(1);
    cout<<obj->get(1)<<endl;
    return 0;
}