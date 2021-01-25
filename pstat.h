#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

extern struct pstat {
    int num_processes;
    int inuse[NPROC];   // whether this slot of the process table is in use (1 or 0)
    int pids[NPROC];       
    int ticks[NPROC];       // ticks = number of times process has been scheduled
    int tickets[NPROC];     // tickets = number of tickets set by settickets()
}pstat;

#endif // _PSTAT_H_