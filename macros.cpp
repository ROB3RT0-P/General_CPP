// RJP - 27/09/2023 - Useful C++ Macros.

#include <iostream>

// 1. Preprocessor conditionals
#define DEBUG

#ifdef DEBUG
#define LOG(message) std::cout << message << std::endl
#else
#define LOG(message)
#endif

// 2. Macros for min and max
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 3. Macros for looping
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FOREACH(element, container) for (auto& element : container)

// 4. Macro for array size
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// 5. Stringification
#define STRINGIFY(x) #x

// 6. Concatenation
#define CONCATENATE(a, b) a ## b

// 7. Debugging macros
#define ASSERT(condition) if (!(condition)) { std::cerr << "Assertion failed: " #condition << std::endl; }

// 8. NULL pointer
#define NULL_PTR nullptr

// 9. File and line info
#define FILE_LINE_INFO __FILE__ << ":" << __LINE__

// 10. Include guards
#ifndef MY_HEADER_H
#define MY_HEADER_H

// Your header content here

#endif // MY_HEADER_H

// 11. Compiler-specific macros
#ifdef __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

// 12. Macro for unused variables
#define UNUSED(x) ((void)(x))

// 13. Macro for custom debug printing
#define DEBUG_PRINT(var) std::cout << #var << " = " << var << std::endl

// 14. Macro for suppressing unused variable warnings
#define UNUSED_VARIABLE(var) ((void)var)

// 15. Include system header with C linkage
EXTERN_C_BEGIN
#include <cstdlib>
EXTERN_C_END

// 16. Token pasting
#define TOKEN_PASTE(x, y) x ## y

// 17. Conditional expression
#define CONDITIONAL(condition, true_val, false_val) ((condition) ? (true_val) : (false_val))

// 18. Bit manipulation
#define SET_BIT(x, pos) ((x) |= (1U << (pos)))
#define CLEAR_BIT(x, pos) ((x) &= ~(1U << (pos)))
#define TOGGLE_BIT(x, pos) ((x) ^= (1U << (pos)))

// 19. Macro for function attributes
#define UNUSED_FUNCTION __attribute__((unused))

// 20. Macro for function inlining
#define INLINE_FUNCTION inline

// 21. String concatenation
#define CONCAT_STR( str1 , str2 ) a ## b

// 22. String length
#define STRING_LENGTH(str) sizeof(str) - 1

// 23. Macro for defining constants
#define PI 3.14159265359

// 24. Helper macro for rounding up division
#define CEIL_DIVIDE(a, b) (((a) + (b) - 1) / (b))

// 25. Macro for custom error handling
#define ERROR(msg) do { std::cerr << "Error: " << msg << std::endl; exit(EXIT_FAILURE); } while(0)

int main() 
{
    int a = 5, b = 10;
    LOG("This is a debug message.");
    std::cout << "Minimum: " << MIN(a, b) << std::endl;
    FOR(i, 5) 
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Array size: " << ARRAY_SIZE("Hello") << std::endl;
    std::cout << "Stringified: " << STRINGIFY(test) << std::endl;
    int CONCATENATE(var, 1) = 42;
    std::cout << "Concatenated variable: " << var1 << std::endl;
    ASSERT(a < b);
    DEBUG_PRINT(a);
    SET_BIT(a, 2);
    std::cout << "After setting bit 2: " << a << std::endl;

    // 21. String concatenation
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string concatenated = CONCAT_STR(str1, str2);
    std::cout << "Concatenated string: " << concatenated << std::endl;

    // 22. String length
    const char* myString = "Hello, world!";
    std::cout << "String length: " << STRING_LENGTH(myString) << std::endl;

    // 23. Constants
    double circleArea = PI * 5 * 5;
    std::cout << "Circle area: " << circleArea << std::endl;

    // 24. Rounding up division
    int result = CEIL_DIVIDE(10, 3);
    std::cout << "Ceiling division result: " << result << std::endl;

    // 25. Custom error handling
    ERROR("Something went wrong!");

    return 0;
}