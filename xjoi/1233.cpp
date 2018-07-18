#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10000001;
const int d=32768;
const int p=1234567;
int n,a[N],b[N],w[N],num[N],tot[d],mx;

void read(LL &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void radixsort(){
	int now=1;
	while(now<=mx){
		memset(tot,0,sizeof tot);
		for(int i=1;i<=n;i++) w[i]=a[i]/now%d;
		for(int i=1;i<=n;i++) tot[w[i]]++;
		for(int i=1;i<d;i++) tot[i]+=tot[i-1];
		for(int i=n;i;i--){
			b[tot[w[i]]]=a[i];
			tot[w[i]]--;
		}
		now*=d;
		memcpy(a,b,sizeof a);
	}
}

int main(){
	cin>>n;
	a[1]=1;a[2]=2;
	for(int i=3;i<=n;i++) a[i]=(a[i-1]+a[i-2])%p,mx=max(mx,a[i]);
	radixsort();
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+(1LL*a[i]*(i-1))%p;
		if (sum>=p) sum-=p;
	}
	cout<<sum<<endl;
	return 0;
}
