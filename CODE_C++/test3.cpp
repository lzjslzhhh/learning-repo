#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            string temp=s+s;
            temp.erase(temp.begin());
            temp.erase(temp.end()-1);
            return kmp(temp,s);
        }
        bool kmp(const string a,const string b){
            vector<int> next(b.size());
            getNext(&next[0],b);
            int j=-1;
            for(int i=1;i<a.size();i++){
                while(j>=0&&a[i]!=b[j+1]){
                    j=next[j];
                }
                if(a[i]==b[j+1]){
                    j++;
                }
                if(j==b.size()-1){
                    return true;
                }
            }
            return false;
        }
        void getNext(int *next,const string s){
            int j=-1;
            next[0]=j;
            for(int i=1;i<s.size();i++){
                while(j>=0&&s[i]!=s[j+1]){
                    j=next[j];
                }
                if(s[i]==s[j+1]){
                    j++;
                }
                next[i]=j;
            }
        }
    };

int main(){
    Solution sol;
    string s="bb";
    cout<<sol.repeatedSubstringPattern(s)<<endl;
    return 0;
}