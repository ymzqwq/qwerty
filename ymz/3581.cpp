#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=500001;
LL n,k;
double sumw,sumv,ans;
struct data{
	LL w,v;
}a[N],c[N];

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int cmp(const data &q,const data &w){ return q.v>w.v; }

void iter(){
	for(int i=1;i<=100000;i++){
		for(int j=1;j<=n;j++) c[j].v=a[j].v-a[j].w*ans,c[j].w=j;
		sort(c+1,c+1+n,cmp);
		sumw=0;sumv=0;
		for(int j=1;j<=k;j++) sumw+=a[c[j].w].w,sumv+=a[c[j].w].v;
		ans=sumv/sumw;
	}
}

int main(){
	read(n);read(k);
	for(int i=1;i<=n;i++) read(a[i].w);
	for(int i=1;i<=n;i++) read(a[i].v);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=k;i++) sumw+=a[i].w,sumv+=a[i].v;
	ans=sumv/sumw;
	iter();
	printf("%.2lf",ans);
	return 0;
}
