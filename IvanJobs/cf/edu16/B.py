n = int(raw_input())
nums = map(int, raw_input().split())

nums.sort()

print nums[(n - 1)/2]
