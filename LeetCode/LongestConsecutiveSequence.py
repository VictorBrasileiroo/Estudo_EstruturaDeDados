from typing import List

class Solution:
    
    # def MenorIndex(self, nums: List[int], inicio) -> int:
    #     menorIndex = inicio
    #     for i in range (inicio + 1, len(nums)):
    #         if nums[i] < nums[menorIndex]:
    #             menorIndex = i
    #     return menorIndex
    
    # def SelectionSort(self, nums: List[int]) -> List[int]:
    #     for i in range (len(nums) - 1):
    #         menorIndex = self.MenorIndex(nums, i)
    #         if nums[i] > nums[menorIndex]:
    #             (nums[i], nums[menorIndex]) = (nums[menorIndex], nums[i])
    #     return nums

    # def BubbleSort(self, nums: List[int]) -> List[int]:
    #     for i in range(len(nums) - 1):
    #         for j in range(len(nums) - 1 - i):
    #             if nums[j] > nums[j + 1]:
    #                 (nums[j], nums[j + 1]) = (nums[j + 1], nums[j])
    #     return nums

    def QuickSort(self, nums: List[int], left, right):
        if left < right:
            pivo = self.Particion(nums, left, right)
            self.QuickSort(nums, left, pivo - 1)
            self.QuickSort(nums, pivo + 1, right)
        return nums

    def Particion(self,nums: List[int],left,rigth):
        pivo = nums[rigth]
        i = left - 1
        for j in range(left,rigth):
            if nums[j] <= pivo:
                i = i + 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i+1], nums[rigth] = nums[rigth], nums[i+1]
        return i + 1
 
    def longestConsecutive(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        
        nums = self.QuickSort(nums,0,len(nums)-1)
        count = 1
        maxCount = 0
        for j in range(len(nums) - 1):
            if nums[j + 1] == nums[j] + 1:
                count += 1
            elif nums[j + 1] == nums[j]:
                continue
            else:
                maxCount = max(maxCount, count)
                count = 1

        return max(maxCount, count)
    
sol = Solution()