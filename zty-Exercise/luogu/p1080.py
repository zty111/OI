n=int(input())
s=input().split()
S=int(s[0])
T=int(s[1])
a=[]
ans=0
for i in range(1,n+1):
    k=input().split()
    a.append((int(k[0]),int(k[1])))

a.sort(key=lambda x:x[0]*x[1])

for i in range(0,n):
    if S
        ans=S
    S*=(a[i])[0]

print(ans)

