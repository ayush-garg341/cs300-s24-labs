#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define BUFSIZE 32

// unused...?
void hack() {
    printf("you've been hacked!\n");
    exit(0);
}

void foo() {
    // stack allocate some variables
    const int fav_number = 3; // your favorite number is a constant so it can't change
    char buf[BUFSIZE];

    // print favorite number
    printf("My favorite number is %d and it will always be %d and nothing can change that\n", fav_number, fav_number);

    // get a string from stdin
    gets(buf);

    // print favorite number again bc its a great number and you want the world to know
    printf("My favorite number is %d and it will always be %d and nothing can change that\n", fav_number, fav_number);

}

int main(int argc, char **argv) {

    foo();

    printf("Returned to main safe and sound\n");

    return 0;
}


// This program is compiled with debug symbols i.e -g option.
// Run it via gdb like gdb buffer
// set breakpoint at foo like break foo
// run
// si
// p &fav_number -> will give address on stack
// p &buf -> will give address on stack
// Stack grows downward, but the memory addresses decreases as we go down.

// If address(fav_number) > address(buf) then it means buf is above on stack and fav_number is below on stack.
// address(fav_number) - address(buf) = 44
// We have to overwrite 44 characters
// fav_number is integer which is 4 bytes and we have address of first byte of an integer in fav_number
// It means if we just overwrite 44 bytes then 44th byte will be stored in fav_number.


// Eg:- "I am Ayush Garg. I am working as a senior so"
// if we enter p, or q or r afer so, we will get 112, 113, 114 as fav_number
// If we change multiple bytes like pq or pqr then address will be like 29040 or 7500144 or in case of pqrs it will be 1936879984


// Most computer systems are litle endian, it means the least significant byte (LSB) is stored first (lowest memory address).

// And stack grows downward, so for "pqrs" it will be somthing like shown below:
// p[0] = 0x70 -> first address ( LSB ), hex code of p
// p[1] = 0x71 -> second address, hex code of q
// p[2] = 0x72 -> third address, hex code of r
// p[3] = 0x73 -> fourth address ( MSB ), hex code of s

// And finally it will be formed like 0x73727170, which corresponds to 1936879984
// So we can change the fav number to anything we want.
// But we should not modified stack many bytes as we will get seg fault

