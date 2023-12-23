import math

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

x = [i * 6.2831 / 1000 for i in range(1000)]

y = [sum([math.sin(A[i]*x[j] + B[i]) for i in range(n)]) for j in range(1000)]

peaks = []
for i in range(1, len(y)-1):
    if y[i] > y[i-1] and y[i] > y[i+1]:
        peaks.append(i)

if y[0] > y[1]:
    peaks.insert(0, 0)

if y[-1] > y[-2]:
    peaks.append(len(y)-1)

print(peaks)
peak_diffs = [x[peaks[i]] - x[peaks[i-1]] for i in range(1, len(peaks))]

print(peak_diffs.index(max(peak_diffs)) + 1)