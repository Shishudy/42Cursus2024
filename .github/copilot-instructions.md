---
applyTo:
  - language: c
  - language: cpp
  - language: makefile
---

# 42 School Development Instructions

## Norminette Compliance (CRITICAL)

### File Header (Required for all .c/.cpp/.h/.hpp files)
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by rafasant          #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

### Core Norminette Rules
- Max 25 lines per function (excluding braces)
- Max 5 functions per file
- Max 80 characters per line
- Max 4 parameters per function
- Variables declared at top of function only
- One statement per line
- No `for`, `do...while`, `switch`, `case`, `goto`
- Tabs (width 4), not spaces
- Single empty line between functions
- Function names: snake_case (C) or camelCase (C++)
- No trailing whitespace
- Space after keywords: `if (`, `while (`

## Compilation Flags

**C Projects:** `CC = cc` with `CFLAGS = -Wall -Wextra -Werror`

**C++ Projects:** `CC = c++` with `CFLAGS = -Wall -Wextra -Werror -std=c++98`
- C++98 standard only (no C++11+ features)
- Class names: PascalCase
- Orthodox Canonical Form when required

## Makefile Structure

Required rules: `all`, `clean`, `fclean`, `re`, `.PHONY`
Must NOT relink unnecessarily - only recompile changed files.

```makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = program_name
RM = rm -rf
SRCS = file1.c file2.c
OBJS = ${SRCS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
```

## Key Constraints

**Memory:** Every `malloc()` needs `free()`. Check all returns immediately.

**Forbidden:** No `printf()` unless allowed. No globals (except signals). Check subject for allowed functions.

## Critical C Patterns

### Error Handling
- Check NULL **before** any operations: `if (!ptr) return (NULL);`
- Malloc check on next line: `ptr = malloc(...); if (!ptr) return (NULL);`
- Protect overflow in calloc:
```c
value = nmemb * size;
if (value && (value / size) != nmemb)
	return (NULL);
```
- Multi-allocation cleanup: Create static helper to free all on failure
```c
static void *ft_free(char **arr)
{
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}
```

### Static Keyword Usage
- Helper functions not in header: Always `static`
- Persistent state (GNL): `static char buffer[BUFFER_SIZE];`
- Multiple FD (bonus): `static char buffer[FOPEN_MAX][BUFFER_SIZE];`
- Avoid globals pattern: `static struct` returned by function

### BUFFER_SIZE & Defines
- Use `#ifndef` for defines: `#ifndef BUFFER_SIZE` then `#define BUFFER_SIZE 42`
- Compile with: `cc -D BUFFER_SIZE=XX` to override

### Memory Patterns
- Always `+1` for null terminator: `malloc(sizeof(char) * (len + 1))`
- Always null-terminate strings: `str[len] = '\0';`
- Comma operator for cleanup: `return (free(ptr), NULL);`
- Reuse pattern (GNL): Functions free old and return new

### Header Guards
Use `#ifndef`, NOT `#pragma once`:
```c
#ifndef FILENAME_H
# define FILENAME_H
#endif
```

### Allowed Functions by Project
- **libft:** `malloc`, `free`, `write`
- **get_next_line:** Add `read`
- **ft_printf:** Add `va_start`, `va_arg`, `va_end`
- **Philosophers:** Add `pthread_*`, `usleep`, `gettimeofday`
- **minishell:** Add `readline`, `fork`, `exec*`, `pipe`, `dup`, `wait*`, signals
- Check subject for project-specific list

## Critical C++ Patterns

### Orthodox Canonical Form (OCF) - Required CPP02+
Every class with attributes needs all 4:
```cpp
Class();                           // Default constructor
Class(const Class &other);         // Copy constructor
Class &operator=(const Class &rhs); // Assignment with self-check
~Class();                          // Destructor (virtual if polymorphic)
```
**Self-assignment check mandatory:** `if (this != &rhs) { ... } return *this;`

### Deep Copy (CPP04)
- Copy constructor/assignment must allocate NEW memory
- Never share pointers: `_ptr = new Type(*other._ptr);`

### C++98 Restrictions
**FORBIDDEN:** `auto`, `nullptr`, `override`, `final`, `using namespace std;`, smart pointers, range-based loops, lambdas
**USE:** `.c_str()` for file streams, `new`/`delete`, traditional loops

### Virtual Functions (CPP04)
- Pure virtual destructors MUST have implementation in .cpp
- Virtual destructor required for polymorphic inheritance
- Virtual inheritance for diamond: `class A : public virtual B`

### Header Guards
Use `#ifndef`, NOT `#pragma once` (except in provided files):
```cpp
#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP
// ... code ...
#endif
```
Format: `FILENAME_HPP` in uppercase

### Naming & Style
- Private members: `_memberName` (underscore prefix)
- Const correctness: `Type getName() const;` for getters
- Return const reference for strings: `const std::string &getName() const;`
- Initializer lists preferred: `Class() : _member(value) {}`

### Operator Overloading (CPP02)
- Post-increment returns copy: `Type operator++(int);`
- Pre-increment returns reference: `Type &operator++();`
- Stream insertion: `std::ostream &operator<<(std::ostream &, const Type &);`

### Exception Handling (CPP05)
```cpp
class MyException : public std::exception {
	virtual const char *what() const throw();
	~MyException() throw();  // throw() for destructors
};
```

### Forward Declarations (CPP04+)
Break circular dependencies:
```cpp
class Brain;  // Forward declaration
class Dog {
	Brain *_brain;
};
```

## Bonus Files
`_bonus` suffix: `file_bonus.c`, `file_bonus.h`. Never mix with mandatory.

## Critical Errors to Avoid

**C:** Functions > 25 lines, unchecked returns, memory leaks, `for`/`printf` when forbidden, globals, missing NULL checks, forgetting `+1` for null terminator

**C++:** Missing self-assignment check, shallow copy, C++11+ features, missing virtual destructor, pure virtual destructor not in .cpp, `using namespace std;`, missing `const` getters
