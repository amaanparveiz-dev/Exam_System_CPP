#include<iostream>
#include<fstream>
#include <limits>
#include<string>
using namespace std;

void ExceptionCin(int &a){
	try{
		if(cin.fail()){
			throw 1;
		}
	}
		catch(int b){
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout<<endl;
		cout<<"You Entered a Non Numeric Value"<<endl<<endl;
		cout<<"Enter a Numeric Value : ";		
		cin>>a;         
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');                 
		ExceptionCin(a);
		system("cls");
	}
}


class Person{
	protected:
	static int logged;
	string f_name,l_name,username;
	int roll_no=0,mcq_no=0,essay_no=0,mcq_done,essay_done;
	static float Mcq_Avg,Essay_Avg,Count_Mcq,Count_Essays;
	public:
	void Set_Roll_no(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetRoll("Data/"+username+"_data.txt");
		SetRoll>>a>>b>>c>>d>>e>>f>>g>>h;
		roll_no=a;
	}
	int Get_Roll_no(){
		return roll_no;
	}
	
	void Set_First_Name(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetName("Data/"+username+"_data.txt");
		SetName>>a>>b>>c>>d>>e>>f>>g>>h;
		f_name=b;
	}
	string Get_First_Name(){
		return f_name;
	}
	
	void Set_Last_Name(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetName("Data/"+username+"_data.txt");
		SetName>>a>>b>>c>>d>>e>>f>>g>>h;
		l_name=h;
	}
	string Get_Last_Name(){
		return l_name;
	}
	
	void Set_Mcq_No(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetMcq("Data/"+username+"_data.txt");
		SetMcq>>a>>b>>c>>d>>e>>f>>g>>h;
		mcq_no=d;
	}
	int Get_Mcq_no(){
		return mcq_no;
	}
	
	void Set_Essay_No(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetEssay("Data/"+username+"_data.txt");
		SetEssay>>a>>b>>c>>d>>e>>f>>g>>h;
		essay_no=e;
	}
	int Get_Essay_no(){
		return essay_no;
	}	
	
	void Set_Essay_Done(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetEssayDone("Data/"+username+"_data.txt");
		SetEssayDone>>a>>b>>c>>d>>e>>f>>g>>h;
		essay_done=g;
	}
	int Get_Essay_Done(){
		return essay_done;
	}	
	
	void Set_Mcq_Done(){
		int a,d,e,f,g;
		string b,c,h;
		ifstream SetMcqDone("Data/"+username+"_data.txt");
		SetMcqDone>>a>>b>>c>>d>>e>>f>>g>>h;
		mcq_done=f;
	}
	int Get_Mcq_Done(){
		return mcq_done;
	}
	
	void Set_Mcq_Avg(){
		int a,d,e,f,g;
		string b,c,h;
		string u,p;
		float sum=0;
		Count_Mcq=0;
		ifstream users_read("Data/Database.txt");
		while(users_read >> u >> p){
			ifstream check_Mcq_done("Data/"+u+"_data.txt");
			check_Mcq_done >> a >> b >> c >> d >> e >> f >> g >> h;
			if(f==1){
				sum=sum+d;
				Count_Mcq++;
			} 
		}
		Mcq_Avg=sum/Count_Mcq;
	}
	
	float Get_Mcq_Avg(){
		return Mcq_Avg;
	}
	
 	void Set_Essay_Avg(){
		int a,d,e,f,g;
		string b,c,h;
		string u,p;
		float sum=0;
		Count_Essays=0;
		ifstream users_read("Data/Database.txt");
		while(users_read >> u >> p){
			ifstream check_essay_done("Data/"+u+"_data.txt");
			check_essay_done >> a >> b >> c >> d >> e >> f >> g >> h;
			if(g==2){
				sum=sum+e;
				Count_Essays++;
			} 
		}
		Essay_Avg=sum/Count_Essays;
	}
	
	float Get_Essay_Avg(){
		return Essay_Avg;
	}
	
