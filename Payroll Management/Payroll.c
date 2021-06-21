#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


void insert_record();
void display_record();
void search_record();
void del_record();
void update_record();
void sort_record();
void calculate();
void welcome_message();
void adminlogin();
void user_login();
void mainmenu();
void payinslip();
void user_record();
void time_display();




struct employee
{
    char name[30];
    int age;
    int empcode;
    int basicsalary;
};

struct user
{
    char employeecode[30];
    char employeepassword[30];
};


struct employee s;
struct user f;
int main()
{
    system("color F1");
    int ch,c;
    welcome_message();
    while(c!=3)
    {
         printf("\t\t1: Enter as Admin\n");
         printf("\t\t2: Enter as User\n");
         printf("\t\t3: Exit\n\n");
         printf("\t\tEnter your choice : ");
         scanf("%d",&c);
         switch(c)
         {
             case 1:
             {
                 adminlogin();
                 break;
             }
             case 2:
             {
                 user_login();
                 break;
             }
             case 3:
             {
                 exit(0);
             }
             default:
             {
                 printf("\n\t\tWrong choice Entered");
                 break;
             }
         }
         printf("\n\t\tPress any key to continue\n");
         getch();
    }
    
}

void time_display()
{
    time_t t;   
    time(&t);

    printf("\n\t\t date and time: %s \n", ctime(&t));
}

void welcome_message()
{

	printf("                                                     WELCOME\n");
	printf("\n                                            PAYROLL MANAGEMENT SYSTEM\n");
	printf("\n                                      ______________________________________\n\n\n");
	printf("                                              SUBMITTED TO UEM,KOLKATA \n\n");
	printf("                                           FACULTY NAME : KAUSTAV BHATTACHARYA\n");
	printf("\n\n");
	printf("\n                          SUBMITTED BY SUMANA KHAN,PRITAM CHAKRABORTY,NITIN JAIN,BIVABASU MAJUMDAR,SUBHAJEET BAGCHI\n\n");
	printf("\npress any key to continue\n");

	fflush(stdin);
	getch();
}

void mainmenu()
{
    int ch;
    while(ch!=7)
    {
        printf("\t\t1: Insert employee record\n");
        printf("\t\t2: Display employee record\n");
        printf("\t\t3: Search employee record\n");
        printf("\t\t4: Delete employee record\n");
        printf("\t\t5: Update employee record\n");
        printf("\t\t6: Sort employee record\n");
        /*printf("\t\t7: Calcutate GS and net income\n");*/
        printf("\t\t7: Exit\n\n");
        printf("\t\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                insert_record();
                user_record();
                break;
            }
            case 2:
            {
                display_record();
                break;
            }
            case 3:
            {
                search_record();
                break;
            }
            case 4:
            {
                del_record();
                break;
            }
            case 5:
            {
                update_record();
                break;
            }
            case 6:
            {
                sort_record();
                break;
            }
            /*case 7:
            {
                calculate();
                break;
            }*/
            case 7:
            {
                exit(0);
            }
            default:
            {
                printf("\n\t\tWrong choice Entered");
                break;
            }
        }
        printf("\n\t\tPress any key to continue \n");
        getch(); 
    }
}

void user_record()
{
    FILE *fp;
    fp=fopen("emp16.txt","ab+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\t **Enter User code and password**");
    fflush(stdin);
    printf("\n\t\tEnter Employee Code: ");
    gets(f.employeecode);
    printf("\n\t\tEnter Employee Password: ");
    gets(f.employeepassword);
    fwrite(&f,sizeof(f),1,fp);
    {
        printf("\n\n\t !!! User Record Inserted Sucessfully\n");
    }
    fclose(fp);
}

