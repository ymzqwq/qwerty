#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int n,ans,w;
struct data{
	int L,r;
}a[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int cmp(const data &q,const data &w){ return q.L<w.L; }

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i].L),read(a[i].r);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	 if (a[i].L>=w) ans++,w=a[i].r;
	  else if (a[i].r<w) w=a[i].r;
	cout<<ans;
	return 0;
}
