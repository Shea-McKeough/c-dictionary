# Dictionary CLI (C)

An interactive key–value dictionary implemented in C using a singly linked list.
The program provides a simple command-line interface for inserting, retrieving,
deleting, and inspecting key–value pairs.

## Features

* Custom dictionary abstract data type (ADT)
* Singly linked list–backed storage
* Commands: `put`, `get`, `del`, `clr`, `siz`
* Manual memory management (malloc/free)
* Interactive REPL-style interface

## Files

* `dict.h` — Dictionary interface (ADT declarations)
* `dict.c` — Dictionary implementation
* `main.c` — Command-line interface and input handling

## Build

Compile with:
'gcc -Wall -Wextra -std=c11 main.c dict.c -o dict'

Run with:
'./dict'

## Usage

Example session:
> put foo:bar
> get foo
bar
> siz
1
> del foo
> siz
0

## Notes

Some helper code (such as the `readline` function and initial program structure)
was provided by the course instructor. The dictionary implementation, command handling,
and memory management logic were written by me.