#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,m,a[N];

inline void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int check(LL x){
	LL pos=1,w=a[1];
	for(int i=1;i<=m;i++){
		LL ti=x-pos;
		while(ti>0){
			LL v=min(ti,w);
			ti-=v;w-=v;
			if (w==0&&pos==n) return 1;
			if (ti==0) continue;  //if w==0?
			pos++;
			ti--;
			w=a[pos];
		}
	}
	return 0;
}

int main(){
	read(n);read(m);
	LL sum=0;
	for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
	while(a[n]==0) n--;
	LL L=n+1,r=sum+n;
	while(L<r){
		LL mid=(L+r)>>1;
		if (check(mid)) r=mid;
		 else L=mid+1;
	}
	cout<<L;
	return 0;
}
