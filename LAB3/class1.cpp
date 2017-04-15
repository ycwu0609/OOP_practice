#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Students_Data
{
private:
    int height;
    char *name;
public:
   Students_Data(){
   	height=0;
   	name=NULL;
   	cout<<"constructor1 called!"<<endl;
   }
   Students_Data (int c,char* b)
   {
   	name=b; 
   height=c;
   cout<<"constructor2 called!"<<endl;
   }
   void set_name(char* b){name=b;}
   void set_height(int c){height=c;}
   char* get_name() {return name;}
   int get_height() {return height;};
   Students_Data(const Students_Data &a){
   name=a.name;
   height=a.height;
   cout<<"copy constructor called!"<<endl;}
   ~Students_Data(){
       delete[] name;
       delete[] &height;
       cout<<"destructor called!"<<endl;
    };
	   }; /*** your code ***/


int main()
{
   int a,i,j;
   char* s;
    /*** part I ***/
    Students_Data S1();
    Students_Data S2(160, "Tony");
    Students_Data S3 = S2;

    /*** part II ***/
	cout<<S3.get_name()<<" "<<S3.get_height()<<endl;/// print the name and height of S3 before setting
     
	 S3.set_name("Jeff");
	 S3.set_height(180);
	 /// change the name and height of S3 into Jeff and 180
     
	 cout<<S3.get_name()<<" "<<S3.get_height()<<endl; /// print the name and height of S3 after setting

    /*** part III ***/
    Students_Data Data[5];
    cout << "before sorting : "  << endl;
    /***
    set Data with name A B C D E
    set their height with rand() function between 150~180
    print the name and height of students from Data[0] to Data [4];
    ***/
    Data[0].set_name("A");
    Data[1].set_name("B");
    Data[2].set_name("C");
    Data[3].set_name("D");
    Data[4].set_name("E");
	for(i=0;i<5;i++)
    {
    	int hei;
    	hei=rand()%31+150;
		Data[i].set_height(hei);
    	cout<<Data[i].get_name()<<" "<<Data[i].get_height()<<endl;
    }
    /*** your code ***/

    /*** sort 5 students with height ***/
    /*** your code ***/
    for(i=4;i>0;i--)
    {for(j=0;j<i;j++)
    {
    if(Data[j+1].get_height()<Data[j].get_height())
    {
    	int m;
    	char* n;
    	m=Data[j].get_height();
    	n=Data[j].get_name();
		Data[j].set_name(Data[j+1].get_name());
		Data[j].set_height(Data[j+1].get_height());
		Data[j+1].set_name(n);
		Data[j+1].set_height(m);
		
    }
    
    }
    }
	
	cout << "after sorting : " << endl;
    /*** print student's name and height after sorting ***/
    /*** your code ***/
    for(i=0;i<5;i++)
    {
    	cout<<Data[i].get_name()<<" "<<Data[i].get_height()<<endl;
    }
    return 0;
}
