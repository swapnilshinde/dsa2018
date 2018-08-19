/*Heading : String operations without pointers */
/* Program details:
   Program showing various operations on string(functions implemented
   without pointers).
   functions implemented:
   (1) Reversing a string
   (2) Palindrome
   (3) Copy
   (4) String comparison
   (5) Searching a string(substring)
 */
#include <stdio.h>

#include<ctype.h>
#include<stdlib.h>
/*function prototypes*/
void reverse(char a[]);
int palindrome(char a[]);
void copy(char a[],char b[]);
int compare(char a[],char b[]);
void search(char a[],char b[]);

void main()
  { char a[100],b[100];
    int result,op;
    clrscr();
    do
      {               /* display the menu */
	 printf("\n1)Reverse the Given String");
	 printf("\n2)Check for palindrome");
	 printf("\n3)Copy");
	 printf("\n4)String Comparison");
	 printf("\n5)String Searching(substring)");
	 printf("\n6)Quit");
	 printf("\n\nEnter Your Choice:");
	 scanf("%d",&op);
	 flushall();
	 switch(op)
	  {
	    case 1: printf("\n Enter a String:");
		    gets(a);
		    reverse(a);
		    printf("\n Result=%s",a);
		    printf("\n\n press a Character !!!!!!");
		    getch();
		    break;
	     case 2: printf("\n Enter a String:");
		    gets(a);
		    result=palindrome(a);
		    if(result==0)
		      printf("\nNot a palindrome");
		    else
		      printf("\nA palindrome");
		     printf("\n\n press a Character !!!!!!");
		    getch();
		    break;
	    case 3: printf("\n Enter a String:");
		    gets(a);
		    copy(b,a);
		    printf("\nResult=%s",b);
		    printf("\n\n press a Character !!!!!!");
		    getch();
		    break;
	    case 4: printf("\n Enter 1st string:");
		    gets(a);
		    printf("\n Enter 2nd string:");
		    gets(b);
		    result=compare(a,b);
		    if(result==0)
		      printf("\nboth are same");
		    else
		       if(result>0)
			 printf("\n1st>2nd");
			   else
			     printf("\n1st<2nd");
		    printf("\n\n press a Character !!!!!!");
		    getch();break;
	    case 5: printf("\n Enter 1st string:");
		    gets(a);
		    printf("\n Enter 2nd string:");
		    gets(b);
		    search(a,b);
		    printf("\n\n press a Character !!!!!!");
		    getch();break;
	  }

       }while(op!=6);
  }
void reverse(char a[])
   { int i,j;
     char temp;
     /* Algorithm used is an inplace Algorithm
       1. j is postioned on the last character
       2. i is postioned on the first character
       3. a[i] is interchanged with a[j]
       4. i is increased by 1 and j is decremented by 1
       5. if i<j then goto step 3
      */
      i=j=0;
      while(a[j]!='\0')
       j++;
      /* j is on the null character*/
      j--;
      while(i<j)
       { temp=a[i]; a[i]=a[j];a[j]=temp;
	 i++;j--;
       }
     }
int palindrome(char a[])
  { int i,j;
   /* Algorith used
      1. j is positioned on the last character
      2. i is positioned on the first character
      3. if a[i] != a[j] then it is not a palindrome,return(0)
      4. i is increased by 1 and j is decremented by 1
      5. if i<j then goto step 3
      6. string is a palindrome , return(1)
  */

     i=j=0;
      while(a[j]!='\0')
       j++;
      /* j is on the null character*/
      j--;/*j is on the last character*/
      while(i<j)
       { if(a[i]!=a[j])
	  return(0);
	 i++;j--;
       }
      return(1);
     }
  void copy(char b[],char a[])
     { int i=0;
       while(a[i]!='\0')
	{ b[i]=a[i];
	  i++;
	}
       b[i]='\0';
     }

  int compare(char a[],char b[])
     { int i;
       /* Algorithm
	  1.both the strings are compared,character by character
	    from the beginning
	  2.on first point of mismatch:
	     a.if(a[i]>b[i]) then a>b
	     b.if(a[i]<b[i]) then a<b
	  3. if both the strings end together then they are eqaul
       */
     i=0;
     while(a[i]!='\0')
      { if(a[i] > b[i])
	 return(1);
	if(a[i] < b[i])
	 return(-1);
	i++;
      }
      return(0);
    }
void search(char a[] ,char b[])
  { int i,j,lena,lenb;
    /*Algorithm
      1. lenb=length of string b[],lena=length of a[]
	string a[] is scanned using the variable i from location
	0 to length of a[]-lenb+1
      2. string b[] is matched in string a[] from the position i
    */
   for(lena=0;a[lena]!='\0';lena++)
   ;
   for(lenb=0;b[lenb]!='\0';lenb++)
   ;

   /* searching */
   for(i=0;i<=lena-lenb+1;i++)
    {
       for(j=0;a[i+j]==b[j]&&b[j]!='\0';j++)
       ;
       if(b[j]=='\0')
	  printf("\nstring found at location:%d",i+1);
    }
  }
