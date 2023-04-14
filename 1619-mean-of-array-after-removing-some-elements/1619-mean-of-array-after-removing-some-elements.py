class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr = sorted(arr)
        n = len(arr)
        
        five_percent = int(n * 0.05)
                
        arr = arr[five_percent: n - five_percent]
        
        return sum(arr) / len(arr)