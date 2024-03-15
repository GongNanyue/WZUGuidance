while True:
    try:
        n = int(input())
        print(f"{bin(n)[2:]}")
    except EOFError:
        break
