#include<bits/stdc++.h>
using namespace std;

class student {
	string name, dept;
	int id, semester;
	float mark[5], total, avg, gpa;
	char grade;

	public:

		void input(){
			cout<<"Enter id: ";
			cin>>id;
			cin.ignore();
			cout<<"Enter name: ";
			getline(cin,name);
			cout<<"Enter depertment: ";
			getline(cin,dept);
			cout<<"Enter semester: ";
			cin>>semester;
			cout<<"Enter 5 course marks"<<endl;
			for(int i=0;i<5;i++){
				cout<<"Course "<<(i+1)<<":";
				cin>>mark[i];}

			calculate();	
		}


		void calculate(){
			total =0;
			for(int i;i<5;i++){
				total += mark[i];
			}
			avg = total / 5;

		if (avg >= 90)      { grade = 'A'; gpa = 4.00; }
        else if (avg >= 80) { grade = 'B'; gpa = 3.75; }
        else if (avg >= 70) { grade = 'C'; gpa = 3.50; }
        else                    { grade = 'F'; gpa = 0.00; }
		}

		void display(){
			cout<<"------Student details------"<<endl;
			cout<<name<<endl;
			cout<<id<<endl;
			cout<<dept<<endl;
			cout<<semester<<endl;
			cout<<"-------MarkSheet---------"<<endl;
			cout<<total<<endl;
			cout<<avg<<endl;
			cout<<gpa<<endl;
			cout<<grade<<endl;


		}

		int getID() const{ return id;}
		string getName() const{return name;}
		string getDepertment() const{return dept;}
		float getGPA() const {return gpa;}
		

};


class StudentManager{
	student students[20];
	int count;


	public:
		StudentManager(){count =0;}

	void addStudent(){
		if(count>=20){
			cout<<"student list full";
		}
		students[count].input();
		count++;
	}

	void displayAll(){
		for(int i=0; i < count;i++){
			students[i].display();
		}
	}

	void searchByID(int id){
		for(int i=0;i<count;i++){
			if(students[i].getID() == id){
				cout<<"Student found";
				students[i].display();
				return;
			}
		}
		cout<<"No Student found";
	}
	void sortByGPA(){
		for(int i=0;i<count -1;i++){
			for(int j=0; j < count -1 - i; j++){
				if(students[j].getGPA() < students[j+1].getGPA()){
					swap(students[j],students[j+1]);
				}

			}
		}
	}
	void displayTopper(){
		if(count==0){
			cout<<"No Students yet.";
			return;
		}
		int topIndex = 0;
		for(int i=0; i<count;i++){
			if(students[i].getGPA() > students[topIndex].getGPA()){topIndex = i;}

		}
		cout<<"Topper";
		students[topIndex].display();

	}

	void depertmentAverage(string dept){
		float sum = 0, dept_avg;
		int n=0;
		for(int i=0;i < count;i++){
			if(students[i].getDepertment() == dept){
				sum += students[i].getGPA();
				n++;
			}
		}
		if (n==0){
			cout<<"No student found in depertment";
			return;
		}
		dept_avg = sum / n;
		cout<<"Average GPA in"<<dept<<dept_avg;
	}

};

int main(){
	StudentManager s2;
	int choice;
	do
	{
		cout << "\n===== STUDENT RECORD MANAGEMENT =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search by ID\n";
        cout << "4. Sort by GPA (Descending)\n";
        cout << "5. Display Topper\n";
        cout << "6. Department-wise Average GPA\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

		switch(choice){
			case 1: s2.addStudent();
				break;
			case 2: s2.displayAll();
				break;
			case 3: {
				int id;
				cout<<"Enter ID: ";
				cin>>id;
				s2.searchByID(id);
				break;
			}
			case 4: s2.sortByGPA();
				break;
			case 5: s2.displayTopper();
				break;
			case 6: {
				string dept;
				cin.ignore();
				cout<<"Enter depertment Name: ";
				getline(cin,dept);
				s2.depertmentAverage(dept);
				break;
			}
			case 0: break;
			default: cout<<"Invalid choice";

		}

	} while (choice != 0);
	
	return 0;
	
}