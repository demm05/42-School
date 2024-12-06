/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 14:07:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

// ------------------------------------CHAR-----------------------------------

/**
 * @brief Tests whether a character is a letter of the alphabet.
 *
 * This function checks if the given character 
 * is an alphabetic character (either uppercase or lowercase).
 *
 * @param c The character to test.
 * @return A non-zero value 
 *		1 (true) if the character is alphabetic,
 *		0 (false) otherwise.
 * */
int		ft_isalpha(int c);

/**
 * @brief Tests whether a character is a decimal digit.
 *
 * This function checks if the given character is a numerical digit 
 * between '0' and '9' inclusive.
 *
 * @param c The character to test.
 * @return A non-zero value 
 *		1 (true) if the character is a digit, 
 *		0 (false) otherwise.
 * */
int		ft_isdigit(int c);

/**
 * @brief Tests whether a character is alphanumeric.
 *
 * This function checks if the given character is an alphanumeric character, 
 * meaning it is either a letter of the alphabet (a-z, A-Z) or a digit (0-9).
 *
 * @param c The character to test.
 *
 * @return A non-zero value 
 *		1 (true) if the character is alphanumeric, 
 *		0 (false) otherwise.
 *
 * @see ft_isalpha(), ft_isdigit()
 * */
int		ft_isalnum(int c);

/**
 * @brief Tests whether a character is an ASCII character.
 *
 * This function checks if the given character 
 * is a 7-bit US-ASCII character code. 
 * ASCII characters have decimal values from 0 to 127 (inclusive).
 *
 * @param c The character to test.
 *
 * @return A non-zero value 
 *		1 (true) if the character is an ASCII character, 
 *		0 (false) otherwise.
 * */
int		ft_isascii(int c);

/**
 * @brief Tests whether a character is a printable character.
 *
 * This function checks if the given character is a printable character, 
 * including spaces but not control characters. 
 *
 * @param c The character to test.
 *
 * @return A non-zero value 
 *		1 (true) if the character is printable, 
 *		0 (false) otherwise.
 * */
int		ft_isprint(int c);

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * This function converts the given character `c` to uppercase 
 * if it is a lowercase letter. Otherwise, it returns the character unchanged.
 *
 * @param c The character to convert.
 *
 * @return The uppercase equivalent of `c` if it is a lowercase letter, 
 *			otherwise `c` unchanged.
 * */
int		ft_toupper(int c);

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * This function converts the given character `c` to lowercase 
 * if it is an uppercase letter.  Otherwise, it returns the character unchanged.
 *
 * @param c The character to convert.
 *
 * @return The lowercase equivalent of `c` if it is an uppercase letter, 
 *			otherwise `c` unchanged.
 * */
int		ft_tolower(int c);

// ------------------------------------CHAR-----------------------------------
// ----------------------------------STRING-----------------------------------

/**
 * @brief Calculates the length of a string.
 *
 * This function computes the length of the string pointed to by `s`, 
 * excluding the terminating null character ('\0').
 *
 * @param s A pointer to the string whose length is to be calculated.
 *
 * @return The length of the string 
 *		(number of characters before the null terminator).
 * */
