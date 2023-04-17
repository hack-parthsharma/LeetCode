class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String w1="";
        String w2="";
        for(int i=0; i<word1.length; i++)
        {
            w1+=word1[i];
        }
        String ans1=w1;
        for(int i=0; i<word2.length; i++)
        {
            w2+=word2[i];
        }
        String ans2=w2;
        if(w1.equals(w2))
        {
            return true;
        }
        else
            return false;
    }
}