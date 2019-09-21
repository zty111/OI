#include<iostream>
 #include<cstdio>
 #include<algorithm>
 #include<cstring>
 using namespace std;
 int a[100],v[100],n,len,cnt,tn,x;
 bool dfs(int stick,int cab,int last){
     if(stick>cnt)return true;
     if(cab==len)return dfs(stick+1,0,1);
     int fail=0;
     for(int i=last;i<=tn;i++)
         if(!v[i]&&cab+a[i]<=len&&fail!=a[i]){
             v[i]=1;
             if(dfs(stick,cab+a[i],i+1))return true;
             fail=a[i];
             v[i]=0;
             if(cab==0||cab+a[i]==len)return false;
         }
     return false;
 }
 bool cmp(int a,int b){return a>b;}
 int main(){
     ios::sync_with_stdio(false);
     while(cin>>n&&n){
         int sum=0,val=0;
         tn=0;
         for(int i=1;i<=n;i++){
             cin>>x;if(x>50)continue;
             tn++;a[tn]=x;
             sum+=a[tn];val=max(val,a[tn]);
         }
         sort(a+1,a+tn+1,cmp);
         for(len=val;len<=sum;len++){
             if(sum%len)continue;
             cnt=sum/len;
             memset(v,0,sizeof(v));
             if(dfs(1,0,1))break;
         }
         cout<<len<<endl;
     }
     return 0;
 }