#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=60001;
const int p=998244353;
int T,n,a[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	freopen("inverse.in","r",stdin);
	freopen("inverse.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++) read(a[i]);
		int ans=0;
		while(next_permutation(a+1,a+n+1)){
			int sum=0,mn=0;
			for(int i=1;i<=n;i++) mn+=abs(i-a[i]);
			//memcpy(c,a,sizeof c);
			mn>>=1;
			for(int i=1;i<n;i++)
			 for(int j=i+1;j<=n;j++)
			  if (a[i]>a[j]) sum++;
			if (sum==mn) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
