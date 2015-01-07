include Makefile.rules


# VARIABLES

EXE   = test
OBJS  = $(notdir $(CFIL:.cc=.o))
DEPS  = $(notdir $(CFIL:.cc=.d))


# MAIN

all: $(EXE)

clean:
	rm -fv $(OBJS) $(EXE) $(DEPS) *.o *.d gmon.out *.gcno *.gcno *.gcov *.gcda

distclean: clean
	rm -fv *.out *.err Makefile.rules sources.rules includes.hh


# COMPIL

includes:
	find ../../include -type f -iname "*.hh" \! -path ".*svn.*" | sed "s%../../include/\(.*\)%#include \"\1\"%" > includes.hh

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(OBJS):
	$(CC) $(CFLAGS) -M $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) $(CFLAGS) -c $< -o $@

test.o: test.cc includes


# SELF

sinclude $(DEPS)

dependency_rule = $(notdir $(1:.cc=.o)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))

.PHONY: sources.rules
