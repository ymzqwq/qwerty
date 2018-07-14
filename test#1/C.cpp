#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200001;
LL n,m,w=1,ans[N];
struct data{
	LL L,r,num;
	bool operator < (const data &q) const{
		return r<q.r;
	}
}a[N];
struct bridge{
	LL L,num;
}b[N];
multiset<data> s;

inline void read(LL &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int cmp(const data &q,const data &w){
	return q.L<w.L;
}

int comp(const bridge &q,const bridge &w){
	return q.L<w.L;
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i].L),read(a[i].r);
	for(int i=1;i<=m;i++) read(b[i].L),b[i].num=i;
	sort(b+1,b+m+1,comp);
	for(int i=1;i<n;i++){
		LL l=a[i+1].L-a[i].r;
		a[i].r=a[i+1].r-a[i].L;
		a[i].L=l;
		a[i].num=i;
	}
	sort(a+1,a+n,cmp);
	for(int i=1;i<=m;i++){
		while(a[w].L<=b[i].L && w<n) s.insert(a[w]),w++;
		while(!s.empty() && s.begin()->r < b[i].L){
			printf("No");
			return 0;
			//s.erase(s.begin());
		}
		if (s.empty()) continue;
		ans[s.begin()->num]=b[i].num;
		s.erase(s.begin());
	}
	if (w<n||!s.empty()) printf("No");
	 else{
	 	printf("Yes\n");
	 	for(int i=1;i<n;i++) printf("%lld ",ans[i]);
	 }
	return 0;
}
