pam_usb.o: pam_usb.c
	gcc -fPIC -lcurl -fno-stack-protector -c pam_usb.c

install: pam_usb.o
	gcc -fPIC -lcurl -fno-stack-protector -c pam_usb.c
	ld -lcurl -x --shared -o /lib64/security/pam.usb.so pam_usb.o
	sed -i "4s/^/	auth	  required  pam.usb.so\n/" /etc/pam.d/system-auth
	gcc create_file.c -o create_file
	gcc new_device.c -o new_device
	./create_file

uninstall:
	rm -f /lib64/security/pam.usb.so
	rm -rf /etc/pam.d/pam.usb
	sed -i '/pam.usb/d' /etc/pam.d/system-auth
	clear
	@echo "Successfully removed USB authentication module."

newdevice:
	./new_device
