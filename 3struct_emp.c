/*Program for  Operations on a database without using pointers*/
/* Program details:
 Various operations like read,insert,delete,print,sort,modify for employee database
*/

#include <stdio.h>
#include <string.h>
typedef struct employee
 { int code;
   char name[20];
   int  salary;
 }employee;
void insert(employee st[],int position,int n);
void Delete(employee st[],int position,int n);
int  search(employee st[],int code,int n);
void print(employee st[],int n);
void read(employee st[],int n);
void sort(employee st[],int n);
void modify(employee st[],int n);
 void main()
  { employee st[30];
    int n,i,op,position,code;
    do{

       printf("\n1)create\n2)insert\n3)delete\n4)search\n5)print\n6)Sort\n7)Modify");
       printf("\n8)Quit");
       printf("\nEnter Your Choice:");
       scanf("%d",&op);
       switch(op)
	{ case 1: printf("\nEnter No. of employees:");
		  scanf("%d",&n);
		  read(st,n);
		  break;
	  case 2: printf("\n enter the position(no of records=%d):",n);
		   scanf("%d",&position);
		  if(position<=n+1)
		   {
		     insert(st,position,n);
		     n++;
		     print(st,n);
		   }
		  else
		   printf("\n can not insert");
		  break;
	  case 3:printf("\n enter the code : ");
		 scanf("%d",&code);
		 position=search(st,code,n);
		 if(position != -1 )
		  {
		    Delete(st,position,n);
		    n--;
		    print(st,n);
		  }
		else
		 printf("\n can not delete ");
		 break;
	  case 4: printf("\nenter code:");
		  scanf("%d",&code);
		  position=search(st,code,n);
		  if(position==-1)
		    printf("\nnot found");
		  else
		   { printf("\n found at location=%d",position+1);
		     printf("\n %s\t%d\t%d",st[position].name,st[position].code,st[position].salary);
		   }
		 break;
	  case 5: print(st,n);
		  break;
	  case 6: sort(st,n);print(st,n);break;
	  case 7: modify(st,n);print(st,n);break;
	}
    }while(op!=8);
  }


void  insert( employee st[],int position,int n)
	{ int i;
	  printf("\n enter data(name code  salary): ");
	  for(i=n-1;i>=position-1;i--) /*index is 1 less than position*/
	     st[i+1]=st[i];
	  scanf("%s%d%d",st[position-1].name,&st[position-1].code,&st[position-1].salary);
	}

void  Delete(employee st[],int position,int n)
      { int i;
	for(i=position+1;i<n;i++)
	  st[i-1]=st[i];
      }
int   search(employee st[],int code,int n)
       { int i;
	 for(i=0;i<n;i++)
	   if(code==st[i].code)
	     return(i);
	 return(-1);
       }

void print(employee st[],int n)
       { int i;
	  for(i=0;i<n;i++)
	    printf("\n%20s%5d%5d",st[i].name,st[i].code,st[i].salary);
       }

void read(employee st[],int n)
   { int i;
	  printf("\n enter data(name code salary): ");
	  for(i=0;i<n;i++)
	    scanf("%s%d%d",st[i].name,&st[i].code,&st[i].salary);
    }
void modify(employee st[], int n)
 {
   int code,i;
   printf("\nEnter the code : ");
   scanf("%d",&code);
   i=search(st,code,n);
   if(i==-1)
       printf("\nNo such rollno  ");
   else
     {
	  printf("\n enter data(name code salary): ");
	  scanf("%s%d%d",st[i].name,&st[i].code,&st[i].salary);
      }
  }
void sort(employee st[],int n)
 { int i,j;
   employee temp;
   for(i=1;i<n;i++)
      for(j=0;j<n-i;j++)
       if(st[j].code > st[j+1].code)
	   {
	      temp=st[j];
	      st[j]=st[j+1];
	      st[j+1]=temp;
	   }
 }
