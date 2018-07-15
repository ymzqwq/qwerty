#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=32;
LL n,f[N][2];

int main(){
	cin>>n;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=(f[i-1][0]+f[i-1][1])*3;
		f[i][1]=f[i-1][0];
	}
	cout<<f[n][0]+f[n][1];
	return 0;
}
