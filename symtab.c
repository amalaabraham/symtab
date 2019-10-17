#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct symbol{
    char name[30];
    int value;

}symbol[10];

void clear(struct symbol symbol[])
{
	for(int i=0;i<10;i++)
	{
		strcpy(symbol[i].name,"NULL");
		symbol[i].value=0;
	}
	
}
void create(struct symbol symbol[],int n)
{
clear(symbol);
for(int i=0;i<n;i++)
{
scanf("%s %d",symbol[i].name,&symbol[i].value);
}
strcpy(symbol[n].name,"NULL");
symbol[n].value=0;
}


void insert(struct symbol symbol[])
{
	int i=0;
	while(strcmp(symbol[i].name,"NULL")!=0) i++;
	scanf("%s %d",symbol[i].name,&symbol[i].value);
	i++;
	strcpy(symbol[i].name,"NULL");
	symbol[i].value=0;

}

int search(struct symbol symbol[], char *name)
{
	int i=0;
	while(strcmp(symbol[i].name,name)!=0 && i<10) i++;
	if(strcmp(symbol[i].name,name)==0)
	{
	printf("\tVarible found at %d\n",i+1);
	printf("\tValue of %s is %d\n",symbol[i].name,symbol[i].value);
	return i;
	}
	else 
	{
	printf("\tVarible not found !");
	return -1;
	}	
}

int modify(struct symbol symbol[],int loc,int value)
{

	symbol[loc].value=value;
}

void display(struct symbol symbol[])
{
	int i=0;	
	while(strcmp(symbol[i].name,"NULL")!=0)
	{
		printf("\t%s %d\n",symbol[i].name,symbol[i].value);
		i++;
	}	

}

int main()
{
int op,n=0,loc=0,value=0;
char name[30];
while(1)
{
	printf("\nEnter option : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:	printf("\nEnter no. of enteries : ");
			scanf("%d",&n);
			create(symbol,n);break;
		case 2:	printf("\nEnter the varible name and value : ");	
			insert(symbol);break;
		case 3:	printf("\nEnter the varible name : ");
			scanf("%s",name);
			loc=search(symbol,name);
			if(loc!=-1){
			printf("\nEnter the new value : ");
			scanf("%d",&value);
			modify(symbol,loc,value);
			display(symbol);}break;
		case 4:	printf("\nEnter the varible name : ");
			scanf("%s",name);
			loc=search(symbol,name);break;
		case 5:	display(symbol);break;
		case 6:	exit(0);
		default:printf("Invalid option !");
			break;
		
	}
}
	return 0;
}
