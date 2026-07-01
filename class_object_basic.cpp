#include<bits/stdc++.h>
using namespace std;

class student{
    string name;
    int id;
    int semester;
    float result;
public:
    void set_name(string);
    void set_id(int);
    void set_semester(int);
    void set_result(float);

    string get_name();
    int get_id();
    int get_semester();
    float get_result();

};
void student::set_name(string name){this->name = name;}
void student::set_id(int id){this->id = id;}
void student::set_semester(int semester){this->semester = semester;}
void student::set_result(float result){this->result = result;}

string student::get_name(){return name;}
int student::get_id(){return id;}
int student::get_semester(){return semester;}
float student::get_result(){return result;}
int main(){
    class student s1;
    s1.set_name("jishan");
    s1.set_id(97);
    s1.set_semester(3);
    s1.set_result(3.44);

    cout << s1.get_name() << endl;
    cout << s1.get_id() << endl;
    cout << s1.get_semester() << endl;
    cout << s1.get_result() << endl;

    return 0;
}
