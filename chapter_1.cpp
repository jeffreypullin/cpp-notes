#include <iostream>
#include <cmath> 
// This toggles debug mode. It is better to pass the compilation flag:
// -DNDEBUG. If the flag is engaged all the assertion will be removed. 
// No debug is the same as release mode. 
//#define NDEBUG
#include <cassert> 
#include <fstream>
#include <memory>
#include <vector>

void inc_value(int x);
void inc_reference(int& x);
int divide(int a, int b);
double divide(double a, double b);
double& square_ref(double d);

// This the more verbose option to facilitate the example in 1.5.5
int main(int argc, char* argv[]) {
    
    // 1.1 Our first program 
    std::cout << "The answer to the Ultimate Question of Life, \n" 
	      << "the Universe and Everything is:"
	      << std::endl << 6 * 7 << std::endl;

    // 1.2 Variables
    int i1 = 2;                                                            
    int i2, i3 = 5; 
    float pi = 3.14159; 
    // Needed later. 
    //double x = -1.5e6;    // -1500000       
    //double y = -1.5e-6;   // -0.0000015
    char c1 = 'a', c2 = 35;   
    // From C++ 11
    auto i4 = i3 + 7;                                                               
    
    // 1.2.1 Constants
    const int ci1 = 2;
    //const int ci2; Error: must provide a value. 
    const float cpi = 3.14159;
    const char cc = 'a';
    const bool cmp = ci1 < pi;

    // 1.2.2 Literals
    // 2 : int
    // 2l : long
    // 2u : unsigned
    // 2ul : unsigned long
    // 2.0 : double
    // 2.0f : float
    // 2.0l : long double
    
    // 1.2.3 Non-narrowing initialization
    // This will have reduced precision on a 32 bit system - it 
    // will be `Narrowed`. (To emulate a 32 bit system compile with -m32).
    long l2 = 1234567890123;
    // To prevent this use Uniform - Braced - Initialization. 
    long l3 = {1234567890123};

    //int i5 = 3.14; Compiles (with warning) despite narrowing. 
    //int i6 = {3.14}; Narrowing error: fractional part lost.

    // 1.2.4 Scopes
    // Omitted.
   
    // 1.3 Operators
    // 1.3.1 Arithmetic Operators
    int i = 3, j = 4;
    int k = ++i + 4; // i is 4, k is 8. ++i is prefered. 
    int l = j++ + 4; // j is 4, l is 7.

    // pi has already been defined. 
    const float r1 = 3.5, r2 = 7.3;

    float area1 = pi * r1 * r1;

    std::cout << "A circle of radius " << r1 << " has area "
              << area1 << "." << std::endl;

    std::cout << "The average of " << r1 << " and " << r2 << " is " 
              << (r1 + r2) / 2 << "." << std::endl;
    
    // Note that if the arguments of a binary operator are different 
    // then the types will be `automatically` coerced. 
    
    // 1.3.2 Boolean operators
    // !, >, >=, <, <=, ==, !=, &&, ||
    // Note that we cannot chain operators. 

    // 1.3.3 Bitwise operators
    // x << y : Shifts the bits of x to the left by y positions. 
    // x >> y : Moves x's bits y times to the right.
    // x & y : Bitwise AND.
    // x | y : Bitwise inclusive OR.
    // x ^ y : Bitwise exclusive OR. 
    // ~x : Ones complement. 
    // Useful for hashing and not much else. 

    // 1.3.4 Assignment
    // object = expr
    // x += y -> x = x + y;
    // x *= y -> x = x * y;
    // etc. (See Table 1.5) Do not prefer brevity over clarity.
    
    // 1.3.5 Program flow
    // 3 + 4, 7 * 9.3 -> 65.1 (First expression ignored).

    // 1.3.6 Memory Handling 
    // new and delete allocate and deallocate memory. 
    
    // 1.3.7 Access Operators
    // See later - pointers.
    
    // 1.3.8 Type Handling 
    // See later - templates.
    
    // 1.3.9 Error Handling
    // The throw operator is used indicate an exception. 

    // 1.3.10 Overloading
    // You can overload pretty much everthing...

    // 1.3.11 Operator Precedence
    // Table 1-8. Boring!

    // 1.3.12 Avoid Side Effects!
    
    // 1.4 Expressions and Statements

    // 1.4.1 Expressions
    
    // 1.4.2 Statements
    // Anything followed by ; is a statement. 

    // 1.4.3 Branching
    
    // 1.4.3.1 if-statement 
    int weight = 120;
    if (weight > 100) {
        std::cout << "This is pretty heavy\n";
    } else { 
        std::cout << "This isn't so heavy\n";
    } 
    // The else clause can be ommitted. 
    // The branches are scopes. 

    // 1.4.3.2 Conditional Expression
    // The result of:
    // condition ? result_for_true : result_for_false
    // is the second expression when condition is true and the third 
    // expression otherwise.
    // Compare:
    // min = x <= y ? x : y;
    //
    // and
    //
    // if (x <= y) {
    //     min = x;
    // } else {
    //     min = y;
    // } 
    
    // 1.4.3.3 switch
    int op_code = 1;
    int z, x = 2, y = 3;
    switch(op_code) {
        case 0: z = x + y; break;
        case 1: z = x - y; std::cout << "Compute difference\n"; break;
        case 2: 
        case 3: z = x * y; break;
        default: z = x / y; 
    } 
    std::cout << z << "\n";
    // Note that the cases will fall through if we do not explicitly
    // `break` them. 
    
    // 1.4.4 Loops

    // 1.4.4.1 while and do-while loops
    // Collatz series:
    int n = 23;
    std::cout << "The collatz sequence of " << n << " is:\n"; 
    while (n != 1) {
        std::cout << n << '\n';
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        } 
    } 
    // Print the final element of the seqeunce (always 1). 
    std::cout << 1 << '\n';

    // There is also a do-while loop but why would you ever want to use it?
    
    // 1.4.4.2 for-loop
    
    double v[3], w[] = {2.0, 4.0, 6.0}, u[] = {6.0, 5.0, 4.0};
    // Note the prefix ++ and the 0 based indexing. 
    // Postfix ++ will cause an uneccesary copy for user types. 
    // use < not <= to get the 0 based indexing correct. 
    for (int i; i < 3; ++i) {
        v[i] = w[i] + u[i];
    } 

    for (int i; i < 3; ++i) {
        std::cout << "v[" << i << "] = " << v[i] << '\n'; 
    } 

    // The Taylor series of the exponential function. 
    // x_ as x defined above. 
    double x_ = 2.0, xn = 1.0, exp_x = 1.0;
    unsigned long fac = 1;
    for (i = 1; i <= 10; ++i) {
        xn = xn * x_;
        fac = fac * i;
        exp_x = exp_x + xn / fac;
        std::cout << "e^x is " << exp_x << '\n';
    } 

    // 1.4.4.3 Range based for-loops
    std::cout << "Primes: \n";
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (int i : primes) {
        std::cout << i << '\n';
    } 
    
    // 1.4.4.4 Loop Control
    // break and continue. 
    
    // 1.4.5 goto
    // JUST DON'T.

    // 1.5 Functions
    
    // 1.5.1 Arguments
    
    int g = 4, h = 4;
    // Call for side effect - yuck!
    inc_value(g);
    // Note here that we don't use & or otherwise change the type of h.
    inc_reference(h);
    std::cout << "Pass by value: " << g << '\n';
    std::cout << "Pass by reference: " << h << '\n';

    // Can also declare things to be const. 
    
    // 1.5.1.3 Defaults
    // Functions can have default parameters. i.e.
    // double root(double x, int degree = 2) {} 
    // Only at the of the argument list. 
    // Useful when an api changes (generalises).

    // 1.5.2 Returning Results
    
    // 1.5.2.1 Returning large amounts of data
    // Tricky - see later.
    
    // 1.5.2.2 Returning Nothing
    // Use void. 
    // This allows no argument return statements. 

    // 1.5.3 Inlining
    // Calling functions is expensive. 
    // We can avoid it by actally inserting the source of the function 
    // into the location of it's call - this is called inlining. 
    // The compiler may choose to inline a function - it can be forced to 
    // by marking a function as inline i.e.
    // inline double square(int x) { x * x }

    // 1.5.4 Overloading
    // Functions can share the same name as long as there parameter declerations 
    // are sufficiently different. 
    int nn = 2, mm = 1;
    double xx = 2.0, yy = 1.0;
    std::cout << divide(nn, mm) << '\n';
    std::cout << divide(xx, yy) << '\n';
    //divide(nn, yy); Ambiguous

    // The signature of function consists of: 
    // * The function name
    // * The number of arguments; called 'arity'
    // * The types of the argument (in their respective order)

    // Overloads must differ by more than just return type. 
    // Reference symbols or other symbols will change type or arguments. 
    // Mixing reference value overloading gets messy - example in text.
 
    // 1.5.5 main Function
    // Two signatures allowed: 
    // int main() {}
    // or 
    // int main(int argc, char* argv[]) 
    // 
    // The latter is equivalent to: 
    // int main(int argc, char** argv) 
    //
    // argv contains the list of arguments and argc containts the 
    // number of arguments. 
    //
    // Tried a range based for loop here but it didn't like the char**
    // Interstingly this loop is removed if we compile in -O3 
    for (int i; i < argc; ++i) {
        std::cout << argv[i] << '\n';
    } 
   
    // 1.6 Error Handling
    
    // 1.6.1 Assertions
    int result = -2;
    //assert(result > 0);

    // 1.6.2 Exceptions

    // Try to accomplish a task and see what happens. i.e. file io, numerical 
    // issues. 
    
    // 1.6.2.1 Motivation
    // Don't return error codes! 
    
    // 1.6.2.2 Throwing
    // I've rewritten the examples from the text from io to numerics
    // because the io code seems to be out of date. 
    
    int test1 = -3; 
    if (test1 < 0){
        //throw "Test less than 0!";
    }
    // Program fails with 'terminating with uncaught expception etc. 
   
    // We need to handle the thrown exception or the program will 
    // crash. 
    // We can throw anyhthing as an exception includig a struct which 
    // could contain information about the error. 
    
    // 1.6.2.3 Catching
    // To react to an expression we have to catch it. 
    // Should try to catch expression by reference. 
    // Can catch different types of errors
    // Catching requires you to know the error codes.  
   
    // In real life these would have information about the error etc.
    struct less_than_zero {};
    struct equal_to_zero {};

    int test2 = -4;
    try {
        if (test2 < 0) {
            // Are we initializing the struct? 
            throw less_than_zero{};
        } else if (test2 == 0) {
            throw equal_to_zero{}; 
        } else if (test2 == 4) {
            throw "I don't like 4";
        } 
    } catch (less_than_zero& e) {
        std::cout << "Input was less than 0!\n";
    } catch (equal_to_zero& e) {
        std::cout << "Input was equal to 0!\n";
    // A catch(...) statement will catch all other exceptions. 
    } catch (...) {
        std::cout << "Unkown error occured\n";
    }

    // We can rethrow exceptions from a catch statement.
    // We can ignore an exception by making a catch block empty ({}). 
    
    // 1.6.2.4 Who throws?
    // We can annotate that a function does *not* throw using noexcept:
    // double square_root(double x) noexcept {...}

    // 1.6.3 Static Assertions
    // static_assert can be used to make assertions about things known at 
    // compile time.

    // 1.7 IO
    // C++ uses an abstraction called 'streams'. A stream in an object where
    // a program can either insert characters or extract them. Streams
    // are provided in header <iostream>
    
    // 1.7.1 Standard Output
    // By default written to the screen. Accessed using cout. 
    // endl or \n can be used to produce a newline character. 
    // endl flushes the buffer \n does not. 
    // logical or bitwise operations must be grouped in parentheses when
    // using <<. 

    // 1.7.2 Standard Input
    // Use std::cin and >> 
    //int age;
    //std::cin >> age;
    //std::cout << "The entered age was: " << age << '\n';
    // Can chain >>
    
    // 1.7.3 Input/Ouput with Files
    // C++ provides the following classes to perform io from files:
    // * ofstream - write to files
    // * ifstream - read from files
    // * fstream - both read and write from/to files
        
    bool do_io = false;
    // The enclosed code works - I just prefer not to clutter up my 
    // directory. 
    if (do_io) {
        std::ofstream square_file;
        square_file.open("squares.txt");
        for (int i = 0; i < 10; ++i) {
            square_file << i << "^2 = " << i * i << std::endl;
        } 
        square_file.close();
    }

    // Alternatively:
    // std::ofstream square_file("squares.txt");
    // Note: that the file will be closed when it goes out of scope 
    // thanks to RAII (discussed later) c.w. rust borrow checker!
    // for loop as above
   
    // Generic Stream Concept 
    // You can implment streams for other types of IO using stringstream

    // 1.7.5 Formatting
    // We can format output using the IO manipulators found in <iomanip>. We can:
    // * Increase precision - setprecision()
    // * Set the width of the output - setw() (i.e. when outputting to a table)
    // * Request alignment - left/right
    // * Set the fill - setfill()
    // * Use scientific notation: scientific
    // * Represent intergers in octal/hexidecimal bases
    // * Represent boolean values as true/false - boolalpha.
    // See text for reference. 

    // 1.7.6 Dealing with IO errors
    // I/O is C++ is not safe let alone idiot proof. 
    // i.e. opening non-existent files does not fail. 
    // Can enable exceptions for each stream at runtime.
    // Summary I/O is hard and buggy. 

    // 1.8. Arrays, Pointers and References
    
    // 1.8.1 Arrays
    // Intrinsic array support in C++ is somewhat problematic. 
    int x_array[10];
    // x_array is an array of int with 3 elements. 
    // Size must be known at constant and known at compile time. 
    // x[i] is a reference to the ith element of x. 
    int y_array[] = {1, 2, 3};
    for (i = 0; i < 3; ++i) {
        std::cout << x_array[i] - 3 * y_array[i] << '\n';
    }

    // We can declare array of higher dimensions:
    float A[3][3];
    int q[3][2][4];

    // C++ does not provide linear algebra operations on arrays. 
    // We can write functions to do these operations but we need to 
    // pass around array size and it's all very painful - use libraries!

    // 1.8.2 Pointers
    // A pointer is a variable which contains a memory address. 
    // This can be the address of another variable or dynamcially 
    // allocated memory. 

    int* e = new int[10];

    // This allocates an array of 10 int. The size can be chosen at runtime. 
    // This is the same as malloc in C. 
    // We need to store the size of the array to prevent out-of-bounds errors. 

    // It is the *programmers* responsibility to release the memory. 
    delete[] e;

    // Pointers and arrays are interchangeable.

    int* ip = new int;
    delete ip;

    // The operator & takes an variable and return it's address. 
    // The opposite operator * which takes an address and returns an object. 
    // This is called de-referencing.
    
    int p = 2;
    int* p_p = &p;
    std::cout << p_p << '\n';
    std::cout << *p_p << '\n';
    
    // 'NULL' pointers will contain random bits. 
    // In C++11 or later use nullptr to refer to a NULL pointer. 
    // Prefer it over both 0 and NULL

    int* ip2 = nullptr;
    int* ip3{}; // Same as above.
    std::cout << ip2 << '\n';
    
    // The big problem with pointers is Memory Leaks - memory is allocated
    // but never freed.

    // Strategies to minimise pointer problems are:
    //
    // * Use standard containers i.e. std::vector for dynamic arrays. 
    // * Encapsulate
    //     Manage memory for on the level of objects our programs act on. 
    //     This principle is called Resource Allocation Is Initialization
    //     (RAII).  See section 2.4.2.1
    // * Smart pointers

    // 1.8.3 Smart Pointers
    // There are three smart pointers in C++11:
    //
    // * unique_ptr
    // * shared_ptr
    // * weak_ptr
    //
    // (All defined in header <memory>)
    
    std::unique_ptr<double> dp{new double};
    //std::cout << dp << '\n';
    *dp = 7;

    double a_double;
    // std::unique_ptr<double> {&a_double}; Error (crash) can't use references. 

    // Use get to refer to pointers data in a raw pointer
    double* raw_dp = dp.get();
    std::cout << raw_dp << '\n';
    
    // Unique pointers cannot be assigned. 
    //std::unique_ptr<double> dp2{dp}; Error: call to deleted copy constructor...
    //dp2 = dp; Error: constructor is implicitly deleted...

    // It can only be moved:
    std::unique_ptr<double> dp3{move(dp)};
    std::unique_ptr<double> dp4;
    dp4 = move(dp);
    
    // move transfers the data instead of duplicating it like copy does
    // ownership of data is passed i.e. when dp2 = dp then dp is nullptr
    // Memory ownership is also passed when unique_ptr is returned from a 
    // function. 
    // Note: we will discuss move semantics more later
    // Note: can use array access syntax when the unique_ptr holds an array. 
    
    // 1.8.3.2 Shared Pointer
    // A shared pointer managed memory that is used by multiple parties. 
    // The memory is automatically relased when all of the pointers holding 
    // memory are dropped. 

    std::shared_ptr<double> sh_p1{new double};
    std::cout << sh_p1.use_count() << '\n';
    std::shared_ptr<double> sh_p2 = sh_p1;
    std::cout << sh_p1.use_count() << '\n';
    
    // Can use make_shared -> puts the memory management and payload in the 
    // same memory -> more efficeint. 
    auto sh_p3 = std::make_shared<double>();
    
    // 1.8.3.3 Weak Pointer
    // Used to break memory cycles - look up when needed. 
    
    // 1.8.4 References
    int var = 4;
    int& ref = var;
    var = 5;
    std::cout << var << '\n';
    // The variable `ref` refers to variable `var`. They will *always* have 
    // the same value. 
    
    // 1.8.5 Comparison between References and Pointers
    // Main advantages of pointers vs references: dynamic memory management 
    // and address calculations. References much safer (but not fail safe).
    // From SO:
    // A pointer can be reassinged a reference cannot. 
    // Reference shares the memory address - reference another name for the 
    // same variable. 
    // Pointers can be assigned to `nullptr` references cannot. 
    // Pointers can be used to iterate over arrays i.e. *p++
    // Pointers need to be dereferenced with * to acess the memory location 
    // associated with it (i.e. to use it) references do not need to be. 
    // Note that you can't reassign a reference - they alias a varaible. 

    // 1.8.6 Do Not Refer to Outdated Data!
    double passed_value = 3;
    // Function local variable are only valid inside the function scope
    //double& returned_ref = square_ref(3); Warning reference to stack memory
    // This also applies to pointers. 

    // 1.8.7 Containers for Arrays
    // Alternatives to C style arrays

    // 1.8.7.1 Standard Vector
    std::vector<double> array_x(3);
    array_x[0] = 1; array_x[1] = 2; array_x[2] = 3;
    // The size of the vector does not need to be known at compile time.
    // Vectors can be resized during their lifetime.
    std::vector<double> array_y{1, 2, 3};
    std::cout << "The size of the vector is: " << array_y.size() << '\n'; 
    // Vectors are copyable and can be known at compile time. 

    // 1.8.7.2 valarray
    // Variable sized arrays - not really used. 

    // 1.9 Structuring Software Projects
    
    // 1.9.1 Comments
    // The primary purpose of a comment is to describe in plain
    // langage what is not obvious to everybody in the program sources. 
    // Make your programs more readable. 
    // // and /* ... */ (block comments)

    // 1.9.2 Preprocesser Directives
    
    // 1.9.2.1 Macros
    // "Almost every macro demonstrates a flaw in the programming language
    // in the program, or the programmer" - Bjarne Stroutrup

    // 1.9.2.2 Inclusion 
    // Use #include to include header files.
    // Can use paths and may have to use include guards (consult 
    // section when neccesary) 
    
    // 1.9.2.3 Conditional Compilation
    // Only compile certain parts of the program when on the right 
    // platform etc. Use as needed. 
    
    // Apparently it is 'standard compliant' to omit the return statment. 
    // return 0;
}

// 1.5.1.1 Call by Value
void inc_value(int x) {
    x++;
} 

// 1.5.1.2 Call be Reference
// This is true pass be reference - not just passing pointers as in C. 
void inc_reference(int& x) {
    x++;
}

// 1.5.4 (Examples)
int divide (int a, int b) {
    return a / b;
} 

double divide (double a, double b) {
    return std::floor(a / b);
} 

// Warning: reference to stack memory associated with local variable
// 's' returned. 
//double& square_ref(double d) {
//    double s = d * d;
//    return s;
//}


