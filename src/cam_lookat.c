/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:57:50 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 16:03:06 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

mat4  cam_lookat(cam_t *cam)
{
	mat4	view = mat4_new();
	vec3	tmp;
	vec3 	fwd;
	vec3 	side;

	fwd = vec3_sub(&cam->pos, &cam->target);
	fwd = vec3_normalize(&fwd);
	side = vec3_cross(&cam->vertical, &fwd);
	side = vec3_normalize(&side);
	tmp = vec3_cross(&fwd, &side);
	view[0] = side.x;
	view[1] = tmp.x;
	view[2] = fwd.x;
	view[3] = 0.f;
	view[4] = side.y;
	view[5] = tmp.y;
	view[6] = fwd.y;
	view[7] = 0.f;
	view[8] = side.z;
	view[9] = tmp.z;
	view[10] = fwd.z;
	view[11] = 0.f;
	view[12] = -vec3_dot(&side, &cam->pos);
	view[13] = -vec3_dot(&tmp, &cam->pos);
	view[14] = -vec3_dot(&fwd, &cam->pos);
	view[15] = 1.f;
    return (view);
}
