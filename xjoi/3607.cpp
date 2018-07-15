#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1000001;
const int p=1e9+7;
LL n,k,seed,ans,L,t=1;
struct data{
	LL x,num;
}h[N];

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void push(LL x,LL num){
	h[++L]=(data){x,num};
	for(;L>t&&h[L].x>h[L-1].x;L--) h[L-1]=h[L];
}

LL pop(LL x){
	while(h[t].num<=x-k) t++;
	return h[t].x;
}

int main(){
	read(n);read(k);read(seed);
	for(int i=1;i<k;i++){
		LL x=seed*i%p;
		push(x,i);
	}
	for(int i=k;i<=n;i++){
		LL x=seed*i%p;
		push(x,i);
		ans+=pop(i);
	}
	cout<<ans;
	return 0;
}
