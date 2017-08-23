/*
 * Aim  : Create Hello World Module
 * Date : July-30-2017
 * File : atclib_task_5.c
 * Author : atclib
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

static int atclib_probe(struct usb_interface *interface,
		const struct usb_device_id *id)
{
	pr_debug("[atclib-5] :USB keyboard plugged in !\n");
	return 0;
}

static void atclib_disconnect(struct usb_interface *interface)
{
	pr_debug("[atclib-5] USB keyboard disconnected.\n");
}

static const struct usb_device_id id_table[] = {
	{USB_INTERFACE_INFO
	(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
	USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{},
};

MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_driver atclib_driver = {
	.name = "atclib-usb",
	.probe = atclib_probe,
	.disconnect = atclib_disconnect,
	.id_table = id_table,
};

static int __init atclib_init(void)
{
	pr_debug("[atclib-5] : atclib init called. !\n");
	return usb_register(&atclib_driver);
}

static void atclib_exit(void)
{
	pr_debug("[atclib-5] : Dieing usb atclib !\n");
	usb_deregister(&atclib_driver);
}

module_init(atclib_init);
module_exit(atclib_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("894e26c7d25d");
MODULE_DESCRIPTION("atclib task-5");
