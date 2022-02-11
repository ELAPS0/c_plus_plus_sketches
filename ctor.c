#include <stdio.h>

int main() {
    printf ("in main\n");
    return 16;
}
__attribute__((constructor))
void ctor() {
    printf("befor main call from %p\n", __builtin_return_address(0));
}
__attribute__((destructor))
void dctor() {
    printf("after main call from %p\n", __builtin_return_address(0));
}
