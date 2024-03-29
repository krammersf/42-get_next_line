
# get_next_line

This is a get_next_line implementation in C.

This project is an implementation of a function named get_next_line, which reads and returns a line from a file descriptor each time it is called, until it reaches the end of the file.

## How it Work

The get_next_line function reads one line from the file descriptor fd each time it is called.
The function returns a pointer to a string containing the line that was read, without the newline character `\n`.
The function returns `NULL` when the end of file is reached or an error occurs.
The function uses a `static variable` to store the remaining characters from the previous call, if any.

### Example Usage

```c
char *line;
int fd = open("example.txt", O_RDONLY); // Open your file (replace "example.txt" with your file name)

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}

close(fd);
``` 

## Buffer size
The size of the buffer used to read from the file descriptor. If not specified, the default value is 42.
To set your own buffer size in the files, use the flag `-D BUFFER_SIZE=n` at time to compile de functons.

`gcc -D BUFFER_SIZE=64 your_source_file.c -o your_executable` 

## Bonus

The project includes a bonus version of get_next_line, which can read from multiple file descriptors at the same time.

## Grade: 125 / 100

## Used Tests
- Francinette: https://github.com/xicodomingues/francinette

### Disclaimer

Maybe you could notice a different coding style. At 42 we need to follow some rules according to the coding standard of the school such as:
```
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
Click here to read the norm file of 42 school.
