#include <stdio.h>

int main() {
    printf ("in main\n");
    return 16;
}

__attribute__((constructor))
void ctor() {
    printf("befor main\n");
}

__attribute__((destructor))
void dctor() {
    printf("after main\n");
}
