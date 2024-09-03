#include<iostream>
#include<fstream>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void Employee_Function();
void Student_Function();
void Book_Function();
void logout();
void delay();
int password();
int checkmobNo(long long m);
 void gotoxy(int x, int y)   //gotoxy(3,7);
{
            COORD c;
            c.X = x;
            c.Y = y;

            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE), c);
}
class Employee
{
   private:
            int id,salary;
            char ename[20];
            long long mob;
   public:
       fstream f;
        void AddEmployee()
        {
            int tid,status=0;
              f.open("Employee.txt",ios::in);
               cout<<"----------Add new Employee-------------\n"<<endl;
            cout<<" Enter Employee Id: "<<endl;
            cin>>tid;
            while(1)
            {
                f>>id>>ename>>salary>>mob;
                 if(f.eof())
                 {
                     break;
                 }
                 if(id==tid)
                 {
                     status=1;
                     cout<<id<<" This Employee ID is  already exit."<<endl;
                 }
            }
            f.close();
            if(status==0)
                    {
                         f.open("Employee.txt",ios::app);
                   id=tid;
                    cout<<" Enter Employee Name: "<<endl;
                    cin>>ename;
                    cout<<" Enter Employee Salary: "<<endl;
                    cin>>salary;
                    while(1)
                    {
                        int a;
                        cout<<" Enter Employee Mobile Number: "<<endl;
                        cin>>mob;
                        a= checkmobNo(mob);
                        if(a==1)
                        {
                            break;
                        }
                        else{
                            cout<<"INPUT Mob Number is Wrong. Please enter again."<<endl;
                        }
                    }
                    f<<id<<" "<<ename<<" "<<salary<<" "<<mob<<endl;
                    cout<<ename<<" details added successfully. \nPlease wait .";
                    for(int y=1;y<=10;y++)
                    {
                        delay();
                        cout<<" . ";
                    }
                    f.close();
            }

        }
        void ViewEmployee()
        {
              f.open("Employee.txt",ios::in);
              cout<<"-------------All the EMPLOYEE Details----------------"<<endl;
              while(1)
              {
                  f>>id>>ename>>salary>>mob;
                 if(f.eof())
                 {
                     break;
                 }
                 cout<<"EMP ID: "<<id<<endl;
                 cout<<"EMP Name: "<<ename<<endl;
                 cout<<"EMP Salary: "<<salary<<endl;
                 cout<<"EMP Mobile No.: "<<mob<<endl;
                 cout<<"-------------------------------"<<endl;
              }
              f.close();
        }
        void SearchEmployee()
        {
              f.open("Employee.txt",ios::in);
              int tid,status=0;
              cout<<"enter employee if to search the data: "<<endl;
              cin>>tid;

              while(1)
              {
                  f>>id>>ename>>salary>>mob;
                 if(f.eof())
                 {
                     break;
                 }
                 if(id==tid)
                 {
                     cout<<"-------------the EMPLOYEE Details----------------"<<endl;
                     cout<<"EMP ID: "<<id<<endl;
                     cout<<"EMP Name: "<<ename<<endl;
                     cout<<"EMP Salary: "<<salary<<endl;
                     cout<<"EMP Mobile No.: "<<mob<<endl;
                     cout<<"-------------------------------"<<endl;
                     status=1;
                 }
              }
              if(status==0)
              {
                  cout<<tid<<" employee id does not exit."<<endl;
              }
              f.close();
        }
        void UpdateEmployee()
        {
            fstream f2;
            int tid,status=0,amount;
            f2.open("Employeetemp.txt",ios::app);
            f.open("Employee.txt",ios::in);
            cout<<"Enter employee id to update the salary: "<<endl;
            cin>>tid;
             while(1)
            {
                f>>id>>ename>>salary>>mob;
                 if(f.eof())
                 {
                     break;
                 }
                 if(id==tid)
                 {
                     status=1;
                     cout<<"enter How much salary you want to increase."<<endl;
                     cin>>amount;
                     salary=salary+amount;
                     cout<<ename<<"'s salary is updated successfully.\nplease wait .";
                     for(int y=1;y<=10;y++)
                     {
                         delay();
                         cout<<" . ";
                     }
                 }
                   f2<<id<<" "<<ename<<" "<<salary<<" "<<mob<<endl;
            }
            if(status==0)
            {
                cout<<tid<<" This Employee ID is not exit."<<endl;
            }
            f2.close();
            f.close();
            remove("Employee.txt");
            rename("Employeetemp.txt","Employee.txt");

        }
}e;
int checkmobNo(long long m)
{
    if(m>6000000000  && m<=99999999999)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void delay()
{
    for(int z=1;z<1000000;z++)
    {
        z++;
        z--;
    }


}

class Book
{
      protected:
       int bid,quantity;
       char bname[20],aname[20];
   public:
       fstream z;
        void AddBook()
        {
            int tid,status=0;
             z.open("Book.txt",ios::in);
             cout<<"enter Book Id: "<<endl;
            cin>>tid;
            while(1)
            {
                z>>bid>>bname>>aname>>quantity;
                if(z.eof())
                {
                    break;
                }
                if(tid==bid)
                {
                    cout<<tid<<" this id is already exist."<<endl;
                    status=1;
                }
            }
            z.close();
            if(status==0)
            {
                        z.open("Book.txt",ios::app);
                    bid=tid;
                    cout<<"enter Book Name: "<<endl;
                    cin>>bname;
                    cout<<"enter Book Author Name: "<<endl;
                    cin>>aname;
                    cout<<"enter Book Quantity: "<<endl;
                    cin>>quantity;
                    z<<bid<<" "<<bname<<" "<<aname<<" "<<quantity<<endl;
                    cout<<bname<<" Book Added successfully.\n Please Wait .";
                    for(int x=1;x<=10;x++)
                    {
                        delay();
                        cout<<" . ";
                    }
                    z.close();
            }
        }
        void ViewBook()
        {
                 int status=0;
             z.open("Book.txt",ios::in);
             cout<<"*******All the Book Details are********"<<endl;
            while(1)
            {
                z>>bid>>bname>>aname>>quantity;
                if(z.eof())
                {
                    break;
                }
                cout<<"Book ID: "<<bid<<endl;
                cout<<"Book Name: "<<bname<<endl;
                cout<<"Book Author: "<<aname<<endl;
                cout<<"Book Quantity: "<<quantity<<endl;
                cout<<"-----------------------------------"<<endl;
            }
            z.close();
        }
        void SearchBook()
        {
                  int status=0,tid;
                  cout<<"Enter the Book Id to Search: "<<endl;
                  cin>>tid;
             z.open("Book.txt",ios::in);
             cout<<"*******All the Book Details are********"<<endl;
            while(1)
            {
                z>>bid>>bname>>aname>>quantity;
                if(z.eof())
                {
                    break;
                }
                if(tid==bid)
                {
                    cout<<"Book ID: "<<bid<<endl;
                cout<<"Book Name: "<<bname<<endl;
                cout<<"Book Author: "<<aname<<endl;
                cout<<"Book Quantity: "<<quantity<<endl;
                cout<<"-----------------------------------"<<endl;
                status=1;
                }
            }
            if(status==0)
            {
                cout<<tid <<" this Book id is not found."<<endl;
            }
            z.close();
        }
        void UpdateBook()
        {
               fstream z1;
               z1.open("BookTemp.txt",ios::app);
               z.open("Book.txt",ios::in);
               int tid,status=0,q=0;
               cout<<"enter Book Id For Update Quantity: "<<endl;
               cin>>tid;
                while(1)
            {
                z>>bid>>bname>>aname>>quantity;
                if(z.eof())
                {
                    break;
                }
                if(tid==bid)
                {
                    cout<<" Enter the New Quantity of Book to add into Data."<<endl;
                    cin>>q;
                    if(q>0)
                    {
                         quantity=quantity+q;
                        cout<<bname<<"'s Quantity Updated successfully.\n Please Wait .";
                        for(int x=1;x<=10;x++)
                        {
                            delay();
                            cout<<" . ";
                        }
                        cout<<"\n-----------------------------------"<<endl;
                    }
                    else{
                        cout<<"\nUpdate is not possible because Quantity is less then Zero."<<endl;
                    }
                   status=1;
                }
               z1<<bid<<" "<<bname<<" "<<aname<<" "<<quantity<<endl;
            }
            if(status==0)
            {
                cout<<tid<<"  this id is not found"<<endl;
            }
              z1.close();
              z.close();
              remove("Book.txt");
              rename("BookTemp.txt","Book.txt");

        }
}b;



void Admin_Login_Function()
{
    char c;
    do
    {
             int x;
        system("cls");
        cout<<"******* ADMIN LOGIN Menu********"<<endl;
         cout<<"Press 1 Go To Employee Details."<<endl;
         cout<<"Press 2 Go To Student Details."<<endl;
         cout<<"Press 3 Go To Book Details."<<endl;
         cout<<"Press 4 EXIT from Project."<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin>>x;
         switch(x)
         {
             case 1: Employee_Function();
                            break;
             case 2: Student_Function();
                            break;
            case 3: Book_Function();
                            break;
            case 4: logout();
                        exit(1);
             default:cout<<"invalid input"<<endl;
         }
         cout<<"Do you want to GO TO Admin Login Menu. If yes then Press y:"<<endl;
         cout<<"GO To Main Menu. Press n"<<endl;
         cin.ignore();
         cin>>c;
    }while(c=='y');
}
void Employee_Login_Function()
{
    char c;
    do
    {
             int x;
        system("cls");
        cout<<"******* EMPLOYEE LOGIN Menu********"<<endl;
         cout<<"Press 1 Go To Student Details."<<endl;
         cout<<"Press 2 Go To Book Details."<<endl;
          cout<<"Press 3 EXIT from Project."<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin>>x;
         switch(x)
         {
             case 1: Student_Function();
                            break;
            case 2: Book_Function();
                            break;
             case 3:   logout();
                            exit(1);
             default:cout<<"invalid input"<<endl;
         }
         cout<<"Do you want to GO TO Employee Login Menu. If yes then Press y:"<<endl;
         cout<<"GO To Main Menu. Press n"<<endl;
         cin.ignore();
         cin>>c;
    }while(c=='y');
}
void Employee_Function()
{
    char c;
   do
   {
            int x;
        system("cls");
        cout<<"******* Employee Menu********"<<endl;
         cout<<"Press 1 Go To New Employee Details."<<endl;
         cout<<"Press 2 Go To View Employee Details."<<endl;
         cout<<"Press 3 Go To Search Employee Details."<<endl;
         cout<<"Press 4 Go To Update Employee Details."<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin>>x;
         switch(x)
         {
             case 1:  e.AddEmployee();
                            break;
             case 2:  e.ViewEmployee();
                            break;
             case 3:  e.SearchEmployee();
                            break;
             case 4: e.UpdateEmployee();
                            break;
             default:cout<<"invalid input"<<endl;
         }
         cout<<"Do you want to Go To Employee Menu, If Yes then Press y:"<<endl;
         cout<<"Go To Previous  Menu. Press n:"<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin.ignore();
         cin>>c;
   }while(c=='y');
}
class Student: public Book
{
            private:
            int id,age;
            char sname[20];
            long long mob;
            int issuebid=0;
   public:
       fstream f;
        void AddStudent()
        {
            int tid,status=0;
              f.open(" Student.txt",ios::in);
               cout<<" Enter Student Id: "<<endl;
                cin>>tid;
              if(f.fail())
              {
                  cout<<"file is not created yet. you are the first to add in data."<<endl;
              }
              else{
                    cout<<"----------Add new Student-------------\n"<<endl;

                    while(1)
                    {
                        f>>id>>sname>>age>>mob>>issuebid;
                         if(f.eof())
                         {
                             break;
                         }
                         if(id==tid)
                         {
                             status=1;
                             cout<<id<<" This Student ID is  already exit."<<endl;
                         }
                    }
                f.close();
            }

            if(status==0)
                    {
                         f.open("Student.txt",ios::app);
                   id=tid;
                    cout<<" Enter Student Name: "<<endl;
                    cin>>sname;
                    cout<<" Enter Student age: "<<endl;
                    cin>>age;
                    while(1)
                    {
                        int a;
                        cout<<" Enter Student Mobile Number: "<<endl;
                        cin>>mob;
                        a= checkmobNo(mob);
                        if(a==1)
                        {
                            break;
                        }
                        else{
                            cout<<"INPUT Mob Number is Wrong. Please enter again."<<endl;
                        }
                    }
                    f<<id<<" "<<sname<<" "<<age<<" "<<mob<<" "<<issuebid<<endl;
                    cout<<sname<<" details added successfully. \nPlease wait .";
                    for(int y=1;y<=10;y++)
                    {
                        delay();
                        cout<<" . ";
                    }
                    f.close();
            }

        }
        void ViewStudent()
        {
              f.open("Student.txt",ios::in);
              cout<<"-------------All the Student Details----------------"<<endl;
              while(1)
              {
                  f>>id>>sname>>age>>mob>>issuebid;
                 if(f.eof())
                 {
                     break;
                 }
                 cout<<"Student ID: "<<id<<endl;
                 cout<<"Student Name: "<<sname<<endl;
                 cout<<"Student Age: "<<age<<endl;
                 cout<<"Student Mobile No.: "<<mob<<endl;
                 cout<<"Issued Book Id: "<<issuebid<<endl;
                 cout<<"-------------------------------"<<endl;
              }
              f.close();
        }
        void SearchStudent()
        {
              f.open("Student.txt",ios::in);
              int tid,status=0;
              cout<<"enter Student if to search the data: "<<endl;
              cin>>tid;

              while(1)
              {
                  f>>id>>sname>>age>>mob>>issuebid;
                 if(f.eof())
                 {
                     break;
                 }
                 if(id==tid)
                 {
                     cout<<"-------------the Student Details----------------"<<endl;
                     cout<<"Student ID: "<<id<<endl;
                     cout<<"Student Name: "<<sname<<endl;
                     cout<<"Student Age: "<<age<<endl;
                     cout<<"Student Mobile No.: "<<mob<<endl;
                       cout<<"Issued Book Id: "<<issuebid<<endl;
                     cout<<"-------------------------------"<<endl;
                     status=1;
                 }
              }
              if(status==0)
              {
                  cout<<tid<<" Student id does not exit."<<endl;
              }
              f.close();
        }
        void UpdateStudent()
        {
            fstream f2;
              int s_tid,b_tid,status=0;
              cout<<"Enter Student Id for Book Issue: "<<endl;
              cin>>s_tid;
              f.open("Student.txt",ios::in);
               f2.open("StudentTemp.txt",ios::app);
                while(1)
              {
                  f>>id>>sname>>age>>mob>>issuebid;
                 if(f.eof())
                 {
                     break;
                 }
                 if(s_tid==id)
                 {
                     status=1;
                     fstream z2;
                     z.open("Book.txt",ios::in);
                      z2.open("Booktemp.txt",ios::app);
                     cout<<"enter Book Id to Issue: "<<endl;
                     cin>>b_tid;
                     while(1)
                     {
                          z>>bid>>bname>>aname>>quantity;
                          if(z.eof())
                          {
                              break;
                          }
                          if(b_tid==bid)
                          {

                              if(quantity>0)
                              {
                                  issuebid=bid;
                                  quantity=quantity-1;
                              }
                              cout<<sname<<" Book issued successfully.  \nPlease wait .";
                                for(int y=1;y<=10;y++)
                                {
                                    delay();
                                    cout<<" . ";
                                }
                          }
                           z2<<bid<<" "<<bname<<" "<<aname<<" "<<quantity<<endl;
                     }
                     z2.close();
                     z.close();
                     remove("Book.txt");
                     rename("Booktemp.txt","Book.txt");
                 }
                  f2<<id<<" "<<sname<<" "<<age<<" "<<mob<<" "<<issuebid<<endl;
              }

              if(status==0)
              {
                  cout<<s_tid<<" Student id does not exit."<<endl;
              }
              f.close();
              f2.close();
              remove("Student.txt");
            rename("StudentTemp.txt","Student.txt");

        }
}s;
void Student_Function()
{
         char c;
   do
   {
            int x;
        system("cls");
        cout<<"******* Student Menu********"<<endl;
         cout<<"Press 1 Go To New Student Details."<<endl;
         cout<<"Press 2 Go To View Student Details."<<endl;
         cout<<"Press 3 Go To Search Student Details."<<endl;
         cout<<"Press 4 Go To Update Student Details."<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin>>x;
         switch(x)
         {
             case 1:  s.AddStudent();
                            break;
             case 2:   s.ViewStudent();
                            break;
             case 3:  s.SearchStudent();
                            break;
             case 4:  s.UpdateStudent();
                            break;
             default:cout<<"invalid input"<<endl;
         }
         cout<<"Do you want to Go To Student Menu, If Yes then Press y:"<<endl;
         cout<<"Go To Previous Menu. Press n:"<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin.ignore();
         cin>>c;
   }while(c=='y');
}

void Book_Function()
{
     char c;
   do
   {
            int x;
            system("cls");
        cout<<"******* Book Menu********"<<endl;
         cout<<"Press 1 Go To New Book Details."<<endl;
         cout<<"Press 2 Go To View Book Details."<<endl;
         cout<<"Press 3 Go To Search Book Details."<<endl;
         cout<<"Press 4 Go To Update Book Details."<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin>>x;
         switch(x)
         {
             case 1:  b.AddBook();
                            break;
             case 2:   b.ViewBook();
                            break;
             case 3: b.SearchBook();
                            break;
             case 4: b.UpdateBook();
                            break;
             default:cout<<"invalid input"<<endl;
         }
         cout<<"\nDo you want to GO To Book Menu, If Yes then Press y:"<<endl;
         cout<<"Go To Previous Menu. Press n:"<<endl;
         cout<<"Enter Your Choice: "<<endl;
         cin.ignore();
         cin>>c;
   }while(c=='y');
}

int password()
{
    char ch;
    char username[20];
    char pass[20];
    int i=0;
    cout<<"enter Username: "<<endl;
    cin>>username;
    cout<<"enter password: "<<endl;
    ch=getch();
    while(ch!=13)
    {
        cout<<"*";
        pass[i]=ch;
         ch=getch();
         i++;
    }
    pass[i]='\0';

    if(!strcmp(username,"Admin") && !strcmp(pass,"Admin"))
    {
        cout<<"Login Successfully"<<endl;
        return 1;
    }
    else
    {
        cout<<"Wrong ID & Password. Please Try Again"<<endl;
        return 0;
    }


}


void logout()
{
    char bye[80]={"*************Thank you.....LOGOUT From Project*************\n"};
    for(int i=0;bye[i]!='\0';i++)
    {
        cout<<bye[i];
        delay();
    }
}
main()
{
    char ch;
    gotoxy(5,5);
    system("color 70");
    char welcome[50]={"*************Library Details*************\n"};
    for(int i=0;welcome[i]!='\0';i++)
    {
        cout<<welcome[i];
        delay();
    }
     do
     {
             int x,r;
         gotoxy(14,7);
          cout<<"******* Main Menu********"<<endl;
          gotoxy(14,8);
         cout<<"Press 1 Go To Admin Login."<<endl;
         gotoxy(14,9);
         cout<<"Press 2 Go To Employee Login."<<endl;
         gotoxy(14,10);
         cout<<"Enter Your Choice: "<<endl;
         gotoxy(14,12);
         cin>>x;
         switch(x)
         {
             case 1:  r=password();
                            if(1==1)
                            {
                                Admin_Login_Function();
                            }
                            break;
             case 2:   Employee_Login_Function();
                            break;
             default:cout<<"invalid input"<<endl;
         }
         cout<<"Do you want to Go To Main Menu, If yes than press y: "<<endl;
         cin.ignore();
         cin>>ch;
         if(ch!='y')
         {
              cout<<"Are you sure you want to exit from the project. if no then press y: "<<endl;
              cin.ignore();
              cin>>ch;
         }
         system("cls");
     }while(ch=='y');
     logout();
}
