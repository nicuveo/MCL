include Makefile.rules



# VARIABLES

OBJS  = $(notdir $(CFIL:.cc=.o))
DEPS  = $(notdir $(CFIL:.cc=.d))



# MAIN

all: $(EXE)

clean: do_clean

distclean: do_distclean



# CLEAN

do_clean:
	rm -fv $(OBJS) $(EXE) $(LIBA) $(LIBSO) $(DYLIB) $(DEPS)

do_distclean: do_clean
	rm -fv Makefile.rules



# COMPIL

$(EXE): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(OBJS):
	$(CC) $(CFLAGS) -M $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) $(CFLAGS) -c $< -o $@



# SELF

sinclude $(DEPS)

dependency_rule = $(notdir $(1:.cc=.o)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))
