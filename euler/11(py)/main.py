with open("input.in", "r") as f:
    m = [[int(y) for y in x.split()] for x in f.read().splitlines()]
    n = len(m)
    result = 0
    for i in range(n):
        for j in range(n):
            s = [1]*4;
            for k in range(4):
                if i+k < n:
                    s[0] *= m[i+k][j]
                if j+k < n:
                    s[1] *= m[i][j+k]
                if i+k < n and j+k < n:
                    s[2] *= m[i+k][j+k]
                if i+k < n and j-k >= 0:
                    s[3] *= m[i+k][j-k]
            result = max(result, max(s))
    print(result)
