# Get Next Line

## Overview
The `get_next_line` project is a programming exercise designed to implement a function that reads a line from a file descriptor, one at a time, regardless of its size. This function is useful for processing text files or streams where lines need to be read incrementally.

## Features
- Reads from a file descriptor one line at a time.
- Handles any valid file descriptor, including standard input, files, and pipes.
- Efficient memory management using dynamic allocation.
- Supports configurable buffer size via the `BUFFER_SIZE` macro.

## Function Prototype
```c
char *get_next_line(int fd);
```

## How It Works
1. **Buffer Handling**: The function reads data from the file descriptor in chunks of `BUFFER_SIZE`.
2. **Line Parsing**: It identifies newline characters to split and return individual lines.
3. **Static Storage**: Unprocessed data is stored in a static variable for subsequent calls.
4. **Memory Management**: Allocates and frees memory dynamically to ensure efficient resource usage.

## File Structure
- `get_next_line.c`: Main implementation of the `get_next_line` function.
- `get_next_line_utils.c`: Helper functions for string manipulation and memory management.
- `get_next_line.h`: Header file containing function prototypes and required macros.

## Compilation
To compile the `get_next_line` function, use the following command:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```
Replace `42` with your desired buffer size.

## Usage
1. Include the `get_next_line.h` header in your project.
2. Call the function with a valid file descriptor:
   ```c
   int fd = open("example.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line);
   }
   close(fd);
   ```
3. Free the returned line after each call to prevent memory leaks.

## Examples
### Reading from a File
```c
int fd = open("file.txt", O_RDONLY);
if (fd < 0)
    return (1);

char *line;
while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Reading from Standard Input
```c
char *line;
while ((line = get_next_line(0)))
{
    printf("%s", line);
    free(line);
}
```

## Requirements
- The function should return `NULL` when an error occurs or when the end of the file is reached.
- A newline character at the end of the file is optional.
- The function must handle multiple file descriptors simultaneously.

## Notes
- Ensure that `BUFFER_SIZE` is greater than 0 for the function to work correctly.
- Avoid memory leaks by freeing all dynamically allocated memory.

## Testing
Test the function with different scenarios:
- Files with multiple lines.
- Files without newlines.
- Empty files.
- Large files.
- Standard input (interactive or piped data).
