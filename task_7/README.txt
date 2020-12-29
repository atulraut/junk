Task :
Just when you think this challenge is all about writing kernel code,
this task is a throwback to your second one.  Yes, that's right,
building kernels.  Turns out that's what most developers end up doing:
tons and tons of rebuilds, not writing new code.  Sad, but it is a good
skill to know.

The task this round is:
  - Download the linux-next kernel for today.  Or tomorrow, just use
    the latest one.  It changes every day so there is no specific one
    you need to pick.  Build it.  Boot it.  Provide proof that you built
    and booted it.

What is the linux-next kernel?  Ah, that's part of the challenge.

For a hint, you should read the excellent documentation about how the
Linux kernel is developed in Documentation/development-process/ in the
kernel source itself.  It's a great read, and should tell you all you
never wanted to know about what Linux kernel developers do and how they
do it.

As always, please respond to this challenge with your id.  I know you
know what it is.  I'll not even include it this time, I trust you.
Don't make me feel that is a mistake.

1] Get local config file : 
cp /boot/config-4.2.0-19-generic .config
2] Download Linux Kernel Tree : 
git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/


Steps to build Linux Kernel Locally :
1. Download Linux Next :
https://www.kernel.org/doc/man-pages/linux-next.html
Ubuntu Grub -
https://askubuntu.com/questions/216398/set-older-kernel-as-default-grub-entry/216420#216420
Kernel Build : 
https://kernelnewbies.org/KernelBuild
https://askubuntu.com/questions/708937/autoconf-kernel-need-config-for-local-build
