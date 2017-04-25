#include <iostream>
using namespace std;

class student_data{
	private:
		int height;
		string name;
	public:	
		student_data(){
			//constructor
			//cout<<"constructor 1!"<<endl;
			height = 0;
			name = "";
		}
		student_data(int input_height, string input_name){
			//constructor
			//cout<<"constructor 2!"<<endl;
			height = input_height;
			name = input_name;
		}
		student_data(const student_data &tmp){
			//cout<<"copy constructor!"<<endl;
			name = tmp.name;
			height = tmp.height;
		}
		void set_value(int new_height, string new_name){
			height = new_height;
			name = new_name;
		}
		string get_name(){return name;}
		int get_height(){return height;}
		~student_data(){
			//cout<<"destructor!"<<endl;
		}
};

ostream& operator<<(ostream& out, student_data S){
	out<<S.get_name()<<" "<<S.get_height();
	return out;
}

int main(){
	
	/*** Part 1 ***/
	student_data S1;
	student_data S2(160, "Tony");
	student_data S3 = S2;
	
	/*** Part 2 ***/
	cout<<S3<<endl;
	//cout<<"S3: "<<S3.get_name()<<" "<<S3.get_height()<<endl;
	S3.set_value(180, "Jeff");
	cout<<"After Change: ";
	cout<<S3<<endl;
	
	/*** Part 3 ***/
	student_data data_set[5];
	cout<<"Before Sorting:"<<endl;
	for(int i=0;i<5;i++){
		int set_height = rand()%31+150;
		string set_name;
		if(i == 0) set_name = "A";
		else if(i == 1) set_name = "B";
		else if(i == 2) set_name = "C";
		else if(i == 3) set_name = "D";
		else set_name = "E";	
		data_set[i].set_value(set_height, set_name);
		cout<<data_set[i]<<endl;
	}
	
	for(int i = 4; i > 0; i--){
		for(int j = 0;j < 5; j++){
			if(data_set[j+1].get_height()<data_set[j].get_height()){
				swap(data_set[j], data_set[j+1]);
				
			}
		}
	}
	cout<<"After Sorting:"<<endl;
	for(int i = 0; i < 5; i++) 
		cout<<data_set[i]<<endl;
	
	
	return 0;
}
