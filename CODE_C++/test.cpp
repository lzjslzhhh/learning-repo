// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// struct ListNode {
//         int val;
//         ListNode *next;
//         // 默认构造函数
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int val):val(val),next(nullptr){}
//         // 双参数构造函数
//         ListNode(int val, ListNode* next) : val(val), next(next) {}

// };
// class Solution {
//     public:
//         string reverseStr(string s, int k) {
//             int slow=0,fast=0;
//             int start=0;
//             while(slow<s.size()){
//                 if(fast>0&&fast%(2*k)==0){
//                     reverse(s,start,slow-1);
//                     slow=fast;
//                     start=fast;
//                 }
//                 slow+=1;
//                 fast+=2;
//             }
//             reverse(s,start,s.size()-1);
//             return s;
//         }
//         void reverse(string &s,int start,int end){
//             while(start<end){
//                 swap(s[start],s[end]);
//                 end--;
//                 start++;
//             }
//         }
//     };

// int main(){
//     Solution sol;
//     string s="abcdefg";
//     int k=2;
//     cout<<sol.reverseStr(s,k)<<endl;
//     return 0;
// }