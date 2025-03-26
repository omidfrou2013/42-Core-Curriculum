/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:04:30 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/18 22:09:42 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WD_NUM 1000
# define WD_LEN 1000
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define IMG_PXL 50
# define WND_NAME "so_long"

typedef struct s_character
{
	int			y;
	int			x;

}				t_character;

typedef struct s_texture
{
	void		*floor;
	void		*item;
	void		*barrier;
	void		*goal;
	void		*char_left1;
	void		*char_right1;
	void		*char_up1;
	void		*char_down1;
	void		*char_left2;
	void		*char_right2;
	void		*char_up2;
	void		*char_down2;
	void		*foe;
	void		*empty;
	void		*collectible;
	void		*exit;
	void		*wall;
	void		*player1;
	void		*player_right1;
	void		*player_right2;
	void		*player_up1;
	void		*player_up2;
	void		*player_down2;
	void		*player_down1;
	void		*enemy;
	void		*player_left1;
	void		*player_left2;

}				t_texture;

typedef struct s_game
{
	int			fd;
	char		*line;
	char		**matrix;
	char		**backup;
	char		*filepath;
	char		**array;
	char		**grid;
	char		*map_name;
	char		*map_data;
	char		*map_file;
	int			move_count;
	int			exit_count;
	int			collect_count;
	int			player_count;
	int			has_won;
	int			exit_pos;
	int			rows;
	int			cols;
	int			collectibles;
	int			height;
	int			width;
	int			exits;
	int			items;
	int			items_left;
	int			exits_left;
	int			players;
	int			completed;
	int			steps;
	int			moves;
	int			map_fd;
	void		*mlx;
	void		*window;
	t_texture	textures;
	t_character	character;
	t_texture	img;

}				t_game;

void			validate_grid(t_game *grid);
void			parse_grid(t_game *grid);
void			load_textures(t_game *grid);
void			draw_grid(t_game *grid);
int				handle_input(int keycode, t_game *grid);
void			error_matrix(t_game *grid);
void			error_filepath(void);
void			error_boundary(t_game *grid);
void			error_file_access(void);
void			error_dimensions(t_game *grid);
void			error_grid_elements(t_game *grid);
void			error_blank_line(t_game *grid);
void			error_structure(void);
int				release_memory(char **ptr, int i);
int				handle_keypress(int keycode, t_game *game);
void			exit_and_cleanup(t_game *grid);
int				release_matrix(char **ptr, int i);
void			move_upward(t_game *grid);
void			move_leftward(t_game *grid);
void			move_downward(t_game *grid);
void			move_rightward(t_game *grid);
void			load_character_textures(t_game *grid);
void			display_victory(t_game *grid);
int				exit_game(t_game *grid);
void			show_step_count(t_game *grid);
void			initialize_grid(t_game *grid, char **av);
void			verify_valid_path(t_game *grid);
void			locate_character(t_game *grid);
void			error(const char *msg);
void			move_down(t_game *game);
void			move_up(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
int				bfs(t_game *game, int **visited, int x, int y);
void			load_map(t_game *game);
void			check_valid_path(t_game *game);
void			grid_free(char **grid, int rows);
int				close_game(t_game *game);
void			error_openfile(void);
void			render_map(t_game *map);
void			render_map2(t_game *map);

void			print_movements(t_game *map);
void			init_game_map(t_game *game, char **argv);
int				main(int ac, char **argv);
void			load_images(t_game *game);
void			validate_filename1(t_game *game);
void			validate_filename(t_game *game);
void			validate_map_elements(t_game *game);
void			validate_map_elements(t_game *game);
void			allocate_visited(int ***visited, int height, int width);
void			free_visited(int **visited, int height);
void			validate_map_size(t_game *game);
void			validate_map_size2(t_game *game);
void			validate_walls(t_game *game);
void			validate_walls2(t_game *game);
void			validate_collectible_count(int collectible);
void			validate_exit_count(int exit_count);
void			count_map_elements(t_game *game, int *player, int *collectible,
					int *exit);
void			validate_player_count(int player);
char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *c);
void			ft_bzero(void *a, size_t len);
void			*ft_calloc(size_t num, size_t size);
void			bfs_initialize_visited(t_game *game, int **visited, int x,
					int y);
int				get_nx(int cx, int dir);
int				get_ny(int cy, int dir);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strnstr(const char *str, const char *substr, size_t length);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strdup(const char *s);
char			**ft_split(const char *s, char c);

#endif
