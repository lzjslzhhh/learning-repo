class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        """
        :type rows: int
        :type cols: int
        :type rStart: int
        :type cStart: int
        :rtype: List[List[int]]
        """
        ans=[]
        lr=0
        lc=0
        hr=0
        hc=1
        cot=1
        ans.append([rStart,cStart])
        while True:
            for i in range(lc+1,hc+1):
                x=lr+rStart
                y=i+cStart
                if x>=0 and x <rows and y>=0 and y<cols:
                    ans.append([x,y])
                    cot+=1
            if cot == rows * cols:
                break
            hr+=1
            for i in range(lr+1,hr+1):
                x=i+rStart
                y=hc+cStart
                if x>=0 and x <rows and y>=0 and y<cols:
                    ans.append([x,y])
                    cot+=1
            if cot == rows * cols:
                break
            lc-=1
            for i in range(hc-1,lc-1,-1):
                x=hr+rStart
                y=i+cStart
                if x>=0 and x <rows and y>=0 and y<cols:
                    ans.append([x,y])
                    cot+=1
            if cot==rows*cols:
                break
            lr-=1
            for i in range(hr-1,lr-1,-1):
                x=i+rStart
                y=lc+cStart
                if x>=0 and x <rows and y>=0 and y<cols:
                    ans.append([x,y])
                    cot+=1
            if cot==rows*cols:
                break
            hc+=1
        return ans

sol = Solution()
n=3
print(sol.spiralMatrixIII(5,6,1,4))
