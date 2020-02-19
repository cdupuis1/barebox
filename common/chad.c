#include <printk.h>
#include "chad.h"

void chad_main(void)
{
	pr_info("Hello from %s.\n", __func__);
}
