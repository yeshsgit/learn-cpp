Week starting 16/11/2026

# Monday 16/11/2026

## 2.10 continued..

doing some recap

translation unit - the result of the preprocessing step which is fed into the compiler.

translation - preprocessing + compiling + linking

preprocessory scans code for **preprocessor directives**

Preprocessor directives - start with # and end with newline (not with semicolon like c++ statements)

final output of preprocessor ie the translation unit contains no preprocessor directives.

the "using directives" for namespaces are not preprocessor directives.

`#include` is replaced with the contents of the included file.

included files may have preprocessor directives so preprocessing needs to be done recursively when a new file is included.

so `#include <iostream>` is replaced with the contents of a file called iostream.

typically one translation unit per source code .cpp file

`#define` used to make macros

macro - rule on how text should be replaced

function-like macros and object-like macros

function-like macros are unsafe and can do anything a function can - ?

object like macros definitions:
```
#define IDENTIFIER
#define IDENTIFIER substitution_text
```

macro identifiers have same rules as cpp identifiers
    convention - uppercase and separated by underscores

object like macro replaces the identifier with the substitution text

object-like macros with sub were used in C to assign names for literals

avoid macros with substitution text

without substitution text an object-like macro replaces the indentifier with nothing.

object-like macros without substitution text is considered acceptable

conditional compilation preprocessor directives:
    ifdef, ifndef, endif

#ifdef checks if an identifier was defined with #define
if the identifier was defined then the code below up till #endif is compiled. if not then it isn't compiled.

#ifndef checks if an identifier has not been defined

`#ifdef IDENTIFIER` is the same as `#if defined(IDENTIFIER)`
`#ifndef IDENTIFIER` is the same as `#if !defined(IDENTIFIER)`

`#if 0` can be used to exclude block of code from being compiled kinda like a block comment. This helps handle the fact tha multiline comments in c++ can't be nested.

most of the time macro substitution does not occur if the macro identifier is used in another preprocessor command.
e.g:

```
#define PRINT_NAME "Bob" // defining the macro to sub PRINT_NAME with "Bob"

int main()
{

// the PRINT_NAME below is inside a preprocessor command so won't be replaced
#ifdef PRINT_NAME

    // PRINT_NAME below will be replaced with "Bob"
    std::cout << "My name is " << PRINT_NAME << '\n';

#endif

    return 0;
}

```

preprocessor directives are resolved before compilation from top to bottom file by file.

directives are only valid from te point of definition to the end of the file they were defined in or the end of the file whic they were included into.

## 2.11

Header files

adding forward function declarations allows us to handle multi-file programs in which we don't want the compiler to complain because a function we use in one file exists in a different file.

Format:
`return_time IDENTIFIER(param datatypes);`

param names are optional and are ignored by the compiler.

For larger programs including tonnes of forward function declarations is not scalable.

Header files solve this (.h or .hpp or no extension)

contain forward declarations

iostream is a header file containing declaration of std::cout and other io identifiers

header files don't need to be added to compile command.
They are added implictly by `#include` statements

best practice to use .h file ext

to include our own header files need "" not <>
e.g: `#include "custom-header-file.h"`

One Definition Rule (ODR) - in a given program a variable or function can have only one definition.

if we add definitions inside a header file and it is included by multiple files this will violate the ODR and likely lead to linker errors because there are multiple identical definitions to choose from.

best practice for source files to `#include` their header files.
This helps catch some errors (like function return type) at compile time, but not all (like function parameter types because overloading is allowed).

avoid including .cpp files
    naming collisions
    ODR violations
    changes to cpp file mean all files including it need recompilation.
    changing cpp more common than headers.

double quotes - preprocessor checks source dir then include directories.
angled brackets (<>) - preprocessor searches include directories

stdlib headers with .h extension declare identifiers in the global namespace - bad because they can collide with user named identifiers.
Modern stdlib headers with no extension declare identifiers into the std namespace. The .h versions are left for backward compatibility only.

convention for user defined headers to use .h extension

including headers from other dirs with relative paths can work but is bad. Makes compilation dependent on directory structure.
A better way is to tell compiler to search for header files in some include path or search directory:
`g++ -o main.exe -I./source/includes main.cpp`

-I option allows to specify an alternate include directory
    note no space after -I

transitive includes are allowed

should not rely on transitive includes to use functionality though

ordering of headers to avoid minimise chance of incorrect inclusions working:
paired header file
project headers
3rd party headers
stdlib headers

^should help reveal problems with includes ie if the paired header file forgets to include stdlib headers for example.

## 2.12

Header guards - also called include guard

```
#ifndef SOME_UNIQUE_NAME
#define SOME_UNIQUE_NAME

// declarations

#endif
```

prevents a header's declarations appearing multiple times in the same translation unit when a header file is included by multiple files.

