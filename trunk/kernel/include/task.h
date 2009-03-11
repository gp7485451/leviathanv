#include <regs.h>

typedef struct
{
regs_t tregs;//task's register's states
unsigned int id;//task id
unsigned int priority;
unsigned int nice;
}task_t;// structure of a task entry