size_t	ft_strlen(const char *str);

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * This function compares at most the first `n` characters of the strings 
 * pointed to by `s1` and `s2`. The comparison is done lexicographically. 
 * Characters following a null character are not considered.
 *
 * @param s1 A pointer to the first string.
 * @param s2 A pointer to the second string.
 * @param n The maximum number of characters to compare.
 *
 * @return An integer indicating the relationship between the two strings:
 *         - Zero if the strings are equal up to the first `n` characters.
 *         - Greater than zero if `s1` is lexicographically greater than `s2`.
 *         - Less than zero if `s1` is lexicographically less than `s2`.
 * */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches the string pointed to by `s` 
 * for the first occurrence of the character `c`.
 *
 * @param s A pointer to the string to be searched.
 * @param c The character to search for.
 *
 * @return A pointer to the first occurrence of `c` in `s`, 
 *				or a null pointer if `c` is not found.
 *         If `c` is the null character ('\0'), 
 *				the function returns a pointer to the null terminator of `s`.
 * */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * This function searches the string pointed to by `s` 
 * for the last occurrence of the character `c`.
 *
 * @param s A pointer to the string to be searched.
 * @param c The character to search for.
 *
 * @return A pointer to the last occurrence of `c` in `s`, 
 *				or a null pointer if `c` is not found.
 *         If `c` is the null character ('\0'),	
 *				the function returns a pointer to the null terminator of `s`.
 * */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Locates the first occurrence of a substring 
 *		within a limited portion of a string.
 *
 * This function searches the string pointed to by `haystack` 
 * for the first occurrence of the substring pointed to by `needle`. 
 * The search is limited to the first `n` characters of `haystack`.
 *
 * @param haystack A pointer to the string to be searched.
 * @param needle A pointer to the substring to search for.
 * @param len The maximum number of characters to search in `haystack`.
 *
 * @return A pointer to the first occurrence of `needle` within `haystack`, 
 *			or a null pointer if `needle` is not found.
 *		If `needle` points to an empty string, `haystack` is returned.
 * */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * @brief Copies a string with size bounds.
 *
 * This function copies up to `size - 1` characters from the string 
 * pointed to by `src` to the buffer pointed to by `dest`. 
 * The copy is always null-terminated.
 *
 * @param dest A pointer to the destination buffer.
 * @param src A pointer to the source string.
 * @param size The size of the destination buffer, 
 *					including space for the null terminator.
 *
 * @return The total length of the string that would have been copied 
 *				if there were enough space. 
 *         This may be larger than `size` if `src` is longer than `size - 1`.
 * */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends a string with size bounds.
 *
 * This function appends up to `size - strlen(dest) - 1` characters 
 * from the string pointed to by `src` to the end of the string 
 * pointed to by `dest`. The destination string is always null-terminated.
 *
 * @param dest A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param size The total size of the destination buffer, 
 *				including space for the null terminator.
 *
 * @return The total length of the string that would have been created 
 *				if there were enough space.
 *         This may be larger than `size` if the combined length of 
 *				`dest` and `src` is greater than `size - 1`.
 * */
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Concatenates two strings.
 *
 * This function allocates (with `malloc(3)`) and returns a new string, 
 * which is the result of the concatenation of `s1` and `s2`.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 *
 * @return The new string, or NULL if the allocation fails.
 * */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trims a string.
 *
 * Allocates (with `malloc(3)`) and returns a copy of `s1` with the characters 
 * specified in `set` removed from the beginning and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 *
 * @return The trimmed string, or NULL if the allocation fails.
 * */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Extracts a substring from a string.
 *
 * Allocates (with `malloc(3)`) and returns a substring from the string `s`.
 * The substring begins at index `start` and is of maximum size `len`.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string `s`.
 * @param len The maximum length of the substring.
 *
 * @return The substring, or NULL if the allocation fails.
 * */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Splits a string into an array of substrings.
 *
 * Allocates (with `malloc(3)`) and returns an array of 
 * strings obtained by splitting `s` using the character `c` as a delimiter. 
 * The array must end with a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 *
 * @return The array of new strings resulting from the split, 
 *			or NULL if the allocation fails.
 * */
char	**ft_split(char const *s, char c);

/**
 * @brief Duplicates a string.
 *
 * This function allocates sufficient memory (with `malloc(3)`) 
 * for a copy of the string pointed to by `s1`, copies the string into 
 * the new memory, and returns a pointer to it.
 *
 * @param s1 The string to duplicate.
 *
 * @return A pointer to the newly allocated string, 
 *			or NULL if insufficient memory was available.
 * */
char	*ft_strdup(const char *src);

/**
 * @brief Converts a string to an integer.
 *
 * This function converts the initial portion of the string 
 * pointed to by `str` to an `int` representation.
 *
 * @param str The string to convert.
 *
 * @return The converted integer value.
 * */
int		ft_atoi(const char *nptr);

/**
 * @brief Converts an integer to a string.
 *
 * Allocates (with `malloc(3)`) and returns a string representing the integer 
 * received as an argument. Negative numbers must be handled.
 *
 * @param n The integer to convert.
 *
 * @return The string representing the integer, or NULL if the allocation fails.
 * */
char	*ft_itoa(int n);

/**
 * @brief Applies a function to each character of a string with index.
 *
 * Applies the function `f` to each character of the string `s`, 
 * passing its index as the first argument and the character itself 
 * as the second. A new string is created (using `malloc(3)`) to collect 
 * the results from the successive applications of `f`.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 *
 * @return The string created from the successive applications of `f`, 
 *			or NULL if the allocation fails.
 * */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies a function to each character of a string with index.
 *
 * Applies the function `f` on each character of the string `s`, 
 * passing its index as the first argument. Each character is passed 
 * by address to `f` to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// -----------------------------------STRING-----------------------------------
// -----------------------------------MEMORY-----------------------------------

