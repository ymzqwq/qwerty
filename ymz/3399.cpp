#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,a[N],A,sum;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(A);
	for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
	for(int i=1;i<=n;i++){
		LL mn=max(A-(sum-a[i]),1LL),mx=min(A-(n-1),a[i]);
		cout<<a[i]-(mx-mn+1)<<' ';
	}
	return 0;
}
