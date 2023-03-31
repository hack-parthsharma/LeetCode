class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& nums) {
    int ans = 0;
    unordered_set<int> setNums{begin(nums), end(nums)};

    for (; head; head = head->next)
      if (setNums.count(head->val) &&
          (!head->next || !setNums.count(head->next->val)))
        ++ans;

    return ans;
  }
};
