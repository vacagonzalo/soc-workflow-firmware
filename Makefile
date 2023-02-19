.PHONY: all clean project test
all: project

project: tempScript.tcl
	xsct $<
	-rm $<

tempScript.tcl: scripts/project.tcl
	cp $< $@

test:
	ceedling test:all

help:
	@echo "project   - create and build the project files"
	@echo "test      - run all Ceedling tests"
	@echo "clean     - delete all artifacts"

clean:
	-rm -r project-files .Xil build tempScript.tcl
