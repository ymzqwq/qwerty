#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,phi[N];
LL ans;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) phi[i]=i;
	for(int i=2;i<=n;i++){
		if (phi[i]==i){
			phi[i]--;
			for(int j=2*i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);
		}
	}
	for(int i=2;i<=n;i++) ans+=phi[i];
	cout<<ans<<endl;
	return 0;
}
