#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
void password();
void menu();
void add_new_student();
void delete_record();
void search_for_student();
void list_students();
void update_details();
void exit_program();
void go(int x,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void main()
{
   password();
}
void password()
{
    system("color A");
    go(43,2);
    char pass[]={"WELCOME TO IIT BHUBANESWAR"};
    int l=strlen(pass);
    for(int j=0;j<20;j++){
        printf("%c",16);
		Sleep(30);}
         printf("  ");
		for(int j=0;j<l;j++)
        {
          printf("%c",pass[j]);
          Sleep(50);
        }
        printf("  ");
        for(int j=0;j<20;j++)
        {
          printf("%c",17);
		  Sleep(30);
        }
        go(50,4);
        printf("User ID: ");
        char user[]={"Admin@iitbbs"},check_user[20];
        char use;
        int i=0;
        while (use!=13)
        {
            use=getch();
            if(use!=13)
            {
                printf("%c",use);
                check_user[i]=use;
                i++;
            }
            check_user[i]='\0';
        }
        go(50,6);
        printf("Password: ");
        char ch,enter[20];
       char check_password[]={"IITBBS"};
         i=0;
         int count;
        char w='*';
        while(ch!=13)
        {
            ch=getch();
            if(ch!=13){
           printf("%c",w);
           enter[i]= ch;
           i++;}
        }
        enter[i]='\0';
        Sleep(600);
        if(strcmp(enter,check_password)==0 && strcmp(user,check_user)==0)
           count=1;
        else
            count=0;
        char correct[]={"CORRECT PASSWORD"};
        char wrong[]={"INVALID PASSWORD"};
        go(50,8);
        if(count)
        {
            for(i=0;i<strlen(correct);i++)
            {
                printf("%c",correct[i]);
                Sleep(50);
            }
            Sleep(500);
            menu();
        }
        else
        {
            for(i=0;i<strlen(wrong);i++)
            {
                printf("%c",wrong[i]);
                Sleep(50);
            }
            system("cls");
           password();
        }
}
void menu()
{
    system("cls");
    system("color B");
    go(50,2);
    int i;
    char s[]={"STUDENTS INFO"};
    for(i=0;i<20;i++)
    {
        printf("\xDB");
        Sleep(30);
    }
    printf("  ");
    for(i=0;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        Sleep(50);
    }
    printf("  ");
    for(i=0;i<20;i++)
    {
        printf("\xDB");
        Sleep(30);
    }
    go(50,6);
    for(i=0;i<5;i++)
    {
        printf("\xCD");
    }
    printf("\xAF");
    printf(" 1.ADD NEW STUDENT");
    Sleep(500);
    go(50,10);
    for(i=0;i<5;i++)
    {
        printf("\xCD");
    }
    printf("\xAF");
    printf(" 2.SEARCH FOR STUDENT");
    Sleep(500);
    go(50,14);
    for(i=0;i<5;i++)
    {
        printf("\xCD");
    }
    printf("\xAF");
    printf(" 3.LIST OF STUDENTS");
    Sleep(500);
    go(50,18);
    for(i=0;i<5;i++)
    {
        printf("\xCD");
    }
    printf("\xAF");
    printf(" 4.UPDATE DETAILS");
    Sleep(500);
    go(50,22);
    for(i=0;i<5;i++)
    {
        printf("\xCD");
    }
    printf("\xAF");
    printf(" 5.DELETE A RECORD");
    Sleep(500);
    go(50,26);
    for(i=0;i<5;i++)
    {
        printf("\xCD");
    }
    printf("\xAF");
    printf(" 6.EXIT");
    switch(getch())
    {
   case '1':
        add_new_student();
        break;
    case '2':
        search_for_student();
        break;
    case '3':
        list_students();
        break;
    case '4':
        update_details();
        break;
    case '5':
        delete_record();
        break;
    case '6':
        exit_program();
        break;
    default:
        system("cls");
        printf("Invalid Enter");
        Sleep(100);
        menu();
        getch();
    }
}
void exit_program()
{
   system("cls");
   system("color D");
   go(50,2);
   int i;
   for(i=0;i<20;i++)
   {
       printf("\xDB");
       Sleep(30);
   }
   printf("  ");
   char team[]={"Team Members"};
   for(i=0;i<strlen(team);i++)
   {
       printf("%c",team[i]);
       Sleep(50);
   }
   printf("  ");
   for(i=0;i<20;i++)
   {
       printf("\xDB");
       Sleep(30);
   }
   go(52,4);
   printf("1.B Venkata Jagadeesh");
   Sleep(500);
   go(52,6);
   printf("2.M Hemanth");
   Sleep(500);
   go(52,8);
   printf("3.M Pardhiva Sri Sai");
   Sleep(500);
   go(52,10);
   printf("4.K Susheel Kumar");
   Sleep(500);
   go(52,12);
   printf("5.R Kartheek");
   Sleep(500);
   getch();
}
void add_new_student()
{
    system("cls");
    system("color D");
    go(50,2);
    int i;
    for(i=0;i<20;i++)
    {
        printf("\xAF");
        Sleep(30);
    }
    printf("  ");
    char student[]={"DETAILS OF NEW STUDENT"};
    for(i=0;i<strlen(student);i++)
    {
        printf("%c",student[i]);
        Sleep(50);
    }
    printf("  ");
    for(i=0;i<20;i++)
    {
        printf("\xAE");
        Sleep(30);
    }
     FILE *fp;
    char name[100],gender[11],dob[10],email[50];
    unsigned long long phone;
    fp=fopen("pds.txt","a+");
    if(fp==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    else
    {
        go(55,4);
        printf("NAME:");
        go(71,4);
        gets(name);
        fprintf(fp,"%s\n",name);
        go(55,6);
        printf("GENDER:");
        go(71,6);
        gets(gender);
        fprintf(fp,"%s\n",gender);
        go(55,8);
        printf("DATE OF BIRTH:");
        go(71,8);
        gets(dob);
        fprintf(fp,"%s\n",dob);
        go(55,10);
        printf("EMAIL ID:");
        go(71,10);
        gets(email);
        fprintf(fp,"%s\n",email);
        go(55,12);
        printf("PHONE NUMBER:");
        go(71,12);
        scanf("%llu",&phone);
        fprintf(fp,"%llu\n",phone);
        go(55,14);
        printf("SELECT A BLOOD GROUP:");
        go(55,16);
        printf("1. 'A' POSITIVE \t 2.'A' NEGATIVE");
        go(55,17);
         printf("3. 'B' POSITIVE \t 4.'B' NEGATIVE");
        go(55,18);
         printf("5. '0' POSITIVE \t 5.'O' NEGATIVE");
         go(55,19);
          printf("7.'AB' POSITIVE \t 8.'AB' NEGATIVE");
          label:
          switch(getch())
          {
          case '1':
            fputs("'A' POSTIVE\n",fp);
            break;
           case '2':
            fputs("'A' NEGATIVE\n",fp);
            break;
            case '3':
            fputs("'B' POSTIVE\n",fp);
            break;
           case '4':
            fputs("'B' NEGATIVE\n",fp);
            break;
            case '5':
            fputs("'O' POSTIVE\n",fp);
            break;
           case '6':
            fputs("'O' NEGATIVE\n",fp);
            break;
            case '7':
            fputs("'AB' POSTIVE\n",fp);
            break;
           case '8':
            fputs("'AB' NEGATIVE\n",fp);
            break;
           default:
             goto label;
          }
          go(55,21);
          printf("SELECT A BRANCH:");
          go(55,23);
          printf("A.CSE(4 YEARS BTECH)\tB.CSE(5 YEARS DUAL DEGREE)");
          go(55,24);
          printf("C.ECE(4 YEARS B TECH)");
          go(55,25);
          printf("D.EE(4 YEARS B TECH)\tE.EE(5 YEARS DUAL DEGREE)");
          go(55,26);
          printf("F.ME(4 YEARS B TECH)\tG.ME(5 YEARS DUAL DEGREE)");
          go(55,27);
          printf("H.CE(4 YEARS B TECH)\tI.CE(5 YEARS DUAL DEGREE)");
          go(55,28);
          printf("J.MM(4 YEARS B TECH)\tK.MM(5 YEARS DUAL DEGREE)");
          char ch;
          a:
          ch=getch();
          switch(ch)
          {
          case 'A':
            fputs("CSE(4 YEARS B TECH)\n",fp);
            break;
          case 'B':
            fputs("CSE(5 YEARS DUAL DEGREE)\n",fp);
            break;
          case 'C':
              fputs("ECE(4 YEARS B TECH)\n",fp);
              break;
          case 'D':
            fputs("EE(4 YEARS B TECH)\n",fp);
            break;
          case 'E':
            fputs("EE(5 YEARS DUAL DEGREE)\n",fp);
            break;
          case 'F':
            fputs("ME(4 YEARS B TECH)\n",fp);
            break;
          case 'G':
            fputs("ME(5 YEARS DUAL DEGREE)\n",fp);
            break;
          case 'H':
                fputs("CE(4 YEARS B TECH)\n",fp);
                break;
          case 'I':
                fputs("CE(5 YEARS DUAL DEGREE)\n",fp);
                break;
          case 'J':
                fputs("MM(4 YEARS B TECH)\n",fp);
                break;
          case 'K':
                fputs("MM(5 YEARS B TECH)\n",fp);
                break;
          default:
          goto a;
          }
go(55,30);
        printf("RECORD ADDED SUCCESSFULLY");
        fclose(fp);
        fflush(stdin);
    }
    char q;
go(10,34);
printf("Press a to add another student details");
go(10,36);
printf("Press m to go to menu");
q=getch();
  if(q=='a')
  {
     add_new_student();
  }
   else if(q=='m')
   {
     menu();
   }
   else
   {
     exit(0);
   }
}
void search_for_student()
{
system("cls");
system("color D");
go(43,1);
int i;
    for(i=0;i<20;i++)
    {
        printf("\xAF");
        Sleep(30);
    }
printf("  ");
char p[]={"SEARCHING STUDENT DETAILS"};
        for(i=0;p[i]!='\0';i++)
        {
            printf("%c",p[i]);
            Sleep(30);
        }
printf("  ");
    for(i=0;i<20;i++)
    {
        printf("\xAE");
        Sleep(30);
    }
FILE *fp;
char c[100];
int count=0;
fflush(stdin);
go(43,3);
printf("Enter the name of the student:");
go(75,3);
scanf("%[^\n]",c);
char name[50],gender[7],dob[15],emailid[100],bloodgrp[15],branch[100];
unsigned long long phoneno;
fp=fopen("pds.txt","r");
    if(fp==NULL)
    {
        printf("such file do not exist ");
        exit(0);
    }
       while(fscanf(fp,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,emailid,&phoneno,bloodgrp,branch)!=EOF)
       {
           if(strcmp(c,name)==0)
           {
               count++;
            go(60,6);
                for(i=0;i<6;i++)
                {
                  printf("\xDB");
                  Sleep(10);
                }
            printf("  ");
            printf("Record found");
            printf("  ");
                for(i=0;i<6;i++)
                {
                    printf("\xDB");
                    Sleep(10);
            }
        for(i=5;i<22;i++)
        {
            go(50,i);
            printf("%c",179);
            go(110,i);
            printf("%c",179);
        }
go(50,4);printf("%c",218);
go(110,4);printf("%c",191);
go(50,22);printf("%c",192);
go(110,22);printf("%c",217);
        for(i=51;i<110;i++)
        {
            go(i,4);
            printf("%c",196);
            go(i,22);
            printf("%c",196);
        }
            go(60,8);
            printf("NAME:");
            go(80,8);
            puts(c);
            go(60,10);
            printf("Gender:");
            go(80,10);
            puts(gender);
            go(60,12);
            printf("DATE OF BIRTH:");
            go(80,12);
            puts(dob);
            go(60,14);
            printf("EMAIL ID:");
            go(80,14);
            puts(emailid);
            go(60,16);
            printf("PHONE NUMBER:");
            go(80,16);
            printf("%llu",phoneno);
            go(60,18);
            printf("BLOOD GROUP:");
            go(80,18);
            puts(bloodgrp);
            go(60,20);
            printf("BRANCH:");
            go(80,20);
            puts(branch);
            }
       }
if(count==0)
{
go(60,6);
printf("SUCH STUDENT RECORD NOT EXIST");
}
go(40,28);
printf("Press s to search for another student details");
go(40,30);
printf("Press m to go to menu");
char q;
q=getch();
  if(q=='s')
  {
     search_for_student();
  }
   else if(q=='m')
   {
     menu();
   }
   else
   {
     exit(0);
   }
}
void delete_record()
{
system("cls");
system("color D");
go(42,2);
int i;
     for(i=0;i<20;i++)
     {
         printf("\xAF");
         Sleep(30);
     }
printf("  ");
char x[]={"DELETION OF STUDENT DETAILS"};
     for(i=0;x[i]!='\0';i++)
     {
         printf("%c",x[i]);
         Sleep(20);
     }
printf("  ");
      for(i=0;i<20;i++)
      {
          printf("\xAE");
          Sleep(30);
      }
go(42,4);
char p[50];
printf("Enter the name of the student:");
go(80,4);
scanf("%[^\n]",p);
FILE *fp,*fp1;
char name[50],gender[7],dob[15],emailid[100],bloodgrp[15],branch[100];
unsigned long long phoneno;
int count=0;
fp=fopen("pds.txt","r");
fp1=fopen("project.txt","w");
         for(;fscanf(fp,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,emailid,&phoneno,bloodgrp,branch)!=EOF;)
         {
             if(strcmp(p,name)==0)
             {
                 count++;
             }
         }
if(count==0)
{
go(42,6);
printf("SUCH STUDENT RECORD DOES NOT EXIST");
}
else
{
rewind(fp);
    for(;fscanf(fp,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,emailid,&phoneno,bloodgrp,branch)!=EOF;)
    {
        if(strcmp(p,name)!=0)
        {
            fprintf(fp1,"%s\n%s\n%s\n%s\n%llu\n%s\n%s\n",name,gender,dob,emailid,phoneno,bloodgrp,branch);
        }
    }
fclose(fp);
fclose(fp1);
fp=fopen("pds.txt","w");
fclose(fp);
fp=fopen("pds.txt","a");
fp1=fopen("project.txt","r");
        for(;fscanf(fp1,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,emailid,&phoneno,bloodgrp,branch)!=EOF;)
        {
            fprintf(fp,"%s\n%s\n%s\n%s\n%llu\n%s\n%s\n",name,gender,dob,emailid,phoneno,bloodgrp,branch);
        }
fclose(fp1);
fclose(fp);
fp1=fopen("project.txt","w");
fclose(fp1);
go(42,10);
printf("STUDENT DETAILS DELETED SUCCESFULLY");
}
go(42,14);
printf("Press d to delete another student details");
go(42,16);
printf("Press m to go to menu");
fflush(stdin);
char q;
q=getch();
  if(q=='d')
  {
     delete_record();
  }
   else if(q=='m')
   {
     menu();
   }
   else
   {
     exit(0);
   }
}
void list_students()
{
system("cls");
    system("color D");
    go(48,3);
    int i;
    for(i=0;i<20;i++)
    {
        printf("\xAF");
        Sleep(30);
    }
    printf("  ");
    char student[]={"LIST OF STUDENTS"};
    for(i=0;i<strlen(student);i++)
    {
        printf("%c",student[i]);
        Sleep(50);
    }
    printf("  ");
    for(i=0;i<20;i++)
    {
        printf("\xAE");
        Sleep(30);
    }
FILE *fp;
    char ch;
    char name[100],gender[11],dob[10],email[50];
    unsigned long long int phoneno;
    char bloodgrp[15],branch[100];
    static int count=1;
   fp=fopen("pds.txt","r");
 if(fp==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
else
{
    for(i=1;i>0;i++)
     { if(i==count)
      {
         fscanf(fp,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,email,&phoneno,bloodgrp,branch);
            go(60,8);
            printf("NAME:");
            go(80,8);
            puts(name);
            go(60,10);
            printf("Gender:");
            go(80,10);
            puts(gender);
            go(60,12);
            printf("DATE OF BIRTH:");
            go(80,12);
            puts(dob);
            go(60,14);
            printf("EMAIL ID:");
            go(80,14);
            puts(email);
            go(60,16);
            printf("PHONE NUMBER:");
            go(80,16);
            printf("%llu",phoneno);
            go(60,18);
            printf("BLOOD GROUP:");
            go(80,18);
            puts(bloodgrp);
            go(60,20);
            printf("BRANCH:");
            go(80,20);
            puts(branch);
        for(i=7;i<22;i++)
        {
            go(50,i);
            printf("%c",179);
            go(110,i);
            printf("%c",179);
        }
            go(50,6);printf("%c",218);
            go(110,6);printf("%c",191);
            go(50,22);printf("%c",192);
            go(110,22);printf("%c",217);
        for(i=51;i<110;i++)
        {
            go(i,6);
            printf("%c",196);
            go(i,22);
            printf("%c",196);
        }
    break;
      }
      else
      {
        fscanf(fp,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,email,&phoneno,bloodgrp,branch);
      }
     }
fflush(stdin);
go(40,25);
printf("(*) USE n TO MOVE TO NEXT STUDENT.(*)\n");
go(40,26);
printf("(*) USE p TO MOVE TO PREVIOUS STUDENT.(*)\n");
go(40,27);
printf("(*) Press m to go to menu.");
char ch;
ch=getch();
if(ch==110)
{
    count=count+1;
    system("cls");
    list_students();
}
else if(ch==112)
{
    if(count==1)
    {count=1;}
    else
    {
    {count=count-1;}
    }
    system("cls");
    list_students();
}

else if(ch=='m')
{
    fclose(fp);
menu();
}
else
   {
       exit(0);
   }
}
}
void update_details()
{
system("cls");
system("color D");
go(45,2);
int i,var=0;
    for(i=0;i<20;i++)
    {
        printf("\xAF");
        Sleep(30);
    }
printf("  ");
char p[]={"UPDATE STUDENT DETAILS"};
        for(i=0;p[i]!='\0';i++)
        {
            printf("%c",p[i]);
            Sleep(30);
        }
printf("  ");
    for(i=0;i<20;i++)
    {
        printf("\xAE");
        Sleep(30);
    }
FILE *ptr1=NULL,*ptr2=NULL;
char name[100],gender[11],dob[10],email[50],bloodgrp[15],branch[100],student[100],c;
char name_modify[100],gender_modify[11],dob_modify[10],email_modify[50],bloodgrp_modify[15],branch_modify[100];
unsigned long long int phoneno,phoneno_modify;
go(45,4);
printf("Enter the name of the student to update the details:");
gets(student);
ptr1=fopen("pds.txt","r");
ptr2=fopen("modify.txt","a");
while(fscanf(ptr1,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,email,&phoneno,bloodgrp,branch)!=EOF)
{
        if(strcmp(student,name)==0)
        {
        var=1;
        go(55,6);
        printf("NAME:");
        go(71,6);
        gets(name_modify);
        fprintf(ptr2,"%s\n",name_modify);
        go(55,8);
        printf("GENDER:");
        go(71,8);
        gets(gender_modify);
        fprintf(ptr2,"%s\n",gender_modify);
        go(55,10);
        printf("DATE OF BIRTH:");
        go(71,10);
        gets(dob_modify);
        fprintf(ptr2,"%s\n",dob_modify);
        go(55,12);
        printf("EMAIL ID:");
        go(71,12);
        gets(email_modify);
        fprintf(ptr2,"%s\n",email_modify);
        go(55,14);
        printf("PHONE NUMBER:");
        go(71,14);
        scanf("%llu",&phoneno_modify);
        fprintf(ptr2,"%llu\n",phoneno_modify);
        go(55,16);
        printf("SELECT A BLOOD GROUP:");
        go(55,17);
        printf("1. 'A' POSITIVE \t 2.'A' NEGATIVE");
        go(55,18);
         printf("3. 'B' POSITIVE \t 4.'B' NEGATIVE");
        go(55,19);
         printf("5. '0' POSITIVE \t 5.'O' NEGATIVE");
         go(55,20);
          printf("7.'AB' POSITIVE \t 8.'AB' NEGATIVE");
          label:
          switch(getch())
          {
          case '1':
            fputs("'A' POSTIVE\n",ptr2);
            break;
           case '2':
            fputs("'A' NEGATIVE\n",ptr2);
            break;
            case '3':
            fputs("'B' POSTIVE\n",ptr2);
            break;
           case '4':
            fputs("'B' NEGATIVE\n",ptr2);
            break;
            case '5':
            fputs("'O' POSTIVE\n",ptr2);
            break;
           case '6':
            fputs("'O' NEGATIVE\n",ptr2);
            break;
            case '7':
            fputs("'AB' POSTIVE\n",ptr2);
            break;
           case '8':
            fputs("'AB' NEGATIVE\n",ptr2);
            break;
           default:
             goto label;
          }
          go(55,22);
          printf("SELECT A BRANCH:");
          go(55,24);
          printf("A.CSE(4 YEARS BTECH)\tB.CSE(5 YEARS DUAL DEGREE)");
          go(55,25);
          printf("C.ECE(4 YEARS B TECH)");
          go(55,26);
          printf("D.EE(4 YEARS B TECH)\tE.EE(5 YEARS DUAL DEGREE)");
          go(55,27);
          printf("F.ME(4 YEARS B TECH)\tG.ME(5 YEARS DUAL DEGREE)");
          go(55,28);
          printf("H.CE(4 YEARS B TECH)\tI.CE(5 YEARS DUAL DEGREE)");
          go(55,29);
          printf("J.MM(4 YEARS B TECH)\tK.MM(5 YEARS DUAL DEGREE)");
          char ch;
          a:
          ch=getch();
          switch(ch)
          {
          case 'A':
            fputs("CSE(4 YEARS B TECH)\n",ptr2);
            break;
          case 'B':
            fputs("CSE(5 YEARS DUAL DEGREE)\n",ptr2);
            break;
          case 'C':
              fputs("ECE(4 YEARS B TECH)\n",ptr2);
              break;
          case 'D':
            fputs("EE(4 YEARS B TECH)\n",ptr2);
            break;
          case 'E':
            fputs("EE(5 YEARS DUAL DEGREE)\n",ptr2);
            break;
          case 'F':
            fputs("ME(4 YEARS B TECH)\n",ptr2);
            break;
          case 'G':
            fputs("ME(5 YEARS DUAL DEGREE)\n",ptr2);
            break;
          case 'H':
                fputs("CE(4 YEARS B TECH)\n",ptr2);
                break;
          case 'I':
                fputs("CE(5 YEARS DUAL DEGREE)\n",ptr2);
                break;
          case 'J':
                fputs("MM(4 YEARS B TECH)\n",ptr2);
                break;
          case 'K':
                fputs("MM(5 YEARS B TECH)\n",ptr2);
                break;
          default:
          goto a;
          }
        }
        else
        {
            fprintf(ptr2,"%s\n%s\n%s\n%s\n%llu%s\n%s\n",name,gender,dob,email,phoneno,bloodgrp,branch);
        }
}
if(var==0)
{
    go(45,6);
    printf("No such student is found");
}
fclose(ptr1);
fclose(ptr2);
ptr1=fopen("pds.txt","w");
fclose(ptr1);
ptr1=fopen("pds.txt","a");
ptr2=fopen("modify.txt","r");
while(fscanf(ptr2,"%[^\n] %s %s %s %llu %[^\n] %[^\n]\n",name,gender,dob,email,&phoneno,bloodgrp,branch)!=EOF)
{
    fprintf(ptr1,"%s\n%s\n%s\n%s\n%llu\n%s\n%s\n",name,gender,dob,email,phoneno,bloodgrp,branch);
}
fclose(ptr1);
fclose(ptr2);
ptr2=fopen("modify.txt","w");
fclose(ptr2);
go(10,34);
printf("Press u to update another student details");
go(10,36);
printf("Press m to go to menu");
fflush(stdin);
char q;
q=getch();
  if(q=='u')
  {
     update_details();
  }
   else if(q=='m')
   {
     menu();
   }
   else
   {
     exit(0);
   }
}
