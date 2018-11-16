all:
	gcc w48phpcmd.c -o w48phpcmd

install-all:
	chown root w48phpcmd
	chmod u=rwx,go=xr,+s w48phpcmd
	cp w48phpcmd /usr/sbin/

build-rpi:
	/opt/cross-pi-gcc/bin/arm-linux-gnueabihf-gcc w48phpcmd.c -o w48phpcmd

clean:
	rm -f *.deb w48phpcmd