/**
 * @brief Allocates memory and initializes it to zero.
 *
 * This function allocates memory for an array of `num` elements, 
 * each of size `size` bytes. The memory is initialized to zero.
 *
 * @param num The number of elements to allocate.
 * @param size The size of each element in bytes.
 *
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 * */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Copies a block of memory, handling overlapping areas.
 *
 * This function copies `n` bytes from the memory area pointed to by `src` 
 * to the memory area pointed to by `dest`. It is designed to handle 
 * overlapping memory areas, ensuring that the copy is performed correctly 
 * even if the source and destination overlap.
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to copy.
 *
 * @return A pointer to the destination memory area (`dest`).
 * */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills a block of memory with a specific value.
 *
 * This function fills the first `n` bytes of the memory area 
 * pointed to by `s` with the constant byte `c`.
 *
 * @param s A pointer to the memory area to fill.
 * @param c The value to fill the memory with (converted to an unsigned char).
 * @param n The number of bytes to fill.
 *
 * @return A pointer to the memory area `s`.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Locates the first occurrence of a byte in a memory block.
 *
 * This function searches the first `n` bytes of the memory 
 * area pointed to by `s` for the first occurrence of the byte `c`.
 *
 * @param s A pointer to the memory area to search.
 * @param c The byte to search for (converted to an unsigned char).
 * @param n The number of bytes to search.
 *
 * @return A pointer to the location of 
 *			the first occurrence of `c` in the memory area, 
 *			or NULL if `c` is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares two blocks of memory.
 *
 * This function compares the first `n` bytes of the memory areas 
 * pointed to by `s1` and `s2`.
 *
 * @param s1 A pointer to the first memory area.
 * @param s2 A pointer to the second memory area.
 * @param n The number of bytes to compare.
 *
 * @return An integer indicating the relationship between the two memory areas:
 *         - Zero if the contents of the memory areas are identical.
 *         - Less than zero if `s1` is lexicographically less than `s2`.
 *         - Greater than zero if `s1` is lexicographically greater than `s2`.
 * */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies a block of memory.
 *
 * This function copies `n` bytes from the memory area pointed to by `src` 
 * to the memory area pointed to by `dest`.
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to copy.
 *
 * @return A pointer to the destination memory area (`dest`).
 * */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Sets a byte string to zero.
 *
 * This function sets the first `n` bytes of the byte string 
 * pointed to by `s` to zero.
 *
 * @param s A pointer to the byte string.
 * @param n The number of bytes to set to zero.
 * */
void	ft_bzero(void *s, size_t n);

// -----------------------------------MEMORY-----------------------------------
// ------------------------------------FILES-----------------------------------

/**
 * @brief Outputs a character to a file descriptor.
 *
 * Outputs the character `c` to the given file descriptor `fd`.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs a string to a file descriptor.
 *
 * Outputs the string `s` to the given file descriptor `fd`.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs a string to a file descriptor, followed by a newline.
 *
 * Outputs the string `s` to the given file descriptor `fd`, 
 * followed by a newline character.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs an integer to a file descriptor.
 *
 * Outputs the integer `n` to the given file descriptor `fd`.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * */
void	ft_putnbr_fd(int num, int fd);
// ------------------------------------FILES-----------------------------------

typedef struct str_info
{
	size_t	str_len;
	size_t	set_in_str;
	size_t	start;
	size_t	end;
}	t_str_info;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ------------------------------------LIST------------------------------------

/**
 * @brief Creates a new node for a linked list.
 *
 * Allocates (with `malloc(3)`) and returns a new node.
 * The member variable `content` is initialized with 
 * the value of the parameter `content`. 
 * The variable `next` is initialized to NULL.
 *
 * @param content The content to create the node with.
 *
 * @return The new node, or NULL if the allocation fails.
 * */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds a new node to the beginning of a linked list.
 *
 * Adds the node `new` at the beginning of the list `lst`.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * Counts the number of nodes in the list `lst`.
 *
 * @param lst The beginning of the list.
 *
 * @return The length of the list.
 * */
int		ft_lstsize(t_list *lst);

/**
 * @brief Finds the last node in a linked list.
 *
 * Returns the last node of the list `lst`.
 *
 * @param lst The beginning of the list.
 *
 * @return The last node of the list, or NULL if the list is empty.
 * */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds a new node to the end of a linked list.
 *
 * Adds the node `new` at the end of the list `lst`.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes a single node in a linked list.
 *
 * Takes as a parameter a node `lst` and frees the memory of 
 * the node's content using the function `del` given as a parameter and 
 * frees the node itself. The memory of `next` must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Clears an entire linked list.
 *
 * Deletes and frees the given node `lst` and every successor of that node, 
 * using the function `del` and `free(3)`. Finally, the pointer to the list 
 * must be set to NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 * */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates through a linked list and applies a function 
 * to each node's content. Iterates the list `lst` and applies 
 * the function `f` on the content of each node.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Creates a new list by applying a function to each node's content.
 *
 * Iterates the list `lst` and applies the function `f` to the content 
 * of each node. Creates a new list resulting from the successive applications 
 * of `f`. The `del` function is used to delete the content of a node if needed.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node.
 *
 * @return The new list, or NULL if the allocation fails.
 * */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ------------------------------------LIST------------------------------------

#endif
