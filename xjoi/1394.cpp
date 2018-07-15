#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n,a[N],b[N];
long long ans;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void merge(int L,int r){
	if (L==r) return;
	int mid=(L+r)>>1;
	merge(L,mid);merge(mid+1,r);
	int p1=L,p2=mid+1,cnt=L-1;
	while(p1<=mid&&p2<=r)
		if (a[p1]<=a[p2]) b[++cnt]=a[p1++];
		 else{
		 	ans+=mid-p1+1;
		 	b[++cnt]=a[p2++];
		 }
	for(;p1<=mid;p1++) b[++cnt]=a[p1];
	for(;p2<=r;p2++) b[++cnt]=a[p2];
	for(int i=L;i<=r;i++) a[i]=b[i];
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	merge(1,n);
	cout<<ans;
	return 0;
}
