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


void mkdirPamUsb(){

    struct stat st = {0};//0 diretorio inexiste, -1 existente

	if (stat("/etc/pam.d/pam.usb", &st) == -1) {
		if(mkdir("/etc/pam.d/pam.usb", 0700) == 0){
            printf("\nDirectory created successfully: /pam.usb");
		}else{
            printf("\nError creating directory: /pam.usb");
        }
	}else{
            printf("\nExisting Directory: /pam.usb");
    }
}

void makeFileSerial(){
    FILE *pdrive_serial;

    pdrive_serial = fopen("/etc/pam.d/pam.usb/usb.serial", "a");

    if (pdrive_serial == NULL){
        printf("\nError creating serial file.");
    }
    else{
        printf("\nSerial file created successfully.");
    }
}

void makeFileLogin(){
    FILE *login;

    login = fopen("/etc/pam.d/pam.usb/login", "a");

    if (login == NULL){
        printf("\nError creating login history file");
    }
    else{
        printf("\nLogin history file created successfully.");
    }
}

void addDevice( char nome[256] ){
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

    buf[len - 1] = 0;

    FILE *file;

        //Abrindo o arquivo (tipo de abertura "w")
        file = fopen("/etc/pam.d/pam.usb/usb.serial", "w");

        //Verificando a criação do arquivo
        if(file == NULL)
        {
        printf("\nError opening file!");
        }

        //Armazenando a string no arquivo
        fprintf(file, "%s", buf);

        fclose(file);

        puts("\nDevice successfully registered.");

}

int main(int argc, char *argv[]){
    system("clear");

    puts("\n\nFirst, make sure the Pendrive is connected.");
    puts("\nIf USB device is not found, the installation program will exit. ");
    system("read -p \"\nPress enter to continue...\" foo");

    system("clear");

    puts("\n----------------------- Starting installation ----------------------------\n");
    sleep(1);

    puts("\nCreating module configuration directories: ");
    puts("   '/etc/pam.d/pam.usb'");
    puts("   '/etc/pam.d/pam.usb/login'");
    mkdirPamUsb();
    sleep(1);

    puts("\nCreating file that stores serials: ");
    puts("   '/etc/pam.d/pam.usb'");
    puts("   '/etc/pam.d/pam.usb/login'");
    makeFileSerial();
    makeFileLogin();

    char nome[100];

    puts("\nCreating first released pendrive: ");

    addDevice(nome);

    system("read -p \"Press enter to continue...\" foo");
}
