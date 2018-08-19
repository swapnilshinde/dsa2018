/*Heading : String operations with pointers */
/* Program details:
   Program showing various operations on string(functions implemented
   with pointers).
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
void reverse(char *a);
int palindrome(char *a);
void copy(char *b,char *a);
int compare(char *a,char *b);
void search(char *a,char *b);

int main()
  { char a[100],b[100];
    int result,op;
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
	 switch(op)
	  {
	    case 1: printf("\n Enter a String:");
		    gets(a);
		    reverse(a);
		    printf("\n Result=%s",a);
		    printf("\n\n press a Character !!!!!!");
		    break;
	     case 2: printf("\n Enter a String:");
		    gets(a);
		    result=palindrome(a);
		    if(result==0)
		      printf("\nNot a palindrome");
		    else
		      printf("\nA palindrome");
		     printf("\n\n press a Character !!!!!!");
		    break;
	    case 3: printf("\n Enter a String:");
		    gets(a);
		    copy(b,a);
		    printf("\nResult=%s",b);
		    printf("\n\n press a Character !!!!!!");
		   
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
		    break;
	    case 5: printf("\n Enter 1st string:");
		    gets(a);
		    printf("\n Enter 2nd string:");
		    gets(b);
		    search(a,b);
		    printf("\n\n press a Character !!!!!!");
		  break;
	  }

       }while(op!=6);
       return 0;
  }

void reverse(char *a)
   { char *p,*q;
     char temp;
     /* Algorithm used is an inplace Algorithm
       1. q is postioned on the last character
       2. p is postioned on the first character
       3. *p is interchanged with *q
       4. p is increased by 1 and q is decremented by 1
       5. if p<q then goto step 3
      */
      p=q=a;
      while(*q!='\0')
       q++;
      /* q is on the null character*/
      q--;
      while(p<q)
       { temp=*p; *p=*q;*q=temp;
	 p++;q--;
       }
     }
int palindrome(char *a)
  { char *p,*q;
   /* Algorith used
      1. q is positioned on the last character
      2. p is positioned on the first character
      3. if *p != *q then it is not a palindrome,return(0)
      4. p is increased by 1 and q is decremented by 1
      5. if p<q then goto step 3
      6. string is a palindrome , return(1)
  */

     p=q=a;
      while(*q!='\0')
       q++;
      /* q is on the null character*/
      q--;/*q is on the last character*/
      while(p<q)
       { if(*p!=*q)
	  return(0);
	 p++;q--;
       }
      return(1);
     }
  void copy(char *b,char *a)
     { while(*a!='\0')
	{ *b=*a;
	  a++;b++;
	}
       *b='\0';
     }

  int compare(char *a,char *b)
     {   /* Algorithm
	  1.both the strings are compared,character by character
	    from the beginning
	  2.on first point of mismatch:
	     a.if(*a>*b) then a>b
	     b.if(*a<b) then a<b
	  3. if both the strings end together then they are eqaul
       */
     while(*a!='\0')
      {
	if(*a > *b)
	     return(1);
	if(*a < *b)
	     return(-1);
	a++;b++;
      }
       return(0);
    }

void search(char *a ,char *b)
  { int lena,lenb;
    char *i,*j,*k;
    /*Algorithm
      1. lenb=length of string b[],lena=length of a[]
	string a[] is scanned using the pointer i from location
	0 to length of a[]-lenb+1
      2. string b[] is matched in string a[] from the position i
    */
   for(lena=0;*(a+lena)!='\0';lena++)
   ;
   for(lenb=0;*(b+lenb)!='\0';lenb++)
   ;

   /* searching */
   for(i=a;i<=a+lena-lenb+1;i++)
    {  k=i;
       for(j=b;*k==*j&& *j!='\0';j++,k++)
       ;
       if(*j=='\0')
	     printf("\nstring found at location:%d",i-a+1);
    }
  }
