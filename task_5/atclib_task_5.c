/*
 * Aim  : When any USB keyboard is plugged in, the module will be
 *        automatically loaded by the correct userspace hotplug tools (which
 *        are implemented by depmod / kmod / udev / mdev / systemd, depending
 *        on what distro you are using.)
 * Date : Sept-24-2017
 * File : atclib_task_5.c
 * Author : atclib
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

/* the driver registers its driver object with the USB subsystem and
 * later uses vendor and device identifiers to tell if tis hardware has
 * been installed. The struct usb_device_id structure provided a list
 * of different types of USB devices that htis driver supports.
 * Trick: Pointer to the struct usb_device_id table that contrains
 * a list of all of the different kinds of USB devices this driver can accept.
 * If this variable is not set, the probe function callback int the USB
 * driver is never called. If you want your driver always to be called
 * for everyUSB device in the system, create a entry that sets only the
 * driver_info field.
 */
static const struct usb_device_id id_table[] = {
		{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD)},
		{}
};

MODULE_DEVICE_TABLE(usb, id_table);

static int __init atclib_init(void)
{
	pr_debug("[atclib-5] : atclib init called. !\n");
	return 0;
}

static void atclib_exit(void)
{
	pr_debug("[atclib-5] : Dieing usb atclib !\n");
}

module_init(atclib_init);
module_exit(atclib_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("894e26c7d25d");
MODULE_DESCRIPTION("atclib task-5");
