#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "rand.h"
#include "pstat.h"
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int sys_settickets(void)
{ 
//  int num = random_at_most(100);
//  settickets(num);
//   if(num==0)return -1;
//   else return 0;
  int n;
  if(argint(0, &n) < 0) {
    return -1;
  }
  else {
    settickets(n);
  }
  return 0;
}
int sys_mprotect((void) {

    int addr;
  int  len = 0;
   if(argint(0,&addr)<0 ||argint (1,&len)<0)
        return -1;
   return mprotect((void *)addr, len);
}
int sys_munprotect((void) {

        int addr;
        int len = 0;
       if(argint(0,&addr)<0 ||argint (1,&len)<0)
                return -1;
        return munprotect((void *)addr, len);
}

int
sys_getprocessesinfo(void){
  struct pstat *p;
    if (argptr(0, (char **)&p, sizeof(struct pstat)) < 0)
        return -1;
    getprocessesinfo(p);
  return 0;
}
