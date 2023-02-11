DOXY_EXEC_PATH = /home/kopi/GitHub/Archived/EMath++
DOXYFILE = /home/kopi/GitHub/Archived/EMath++/doxygen.conf
DOXYDOCS_PM = /home/kopi/GitHub/Archived/EMath++/./doc/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = /home/kopi/GitHub/Archived/EMath++/./doc/perlmod/DoxyStructure.pm
DOXYRULES = /home/kopi/GitHub/Archived/EMath++/./doc/perlmod/doxyrules.make

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
