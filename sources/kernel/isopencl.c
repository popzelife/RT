/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isopencl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 01:31:11 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/09 22:06:30 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		kernel_isopencl(void)
{
	cl_uint			i;
	cl_device_id	*devices;
	cl_uint			num_devices;
	char			buf[128];

	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
	devices = malloc(sizeof(cl_device_id) * num_devices);
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);
	i = 0;
	while (i < num_devices)
	{
		clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 128, buf, NULL);
		ft_printf("Device %s supports ", buf);
		clGetDeviceInfo(devices[i], CL_DEVICE_VERSION, 128, buf, NULL);
		ft_printf("%s\n", buf);
		++i;
	}
	ft_printf("\n");
	free(devices);
}
