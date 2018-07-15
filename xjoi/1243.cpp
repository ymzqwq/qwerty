#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,m,ans,sum;
char c[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(m);
	scanf("%s",c);
	if (m>2){
		for(int i=0;i<n;i++){
			int j;
			for(j=i+1;j<n;j++) if (c[j]!=c[i]) break;
			ans+=(j-i)>>1;
			i=j-1;
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++) if (c[i]!='A'+i%2) ans++;
	for(int i=0;i<n;i++) if (c[i]=='A'+i%2) sum++;
	cout<<min(sum,ans);
	return 0;
}
