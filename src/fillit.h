/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:07:25 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 22:35:50 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 21
# define VAL_SYMBOLS(ch) (ch != '.' && ch != '\n' && ch != '#')
# include <fcntl.h>
# include "libft.h"

typedef struct	s_coord
{
	char			x;
	char			y;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_tetr
{
	struct s_coord	*coord;
	char			alph;
	struct s_tetr	*next;
}				t_tetr;

typedef struct	s_mapsize
{
	char		**map;
	int			size;
	char		alph;
}				t_mapsize;

void			error(t_tetr *tetr, char **mas);
void			free_map(char **map);
void			free_lst(t_tetr *tetr);
void			print_map(char **map);
void			tetradd(t_coord *coord, char alph, t_tetr **alst);
void			read_map(t_tetr *tetr, int count_tetr);
int				input(int fd, t_tetr **tetr);
int				coordadd(char x, char y, t_coord **alst);
int				recursive_map(char **map, int size, t_tetr *tetr);

int				check_strings(char *buf);
int				check_newline(char *buf);
int				check_string(char *buf, int string_number);
int				validate(char *buf, int bt);
int				check_hash(char *buf, int bt);

#endif
