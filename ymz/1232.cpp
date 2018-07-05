#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1000000;
LL n,ans,tot[N],a[3],cnt;

void read(LL &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	a[0]=1;a[1]=2;
	tot[1]++;tot[2]++;
	for(int i=2;i<n;i++){
		a[i%3]=(a[(i-1)%3]+a[(i-2)%3])%N;
		tot[a[i%3]]++;
	}
	for(int i=0;i<N;i++)
	 for(int j=tot[i];j;j--)
	 	ans=(ans+1LL*i*cnt)%N,cnt++;
	cout<<ans;
	return 0;
}
