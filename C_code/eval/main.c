#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//self-referential structure
struct stackNode{
	char data; //define data as character
    struct stackNode *nextPtr; // stackNode pointer;
};



typedef struct stackNode StackNode; // synonym for struct StackNode
typedef StackNode *StackNodePtr; // synonym for StackNode*

struct stackNumberNode {
	int data; // define data as a character
	struct stackNumberNode* nextPtr; // stackNode pointer
};


typedef struct stackNumberNode StackNumberNode;
typedef StackNumberNode *StackNumberNodePtr;

// prototypes
void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
char stackTop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);
int isoperator(char value);
int precedence(char opl, char op2);
void convertToPostfix(char infix[], char postfix[]);

void  numberpush(StackNumberNodePtr  *topPtr,int value);
int numberpop(StackNumberNodePtr *topPtr);
int isnumberEmpty(StackNumberNodePtr topPtr);
void printnumberStack(StackNumberNodePtr topPtr);
int calculate(int op1, int op2,	char operator);
int evaluatePostfixEpression(char *expr);

StackNodePtr stackPtr = NULL; // points to stack top
StackNumberNodePtr stackNumberPtr = NULL;

int main(void)
{
     char infixexp[80], postfixexp[80];
     puts("Please input your calculation expression below!!!!!");
     scanf("%s",infixexp);
     convertToPostfix(infixexp,postfixexp);
     printf("Postfix string is : %s\n\n", postfixexp);
     printf("The result is %d \n", evaluatePostfixEpression(postfixexp));
}

int isoperator(char value)
{
     if(value == '^' || value == '*' || value == '/' || value == '%' || value == '+' || value == '-') {
        return 1;
     }
     else {
        return 0;
     }
}

int precedence(char op1, char op2)
{
     if (op1 == '^'){
          if (op2 = '^'){
               return 0;
          }
          else {
          return 1;
          }
}
     if (op1 == '*' || op1 == '/' || op1 == '%') {
         if (op2 == '^') {
             return -1;
         }
         else {
             if (op2 == '*' || op2 == '/' || op2 == '%') {
                 return 0;
             }
             else {
                 return 1;
             }

         }
     }
     if (op2 == '+' || op2 == '-') {
          return 0;
     }
     else {
          return -1;
     }
}

void convertToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char value;
    push(&stackPtr, '(');
    strcat(infix, ")");
    while (!isEmpty(stackPtr)) {
        value = infix[i];
        if (isdigit(value)) {
            postfix[j++] = value;
        }
        if (value == '(') {
            push(&stackPtr, '(');
        }
        if (isoperator(value)) {
            while ((isoperator(stackTop(stackPtr))) && (precedence(stackTop(stackPtr), value) >= 0)) {
                postfix[j++] = pop(&stackPtr);
            }
            push(&stackPtr, value);
        }
        if (value == ')') {
            while (stackTop(stackPtr) != '(') {
                postfix[j++] = pop(&stackPtr);
            }
            value = pop(&stackPtr);	// discard
        }
        i++;
        printf("%s", "Postfix string is : ");
        for (int k = 0; k < j; k++) { printf("%c", postfix[k]); }
        printf("\n");
        printStack(stackPtr);
    }
    postfix[j] = '\0';
}

void numberpush(StackNumberNodePtr *topPtr,int value)
{
     StackNumberNodePtr  newPtr = malloc(sizeof(StackNumberNode));


     // insert the node at stack top

     if (newPtr != NULL) {
          newPtr->data = value;
          newPtr -> nextPtr = *topPtr;
          *topPtr = newPtr;
     }
     else { // no space available
          printf("%c not inserted. No memory available.\n", value);
     }
}

int numberpop(StackNumberNodePtr *topPtr)
{
     StackNumberNodePtr tempPtr = *topPtr;
     int popValue = (*topPtr)->data;
     *topPtr = (*topPtr)->nextPtr;
     free(tempPtr);
     return popValue;
}

int isnumberEmpty(StackNumberNodePtr topPtr)
{
return topPtr == NULL;
}

void printnumberStack(StackNumberNodePtr currentPtr)
{
     if (currentPtr == NULL) {
           puts("The stack is empty.\n");
     }
     else {
          puts("The number stack is:");

          // while not the end of the stack
          while (currentPtr != NULL) {
              printf("%d -- > ", currentPtr->data);
              currentPtr = currentPtr->nextPtr;
          }

          puts("NULL\n");
     }
}

int calculate(int op1, int op2, char operator)
{
     switch (operator)
     {
     case '+':
        return(op1 + op2);
        break;
     case '-':
        return(op1 - op2);
        break;
     case '*':
        return(op1 * op2);
        break;
     case '/':
        return (op1 / op2);
        break;
     case '^':
        return ((int)pow(op1 , op2));
         break;
     case '%':
        return(op1 % op2);
        break;
     default :
        return 0;
        break;
     }
}

int evaluatePostfixEpression(char *expr)
{
     int pos = 0;
     while(expr[pos] != '\0') {
         printf("The postfix string is : %s\n", &expr[pos]);
         printnumberStack(stackNumberPtr);
         if(isdigit(expr[pos])) {
              numberpush(&stackNumberPtr, expr[pos] - '0');
         }
         else {

            int op2 = numberpop(&stackNumberPtr);
            int op1 = numberpop(&stackNumberPtr);
            numberpush(&stackNumberPtr, calculate(op1, op2 , expr[pos]));
         }
         pos++;
     }
     return numberpop(&stackNumberPtr);
}


// insert a node at the stack top
void push(StackNodePtr *topPtr, char value)
{
     StackNodePtr newPtr = malloc(sizeof(StackNode));

     // insert the node at stack top
     if (newPtr != NULL) {
          newPtr->data = value;
          newPtr-> nextPtr = *topPtr;
          *topPtr = newPtr;
     }
     else { // no space available
          printf("%c not inserted. No memory available.\n", value);
     }
}


// remove a node from the stack top
char pop(StackNodePtr *topPtr)
{
     StackNodePtr tempPtr = *topPtr;
     char popValue = (*topPtr)->data;
     *topPtr = (*topPtr)->nextPtr;
     free(tempPtr);
     return popValue;
}


char stackTop(StackNodePtr topPtr)
{
return topPtr->data;
}


// print the stack
void printStack(StackNodePtr  currentPtr)
{

   // if stack is empty
   if (currentPtr == NULL) {
   puts("The stack is empty.\n");
   }
   else {
        puts("The stack is:");

        // while not the end of the stack
        while (currentPtr != NULL) {
            printf("'%c' --> ", currentPtr -> data);
            currentPtr = currentPtr -> nextPtr;
        }

        puts("NULL\n");
   }
}

// return 1 if the stack is empty , 0 otherwise
int isEmpty(StackNodePtr topPtr)
{
return topPtr == NULL;
}

