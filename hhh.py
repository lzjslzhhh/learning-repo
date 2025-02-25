class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        highrow = List.length
        highcol = List[0].length
        lowrow = 0
        lowcol = 0
        while lowrow < highrow && low < highcol:
            midrow = (highrow - lowrow)/2 + lowrow
            midcol = (highcol - lowcol)/2 + lowcol
            if List[midrow][midcol] == target:
                return True
            elif 

