all:
	c++ -o crypt crypt.cpp main.cpp

install:
	sudo cp crypt /usr/local/bin/

uninstall:
	sudo rm /usr/local/bin/crypt

clean:
	rm crypt

