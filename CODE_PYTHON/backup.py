class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        lr, lc = 0, 0
        hr, hc = m - 1, n - 1
        mr, mc = m - 1, n - 1
        while lr <= hr and lc <= hc:
            mr = int((hr + lr) / 2)
            mc = int((hc + lc) / 2)
            if matrix[mr][mc] == target:
                return True
            elif matrix[mr][mc] >= target and matrix[mr - 1][mc - 1] < target:
                for i in range(0, mr + 1):
                    if matrix[i][mc] == target:
                        return True
                for j in range(0, mc + 1):
                    if matrix[mr][j] == target:
                        return True
                return False
            elif matrix[mr][mc] > target:
                hr, hc = mr - 1, mc - 1
            else:
                lr, lc = mr + 1, mc + 1
        for i in range(0, mr + 1):
            if matrix[i][lc-1] == target:
                return True
        for j in range(0, mc + 1):
            if matrix[lr-1][j] == target:
                return True
        return False