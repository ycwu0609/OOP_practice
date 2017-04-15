#include <iostream>
using namespace std;

class Device
{
	protected:
		char name[100];
		int ID;
	public:
		Device(){
		   name[100]={NULL};
		   ID=0;
		}
		virtual void show(){cout<<name<<endl;}
		virtual char* get_name(){return name;}
		virtual int get_ID(){return ID;}
		virtual char* rename(char a[100])
		{
			for(int i=0;i<100;i++)
			{
				name[i]=a[i];
			}
		}
		
};

class CD:public Device
{
	public:
		CD(char a[100])
		{
			for(int i=0;i<100;i++){name[i]=a[i];}
			ID++;
		}
		virtual void show(){cout<<"<CD>"<<name<<endl;}
		virtual char* rename(char a[100])
		{
			for(int i=0;i<100;i++){name[i]=a[i];}
		}	
};

class HD:public Device
{
	
	public:
		HD(char a[100])
		{
			for(int i=0;i<100;i++){name[i]=a[i];}
			ID++;
		}
		virtual void show(){cout<<"<HD>"<<name<<endl;}
		virtual char* rename(char a[100])
		{
			for(int i=0;i<100;i++){name[i]=a[i];}
		}
		
};

class Host
{
	private:
		Device *d[100];
	public:
		Host(){d[100]={NULL};}
		void set(Device *a,int i){d[i]=a;}
		void show(int i){d[i]->show();}	
};

int main()
{
	Host H;
	Device* d[6];
	int num=0; 
	cout<<"Part1."<<endl; //Initiation
	
	HD h1("Western Digital-750G");
	cout<<"Device "<<num<<": ";
	h1.show();
	
	CD c1("ASUS-E818A");
	cout<<"Device "<<num<<": ";
	c1.show();

    HD h2("HITACHI-500G");
	cout<<"Device "<<num<<": ";
	h2.show();
	
	CD c2("SONY-1642");
	cout<<"Device "<<num<<": ";
	c2.show();
	
	CD c3("PHILIPS-SPD2514");
	cout<<"Device "<<num<<": ";
	c3.show();
	
	HD h3("SEAGATE-750G");
	cout<<"Device "<<num<<": ";
	h3.show();
	
	cout<<endl;
	cout<<"Part2."<<endl;
	
	d[0]=&h1;
	d[1]=&c2;
	d[2]=&c3;
	d[3]=&h2;
	d[4]=&h3;
	d[5]=&c1;
	
	for(num=0;num<6;num++)
	{	
		H.set(d[num],num);
		cout<<"Device "<<num+1<<": ";
		d[num]->show();
	}
	
	cout<<endl;
	cout<<"Part3."<<endl;
	
	h2.rename("MAXTOR-160G");
	H.set(d[3],3);
	c1.rename("PHILIPS-SPD2514");
	H.set(d[5],5);
	for(int i=0;i<6;i++)
	{
        cout<<"Device "<<i+1<<": ";
		H.show(i);
	}
    return 0;
}
