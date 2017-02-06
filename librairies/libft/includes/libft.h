/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:03:03 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/24 00:58:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <wchar.h>
# include <stdint.h>

void			ft_bzero(void *src, size_t len);
void			ft_memdel(void **a_ptr);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int endchr, size_t len);
void			*ft_memchr(const void *src, int c, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_realloc(void *ptr, size_t size);

int				ft_memcmp(const void *s1, const void *s2, size_t len);

void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int n);
void			ft_putnl(void);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int n, int fd);

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);

char			*ft_strdup(const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *str, char (*f)(char));
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char			*ft_strsub(char const *str, unsigned int start, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);

char			**ft_strsplit(char const *str, char c);

void			ft_strdel(char **a_str);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));

int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_uporlow(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
char			*ft_itoa(int n);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

long			ft_atoi(const char *str);
double			ft_atof(const char *str);
void			ft_swap(int *a, int *b);
double			ft_sqrt(double x);
double			ft_invsqrt(double x);

size_t			ft_strlen_w(wchar_t *str);
void			ft_putnbrlong(long long int nb);
char			*ft_octal_itoa(unsigned long long n);
char			*ft_unsigned_itoa(unsigned long int n);
char			*ft_hexa_itoa(unsigned long long n);
int				ft_nbrlen(intmax_t nb);
int				ft_nbrlonglen(long long nb);

#endif
