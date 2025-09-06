/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:02:19 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 10:31:00 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

//#define WIDTH 1280
//#define HEIGHT 720

# define DEFAULT_DIRTY_SIZE 6
# define DIRTY_FRAME_TICKS 12

# define MAXITER 255 

# define ESCAPE		65307
# define LEFTARROW	65361
# define UPARROW		65362
# define RIGHTARROW	65363
# define DOWNARROW	65364
# define ESC 65307

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

typedef struct s_contxt
{
	void		*mlx;
	void		*win;
	long double	xoffset;
	long double	yoffset;
	int			mousex;
	int			mousey;
	long double	zoom;

	long double	c_r;
	long double	c_i;

	int			arrow_keys[4];

	void		*img;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	char		*buffer;
	t_rectangle	rectangle;
}				t_contxt;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

/*
	Minilibft
*/

int		parse(int argc, char **argv, t_contxt *contxt);

int		ft_strcmp(const char *s1, const char *s2);

double	ft_atod(char *str);

int		random32(void);

int		hex_to_int(char *str);

/*
	MLX Hooks
*/

void	key_down_hooker(int button, t_contxt *contxt);

int		loop_hooker(t_contxt *contxt);

int		mouse_hooker(int button, int x, int y, t_contxt *contxt);

int		key_hooker(int button, t_contxt *contxt);

/*
	Fractals
*/

int		mandelbrot(t_contxt *contxt, int x, int y);

int		julia(t_contxt *contxt, int x, int y);

int		tricorn(t_contxt *contxt, int x, int y);

/*
	MLX image utils
*/

void	set_pixel_color(t_contxt *contxt, int x, int y, int color);

void	draw_solid_rect(t_contxt *contxt, t_rectangle *rect);

void	draw_hollow_rect(t_contxt *contxt, t_rectangle *rect);
/*
	Math utils
*/

int		max(int i, int m);

int		min(int m, int i);

int		clamp(int i, int mi, int ma);

/*
	Palette
*/

void	generate_palette_linear(t_contxt *contxt, int mincolor, int maxcolor);

void	generate_palette_random(t_contxt *contxt);

/*
	Renderer
*/

void	render(t_contxt *contxt);

/*
	Tiny printf
*/

int		tprintf(char *format, ...);

#endif // FRACTOL_H
