class Solution:
  def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
    # If desiredTotal is less than or equal to zero, then player 1 wins
    if desiredTotal <= 0:
        return True
    # If the sum of all the integers is less than the desiredTotal, then player 1 can't win
    if (maxChoosableInteger * (maxChoosableInteger + 1)) // 2 < desiredTotal:
        return False
    
    # Store the sub-problems result
    self.memo = {}
    
    # Traverse through all possible moves of player 1
    return self.can_win(tuple(range(1, maxChoosableInteger+1)), desiredTotal)


  def can_win(self, choices, target):
    # If there is only one choice left and it's value is greater than or equal to target, then player 1 wins
    if choices[-1] >= target:
        return True
    
    # If the sub-problem already exists, return it's result
    if choices in self.memo:
        return self.memo[choices]
    
    # Traverse through all possible moves of player 1
    for i in range(len(choices)):
        # Player 1 chooses a number
        if not self.can_win(choices[:i]+choices[i+1:], target-choices[i]):
            # If player 2 can't win, then player 1 can win
            self.memo[choices] = True
            return True
    
    # If no move of player 1 results in player 1 winning, then player 1 can't win
    self.memo[choices] = False
    return False

