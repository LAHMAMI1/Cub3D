/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:40:23 by fdiraa            #+#    #+#             */
/*   Updated: 2023/09/22 01:02:11 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int f);
int					ft_isdigit(int f);
int					ft_isalnum(int f);
int					ft_isascii(int f);
int					ft_isprint(int f);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *f, int c, size_t n);
void				ft_bzero(void *f, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_toupper(int f);
int					ft_tolower(int f);
char				*ft_strchr(const char *f, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char const *s, char c);

char				*ft_dup(const char *s, int n);
int					ft_free(char **s, int i);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *list);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *list);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_isspace(int ch);
void				ft_free_split(char **splited_array);
int					ft_strcmp(const char *str1, const char *str2);
void				ft_lstswap(t_list *a, t_list *b);
int					ft_strcmp_char(char *str1, char *str2, char c);
void				ft_swap_strings(char **str1, char **str2);
int					ft_isnumber(char *number);
long				ft_long_atoi(const char *str);
#endif
