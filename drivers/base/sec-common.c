#include <linux/device.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/sec-common.h>

struct class *sec_class;
EXPORT_SYMBOL(sec_class);

static int __init rhea_class_create(void)
{
	sec_class = class_create(THIS_MODULE, "sec");
	if (IS_ERR(sec_class)) {
		pr_err("Failed to create class(sec)!\n");
		return PTR_ERR(sec_class);
	}

	return 0;
}

subsys_initcall(rhea_class_create);

