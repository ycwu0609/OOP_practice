#include <iostream>
#include <string.h>
using namespace std;

class userdata{
	private:
		string name;
		char zipcode[10];
	public:
		userdata(){
			name = "";
			//zipcode = NULL;
		}
		userdata(string input_name, char input_zipcode[10]){
			name = input_name;
			strcpy(zipcode, input_zipcode);
		}
		void set_value(string input_name, char input_zipcode[10]){
			name = input_name;
			strcpy(zipcode, input_zipcode);
		}
		string get_name(){return name;}
		char* get_zipcode(){return zipcode;}
		userdata operator+(userdata U){
			for(int i=0;i<6;i++){
				if(i == 3) continue;
				zipcode[i] += (U.zipcode[i]-'0');
			}
		}		
};

ostream& operator<<(ostream& out, userdata U){
	out<<U.get_name()<<" "<<U.get_zipcode();
	return out;
}

int main(){
	int user_cnt = 0;;
	userdata data_set[100];
	userdata New_data;
	int comment;
	do{
		cin>>comment;
		if(comment == 0){
			//create user
			cout<<"Enter new user name: ";
			string new_user_name;
			cin>>new_user_name;
			data_set[user_cnt++].set_value(new_user_name, "");
			cout<<"User Created: "<<data_set[user_cnt-1]<<endl;
		}
		else if(comment == 1){
			//set zipcode
			cout<<"Set zipcode."<<endl;
			int i;
			string search_user_name;
			cout<<"Enter exist user name: ";
			cin>>search_user_name;
			for(i = 0; i < user_cnt; i++){
				if(data_set[i].get_name() == search_user_name) break;
			}
			if(i >= user_cnt)
				cout<<"There is no that user."<<endl;
			else {
				char new_zipcode[10];
				cin>>new_zipcode;
				data_set[i].set_value(data_set[i].get_name(), new_zipcode);
			}
			cout<<data_set[i]<<endl;
		}
		else if(comment == 2){
			//add 2 user's zipcode
			int i, j;
			string user1, user2;
			cout<<"Enter User 1: ";
			while(cin>>user1){
				for(i = 0; i < user_cnt; i++){
					if(data_set[i].get_name() == user1) break;
				}
				if(i<user_cnt) break;
				cout<<"The user doesn't exist."<<endl;
			}
			cout<<"Enter User 2: ";
			while(cin>>user2){
				for(j = 0; j < user_cnt; j++){
					if(data_set[j].get_name() == user2) break;
				}
				if(j<user_cnt) break;
				cout<<"The user doesn't exist."<<endl;
			}
			data_set[i] + data_set[j];
			cout<<data_set[i]<<endl;
			cout<<data_set[j]<<endl;
		}
		else if(comment == 3){
			//List
			cout<<"List all user."<<endl;
			for(int i = 0;i < user_cnt; i++){
				cout<<data_set[i]<<endl;
			}
		}
		else if(comment == 4) break;
	}
	while(1);
	return 0;
}
