/*
 * Aim  : Create Hello World Module
 * Date : March-2-2017
 * File : atclib_task1.c
 * Author : atclib
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int atclib_init(void)
{
	pr_info("[atclib] : Hello World !\n");
	return 0;
}

static void atclib_exit(void)
{
	pr_info("[atclib] : Dieing atclib !\n");
}

module_init(atclib_init);
module_exit(atclib_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("894e26c7d25d");
MODULE_DESCRIPTION("atclib task-1");
