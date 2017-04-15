#include <iostream>
using namespace std;

class People
{
	int HP=100;
	int Shield_HP=0;
	public:
		void show()
		{
			cout<<"Hero HP"<<"<"<<HP<<"/100>:";
			for(int i=1;i<=HP/10;i++)
			{
				cout<<"|";
			}
			cout<<endl;
			if(Shield_HP>0)
			{
				cout<<"Shell HP"<<"<"<<Shield_HP<<"/100>:";
				for(int i=1;i<=Shield_HP/10;i++)
			{
				cout<<"|";
			}
			cout<<endl;
			}
		}
		void set_Shield(){Shield_HP=100;}
		int get_HP(){return HP;}
		void get_damage()
		{
			if(Shield_HP>0)
			{
				Shield_HP-=40;
				cout<<"Hero got 40 Damage."<<endl;
				if(Shield_HP<=0)
				{
					cout<<"Shell Break."<<endl;
				}
			}
			else
			{
			   HP-=50;
			   cout<<"Hero got 50 Damage."<<endl;
			}
		}
		
};

class Swordsman:virtual public People
{
	int weapon;
	int damage;
	public:
		void choose_weapon(int a){weapon=a;}
		int attack(){
		   if(weapon==0){damage=10;}
		   else if(weapon==1){damage=20;}
		   else{damage=100;}
		   
		   return damage;
		}
		
};

class Wizard:virtual public People
{
	int wand;
	int damage=0;
	public:
		void choose_wand(int a){wand=a;}
		int spell_magic(int skill)
		{
			if(skill==0){set_Shield(); damage=0;}
			else if(skill==1&&skill==2&&skill==3){damage=50;}
			else if(skill=13112){damage=100;}
	    }
		int skill()
		{
			if(wand==0){return damage;}
			else if(wand==1){return 1.2*damage;}
			else {return 2*damage;};
		}
		
};

class Magicka:public Swordsman , public Wizard
{
	
};

class Boss
{
	int HP=500;
	public:
		void show()
		{
			cout<<"Boss HP"<<"<"<<HP<<"/500>:";
			for(int i=1;i<=HP/10;i++)
			{
				cout<<"|";
			}
			cout<<endl;
		}
		int get_HP(){return HP;}
		void get_damage(int a)
		{
		cout<<"Boss got "<<a<<" Damage"<<endl;
		HP-=a;
		}
};

int main()
{
	Magicka Hero;
	Boss Boss;
	int weapon,wand;
	int count=1;
	cout<<"Please choose weapon for hero. [0]:sword [1]:M60 [2]:Excalibur"<<endl;
	cin>>weapon;
	Hero.choose_weapon(weapon);
	cout<<"Please choose wand for hero. [0]:Wood wand [1]:Silver wand [2]:Gold wand"<<endl;
    cin>>wand;
    Hero.choose_wand(wand);
    
    while(Boss.get_HP()>0&&Hero.get_HP()>0)
    {
    	int attack,skill;
    	cout<<"Round "<<count<<endl;
    	count++;
    	Boss.show();
    	Hero.show();
    	cout<<"Boss attack!!"<<endl;
    	cout<<"Select attack or magic for Hero. [0]:attack [1]:magic >>";
    	cin>>attack;
    	if(attack==0)
    	{
    		Hero.get_damage();
    		Boss.get_damage(Hero.attack());
    	}
    	else
    	{
    		cout<<"Select skill for Hero >>";
    		cin>>skill;
    		Hero.spell_magic(skill);
    		Hero.get_damage();
    		Boss.get_damage(Hero.skill());
    	}
    	
    	cout<<endl;
    }
    if(Boss.get_HP()<=0)
    {
    	if(Hero.get_HP()>0)
		{cout<<"You win!"<<endl;}
		else{cout<<"You lose!"<<endl;}
    }
    else
    {
    	cout<<"You lose!"<<endl;
    }
    return 0;
}

