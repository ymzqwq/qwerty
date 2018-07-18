#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=21;
LL n,k,ans,w;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int pd(){
	LL d=(1<<k)-1;
	for(;d<=n;d<<=1)
	 if ((n&d)==d) return 1;
	return 0;
}

int main(){
	cin>>n>>k;
	LL d=(1LL<<k)-1;
	ans=n|d;
	for(;d<=n;d<<=1)
	 ans=min(ans,n|d);
	cout<<ans;
	return 0;
}
