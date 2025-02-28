class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start=0
        end=0
        n=len(nums)
        while end<len(nums):
            if end>=2 and nums[end-2]==nums[end]:
                start=end
                num=nums[end]
                while nums[end]==num:
                    end+=1
                    if nums[end - 2] == nums[end]:
                        n-=1
                nums[start]=nums[end]
                start+=1
                end+=1
                while end<len(nums) and nums[start]<nums[end]:
                    nums[start]=nums[end]
                    start+=1
                    end+=1
                n-=1
            end+=1
        return n

sol = Solution()
nums=[1,1,1,2,2,3]
print(sol.removeDuplicates(nums))
