/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:59 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/03 13:52:12 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

// MISC
# define ESC 65307 //KEY_ESC
# define RESET 114 //KEY_R
# define PARALLEL 112
# define ISOMETRIC 105
# define SHIFT 65505 //KEY_SHIFT

// ZOOM
# define ZOOM_IN 4 //SCROLL_UP
# define ZOOM_OUT 5 //SCROLL_UP

// TRANSLATION
# define MOVE_UP 119 //KEY_W
# define MOVE_DOWN 115 //KEY_S
# define MOVE_LEFT 97 //KEY_A
# define MOVE_RIGHT 100 //KEY_D

// ROTATION
# define ROTATE_UP 65431 //NUMPAD_8
# define ROTATE_DOWN 65433 //NUMPAD_2
# define ROTATE_LEFT 65430 //NUMPAD_4
# define ROTATE_RIGHT 65432 //NUMPAD_6
# define ROTATE_Z_LEFT 65429 //NUMPAD_7
# define ROTATE_Z_RIGHT 65434 //NUMPAD_9

// COLOUR
# define DEFAULT_COLOUR 16777215
# define RED 16711680
# define BLUE 255
# define GREEN 65280

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coords
{
	int	x;
	int	y;
	int	z;
	int	colour;
}				t_coords;

typedef struct s_wf
{
	t_data	*canva;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		zoom;
	int		x; // position where the center of the wf will be
	int		y;
	int		pers;
}				t_wf;

typedef struct s_map
{
	int		altitude; // z axis
	int		colour; // colour code
}					t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}					t_mlx;

typedef struct s_bag
{
	t_map	**map;

	t_mlx	*mlx;
	t_wf	*og_wf;
	t_wf	*mod_wf;
	int		max_z;
	int		axis_len; // x axis
	int		ordinate_len; // y axis
	int		fd;
	char	*file;
}					t_bag;

/* init_bag.c */
void	get_fd(t_bag *bag);
void	create_map(t_bag *bag);
void	init_og_wf(t_bag *bag);
t_bag	*create_bag(char *file);
/* proc_map.c */
void	get_max_ordinates(t_bag *bag);
void	allocate_map(t_bag *bag);
void	process_line(t_bag *bag, char *line, int i);
void	create_wireframe(t_bag *bag, t_wf *wf);
/* hooks.c */
int		close_window(t_bag *bag);
int		hooks(int keycode, t_bag *bag);
int		mouse_hooks(int mouse_code, t_bag *bag);
void	copy_og_wf(t_bag *bag);
/* error.c */
void	ft_free(char **array);
void	deallocate(t_bag *bag);

#endif