/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:40:47 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 15:50:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

vec3  vec3_normalize(vec3 *v)
{
    vec3	ret;
    float	len;

    len = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    ret.x = v->x / len;
    ret.y = v->y / len;
    ret.z = v->z / len;
    return (ret);
}