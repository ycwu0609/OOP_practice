#include <iostream>
#include <fstream>
using namespace std;

class binary
{
	private:
		char name[100];
		char num[100];
		int len;
	public:
	binary()
	{
		name[100]={NULL};
		num[100]={NULL};
		len=0;
	}
	void set_name(char *a)
	{
		strcpy(name,a);
	}
	void set_num(char* a)
	{
		len=strlen(a);
		strcpy(num,a);
	}
	char* get_name(){return name;}
	char* get_num(){return num;}
	int decimal()
	{
		int i=1,sum=0,count=0,tmp;
		for(count=len-1;count>=0;count--)
		{
			tmp=(num[count]-'0')*i;
			sum+=tmp;
			
			i*=2;
		}
		return sum;
	}
};

int main()
{
	char a[100];
	char b[100];
	binary B[5];
	binary T;
	int i=0;
	
	fstream file;
	file.open("input.txt",ios::in);
	while(file.eof()!=1)
	{
		file>>a;
		B[i].set_name(a);
		cout<<B[i].get_name()<<" ";
		file>>b;
		B[i].set_num(b);
		cout<<B[i].get_num()<<" ";
		cout<<B[i].decimal()<<endl;
		i++;
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{for(int j=4;j>i;j--)
	{
		if(B[j].decimal()<B[j-1].decimal())
		{
			T=B[j];
			B[j]=B[j-1];
			B[j-1]=T;
		}
	}
	}
	
	for(int i=0;i<5;i++)
	{
		cout<<B[i].get_name()<<" ";
		cout<<B[i].decimal()<<endl;
	}
	
	fstream fout("output.txt",ios::out);
	for(int i=0;i<5;i++)
	{
		fout<<B[i].get_name()<<" ";
		fout<<B[i].get_num()<<endl;
	}
	file.close();
	return 0;
}
