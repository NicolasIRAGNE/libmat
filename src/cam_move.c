/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:42:57 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 16:02:24 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void    cam_move_forward(cam_t *cam, float speed)
{
    vec3 tmp;

    tmp.x = cam->orientation.x * speed;
    tmp.y = cam->orientation.y * speed;
    tmp.z = cam->orientation.z * speed;
    cam->pos = vec3_add(&cam->pos, &tmp);
    cam->target = vec3_add(&cam->pos, &cam->orientation);
}

void    cam_move_backward(cam_t *cam, float speed)
{
    vec3 tmp;

    tmp.x = cam->orientation.x * speed;
    tmp.y = cam->orientation.y * speed;
    tmp.z = cam->orientation.z * speed;
    cam->pos = vec3_sub(&cam->pos, &tmp);
    cam->target = vec3_add(&cam->pos, &cam->orientation);
}

void    cam_move_right(cam_t *cam, float speed)
{
    vec3 tmp;

    tmp.x = cam->lateral.x * speed;
    tmp.y = cam->lateral.y * speed;
    tmp.z = cam->lateral.z * speed;
    cam->pos = vec3_sub(&cam->pos, &tmp);
    cam->target = vec3_add(&cam->pos, &cam->orientation);
}

void    cam_move_left(cam_t *cam, float speed)
{
    vec3 tmp;

    tmp.x = cam->lateral.x * speed;
    tmp.y = cam->lateral.y * speed;
    tmp.z = cam->lateral.z * speed;
    cam->pos = vec3_add(&cam->pos, &tmp);
    cam->target = vec3_add(&cam->pos, &cam->orientation);
}