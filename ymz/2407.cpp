#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=101;
LL x,y,m,n,L,a,k,g,c,b;

LL gcd(LL a,LL b) { return b==0?a:gcd(b,a%b); }

void exgcd(LL a,LL b,LL &g,LL &x,LL &y){
	if (b==0) { g=a;x=1;y=0;return; }
	exgcd(b,a%b,g,y,x);
	y-=a/b*x;
}

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	cin>>x>>y>>m>>n>>L;
	//if (x>y) x^=y^=x^=y,m^=n^=m^=n;
	a=m-n;b=-L;c=y-x;
	g=gcd(a,b);
	if (c==0){
		printf("0");
		return 0;
	}
	if (c%gcd(a,b)){
		printf("Impossible");
		return 0;
	}
	a/=g;b/=g;c/=g;
	exgcd(a,b,g,x,y);
	x*=c;
	x=(x%b+b)%b;
	cout<<x;
	return 0;
}
