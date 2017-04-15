#include <iostream>
using namespace std;


class PolySeq
{
	public:
		PolySeq operator -(PolySeq p);
		PolySeq operator *(PolySeq p);
		void print();
		int set_num(int a){num_of_terms=a;}
		int get_num_of_terms(){return num_of_terms;}
		void set_coe(int* s);
		int* get_coe(){return coe;}
		void set_exp(int* s);
		int* get_exp(){return exp;}
		int GetValue(int x);
	private:
	    int coe[100];
		int exp[100];
		int num_of_terms;	
};

ostream& operator<<(ostream& out,PolySeq p)
{
	int a=p.get_num_of_terms();
	out<<p.get_coe()[0]<<" ";
	out<<"X^"<<a-1;
	for(int i=1;i<a;i++)
	{
		if(p.get_coe()[i]==0)
		{
			continue;
		}
		out<<" +";
		out<<p.get_coe()[i]<<" ";
		out<<"X^"<<a-1-i;
    }
	out<<endl;
	return out;
}
int main()
{
	int a,c1[100],e1[100];
	int b,c2[100],e2[100];
	int x;
	PolySeq Poly1;
	PolySeq Poly2;
	PolySeq Poly3;
	PolySeq Poly4;
	PolySeq Poly5;
	cout<<"Enter Num of Terms of Poly1:"<<endl;
	cin>>a;
	Poly1.set_num(a);
	//set num
	cout<<"Enter Coefficients of Poly1:"<<endl;
	for(int i=0;i<a;i++)
	{
		cin>>c1[i];
	}
	Poly1.set_coe(c1);
	//set coe
	cout<<"Enter Exponentials of x in Poly1<from high to low>:"<<endl;
	for(int i=0;i<a;i++)
	{
		cin>>e1[i];
	}
	Poly1.set_exp(e1);
	//set exp
	
	cout<<"Enter Num of Terms of Poly2:"<<endl;
	cin>>b;
	Poly2.set_num(b);
	//set num
	
	cout<<"Enter Coefficients of Poly2:"<<endl;
	for(int i=0;i<b;i++)
	{
		cin>>c2[i];
	}
	Poly2.set_coe(c2);
	//set coe
	
	cout<<"Enter Exponentials of x in Poly2<from high to low>:"<<endl;
	for(int i=0;i<b;i++)
	{
		cin>>e2[i];
	}
	Poly2.set_exp(e2);
	//set exp
	
	cout<<"Enter the value of x:"<<endl;
	cin>>x;
	
	cout<<"P1-P2: ";
	Poly3=Poly1-Poly2;
	cout<<Poly3;
	
	cout<<"P2-P1: ";
	Poly4=Poly2-Poly1;
	cout<<Poly4;
	
	cout<<"P1*P2: ";
	Poly5=Poly1*Poly2;
	cout<<Poly5;
	
	cout<<"P1<x1>: ";
	cout<<Poly1.GetValue(x)<<endl;
	
	cout<<"P2<x1>: ";
	cout<<Poly2.GetValue(x)<<endl;
	
	cout<<"<P1-P2><x1>: ";
	cout<<Poly3.GetValue(x)<<endl;
	
	cout<<"<P2-P1><x1>: ";
	cout<<Poly4.GetValue(x)<<endl;
	
	cout<<"<P1*P2><x1>: ";
	cout<<Poly5.GetValue(x)<<endl;
	return 0;
}
void PolySeq::set_coe(int* s)
{
	for(int i=0;i<num_of_terms;i++)
	{
		coe[i]=s[i];
	}
}

void PolySeq::set_exp(int* s)
{
	for(int i=0;i<num_of_terms;i++)
	{
		exp[i]=s[i];
	}
}



PolySeq PolySeq::operator -(PolySeq p)
{   
    int a;
	a=num_of_terms;
	PolySeq result;
	int i=a-1;
	int j=p.get_num_of_terms()-1;
	int b=p.get_num_of_terms()-a;
	
	while(i>=0&&j>=0)
	{
	
		result.coe[i]=coe[i]-p.coe[j];
	    i--;
	    j--;
	}
	if(b>0)
	{
		result.coe[j]=0-p.coe[j];
		result.set_num(b+a);
	}
	for(i;i>=0;i--)
	{
		result.coe[i]=coe[i];
	
	result.set_num(a);
    }
	return result;
	
}

PolySeq PolySeq::operator *(PolySeq p)
{
	int a,b,i,j;
	a=num_of_terms;
	b=p.get_num_of_terms();
	PolySeq result;
	for(i=0;i<100;i++)
	{
		result.coe[i]=0;
	}
	for(i=0;i<a;i++)
	{for(j=0;j<b;j++)
		{
		result.coe[i+j]+=coe[i]*p.coe[j];
	    }
	}
	result.set_num(i+j-1);
	return result;
}

int PolySeq::GetValue(int x)
{
	int a=num_of_terms,sum[100]={0},result=0,i,j;
	for(i=0;i<a;i++)
	{
		sum[i]+=coe[i];
		for(j=a-1;j>i;j--)
		{
			sum[i]*=x;
		}
		
		result+=sum[i];
	}
	return result;
}