	void Setters(){
		Set_Roll_no();
		Set_First_Name();
		Set_Last_Name();
		Set_Mcq_No();
		Set_Essay_No();
		Set_Essay_Done();
		Set_Mcq_Done();
		Set_Mcq_Avg();
		Set_Essay_Avg();
	}	
	
	static int get_Logged_status(){
	return logged;
}
	virtual void Register(){};
	virtual void Login()=0;
	virtual void menu()=0;
	virtual void MCQ_Exam(){};
	virtual void Essay_exam(){};
	virtual void check_Mcq_No()=0;
	virtual void check_Essay_No(){};
};

class Student : public Person{
	public:
	 void Register(){
		int registered=0;
		string f_name,l_name,username_r,password,u,p,temp;
		int t_stds=0;
			cout<<"Enter Your First Name : ";
			cin>>f_name;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout<<"Enter Your Last Name : ";
			cin>>l_name;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout<<"Enter Username To Register : ";
			cin>>username_r;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');	
			cout<<"Enter Password To Register : ";
			cin>>password;	
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');	
			ifstream Input("Data/Database.txt");
			while (Input>>u>>p){
				if(u==username_r){
					registered=1;
				}	
			}
			if(registered==1){
				system("cls");
				cout<<"This Username Already Exist, Kindly Use Another"<<endl<<endl;
				cout<<"Press Any Key To Go Back"<<endl<<endl;
				cin>>temp;
				system("cls");

			}
			else{
			ofstream f1("Data/Database.txt",ios::app);
			f1<<username_r<<" "<<password<<" "<<endl;
			system("cls");
			cout<<"Registered"<<endl<<endl;
			
			ifstream Old_Total_Students("Data/T_students.txt");
			while( Old_Total_Students >> t_stds){
			}
			t_stds++;

			ofstream Updated_Total_Students("Data/T_students.txt");
			Updated_Total_Students << t_stds;
			
			ofstream L_Name("Data/"+username_r+"_data.txt" ,ios::app);
			L_Name <<l_name<<" ";
					
			ofstream Essay_done("Data/"+username_r+"_data.txt" ,ios::app);
			Essay_done << 0<<" ";
			
			ofstream Mcq_done("Data/"+username_r+"_data.txt" ,ios::app);
			Mcq_done << 0<<" ";
			
			ofstream Essay_no("Data/"+username_r+"_data.txt" ,ios::app);
			Essay_no << 0<<" ";
			
			ofstream MCQ_no("Data/"+username_r+"_data.txt" , ios::app);
			MCQ_no << 0<<" ";
			
			ofstream Username("Data/"+username_r+"_data.txt" , ios::app);
			Username << username_r<<" ";
			
			ofstream F_Name("Data/"+username_r+"_data.txt" , ios::app);
			F_Name << f_name<<" ";
			
			ofstream Rollno("Data/"+username_r+"_data.txt", ios::app);
			Rollno << t_stds<<" ";
			
			cout<<"You Have Been Alloted Roll Number"<<" "<<t_stds<<endl<<endl;
			cout<<"Press Any Key To Go Back"<<endl<<endl;
			cin>>temp;
			system("cls");
	}
}

	void Login(){
			string username_l,password,u,p;
			cout<<"Enter Username To Login : ";
			cin>>username_l;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');	
			cout<<"Enter Password To Login : ";
			cin>>password;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');	
			ifstream Input("Data/database.txt");
			while (Input>>u>>p){
				if(u==username_l && p==password){
					system("cls");
					cout<<"Login Succesfull"<<endl;
					username=username_l;
					logged=1;
				}	
			}
			
			if(logged==0){
				system("cls");
				cout<<"Wrong Credentials...."<<endl<<endl;
			}
		}

