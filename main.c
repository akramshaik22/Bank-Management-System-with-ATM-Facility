//BANK MANAGEMENT SYSTEM PROGRAM
//Code By : AKRAM .

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
//#include <math.h>

int c;

int new_customer();
void existing_customer();

int check_char(char ch[])
{
   int i=0;

    while(isalpha(ch[i]))
           i++;

	if(i==strlen(ch))
       return 0;
    else
        return 1;
}
int check_int(char ch[])
{
    int i=0;
	while(isdigit(ch[i]))
        i++;

    if(i==strlen(ch))
       return 0;
    else
        return 1;
}
void employee()
{
    char id[10],password[20];
    FILE * emp_login;

    printf("\n\n\t\tEnter Your ID  :  ");
    scanf("%s",id);
    printf("\n\n\t\tEnter Password :  ");
    scanf("%s",password);

    if(strcmp("employee",id)==0 && strcmp("akram",password)==0)
    {
        printf("\n\tLOGGED IN");


    }
    else
        printf("\n\n\t\t!!!You Have Entered Invalid ID or Password!!!!");

        getch();
}

struct
{
    char fname[20],sname[20];
    char ac_no[20];
    char ph_no[11];
    char password[20];

    struct
    {
        int d;
        int m;
        int y;
    }dob;

}ncd,ecd,eac;

long int ac_no_creating(int z)
{
   long int dacno;
   char *fname;
   FILE * acno;

   if(z==1)
    fname = "defaultacno.txt";
  else if(z==2)
    fname = "defaultdcno.txt";
  else if(z==3)
    fname = "defaultcvv.txt";

   acno = fopen(fname,"r");
   fscanf(acno,"%ld",&dacno);
   fclose(acno);

   acno = fopen(fname,"w");
   dacno++;
   fprintf(acno,"%ld",dacno);
   fclose(acno);

   return dacno;
}

void ext(void)
{
    system("cls");

    printf("\n\n\n\t\t                    ** \n");
    printf("\t\t                   **** \n");
    printf("\t\t****  THANKS FOR VISITING OUR BANK  ****\n\n");
    printf("\t\t                   **** \n");
    printf("\t\t                    ** \n");

    getch();
}

int del_ac(long int amoney)
{
    int m,j;
    long int i;
    i=amoney;

    system("cls");

    printf("\n\n\tEnter The Total Money in Your Account to Withdraw : ");
    scanf("%d",&m);
    j=amoney-m;
    if(j==0)
    {
     printf("\n\n\t\tYou Successfully Withdrawn Your Total Money");
     printf("\n\t\tNow Your Account Balance is 0");
     printf("\n\t\tYour Money Will be given After Deleting Your Account");
     printf("\n\n\t\tPress any key to Procede to Delete Your Account ");
    getch();
    }
    else if(j>0)
    {
      printf("\n\n\t\tYou Entered Amount is Less than Your Bank Balance");
      printf("\n\t\tNow Your Account Balance is %d",j);
      printf("\n\n\t\tPress any key to Withdraw Remaining Amount ");
      getch();
      del_ac(j);
    }
    else if(j<0)
    {
       printf("\n\n\t\tYou Entered Amount is Greater than Your Bank Balance");
      printf("\n\t\tNow Your Account Balance is %ld",i);
      printf("\n\n\t\tPress any key to Withdraw Total Amount ");
      getch();
      del_ac(i);
    }

    return 1;
}

