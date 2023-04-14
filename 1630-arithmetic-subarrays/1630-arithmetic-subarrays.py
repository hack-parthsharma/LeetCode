class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        answer = []
        for i in range(len(l)):
            answer.append(self.checkCurrentSubarray(nums[l[i]:r[i]+1]))
        return answer
    
    def checkCurrentSubarray(self, sequence):
        sequence.sort()
        difference = sequence[1] - sequence[0]
        for j in range(2, len(sequence)):
            if sequence[j] - sequence[j-1] != difference:
                return False
        return True