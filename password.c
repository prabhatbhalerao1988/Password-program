#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ATTEMPTS 3
#define PASSWORD "secret123"
int a;//global varible

typedef struct Stack 
{
    char* attempts[MAX_ATTEMPTS]; // Array to store the attempts
    int top;                      // Index of the top of the stack
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) 
{
    stack->top=-1; // Initialize the top of the stack to -1 (empty)
}

// Function to push a password attempt onto the stack
void push(Stack* stack, const char* attempt) 
{
    if (stack->top<MAX_ATTEMPTS-1) 
	{
        stack->top++;
        stack->attempts[stack->top] = (char*)malloc(strlen(attempt) + 1); 
        strcpy(stack->attempts[stack->top], attempt); // Copy the attempt into the stack
    }
}

// Function to pop the top password attempt from the stack
char* pop(Stack* stack) 
{
    if (stack->top>=0)
	 {
        char* attempt=stack->attempts[stack->top];
        stack->top--;
        return attempt;
    }
    return NULL;
}

int checkPassword(const char* input)
 {
    return strcmp(input,PASSWORD)==0; // Return 1 if passwords match, 0 otherwise
}

// Function to print the history of password attempts
void printAttemptHistory(Stack* stack) 
{
    printf("\nPassword Attempt History:\n");
    for (a=0;a<=stack->top;a++)
	{
        printf("Attempt %d: %s\n",a+1,stack->attempts[a]);
    }
}

int main() 
{
    Stack stack;
    char p[50];
    int attemptsLeft = MAX_ATTEMPTS;
    
    initStack(&stack);
    
    // Allow the user 3 attempts to enter the correct password
    while (attemptsLeft>0) 
	{
        printf("Enter password (Remaining attempts: %d): ",attemptsLeft);
        scanf("%s",&p);
        
        // Push the attempt onto the stack
        push(&stack,p);
        
        // Check if the entered password matches the correct one
        if (checkPassword(p))
		 {
            printf("Password correct! Access granted.\n");
            break;
        } 
		else 
		{
            attemptsLeft--;
            printf("Incorrect password. ");
            if (attemptsLeft==0) 
			{
                printf("No more attempts left. Exiting...\n");
            } 
			else 
			{
                printf("You have %d attempts left.\n", attemptsLeft);
            }
        }
    }


    printAttemptHistory(&stack);
    while (stack.top>=0) 
	{
        char* attempt = pop(&stack);
        free(attempt);
    }

    return 0;
}

