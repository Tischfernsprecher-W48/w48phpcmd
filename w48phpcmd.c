#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[])  {


    int opt = 0;

    char *in_fname = NULL;
    char cmd[256];

    while ((opt = getopt(argc, argv, "r:s:d:x:")) != -1) {
        switch(opt) {
            case 'r':
                in_fname = optarg;
                sprintf(cmd, "service  %s restart",  in_fname);
                setuid (0);
                setgid(0);
                system(cmd);
                break;
            case 's':
                in_fname = optarg;
                sprintf(cmd, "/usr/sbin/asterisk -rx 'sip show peers' | grep %s | awk -F ' ' '{print $6 $7 $8}'",in_fname);
                setuid (0);
                setgid(0);
                system(cmd);
                break;
            case 'd':
                in_fname = optarg;
                sprintf(cmd, "/usr/sbin/w48conf %s",in_fname);
                setuid (0);
                setgid(0);
                system(cmd);
                break;
            case 'x':
                in_fname = optarg;
                sprintf(cmd, "%s",in_fname);
                setuid (0);
                setgid(0);
                system(cmd);
                break;
            case '?':
                if (optopt == 'i') {
                    printf("\nMissing input option");
                } else {
                     printf("\nInvalid option");
                }
                break;
         }
     }

return 0;
}

