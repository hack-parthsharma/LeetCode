class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counter = {}
        
        for num in arr:
            counter[num] = counter.get(num, 0) + 1
            
        lucky = -1
        for key, value in counter.items():
            if key == value and key > lucky:
                lucky = value
            
        return lucky