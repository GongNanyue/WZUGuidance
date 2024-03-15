T, k = map(int, input().split())
for _ in range(k):
    n1, b, t, n2 = map(int, input().split())
    if t > T:
        print(f"Not enough tokens.  Total = {T}.")
    elif b == 0 and n2 < n1 or b == 1 and n2 > n1:
        print(f"Win {t}!  Total = {T + t}.")
        T += t
    else:
        print(f"Lose {t}.  Total = {T - t}.")
        T -= t
    if T == 0:
        print("Game Over.")
        break
