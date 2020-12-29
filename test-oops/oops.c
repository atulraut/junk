/*
 * Aim  : Create Hello World Module
 * Date : Feb-2-2018
 * File : oops.c
 * Author : atclib
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static void create_oops(void);

static void create_oops(void) {
        *(int *)0 = 0;
}
 
static int __init my_oops_init(void) {
        printk("oops from the module\n");
        create_oops();
       return (0);
}
static void __exit my_oops_exit(void) {
        printk("Goodbye world\n");
}
 
module_init(my_oops_init);
module_exit(my_oops_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("atclib oops");
