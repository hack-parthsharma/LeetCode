class Solution {
 public:
  string reorganizeString(string s) {
    unordered_map<char, int> count;
    int maxFreq = 0;

    for (const char c : s)
      maxFreq = max(maxFreq, ++count[c]);
    if (maxFreq > (s.length() + 1) / 2)
      return "";
    string ans;
    priority_queue<pair<int, char>> maxHeap;  
    int prevFreq = 0;
    char prevChar = '@';
    for (const auto& [c, freq] : count)
      maxHeap.emplace(freq, c);
    while (!maxHeap.empty()) {
      const auto [freq, c] = maxHeap.top();
      maxHeap.pop();
      ans += c;
      if (prevFreq > 0)
        maxHeap.emplace(prevFreq, prevChar);
      prevFreq = freq - 1;
      prevChar = c;
    }
    return ans;
  }
};
