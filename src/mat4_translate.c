/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:36:35 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 15:43:43 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void    mat4_translate(mat4 *mat, vec3 *v)
{
    mat4 ret;
    mat4 tmp;

    tmp = *mat;
    ret = mat4_id_new();
    ret[12] = v->x;
    ret[13] = v->y;
    ret[14] = v->z;
    *mat = mat4_mult(*mat, ret);
	free(ret);
    free(tmp);
}