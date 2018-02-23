/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:14:36 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 16:01:03 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

static mat4   get_rot(vec3 *v, float angle)
{
    mat4	ret;
    float	c;
    float	s;

    s = sin(angle);
    c = cos(angle);
    ret = mat4_new();
    ret[0] = v->x * v->x * (1.0 - c) + c;
    ret[1] = v->x * v->y * (1.0 - c) + v->z * s;
    ret[2] = v->x * v->z * (1.0 - c) - v->y * s;
    ret[3] = 0.f;
    ret[4] = v->x * v->y * (1.0 - c) - v->z * s;
    ret[5] = v->y * v->y * (1.0 - c) + c;
    ret[6] = v->y * v->z * (1.0 - c) + v->x * s;
    ret[7] = 0.f;
    ret[8] = v->x * v->z * (1.0 - c) + v->y * s;
    ret[9] = v->y * v->z * (1.0 - c) - v->x * s;
    ret[10] = v->z * v->z * (1.0 - c) + c;
    ret[11] = 0.f;
    ret[12] = 0.f;
    ret[13] = 0.f;
    ret[14] = 0.f;
    ret[15] = 1.f;
    return (ret);
}

void    mat4_rotate(mat4 *mat, vec3 *v, float angle)
{
    mat4 mat_rot;
    mat4 tmp;

    mat_rot = get_rot(v, angle);
    tmp = *mat;
    *mat = mat4_mult(*mat, mat_rot);
	free(mat_rot);
    free(tmp);
}
