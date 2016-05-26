class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        if secret is None or guess is None or len(secret)==0:
            return ""
        temp,countA,countB={},0,0
        for n in secret:
            temp[n]=temp.get(n,0)+1
        for i,g in enumerate(guess):
            if g in secret:
                if g==secret[i]:
                    countA+=1
                else:
                    countB+=1
                if temp[g]<1:
                    countB-=1
                temp[g]-=1
        return str(countA)+"A"+str(countB)+"B"
