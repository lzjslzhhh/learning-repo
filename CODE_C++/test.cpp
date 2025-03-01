#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int right1=nums.size()-1;
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            int cot=0;
            if(nums.size()<4) {
                return ans;
            }
            for(int left1=0;left1<nums.size()-3;left1++){
                if(nums[left1]>target&&target>=0) return ans;
                right1=nums.size()-1;
                while(right1-left1>=3){
                    if(left1>0&&nums[left1-1]==nums[left1]){
                        left1++;
                        continue;
                    }
                    if(right1<nums.size()-1&&nums[right1+1]==nums[right1]){
                        right1--;
                        continue;
                    }
                    int left2=left1+1;
                    int right2=right1-1;
                    while(left2<right2){
                        if(nums[left1]>=target&&target>0) return ans;
                        if(nums[right1]<target&&target<0) break;
                        int temp=nums[left1]+nums[right1]+nums[left2]+nums[right2];
                        if(temp==target){
                            ans.push_back({nums[left1],nums[right1],nums[left2],nums[right2]});
                            left2++;
                            right2--;
                            while(left2<right2&&nums[left2-1]==nums[left2]) left2++;
                            while(left2<right2&&nums[right2+1]==nums[right2]) right2--;
                        }else if(temp>target){
                            right2--;
                        }else{
                            left2++;
                        }
                    }
                    if(nums[right1]<target&&target<0) break;
                    right1--;
                }
                if(nums[right1]<target&&target<0) continue;
            }
            return ans;
        }
    };

int main(){
    Solution s;
    vector<int> nums={-1000000000,-1000000000,-1000000000,-1000000000};
    vector<vector<int>> ans=s.fourSum(nums,-2);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}