void user_login()
{
    FILE *fp;
    int i;
    char ch;
    char emp[30];
    char pwd[30];
    int flag=0;
    fp=fopen("emp16.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    fflush(stdin);
    printf("\n\t\tEnter Employee Code: ");
    gets(emp);
    printf("\n\t\tEnter Employee Password <any 3 characters>: ");
    
    for(i=0;i<3;i++)
    {
        ch = getch();
        pwd[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
 
    pwd[i] ='\0';
    while(fread(&f,sizeof(f),1,fp)>0 && flag==0)
    {
        if((strcmp(f.employeecode,emp)==0)&&(strcmp(f.employeepassword,pwd)==0))
        {
            flag=1;
            printf("\n\t\tLogged in successfully !!!");
            time_display();
            payinslip();
        }
    }
    if(flag==0)
    {
        printf("\n\t\tCheck Employee code and password: Try Again!!!");
    }
    fclose(fp);

}

void adminlogin()
{
    FILE *fp;
    char un[50];
    int i;
    char ch;
    char pwd[50];
    char adminname[50];
    char adminpassword[50];
    fp=fopen("emp5.txt","r");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    fflush(stdin);
    fscanf(fp,"%s%s",adminname,adminpassword);
    printf("\n\t\tEnter Admin: ");
    gets(un);
    printf("\n\t\tEnter the password <any 3 characters>: ");

    for(i=0;i<3;i++)
    {
       ch = getch();
       pwd[i] = ch;
       ch = '*' ;
       printf("%c",ch);
    }
 
    pwd[i] ='\0';
    if((strcmp(adminname,un)==0)&&(strcmp(adminpassword,pwd)==0))
    {
        printf("\n\t\tLogged in successfully!!!\n");
        time_display();
        mainmenu();
    }
    else
    {
        printf("\n\t\tCheck Admin name and password: Try Again!!!");
    }
      
    
    
}

void payinslip()
{
    FILE *fp;
    int emp,flag=0,houserentallowance,dearnessallowance,conveyanceallowance,medicalallowance,specialallowance,grosssalary,netincome,providentfund,professionaltax;
    fp=fopen("emp2.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the File !!!");
        return;
    }
    printf("\n\n\tEnter Employee code: ");
    scanf("%d",&emp);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.empcode==emp)
        {
            flag=1;
            printf("\n\t\tName of an employee: %s",s.name);
            printf("\n\t\tBasic Salary of an employee: %d",s.basicsalary);
            dearnessallowance=0.1*s.basicsalary;
            printf("\n\t\tDearness allowance: %d",dearnessallowance);
            houserentallowance=0.5*s.basicsalary;
            printf("\n\t\tHouse rent allowance: %d", houserentallowance);
            conveyanceallowance=0.4*s.basicsalary;
            printf("\n\t\tConveyance allowance: %d",conveyanceallowance);
            medicalallowance=0.1125*s.basicsalary;
            printf("\n\t\tMedical allowance: %d",medicalallowance);
            specialallowance=0.7*s.basicsalary;
            printf("\n\t\tSpecial allowance: %d",specialallowance);
            grosssalary=s.basicsalary+houserentallowance+dearnessallowance+specialallowance+medicalallowance+conveyanceallowance;
            printf("\n\t\tGross salary: %d",grosssalary);
            providentfund=0.125*grosssalary;
            if(grosssalary>=40000)
            {
                professionaltax=200;
            }
            else
            {
                professionaltax=100;
            }
            netincome=grosssalary-providentfund-professionaltax;
            printf("\n\t\tNet income: %d",netincome);
        }
    }
    if(flag==0)
    {
        printf("\n\n\t\tNo Such Record Found !!!");
    }
    fclose(fp);

}

void insert_record()
{
    
    FILE *fp;
    fp=fopen("emp2.txt","ab+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\t ** Previous Stored Data **");
    display_record();
    fflush(stdin);
    printf("\n\t\tEnter Employee Name: ");
    gets(s.name);
    printf("\n\t\tEnter Employee Age: ");
    scanf("%d",&s.age);
    printf("\n\t\tEnter Employee Code: ");
    scanf("%d",&s.empcode);
    printf("\n\t\tEnter Basic Salary : ");
    scanf("%d",&s.basicsalary);
    fwrite(&s,sizeof(s),1,fp);
    {
        printf("\n\n\t !!! Employee Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n\t\t Updated Record !!\n");
    display_record();
}

void display_record()
{
    FILE *fp;
    fp=fopen("emp2.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the File !!!");
        return;
    }
    printf("\nEmployee name\t\tEmployee age\tEmployee code\tEmployee basic salary\n\n");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
         printf("%s \t\t %d \t\t %d \t\t %d\n",s.name,s.age,s.empcode,s.basicsalary);
    }
    fclose(fp);
}

