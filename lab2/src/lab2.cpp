#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string usn;
    string  name;
    string branch;
    string sem;
public:
    void read();
    void pack(string filename);
    void search(string,string);
    void unpack(string);
    void modify(string);
    };
int main()
{
    int ch;
    //fstream f;
    Student s;
    string fname,key;
    while(1)
    {
    cout<<"1.insert 2.search 3.delete 4.modify\n";
    cout<<"enter your choice";
    cin>>ch;

         switch(ch)
        {
        case 1:
            s.read();
            cout<<"enter filename ";
            cin >> fname;
            s.pack(fname);
            break;
        case 2:
            cout<<"Enter the USN to be searched\n";
            cin>>key;
            s.search(key,fname);
            break;
        case 3:
            s.modify(fname);
            break;
        case 4:
            s.unpack(fname);
            break;

            }
        }
}
void Student::read(){
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter usn"<<endl;
    cin>>usn;
    cout<<"enter branch"<<endl;
    cin>>branch;
    cout<<"enter sem"<<endl;
    cin>>sem;
}
void Student::pack(string fname){
    string buffer;
    ofstream myf(fname.c_str(),ios::app);
    buffer= usn+"|"+name+"|"+sem+"|"+branch;
    myf<<buffer<<endl;
    myf.close();

}
void Student::unpack(string fname)
{
    ifstream myf(fname.c_str());
    getline(myf,usn,'|');
    getline(myf,name,'|');
    getline(myf,branch,'|');
    getline(myf,sem,'|');
    myf.close();

}
void Student::search(string key,string fname)
{
    Student s[10];
    int i=0;

    ifstream myf(fname.c_str());
    //cout<<myf;
    while(!myf.eof())
    {
    cout<<"In search\n";
    s[i].unpack(fname);
    if(key==s[i].usn)
    {
                cout<<"record found\n";
                cout<<s[i].usn<<"\t"<<s[i].name;
                break;
    }
    i++;
    }


    myf.close();
}
void Student::modify(string fname)
{
	ofstream myf(fname.c_str());
    int i=0;
    string buffer;
    Student s[10];
    cout<<"enter the usn to modify"<<endl;
    cin>>buffer;

  while(!myf.eof())
    {
    cout<<"In search\n";
    s[i].unpack(fname);
    if(buffer==s[i].usn)
    {
                cout<<"record found\n";
                cout<<s[i].usn<<"\t"<<s[i].name;
                break;
    }
    i++;
}
  cout<<"enter the new usn";
  cin>>s[i].usn;
}
