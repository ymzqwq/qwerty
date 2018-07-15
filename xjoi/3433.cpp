#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
const int N=100001;
LL A,B,C,X1,x2,Y1,y2,g,x,y,a0,b0,mn,mx;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void exgcd(LL a,LL b,LL &g,LL &x,LL &y){
	if (b==0) { g=a;x=1;y=0;return; }
	exgcd(b,a%b,g,y,x);
	y-=(a/b)*x;
}

int main(){
	cin>>A>>B>>C>>X1>>x2>>Y1>>y2;
	if (A==0&&B==0){
		if (C==0) cout<<x2-X1+y2-Y1+2;
		 else cout<<'0';
		return 0;
	}
	if (A<B) A^=B^=A^=B;
	C=-C;
	exgcd(A,B,g,x,y);
	if (C%g){
		printf("0");
		return 0;
	}
	if (B==0){
		printf("1");
		return 0;
	}
	x*=C/g;y*=C/g;
	a0=A/g;b0=B/g;
	mn=max((LL)ceil((X1-x)*1.0/b0),(LL)ceil((y-y2)*1.0/a0));
	mx=min((LL)floor((x2-x)*1.0/b0),(LL)floor((y-Y1)*1.0/a0));
	cout<<max(mx-mn+1,1LL*0);
	return 0;
}
