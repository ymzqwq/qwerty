#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,h;
LL ans;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(h);read(n);
	n--;
	n+=(1<<h);
	for(LL i=0;i<h;i++){
		int x=(n&(1<<i))==0,y=(n&(1<<i+1))==0;
		if ((x^y)==0) ans+=(1<<i+1)-1;
	}
	ans+=h;
	cout<<ans;
	return 0;
}
