#include<iostream>
#include<string.h>
using namespace std;

class Student{
    protected:
      char name[20];
      int roll,sec;
    public:
      Student()
      {
      	cout<<"ENTER NAME: ";
      	cin>>name;
      	cout<<"ENTER ROLL: ";
      	cin>>roll;
      	cout<<"ENTER SECTION: ";
      	cin>>sec;
	  }
      void Display(){
        cout<<"Student Name is: "<<name<<endl;
        cout<<"Student Roll No. is: "<<roll<<endl;
        cout<<"Student Section is: "<<sec<<endl;
      }
};

class MidSem : virtual public Student{
    protected:
      float midmarks[5];
    public:
      void set_data1()
	  {
        cout<<"Enter MID SEM MARKS out of 40 "<<endl;
        for(int i=0;i<=4;i++)
		{
        cout<<"Enter marks of Subject "<<i+1<<endl;
        cin>>midmarks[i];
        }
      }
      void Display(){
        for(int i=0;i<=4;i++){
        cout<<"Marks of Subject "<<i+1<<" "<<midmarks[i]<<endl;
        }
      }
};

class EndSem : virtual public Student{
    protected:
      float endmarks[5];
    public:
      void set_data2(){
        cout<<"Enter END SEM MARKS out of 60 "<<endl;
        for(int i=0;i<=4;i++){
        cout<<"Enter marks of Subject "<<i+1<<endl;
        cin>>endmarks[i];
        }
      }
      void Display(){
        for(int i=0;i<=4;i++){
        cout<<"Marks of Subject "<<i+1<<" "<<endmarks[i]<<endl;
        }
      }
};

class Result : public MidSem,public EndSem{ 
    float sum1,sum2,total,percent;
    public:
    	Result()
		{
			sum1=0;
			sum2=0;
		} 
        float Total()
		{
        for(int i=0;i<=4;i++)
		{
          sum1 += midmarks[i];
        }
        for(int j=0;j<=4;j++)
		{
          sum2 += endmarks[j];
        }
        total = sum1 + sum2;
        return total;
        }

        float Percentage()
		{
        percent = (total/5);
        return percent;
        }
        void display_Total()
		{
        Student :: Display();
        MidSem :: Display();
        EndSem :: Display();
        cout<<"Total Marks is: "<<Total()<<endl;
        cout<<"Total Percentage is: "<<Percentage()<<endl;
        }
        friend void operator==(class Result&,class Result&);
        friend void percheck(class Result&);
};
void operator==(Result &x,Result &y)
{
	if(x.percent>y.percent)
	{
		cout<<x.name<<" HAS HIGHER PERCENTAGE."<<endl;
	}
	else if(x.percent==y.percent)
	{
		cout<<"THE PERCENTAGES ARE EQUAL...";
	}
    else
	{
		cout<<y.name<<" HAS HIGHER PERCENTAGE."<<endl;
	}
}
void percheck(Result &p)
{
	try
	{
	    if(p.percent<40)
	    {
	    	throw p.percent;
		}
	}
	catch(float per)
	{
		cout<<"THE STUDENT "<<p.name<<" HAS FAILED WITH "<<per<<" %";
	}
}
template<class T>
class Stdpassed
{
	T pass[20];
	int size;
	public:
		Stdpassed()
		{
			size=0;
		}
		void add_data()
		{
			int i,ch;
			T value;
			do
			{
				cout<<"\nENTER THE VALUE: ";
				cin>>value;
				pass[size]=value;
				size++;
				cout<<"\nDO YOU WANT TO ADD ELEMENTS? ";
				cin>>ch;
			}while(ch==-1);
		}
		void modify()
		{
			int k;
			T n;
			cout<<"\nENTER INDEX FOR MODIFICATION: ";
			cin>>k;
			cout<<"\nENTER VALUE: ";
			cin>>n;
			pass[k]=n;
		}
		void display()
		{
			cout<<"\nSIZE OF VECTOR IS: "<<size;
			cout<<"\nELEMENTS ARE: "<<endl;
			cout<<"[";
			for(int i=0;i<size;i++)
			{
				cout<<pass[i]<<",";
			}
			cout<<"]";
		}
		
};

int main()
{   Result r,q;
    r.set_data1();
    r.set_data2();
    r.display_Total();
    q.set_data1();
    q.set_data2();
    q.display_Total();
    operator==(r,q);
    percheck(q);
    int c;
	Stdpassed<int>obj;
	do
	{
		cout<<"\n 1.CREATE \n 2.MODIFY \n 3.DISPLAY \n";
		cout<<"ENTER CHOICE: ";
		cin>>c;
		switch(c)
		{
			case 1:
				obj.add_data();
				break;
			case 2:
				obj.modify();
				break;
			case 3:
				obj.display();
				break;
			default:
				cout<<"\nINVALID.";
				break;
	    }
	}while(c!=-1);
    return 0;
}