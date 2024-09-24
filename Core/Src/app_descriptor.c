/*
 * app_descriptor.c
 *
 *  Created on: 2024年9月23日
 *      Author: m2640
 */
#include "main.h"

__IO const app_descriptor ad __attribute__((used, section(".app_descriptor"))) =
{
	.sig = APP_DESCRIPTOR_SIG,
	.image_size = USER_FLASH_SIZE
};

