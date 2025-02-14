/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:19:49 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/14 19:27:43 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
 * ft_isalpha checks if c is alphabetical character.
 * returns zero if the character tests false and
 * returns non-zero if the character tests true.
 */
int					ft_isalpha(int c);

/*
 * ft_isdigit checks for a decimal digit character.
 * from '0' -> '9'
 * returns zero if c not included from '0' -> '9' one otherwise
 */
int					ft_isdigit(int c);

/*
 * ft_isnumber checks for any character either alpha using
 * ft_isalpha() or digit using ft_isdigit.
 * character set '0' -> '9', 'a' -> 'z' and 'A' -> 'Z'.
 * returns zero if c not included in the character set, non zero if included.
 */
int					ft_isalnum(int c);

/*
 * ft_isascii tests if the given c is an ascii character.
 * which is any character between 0 and decimal 127 inclusive
 */
int					ft_isascii(int c);

/*
 * ft_isprint tests for any printing character, including space.
 * returns zero if c not included, none zero otherwise
 */
int					ft_isprint(int c);

/*
 * ft_strlen computes the length of the string s.
 */
size_t				ft_strlen(const char *s);

/*
 * ft_memset writes len bytes of value c.
 * c is converted to unsigned char to the string b.
 * returns it's first argument
 */
void				*ft_memset(void *b, int c, size_t len);

/*
 * ft_bzero writes n butes to the strgin s.
 * if n is zero ft_bzero does nothing.
 */
void				ft_bzero(void *s, size_t n);

/*
 * ft_memcpy copies n bytes from src to dst.
 * if dst and src overlap, behavior is undefined.
 * returns the original value of dst
 */
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
 * ft_memmove copies n bytes from string src to string dst.
 * The two strings my overlap.
 * the copy is always done in a non-destructive manner.
 * returns the original value of dst.
 */
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
 * ft_strlcpy takes the full size of dst buffer and guarantee
 * null termination
 * if there is room.
 * The room for null should be included in dstsize.
 *
 * ft_strlcpy copies up to dstsize - 1 characters from src to
 * dst null terminating the result
 * if src and dst overlap behavior is undefined.
 *
 * returns the total length of the string it tried to creat, means
 * the length of src
 *
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
 * ft_strlcat appends strings src to dst.
 * It will pend at most dstsize - ft_strlen(dst) - 1.
 * dstsize is the full length of the concatenated string src + dst + 1.
 *
 * returns
 * 	-> src length if dstsize = 0
 * 	-> dstsize + src length if dstsize less than dst length
 * 	-> dst length + src length if dst length less than dstsize
 */
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
 * ft_toupper converts a lowercase letter to the corresponding letter.
 * if c is lowercase letter ft_toupper returns:
 * the corresponding uppercase letter if there is one.
 * the argument is unchanged otherwise.
 */
int					ft_toupper(int c);

/*
 * ft_tolower converts an uppercase character to the correspanding letter.
 * if c is uppercase ft_tolower returns:
 * the corresponding lowercse letter if there is one.
 * the argument is unchanged otherwise.
 */
int					ft_tolower(int c);

/*
 * ft_strchr locates the first occurrence of c (converted to char) in the
 * string s.
 * The null terminator '\0' considered to be part of the string.
 * if c is '\0' the function locate the terminating '\0'.
 *
 * returns a pointer to the located character,
 * NULL if the character does not appear in the string
 */
char				*ft_strchr(const char *s, int c);

/*
 * ft_strrchr identical to ft_strchr except
 * it locates the last occurrence of c.
 *
 * returns a pointer to the located character,
 * NULL if the character does not appear in the string
 */
char				*ft_strrchr(const char *s, int c);

/*
 * ft_strncmp lexicographically compare
 * the null-terminated strings s1 and s2.
 * returns
 * 	-> int greater than zero if s1 greater than s2
 * 	-> int less than zero if s2 greater than s1
 * 	-> zero if s1 equal to s2
 *
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * ft_memchr locates the first occurrence of c (converted to an unsigned char)
 * in string s.
 * The function returns a pointer to the byte located,
 * or NULL if no such byte exists within n bytes
 */
void				*ft_memchr(const void *s, int c, size_t n);

/*
 * ft_memcmp compares byte string s1 against byte string s2.
 * Both string are assumed to be n bytes logn.
 *
 * returns zero if the two strings are identical,
 * otherwise returns the difference between
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 * ft_strnstr locates the first occurrence of the null terminated string
 * needle in the string haystak.
 * where not more than len characters are searched.
 * Characters that appear after a '\0' are not searched.
 *
 * if needle is empty string haystack is returned.
 * if needls occurs nowhere in haystack NULL is returned.
 * otherwise a pointer to the first character found of needls ir returned
 */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

/*
 * ft_atoi ascii to integer
 */

# ifndef ATOIERROR
#  define ATOIERROR 9223372036854775807LL
# endif
long long			ft_atoi(const char *str);

/*
 * ft_calloc function contiguously allocates enough space
 * for count objects that are size bytes of memory each
 * and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 */
void				*ft_calloc(size_t count, size_t size);

/*
 * ft_strdup allocates sufficine memory
 * for a copy of the string s1.
 * if insufficient memory is available, NULL is returned.
 * alwans NULL terminating the copied string.
 */
char				*ft_strdup(const char *s1);

// PART II

/*
 * s: The string from which to create the substring.
 * start: The start index of the substring in the string ’s’.
 * len: The maximum length of the substring.
 * ft_substr returns the substring or NULL if allocation failed.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
 * -> s1: The prefix string.
 * -> s2: The suffix string.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/*
 * -> s1: The string to be trimmed.
 * -> set: The reference set of characters to trim.
 * returns
 * -> the trimmed string.
 * -> NULL if the allocation falis.
 */
char				*ft_strtrim(char const *s1, char const *set);

/*
 * ft_split:
 * -> s: The string to be split.
 * -> c: The delimiter character.
 * returns
 * -> The array of new strings.
 * -> NULL if allocation fails.
 */
char				**ft_split(char const *s, char c);

/* ft_itoa inteder to ascii */
char				*ft_itoa(int n);

/*
 * -> s The string on which to intterate.
 * -> f the function to apply to each character.
 * returns
 * -> The string from the successive applications of f.
 * -> NULL if the allocation falis.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
 * -> s The string on which to intterate.
 * -> f the function to apply to each character.
 * returns
 * -> The string from the successive applications of f.
 * -> NULL if the allocation falis.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// ---- file descriptors functions ----
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// ---- Linked list ----
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);

/*
 * Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/*
 * Deletes and frees the given node and every
 * successor of that node, using the function ’del’
 * and free(3).
 * Finally, the pointer to the list must be set to
 * NULL.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/*
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
