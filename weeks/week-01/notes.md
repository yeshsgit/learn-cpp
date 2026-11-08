Week starting 02/11/2026

# Monday 02/11/2026

# Tuesday 03/11/2026

## 0.4

gives programmer a lot of freedom - can make lots of mistakes.

compile, then link object files.

code -compile-> assembly -assembler-> object code -linker-> executable

primary source file naming convention is main.cpp

## 0.5

The linker takes many things as input such as object files and std lib and generates executable.

std lib usually linked by default.

building -> going rom source code to executable

## 0.6

## 0.7

## 0.8

# Wednesday 04/11/2026

## 0.9

build configurations - project settings affecting how the project is built

debug and release configs.

`-ggdb` for debug builds

`-O0` disables optimisation (default)

`-02`, `-03` optimise

## 0.10

compiler extensions

best practice to disable compiler extensions.
compiler extensions let you write c++ code which is not standard in order to support older versions of the language. This means that all compilers CANNOT compile the code.

`-pedantic-errors` disables compiler extensions


cmd to compile with debugging enabled and with compiler extensions disabled:
`g++ hello-world.cpp -o hello-world.o -ggdb -pedantic-errors`

## 0.11

warning and error levels

there is no c++ standard for diagnostic messsages

some conventions:

diagnostic error - halted compilation (issue could not be ignored)

diagnostic warning - did not halt compilation (issue ignored)

sometimes compilers may not agree on whether an issue should lead to a warning or an error.

good practice to use more sensitive warning levels.

compilation flags to add to increase warning levels:

-Wall
-Weffc++
-Wextra
-Wconversion
-Wsign-conversion

good practice to treat warnings like errors ie tell compiler to halt on warnings.

use -Werror to treat warnings like errors

## 0.12

choosing a language standard

in professional dev, common to use a standard 1 or 2 versions older - likely more stable and better understood.

for personal proj can j use latest stable one

-std=c++23

## 0.13

what language standard is being used by compiler?

yippee it works
stdout:
Your compiler is using C++23 (language standard code 202302L)

# Thursday 05/11/2026

## 1.1

statement ~ basc a sentence

end statement with semicolon ";"

all c++ programs must have a function called main

analysing hello world:

`#include <iostream>` is for the preprocessor.
tells it to use the iostream library

then the main function is defined (required for all c++ programs) with int return type.
w/o main function linking fails.

0 indicates successful completion to os.

## 1.2

comments

//

/*
*/

what does code do?

how does it do it?

statement level - describe why not what.
    a statement that is too complex is bad

why was a certain implementation chosen?

should be understandable to someone who doesn't know what the code does.

## 1.3

data - information that can be moved processed or stored

'' - values in single quotes are character values
"" - values in double quotes are text values

data values specified directly in source code are called literals

literals are read-only. can't be modified, and so can't be used to store data.

object - represents region in memory that can hold a value

in c++ access memory through objects, using direct access is not recommended.

variable - an object with a name (identifier)

# Sunday 08/11/2026

objects are a layer of abstraction above memory - lets us use the compiler to figure out where objects are stored so we can just interact with objects directly

typically "object" refers to a variable or function but in c++ the term object excludes functions.

definition is a type of declaration statement.

definition statement tells compiler we want to use a variable.

```
// defining an integer variable x:
int x;
```

if we use identifier x later in code, the compiler knows we are referring to this variable.

compiler takes care of:
* how much memory the object needs
* where in memory the object will be placed (RAM or CPU register)
* the address in memory
* the object's life cycle (creation, destruction,..)

allocation - reserving storage for an object

object can only be created after allocation

objects are essentially just regions in memory that store data values. Objects have datatypes so we know how to interpret the stored value.

in c++ the object type must be known at compile time.

defining multiple vars in the same line:
`int a,b;`
^ a and b have the same type: int

best practice to define one variable per line.

## 1.4

variable assignment and initialisation

assignment - giving a variable a value using = operator

= is called the assignment operator

copy assignment - copy value on the right hand side of = to the variable on the left hand side of =

e.g:
int x; // define x
x = 5; // copy assignment

initialisation - specifying initial value for object while defining it. e.g:

`int x {5}; // defines x and initialises it with value 5`

5 common types of initialisation;

```
int a;          // default initialisation

// traditional methods
int b = 5;      // copy initialisation
int c (6);      // direct initialisation

// modern methods (preferred)
int d { 7 };    // direct list initialisation
int e {};       // value initialisation
```

copy, direct and direct list initialisation behave the same in most cases

default init - leaves variable with garbage value

copy init - from c. used to be less efficient than other initialisation methods for some complex types.

direct init - was meant to be more efficient than copy init.

list init - modern. 2 forms: direct list init and copy list init. introduced to provide a syntax that works in all cases and behave consistently.

list init disallows narrowing conversions.
    storing disallowed value like decimal in an int variable produces a diagnostic

`int x {1.5}; // throws compile error`

the compiler won't convert 1.5 to a value the integer variable x can hold as the fractional part of the 1.5 would be lost (a narrowing conversion)

both of the below cases compile and init x and y to 1.
```
int x = 1.5; // copy init to 1
int y (1.5); // direct init to 1
```

value init - {}. in most cases initialises variable to zero. in these cases its called zero-initialisation.

`int x {}; // initialises x to 0`

value init for classes uses default values.

**list init is the preferred form of initialisation in modern c++.**

best practice to initialise variables on creation.

instantation - means allocation + initialisation

every var needs its own initialiser:
```
int a, b = 5;       // a gets garbage value, b gets 5
int a = 5, b = 5;   // a and b both get 5.
```

^ easy to mix up so another reason why it's better to define and init one variable per line.

`[[maybe_unused]]` attribute introduced in c++17 to tell compiler it is okay to for a var to be unused:

```
int main()
{
    [[maybe_unused]] int x { 3 };
    return 0;
}
```

## 1.5

iostream

std::cout - a variable from iostream lib that enables sending data to the console.

cout stands for character output

<< is the insertion operator

<< can be used multiple times in single statement to concatenate pieces of output. e.g:

`std::cout << "hello" << " world";`

std::endl - outputs newline

best practice to always output newline after output is complete

std::cout is buffered. The buffer is periodically flushed to the console

buffering batches multiple writes together improving performance.

std::endl does two things:
    - outputs newlines
    - flushes the buffer (which is slow)

so std::endl is inefficient.

to output a newline without flushing the output buffer can use `\n`.
since there is no flushing `\n` tends to have better performance than std::endl.

best practice to use \n over std::endl when printing to console.

`std::cin` - reads character input.

`>>` is the extraction operator.

std::cin is also buffered.

`>>` extracts from the input buffer and converts to values and does copy assignment to a variable.

std::cin is buffered allowing for separate entering of input from extracting the input. ie: can input once and extract multiple times.

leading whitespace characters are discarded during extraction.

if extraction fails then future extractions fail till std::cin is cleared. ie non extracted characters stay in the buffer for next extraction attempt.

