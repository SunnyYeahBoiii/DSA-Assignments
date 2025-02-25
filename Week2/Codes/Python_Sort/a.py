import time
import sys

with open("dummy.inp" , "r") as file:
    n = int(file.readline().strip())  # Read first line as an integer
    a = list(map(int, file.readline().strip().split()))  # Read second line as a list of integers

start_time = time.time()

a.sort()

num = float(time.time() - start_time)

file = open("Time_measured.txt" , "a")
file.write("Python Sort took = " + f"{num:.6f}" + " seconds on test " )
file.write(sys.argv[1])
file.write("\n")
file.close()

with open("dummy.out" , "w") as file:
    for x in a:
        file.write(str(x))
        file.write(" ")