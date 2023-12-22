
up, right, downright, downleft, left = [False]*5

def read_info():
    global up, right, downright, downleft, left
    s = input()
    up, right, downright, downleft, left = [s[i] == "1" for i in range(5)]

def app():
    print("app")
    return int(input())

read_info()
while up:
    print("up", flush=True)
    read_info()

dist = app()
while dist > 0:
    if downleft:
        print("downleft")
        read_info()
    else:
        print("downright")
        read_info()
    new_dist = app()
    if new_dist == dist:
        print("right")
        read_info()
    dist -= 1

print("here")