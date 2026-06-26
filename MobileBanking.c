#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct favourite
{
    int acc_id;
    char acc_holder_name[70];
    char bank[90];
};
int list();
void check();
void history();
void transfer();
void viewinfo();
int favour();
void setting();
int complain();
void logout();
void add();
void view();
void send();
void back();
void delete_acc();
void cancel();
char name[50];
int acc_no;
 long long int Total=10000;
int acc_id;
char acc_holder_name[50];
char bank[50];

   void main()
{
  printf("\n                 ***WELCOME TO ABC BANK***\n");

   while(1)
  {
      switch(list())
      {
        case 1:
        check();
        break;

        case 2:
        history();
        break;

        case 3:
        transfer();
        break;

        case 4:
        viewinfo();
        break;

        case 5:
        favour();
        break;

        case 6:
        setting();
        break;

        case 7:
        complain();
        break;

        case 8:
        logout();
        break;

        default:
        printf("Inva:id Option!!\n");

      }
      getch();

   }



}
     int list()
     {
      int choice;
      printf("\n\n1.Check Balance");
      printf("\n2.Transaction History");
      printf("\n3.Transfer Money");
      printf("\n4.View A/C Information");
      printf("\n5.Favourite Account");
      printf("\n6.Setting");
      printf("\n7.Complain/Feedback");
      printf("\n8.Logout\n");
      printf("\nEnter your choice:");
      scanf("%d",&choice);
      return(choice);
     }
  void check()
  {
  	printf("Your total Amount is %lld\n",Total);
  }


   void history()
  {
  	printf("Your total Amount is %d\n",Total);
  }


   void transfer()
  {
  	printf("Your total Amount is %d\n",Total);
  }


   void viewinfo()
  {
  	printf("Your total Amount is %d\n",Total);
  }


   int favour()
  {

      int choose;
      printf("\n1.ADD");
      printf("\n2.VIEW");
      printf("\n3.DELETE");
      printf("\n0.BACK\n");
      printf("\nEnter your choice:");
      scanf("%d",&choose);
        switch(choose)
      {
        case 1:
        add();
        break;

        case 2:
        view();
        break;

        case 3:
            delete_acc();
            break;

        case 0:
            back();
         list();
         break;

          default:
          printf("\nInva:id Option!!");
      }
      getch();
  }

  void add()
  {
      system("cls");
       int i,n;
    FILE *fp;
    struct favourite f[90];
    fp=fopen("favacc.txt","a");
    printf("\nNumber Of accounts You want to add:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Account_ID,Account_Holder_Name,Bank_name:\n");
        scanf("%d%s%s",&f[i].acc_id,f[i].acc_holder_name,f[i].bank);
        fwrite(&f[i],sizeof(struct favourite),1,fp);
    }
    printf("\nAccount Added!");
    fclose(fp);
    getch();
  }
   void view()
   {
       system("cls");
       int i,n=-1;
    FILE *fp;
    struct favourite f[90];
    fp=fopen("favacc.txt","r");
    while(!feof(fp))
    {
     fread(&f[++n],sizeof(struct favourite),1,fp);
    }
    printf("Details:\n");
    printf("Acc_ID\t  Acc_Holder_Name\t  Bank_Name\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",f[i].acc_id);
        printf("      %s\t",f[i].acc_holder_name);
        printf("           %s\n",f[i].bank);
    }
    fclose(fp);

   }

   void delete_acc()
   {
       system("cls");
      FILE *fp;
      struct favourite f[50];
       int i=0,k,dacc_id,length;
      fp=fopen("favacc.txt","r");
       printf("\nEnter the account ID you to delete:");
       scanf("%d",&dacc_id);
       while(!feof(fp))
        {
            fread(&f[i],sizeof(struct favourite),1,fp);
             i++;
         }
            length=i;
//           fflush(fp);
             fclose(fp);
          fp=fopen("favacc.txt","w");
          for(k=0;k<length-1;k++)
           {
              if(f[k].acc_id!=dacc_id)
            fwrite(&f[k],sizeof(struct favourite),1,fp);
            }
             fclose(fp);
            printf("\nRecord Deleted!\n");
             printf("\nPress any key to see content after deletion....");
            getch();
              view();
         }

     void back()
  {
      list();
  }



   void setting()
  {
  	printf("Your total Amount is %d",Total);
  }


      int complain()
  {
      system("cls");
    	int num;
    	char email[100],feedback[1000];
  	    printf("Your complain or feedback \n");
     	printf("Enter your email address::\n");
        scanf("%s",email);
    	getchar();
    	system("cls");
    	printf("Enter your complain/feedback::\n");
    	gets(feedback);
    	getchar();
    	system("cls");
    	printf("\n1.Send");
    	printf("\n0.Back\n");
    	printf("\nEnter your choice:");
    	scanf("%d",&num);
    	switch(num)
    	{
            case 1:
            send();
            break;

            case 0:
            cancel();
            list();
            break;

            default:
                printf("Inva:id option*");
    	}

  }

     void send()
     {
         system("cls");
         printf("Message Sent\n**Thank you for your feedback!**");
     }
     void cancel()
     {
         list();
     }

 void logout()
  {
      system("cls");
      printf("\n*******Thank You For visiting our site********");
      exit(0);
  }

