# 42_pipex

Hi! This is my implementation of the **pipex** project for the 42 school curriculum.

This project is all about understanding and recreating the core logic behind Unix pipes (`|`)—that is, the ability to chain commands together so that the output of one becomes the input of the next, just like in the shell. The project also covers handling file redirections, argument parsing (including quoted and escaped arguments), and careful manual memory management in C.

---

## What is 42_pipex?

The main goal is to reproduce the behavior of a shell pipeline, e.g.:

```sh
< infile cmd1 | cmd2 | cmd3 > outfile
```

- The program takes an input file, a set of commands (with their own arguments), and an output file.
- It sets up the pipeline so that each command’s output is passed to the next command as input.
- It handles all the necessary process creation, redirections, and memory clean-up.

---

## Why did I build it this way?

I wanted my code to be modular, safe, and easy to understand (for others and my future self). Some key things I focused on:

- **Manual memory management**: No leaks allowed! Every allocation is freed, and all lists/arrays are cleaned up properly.
- **Clear error handling**: Every system call is checked, and errors are reported with helpful messages.
- **Argument parsing**: I made sure my code handles tricky cases like quoted arguments and escape characters.
- **Modular structure**: Each file does one thing—parsing, process management, redirection, or utility functions.

---

## How is the project structured?

```
ft_printf/                       #Custom implementation of a standard printf
get_next_line/                   #Custom implementation of a getline
src/
  commands.c                     # Finds command paths and builds command lists
  processes.c                    # Sets up and runs the pipeline of processes
  redirection.c                  # Handles redirection for single commands
  split_arguments.c              # Splits command lines into proper argv arrays

utilities/
  helpers.c                      # Array helpers: size, copy, and free
  list_utilities.c               # Linked list helpers for commands
  pipe_utils.c                   # File descriptor and piping helpers
  spl_args_utils.c               # Helpers for splitting arguments safely
  split_arguments_list_utils.c   # Linked list helpers for argument nodes

pipex.h                          # All types, macros, and function declarations
Makefile                         #Compilation
```

---

## How to use it

Compile with:

```sh
make
```

Then run, for example:

```sh
./pipex infile "grep hello" "wc -l" outfile
```

- Handles any number of commands.
- Supports arguments with spaces and quotes (e.g., `"grep 'hello world'"`).
- Errors are explained if anything goes wrong.

---

## What makes this implementation solid?

- **Memory safety:** All dynamic memory is freed. There are dedicated functions for cleaning up lists and arrays.
- **Process management:** Each command runs in its own child process; the parent waits for all children.
- **Error handling:** Every open, fork, exec, malloc, etc., is checked. If something fails, you get a clear error message.
- **Argument splitting:** Handles single and double quotes, as well as escaped characters—so commands behave just like in a shell.
- **No surprises:** Functions do exactly what their names say. Utility files contain only helpers, and main logic is in `src/`.

---

## What could be improved or extended?

- For very long command lists, a tail pointer could speed up appending nodes to the list.
- More comments and documentation—especially in the tricky parts of argument parsing—would help future me (and others).
- If you want to build a full shell, this code would be a solid base for command execution and argument parsing.

---

## Author

- **aobshatk**

---

## Licence 
This project is part of the 42 school curriculum and is meant for educational purposes.
