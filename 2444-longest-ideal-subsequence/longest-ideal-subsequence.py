class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        return (d:=[0]*123) and max(setitem(d,z:=ord(c),1+max(d[z-k:z+k+1])) or d[z] for c in s)