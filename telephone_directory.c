#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int choice2,choice3;
char namex[100];
int del_line;

struct contact
    {
        char name[40];
        char mob[11];
        char address[40];
    };
    struct contact c;


void emergency_contact();
void personal_contact();
void add_contact();
void view_all_contact();
void modify_contact();
void delete_contact();
void search_contact();
int delline();


void personal_contact()
{
    printf(" \t \t\t\t\t\t\t1 ADD CONTACT\n\n");
    printf("\t \t\t\t\t\t\t2 VIEW ALL CONTACT\n\n");
    printf("\t \t\t\t\t\t\t3 SEARCH CONTACT\n\n");
    printf("\t \t\t\t\t\t\t4 DELETE CONTACT\n\n");
    printf("\t \t\t\t\t\t\tEnter your next choice\n\n");

    scanf("%d",&choice2);

    switch(choice2)
    {

    case 1:
        add_contact();
        break;

    case 2:
        view_all_contact();
        break;

    case 5:
       // modify_contact();
        break;

    case 4:
       // delete_contact();
        del_line = delline(); // CALLING FUNCTION TO GET TO KNOW THE NUMBER OF FILE USER WANTS TO DELETE
        delete_contact();
        break;

    case 3:
        search_contact();
        break;

    default:
        printf("INVALID CHOICE\n\n");
    }

}

void emergency_contact()
{
   printf("\n \t\t\t\t ENTER 1 for BHOPAL\n\n");
   printf(" \t\t\t\t ENTER 2 for INDORE\n\n");
   printf(" \t\t\t\t ENTER 3 for GWALIOR\n\n");
   printf(" \t\t\t\t ENTER YOUR CHOICE\n\n");
   scanf("%d",&choice3);

   switch(choice3)

   {
    case 1:
    {
    FILE *fptr;

    char c;

    fptr = fopen("emergencybhopal.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }


    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    }

        break;

    case 2:
        {
    FILE *ptr;

    char c;
    ptr = fopen("emergencyindore.txt", "r");
    if (ptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    c = fgetc(ptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(ptr);
    }

    fclose(ptr);

}

        break;

    case 3:
        {
    FILE *pr;

    char c;
    pr = fopen("emergencygwalior.txt", "r");
    if (pr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }


    c = fgetc(pr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(pr);
    }

    fclose(pr);
    }

        break;
   }

}

void add_contact()
{
    char namex[100];

    char mob[20];

    char add[20];


    FILE *ec;
    ec=fopen("personalcontact.txt","a+");
    printf("\n\tName --");
    fflush(stdin);
    gets(namex);
    printf("\n\tPhone number--");

    scanf("%s",&mob);
    printf("\n\tcity--");

    scanf("%s",&add);
    fprintf(ec,"\n%s \t\t\t\t\t%s\t\t\t\t%s\n",namex,mob,add);
    fclose(ec);


}

void view_all_contact()
{
    FILE *vc;

    char c;


    vc = fopen("personalcontact.txt", "r");
    if (vc == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(vc);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(vc);
    }

    fclose(vc);
    void returntomenu();

}


void search_contact()
{
    FILE*ec;
ec=fopen("personalcontact.txt","r");
printf("enter name--");
fflush(stdin);
char name[100];
scanf("%s",&name);


//char name[34];
//gets(name);
//printf("enter surname--");

/*char sname[34];
gets(sname);*/

char name1[34],name2[100],mob[20],add[34];
while(fscanf(ec,"%s %s %s %s",name1,name2,mob,add)!=EOF)
{
    if(strcmp(name,name1)==0)
    {
        printf("Name--");
        printf("%s ",name1);
        printf("%s",name2);
        printf("\n");

        printf("phone number.--%s",mob);
         printf("\n");
        printf("address--%s",add);
    }


}
fclose(ec);





}


int delline()
{
    FILE *fp;
    int i=0,line =0;
    fp = fopen("personalcontact.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    printf("\n\n Enter name--");
    fflush(stdin);
    char name[100];
    //gets(name);
    scanf("%s",name);
    //scanf("%[^\n]s",name);
    //LOOP WILL EXECUTE TILL THE END OF FILE
    while (fscanf(fp,"%s %d %s %d %s",&c.name,&c.mob,&c.address) != EOF)
    {
        if(strcmp(name,c.name)==0)
        {
            printf("\n");
            break;
        }
        else
        {
            i=i+1;
            //printf("%d\n",i);
        }
    }
    line = i+1;
    //printf("%d",line);

    fclose(fp);
    return line; // THIS FUNCTION RETURNS THE VALUE OF LINE

}

void delete_contact()

{
    struct contact
    {
        char name[40];
        char mob[11];
        char address[40];
    };
    struct contact c;


    FILE *fp1, *fp2;
    char ch;

    int temp = 1;
    //open file in read mode

    fp1 = fopen("personalcontact.txt", "r");

    //rewind
    rewind(fp1);
    //open new file in write mode
    fp2 = fopen("replica.c", "w");
    ch = getc(fp1);

    while (ch != EOF) // LOOP WILL EXECUTE TILL THE END OF FILE

    {
        ch = getc(fp1);
        if (ch == '\n')
            temp++;

            //except the line to be deleted
            if (temp != del_line)

            {
                //copy all lines in file replica.c
                putc( ch, fp2);

            }

    }

    fclose(fp1);
    fclose(fp2);
    remove("personalcontact.txt");
    //rename the file replica.c to original name
    rename("replica.c", "personalcontact.txt");

    fclose(fp1);
    printf(" \t\t\t\t\t DATA HAS BEEN SUCCESSFULLY DELETED \t\t\t\t\t ");
}


void main()
{

    int age,choice1;
    long number;
    char name[340];
    char city[50];
    //printf("Welcome to the Telephonr Directory System\n");
    printf("Enter your name ");
    gets(name);
    printf("Enter your age ");
    scanf("%d",&age);
    printf("Enter your phone Number ");
    scanf("%ld",&number);
    printf("Enter your city ");
    scanf("%s",&city);
    x:printf("\n \n\n\t\t\t\t\t\tWELCOME TO THE TELEPHONE DIRECTORY SYSTEM\n\n\n ");
    printf("\t\t\t\t\t\t\t 1 for EMERGENGY NUMBERS\n");
    printf("\t\t\t\t\t\t\t 2 for PERSONAL CONTACT\n");
    printf("\t\t\t\t\t\t\t Enter your choice\n\n");
    scanf("%d",&choice1);
    switch(choice1)

    {
        case 1:
            emergency_contact();
            break;

        case 2:
            personal_contact();
            break;

        default:
            printf("INVALID CHOICE\n");
    }
    int choice4;
    printf("\n\n\n \t\t\t\t\t Enter 1 to exit\n");
    printf("\t\t\t\t \t Enter 2 to continue\n");
    printf("\n\n\t\t\t\t\t Enter your choice ");
    fflush(stdin);
    scanf("%d",&choice4);
    switch(choice4)
    {
    case 1:
        exit(0);
        break;
    case 2:
        goto x;
        break;
    case 3:
        view_all_contact();
        break;
    }
}