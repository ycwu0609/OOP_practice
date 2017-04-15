#include <iostream>
using namespace std;

class Data
{
	char name[100];
	public:
		void setname(char* a){strcpy(name,a);}
		char* getname(){return name;}
		friend class course;
	
};
class course
{
	char name[100];
	char course[100][4];
	public:
		void setname(Data a){strcpy(name,a.name);}
		void setcourse(char a[100][4]){
		for(int i=0;i<100;i++)
		{for(int j=0;j<4;j++)
		{
			strcpy(course[i],a[i]);
		}
		}}
		char* getcourse(){return course[100];}
};

int main()
{
	Data data[100];
	course course[100];
	int count=0,j=0,q,i;
	char course1[100][4];
	
	
		int a1;
		do
		{
		cout<<"press 0 for new user register.press 1 for login:";
		cin>>a1;
		
		if(a1==0)
		{
			char name[100];
			cout<<"enter name:";
			cin>>name;
			data[count].setname(name);
			course[count].setname(data[count]);
			cout<<"user "<<name<<" have been created!"<<endl;
			count++;
		}
		else if(a1==1)
		{
			int course[5][8];
			char name[100];
			cout<<"name:";
			cin>>name;
			for(q=0;q<count;q++)
			{
				if(strcmp(name,data[q].getname())==0)
				{
					break;
				}
			}
			if(strcmp(name,data[q].getname())!=0)
			{
			cout<<"there is no this user."<<endl;
		    }
		    else
		    {
			cout<<"welcome!"<<name<<endl;
			
			int a2;
			
			do
			{
			cout<<"press 2 for choose course. press 3 for showing course. press 4 to logout:";
			cin>>a2;
			if(a2==1)
			{
				cout<<"allow one user at the same time!"<<endl;
			}
			if(a2==2)
			{
			    int course2[5][8]={0};
				char tmp[4];	
				do
				{
					cout<<"enter course name:";
					cin>>tmp;
					if(strcmp(tmp,"CO")==0)
					{
						for(i=0;i<3;i++)
						{
							course2[0][i]++;
							if(course2[0][i]>1)
							{
								
								cout<<"overlap!"<<endl;
								break;
							}
						}
						if(course2[0][i]>1)
						{
						;
					    }
					    else
					    {
					    strcpy(course1[j],tmp);
						cout<<"CO choosed"<<endl;
					    j++;
					}
				}
					else if(strcmp(tmp,"NP")==0)
					{
						for(i=2;i<5;i++)
						{
							course2[0][i]++;
							if(course2[0][i]>1)
							{
								
								cout<<"overlap!"<<endl;
								break;
							}
						}
						if(course2[0][i]>1)
						{
						;
					    }
					    else
					    {
						strcpy(course1[j],tmp);
						cout<<"NP choosed."<<endl;
					    j++;
					    }
					}
					else if(strcmp(tmp,"DS")==0)
					{
						for(i=2;i<5;i++)
						{
							course2[2][i]++;
							if(course2[2][i]>1)
							{
								
								cout<<"overlap!"<<endl;
								break;
							}
						}
						if(course2[2][i]>1)
						{
						;
					    }
					    else
					    {
						strcpy(course1[j],tmp);
						cout<<"DS choosed."<<endl;
					    j++;
					    }
					}
					else if(strcmp(tmp,"PL")==0)
					{
						for(i=4;i<7;i++)
						{
							course2[2][i]++;
							if(course2[2][i]>1)
							{
								
								cout<<"overlap!"<<endl;
								break;
							}
						}
						if(course2[2][i]>1)
						{
						;					
						}
						else
						{
							strcpy(course1[j],tmp);
							cout<<"PL choosed."<<endl;
							j++;
						}
					}
					else if(strcmp(tmp,"LA")==0)
					{
						for(i=4;i<7;i++)
						{
							course2[4][i]++;
							if(course2[4][i]>1)
							{
								
								cout<<"overlap!"<<endl;
								break;
							}
						}
						if(course2[4][i]>1)
						{
						;
					    }
					    else
					    {
						strcpy(course1[j],tmp);
						cout<<"LA choosed."<<endl;
					    j++;
					    }
					}
					else if(strcmp(tmp,"OS")==0)
					{
						for(i=5;i<8;i++)
						{
							course2[4][i]++;
							if(course2[4][i]>1)
							{
								
								cout<<"overlap!"<<endl;
								break;
							}
						}
						if(course2[4][i]>1)
						{
						;
					    }
					    else
					    {
						strcpy(course1[j],tmp);
						cout<<"OS choosed."<<endl;
					    j++;
					    }
					}
					else if(strcmp(course1[j],"END")==0)
					{
						break;
					}
				}
				while(strcmp(tmp,"END")!=0);
//			    course[q].setcourse(course1[100][4]);
			}
			if(a2==3)
			{
				for(int z=0;z<j;z++)
				{
					cout<<course1[z]<<" ";
					if(strcmp(course1[z],"CO")==0)
					{
						cout<<"MON 123"<<endl;
					}
					else if(strcmp(course1[z],"NP")==0)
					{
						cout<<"MON 345"<<endl;
					}
					else if(strcmp(course1[z],"DS")==0)
					{
						cout<<"WED 345"<<endl;
					}
					else if(strcmp(course1[z],"PL")==0)
					{
						cout<<"WED 567"<<endl;
					}
					else if(strcmp(course1[z],"LA")==0)
					{
						cout<<"FRI 567"<<endl;
					}
					else if(strcmp(course1[z],"OS")==0)
					{
						cout<<"FRI 678"<<endl;
					}
				}
				
			}
			if(a2==4)
			{
				cout<<"logout!"<<endl;
				break;
			}
		}
		while(a2!=4);
	    }
		}
	}while(1);
	return 0;	
	}
	

