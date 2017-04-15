#include <iostream>
#include <string.h>
using namespace std;

class UserData
{
	private:
		char name[128];
		char zipcode[128];
	public:
	    void SetName(char* c){strcpy(name, c);}
		void SetZipcode(char* c){strcpy(zipcode,c);}
		char* Getname(){return name;}
		char* Getzipcode(){return zipcode;}
		void operator+(UserData U)
		{
			for(int i=0;i<6;i++)
			{
				if(i==3)
				{
					continue;
				}
				zipcode[i]+=(U.zipcode[i]-'0');
			}
		}
		UserData& operator=(UserData U)
		{
			strcpy(name,U.name);
			strcpy(zipcode,U.zipcode);
			return *this;
		}
		
};


int main()
{
	int i=0;
	UserData Data[100];
	UserData New;
	int a;
	
	do
	{
	cin>>a;
	if(a==0)
	{
		char c[128];
		cin>>c;
		Data[i].SetName(c);
		cout<<"User Created."<<endl;
		i++;
	}
	else if(a==1)
	{
		int j;
		char d[128];
		cin>>d;
		for(j=0;j<i;j++)
		{
		if(strcmp(d,Data[j].Getname())==0)
		{
			break;
		}
		
		}
		if(strcmp(d,Data[j].Getname())!=0)
		{
			cout<<"There is no that user."<<endl;
		}
		else
		{
	    char e[128];
		cin>>e;
		Data[j].SetZipcode(e);
		cout<<"User's name:"<<Data[j].Getname()<<endl;
		cout<<"Zipcode:"<<Data[j].Getzipcode()<<endl;
	}
	}
	else if(a==2)
	{
		int z,x;
		char g[128];
		char h[128];
		cin>>g;
		for(z=0;z<i;z++)
		{
		if(strcmp(g,Data[z].Getname())==0)
		{
			break;
		}
		}
		cin>>h;
		for(x=0;x<i;x++)
		{
		if(strcmp(h,Data[x].Getname())==0)
		{
			break;
		}
		}
		Data[z]+Data[x];
		cout<<"User's name:"<<Data[z].Getname()<<endl;
		cout<<"Zipcode:"<<Data[z].Getzipcode()<<endl;
		cout<<"User's name:"<<Data[x].Getname()<<endl;
		cout<<"Zipcode:"<<Data[x].Getzipcode()<<endl;
	}
	else if(a==3)
	{
		int b,p[100],e,digit;
	    int sum[100]={0};
		for(b=0;b<i;b++)
		{
		
			cout<<"User's name:"<<Data[b].Getname()<<endl;
			for(int q=0;q<6;q++)
			{
				if(q==3)
				{
					continue;
				}
				digit=Data[b].Getzipcode()[q]-'0';
				sum[b]+=digit;
			}
			cout<<"Sum:"<<sum[b]<<endl;
		}
		for(b=0;b<i;b++)
		{
			int tmp1;
			char tmp2[128];
			if(sum[b]>sum[b+1])
			{
				tmp1=sum[b];
				sum[b]=sum[b+1];
				sum[b+1]=tmp1;
				
				strcpy(tmp2,Data[b].Getname());
				Data[b]=Data[b+1];
				Data[b+1].SetName(tmp2);
			}
		}
		for(b=i;b>=0;b--)
		{
			cout<<Data[b].Getname();
			if(b>0)
			{
				cout<<">";
			}
		}
	
	}
	else
	{
		continue;
	}
    }
	while(a!=4);
	return 0;
}
