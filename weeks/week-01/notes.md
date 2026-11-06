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

data values in source code are called literals

object - represents region in memory that can hold a value

in c++ access memory through objects, using direct access is not generally good.

variable - an object with a name (identifier)


