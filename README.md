# Get Next Line

The `get_next_line` function is a utility function that reads a line from a file descriptor and returns it as a dynamically allocated string. This function is particularly useful for reading input from files or standard input in a line-by-line manner.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

The `get_next_line` function simplifies the process of reading lines from a file descriptor. It handles the complexities of reading and buffering data, allowing you to focus on processing the lines of input.

## Features

- Reads lines from a file descriptor and returns them as dynamically allocated strings.
- Handles buffering and reading data from the file descriptor efficiently.
- Supports reading from multiple file descriptors simultaneously.

## Installation

To use the `get_next_line` function in your project, follow these steps:

1. Clone the repository to your local machine.
2. Copy the `get_next_line.c` and `get_next_line.h` files into your project directory.
3. Include the `get_next_line.h` header file in your source code.

## Usage

The `get_next_line` function has the following prototype:

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.

The function returns a dynamically allocated string containing the next line read from the file descriptor. If the end of the file is reached, or an error occurs, the function returns `NULL`.

Here's an example of how to use the `get_next_line` function:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

Make sure to include the necessary headers and handle any error conditions appropriately.

## Contributing

Contributions to the Get Next Line project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

