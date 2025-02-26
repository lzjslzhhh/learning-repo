class Solution:
    def searchMatrix(self, matrix, target) -> bool:
        m = len(matrix)
        m = len(matrix)
        n = len(matrix[0])
        row = 0
        col = n - 1
        while col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1
            else:
                row += 1
        return False


matrix = [[2,5],[2,8],[7,9],[7,11],[9,11]]
target = 7
sol = Solution()
print(sol.searchMatrix(matrix, target))
