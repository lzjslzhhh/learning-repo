class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :type nums4: List[int]
        :rtype: int
        """
        count=0
        hash_map={}
        for i in nums1:
            for j in nums2:
                if i+j in hash_map:
                    hash_map[i+j]+=1
                else:
                    hash_map[i+j]=1
        for i in nums1:
            for j in nums2:
                if -(i+j) in hash_map:
                    count+=hash_map[-(i+j)]
        return count

sol = Solution()
nums=[1,1,1,2,2,3]
print(sol.fourSumCount())
