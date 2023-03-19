DOXY_EXEC_PATH = /home/kopi/GitHub/Emath
DOXYFILE = /home/kopi/GitHub/Emath/doxygen.conf
DOXYDOCS_PM = /home/kopi/GitHub/Emath/./doc/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = /home/kopi/GitHub/Emath/./doc/perlmod/DoxyStructure.pm
DOXYRULES = /home/kopi/GitHub/Emath/./doc/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
