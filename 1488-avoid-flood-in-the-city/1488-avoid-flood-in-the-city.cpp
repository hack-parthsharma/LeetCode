class Solution {
 public:
  vector<int> avoidFlood(vector<int>& rains) {
    vector<int> ans(rains.size(), -1);
    unordered_map<int, int> lakeIdToFullDay;
    set<int> emptyDays;  // indices of rains[i] == 0

    for (int i = 0; i < rains.size(); ++i) {
      const int lakeId = rains[i];
      if (lakeId == 0) {
        emptyDays.insert(i);
        continue;
      }
      if (const auto itFullDay = lakeIdToFullDay.find(lakeId);
          itFullDay != cend(lakeIdToFullDay)) {
        // The lake was full in a previous day. Greedily find the closest day
        // to make the lake empty.
        const auto itEmptyDay = emptyDays.upper_bound(itFullDay->second);
        if (itEmptyDay == cend(emptyDays))  // Not found.
          return {};
        // Empty the lake at this day.
        ans[*itEmptyDay] = lakeId;
        emptyDays.erase(itEmptyDay);
      }
      // Lake with `lakeId` becomes full at day i.
      lakeIdToFullDay[lakeId] = i;
    }

    // Pick a arbitrary lake to empty if there are remaining empty days.
    for (const int emptyDay : emptyDays)
      ans[emptyDay] = 1;

    return ans;
  }
};
