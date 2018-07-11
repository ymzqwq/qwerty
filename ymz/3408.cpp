#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,a[N],mx,tot[N];
LL sum,ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		sum+=a[i];tot[a[i]]++;
		ans+=a[i]*(i-tot[a[i]]-tot[a[i]-1]-tot[a[i]+1]);
		ans-=sum-a[i]*tot[a[i]]-(a[i]-1)*tot[a[i]-1]-(a[i]+1)*tot[a[i]+1];
	}
	cout<<ans;
	return 0;
}
