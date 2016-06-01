class BinaryCode:
    def decode(self, message):
        secret = map(int, list(message))

        n = len(secret)
        res = []
        # plain0
        plain0 = [0,] * n
        failed = False
        for i in range(1, n):
            # calculate plain0[i], use secret[i - 1] = plain0[i - 2] + plain0[i - 1] + plain0[i]
            pending = secret[i - 1]
            if i - 2 >= 0:
                pending -= plain0[i - 2]
            if i - 1 >= 0:
                pending -= plain0[i - 1]
            if pending in [0, 1]:
                plain0[i] = pending
            else:
                failed = True
                break

        # test secret[n - 1]
        tmp = 0
        if n - 2 >= 0:
            tmp += plain0[n - 2]
        tmp += plain0[n - 1]
        if tmp != secret[n - 1]:
            failed = True
        
        if failed:
            res.append('NONE')
        else:
            res.append(''.join(map(str, plain0)))
        # plain1
        plain1 = [1,] * n
        failed = False
        for i in range(1, n):
            # calculate plain0[i], use secret[i - 1] = plain0[i - 2] + plain0[i - 1] + plain0[i]
            pending = secret[i - 1]
            if i - 2 >= 0:
                pending -= plain0[i - 2]
            if i - 1 >= 0:
                pending -= plain0[i - 1]
            if pending in [0, 1]:
                plain0[i] = pending
            else:
                failed = True
                break
        # test secret[n - 1]
        tmp = 0
        if n - 2 >= 0:
            tmp += plain1[n - 2]
        tmp += plain1[n - 1]
        if tmp != secret[n - 1]:
            failed = False
        if failed:
            res.append('NONE')
        else:
            res.append(''.join(map(str, plain1)))

        return tuple(res)


