"""
    test-stats.py
    This program validates the class and procedures to calculate the basic
    statistics of a stream of data without storing the individual values
    in the stream

    Written by hdtodd@gmail.com, 2022.05
"""


import math
import class_stats as stats

x = [20,10, 5,19, 35,60,15,43,23, 8]
y = [18,19,20,-21,22,23,24,25,26,27]

print("\nProgram to validate iterative calculation of basic statistics over a stream of data\n")

avgx = 0.0
for i in x:
    avgx += i
avgx /= len(x)
avgy = 0.0
for i in y:
   avgy += i
avgy /= len(y)

stdx = 0.0
for i in x:
    stdx += (i-avgx)**2
stdx = math.sqrt(stdx/(len(x)-1))
stdy = 0.0
for i in y:
    stdy += (i-avgy)**2
stdy = math.sqrt(stdy/(len(y)-1))

print("By traditional algorithm, \n\t x count, mean, stdev = \t\t", len(x), avgx, stdx,
      "\n\t y count, mean, stdev = \t\t", len(y), avgy, stdy)

for i in range(len(x)):
   if i==0:
       x_stats = stats.stats(x[i])
       y_stats = stats.stats(y[i])
   else:
       x_stats.append(x[i])
       y_stats.append(y[i])

(nx,avgx,stdx,minx,maxx) = x_stats.get()
(ny,avgy,stdy,miny,maxy) = y_stats.get()

print("By recursion, \n\t x count, mean, stdev, min, max = \t", nx, avgx, stdx, minx, maxx,
      "\n\t y count, mean, stdev, min, max = \t", ny, avgy, stdy, miny, maxy)

quit()
