#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

int main(int argc , char *argv[]){
    int tickets ;
    int pid ;
    struct pstat p ;
    if(argc < 2){
        printf(2,"Usage : arguments needed!\n");
        exit();
    }
    tickets = atoi(argv[1]);
    if(tickets < 1 || tickets > 200){
        printf(2,"Invalid tickets (1-200)!\n");
        exit();
    }
    cps(); 
    pid = fork();
    if(pid < 0){
        printf(1,"forking faild!\n");
    }
    else if(pid > 0){
        cps(); 

        wait();
        printf(2,"Parent %d creating child %d and waited for it\n ",getpid(),pid);
        
    }
    else
    {
        printf(2,"Child %d executing------\n",getpid());
        settickets(tickets);
        printf(2,"%d tickets are added\n",tickets);
        getprocessesinfo(&p) ;
        printf(1, "%d running processes\n", p.num_processes);
        printf(1, "PID\tTICKETS\tTICKS\n");
        for (int i = 0; i < p.num_processes; ++i) {
        printf(1, "%d\t%d\t%d\n", p.pids[i], p.tickets[i], p.ticks[i]);
    }
    }
    
    exit();
}