/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:45:48 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 16:03:51 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBMAT_H
# define LIBMAT_H
# include <stdlib.h>
# include <strings.h>
# include <math.h>

typedef struct s_vec2 vec2;
typedef struct s_vec3 vec3;
typedef struct s_vec4 vec4;
typedef struct s_cam cam_t;
typedef float* mat3;
typedef float* mat4;

struct  s_vec2
{
    float x;
    float y;
};

struct  s_vec3
{
    float x;
    float y;
    float z;
};

struct  s_vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct  s_cam
{
    float	phi;
	float	teta;
	vec3	orientation;
	vec3	vertical;
	vec3	lateral;
	vec3	pos;
	vec3	target;
};

mat3	mat3_new(void);
mat3	mat3_id_new(void);
mat3	mat3_mult(mat3 a, mat3 b);

mat4	mat4_new(void);
mat4	mat4_id_new(void);
mat4	mat4_mult(mat4 a, mat4 b);
mat4	mat4_perspective(float angle, float ratio, float near, float far);
void	mat4_zoom(mat4 *m, vec3 *v);
void	mat4_rotate(mat4 *mat, vec3 *v, float angle);
void	mat4_translate(mat4 *m, vec3 *v);

vec3	vec3_normalize(vec3 *v);
vec3	vec3_add(vec3 *u, vec3 *v);
vec3	vec3_sub(vec3 *u, vec3 *v);
vec3	vec3_cross(vec3 *u, vec3 *v);
float	vec3_dot(vec3 *u, vec3 *v);

mat4	cam_lookat(cam_t *cam);
void	cam_orient(cam_t *cam, int xrel, int yrel, float mult);
void	cam_move_up(cam_t *cam, float speed);
void	cam_move_down(cam_t *cam, float speed);
void	cam_move_right(cam_t *cam, float speed);
void	cam_move_left(cam_t *cam, float speed);
void	cam_settarget(cam_t *cam, vec3 *target);

#endif