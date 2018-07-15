#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

LL gcd(LL a,LL b) { return b==0?a:gcd(b,a%b); }

int main(){
	cin>>n;
	cout<<4*n/gcd(n<<2,n+1)+1;
	return 0;
}
