#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200001;
const LL p=1e9+7;
LL n,mul[N],inv[N];

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

LL getc(LL m,LL n){
	return inv[n]*inv[m-n]%p*mul[m]%p;
}

int main(){
	cin>>n;
	mul[0]=1;
	for(int i=1;i<=n<<1;i++) mul[i]=mul[i-1]*i%p;
	inv[n<<1]=power(mul[n<<1],p-2);
	for(int i=(n<<1)-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
	cout<<(getc(n<<1,n)-getc(n<<1,n-1)+p)%p;
	return 0;
}
