#include "header.h"

/**
 * _getline - reads an entire line from stream,
 * storing the address of the buffer containing the text into *lineptr.
 * The buffer is null-terminated and includes the newline character,
 * if one was found
 * @lineptr: the buffer that the function should update each call
 * @n: the size of the line_buffer after update
 * @stream: the stream that the function should read the characters from
 * Return: On  success, return  the  number of characters read,
 * including the delimiter character, but not including the
 * terminating null byte ('\0'). This value can be used to
 * handle embedded null bytes in the line read.
 *
 * return -1 on failure to read a line (including end-of-file condition).
 * the buffer should be freed by the user program even on failure.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	int buffer_position = 0;
	size_t line_position = 0;
	ssize_t r = 0, index = 0, char_count = 0;

	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BUFFER_SIZE);
		*n = BUFFER_SIZE;
	}
	do {
		r = read(fileno(stream), buffer, *n);
		if (r == -1)
			return (-1);
		if (r == 0)
			break;
		if (line_position + r >= *n)
		{
			*n += r;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		while (index < r)
		{
			if (buffer[buffer_position] == '\n')
			{
				(*lineptr)[line_position++] = '\0';
				return (char_count);
			}
			(*lineptr)[line_position++] = buffer[buffer_position++];
			char_count++;
		}
		if (buffer_position >= r)
			buffer_position = 0;
		index++;
	} while (r > 0);
	if (line_position == 0 && r == 0)
		return (0);
	return (char_count);
}
