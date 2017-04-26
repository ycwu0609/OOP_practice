#include <iostream>
#include <vector>
using namespace std;

class Device{
	friend class Host;
	protected:
		int mount_ID;
		string name;
	public:
		Device();
		virtual void show();	
};

class CD:public Device{
	public:
		CD(string input_name);
		virtual void show();
		
};

class HD:public Device{
	public:
		HD(string input_name);
		virtual void show();
};

class Host{
	private:
		vector<Device*> device_set;
	public:
		Host(){}
		void set(Device *d);
		void show(int id);
		void rename(string input_name, int id);
};


int main(){
	vector<Device*> vec;
	Host H;
	int num=0; 
	cout<<"Part1."<<endl; //Initiation
	
	HD h1("Western Digital-750G");
	cout<<"Device "<<num<<": ";
	vec.push_back(&h1);
	h1.show();
	
	CD c1("ASUS-E818A");
	cout<<"Device "<<num<<": ";
	vec.push_back(&c1);
	c1.show();

    HD h2("HITACHI-500G");
	cout<<"Device "<<num<<": ";
	vec.push_back(&h2);
	h2.show();
	
	CD c2("SONY-1642");
	cout<<"Device "<<num<<": ";
	vec.push_back(&c2);
	c2.show();
	
	CD c3("PHILIPS-SPD2514");
	cout<<"Device "<<num<<": ";
	vec.push_back(&c3);
	c3.show();
	
	HD h3("SEAGATE-750G");
	cout<<"Device "<<num<<": ";
	vec.push_back(&h3);
	h3.show();
	
	cout<<endl;
	cout<<"Part2."<<endl;
	
	H.set(&h1);
	H.set(&c2);
	H.set(&c3);
	H.set(&h2);
	H.set(&h3);
	H.set(&c1);
	
	for(int i=0;i<6;i++){
		cout<<"Device "<<i+1<<": ";
		vec[i]->show();
	}
		
	
	cout<<endl;
	cout<<"Part3."<<endl;
	H.rename("MAXTOR-160G", 4);
	H.rename("PHILIPS-SPD2514", 6);
	for(int i=0;i<6;i++){
		cout<<"Device "<<i+1<<": ";
		H.show(i);
	}	
	return 0;
}

//---Device func---//
Device::Device(){
	mount_ID = -1;
	name = "";
}
void Device::show(){
	cout<<name<<endl;
}
//---CD finc---//
CD::CD(string input_name){
	name = input_name;
	mount_ID++;
}
void CD::show(){
	cout<<"<CD> "<<name<<endl;
}
//---HD func---//
HD::HD(string input_name){
	name = input_name;
	mount_ID++;
}
void HD::show(){
	cout<<"<HD> "<<name<<endl;
}
//---Host func---//
void Host::set(Device *d){
	device_set.push_back(d);
}
void Host::show(int id){
	device_set[id]->show();
}
void Host::rename(string input_name, int id){
	device_set[id-1]->name = input_name;
}


