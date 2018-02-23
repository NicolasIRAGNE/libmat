/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_perspective.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:27:31 by niragne           #+#    #+#             */
/*   Updated: 2018/02/23 15:39:19 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

mat4	mat4_perspective(float angle, float ratio, float near, float far)
{
	mat4	ret;
	float	t;

	t = tanf(angle / 2.f);
	ret = mat4_new();
	ret[0] = 1.f / (t * ratio);
	ret[1] = 0.f;
	ret[2] = 0.f;
	ret[3] = 0.f;
	ret[4] = 0.f;
	ret[5] = 1.f / t;
	ret[6] = 0.f;
	ret[7] = 0.f;
	ret[8] = 0.f;
	ret[9] = 0.f;
	ret[10] = (-near - far) / (far - near);
	ret[11] = -1.f;
	ret[12] = 0.f;
	ret[13] = 0.f;
	ret[14] = -2.f * far * near / (far - near);
	ret[15] = 0.f;
	return (ret);
}
