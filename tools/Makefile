TOOLS = clcc clcd clct



all: $(TOOLS)



$(TOOLS):
	cd $@ && make all

clean:
	for e in $(TOOLS) ; do (cd $$e && make clean) ; done

distclean:
	for e in $(TOOLS) ; do (cd $$e && make distclean) ; done



.PHONY: $(TOOLS)
