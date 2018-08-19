/*Program for  Student information */
/* Program details:
   1. Display the data in descending order of percentage.
   2. Display data for Roll No. specified by the user(linear search).
   3. Display the number of passes and comparisons for different test cases(
      (Worst, Average,Best case).
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct student
 { int rollno;
   char name[20];
   float  perc;
 }student;
int  search(student st[],int rollno,int n);
/* Different cases for searching :
   Best case - Data being searched is the first data
   worst Case - Data being searched is not there.
   Average Case - Data being searched is found around centre.
*/
void print(student st[],int n);
void read(student st[],int n);
void sort(student st[],int n);
/*Different cases for bubble sort :
  Only one case :
     No. of passes = n-1
     no. of comparisons= n(n-1)/2
*/

void main()
  { student st[30];
    int n,i,op,position,rollno;
    clrscr();
    do{
       flushall();
       printf("\n1)create\n2)search\n3)print\n4)Sort(Descending on percentage)\n5)Quit");
       printf("\nEnter Your Choice:");
       scanf("%d",&op);
       switch(op)
	{ case 1: printf("\nEnter No. of student:");
		  scanf("%d",&n);
		  read(st,n);
		  break;
	  case 2: printf("\nenter rollno:");
		  scanf("%d",&rollno);
		  position=search(st,rollno,n);
		  if(position==-1)
		    printf("\nnot found");
		  else
		   { printf("\n found at location=%d",position+1);
		     printf("\n %s\t%d\t%6.2f",st[position].name,st[position].rollno,st[position].perc);
		   }
		 break;
	  case 3: print(st,n);
		  break;
	  case 4: sort(st,n);print(st,n);break;
	}
    }while(op!=5);
  }


int   search(student st[],int rollno,int n)
       { int i,comp=0;;
	 for(i=0;i<n;i++)
	  {  comp++;
	     if(rollno==st[i].rollno)
		{
		   printf("\nNo. of comparisons = %d ",comp);
		   return(i);
		}
	  }
		   printf("\nNo. of comparisons = %d ",comp);
	 return(-1);
       }

void print(student st[],int n)
       { int i;
	  for(i=0;i<n;i++)
	    printf("\n%20s%5d%6.2f",st[i].name,st[i].rollno,st[i].perc);
       }

void read(student st[],int n)
   { int i;
     float perc;
	  printf("\n enter data(name rollno percentage): ");
	  for(i=0;i<n;i++)
	    {
	      scanf("%s%d%f",st[i].name,&st[i].rollno,&perc);
	      st[i].perc=perc;
	    }
    }
void sort(student st[],int n)
 { int i,j,comp=0,passes=0;
   student temp;
   for(i=1;i<n;i++)
    {
       passes++;
       for(j=0;j<n-i;j++)
	{      comp++;
	       if(st[j].perc < st[j+1].perc)
		   {  temp=st[j];
		      st[j]=st[j+1];
		      st[j+1]=temp;
		   }
	}
    }
   printf("\nPasses = %d\t Comparisons = %d",passes,comp);
 }