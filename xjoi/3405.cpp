#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5001;
const int p=998244353;
LL a,b,c,ans,C[N+1][N+1],mul[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

LL power(LL a,LL n){
	LL sum=a,ans=1;
	while(n){
		if (n&1) ans=ans*sum%p;
		n>>=1;
		sum=sum*sum%p;
	}
	return ans;
}

LL add_up(LL a,LL b){
	if (a>b) a^=b^=a^=b;
	LL sum=0;
	for(int i=0;i<=a;i++)
	 sum=(sum+C[a+1][i+1]*C[b+1][i+1]%p*mul[i]%p)%p;
	return sum;
}

int main(){
	cin>>a>>b>>c;
	C[0][0]=1;
	for(int i=1;i<=N;i++)
	 for(int j=1;j<=N;j++)
	  C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	mul[0]=1;
	for(int i=1;i<N;i++) mul[i]=mul[i-1]*i%p;
	ans=add_up(a,b)*add_up(b,c)%p*add_up(a,c)%p;
	cout<<ans;
	return 0;
}
