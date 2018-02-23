/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:47:08 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 15:51:17 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

vec3      vec3_sub(vec3 *u, vec3 *v)
{
    vec3 ret;

    ret.x = u->x - v->x;
    ret.y = u->y - v->y;
    ret.z = u->z - v->z;
    return (ret);
}