Week starting 09/11/2026

# Monday 09/11/2026

# Tuesday 10/11/2026

playing the catch up game today.

## 1.6

uninitialised vars and undefined behaviour

uninitialised isn't the same as not initialised. it means that a variable wasn't assigned a value while being defining or later by assignment.

there is a small cost to initialisation. So default initialisation is slightly more performant.

compiled print-unitialised-int.cpp with release build flags (-02 -DNDEBUG) and the printed value change

hard to debug uninitialised variables mistakes. always init vars.

undefined behaviour - behaviour of code that is not well defined by the c++ language

c++ implementation - a specific compiler and associated std lib

c++ language standard allows the implementation to decide how some things in the language behave - implementation defined behaviour.

an example of implementation defined behaviour is the number of bytes an int takes.

unspecified behaviour - behaviour that is left up to the implementatio but that is not required to be documented.

implementation defined unspecified behaviour is bad and to be avoided.

## 1.7

keywords and naming identifiers

# Saturday 14/11/2026

The 10 hour lock in...

## 1.7 continued..

keywords - set of words reserved for the language.

special identifiers: override, final, import, module
    Have special meanings in some contexts

recall that the name of a variable (a region in memory) is called an identifier.

identifier naming rules:
    - cannot be a keyword
    - only made of letters, numbers and underscore
    - must begine with a letter or an underscore (basically can't start with a number)
    - cpp is case sensitive.

identifier naming best practices:

in general functions and vars start with lowercase letters with the body also lowercase.

names should make clear what the value they are holding means.

identifier length should generally be proportional to how specific and accessible the identifier is.

a comment alongside variable declaration can be useful to explain anything not obvious.

## 1.8

formatting and whitespace

some language elements must be separated with whitespace.
    mostly when two keywords or identifiers are placed consecutively so the compiler can tell them apart.

e.g: variable declatation must be white space separated
    `int x;`

`intx` would be interpreted as an identifier.

when white space is needed as a separator, the compiler doesn't care how much whitespace is used.

so.. all the below are valid:
```
int x;
int     y; 
    int
            z;
```

in some cases, newlines are used as a separator: single line comments are terminated by a newline.

preprocessor instructions like `#include <iostream>` need to be on different lines.

quotes separated by only whitespace will be concatenated:
```
std::cout << "Hello "
    "world"; // prints "Hello world" - crazy stuff.
```

good practice - when splitting a long line with operators, the operator should be placed at the beginning of the next line not the end:
```
std::cout << 4 + 9
    - 5 + 9
    * 3 - 2;
```

using whitespace to line up comments and values etc makes the code easier to read.


auto formatting shortcut: option + shift + F

## 1.9

literals and operators

literal - a fixed value directly inserted into the source code like some text of a number.

both literals and vars have a value and type.
unlike vars, the value of a literal can't be changed ie literals are constants.

literals can be printed directly, while with variables their value must be fetched from memory first.

literal's value is placed stright into the executable, and the executable can't be changed once it is made by compilation.
a variables value is placed in memory and the value in memory can be changed after compilation during run time.

This explains why a literal is constant while variables can change.

in cpp the output value of an operation is called a return value.

in cpp, assignment, insertion (<<), extraction (>>) and equality are operators along with the traditional ones.

there are some operators which keywords as opposed to being a symbol: new, delete, throw

operator arity -> the number of operands the operator takes as input.

most operators use operands to calculate a return value. Some operators don't produce a return value (like delete and throw).

some operators cause side effects (an observable effect beyond producing the return value is called a side effect)
    for example assignment, and << into std::cout.

some side effects like that in the case of assignment is actually useful and what we use
the = operator for. Useful only because the side effect is both beneficial and predictable.

in the case of = and << the return value is their left operand. This is done so that operators can be chained:
    x = y = 5 is evaluated as x = (y = 5)
    std::cout << "Hi " << "There" is evaluted as (std::cout << "Hi ") << "There"

This actually might be why I wasn't able to assign the return of a print statement
into a character array. The left operand in std::cout << ""; is the special character input
variable.
the error I got was "expression is not assignable"

## 1.10

expressions

Expression - a non-empty sequence of literals, variables, operators and function calls that calculates a value.

process of executing an expression (running it to get the result/return value) is called evaluation

in cpp the result of an expression is one of:
    - a value
    - an object or function
    - nothing (void)

literals evaluate to their own values
variables evaluate to the value stored in the region of mem the var points to
operators use operands to evaluate to some value
function calls evaluate to whatever value the function returns

expressions involving side effects are more tricky (assignment, insertion, ++x , x++,..)

expressions are always evaluated in statements.
expressions don't need semicolons but also can't be compiled by themselves.

can initialise variables with the result value of expression as long as the type is right:
```
// notice the semicolon is not after the expression. Its placed at the end of the inialisation statement.
int x {2 - 1};
```

form: `type identifier {expression};`

expressions can't be executed by themself. They must be be part of a statement.

expression statement - statement that consists of form `[expression];`

so the expression `x = 5` can be made into an expression statement `x = 5;`
which compiles.

any result generated by the expression in an expression statement it discarded.

an expression with no effect is useless because it doesn't make any impact to the rest of the program.

subexpression - an expression used as an operand:
    sub expressions of x = 4 + 5 are (4 + 5) and x
    sub expressions of 4 + 5 are 4 and 5

full expression - an expression which that is not a subexpression. (so a top level expression)

compound expression - expression that uses 2 or more operators.

## 1.11

making first program!!

optimise your code for maintainability!

## 2.1

functions

functions are a collection of sattements that execute sequentially.

reusable.

enables us to make code more modular.

user-defined functions - ones you write yourself

function calls also called invocations.

user-defined function form:

```
returnType functionName() // known as the function header - tells the compiler the function exists
{
    functionBody
}
```

nested functions - a function whose definition is in another function.

nested functions are not supported in c++

## 2.2

function return values

return by value - returning a copied value back to the caller

how main() works:
    When program is executed, os makes a function call to main().
    statements in main() are executed sequentially.
    main() returns an int and program terminates.

rules for main():
    main() has to return an int
    explicit function calls to main() are not allowed (So are implicit calls allowed..?)

C allows for main() to be called explicitly but not C++

The return value from main() is called:
    status code, exit code, return code
    ^ used to say whether the program ran successfully or not.

0 means the program ran normally.

c++ standard defines 3 status codes
    0
    EXIT_SUCCESS
    EXIT_FAILURE

EXIT_FAILURE AND EXIT_SUCCESS are preprocessor macros defined in `<cstlib>`

status code is returned to the OS.
The OS typically sends the status code to whichever program launched the program returning the status code,
so it knows if the program it launched was successful or not.

If a function that is meant to return a value doesn't return a value it produces **undefined behaviour**.

best practice to ensure non-void functions return a value in all cases.

main() implicitly returns 0 if no return is provided.

functions can only return a single value.

document functions on what the return value means

## 2.3

void functions

used for functions that don't return a value.

best practice to have no return statement at the end of a void function.
Though it might be useful to return out of a loop under a certain case.

can't call a void function in a context that needs a value.

returning from a void function causes compilation error.

## 2.4

function params and args

function params - variables defined in the function header initialised with value provided by caller.

```
void exampleFunction(int x, int y, int z) // x,y,z are the params and can be used like any other var in the function.
{}
```

argument - value passed from caller to called function

`exampleFunction(1,2,3); // 1,2,3 are the args`

params of the called function are made as variables.
The values of the args are copied into the matching parameter via copy initialisation.
This is called **pass by value**.

value parameters - function params that use pass by value

The args passed to a function can be any valid expression.
args are just initialisers for the parameters and initialisers can be any valid expression.

unreferenced parameters - params that are not used in the body of the function

in function definition, the name of function parameter is optional.
so if a function parameter needs to exist but its not used in the body
the name can be omitted.

unnamed parameter - parameter without a name.

```
void doStuff(int) // unnamed parameter
{}
```

unnamed parameters are okay so the compiler won't throw warnings, but
unereferenced params will lead to warnings.

q4:
```
doubleNumber(int num)
{
    return 2 * num;
}
```

## 2.5

local scope

local variables - variables defined in the body of a function.

function parameters are considered as local variables also.

function params are created and initialised when the function is entered.
vars in the function body are created and initialised at the point of definition

local variables are destroyed in opposite order to creation at the end of the function.

lifetime is a runtime property.
object lifetime - the time between its creation and destruction

using an object after it has been destroyed causes undefined behaviour.

at some point after destruction, memory used by the object is deallocated.

identifier's scope defines where the identifier can be seen and used within the code.

in scope vs out of scope.

scope is a compile time property. Using out of scope identifiers causes compilation errors.

local scope is also called block scope.
local variable's identifier has local scope.

caller's local vars aren't in scope inside a called function.

local vars lifetime ends when it goes out of scope.

best practice to define local variables close to their first use.

temporary object - unnamed object that holds a value that is needed for a short time

return by value returns a temporary object, which holds a copy of the the return value, to the caller.

temporary objects are made by the compiler when needed

temporary objects have no scope, and are destroyed at the end of the full expression where they
were created. so destroyed before next statement executes.

in modern c++, compiler often skips creating temporary objects, just initialising the variable directly
with the returned value.

## 2.6

## 2.7

forward declarations and definitions

compiler compiles code sequentially.

using a function before it is defined in code leads to compilation error.

if functions depend on each other cyclically then there is no way to order the functions
that will satisfy the compiler.

forward declaration - lets us tell compiler about an identifier before defining it.

example function declaration (also called function prototype):
`int add(int x, int y);`

it includes the return type, name, parameters (parameter types are required but names are not) and a semicolon.
This is therefore also a valid function prototype:
`int add(int, int);`

best practice to specify param names in function declarations.

function declaration is essentially just the function header with a semicolon at the end.

this naturally leads to the idea of a header file with function protypes.

if the function is never defined after forward declaration and the function is called in the
program then the program will compile but the linker will not be able to resolve the function call.

forward declarations can be used with any identifier in c++.

declaration vs definition:
declaration - say that an identifier exists and what its type is.. for example a function prototype
definition - the actual implementation (for functions and types) or instantiation (for variables) of the identifier.

pure declarations - declarations that aren't instantiations. (function declarations are an example of pure declarations)

`int x` - this is both a declaration and a definition - I believe its considered a definition
because it is initialised with some garbage value by default.

declaration is often used to mean pure declaration.

one definition rule:
    - within a file in a given scope, functions, variables, types and templates can only have one definition.
    - within a program in a given scope, functions and variables can only have one definition.

not sure I get these completely yet.. covered more thoroughly later.

function overloading is supported.

the function parameter names in a forward function declaration are optional as mentioned earlier.
If parameter names are specified, the compiler ignores them.
So you can actually mess up the function declaration's parameter order
without realising.

compilation error - if we can't find an appropriate declaration for an identifier we use.
linker error - we have a declaration to an identifier we are trying to use but we can't find the definition
               aka the implentation of this identifier.

## 2.8

main.cpp:
```
#include <iostream>

int getInteger();

int main()
{
    int x {getInteger()};
    int y {getInteger()};

    std::cout << x << " + " << y << " is " << x + y << '\n';

    return 0;
}
```

input.cpp:
```
#include <iostream>


int getInteger()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;
    return x;
}
```

## 2.9

naming collisions and namespaces

naming collision/conflict - two identical identifiers that the compiler or linker can't tell apart

colliding identifiers in the same file results in a compiler error
colliding identifiers in different files of the same program result in linker error

scope region - area where declared identifiers are distinct from names in other scopes.

body of function is an example of a scope region.

namespaces - provide another type of scope region.

names declared in a namespace are isolated from names declared in other namespaces.

namespaces can only contain declarations and definitions.

global namespace - any name not defined in a class, function or namespace is part of the global namespace

having executable statements like `x = 5;` in any namespace including the global namespace causes
compilation error.

avoid defining variables in the global namespace.

std namespace: namespace for the c++ standard library.

in std::cout the character our identifier is cout and std is just
the name of the standard lib namespace.

explicit namespace qualifier

the `::` symbol is the **scope resolution operator**.
identifier left of `::` is the namespace and right of `::` is the name inside the
namespace.

`::<name>` just uses the global namespace

`std::cout` means the `cout` that is declared in namespace `std`

qualified name - when an identifier includes a namespace prefix

using directive - allows us to access names in a namespace without the namespace prefix
e.g:
```
using namespace std; // the using directive

int main()
{
    cout << "hi"; // don't need to use std:: anymore
}
```

making use of a using directive is bad practice as it makes it much easier for identifiers to collide.

curly braces used to show scope regions.

## 2.10

preprocessor

one of the directives the preprocessor processes is `#include`'s

The output of the proprocessor given source code is called a translation unit.
The compiler compiles the translation unit.

preprocessing, compiling, linking pipeline is called translation

preprocessor directives - start with a # and end with a newline

#include - preprocessor replaces the #include directive with the contents of the included file.

recursive preprocessing because the included file might have its own #include directives.

#define directive can be used to create macros

macro - rule on how input text is converted into output text

types of macros:
    * function like macros - unsafe, can do anything that can be done by a normal function.
    * object like macros - 


