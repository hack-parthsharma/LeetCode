class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])                          #sort the intervals with starting time as the key
        merged = []
        for interval in intervals:
            if not merged or merged[-1][1] < interval[0]:           #If merged list is empty (we need to push the first interval) or Overlapping condn doesnt satisfy
                merged.append(interval)                             #push the interval in merged array
            else:                                                   #else
                merged[-1][1] = max(merged[-1][1], interval[1])     #update the end time of last interval in merged array as maximum of end time of both intervals
        return merged 