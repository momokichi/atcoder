s = input()
ans= 0

for i in range(len(s)):
  for j in range(i+3,len(s)):
    itoj = s[i:j+1]
    if (int(itoj) %  2019 ==0):
      ans+=1
      # print(i,j)

print(ans)