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
   int search(string,string);
    void unpack(string);
    void modify(string,string);
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
            s.unpack(fname);
            break;
        case 4:
        s.modify(key,fname);
            break;

            }
        }
}
void Student::read()
{
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
int Student::search(string key,string fname)
{
    Student s[10];
    int i=0,pos=0;
    ifstream myf(fname.c_str());
    //cout<<myf;
    while(!myf.eof())
    {
    cout<<"In search\n";
    s[i].unpack(fname);
    if(key==s[i].usn)
    {
                cout<<"record found\n";
                cout<<s[i].usn<<"\t"<<s[i].name<<"\t"<<s[i].branch<<"\t"<<s[i].sem;
                pos=myf.tellg();
                return pos;
                break;
    }
    i++;
    }
     myf.close();return 0;
}
void Student::modify(string key,string fname)
{
    string buffer;
    fstream file;
    int choice,pos;
    cout<<"Enter the usn to be searched\n";
    cin>>key;
    cout<<"enter the filename";
            cin>>fname;
    pos=search(key,fname);
    pos=pos-100;
    if(pos){
    cout<<"\n What to modify?";
    cin>>choice;

    switch(choice)
    {
        case 1: cout<<"\nUSN:"; cin>>usn; break;
        case 2:    cout<<"\nName:";cin>>name;break;
        case 3:    cout<<"\nBranch:";cin>>branch;break;
        case 4:    cout<<"\nSemster:";cin>>sem;break;
        default: cout <<"Wrong Choice";
    }


    file.open(fname.c_str(),ios::out);
    pos-=101;//skip $\n
    file.seekp(pos,ios::beg);
    pack(fname);
    file.close();
    }
    else
       printf("not able to get position");

}
