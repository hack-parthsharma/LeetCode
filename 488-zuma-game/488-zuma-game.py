class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        
        # remove the consecutive same balls starting from index i
        def remove_same(s, i):
            if i < 0:
                return s
            
            left = right = i
            while left > 0 and s[left-1] == s[i]:
                left -= 1
            while right+1 < len(s) and s[right+1] == s[i]:
                right += 1
            
            length = right - left + 1
            if length >= 3:
                # remove consecutive same balls
                new_s = s[:left] + s[right+1:]
                return remove_same(new_s, left-1)
            else:
                return s

        # sort hand so that we can easily iterate over it
        hand = "".join(sorted(hand))

        # initialize queue and visited set
        q = collections.deque([(board, hand, 0)])
        visited = set([(board, hand)])

        while q:
            # get the current board, hand and step from queue
            curr_board, curr_hand, step = q.popleft()
            for i in range(len(curr_board)+1):
                for j in range(len(curr_hand)):
                    # skip balls in hand that are consecutive to the previous one
                    if j > 0 and curr_hand[j] == curr_hand[j-1]:
                        continue
                    
                    # only insert a ball in board if it is the first ball in a sequence
                    if i > 0 and curr_board[i-1] == curr_hand[j]:
                        continue
                    
                    # check if the ball can be picked and inserted
                    pick = False
                    # 1. same color with right
                    # 2. left and right are same but pick is different
                    if i < len(curr_board) and curr_board[i] == curr_hand[j]:
                        pick = True
                    if 0<i<len(curr_board) and curr_board[i-1] == curr_board[i] and curr_board[i] != curr_hand[j]:
                        pick = True
                    
                    # if the ball can be picked and inserted, add the new board, hand and step to the queue
                    if pick:
                        new_board = remove_same(curr_board[:i] + curr_hand[j] + curr_board[i:], i)
                        new_hand = curr_hand[:j] + curr_hand[j+1:]
                        if not new_board:
                            # if the board is empty, return the number of steps taken to reach it
                            return step + 1
                        if (new_board, new_hand) not in visited:
                            q.append((new_board, new_hand, step+1))
                            visited.add((new_board, new_hand))

        # if no solution is found, return -1
        return -1

