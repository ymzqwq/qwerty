#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,f[N],tot[N],k;
char c[N];
LL ans;

void read(int &x){
	char ch=getchar();x=0;int flag=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
	 if (flag) x=(x<<3)+(x<<1)+1;
	  else if (ch<'2') x=(x<<3)+(x<<1)+ch-'0';
	   else{
	   	  flag=1;
	   	  x=(x<<3)+(x<<1)+1;
	   }
}

int main(){
	read(k);
	scanf("%s",c+1);
	int n=strlen(c+1);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+(c[i]=='1');
	for(int i=0;i<=n;i++) tot[f[i]]++;
	for(int i=0;i<=f[n]-k;i++) ans+=1LL*f[i]*f[i+k];
	cout<<ans;
	return 0;
}
