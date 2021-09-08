#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include<cstdlib>



using namespace std;

int rec_flag_student=0,no_student=0;
char rec_ind_student[5];
//For students
struct student
{
 char fname[20];//for student first name
 char lname[20];//for student last name
 char registrationid[20];//for Registration No number
 char age[5];//student phone
 char feestatus[10];//fee status of students
 char cel_no[20];//Phone number
 char batch[20];//for class info
 char ind[5];//for index

}studentData[20];//Variable of student type

struct index
{
char registrationid[20],indstudent[20];
}instudent[20],tempstudent;

void sort_index_student()
{
int i,j;

for(i=0;i<no_student-1;i++)
for(j=0;j<no_student-i-1;j++)
if(strcmp(instudent[j].registrationid,instudent[j+1].registrationid)>0)
{
tempstudent=instudent[j];
instudent[j]=instudent[j+1];
instudent[j+1]=tempstudent;
}
}

void retrive_record_student(char *ind)
{
for(int i=0;i<no_student;i++)
{
if(strcmp(studentData[i].ind,ind)==0)
{
strcpy(rec_ind_student,ind);
rec_flag_student=1;
cout<<"Record found:\n";
cout<<studentData[i].ind<<"\t\t"<<studentData[i].fname<<"\t\t"<<studentData[i].lname<<"\t\t"<<studentData[i].registrationid<<"\t\t"<<studentData[i].age<<"\t"<<studentData[i].cel_no<<"\t"<<studentData[i].batch<<"\n";
            return;
}
}

cout<<"Press any key to continue\n";
    getch();
}

int search_index_student(char *registrationid)
{
int flag=0;
for(int i=0;i<no_student;i++)
{
if(strcmp(instudent[i].registrationid,registrationid)==0)
{
retrive_record_student(instudent[i].indstudent);
flag=1;
}
}
if(flag)
return 1;
else
return -1;
}

int search_id_student(char *registrationid,int j)
{
int flag=0;
for(int i=0;i<j;i++)
{
if(strcmp(studentData[i].registrationid,registrationid)==0)
{
flag=1;
break;
}
}
if(flag)
return 1;
else
return -1;
}


void delet_student(char *st_registrationid)
{
rec_flag_student=0;
int fr=0;
search_index_student(st_registrationid);
if(!rec_flag_student)
{
cout<<"Deletion failed.Record not found\n";
cout<<"Press any key to continue\n";
getch();
return;

}
for(int i=0;i<no_student;i++)
{
if(strcmp(studentData[i].ind,rec_ind_student)==0)
{
fr=i;
break;
}
}
for(int i=fr;i<no_student-1;i++)
{
studentData[i]=studentData[i+1];
char str[3];
sprintf(str,"%d",i);
strcpy(studentData[i].ind,str);
}
no_student--;
fstream f1,f2;
f1.open("record_student.txt",ios::out);
f2.open("index_student.txt",ios::out);
for(int i=0;i<no_student;i++)
{
strcpy(instudent[i].registrationid,studentData[i].registrationid);
strcpy(instudent[i].indstudent,studentData[i].ind);
}
sort_index_student();
for(int i=0;i<no_student;i++)
{
   f1<<studentData[i].ind<<"|"<<studentData[i].fname<<"|"<<studentData[i].lname<<"|"<<studentData[i].registrationid<<"|"<<studentData[i].feestatus<<"|"<<studentData[i].age<<"|"<<studentData[i].cel_no<<"|"<<studentData[i].batch<<"\n";
f2<<instudent[i].registrationid<<"|"<<instudent[i].indstudent<<"\n";
}
f1.close();
f2.close();
cout<<"Deletion successful\n";
cout<<"Press any key to continue\n";
getch();
}

void update_status(char *id)
{

    for (int k = 0;k<no_student;k++)
    {
        if(strcmp(studentData[k].registrationid,id)==0)
        {
            if (strcmp(studentData[k].feestatus,"unpaid")==0)
            {
                strcpy(studentData[k].feestatus,"paid");
            }
        }
    }
    fstream f1;
f1.open("record_student.txt",ios::out);
    for(int k = 0;k<no_student;k++ )
    {

        f1<<studentData[k].ind<<"|"<<studentData[k].fname<<"|"<<studentData[k].lname<<"|"<<studentData[k].registrationid<<"|"<<studentData[k].feestatus<<"|"<<studentData[k].age<<"|"<<studentData[k].cel_no<<"|"<<studentData[k].batch<<"\n";
    }
    f1.close();
    cout<<"Updation successful";
    cout<<"Press any key to continue";
    getch();
}


