
# Structs

## Structure
A structure is a container, it can hold a bunch of things
* these can be of any type

Structure are used to organize related data (variables)
The structure s essentially a pre-cursor to Object Orientation
* In C++ they have evolved and look even closer to classes
* Unlike Object Orientation we do not have visibility modifiers

It's safe to treat a structure like a class/object

### Example
Each *thing* in a structure is called member
Each *member* has a name, a type and value
Names follow the rules for var names
Types can be any defined type

```cpp
{

    struct StudentRecord
    {
        char *name; //student name
        double hw[3]; //homework grades
        double test[2]; //test grades
        double ave; //final average
    };

}
```

When defining a structure we create a new data type
* similar to Object Oriented Programming
Once defined we create variables of this new type
* `StudentRecord stu;` variable on the stack

We can create pointers with it as well
* `StudentRecord* ptr;`

## Accessing Members
These are treated like variables
Use member to access operator '.'

```cpp
{

    cout << stu.name << endl;
    stu.hw[2] = 82.3;

}
```

## Assignment
Structures can be use just like variables

```cpp
{

    StudentRecord s1,s2;
    s1.name = "Mark Ash";
    ...
    s2 = s1; //copies this entire structure

}
```

## Pointers and Structs
Pointers to structures are often used
There is another member access operator used with pointers

```cpp
{

    StudentRecord *sptr;
    ...
    cout << "Name is " << sptr->name;
    cout << "Ave is " << sptr->ave;

}
```
This is the same syntax used in Object Orientation
* Used when building data structures

When making a struct in C we have to use type definitions (small syntax difference)

# Structs and Memory
> The "lost art" of Structure Packing

## Memory 
RAM
1. Stack
2. Static
3. Heap

Each variable in a struct take a certain amount of space
Each data type also has rules about how they can exist in memory
* It is **Vitally** important that data types must be addressed/allocated in memory
Poor use of variables and data types can/will lead to ineffecient storage

Arrays work because we have pointers at beginning and when we want something else in the array, we do pointer math  
Must be correct data type, so we use the correct pointer math 

### Does this really matter?
Yes, even though we use and have quick computers, we many eventually program small devices such as cell phones or automobile on-board computers
Even if we save 10-20% of space, that can be extremely helpful

## Struct Memory
Data Storage doesn't start on an arbitrary address
Each data type except for characteres have an alignment requirement

in x86:
1. Characters can start on any byte address
2. Shorts must start on and *EVEN* address
3. Int's and floats must start on a multiple of 4
    * 32 bit pointers
4. Long's and doubles must start on a multiple of 8

64 bit processor change this a little, but the ideas here are still the same

## Padding
This happens outside of structures 
Data types are "self aligning" 
* address follows rules automatically

We often take for granted what else is happening
Example:
`char *p;`
`char c;`
`in x;`
However, these are not assigned in memory order

`char *p;` - 4 bytes  
`char c;` - 1 byte  
`int x;` - 4 bytes  

So there would be extra space (padding that is in between these variables)

### What happens if we change the order?

char c; - 1  
char b; - 1  
char *p; - 4  
int x;  

So we would skip large amounts of memory

Pointer | Padding / Assignment
--------|------------------------
15274390| Char C
15274391| Char B
15274392| EMPTY LOSS OF MEMORY
15274393| EMPTY LOSS OF MEMORY
15274394| Char *p
15274395| Char *p
15274396| Char *p
15274397| Char *p
15274394| int x;
15274398| int x;
15274399| int x;
15274400| int x;

**BEST** way to address this is to keep everything together and list from greatest to least or least to greatest

So... double > int > char *p > char
or... char < char *p < int < double < float


