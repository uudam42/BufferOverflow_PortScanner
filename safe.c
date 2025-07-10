#include <stdio.h>
#include <string.h>

void win() {
    printf("You win!\n");
}

void safe(){
    char buffer[64];
    printf("Enter your name:");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Hello, %s\n", buffer);
}

int main() {
    safe();
    return 0;
}