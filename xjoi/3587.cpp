#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1003;
char a[N],b[N];
int f[N][N],la,lb;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	scanf("%s%s",a,b);
	la=strlen(a);lb=strlen(b);
	for(int i=1;i<=la;i++)
	 for(int j=1;j<=lb;j++){
	 	f[i][j]=max(f[i-1][j],f[i][j-1]);
	 	if (a[i-1]==b[j-1]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
	 }
	cout<<f[la][lb];
	return 0;
}
