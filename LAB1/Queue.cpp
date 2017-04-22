#include <stdio.h>

int main(void)
{
	int Queue[5];
	int front,rear,s;
	front=rear=-1;	
	do
	{
		int n;
		printf("1.push 2.pop 3.print 4.exit:");
		scanf("%d",&s);
		if(s==1){
			scanf("%d",&n);
	        	if(rear>=4)
	        		printf("full\n");
            		else{
    	      			rear++;
			  	Queue[rear]=n;
            		}
		}
		else if(s==2){
			front++;
			if(rear<0)
				printf("empty\n");
			else{
				rear--;
				printf("%d\n",Queue[0]);
				for(int i=0;i<=rear;i++)	
				   	Queue[i]=Queue[i+1];
				Queue[rear+1]=NULL;
			}
		}
		else if(s==3){
			for(int j=0;j<=4;j++)
				printf("%d ",Queue[j]);
			
		   	printf("\n");
		}
		else
			break;
		
	}
	while(s>=0);
	
}