///////////////////////////////////////////////////
//Main function

int main()
{
fstream ff,fi;
ff.open("record_student.txt",ios::in);
for(int i=0;i<100;i++)
{
ff.getline(studentData[i].ind,5,'|');
if(strcmp(studentData[i].ind,"")==0)
break;
ff.getline(studentData[i].fname,20,'|');
ff.getline(studentData[i].lname,20,'|');
ff.getline(studentData[i].registrationid,20,'|');
ff.getline(studentData[i].feestatus,10,'|');
ff.getline(studentData[i].age,5,'|');
ff.getline(studentData[i].cel_no,20,'|');
ff.getline(studentData[i].batch,20,'\n');
 int m=atoi(studentData[i].ind); 
if(i==m)
	no_student++;
else
	break;              
}
ff.close();
fi.open("index_student.txt",ios::out);
for(int i=0;i<no_student;i++)
{
strcpy(instudent[i].registrationid,studentData[i].registrationid);
strcpy(instudent[i].indstudent,studentData[i].ind);
}
sort_index_student();
for(int i=0;i<no_student;i++)
{
fi<<instudent[i].registrationid<<"|"<<instudent[i].indstudent<<"\n";
}
fi.close();

 //Level 1-Display process

cout<<"                              \t\tSCHOOL MANAGEMENT SYSTEM\n";
cout<<"\n\n\n";
cout<<"                                   \t\t  HELLO \n\n\n";
cout<<"                                     \t\t press ENTER to continue.....\n";
if(cin.get()=='\n')
{

    char fname[20];//for student first name
    char lname[20];//for student last name
    char registrationid[20];//for Registration No number
    char st_registrationid[20];
    char age[5];//student phone
    char feestatus[10];//fee status of student
    char cel_no_student[20];//Phone number
    char batch_student[20];//for class info
    char ind_student[5];//for index


    fstream file1;
    int i=0,j;//for processing usage
    char choice;//for getting choice
    int n;
while(1)//inner loop-1
{
system("cls");//Clear screen
//Level-2 display
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\t\t\tSCHOOL MANAGEMENT SYSTEM\n\n";
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\t\t\t\tHOME PAGE\n\n";
 cout<<"This is a School management system,used to maintain the records of students  in the school\n\n";
cout<<"\n\n\t\t\t\t\tSTUDENTS INFORMATION \n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.New Admission\n";
cout<<"2.Find Student\n";
cout<<"3.Check fee status\n";
cout<<"4.Remove Student\n";
cout<<"5.Display Students Batch-wise\n";
cout<<"6.Display all Students\n";
cout<<"7.Update Fee status\n";
cout<<"8.Exit\n";
cin>>choice;

switch (choice)//Second switch

{
    case '1'://Insert data
    {
        file1.open("record_student.txt",ios::out|ios::app);

        while(choice!='n')
        {

            if((choice=='y')||(choice=='Y')||(choice=='1'))
            {

                cout<<"enter the no of students:\t";
                cin>>n;
                cout<<"enter the details\n";
                for(i = no_student;i<no_student+n;i++)
{
label: cout<<"enter "<<i+1<<" student details:\n";
cout<<"First name : ";
cin>>studentData[i].fname;
cout<<"Last name : ";
cin>>studentData[i].lname;
cout<<"Registration Id : ";
cin>>studentData[i].registrationid;
cout<<"Fee Status : ";
cin>>studentData[i].feestatus;
cout<<"Age : ";
cin>>studentData[i].age;
cout<<"Batch Allotted : ";
cin>>studentData[i].batch;
cout<<"Contact Number : ";
cin>>studentData[i].cel_no;
int q = search_id_student(studentData[i].registrationid,i);
if(q==1)
{
cout<<"Duplicate value\n";
cout<<"enter again:\n";
goto label;
}
file1<<i<<"|"<<studentData[i].fname<<"|"<<studentData[i].lname<<"|"<<studentData[i].registrationid<<"|"<<studentData[i].feestatus<<"|"<<studentData[i].age<<"|"<<studentData[i].cel_no<<"|"<<studentData[i].batch<<"\n";

}
no_student=no_student+n;
cout<<"Do you want to enter more data?\n ";
                cout<<"Press Y for Continue and N to Finish:  ";
                cin>>choice;

            }
        }
                file1.close();

fstream file1,file2;
file1.open("record_student.txt",ios::in);
file2.open("index_student.txt",ios::out);
for(int i=0;i<no_student;i++)
{
file1.getline(ind_student,5,'|');
file1.getline(fname,20,'|');
file1.getline(lname,20,'|');
file1.getline(registrationid,20,'|');
file1.getline(feestatus,10,'|');
file1.getline(age,5,'|');
file1.getline(cel_no_student,20,'|');
file1.getline(batch_student,20,'\n');
strcpy(studentData[i].ind,ind_student);
strcpy(instudent[i].registrationid,registrationid);
strcpy(instudent[i].indstudent,ind_student);
}
sort_index_student();
for(int i=0;i<no_student;i++)
{
file2<<instudent[i].registrationid<<"|"<<instudent[i].indstudent<<"\n";
}
file1.close();
file2.close();
    }
continue;//control back to inner loop -1

case '2'://search data
{
                cout<<"Enter the Id of the student whose record is to be searched:\t";
cin>>st_registrationid;
int q=search_index_student(st_registrationid);
if(q==1){
cout<<"Search successful\n";
cout<<"Press any key to continue\n";
                    getch();
}
else{
cout<<"Search unsuccessful\n";
cout<<"Press any key to continue\n";
                    getch();
}

}
continue;//control back to inner loop -1

case '3'://print fee status
    {
        char ch;
        cout<<"Choose the kind of status\n";
        cout<<"1.Paid\n";
        cout<<"2.Unpaid\n";
        cin>>ch;
        if(ch== '1')
        {
            cout<<"Students who have paid the fees\n";
                   cout<<"Index\tFname\tLname\tReg. ID\tFee Status\tAge\tPhno\n";
            for (int k=0;k<no_student;k++)
            {    
                if (strcmp(studentData[k].feestatus,"paid")==0)
                {
                   cout<<k<<"\t"<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].feestatus<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;
                }


            }

        }

        else if(ch == '2'){

                cout<<"Students who have not paid the fees\n";
               cout<<"Index\tFname\tLname\tReg. ID\tFee Status\tAge\tPhno\n";
            for (int k=0;k<no_student;k++)
            {
                if (strcmp(studentData[k].feestatus,"unpaid")==0)
                {
                   cout<<k<<"\t"<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].feestatus<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;
                }


            }


        }
        cout<<"Press any key to continue";
        getch();

    }

    continue;

case '4'://delete data

    {
                cout<<"Enter the Id of the student whose record is to be deleted:\t";
cin>>st_registrationid;
delet_student(st_registrationid);
    }
    continue;//control back to inner loop -1

case '5'://display students batch-wise
    {
        char bat[10];
        cout<<"Enter the batch whose record you want to display\n";
        cin>>bat;
        for(int k = 0;k<no_student;k++)
        {
            if(strcmp(studentData[k].batch,bat)==0)
            {
                cout<<k<<"\t"<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;

            }
        }

        cout<<"Press any key to continue\n";
        getch();
    }
    continue;



case '6'://display all data
{
fstream f1;
f1.open("record_student.txt",ios::in);
if(!f1)
{
cout<<"Error!!!";
exit(0);
}
int i=0;
      cout<<"Index\tFname\tLname\tReg.ID\t\tFee Status\tAge\tPhno\t\tBatch\n";
while(i!=no_student)
{
   cout<<studentData[i].ind<<"\t"<<studentData[i].fname<<"\t"<<studentData[i].lname<<"\t"<<studentData[i].registrationid<<"\t"<<studentData[i].feestatus<<"\t\t"<<studentData[i].age<<"\t"<<studentData[i].cel_no<<"\t"<<studentData[i].batch<<"\n";
   i++;
}
f1.close();
cout<<"Press any key to continue\n";
getch();
}
continue;

case '7': {
            char id[20];
            cout<<"Students who have not paid the fees\n";
                 cout<<"Index\tFirst Name\tLast Name\tReg. ID\tFee Status\tAge\tPhno\n";
            for (int k=0;k<no_student;k++)
            {
                if (strcmp(studentData[k].feestatus,"unpaid")==0)
                {
                   cout<<k<<"\t"<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].feestatus<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;
                }


            }

            cout<<"Enter the Id of the student whose status you want to update\n";
            cin>>id;
            update_status(id);


        }
        continue;

case '8':
{
cout<<"thankyou for using software\n";
exit(0);
}
}
}
}
}
