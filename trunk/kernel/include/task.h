#include <regs.h>
#define SYSLEVEL 0xBA     //priviledge level defines
#define SUPERLEVEL 0xCA
#define USERLEVEL 0xEA

typedef struct
{
unsigned int id;
char name[20];//used by processes to find another processes id
}PID_T; // process id structure

typedef struct
{
regs_t tregs;//task's register's states
PID_T pid;//task id
unsigned char priv; //privilegde level
}task_t;// structure of a task entry
