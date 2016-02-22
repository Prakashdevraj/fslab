//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : lab2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Student
{
private:string name;
        string usn;
        string branch;
        string sem;
public:
       void pack(string);
       void unpack(string);
       void modify();
       void search();
       void del();
       void read();
};
int main()
{
  int ch;
  fstream f;
  Student s;
  string filename;
while(1)
  {
	  cout<<"1 read";
	  cout<<"2 search";
	  cout<<"3 delete";
	  cout<<"4 modify";
	  cout<<"enter the choice";
	  cin>>ch;
     switch(ch)
        {
     	 	 case 1:
     	 		  cout<<"enter the filename";
     	 		  cin>> filename;
     	 		    s.read();
                    s.pack(filename);
                    s.unpack(filename);
                    break;
     	 	 case 2:
     	 		    //s.search();
     	 	        break;
     	 	 case 3:
     	 		    //s.modify();
                    break;
     	 	 case 4:
     	 		    //s.del();
     	 	        break;
         }
   }
}
void Student::read()
{
	cout<<"enter the name"<<endl;
    cin>>name;
    cout<<"enter the usn"<<endl;
    cin>>usn;
    cout<<"enter the branch"<<endl;
    cin>>branch;
    cout<<"enter the sem"<<endl;
    cin>>sem;
}
void Student::pack(string filename)
{
string temp;
temp=usn +'|' +name+'|' +branch+'|' +sem ;
ofstream myf(filename.c_str(),ios::app);
myf<<temp<<endl;
myf.close();
}
void Student::unpack(string filename)
{
	ifstream myf(filename.c_str());
	getline(myf,usn,'|');
	getline(myf,sem,'|');
	getline(myf,branch,'|');
	getline(myf,name,'|');
	cout<<<<endl;
}
