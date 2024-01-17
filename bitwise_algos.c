#include <stdio.h>

// function prototypes for the compiler: 
int count_set_bits(int number); 
int turn_off_right_bit(int number); 
int is_pow_of_two(int number); 
int find_only_set_bit(int number); 
int xor_without_xor(int num1, int num2); 

int main()
{
    printf("Hello, World!\n");
    
    printf("Number of 1s in 7: %d \n", count_set_bits(7)); 
    printf("Number of 1s in 10: %d \n", count_set_bits(10)); 
    printf("Number of 1s in 214123543: %d \n", count_set_bits(214123543)); 
    
    printf("Turning off rightmost bit of 12: %d \n", turn_off_right_bit(12)); 
    
    printf("is 2 a power of 2: %d \n", is_pow_of_two(2)); 
    printf("is 3 a power of 2: %d \n", is_pow_of_two(3)); 
    printf("is 32 a power of 2: %d \n", is_pow_of_two(32)); 
    
    printf("Find the position of the only set bit of 5: %d \n", find_only_set_bit(5)); 
    printf("Find the position of the only set bit of 10: %d \n", find_only_set_bit(10));
    printf("Find the position of the only set bit of 128: %d \n", find_only_set_bit(128));
    
    printf("XOR of 1 and 2: %d \n", xor_without_xor(1, 2)); 
    printf("XOR of 3 and 5: %d \n", xor_without_xor(3, 5)); 
    
    return 0;
}

// given a number, will count the number of set bits 
int count_set_bits(int number) { 
    int sum_to_return = 0; 
    while (number) { 
        sum_to_return += (number & 1); 
        number = number >> 1;    
    }
    return sum_to_return; 
}

// will turn off the rightmost bit 
int turn_off_right_bit(int number) { 
    return (number & (number - 1)); 
}

// will let you find if a number is a power of 2
int is_pow_of_two(int number) { 
    // naive approach: 
    if (count_set_bits(number) == 1) return 1; 
    return 0; 
}

// return the position of the only set bit
// return -1 if there is more than one set bit, or if 0 
int find_only_set_bit(int number) { 
    if (number == 0) return -1; 
    int position = 1;
    int number_found = 0; // 0 if not found, 1 if found 
    while (number) { 
        if (number_found == 1) return -1; // while loop still going, but we've found a 1 
        if ((number & 1) == 0) ++position; // on a 0, and havent found our number yet 
        else if (number & 1 == 1) number_found = 1; // on a 1, and havent found our number yet, set number found to 1 
        number = number >> 1; // shift over by 1 to analyze next bit 
    }
    return position; 
}

// find the xor of two numbers without using xor 
/* 
can break this problem up by looking at the fundamental truth tables: 
xor: 

a b out 
0 0 0 
0 1 1
1 0 1
1 1 0

or: 

a b out 
0 0 0 
0 1 1
1 0 1
1 1 1 

and: 

a b out 
0 0 0
0 1 0 
1 0 0 
1 1 1 

nand: 

a b out 
0 0 1 
0 1 1 
1 0 1 
1 1 0 

xor = (a | b) & ~(a & b); 
xor = (or) and (nand) of the two numbers 
*/ 

int xor_without_xor(int num1, int num2) { 
    return (num1 | num2) & ~(num1 & num2); 
    // xor = or anded with nand 
}
