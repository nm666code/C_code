#include <stdio.h>
#include <stdlib.h>

int first = 1;
void funca(int *);
void funcb(int **);
void getmem(char **);

int main(void) {
    int second = 2;
    int *ptr = &second;
    char *three = NULL;
    char myarray1[] = "Testing String Pointer";
    char *chptr = myarray1;
    int *intptr = (int *)myarray1;
    char myarray2[] = "0123456";
    int myarray3[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    char *myarray4[][3] = {"January", "Febuary", "March","April", "May", "June","July", "August", "September"};
    char myarray5[3][9] = {"October", "Novenber", "Decenber"};
    int myarray6[4][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {9, 11, 13, 15}, {10, 12, 14, 16}};
    int *test1[3] = {myarray3 + 2, myarray3 + 8, myarray3 + 5};
    int (*test2)[4] = myarray6 + 2;

    funca(ptr);
    printf("funca(ptr)--> *ptr = %d\n", *ptr);
    funcb(&ptr);
    printf("funcb(ptr)--> *ptr = %d\n", *ptr);
    getmem(&three);
    printf("&three = 0x%p\n\n", &three);
    printf("three = 0x%p\n\n", three);
    printf("my array1 = %s\n", myarray1);
    printf("chptr = %s\n", chptr);
    printf("*chptr = %c\n", *chptr);
    printf("chptr + 2 = %s\n", chptr + 2);
    printf("*(chptr + 2) = %c\n", *(chptr + 2));
    printf("intptr = %s\n", intptr );
    printf("*intptr = %c\n", *intptr );
    printf("*intptr + 2 = %c\n", *intptr + 2);
    printf("*(intptr + 2) = %c\n\n", *(intptr + 2) );
    chptr = myarray2;
    printf("chptr = %s\t(0x%p)\n", chptr, chptr);
    printf("*chptr++ = %c\t%s\t(0x%p)\n", *chptr++, chptr, chptr);
    printf("*(chptr++) = %c\t%s\t(0x%p)\n", *(chptr++), chptr, chptr);
    printf("(*(chptr))++= %c\t%s\t(0x%p)\n", (*(chptr))++, chptr, chptr);
    printf("*(chptr)++ = %c\t%s\t(0x%p)\n", *(chptr)++, chptr, chptr);
    printf("*++chptr = %c\t%s\t(0x%p)\n", *++chptr, chptr, chptr);
    printf("*(++chptr) = %c\t%s\t(0x%p)\n", *(++chptr), chptr, chptr);
    printf("++*chptr = %c\t%s\t(0x%p)\n", ++*chptr, chptr, chptr);
    printf("++(*chptr) = %c\t%s\t(0x%p)\n", ++(*chptr), chptr, chptr);
    printf("myarray2 = %s\n\n", myarray2);
    intptr = (int*)(&myarray3 + 1);
    puts("myarray3 = {1,9,2,8,3,7,4,6,5}\t intptr = (int*)&myarray3 + 1");
    printf("&myarray3 = 0x%p\t\t", &myarray3);
    printf("&myarray3 + 1 = 0x%p\n", &myarray3 + 1);
    printf("intptr = 0x%p\t\t", intptr);
    printf("*(intptr) = %d\n",*(intptr));
    printf("intptr - 1 = 0x%p\t\t", intptr - 1);
    printf("*(intptr - 1) = %d\n", *(intptr - 1));
    printf("intptr - 3 = 0x%p\t\t", intptr - 3);
    printf("*(intptr - 3) = %d\n", *(intptr - 3));
    printf("myarray3 = 0x%p\t\t", myarray3);
    printf("*myarray3 = %d\n", *myarray3);
    printf("*myarray3 + 7 = %d\t\t", *myarray3 + 7);
    printf("*(myarray3 + 7) = %d\n", *(myarray3 + 7));
    intptr = myarray3;
    ptr = myarray3 + 4;
    puts("intptr = myarray3                 ptr = myarray3 + 4");
    printf("ptr - intptr = %d\t\t", ptr - intptr);
    printf("(char*)ptr - (char*)intptr = %d\n", (char*)ptr - (char*)intptr);
    printf("*ptr - *intptr = %d\t\t", *ptr - *intptr);
    printf("*(4 + myarray3) = %d\t\t", *(4 + myarray3));
    printf("4[myarray3] = %d\n\n", 4[myarray3]);
    printf("myarray4[1][2] = %s    \tmyarray5[1][2] = %c\n", myarray4[1][2], myarray5[1][2]);
    printf("myarray6 = %p    \t\tmyarray6 + 1 = %p\n", myarray6, myarray6 + 1);
    printf("(myarray6 + 1)[2] = %p  \t((myarray6 + 1)[2]) = %p\n", (myarray6 + 1)[2], ((myarray6 + 1)[2]));
    printf("*(myarray6 + 1)[2] = %d  \t*((myarray6 + 1)[2]) = %d\n", *(myarray6 + 1)[2], *((myarray6 + 1)[2]));
    printf("(*(myarray6 + 1))[2] = %d  \t(*(myarray6 + 2)[1]) = %d\n\n", (*(myarray6 + 1))[2], (*(myarray6 + 2)[1]));
    printf("Array test1 = \t%d\t%d\t%d\n\n", *test1[0], *test1[1], *test1[2]);
    printf("Array test2 = \t%d\t%d\t%d\t%d\n\n", (*test2)[0], (*test2)[1], (*test2)[2], (*test2)[3]);
    printf("Array test2+1 = \t%d\t%d\t%d\t%d\n\n", (*(test2+1))[0], (*(test2+1))[1], (*(test2+1))[2], (*(test2+1))[3]);
    return 0;
}

void funca(int *p1){
    p1 = &first;
}

void funcb(int **p2){
    *p2 = &first;
}

void getmem(char **p3){
    *p3 = malloc(sizeof(char));
    printf("p3 = 0x%p\n", p3);
    printf("*p3 = 0x%p\n", *p3);
}
