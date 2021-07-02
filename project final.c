#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>

struct contact
{
	long int phno;
	char name[30],add[40],email[10];
	
}list;
char query[30],name[30];
FILE *fp,*ft;
int i,n,ch,found,l,dch;
long int ph;

int main()
{
	main:
		system("cls");
		printf("\n\t******Welcome to contact management******");
		printf("\n\n\n\t\t\tMAIN MENU");
		printf("\n\t\t====================");
		printf("\n\t\t1.Add new contact");
		printf("\n\t\t2.List of all contacts");
		printf("\n\t\t3.Search for contact");
		printf("\n\t\t4.Edit a contact ");
		printf("\n\t\t5.Delete a contact");
		printf("\n\t\t6.Erase all contacts");
		printf("\n\t\t7.exit");
		printf("\n\t\t=====================");
		
		printf("Enter your choice");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0:
				printf("\n\n\t\t Are you sure you want t exit");
				break;
			
			case 1:
			system("cls");
			fp=fopen("contact.dll","a");
			for(;;)
			{
				fflush(stdin);
				printf("\nTo exit enter the blank space or press the space bar in place of name input");
				printf("\n Name(use identical):\t");
				scanf("%[^\n]",&list.name);
				if(stricmp(list.name,"")==0|| stricmp(list.name," ")==0)
				break;
				
				
				fflush(stdin);
				printf("phone number:\t");
				scanf("%ld",&list.phno);
				
				fflush(stdin);
				printf("Address:\t");
				scanf("%[^\n]",&list.add);
				
				fflush(stdin);
				printf("E-mail address(ID):\t");
				gets(list.email);
				printf("\n");
				
				fwrite(&list,sizeof(list),1,fp);
			}
		
		fclose(fp);
		break;
		
		case 2:
	
	system("cls");
	
	printf("\n\t\t================================\n\t\t\tLIST OF	CONTACTS\n\t\t================================\n\nName\t\tPhone No\t Address\t\tE-mail	ad.\n=================================================================\n\n");

	for(i=97; i<=122; i=i+1)

	{		

		fp=fopen("contact.dll","r");

		fflush(stdin);

		found=0;

		while(fread(&list,sizeof(list),1,fp)==1)

		{	

			if(list.name[0]==i || list.name[0]==i-32)

			{	

				printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t:%s\n",list.name,list.phno,list.add,list.email);

				found++;
			}

		}

		if(found!=0)

		{	
			printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

			getch();
		}

	fclose(fp);

	}

	break;

	case 3:

	system("cls");
	do
	{


		found=0;


		printf("\n\n\t..::CONTACTSEARCH\n\t===========================\n\t..::Name of the contact to search:");


		fflush(stdin);
		scanf("%[^\n]",&query);
		l=strlen(query);
		fp=fopen("contact.dll","r");
		system("cls");
		printf("\n\n..::Search result for'%s'\n====================================================\n",query);
		while(fread(&list,sizeof(list),1,fp)==1)
		{
			for(i=0;i<=l;i++)
   			name[i]=list.name[i];
 			name[l]='\0';
 			if(stricmp(name,query)==0)
 			{
  				printf("\n..::Name\t:%s\n..::Phone\t:%ld\n..::Address\t:%s\n..::Email\t:%s\n",list.name,list.phno,list.add,list.email);

				found++;
				if(found%4==0)
				{
					printf("..::Press any key to continue...");
					getch();

				}


    		}



		}	

		if(found==0)
 
  			printf("\n..::No match found!");
 
		else
 
  			printf("\n..::%d match(s)found!",found);
 
		fclose(fp);
  		printf("\n..::Try again?\n\n\t[1]Yes\t\t[0]No\n\t");
  		scanf("%d",&ch);
   
 
	}
	while(ch==1);
	break;
	case 4:
		system("cls");
		fp=fopen("contact.dll","r");
		ft=fopen("temp.dat","w");
		fflush(stdin);
		printf("....Edit contact ");
		printf("\n================\n");
		printf("\n\t....Enter the name of contact to edit:");
		scanf("%[^\n]",name);
		while(fread(&list,sizeof(list),1,fp)==1)
		{
			
			
			
			if(stricmp(name,list.name)==0)
			
			fwrite(&list,sizeof(list),1,ft);
			else 
			{
			
			printf("contact doesnt exist");
			exit(0);
			
			}
	}
			
			
			
		
		fflush(stdin);
		printf("\n\n...::Editing '%s'\n\n",name);
		printf("...::Name(Use identical):");
		scanf("%[^\n]",&list.name);
		fflush(stdin);
		printf("...:phone:");
		scanf("%ld",&list.phno);
		fflush(stdin);
		printf("..::Address:");
		scanf("%[^\n]",&list.add);
		fflush(stdin);
		printf("...:Email address");
		gets(list.email);
		printf("\n");
		fwrite(&list,sizeof(list),1,ft);
		fclose(fp);
		fclose(ft);
		remove("contact.dll");
		rename("temp.dat","contact.dll");
		
		break;
		
		case 5:
		system("cls");
			fflush(stdin);
		printf("\n\n\t...:: DELETE A CONTACT");
		printf("\n\t==================");
				fflush(stdin);
				printf("\n\n\t...::Enter the name of the contact to delete\n\t");
				scanf("%[^\n]",&name);
				fp=fopen("contact.dll","r");
				ft=fopen("temp.dat","w");
				while(fread(&list,sizeof(list),1,fp)!=0)
				if(stricmp(name,list.name)!=0)
				fwrite(&list,sizeof(list),1,ft);
				fclose(fp);
				fclose(ft);
				remove("contact.dll");
				rename("temp.dat","contact.dll");
				
			
			break;
	case 6:
    	printf("\n\n\tare you sure you want to delete all the contacts");
    	printf("\n\n\t press 1 to delete");
    	printf("\n\n\t press 2 to exit");
    	scanf("%d",&da);
    	if(da==1)
    	{
    		fclose(fopen("contact.dll", "w"));
		}
		else 
		{
			
			printf("\n\n\t\toperation cancelled");
			getch();
			
			goto main;
		}
		break;
		
	case 7:
			exit(0);
			break;
		
	deafult:
			printf("invalid choice");
			break;
	}	
	

	printf("\n\n\n\t....::Enter the choice");
	printf("\n\n\t1.Main menu");
	printf("\n\n\t2.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			goto main;
		case 2:
			break;
		default:
			printf("invalid choice");
			break;
	}
	return 0;
}
	
		
								
									
		
		
		

