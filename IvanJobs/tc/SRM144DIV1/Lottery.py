import math

def cmp(x1, x2):
    if x1[1] < x2[1]:
        return True
    elif x1[1] == x2[1]:
        return x1[0] <= x2[0]
    else:
        return False

    
def A(n, m):
    return math.factorial(n)/math.factorial(n - m)

def C(n, m):
    return A(n, m) / math.factorial(m)


class Lottery:
    def sortByOdds(self, rules):
        # parse rules
        holder = []
        for rule in rules:
            item = []
            tmp = rule.split(':')
            item.append(tmp[0])
            choices, blanks, issort, isunique = tmp[1].split()
            choices, blanks = int(choices), int(blanks)
            cnt = -1 
            if issort == 'F' and isunique == 'F':
                cnt = choices ** blanks
            if issort == 'T' and isunique == 'F':
                dp = [0] * (blanks + 1)
                dp = [dp] * (choices + 1)

                # prepare init state
                for i in range(1, choices + 1):
                    dp[i][1] = i

                for i in range(1, blanks + 1):
                    dp[1][i] = 1


                for n in range(2, choices + 1):
                    for m in range(2, blanks + 1):
                        # calculate dp[n][m]
                        tmp = 0
                        for j in range(1, n + 1):
                            tmp += dp[j][m - 1]
                        dp[n][m] = tmp

                cnt = dp[choices][blanks]

 
            if issort == 'F' and isunique == 'T':
                cnt = A(choices, blanks)
            if issort == 'T' and isunique == 'T':
                cnt = C(choices, blanks)
            
            item.append(cnt)

            holder.append(item)

        # cust sort

        holder.sort(cmp)
        res = []
        for item in holder:
            res.append(item[0])

        return tuple(res)