all header files should have header guards on them.

convention for the unique name is to use the full filename of the header file in all caps with underscores for spaces or punctuation.

just checked iostream header file and it has a header guard.. pretty cool

large projects - header files may have same name.
This means including one would prevent the other from being included when header guards are used.
In this case, need to make the unique names more unique.

note that header guards don't prevent a header from being included multiple times across multiple files - for example if 2 different files include the same header file.

so function definitions should go in cpp files, put the forward function declarations in header files.

there are some  cases where it is necessary to put non-function definitions (like type definitions) in header files. Header guards are for these mainly.

`#pragma` modern compiler preprocessor directive that can also be used for header guards.
e.g:
```
#pragma once

//code here
```

`#pragma once` won't work if a header file is duplicated and each is included effectively including the same header file twice (because the compiler doesn't know both files are the same) while the ifndef header guard would.

other pragma's are implementation specific and may not be supported on different compilers.. only pragma once behaviour is supported across most modern compilers

`#pragma once` is not defined by the cpp standard - so some compilers might not implement it.

quiz:

```
#ifndef ADD_H
#define ADD_H

int add(int x, int y);

#endif
```

# Tuesday 17/11/2026

## 2.13

designing programs

important to design programs before starting coding.

Design:

1 - define the goal

can only write a successful program if you know what you want it to do.

2 - define requirements

constraints the solution has - like time, space, memory, SLAs (I think) etc.

reqs should focus on what not how.

3 - define tools, targets and backup plan

4 - break down hard problems

gives program structure too.

5 - figuring out sequence of events

order to do things?

Implementation:

1 - outlining main function

2 - implement each function

define function prototype
write function
test the function

3 - final testing

keep programs simple to start - e.g displaying a 2-d field on the screen

add features over time

focus on one area at a time

test code as you go

don't try perfecting early code - aim for good enough

optimise for maintainability not perf

# Wednesday 18/11/2026

## 3.1

syntax and semantic errors

syntax errors - not following the grammar of c++

semantic errors - right syntax but the meaning is wrong. Some of these can be caught by the compiler, but many aren't caught. So the program just exhibits incorrect behaviour.

## 3.2

the debugging process

general approach to debugging:
1 - find the root cause of the problem
2 - understand why the bug is occuring
3 - figure out how to fix the bug
4 - fix the bug
5 - test the program again to make sure the bug is fixed
6 - test to ensure no new bugs were introduced

## 3.3

strat for debugging

finding the code causing a bug by inspection is difficult for complex programs.

bug **reproduction steps**

then need to use that to narrow down where the bug is.

a guessing game

## 3.4

basic debugging tactics

1 - comment out code

2 - validate code flow

3 - print values

print debugging has its flaws:
    - clutters code and output of program
    - need to modify code which might introduce new bugs
    - need to remove debug statements so not reusable

use std::cerr for debug statements - it doesn't buffer output like std::cout so it makes it avoids confusion as to where the error occurred.

## 3.5

more debugging tactics

can make debug statements conditional using preprocessor directives

use a logger

std::clog used for logging.
by default std::clog write to std::cerr

third party loggers

## 3.6

the debugger

debugger lets you examine (and modify) the program state while the program is running.

used -g to generate debug symbols.

then used lldb to run debugger

set breakpoint to main with `b main`

then used s to step through

`std::cout << std::unitbuf; // enables automatic flushing for std::out for debugging`

step over and step into - makes sense from the names

s or step - is like step into
n or next - is like step over
finish    - is like step out

some debuggers support stepping back, though it appears lldb does not

## 3.7

running and breakpoints

run to cursor equivalent: 

`thread until <line>` or `th u <line>`

or if not paused:

`breakpoint set --file <file> --line <line>`

can list, disable and delete breakpoints too

found some [docs](https://lldb.llvm.org/use/map.html#breakpoint-commands)

can use `thread jump --line <line>` to jump execution

step back isn't the same as the "set next statement" or jump in my case.

step back rewinds state while jump does not.

## 3.8

watching variables

on mac `-g` debug builds can work with both lldb and gdb.
but `-ggdb` can confuse lldb

can print vars on each step.

can watch vars.

can also set breakpoints on a var changing.

print x + 5 evaluates expression with var x

watching all local vars is possible too.

## 3.9

the call stack

bt displays the entire call stack

can view stack frames: `frame select <stack frame num>`

0 represents the top stack frame ie the function which is currently being called

1 is therefore the caller function

stackframe tells us what functions were called to get to a particular point in the code.

## 3.10

finding issues before they become problems.

don't make behavioural and structural changes to code at the same time.

defensive programming.

anticipate software misuse.

write tests

finding common mistakes with static analysis tools (linters)

best practice is to use a static analysis tool on programs.