void search_record()
{
    int emp,flag=0;
    FILE *fp;
    fp=fopen("emp2.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Employee code Which You Want To Search: ");
    scanf("%d",&emp);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.empcode==emp)
        {
            flag=1;
            printf("\n\n\tSearch Successfull And Employee Records Is as Follows: \n\n");
            printf("\nEmployee name\tEmployee age\tEmployee code\t\tEmployee basic salary\n\n");
            printf("%s\t%d\t%d  \t\t%d\n",s.name,s.age,s.empcode,s.basicsalary);
        }

    }
    if(flag==0)
    {
        printf("\n\n\t\tNo Such Record Found !!!!!\n");
    }
    fclose(fp);
}

void del_record()
{
    int emp,flag=0;
    FILE *fp,*ft;
    fp=fopen("emp2.txt","rb");
    ft=fopen("emp3.txt","ab+");
    if(fp==NULL)
    {
         printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Employee code Which You Want to Delete ");
    scanf("%d",&emp);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.empcode==emp)
        {
            flag=1;
            printf("\n\t\tRecord Deleted Successfully \n");
        }
        else
        {
            fwrite(&s,sizeof(s),1,ft);
        }
    }
    if(flag==0)
    {
       printf("\n\n\t\tNo Such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("emp2.txt");
    rename("emp3.txt","emp2.txt");
    printf("\n\t\t Updated Record !!\n");
    display_record();
}

void update_record()
{
    int emp,flag=0,c;
    FILE *fp;
    fp=fopen("emp2.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Employee code of employee Whose Record You Want To Update: ");
    scanf("%d",&emp);
    printf("\n\t\t** Previously Stored Record Of Given Employee code **");
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.empcode==emp)
        {
            flag=1;
            printf("\nEmployee name\tEmployee age\tEmployee code\t\tEmployee basic salary\n\n");
            printf("%s\t%d\t%d  \t\t%d\n",s.name,s.age,s.empcode,s.basicsalary);
            printf("\n\t\tUpdated Employee basic salary: ");
            scanf("%d",&s.basicsalary);
            fseek(fp,-(long)sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
        }
    }
    if(flag==0)
    {
         printf("\n\t\tError : Something went wrong!!!");
    }
    fclose(fp);
}

void sort_record()
{
    struct employee temp;
    struct employee arr[50];
    int i,j,k=0;
    FILE *fp;
    fp=fopen("emp2.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open File !!!\n");
    }
    i=0;
    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
    {
        i++;
        k++;
    }
    for(i=0;i<k;i++)
    {
       for(j=0;j<k-i-1;j++)
         {
            if(arr[j].empcode>arr[j+1].empcode)
             {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
             }
          }
    }
    printf("\n\t\tAfter Sorting Student Details !!\n\n");
    for(i=0;i<k;i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\n",arr[i].name,arr[i].age,arr[i].empcode,arr[i].basicsalary);

    }
    fclose(fp);
}

/*void calculate()
{
    int emp,flag=0,houserentallowance,dearnessallowance,conveyanceallowance,medicalallowance,specialallowance,grosssalary,netincome,providentfund,professionaltax;
    FILE *fp;
    fp=fopen("emp2.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Employee Code of employee Whose Record You Want To Calculate: ");
    scanf("%d",&emp);
    printf("\n\t\t** Previously Stored Record Of Given Employee code **");
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.empcode==emp)
        {
            flag=1;
            printf("\n\t\tName of an employee: %s",s.name);
            dearnessallowance=0.1*s.basicsalary;
            printf("\n\t\tDearness allowance: %d",dearnessallowance);
            houserentallowance=0.5*s.basicsalary;
            printf("\n\t\tHouse rent allowance: %d", houserentallowance);
            conveyanceallowance=0.4*s.basicsalary;
            printf("\n\t\tConveyance allowance: %d",conveyanceallowance);
            medicalallowance=0.1125*s.basicsalary;
            printf("\n\t\tMedical allowance: %d",medicalallowance);
            specialallowance=0.7*s.basicsalary;
            printf("\n\t\tSpecial allowance: %d",specialallowance);
            grosssalary=s.basicsalary+houserentallowance+dearnessallowance+specialallowance+medicalallowance+conveyanceallowance;
            printf("\n\t\tGross salary: %d",grosssalary);
            providentfund=0.125*grosssalary;
            if(grosssalary>=40000)
            {
                professionaltax=200;
            }
            else
            {
                professionaltax=100;
            }
            netincome=grosssalary-providentfund-professionaltax;
            printf("\n\t\tNet income: %d",netincome);
        }
    }
    if(flag==0)
    {
        printf("\n\n\t\tNo Such Record Found !!!");
    }
    fclose(fp);
}*/
