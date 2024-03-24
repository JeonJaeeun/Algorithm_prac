#include<cstdio>
#include<string.h>
int n,m,p,a,v[26];
char d[27],b;
int main(){
	scanf("%d %d",&n,&m);
	memset(d,'?',sizeof(char)*n);
	while(m--){
		scanf("%d %c",&a,&b);
		a%=n;
		p-=a;
		if(p<0)p=n+p;
		if((d[p]!='?'&&d[p]!=b)||(v[b-'A']&&d[p]!=b)){
			printf("!");
			return 0;
		}
		d[p]=b;
		v[b-'A']=1;
	}
	for(m=0;m<n;m++){
		if(p+m>=n)p=-m;
		printf("%c",d[p+m]);
	}
}