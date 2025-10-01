# Documentation Compilation
DOXYGEN = doxygen
DOXYFILE = Doxyfile
DOC_DIR = doc/html doc/latex

.PHONY: doc clean_doc

# Target to generate the documentation
doc:
	@echo "Generating Doxygen documentation..."
	$(DOXYGEN) $(DOXYFILE)

# Clean the generated documentation
clean:
	@echo "Cleaning Doxygen documentation..."
	rm -rf $(DOC_DIR)