#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int n,a[N],sum[N];

inline void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++){
		int v=i-2,j,t;
		for(j=1;j<=i-2;j=t+1){
			t=v/(v/j);
			if (a[(i-2)/j+1]>a[i]) sum[j]++,sum[t+1]--;
		}
		if (a[1]>a[i]) sum[i-1]++,sum[n]--;
	}
	for(int i=1;i<n;i++){
		sum[i]+=sum[i-1];
		printf("%d ",sum[i]);
	}
	return 0;
}
