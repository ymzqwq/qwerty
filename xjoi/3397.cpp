#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,a[N],ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	 if (a[i]!=a[i-1]){
	 	int j=a[i]<<1,p;
	 	while(j<=a[n-1]){
	 		p=lower_bound(a,a+n,j)-a;
	 		if (p>0) ans=max(ans,a[p-1]%a[i]);
	 		j+=a[i];
	 	}
	 	ans=max(ans,a[n-1]%a[i]);
	 }
	printf("%d",ans);
	return 0;
}
