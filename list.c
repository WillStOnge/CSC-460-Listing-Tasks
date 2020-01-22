#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
	struct task_struct *task;

	pr_info("Inserting listing tasks module\n");	
	pr_info("Current tasks:\n");
	pr_info("  PID\t Name\t\t\tState");

	for_each_process(task)
	{
		pr_info("%4d\t%-20s\t%ld\n", task->pid, task->comm, task->state);
	}
	
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
	pr_info("Removing listing tasks module\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lists all current tasks on the operating system.");
MODULE_AUTHOR("Will St. Onge, stongew1@nku.edu");
MODULE_VERSION("1.0");
