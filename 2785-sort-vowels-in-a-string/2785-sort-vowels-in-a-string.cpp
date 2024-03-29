class Solution {
public:
  string sortVowels(string s) {
    string ans;
    vector<char> vowels;
for (const char c : s)
      if (isVowel(c))
        vowels.push_back(c);
    sort(vowels.begin(), vowels.end());
    int i = 0; 
    for (const char c : s)
      ans += isVowel(c) ? vowels[i++] : c;
    return ans;
  }
    
 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }
};
