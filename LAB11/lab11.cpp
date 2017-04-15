#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

class student
{
private:
    char name[10];
    int height;
public:
	void set(char *n,int h)
	{
		strcpy(name,n);
		height=h;
		cout<<n<<" "<<height<<endl;
	}
	~student()
	{
		delete [] name;
	}
	char* get_name(){return name;}
	int get_hei(){return height;}
};

/**
your_sort with template
**/
template <class A>
void your_sort(A a)
{
	int i,j;
	double tmp;
	for(i=0;i<10;i++)
	{for(j=10-1;j>i;j--)
	{
		if(a[j-1] > a[j])
		{
			tmp=a[j-1];
			a[j-1]=a[j];
			a[j]=tmp;
		}
	}
	}
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
    /**********part A***********/
    srand(time(NULL));
	vector<int> part_a_int;
    vector<double> part_a_double;
    /// random 10 integer numbers yourself from 0 to 100
    for(int i=0;i<10;i++)
    {
    	int ran;
    	ran=(int)rand()%100;
    	part_a_int.push_back(ran);
    }
    your_sort(part_a_int);

    /// random 10 double numbers yourself
    /// hint put (double) before rand()
   for(int i=0;i<10;i++)
    {
    	double ran;
    	ran=(double)rand()/1000;
    	part_a_double.push_back(ran);
    }
    your_sort(part_a_double);

    /**********part B***********/
    /// set 10 students A B C D E F G H I J
    /// set their height using random function from 150 to 180
    /// show the data
    /// delete the shortest one /// find the function in the c++ reference
    /// sort the result and show
    vector<student> data(10);
    char c[10];
    student tmp;
    int count=0;
	for(int i=0;i<10;i++)
    {
		int h= rand()%31+150;
		cin>>c;
		data[i].set(c,h);
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
    	cout<<data[i].get_name()<<" "<<data[i].get_hei()<<endl;
    }
    for(int i=0;i<10;i++)
    {
    	if(data[count].get_hei()<data[i].get_hei())
    	{
    		count=i;
    	}
    }
	for(int i=0;i<10;i++)
    {
    	for(int j=10-1;j>i;j--)
    	{
    		if(data[j-1].get_hei()>data[j].get_hei())
    		{
    			tmp=data[j-1];
    			data[j-1]=data[j];
    			data[j]=tmp;
    		}
    	}
    }
    
    
    cout<<endl;
    data.erase(data.begin()+count-1);
    
    for(int i=0;i<9;i++)
    {
    	cout<<data[i].get_name()<<" "<<data[i].get_hei()<<endl;
    }
    return 0;
}
