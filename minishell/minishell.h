/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:44:51 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/10/27 12:27:18 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define KYEL "\x1B[33m"
# define KNRM  "\x1B[0m"

# define PERS_EXIT 32

extern int g_info_exit;

typedef	struct s_list
{
	int				i;
	char			*old_word;
	char			*new_word;
	struct s_list	*next;
	
}	t_list;

typedef struct s_info
{
	int		argc;
	char	**argv;
	char	**env_copy;

}	t_info;

typedef struct s_term
{
	int		fd_0;
	int		fd_1;;
	int		n_cmd;
	char	*prompt;
	char	***cmd;
	t_info	info;
	t_list	*env;
	int 	double_q;
	int 	single_q;
	int 	i;
	int		c_quote;
	int		q_skip;

}	t_term;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned int	numbwords(char const *s, char c);
unsigned int	numbletter(char const *s, char c);
char			**mallocstring(char **str, char const *s,
					char c, unsigned int nb);
char			**ft_split(char const *s, char c);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
int 			handler_env(t_term *term, char **cmd_d, int pos);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(char *old, char *new);
int				ft_lstsize(t_list *lst);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_countquotes(char *line);
size_t			ft_countredir(char *prompt);
int				ft_perror(char *str);
int				ft_strchr(const char *s, int c);
int				ft_isprint(int c);
int				ft_findpath(t_term *term, char *path);
char			*ft_strjoin(char const *s1, char const *s2);

void			ft_builtinfunctions(t_term *term, char **cmd);
char			*ft_substr(char *s, int start, char c);


void 			handler_dollar(t_term *term, char **cmd);
void			handler_dollar_qm(t_term *term, char **cmd, int i);
int				handler_dollar2(t_term *term, char **cmd, int c, int i);
int				handler_dollar_dou(t_term *term, char c);
int				handler_dollar_sing(t_term *term, char c);

unsigned int	numbletter_orig(char const *s, char c);

void			ft_export(t_term *term, char **cmd);

void 			ft_matrixcopy(char ***cp_matrix, char **matrix);
int				ft_matrixlen(char **cmd);
int				ft_matrix_find_i_line(char **matrix, char *line_to_find);
void 			ft_matrixprint(char **matrix);
void 			ft_matrixfree(char **matrix);
void			ft_matrix_add(char ***matrix, char *line_to_add);
void			ft_matrix_remove(char ***matrix, char *line_to_rem);
void 			ft_matrix_remove_w(t_term *term, char *cmd, char del, int no_del);

char			*ft_realloc(char *path, char *cmd);

void			ft_exec_echo(char **cmd);
void			ft_exec_pwd(char **cmd);
void    		ft_exec_cd(t_term *term, char **cmd);
void 			ft_export(t_term *term, char **cmd);
//redirections

int				ft_nredir_count(char *line, char *c);
int				get_next_line(char **line);
char			*ft_realloc2(char *line, char c);
int				ft_isredir(char c);
int				ft_checkredirline(t_term *term, int x);
int				ft_manageredir(t_term *term, char ***cmd);
int 			ft_str_nredir_count(int x, char **cmd, char *c);
char			**ft_special_realloc(char **cmd);
int				ft_check_builtin(char **cmd);
int				ft_redir_imput(t_term *term, char ***cmd);
void			ft_quoteclean(char ***cmd);
int				ft_check_specialcase(char ***cmd);
char			*ft_remove_char(char *str, int pos);

void			rl_replace_line(const char *, int);
int				ft_control_env(char **cmd);
void			ft_putstr_fd(char *s, int fd);

//signals

void 			handle_signals(int sig);
void   			sigint_father(int sig);
void   			sigquit_child(int sig);
void			sigint_child(int sig);

char			*ft_itoa(int n);
int				ft_strchr_mod(const char *s, int c, int skip);
void			ft_print_minishell();
int				ft_isspace(char *str);

#endif
