#Global compilation

all: src doc

src:
	$(MAKE) -C src

doc:
	$(MAKE) -C doc

test:
	$(MAKE) -C tests test

.PHONY: all clean src doc test clean_test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C doc clean

clean_test: 
	$(MAKE) -C tests clean
