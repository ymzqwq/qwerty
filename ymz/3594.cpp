#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int n,pr[N],L;
bool b[N*10];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		if (!b[i]) pr[++L]=i;
		for(int j=1;j<=L&&i*pr[j]<=n;j++){
			b[i*pr[j]]=1;
			if (i%pr[j]==0) break;
		}
	}
	cout<<L;
	return 0;
}
