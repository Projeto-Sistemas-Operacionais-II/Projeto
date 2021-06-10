#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>

int main()
{
    system("clear");

    struct tm *date_time;
    time_t segundos;
    time(&segundos);
    date_time = localtime(&segundos);

    ssize_t len;

    char buf[256], *p;
    char buf2[256];
    int i;

    len = readlink("/sys/block/sdb", buf, 256);

    buf[len] = 0;

    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }

    strcat(buf2, "/serial");

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
    }

    buf[len] = 0;

    FILE *file;

        //Abrindo o arquivo (tipo de abertura "a")
        file = fopen("/etc/pam.d/pam.usb/usb.serial", "a");

        //Verificando a cria��o do arquivo
        if(file == NULL)
        {
        printf("nError opening file!");
        }

        //Armazenando a string no arquivo
        fprintf(file, "\n%s", buf);

        fclose(file);

        puts("\nDevice registered successfully.\n\n");
}
