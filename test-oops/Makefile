CFLAGS_atclib_task_1.o = -DDEBUG

obj-m += oops.o 
KDIR := /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

all:
		$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
		$(MAKE) -C $(KDIR) M=$(PWD) clean
