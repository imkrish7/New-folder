#include<stdio.h>


void foo()
{
printf("I am writing this after main terminated !!");
}

int main()
{

printf("In main !!");

atexit(foo);

return 0;
}

