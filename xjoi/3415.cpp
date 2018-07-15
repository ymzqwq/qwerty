#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=101;
LL ans,n;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	cin>>n;
	for(int i=2;i*i<=n;i++){
		int j=n/i;
		if (i+1<=j) ans=ans+1LL*(i+j+1)*(j-i)/2;
		ans+=1LL*i*(j-i+1);
	}
	cout<<ans;
	return 0;
}