	void MCQ_Exam(){
		system("cls");
		int choice;
		string temp;
		for (int x=0;x!=1;){
		cout<<"Q1:What is an operating system?"<<endl;
		cout<<"1) Interface between the hardware and application programs"<<endl;
		cout<<"2) Collection of programs that manages hardware resources"<<endl;
		cout<<"3) System service provider to the application programs"<<endl;
		cout<<"4) All of the mentioned"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==4){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
	
		for (int x=0;x!=1;){
		cout<<"Q2:How is Fatima as a Coder?"<<endl;
		cout<<"1) Brilliant"<<endl;
		cout<<"2) Fantastic"<<endl;
		cout<<"3) Very Good"<<endl;
		cout<<"4) All of The Above"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==4){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
		
		for (int x=0;x!=1;){
		cout<<"Q3:A Verb tells us : "<<endl;
		cout<<"1) What a person or thing does"<<endl;
		cout<<"2) The quantity of something"<<endl;
		cout<<"3) Modify a noun"<<endl;
		cout<<"4) The Number or Quantity"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==1){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q4:Which flower is national flower of Pakistan?"<<endl;
		cout<<"1) Jasmine"<<endl;
		cout<<"2) Rose"<<endl;
		cout<<"3) Sun Flower"<<endl;
		cout<<"4) None of the above"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==1){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q5:In C++, which operator is used to access the value of a variable through a pointer?"<<endl;
		cout<<"1) &"<<endl;
		cout<<"2) *"<<endl;
		cout<<"3) $"<<endl;
		cout<<"4) #"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==2){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q6:Which of the following is a synonym for HAPPY?"<<endl;
		cout<<"1) Sad"<<endl;
		cout<<"2) Angry"<<endl;
		cout<<"3) Joyful"<<endl;
		cout<<"4) Frustrated"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==3){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q7:Which of the following is not a type of access modifier in C++?"<<endl;
		cout<<"1) Public"<<endl;
		cout<<"2) Private"<<endl;
		cout<<"3) Protected"<<endl;
		cout<<"4) Default"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==4){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q8:What is a destructor in C++?"<<endl;
		cout<<"1) A function that is automatically called when an object is created"<<endl;
		cout<<"2) A function that is called when an object is destroyed"<<endl;
		cout<<"3) A function that is used to assign a value to a variable"<<endl;
		cout<<"4) None of the abover"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==2){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q9:What is the process by which plants make their own food?"<<endl;
		cout<<"1) Photosynthesis"<<endl;
		cout<<"2) Respiration"<<endl;
		cout<<"3) Transpiration"<<endl;
		cout<<"4) Combustion"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==1){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
	
		for (int x=0;x!=1;){
		cout<<"Q10:What is a constructor in C++?"<<endl;
		cout<<"1) A function that is automatically called when an object is created"<<endl;
		cout<<"2) A function that is called when an object is destroyed"<<endl;
		cout<<"3) A function that is used to assign a value to a variable"<<endl;
		cout<<"4) None of the abover"<<endl;				
		cin>>choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(choice);
		if(choice==1){
			mcq_no++;
		}
		if(choice>=1 && choice<=4){
			mcq_done=1;
			x=1;
			system("cls");
		}
		else{
			system("cls");
			cout<<"Invalid option..."<<endl<<endl;
		}
	}
		cout<<"You Got"<<" "<<Get_Mcq_no()<<" "<<"Numbers In This Test"<<endl<<endl;
		cout<<"Thank You For Taking Your Mcqs Exam"<<endl<<endl;
		cout<<"Press Any Key To Go Back"<<endl<<endl;
		cin>>temp;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		system("cls");
		ofstream update_mcq("Data/"+username+"_data.txt");
		update_mcq<<roll_no<<" "<<f_name<<" "<<username<<" "<<mcq_no<<" "<<essay_no<<" "<<mcq_done<<" "<<essay_done<<" "<<l_name; 
	}
	void Essay_exam(){
		system("cls");
		string a,temp;
		ofstream Essay("Data/"+username+"essay.txt");
		cout<<"Enter Essay On Democracy "<<endl;
		cin.ignore();
		getline(cin,a);
		Essay<<a;
		essay_done=1;
		system("cls");
		cout<<"Thank You For Attempting Your Essay"<<endl<<endl;
		cout<<"Press Any Key To Go Back"<<endl<<endl;
		cin>>temp;
		system("cls");
		ofstream update_essay("Data/"+username+"_data.txt");
		update_essay<<roll_no<<" "<<f_name<<" "<<username<<" "<<mcq_no<<" "<<essay_no<<" "<<mcq_done<<" "<<essay_done<<" "<<l_name; 
	}
	
	void check_Mcq_No(){
		system("cls");
		int a,d,e,f,g;
		string b,c,h,temp;
		ifstream check_mcq_no("Data/"+username+"_data.txt");
		check_mcq_no >> a >> b >> c >> d >> e >> f >> g >> h;
		cout<<"You Got"<<" "<<d<<" "<<"Numbers in Your MCQs Exam"<<endl<<endl;
		cout<<"A Total of"<<" "<<Count_Mcq<<" "<<"Students Appeard in Mcq Exam and The Average is"<<" "<<Mcq_Avg<<endl<<endl;
		if(d>Mcq_Avg){
		cout<<"As You Got"<<" "<<d<<" "<<"Numbers in your Exams, You are Above Average"<<endl<<endl;
		}
		if(d<Mcq_Avg){
		cout<<"As You Got"<<" "<<d<<" "<<"Numbers in your Exams, You are Below Average"<<endl<<endl;
		}
		if(d==Mcq_Avg){
		cout<<"As You Got"<<" "<<d<<" "<<"Numbers in your Exams, You Got Average Numbers"<<endl<<endl;
		}
		cout<<"Press Any Key To Go Back"<<endl<<endl;
		cin>>temp;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		system("cls");
	}
	void check_Essay_No(){
		system("cls");
		int a,d,e,f,g;
		string b,c,h,temp;
		ifstream check_Essay_no("Data/"+username+"_data.txt");
		check_Essay_no >> a >> b >> c >> d >> e >> f >> g >> h;
		cout<<"You Got"<<" "<<e<<" "<<"Numbers in Your Essay Exam"<<endl<<endl;
		cout<<"A Total of"<<" "<<Count_Essays<<" "<<"Students Appeard in Essay Exam and The Average is"<<" "<<Essay_Avg<<endl<<endl;
		if(e>Essay_Avg){
		cout<<"As You Got"<<" "<<e<<" "<<"Numbers in your Exams, You are Above Average"<<endl<<endl;		
		}
		if(e<Essay_Avg){
		cout<<"As You Got"<<" "<<e<<" "<<"Numbers in your Exams, You are Below Average"<<endl<<endl;
		}
		if(e==Essay_Avg){
		cout<<"As You Got"<<" "<<e<<" "<<"Numbers in your Exams, You Got Average Numbers"<<endl<<endl;
		}
		cout<<"Press Any Key To Go Back"<<endl<<endl;
		cin>>temp;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		system("cls");
	}

	
	void menu(){
	system("cls");
	int a,d,e,f,g,choice,temp;
	string b,c;
	Setters();
	for(int x=0;x!=1;){
		cout<<"Name : "<<Get_First_Name()<<" "<<Get_Last_Name()<<"		"<<"Roll No : "<<Get_Roll_no()<<"		"<<"Username : "<<username<<endl<<endl<<endl;
		if(Get_Mcq_Done()==0){
			cout<<"Press 1 To Take MCQs Test"<<endl<<endl;
			}
		if(Get_Mcq_Done()==1){
			cout<<"Press 1 To Check Your MCQs Numbers"<<endl<<endl;
			}	
		if(Get_Essay_Done()==0){
			cout<<"Press 2 To Take Essay Test"<<endl<<endl;
			}
		if(Get_Essay_Done()==2){
			cout<<"Press 2 To Check Your Essay Numbers"<<endl<<endl;
			}
		if(Get_Essay_Done()==1){
			cout<<"Your Essay Exam is Not Checked Yet.."<<endl<<endl;
			}	
			cout<<"Press 3 To Sign Out"<<endl;	
			cin>>choice;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			ExceptionCin(choice);	
			system("cls");
				if (choice==1 && Get_Mcq_Done()==0){
					MCQ_Exam();
				}
				else if (choice==2 && Get_Essay_Done()==0){
					Essay_exam();
				}
				else if (choice==1 && Get_Mcq_Done()==1){
					check_Mcq_No();
				}
				else if (choice==2 && Get_Essay_Done()==2){
					check_Essay_No();
				}
				else if (choice==3){
					system("cls");
					cout<<"Thank You For Using Our System...."<<endl<<endl;
					x=1;
					logged=0;
				}
				else{
					cout<<"Invalid Option.."<<endl<<endl;
				}
			}
		}
};
class Teacher : public Person{
	public:
		void Login(){
			string username_l,password,u,p;
			cout<<"Enter Username To Login : ";
			cin>>username_l;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');	
			cout<<"Enter Password To Login : ";
			cin>>password;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');	
			ifstream Input("admin_credentials.txt");
			while (Input>>u>>p){
				if(u==username_l && p==password){
					cout<<"Login Succesfull"<<endl;
					username=username_l;
					logged=1;
				}	
			}
			
			if(logged==0){
				system("cls");
				cout<<"Login Failed"<<endl<<endl;
			}
		}
	void check_essay(){
		int a,d,e,f,g,marks,null,checked=0;
		string b,c,essay,user;
		string u,p,h;
		string choice;
		system("cls");
		for(int x=0; x!=1;){
		null=1;
		cout<<"Students Who Have Completed Their Essay Are : "<<endl<<endl;
		ifstream users_read("Data/Database.txt");
		while(users_read >> u >> p){
			ifstream check_essay_done("Data/"+u+"_data.txt");
			check_essay_done >> a >> b >> c >> d >> e >> f >> g >> h;
			if(g==1 && g!=2){
				cout<<u<<endl<<endl;
				null=0;
			} 
		}
		if(null==0){
		cout<<"Enter The Username of The Student To Check His/Her Essay : ";
		cin>>user;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ifstream users_check("Data/Database.txt");
		while(users_check >> u >> p){
			ifstream check_essays_done("Data/"+u+"_data.txt");
			check_essays_done >> a >> b >> c >> d >> e >> f >> g >> h;
			if(user==u && g==1 && g!=2){
				system("cls");
				checked=1;
				username=user;
				Setters();
				ifstream read_essay("Data/"+user+"essay.txt");
				getline(read_essay , essay );
				cout<<"Essay of"<<" "<<Get_First_Name()<<" "<<Get_Last_Name()<<" "<<"is"<<endl<<endl; 
 				cout<<essay<<endl<<endl;
 				cout<<"Enter Marks Between 0-10"<<endl;
		 		cin>>marks;
		 		ExceptionCin(marks);
		 		system("cls");
				if(marks>=0 && marks<=10){
		 			essay_no=marks;
		 			essay_done=2;
		 			ofstream update_essay("Data/"+u+"_data.txt");
		 			update_essay<<roll_no<<" "<<f_name<<" "<<username<<" "<<mcq_no<<" "<<essay_no<<" "<<mcq_done<<" "<<essay_done<<" "<<l_name;
 					}
 				else{
 					cout<<"Invalid Option Please Try Again..."<<endl<<endl;
				 }
		cout<<"Press Any Key Except 'N' If You Want to Check Another Essay"<<endl;
 		cin>>choice;
 		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
 		system("cls");
 		if(choice == "N" || choice == "n"){
 			x=1;
		 	}
 		}
 		else if(checked==0){
 			system("cls");
 			cout<<"Wrong Username..."<<endl<<endl;
		 }
 	}
 }
 		else{
 		system("cls");
		cout<<"There are No Essays Left To Check"<<endl<<endl;
		x=1;
		}	
	}
}
	void check_Mcq_No(){
		system("cls");
		int a,d,e,f,g,marks;
		string b,c,essay,temp;
		string u,p,h;
		cout<<"Students Who Have Completed Their MCQs With Thier Numbers Are : "<<endl<<endl;
		ifstream users_read("Data/Database.txt");
		while(users_read >> u >> p){
			ifstream check_essay_done("Data/"+u+"_data.txt");
			check_essay_done >> a >> b >> c >> d >> e >> f >> g >> h;
			if(f==1){
				cout<<u<<" "<<"Got"<<" "<<d<<" "<<"Numbers"<<endl<<endl;
			} 
		}
		cout<<"Press Any Key To Go Back"<<endl<<endl;
		cin>>temp;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		system("cls");
}
	void change_pass(){
		system("cls");
		string p;
		cout<<"Enter New Password"<<endl;
		cin>>p;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ofstream change_pass("admin_credentials.txt");
		change_pass << "admin" <<" "<< p;
		system("cls");
		cout<<"Password Changed Sucessfully"<<endl<<endl;
	}
	
	void menu(){
	system("cls");
	int choice;
	for(int x=0;x!=1;){
	cout<<"Welcome"<<" "<<endl<<endl;	
	cout<<"Press 1 To Check The Essays of Students"<<endl;
	cout<<"Press 2 To Check The Results of MCQs of Students"<<endl;
	cout<<"Press 3 To Check The Average Marks of Mcqs And Essays of Students"<<endl;
	cout<<"Press 4 To Change Your Password"<<endl;
	cout<<"Press 5 To Sign Out"<<endl;
	cin>>choice;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	ExceptionCin(choice);
		switch (choice){
		case 1: 
			check_essay();
			break;
		case 2:
			check_Mcq_No();
			break;
		case 3:{
			string temp;
			Set_Mcq_Avg();
			Set_Essay_Avg();
			system("cls");
			cout<<"A Total of"<<" "<<Count_Mcq<<" "<<"Students Appeard in Mcqs Exam and The Average is"<<" "<<Mcq_Avg<<endl<<endl;
			cout<<"A Total of"<<" "<<Count_Essays<<" "<<"Students Appeard in Essay Exam and The Average is"<<" "<<Essay_Avg<<endl<<endl;
			cout<<"Press Any Key To Go Back"<<endl<<endl;
			cin>>temp;
			system("cls");
		}
			break;
		case 4:
			change_pass();
			break;
		case 5:
			system("cls");
			cout<<"Thank You For Using Our System...."<<endl<<endl;
			x=1;
			logged=0;
			break;
		default:
			system("cls");
		cout<<"Invalid Option..."<<endl<<endl;	
			}
		}	
	}
};

int Person :: logged = 0;
float Person :: Mcq_Avg = 0;
float Person :: Essay_Avg = 0;
float Person :: Count_Mcq = 0;
float Person :: Count_Essays = 0;
int main(){
	int a,b,c;
	for (int x=0;x!=1;){
	cout<<"=========================================== WELCOME TO FIA EXAM SYSTEM =============================================="<<endl<<endl;
	cout<<"Press 1 If You Are a Student"<<endl;
	cout<<"Press 2 If You Are a Teacher"<<endl;
	cout<<"Press 3 To Exit"<<endl;
	cin>>a;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	ExceptionCin(a);
	switch (a){
		case 1:{
		system("cls");
		Person *p;
		Student s;
		p=&s;
		cout<<"Press 1 To Register"<<endl;
		cout<<"Press 2 To Login"<<endl;
		cout<<"Press 3 To Exit"<<endl;
		cin>>b;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(b);
		switch (b){
			case 1:
				p->Register();
				break;
			case 2:
				p->Login();
				if(Person::get_Logged_status()==1){
				p->menu();
				}
				break;
			case 3:
				system("cls");
				break;
			default:
			system("cls");
			cout<<"Invalid Option..."<<endl<<endl;
				break;
				}
		break;
	}
		case 2:{
		system("cls");
		Person *p;
		Teacher t;
		p=&t;
		cout<<"Press 1 To Login"<<endl;
		cout<<"Press 2 To Exit"<<endl;
		cin>>c;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		ExceptionCin(c);
		switch (c){
			case 1:
				p->Login();
				if(Person::get_Logged_status()==1){
				p->menu();
				}
				break;
			case 2:
				system("cls");
				break;
			default:
				system("cls");
				cout<<"Invalid Option..."<<endl<<endl;
				break;
		}
		break;
	}
	case 3:
		x=1;
		system("cls");
		cout<<"Thank You For Using Our Exam System..."<<endl<<endl;
		cout<<"Come Again...."<<endl;
		break;
	default:
		system("cls");
		cout<<"Invalid Choice..."<<endl<<endl;	
		}	
	}
}
