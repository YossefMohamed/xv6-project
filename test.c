#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

void print_info(struct pstat p);
int main(int argc , char *argv[]){
    int tickets ;
    int pid ;
    int x , z ;
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
    
    pid = fork();
    if(pid < 0){
        printf(1,"forking faild!\n");
    }
    else if(pid > 0){ 
         print_info(p);
        wait();
        printf(2,"Parent %d creating child %d and waited for it\n ",getpid(),pid);
        
    }
    else
    {
        printf(2,"Child %d executing------\n",getpid());
        settickets(tickets+5);
        printf(2,"%d tickets are added\n",tickets+5);
       for(z = 0; z < 4000000000; z+=1){
            x = x + 3.14*89.64; //Useless calculation to consume CPU Time
            break;
        }
        print_info(p);
    }
    
    
    exit();
}
void print_info(struct pstat p){
    getprocessesinfo(&p) ;
    printf(1, "%d running processes\n", p.num_processes);
    printf(1, "PID\tTICKETS\tTICKS\tTIMES\n");
    for (int i = 0; i < p.num_processes; ++i) {
        printf(1, "%d\t%d\t%d\t%d\n", p.pids[i], p.tickets[i], p.ticks[i],p.run[i]);
    }
}