int debit_card_creation(char fname[],char sname[])
{
    char pwstr[20],acno[20],dcno[]="45674321",dcno1[20],pline[100];
    long int dcno2;
    int i=1,cvv,dcpin,ex=3;
    FILE * ac_login;
    FILE * dc_login;
    FILE * tempfile;

  while(ex!=0)
  {
        system("cls");

        printf("\n\n\t\t\t****DEBIT CARD CREATION****");

        printf("\n\n\t\t\t****LOGIN TO YOUR ACCOUNT****");
        while(i!=0)
        {
        printf("\n\n\tEnter Your Name As In Your Bank Account (firstName secondName) : ");
        scanf("%s %s",ecd.fname,ecd.sname);
        if(strcmp(fname,ecd.fname)==0 && strcmp(sname,ecd.sname)==0)
          i=0;
        else
          {
           printf("\n\n\t\t!!Enter the Correct Name as in your Account Details!!");
           printf("\n\n\t\tPress Any key to Try Again  ");
           getch();
           system("cls");
          }
        }
        printf("\n\n\t\tEnter Your A.c No   : ");
        scanf("%s",ecd.ac_no);
        printf("\t\tEnter Your Password : ");
        scanf("%s",ecd.password);

       strcpy(acno,ecd.ac_no);
//printf("\n%s",acno);
     /*  for(i=0;i<strlen(ecd.ac_no);i++)
       {
           acno[i] = ecd.ac_no[i];
       }*/
//printf("\n%s",acno);
       strcat(ecd.ac_no,".txt");

     ac_login = fopen(ecd.ac_no,"r");

    fscanf(ac_login,"%[^\n]",pwstr);

    if(ac_login!=NULL && strcmp(ecd.password,pwstr)==0)
    {

      fclose(ac_login);

      system("cls");

      dcno2=ac_no_creating(2);

      sprintf(dcno1,"%ld",dcno2);

      cvv = ac_no_creating(3);

      printf("\n\n\tCreate 4-Digit Pin to Your Card");
      printf("\n\tEnter 4-Digit Pin  :  ");
      scanf("%d",&dcpin);

      dc_login = fopen("dclogin.txt","a");

      fprintf(dc_login,"%s %s\n",ecd.fname,ecd.sname);
      fprintf(dc_login,"%s%s\n",dcno,dcno1);
      fprintf(dc_login,"%d\n",cvv);
      fprintf(dc_login,"%d\n",dcpin);
      fprintf(dc_login,"%s\n",acno);
      //fprintf(dc_login,"%s\n",pwstr);
      fclose(dc_login);

      system("cls");

      printf("\n\n\tCONGRATULATIONS,Your Debit Card Has Been Created For Your Account");
      printf("\n\n\t\tYour Debit Card No. is %s%s",dcno,dcno1);
      printf("\n\t\tYour CVV is  %d",cvv);
      printf("\n\n\tNOTE : Dont Forget Your Debit Card Number and CVV and PIN");

      ac_login = fopen(ecd.ac_no,"r");
      tempfile = fopen("tempfile.txt","w");
      i=0;
      while(fgets(pline,sizeof(pline),ac_login))
      {
          i++;

          if(i==1)
          fprintf(tempfile,"%s\n",pwstr);
          else if(i==7)
          {
            fprintf(tempfile,"Debit Card No : %s%s\n",dcno,dcno1);
            fprintf(tempfile,"CVV           : %d\n",cvv);
           fprintf(tempfile,"%s",pline);
          }
          else
          fprintf(tempfile,"%s",pline);
      }
      fclose(ac_login);
      fclose(tempfile);

      remove(ecd.ac_no);
      rename("tempfile.txt",ecd.ac_no);

      //printf("\n\n\t\tPress any key to go to Next Page   ");
      //getch();
      ex=0;
      i=0;
    }
    else
    {
        i++;
        printf("\n\n!!!!You Have Entered Invalid Password or Account Number!!!!");

        if(i==3)
            ex=0;
        else
        {
            printf("\n\n!!You Have %d Tr%s left!!",3-i,i==2?"y":"ies");
            printf("\n\n\t\tPress any key to Try again   ");
            getch();
        }
    }
 }

return i;
}

int main()
{
    //clrscr();
    system("cls");

   printf("\n\n\n\t\t******************************************\n");
   printf("\t\t**********BANK MANAGEMENT SYSTEM**********\n");
   printf("\t\t******************************************\n");

   printf("\n\n\t\t\t1.New Customer \n\t\t\t2.Existing Customer \n\t\t\t3.Exit");

   printf("\n\n\t\tEnter Your Choice  :  ");
   scanf("%d",&c);

   switch(c)
   {
       case 1:new_customer();
       break;
       case 2:existing_customer();
       break;
       case 4:employee();
       break;
       //case 3:debit_card_creation();
       //break;
       case 3:ext();
       break;
       default : printf("\n\n\t\t!!Enter Correct Choice Among Given!!");
                 printf("\n\n\t\tPress any key to Try Again  ");
                 getch();
                 main();
       break;
   }
  return 0;
}

