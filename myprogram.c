#include "types.h"
#include "stat.h"
#include "user.h"
#define NULL ((void *)0)

int main (int argc , char *argv[]){
int a;

int *pi;
a=5;
pi=&a;
a=*pi;
pi=NULL;
printf(1,"\n \n \n NULL pointer valuie: %p \n \n \n" , *pi);
exit();
}


