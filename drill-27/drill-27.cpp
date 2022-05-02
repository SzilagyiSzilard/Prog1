#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is\"%s\" and x is %i\n", p, x);
}

int main()
{
   //1
    printf("Hello World!\n");

    //4
    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);

   //3
    print_out("Aert", 12);
    print_out("asf", 2345);
    print_out("DFG", 8456);
    return 0;
}
