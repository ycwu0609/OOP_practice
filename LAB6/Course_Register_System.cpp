#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Course{
	friend class data;
	friend class Course_Register_System;
	friend class userdata;
	private:
		string name;
		int week_day;
		int c_time;
	public:
		Course(){
			name = "";
			week_day = 0;
			c_time = 0;
		}
		~Course(){}
		void set(string input_name, int day, int course_time){
			name = input_name;
			week_day = day;
			c_time = course_time;
		}
};

class data{
	friend class userdata;
	private:
		string schedule[5][8];
	public:
		data(){
			for(int i=0;i<5;i++) 
				for(int j=0;j<8;j++) schedule[i][j] = "";
		}
		~data(){}
		void list(){
			printf("\tMON\tTUE\tWED\tTHUR\tFRI\n");
			for(int i=0;i<8;i++){
				printf("%d\t", i+1);
				for(int j=0;j<5;j++){
					if(schedule[j][i] == "") printf("\t");
					else {
						cout<<schedule[j][i];
						printf("\t");
					}
				}
				cout<<endl;
			}
			
		}
};

class userdata{
	friend class Course_Register_System;
	private:
		string account;
		string password;
		data data;
	public:
		userdata(){
			account = "";
			password = "";
		}
		~userdata(){;}
		userdata(string input_account, string input_password){
			account = input_account;
			password = input_password;
		}
		void add(Course &C){
			int t = C.c_time;
			//check
			while(t!=0){
				int tmp = t%10;
				if(data.schedule[C.week_day-1][tmp-1] != ""){
					cout<<"Course Collide!"<<endl;
					return;
				}
				t/=10;
			}
			//add
			t = C.c_time;
			while(t!=0){
				int tmp = t%10;
				data.schedule[C.week_day-1][tmp-1] = C.name;
				t/=10;
			}
			cout<<"Success!"<<endl;
			
		}
		void list(){
			data.list();
		}
};

class Course_Register_System{	
	private:
		vector<userdata> User;
	public:
		Course_Register_System(){;}
		~Course_Register_System(){;}
		void Create_New_User(){
			string new_act, new_pwd;
			cout<<"Please Enter Your Account: ";
			while(cin>>new_act){
				for(int i=0;i<User.size();i++)
					if(User[i].account == new_act){
						cout<<"This account has been used, please change one"<<endl;
						continue;
					}
				break;
			}
			
			cout<<"Please Enter Your Passwaord(more than 6 char): ";
			while(cin>>new_pwd){
				if(new_pwd.length()>6) break;
			}
			userdata new_user(new_act, new_pwd);
			User.push_back(new_user);
			cout<<"Create!"<<endl;
		}
		int Login(){
			string act, pwd;
			cout<<"Your Account: ";
			cin>>act;
			cout<<"Your Password: ";
			cin>>pwd;
			for(int i=0;i<User.size();i++){
				if(User[i].account == act && User[i].password == pwd){
					cout<<"Login!"<<endl;
					return i;
				}
			}
			cout<<"Login Error!"<<endl;
			return -1;
		}
		void List_All_User(){
			for(int i=0;i<User.size();i++){
				cout<<User[i].account<<endl;
			}
		}
		void Choose_Course(int user_id){
			if(user_id == -1){
				cout<<"You haven't login."<<endl;
				return;
			}
			Course Course_set[6];
			
			Course_set[0].set("CO", 1, 123);
			Course_set[1].set("NP", 1, 345);
			Course_set[2].set("DS", 3, 345);
			Course_set[3].set("PL", 3, 567);
			Course_set[4].set("LA", 5, 567);
			Course_set[5].set("OS", 5, 678);
			
			string choose_course;
			cout<<"Enter which course you want to choose: ";
			cin>>choose_course;
			for(int i=0;i<6;i++){
				if(choose_course == Course_set[i].name){
					User[user_id].add(Course_set[i]);
					return;
				}
			}
			cout<<"Error: Cannot find the course."<<endl;
			
		}
		void List_schedule(int user_id){
			if(user_id == -1){
				cout<<"You haven't login."<<endl;
				return;
			}
			User[user_id].list();
		}
};


int main(){
	int comment;
	int your_num = -1;
	Course_Register_System CRS;
	cout<<"<Usage>"<<endl<<"1: Create User"<<endl<<"2: List All Users"<<endl<<"3: Login"<<endl;
	cout<<"4: Logout"<<endl<<"5: Choose Course"<<endl<<"6: List Your Schedule"<<endl;
	while(cin>>comment){
		if(comment == 1) CRS.Create_New_User();
		if(comment == 2) CRS.List_All_User();
		if(comment == 3) your_num = CRS.Login();
		if(comment == 4) {
			cout<<"Logout!"<<endl;
			your_num = -1;
		}
		if(comment == 5) CRS.Choose_Course(your_num);
		if(comment == 6) CRS.List_schedule(your_num);
	}
	return 0;
}
