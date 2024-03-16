/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:35:26 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/16 03:42:50 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

typedef struct s_render_data {
    t_fract  *vars;
} t_render_data;

typedef struct s_vars {
    void    *mlx;
    void    *win;
    double  min_x;
    double  max_x;
    double  min_y;
    double  max_y;
} t_vars;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#define MIN_X_PIXEL 0
#define MAX_X_PIXEL (WINDOW_WIDTH - 1)
#define MIN_Y_PIXEL 0
#define MAX_Y_PIXEL (WINDOW_HEIGHT - 1)

double	coordinate(int pos, int len, double min, double max)
{
	double	dis;
	double	res;
	double	p;

	dis = fabs(max - min);
	p = (double)pos / (double)len;
	res = min + (p * dis);
	return (res);
}
double scale_to_mandelbrot_x(int x)
{
    return coordinate(x, MAX_X_PIXEL + 1, -2, 2);
}

double scale_to_mandelbrot_y(int y)
{
    return coordinate(y, MAX_Y_PIXEL + 1, -2, 2);
}
int render_next_frame(void *render_data)
{
    t_render_data *data = (t_render_data *)render_data;
    return (0);
}
void    init(t_fract *fractal)
{
    t_render_data *render_data = malloc(sizeof(t_render_data));
    if (!render_data)
    {
        perror("malloc error");
        exit(1);
    }

    render_data->vars = fractal;

    fractal->connection = mlx_init();
    if (!fractal->connection)
    {
        perror("mlx_init error");
        exit(1);
    }

    fractal->window = mlx_new_window(fractal->connection,
                                      WIDTH, HEIGHT, fractal->title);
    if (!fractal->window)
    {
        perror("mlx_new_window error");
        exit(1);
    }

    fractal->img.image = mlx_new_image(fractal->connection,
                                        WIDTH, HEIGHT);
    if (!fractal->img.image)
    {
        perror("mlx_new_image error");
        mlx_destroy_window(fractal->connection, fractal->window);
        exit(1);
    }

    fractal->img.pixels = mlx_get_data_addr(fractal->img.image,
                                             &fractal->img.bpp,
                                             &fractal->img.llen,
                                             &fractal->img.endian);

    mlx_loop_hook(fractal->connection, render_next_frame, render_data);
    mlx_loop(fractal->connection);
    free(render_data); // Free the allocated memory after mlx_loop
}

int key_hook(int keycode, t_vars *vars)
{
    printf("Hello from key_hook!\n");
    if (keycode == 53) // 53 is the keycode for the Escape key
    {
        printf("Escape key pressed. Exiting...\n");
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}
int mouse_hook(int button, int x, int y, t_vars *vars)
{
    if (button == 1) // Check if left mouse button is clicked
    {
        // Print the pixel coordinates
        printf("Mouse clicked at pixel position: (%d, %d)\n", x, y);

        // Scale pixel coordinates to the Mandelbrot set's coordinate system
        double mandelbrot_x = scale_to_mandelbrot_x(x);
        double mandelbrot_y = scale_to_mandelbrot_y(y);
        printf("Equivalent Mandelbrot set coordinates: (%f, %f)\n", mandelbrot_x, mandelbrot_y);
    }
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
    mlx_mouse_hook(vars.win, mouse_hook, &vars); // Register mouse event handler
    mlx_key_hook(vars.win, key_hook, &vars);

    // for (int i = 0; i < 800; ++i)
    // {
    //     double mandelbrot_x = coordinate(i, 800, -2, 2);
    //     printf("%d -> %f\n", i, mandelbrot_x);
    // }

    mlx_loop(vars.mlx);
    return (0);
}
