#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x92997ed8, "_printk" },
	{ 0x24aec75a, "cdev_init" },
	{ 0x87efb320, "cdev_add" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xe43bdf80, "class_create" },
	{ 0x9defab29, "cdev_del" },
	{ 0x37ca1390, "device_create" },
	{ 0xaa1fdc8, "class_destroy" },
	{ 0xae806c1a, "device_destroy" },
	{ 0x4f6a48c4, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2880B0F80D938F04F1EB3B7");
