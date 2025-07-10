#include <stdio.h>
#include <string.h>

void win() {
    printf("You win!\n");
}

void vulnerable() {
    char buffer[64];
    printf("Enter your name:");
    gets(buffer); // Vulnerable to buffer overflow
    printf("Hello, %s\n", buffer);
}

int main() {
    vulnerable();
    return 0;
}