int new_customer()
{
    int j=1,k=1;
    long int acno1,i;
    char acno[20];
    FILE * ac_creation;

    system("cls");

    printf("\n\n\n\t\t1.Create an Savings Account \n\t\t2.Go to Previous Page \n\t\t3.Exit");
    printf("\n\n\tEnter Your Choice : ");
    scanf("%d",&c);

if(c==1)
{
    system("cls");
   printf("\n\n\t\t\t****ACCOUNT CREATION****");

   printf("\n\n\tEnter Your Details For Creating Your Account In Our Bank");
  while(j==1 || k==1)
  {
   printf("\n\n\tEnter Your Name(firstName secondName) : ");
   scanf("%s %s",ncd.fname,ncd.sname);
    j=check_char(ncd.fname);
    k=check_char(ncd.sname);
     if(j==1 || k==1)
     {
      printf("\n\n\t\t!!Enter Valid Name!!");
      printf("\n\n\t\tPress Any key to Try Again  ");
      getch();
      system("cls");
     }
  }
  j=1;
   while(j==1)
   {
      printf("\tEnter Your DOB (dd mm yyyy) : ");
      scanf("%d %d %d",&ncd.dob.d,&ncd.dob.m,&ncd.dob.y);

     if(ncd.dob.d>0 && ncd.dob.d<=31 && ncd.dob.m>0 && ncd.dob.m<=12 && ncd.dob.y>1900 && ncd.dob.y<2023)
          j=0;
     else
     {
      printf("\n\n\t\t!!Enter Valid DOB!!");
      printf("\n\n\t\tPress Any key to Try Again  ");
      getch();
      system("cls");
     }
   }
   j=1;
  while(j==1)
  {
      printf("\tEnter Your Phone Number : ");
      scanf("%s",ncd.ph_no);

      j=check_int(ncd.ph_no);

      if(j==1 || strlen(ncd.ph_no)!=10 || ncd.ph_no[0]=='5'||ncd.ph_no[0]=='4'|| ncd.ph_no[0]=='3'|| ncd.ph_no[0]=='2'|| ncd.ph_no[0]=='1'|| ncd.ph_no[0]=='0')
      {
      printf("\n\n\t\t!!Enter Valid Phone Number!!");
      printf("\n\n\t\tPress Any key to Try Again  ");
      getch();
      j=1;
      system("cls");
      }
  }

   printf("\tSet Password for Your Account : ");
   scanf("%s",ncd.password);

   acno1=ac_no_creating(1);

   sprintf(acno,"%ld",acno1);

   printf("\n\tCONGRATULATIONS,Your Account Has Been Created In Our Bank");
   printf("\n\n\tYour Acccount Number is : %s",acno);
   printf("\n\n\tNOTE : Dont Forget Your Account Number and Password");

   strcat(acno,".txt");

   ac_creation = fopen(acno,"a+");

   fprintf(ac_creation,"%s",ncd.password);
   fprintf(ac_creation,"\n   **Account Details**");
   fprintf(ac_creation,"\nA/c.No    : %ld",acno1);
   fprintf(ac_creation,"\nName      : %s %s",ncd.fname,ncd.sname);
   fprintf(ac_creation,"\nDOB       : %d-%d-%d",ncd.dob.d,ncd.dob.m,ncd.dob.y);
   fprintf(ac_creation,"\nPh.No     : %s",ncd.ph_no);
   fprintf(ac_creation,"\nA/c Balance : 0");
   //fprintf(ac_creation,"\nPassword  : %s",ncd.password);
   fprintf(ac_creation,"\n----Transaction Details----");
   fprintf(ac_creation,"\n0 == Total Amount");

   fclose(ac_creation);

   printf("\n\n\t~~Now a Days DEBIT CARD is VERY IMPORTANT For All Types of Transactions~~");
   printf("\n\n\t\t~~~~So, APPLYING for DEBIT CARD is MANDATORY~~~~");
   printf("\n\n\tPress any key to Apply for Your DEBIT CARD  ");
   getch();
   i=debit_card_creation(ncd.fname,ncd.sname);

   while(i!=0)
   {
       printf("\n\n\n\t**~~**DONT FORGET YOUR ACCOUNT NUMBER AND PASSWORD**~~**");
       printf("\n\n\tPress any key to see Your Account Number and Password  ");
       getch();
       system("cls");
       printf("\n\n\tYour Acccount Number is : %ld",acno1);
       printf("\n\tPassword  : %s",ncd.password);
       printf("\n\n\tPress any key to Apply Again for Your DEBIT CARD  ");
       getch();
       i=debit_card_creation(ncd.fname,ncd.sname);
   }

   printf("\n\n\t\t\t****THANKS FOR CHOOSING OUR BANK****\n");

   printf("\n\n\tNow You Are An Existing Customer of Our Bank");
   printf("\n\n\t\t Press any key to go to Existing Customer Options : ");
   getch();

   existing_customer();
}
else if(c==2)
    main();
else if(c==3)
    ext();
else
    new_customer();

return 0;
}

