class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        indegrees = collections.defaultdict(list)
        for i in range(n):
            for a, b in roads:
                if i == a:
                    indegrees[i].append(f'{i}-{b}')
                    indegrees[i].append(f'{b}-{i}')
                if i == b:
                    indegrees[i].append(f'{i}-{a}')
                    indegrees[i].append(f'{a}-{i}')

        max_net = 0
        for i in range(n):
            for j in range(n):
                if f'{i}-{j}' or f'{j}-{i}' in indegrees[i]:
                    net = len(set(indegrees[i] + indegrees[j])) // 2
                    max_net = max(max_net, net)

        return max_net