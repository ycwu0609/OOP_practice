#include<iostream>
#include"vec.h"
using namespace std;
///
///Stack & Queue must inherit protected vec
///
class Stack:protected vec
{
	private:
		int top=-1;
	public:	
	    Stack(int a):vec(a){;}
	    void Push(int a){
	    	top++;
	    	if(top<get_size()){
			set(top,a);
	        }
	        else{
	        	cout<<"full"<<endl;
	        	top--;
	        }
	    }
	    int Top(){
	    	return get_data(top);
	    }
	    void Pop()
	    {
	    	
			if(top>=0)
	    	{
			
			set(top,NULL);
			top--;
		    }
		    else
			{
		    	cout<<"empty";
		    }
	    }
	    int isEmpty()
	    {
	    	if(top==-1)
			{
	    		return 1;
	    	}
	    	else
			{
	    		return 0;
	    	}
	    }
};

class Queue:protected vec
{
	private:
		int front=0,rear=0;
	public:
		Queue(int a):vec(a){;}
		Queue(Queue& q):vec(q.get_size())
		{
			
			front=0;
			rear=q.rear;
			for(int i=0;i<rear;i++){
				set(i,q.get_data(i));
			}
		}
		void Push(int n){
			if(rear<=get_size()-1)
			{
			set(rear,n);
			rear++;
		    }
		    else
		    {
		    	cout<<"full"<<endl;
		    }
		}
		void Pop(){
			set(front,NULL);
			if(rear>front){
			for(int i=front+1;i<=rear;i++)
			{
				set(i-1,get_data(i));
			}
			rear--;
		    }
		    else{
		    	cout<<"empty"<<endl;
		    }
		}
		int Front(){
			return get_data(front);
		}
		int isEmpty(){
			if(rear==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};

int main()
{
cout<<"Test Stack"<<endl;
	Stack s(5);
	// Push 0~5 into Stack s
	for(int i=0;i<6;i++)
		s.Push(i);
	// Print Stack s
	while(!s.isEmpty()){
		cout<<s.Top()<<" ";
		s.Pop();
	}
	cout<<endl;
	s.Pop();
	cout<<endl;
	
	cout<<"Test Queue"<<endl;
	Queue test(10); 
	// Push 1~3 into Queue test
	for (int i = 1; i < 4; i++)test.Push(i);
	Queue test1(test); // content of test1 are 1~3 by copy constructor
	// Push 4~11 into Queue test1
	for (int i = 4; i <= 11; i++)test1.Push(i);
	test1.Pop(); test1.Pop(); test1.Push(11);
	// Print Queue test1
	while(!test1.isEmpty()){
		cout<<test1.Front()<<" ";
		test1.Pop();
	}
	cout<<endl;
	test1.Pop();

//    system("pause");
    return 0;
}
