/*
 * File : atclib_task6.c
 * Author : atclib
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>
#include <linux/slab.h>

#define DRIVER_NAME "eudyptula"
#define ATCLIB_ID "894e26c7d25d"

#define ATCLIB_ID_LEN 13

static ssize_t atclib_misc_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
	char *atclib_str = ATCLIB_ID;

	return simple_read_from_buffer(buf, count, ppos, atclib_str,
			strlen(atclib_str));

}

static ssize_t atclib_misc_write(struct file *file, const char __user *buf,
				 size_t count, loff_t *ppos)
{
	char *atclib_str = ATCLIB_ID;
	int rc;

	char *msg = kmalloc(count + 1, GFP_KERNEL);

	if (!msg)
		return -ENOMEM;

	if (strlen(atclib_str) != count-1)
		return -EINVAL;

	rc = simple_write_to_buffer(msg, count, ppos, buf,
			count);

	if (rc != count) {
		kfree(msg);
		return rc >= 0 ? -EIO : rc;
	}

	if (strncmp(msg, atclib_str, strlen(atclib_str)) != 0)
		return -EINVAL;

	return count;
}

static const struct file_operations atclib_misc_fops = {
	.owner = THIS_MODULE,
	.read = atclib_misc_read,
	.write = atclib_misc_write,
};

static struct  miscdevice atclib_misc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name  = DRIVER_NAME,
	.fops = &atclib_misc_fops,
};

static int atclib_init(void)
{
	int rc = 0;

	pr_debug("[atclib-6] : Hello misc char device !\n");
	rc = misc_register(&atclib_misc_device);
	return 0;
}

static void atclib_exit(void)
{
	pr_debug("[atclib-6] : Dieing atclib !\n");
	misc_deregister(&atclib_misc_device);
}

module_init(atclib_init);
module_exit(atclib_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("894e26c7d25d");
MODULE_DESCRIPTION("atclib task-6");
