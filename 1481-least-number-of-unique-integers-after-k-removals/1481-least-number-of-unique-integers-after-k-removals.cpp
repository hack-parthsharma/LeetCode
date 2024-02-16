class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> count;
    priority_queue<int, vector<int>, greater<>> minHeap;

for (const int a : arr)
      ++count[a];

for (const auto& [_, freq] : count)
      minHeap.push(freq);

while (k > 0)
      k -= minHeap.top(), minHeap.pop();

    return minHeap.size() + (k < 0 ? 1 : 0);
  }
};
