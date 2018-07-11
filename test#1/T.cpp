#include<bits/stdc++.h>
using namespace std;
const int N=100001;
const int M=26;
int n,a[N],f[2][N],ans,x,y;
set<int> s;

inline void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++){
		x|=a[i];
		if (!s.count(x)){
			s.insert(x);
			ans++;
		}
	}
	for(int i=2;i<=n;i++){
		x=a[i];y=a[i-1];
		int j=i;
		while(x!=y&&j<=n){
			x|=a[j];y|=a[j];
			if (!s.count(x)){
				s.insert(x);
				ans++;
			}
			j++;
		}
	}
	cout<<ans;
	return 0;
}
