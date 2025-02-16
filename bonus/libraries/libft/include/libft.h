/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:32:05 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/11 13:32:56 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;
/* ---------------	LISTSAS		--------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ---------------	CARACTERES		--------------- */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(char c);

/* ---------------	STRINGS		--------------- */
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strstr(char *str, char *to_find);

/* ---------------   DESCRITOR DE FICHEIROS   --------------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_flags	initflags(void);
t_flags	setleft(t_flags flags);
t_flags	setdigit(char c, t_flags flags);
t_flags	setwidth(va_list args, t_flags flags);
int		setprecision(const char *str, int pos,
			va_list args, t_flags *flags);
int		ft_printf(const char *format, ...);
int		printer(char type, va_list args, t_flags flags);
int		printchar(char c, t_flags flags);
int		ft_putchar(char c);
int		put_str(const char *str, t_flags flags);
int		putstr(const char *str);
int		put_pre(const char *str, int precision);
int		putsign(int n, t_flags *flags);
int		putint(int n, t_flags flags);
int		putinteger(char *nbstr, int n, t_flags flags);
int		put_i(char *nbstr, int n, t_flags flags);
int		putunsigned(unsigned int n, t_flags flags);
int		put_u(char *nbstr, t_flags flags);
int		putunint(char *nbstr, t_flags flags);
int		ft_puthex(unsigned int n, int is_upper, t_flags flags);
int		putx(char *nbstr, int n, int is_upper, t_flags flags);
int		puthex(char *nbstr, int n, int is_upper, t_flags flags);
int		putpointer(unsigned long int n, t_flags flags);
int		putpointer_pre(unsigned long int n);
void	putnbr(unsigned long int n);
char	*itoa(long nb);
char	*utoa(unsigned int nb);
char	*xtoa(unsigned long int nb, int is_upper);
int		ft_unintlen(unsigned int n);
int		ft_hexlen(unsigned int n);
int		pointerlen(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);
int		putspace(int total_width, int size, int zero);
void	set_signals(void);
/* ---------------	MEMORIAS		--------------- */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc(size_t count, size_t size);
void	ft_free_collector(void);
/* ---------------	NUMEROS		--------------- */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_err_msg(char *msg, int int_return);
int		ft_fd_lines_counter(char *file_path);
void	ft_free_matriz(char **dp_char);
size_t	ft_get_time(void);
int		ft_is_quote_closed(char *input);
int		ft_matriz_big_line(char **matriz);
char	**ft_matrizdup(char **to_dup);
int		ft_matrizlen(char **to_count);
void	ft_printf_matriz(char **to_print);
char	*ft_strjoin3(char *s1, char *s2, char *s3, int flag);
void	ft_usleep(size_t time);

/* ---------------	GET_NEXT_LINE		--------------- */
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s);
void	*ft_calloc_gnl(size_t nmemb, size_t size);

#endif
