#include <string.h> 
#include <iostream>	
using namespace std;
bool se(char s[])
{
	int len=strlen(s);
	for(int i=0;i<len;i++)
	if(s[i]=='A')
	for(int j=0;s[j]==' '||s[j]=='l';j++)
	if(s[j]=='l')
	for(int m=0;s[m]==' '||s[m]=='a';m++)
	if(s[j]=='a')
	for(int n=0;s[n]==' '||s[n]=='n';n++)
	if(s[j]=='n') return 1;
	return 0;
}
int main()
{
	char c;
	int n;
	int ans=0;
	int sum=0;
	char s[1010];
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		int j=0;
		while(scanf("%c", &c)&&c != '\n')
		{
			s[j++]=c;
			if(c=='%')	sum++;
		}
		s[j]='\0';
		if(se(s)) ans+=sum;
		sum=0;
	}
	cout<<ans<<endl;
}