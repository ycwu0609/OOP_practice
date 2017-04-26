#include "Course.h"

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
