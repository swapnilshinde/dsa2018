
//Write a program to perform Push, Pop, and Peek operations on a stack.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3 // Altering this value changes size of stack created
int st[MAX], top=-1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

time_t start, finish;

int main() 
{
	time(&start);
	int val;
	int option;
	do
	{	
		printf("\n *****MAIN MENU*****");
				
		printf("\n 1. PUSH");
				
		printf("\n 2. POP");
				
		printf("\n 3. PEEK");
				
		printf("\n 4. DISPLAY");
				
		printf("\n 5. EXIT");
				
		printf("\n Enter your option: ");
				
		scanf("%d", &option);
				
		switch(option)
				
		{
				
			case 1:
					
					printf("\n Enter the number to be pushed on stack: ");
								
					scanf("%d", &val);
								
					push(st, val);
								
					break;
							
			case 2:
					
					val = pop(st);
								
					if(val != -1)
								
					printf("\n The value deleted from stack is: %d", val);
								
					break;
							
			case 3:
					
					val = peek(st);
								
					if(val != -1)
					
					printf("\n The value stored at top of stack is: %d", val);
								
					break;
				
			case 4:								
					display(st);
								
					break;
		}
			
	}while(option != 5);
	
	time(&finish);
	
	printf("\n elapsed time = %.01f seconds", difftime(finish, start));
		
	return 0;
	}


/* push() function will take argument as value to be inserted into stack*/

void push(int st[], int val)
{	
	if(top == MAX-1)	
	{		
		printf("\n STACK OVERFLOW");
	}
	else
	{
		top++;
		st[top] = val;
	}
}

int pop(int st[])
{
	int val;
	if(top == -1)
	{
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else
	{
		val = st[top];
		top--;
		return val;
	}
}

void display(int st[])
{
	int i;
	if(top == -1)
		printf("\n STACK IS EMPTY");
	else
	{
		for(i=top;i>=0;i--)
			printf("\n %d",st[i]);
		printf("\n"); // Added for formatting purposes
	}
}

int peek(int st[])
{
	if(top == -1)
	{
		printf("\n STACK IS EMPTY");
		return -1;
	}
	else
		return (st[top]);
}
