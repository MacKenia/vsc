#include<stdio.h>

int main()
{
	int i,j,a=0,b=0,c=0;
	for(i='A';i<'D';i++){
		for(j='X';j<='Z';j++){
			if(i=='A'&&j=='X'||i=='C'&&j=='X'||i=='C'&&j=='Z') continue;
			else switch(i){
				case'A': a+=j;break;
				case'B': b+=j;break;
				case'C': c+=j;break;
				}
//			printf("%c\n",a);
//			if(i=='A'&&j=='X'||i=='C'&&j=='X'||i=='C'&&j=='Z') continue;
//			else 
		}
	}
//	printf("%d\n",a);
//	printf("%d\n",b);
//	printf("%d\n",c);
	if(a>b){
		if(c>b){
			if(c>a){a=a-b;c=c-a-b;}
			else{c=c-b;a=a-c-b;}
		}
		else{b=b-c;a=a-b-c;}
	}
	else {
		if(c>a){
			if(c>b){b=b-a;c=c-b-a;}
			else{c=c-a;b=b-c-a;}
		}
		else{a=a-c;b=b-a-c;}
	}
	printf("A-->%c\n",a);	
	printf("B-->%c\n",b);
	printf("C-->%c\n",c);
	return 0;
	
}