void existing_customer()
{
    char pwstr[20],dcno1[20],pline[50],pline2[50];
    int i,lc,ex=3,l;
    int cvv,cvv1,dcpin,dcpin1,dc,ec,p;
    long int money,acmoney,tmoney;
    FILE * ac_login;
    FILE * dc_login;
    FILE * drcmoney;

    system("cls");

    printf("\n\n\t\t\t****EXISTING CUSTOMER OPTIONS****");

    printf("\n\n\t\t\t\t1.Login \n\t\t\t\t2.Debit Card Services \n\t\t\t\t3.Remove Your Account \n\t\t\t\t4.Go to First Page \n\t\t\t\t5.Exit");

    printf("\n\n\t\t\tEnter Your Choice :  ");
    scanf("%d",&ec);


if(ec==1 || ec==2 || ec==3)
{
  do
    {
        system("cls");

        printf("\n\n\t\t****LOGIN TO YOUR ACCOUNT****");

    if(ec==2)
    {
    printf("\n\n\tEnter Your Debit Card No. :  ");
    scanf("%s",dcno1);
    printf("\n\tEnter Your CVV  :  ");
    scanf("%d",&cvv);
    printf("\n\tEnter Your PIN  :  ");
    scanf("%d",&dcpin);

    dc_login = fopen("dclogin.txt","r");

    p=0;
    while(fgets(pline,18,dc_login))
    {
        p++;
        for(i=0;pline[i]!='\n';i++)
           pline2[i]=pline[i];

           pline2[i]='\0';

//printf(" %d ",p);
//printf("%s",pline2);
        if(strcmp(dcno1,pline2)==0)
        {
            p++;
            //printf("\n%d",p);
            fscanf(dc_login,"%d",&cvv1);
            p++;
            //printf("%d,%d",cvv1,p);
            fscanf(dc_login,"%d",&dcpin1);
    //  printf("%d",cvv1);
            fscanf(dc_login,"%s",ecd.ac_no);
     //  printf("%s",pline2);
            //fscanf(dc_login,"%s",pwstr1);

            break;
        }
     }
  //   getch();
      fclose(dc_login);
    }
    else
    {
        printf("\n\n\t\tEnter Your A.c No   : ");
        scanf("%s",ecd.ac_no);
        printf("\t\tEnter Your Password : ");
        scanf("%s",ecd.password);
    }
       strcat(ecd.ac_no,".txt");

     ac_login = fopen(ecd.ac_no,"r");

    if(ec==1 || ec==3)
    fscanf(ac_login,"%[^\n]",pwstr);

    if((ac_login!=NULL && strcmp(ecd.password,pwstr)==0 && ec==1) || (ac_login!=NULL && cvv==cvv1 && dcpin==dcpin1 && ec==2))
    {
      fclose(ac_login);

      do
      {
        ac_login = fopen(ecd.ac_no,"r");
             system("cls");

    if(ec==2)
    {
        printf("\n\n\t\t****BANKING OPTIONS THROUGH DEBIT CARD****\n");

        printf("\n\n\t1.A/c Balance");
        printf("\n\t2.Debit Money from A/c");
        printf("\n\t3.Pin Change");
        printf("\n\t4.Exit");

        printf("\n\n\tWhich Service Do You Want : ");
        scanf("%d",&dc);

        c=0;
    }
    else
    {
       printf("\n\n\t\t****BANKING OPTIONS****");

       printf("\n\n\t1.A/c Balance");
       printf("\n\t2.Account Details");
       printf("\n\t3.Transaction Details");
       printf("\n\t4.Credit Money to A/c");
       printf("\n\t5.Debit Money from A/c");
       printf("\n\t6.Modify A/c details");
       printf("\n\t7.Go to First Page");
       printf("\n\t8.Exit");

       printf("\n\n\tWhich Service Do You Want : ");
       scanf("%d",&c);
       printf("\n");
    }
   //LINES COUNTING IN A FILE
   lc=0;
  while(fgets(pline,sizeof(pline),ac_login))
  {
      lc++;

      for(i=0;pline[i]!='\n';i++)
           pline2[i]=pline[i];

           pline2[i]='\0';

      if(strcmp(pline2,"----Transaction Details----")==0)
        l=lc-1;
  }

//printf("lcount=%d\n",l);
//getch();
  fclose(ac_login);
  ac_login = fopen(ecd.ac_no,"r");

  if(dc==1 || c==1 || c==2 || c==3)
  {
      system("cls");

    printf("\n\n\n");
    i=0;
    while(fgets(pline,sizeof(pline),ac_login))
    {
      i++;

      //TRANSACTION DETAILS
      if(c==3 && i>=l)
        printf("\t\t\t%s",pline);

      //ACCOUNT DETAILS
      else if((c==2 && i>=2 && i<=6) || (i==l && c==2))
        printf("\t\t\t%s",pline);

      //ACCOUNT BALANCE
      else if((c==1 || dc==1) && i==l)
      {
        printf("\t\t\t%s",pline);
        break;
      }
    }
  }

  //CREDIT & DEBIT MONEY
  else if(c==4 || c==5 || dc==2)
  {
      system("cls");

      printf("\n\n\t\t\t****MONEY %s SECTION****",c==4?"CREDITING":"DEBITING");
      printf("\n\n\t\tEnter How Much Amount You Want to %s : Rs.",c==4?"Credit":"Debit");
      scanf("%ld",&money);

      drcmoney = fopen("tempfile.txt","w");

        i=0;
       while(fgets(pline,sizeof(pline),ac_login))
       {
           i++;
          if(i == lc-1) //i==lc-1 because cursor places before lc line means last line.
          {             //then it scans last line 1st int value
              //j++;
              //acmoney=getw(ac_login);
             fscanf(ac_login,"%ld",&acmoney);
             //printf("acmoney = %d\n",acmoney);
          }
       }
       fclose(ac_login);
       ac_login = fopen(ecd.ac_no,"r");

       /*tacmoney=0;
       for(i=1;i<=j;i++)
        tacmoney+=acmoney[i];
       printf("tacmoney = %d\n",tacmoney);*/

        if(c==4)
       tmoney = acmoney + money;
       else if(c==5 || dc==2)
       tmoney = acmoney - money;
       //printf("tmoney = %d\n",tmoney);

     if(tmoney>=0)
     {
      i=0;
      while(fgets(pline,sizeof(pline),ac_login))
      {
          i++;

          if(i==l)
          fprintf(drcmoney,"A/c Balance : %ld\n",tmoney);
          else if(i==lc)
          {
           fprintf(drcmoney,"%ld %s %s : Balance = %ld\n",money,c==4?"Credited":"Debited",dc==2?"Through Card":" ",tmoney);
           fprintf(drcmoney,"%ld == Total Amount",tmoney);
          }
          else
          fprintf(drcmoney,"%s",pline);
      }

      fclose(ac_login);
      fclose(drcmoney);

      remove(ecd.ac_no);
      rename("tempfile.txt",ecd.ac_no);

      printf("\n\n\t\t**** Your Transaction of Amount of Rs.%ld is Successful ****\n",money);

      ac_login = fopen(ecd.ac_no,"r");
   }
   else
   {
    printf("\n\t\t\t!!!! Your Transaction is FAILED !!!!");
    printf("\n\t!!!! Because,You Entered Amount Rs.%ld Exceeds Your Bank Balance !!!!\n",money);
   }
  }
  else if(dc==3)
     {
         system("cls");

         fclose(ac_login);
         dc_login = fopen("dclogin.txt","r");
         drcmoney = fopen("tempfile.txt","w");

         printf("\n\n\t\tEnter the Old PIN :  ");
         scanf("%d",&dcpin);

         if(dc_login!=NULL && dcpin==dcpin1)
         {
             printf("\n\n\t\tEnter New PIN  :  ");
             scanf("%d",&dcpin1);
             i=0;
             while(fgets(pline,50,dc_login))
             {
                 i++;
                 if(i==p)
                 {
                     fprintf(drcmoney,"%d\n",dcpin1);
                      printf("\n\n\t\t~~Your PIN Has been Changed Successfully~~");
                 }

                 else
                    fprintf(drcmoney,"%s",pline);
             }
             fclose(dc_login);
             fclose(drcmoney);

             remove("dclogin.txt");
             rename("tempfile.txt","dclogin.txt");


             printf("\n\n\t\tPress any key to go to Existing Customer Services Page   ");
             ex=1;
            // debit_credit_card();
         }
         else
         {
            printf("\n\n\t\t!!!!You Have Entered Invalid Old PIN!!!!");
            printf("\n\n\t\tPress any key to go to Existing Customer Services Page   ");
             ex=1;
            // debit_credit_card();
         }
   }
   else if(c==6)
    {
        fclose(ac_login);
   while(c!=5)
   {
       system("cls");
    printf("\n\n\t\t\t****ACCOUNT DETAILS MODIFICATION SERVICES****");

    printf("\n\n\n\t\tYou can Edit Only : ");
    printf("\n\t\t1.Name \n\t\t2.DOB \n\t\t3.Ph.No \n\t\t4.Password");
    printf("\n\n\t\tEnter 5 to Exit ");
    printf("\n\n\t Enter Your Choice  :  ");
    scanf("%d",&c);
  if(c>0 && c<5)
  {
      system("cls");
    ac_login = fopen(ecd.ac_no,"r");
    drcmoney = fopen("tempfile.txt","w");
    i=0;
    while(fgets(pline,100,ac_login))
    {
     i++;
     if(c==4 && i==1)
     {
         printf("\n\n\t\tSet New Password for Your Account : ");
         scanf("%s",eac.password);
         fprintf(drcmoney,"%s\n",eac.password);
     }
     else if(c==1 && i==4)
     {
        printf("\n\n\t\tEnter Your New Name (firstName secondName) :  ");
        scanf("%s %s",eac.fname,eac.sname);
        fprintf(drcmoney,"Name      : %s %s\n",eac.fname,eac.sname);
     }
     else if(c==2 && i==5)
     {
         printf("\n\n\t\tEnter Your New DOB (dd mm yyyy) :  ");
          scanf("%d %d %d",&eac.dob.d,&eac.dob.m,&eac.dob.y);
          fprintf(drcmoney,"DOB       : %d-%d-%d\n",eac.dob.d,eac.dob.m,eac.dob.y);
     }
     else if(c==3 && i==6)
     {
         printf("\n\n\t\tEnter Your New Phone Number : ");
         scanf("%s",eac.ph_no);
         fprintf(drcmoney,"Ph.No     : %s\n",eac.ph_no);
     }
     else
        fprintf(drcmoney,"%s",pline);
    }
    fclose(ac_login);
    fclose(drcmoney);

    remove(ecd.ac_no);
    rename("tempfile.txt",ecd.ac_no);
    printf("\n\n\t\t\t~~Your Details Have Been Updated Successfully~~");
    printf("\n\n\t\tPress any key to go to previous page  ");
    getch();
   }
   else if(c!=5)
   {
   	 printf("\n\n\n\n\t\t\t!!!! Enter The Correct Choice Among Given !!!!");
   	 getch();
   }

   }
  }

   else if(c==7)
    ex=2;  //main();

  //EXIT
   else if(c==8 || dc==4)
   {
       //ext();
      ex=0;
   }
   else
   {
        system("cls");
      printf("\n\n\n\n\t\t\t!!!! Enter The Correct Choice Among Given !!!!");
   }

 fclose(ac_login);

   if(c!=8 && c!=7 && c!=0)
   {
     printf("\n\n\tPress any key to go to Banking Options : ");
     getch();
   }

  }while(c!=8 && c!=7 && dc!=4 && ec!=2);
 }
 else if(ac_login!=NULL && strcmp(ecd.password,pwstr)==0 && ec==3)
 {
        printf("\n\n\n\t\t****Procedure To Removing Your Savings Account From Our Bank****");
      printf("\n\n\t\t    First,Check Your Account Details");
      printf("\n\t\t    Next,Withdraw All Your Money From Your Account");
      printf("\n\t\t    Finally, REMOVE Your Account From Our Bank");
      printf("\n\n\t\t Press any key to Procede to Remove Your Account");
      getch();

      system("cls");

      printf("\n\n\n");
      i=0;
      while(fgets(pline,sizeof(pline),ac_login))
    {
      i++;
      //ACCOUNT DETAILS
      if(i>=2 && i<=9)
        {
        printf("\t\t\t%s",pline);
        }
        fscanf(ac_login,"%ld",&acmoney);
    }
    //printf("acmoney = %d\n",acmoney);
    fclose(ac_login);
    printf("\n\n\tPress any key to Procede to Withdraw Total Money of Your Account  ");
    getch();

    i=del_ac(acmoney);

    if(i==1)
    {
        system("cls");

    printf("\n\n\t\tFor Confirmation Login To Your Account");

        printf("\n\n\t\tEnter Your A.c No   : ");
        scanf("%s",ecd.ac_no);
        printf("\t\tEnter Your Password : ");
        scanf("%s",ecd.password);

       strcat(ecd.ac_no,".txt");

     ac_login = fopen(ecd.ac_no,"r");

    fscanf(ac_login,"%[^\n]",pwstr);

    if(ac_login!=NULL && strcmp(ecd.password,pwstr)==0)
    {
      fclose(ac_login);
    remove(ecd.ac_no);

    printf("\n\n\t\tSuccessfully Your Account Is Removed From Our Bank");
    printf("\n\n\tPress any key to Exit : ");
    getch();
    ex=0;
    }
    else
    {
        printf("\n\tThe Process of Deleting Account is Terminated");
        printf("\n\tBecause,You Entered Incorrect UserName or Password");
        printf("\n\tYour Money Will be Safe and Credited In Your Account Successfully");
        printf("\n\n\tPress any key to go to Existing Customer Options : ");
        getch();
        ex=1;
    }
   }
  }
  else if(ec==2)
  {
         printf("\n\n\t\t!!!!You Have Entered Invalid Debit Card Number OR Password OR CVV!!!!");
         printf("\n\n\t\tEnter 0 to Exit");
         printf("\n\t\tEnter 1 to Go to Existing Customer Options");
         printf("\n\t\tEnter between 2 to Try Again");
        while(ex!=0 && ex!=1 && ex!=2)
        {
            printf("\n\n\tEnter Your Choice : ");
            scanf("%d",&ex);
        }
         dc=4;
  }
  else
  {
           fclose(ac_login);
        printf("\n\n\t\t!!!! You Have Entered Invalid Username OR Password !!!!");
        printf("\n\n\t\tEnter 0 to Exit");
        printf("\n\t\tEnter 1 to Go to Existing Customer Options");
        printf("\n\t\tEnter between 2 to Try Again");
        while(ex!=0 && ex!=1 && ex!=2)
        {
            printf("\n\n\tEnter Your Choice : ");
            scanf("%d",&ex);
        }
  }

      if(ec==2 && dc!=4 && c!=7 && c!=8)
        getch();

  }while(ex!=0 && ex!=1 && ec!=2 && c!=7);
 }
 else if(ec==4)
        main();
 else if(ec==5)
         ext();
 else
 {
     existing_customer();
 }

    if(ex==0)
        ext();
    else if(ex==1 || ec==2)
    {
        existing_customer();
    }
    else if(ec!=5 && ec!=4)
        main();
}
