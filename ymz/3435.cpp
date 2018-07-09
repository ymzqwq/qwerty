#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL m,n,p,mul[N],inv[N];

void read(LL &x){
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

LL getc(LL m,LL n,LL p){
	return inv[n]*inv[m-n]%p*mul[m]%p;
}

LL lucas(LL m,LL n,LL p){
	LL ans=1;
	while(m||n){
		LL a=m%p,b=n%p;
		ans=ans*getc(a,b,p);
		m/=p;n/=p;
	}
	return ans;
}

int main(){
	cin>>m>>n>>p;
	if (m>=p){
		mul[0]=1;
		for(int i=1;i<p;i++) mul[i]=mul[i-1]*i%p;
		inv[p-1]=power(mul[p-1],p-2);
		for(int i=p-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
		cout<<lucas(m,n,p);
	}
	 else{
	 	mul[0]=1;
		for(int i=1;i<=m;i++) mul[i]=mul[i-1]*i%p;
		inv[m]=power(mul[m],p-2);
		for(int i=m-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
		cout<<getc(m,n,p);
	 }
	return 0;
}
