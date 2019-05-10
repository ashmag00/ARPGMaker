GAME = alec_demo.py

.PHONY: build clean

build:
	touch extend.cpp; rm -f ARPGMaker.cpython-37m-x86_64-linux-gnu.so; python3.7 setup.py build; mv build/lib.linux-x86_64-3.7/ARPGMaker.cpython-37m-x86_64-linux-gnu.so .;

clean:
	rm -f ARPGMaker.cpython-37m-x86_64-linux-gnu.so;

run:
	python3.7 $(GAME)