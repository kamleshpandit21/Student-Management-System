#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 typedef struct{
    int sr_no;
    char first_name[20];
    char last_name[20];
    int  age;
    char city[20];
    float percentage;
   long long  int phno;
    }student;
    student s1;

  void add_student();
  void see_student();
  void delete_student();
  void search_student();
  //----------------------------------Main funtion---------------------------
int main(){
    int n;
     while(n !=5)
     {  printf("\n");
        printf("---------------------Choose Your Option--------------------\n");
        printf("Enter 1 To Enter Student Details\n");
        printf("Enter 2 To Search Student\n");
        printf("Enter 3 To See Student List\n");
        printf("Enter 4 To Delete Student Record\n");
        printf("Enter 5 To EXIT\n");
        printf("Enter Your Choice Here : ");
        scanf("%d",&n);
        printf("-----------------------------------------------------------\n");
       
       switch (n)
       {
       case 1:
       {
       
        add_student();
        break;
       }
       case 2:{
         search_student();
         break;
       }
       case 3:
       {
        see_student();
        break;
       }
       case 4:
       {
        delete_student();
        break;
       }

       default:
        break;
       } 
     }
      
return 0;
}
//-------------------------------------funtion to add student-----------------//
 void add_student()
{
  FILE *fptr;
printf("-----------------Enter Student Details Here-----------------\n");
printf("Enter Student Sr No            :- ");
scanf("%d",&s1.sr_no);
printf("Enter Student First Name       :- ");
scanf("%s",&s1.first_name);
printf("Enter Student Last Name        :- ");
scanf("%s",&s1.last_name);
printf("Enter Student Age              :- ");
scanf("%d",&s1.age);
printf("Enter the City of Student      :- ");
scanf("%s",&s1.city);
printf("Enter the Student percentage   :- ");
scanf("%f",&s1.percentage);
printf("Enter the Student Phone Number :- ");
scanf("%lld",&s1.phno);
fptr=fopen("student_detail.txt","a");

fwrite(&s1,sizeof(student),1,fptr);
fclose(fptr);
printf("\n");
printf("Student Details Enterd Successfully\n");
printf("------------------------------------------------------------\n");

}

//-------------------------funtion to search student----------------//
void search_student(){
 int sr_no,flag=0; 
printf("\n----------------- Search Student Record --------------------\n");
printf("Enter Student Sr No :- ");
scanf("%d",&sr_no);

FILE *orignalFile;
orignalFile=fopen("student_detail.txt","r");
if(orignalFile == NULL){
  printf("Error in opening file");
  return ;
}
while (fread(&s1,sizeof(student),1,orignalFile)==1)
{
  if(s1.sr_no == sr_no){
   printf("-----------------------------------------------------------\n");
   printf("Sr NO        -: %d\n",s1.sr_no);
   printf("Name         -: %s %s\n",s1.first_name,s1.last_name);
   printf("Age          -: %d\n",s1.age);
   printf("Percentage   -: %.2f %%\n",s1.percentage);
   printf("City         -: %s\n",s1.city);
   printf("Phone Number -: %lld\n",s1.phno);
   printf("\n-----------------------------------------------------------");
   printf("\n");
   
  }
  
}
// if(flag ==0){
//    printf("Record Not Found");
// }
fclose(orignalFile);
  }

//------------------------function to print student details-----------------------//  
void see_student()
{
  FILE *fptr;
fptr=fopen("student_detail.txt","r");
if(fptr ==NULL){
  printf("The file not found");
}
else
{
 printf("\n------------ The List Of Registerd Student ------------------\n"); 
 while(fread(&s1,sizeof(student),1,fptr) == 1){  

   printf("-------------------------------------------------------------\n");
   printf("Sr NO        -: %d\n",s1.sr_no);
   printf("Name         -: %s %s\n",s1.first_name,s1.last_name);
   printf("Age          -: %d\n",s1.age);
   printf("Percentage   -: %.2f %%\n",s1.percentage);
   printf("City         -: %s\n",s1.city);
   printf("Phone Number -: %lld\n",s1.phno);
   printf("\n-------------------------------------------------------------");
   printf("\n");
    }
    }

    fclose(fptr);
}
// ---------------------------------function to delete student detail---------------//
void delete_student(){
 int sr_no,flag=0;
  printf("\n------------------ Delete Student Record ---------------------\n");
printf("Enter Student Sr No :- ");
scanf("%d",&sr_no);

FILE *orignalFile;
FILE *tempFile;
orignalFile=fopen("student_detail.txt","r");
tempFile=fopen("tempFile.txt","w");
if(orignalFile == NULL || tempFile ==NULL){
  printf("Error in opening file");
  return ;
}
while (fread(&s1,sizeof(student),1,orignalFile)==1)
{
  if(s1.sr_no != sr_no){
    fwrite(&s1,sizeof(student),1,tempFile);
   
  }
  
}
fclose(orignalFile);
fclose(tempFile);
remove("student_detail.txt");
rename("tempFile.txt","student_detail.txt");
printf("Student with Sr No %d has been deleted.\n", sr_no);

 
}
  