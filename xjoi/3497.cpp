#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=26;
int a[N][N],b[N],rd[N];
char c[101];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	while(scanf("%s",c)>0){
		for(int i=1;i<strlen(c);i++)
		 if (c[i]!=c[i-1]){
		 	a[c[i-1]-'a'][c[i]-'a']=1;
		 	rd[c[i]-'a']++;
		 }
	}
	for(int i=0;i<N;i++){
		int k=-1;
		for(int j=0;j<N;j++)
		 if (rd[j]==0&&b[j]==0){
		 	k=j;break;
		 }
		if (k==-1){
			printf("Impossible");
			return 0;
		}
		b[k]=1;
		for(int j=0;j<N;j++)
		 if (a[k][j]){
		 	a[k][j]=0;
		 	rd[j]--;
		 }
	}
	printf("Possible");
	return 0;
}
