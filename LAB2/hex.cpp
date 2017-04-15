#include <iostream>
#include<string.h>
using namespace std;



int main(int argc, char*argv[])
{
   int i,j;
   int b=1;
   int s[100];
   for(i=1;i<argc;i++){
   	cout<<argv[i]<<' ';
   }
   s[0]=(argv[1][0]-'0')*16+argv[1][1]+10-'A';
   for(i=2;i<argc;i++){
   	int a=0;
   	switch(argv[i][0])
   	{
   	case '+':
   		s[b-2]=s[b-1]+s[b-2];
   			b--;
   		break;	
   	case '-':
	   	s[b-2]=s[b-2]-s[b-1];
   			b--;
   			break;
	case 'x':
		s[b-2]=s[b-2]*s[b-1];
   			b--;
   			break;
	case '/':
		s[b-2]=s[b-2]/s[b-1];
   			b--;	
		    break;
	default:		   	   	
 
   		for(j=0;argv[i][j]!='\0';j++){
   		a*=16;
	   		if('0'<=argv[i][j]&&argv[i][j]<='9'){
	   			a+=argv[i][j]-'0';
	   		}
	   		else if('A'<=argv[i][j]&&argv[i][j]<='F'){
	   			a+=argv[i][j]-'A'+10;
	   		}
	
   		}
   		s[b]=a;
   		b++;
   	
   }
   }
   cout<<" = ";
   cout<<(hex)<<s[0];
   return 0;
}
