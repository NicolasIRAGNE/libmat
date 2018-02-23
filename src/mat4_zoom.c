/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:14:48 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 16:01:13 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void	mat4_zoom(mat4 *m, vec3 *v)
{
	mat4	zoom;
	mat4	tmp;

    zoom = mat4_new();
    zoom[0] = v->x; zoom[4] = 0.f;  zoom[8] = 0.f;   zoom[12] = 0.f;
    zoom[1] = 0.f;  zoom[5] = v->y; zoom[9] = 0.f;   zoom[13] = 0.f;
    zoom[2] = 0.f;  zoom[6] = 0.f;  zoom[10] = v->z; zoom[14] = 0.f;
    zoom[3] = 0.f;  zoom[7] = 0.f;  zoom[11] = 0.f;  zoom[15] = 1.f;
	tmp = *m;
    *m = mat4_mult(zoom, *m);
	free(tmp);
	free(zoom);
}
