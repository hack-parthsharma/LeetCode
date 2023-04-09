class Solution:
    def reformat(self, s: str) -> str:
        
        digits = []
        chars = []
        
        for c in s:
            
            if c.isalpha():
                chars.append(c)
            elif c.isdigit():
                digits.append(c)
                
                
        if abs(len(digits) - len(chars)) > 1:
            return ""
        
        if len(digits) > len(chars):
            longer = digits 
            shorter = chars
        else:
            longer = chars
            shorter = digits
            
        result = ""
        
        for i in range(len(s)):
            if i % 2 == 0:
                result += longer.pop(0)
            else:
                result += shorter.pop(0)
                
                
        return result        

