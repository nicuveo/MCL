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
	rm -fv *.out *.err Makefile.rules


# COMPIL

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(OBJS):
	$(CC) $(CFLAGS) -M $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) $(CFLAGS) -c $< -o $@


# SELF

sinclude $(DEPS)

dependency_rule = $(notdir $(1:.cc=.o)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))
