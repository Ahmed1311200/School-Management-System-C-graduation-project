#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED



//the sum of number
#define SUM(n) ((n) * ((n) + 1) / 2)
// Sets the specified bit in 'a' to 1.
#define SET_BIT(a, bit)  ((a) |= (1 << (bit)))

// Clears the specified bit in 'a', setting it to 0.
#define CLEAR_BIT(a, bit)  ((a) &= ~(1 << (bit)))

// Toggles the specified bit in 'a', flipping it from 0 to 1 or from 1 to 0.
#define TOGGLE_BIT(a, bit)  ((a) ^= (1 << (bit)))

// Reads the specified bit in 'num'.
#define READ_BIT(num, bit) (((num) >> (bit)) & 1)

// Checks the value of the specified bit in 'a' and returns it as either 0 or 1.
#define CHECK_BIT(a, bit)   (((a) & (1 << (bit))) >> (bit))

// Resets all bits in 'a' to 0.
#define RESET_ALL_BITS(a)     ((a) = 0)

// Retrieves the value of the specified bit in 'a' as either 0 or 1.
#define GET_BIT(a, bit) (((a) >> (bit)) & 1)



// Define macros for bitwise operations

// Macro for bitwise AND
#define BITWISE_AND(a, b)   ((a) & (b)) // Returns the bitwise AND of 'a' and 'b'

// Macro for bitwise OR
#define BITWISE_OR(a, b)    ((a) | (b)) // Returns the bitwise OR of 'a' and 'b'

// Macro for bitwise NOT
#define BITWISE_NOT(a)      (~(a))       // Returns the bitwise NOT of 'a' (inverts all bits)

// Macro for bitwise XOR
#define BITWISE_XOR(a, b)   ((a) ^ (b)) // Returns the bitwise XOR of 'a' and 'b'

// Macro for left bitwise shift
#define SHIFT_LEFT(a, n)    ((a) << (n)) // Shifts 'a' left by 'n' positions

// Macro for right bitwise shift
#define SHIFT_RIGHT(a, n)   ((a) >> (n)) // Shifts 'a' right by 'n' positions


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Macro to count the number of 1's in the binary representation of an unsigned 32-bit integer
#define COUNT_1s(num) ({ \
    int count = 0; \
    unsigned int _num = (num); \
    while (_num) { \
        count += _num & 1; \
        _num >>= 1; \
    } \
    count; \
})
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PRINT_BINARY(num) ({ \
    int _leading_zero = 1; \
    if ((num) == 0) { \
        printf("0"); \
    } else { \
        for (int i = 31; i >= 0; i--) { \
            if ((num) & (1 << i)) { \
                _leading_zero = 0; \
                printf("1"); \
            } else if (!_leading_zero) { \
                printf("0"); \
            } \
        } \
    } \
})
//////////////////////////////////////////////////////////////////////////////////////////////////////




#endif // MATH_H_INCLUDED
