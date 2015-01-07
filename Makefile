# MAIN

PROJ    = mcl
EXE     = bin/$(PROJ)
LIBA    = bin/lib$(PROJ).a
LIBSO   = bin/lib$(PROJ).so
DYLIB   = bin/lib$(PROJ).dylib

$(PROJ): all

sinclude Makefile.rules
sinclude Makefile.custom



# VARIABLES

OBJS  = $(addprefix $(BUILD_DIR)/, $(notdir $(CFIL:.cc=.o)))
DEPS  = $(addprefix $(BUILD_DIR)/, $(notdir $(CFIL:.cc=.d)))

CLEAN += '*~' '\#*' '.\#*' '.DS_Store' '.gdb_history' '*.stackdump' \
'.gdb_history' 'gmon.out' '*.dSYM'



# ALL

all: $(TARGETS)

install: all
	@if [ -x ./install ] ; then ./install "$(PREFIX)" ; else		\
	    test -r "$(EXE)"   && install -v	    "$(EXE)"   "$(PREFIX)/bin";	\
	    test -r "$(LIBA)"  && install -v -m 644 "$(LIBA)"  "$(PREFIX)/lib";	\
	    test -r "$(LIBSO)" && install -v -m 644 "$(LIBSO)" "$(PREFIX)/lib";	\
	    test -r "$(DYLIB)" && install -v -m 644 "$(DYLIB)" "$(PREFIX)/lib";	\
	    find include -type f \! -path '*.svn*' 			        \
                -exec install -v -m 644 "{}" -D "$(PREFIX)/{}" \;;		\
	fi



# COMPIL

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(LIBA): $(OBJS)
	ar -scr $(LIBA) $(OBJS)

$(LIBSO): $(OBJS)
	$(CC) -shared $(OBJS) $(LDFLAGS) -o $(LIBSO)

$(DYLIB): $(OBJS)
	$(CC) -dynamiclib $(OBJS) $(LDFLAGS) -o $@

$(OBJS):
	$(CC) $(CFLAGS) -M $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) $(CFLAGS) -c $< -o $@



# DISPATCH

sub_call_func = (cd ./$1 && $2)
sub_call_rule = $(call sub_call_func,$1,$(MAKE) $2)
define sub_make_rule
$1: all
	$(call sub_call_rule,$1,all)
endef

$(foreach sub,$(SUB_DIRS),$(eval $(call sub_make_rule,$(sub))))


clean: do_clean
	$(foreach sub,$(SUB_DIRS),$(call sub_call_rule,$(sub), clean);)

distclean: do_distclean
	$(foreach sub,$(SUB_DIRS),$(call sub_call_rule,$(sub), distclean);)



# CLEAN

do_clean:
	for f in ${CLEAN} ; do find . -name "$$f" | xargs rm -Rfv ; done
	rm -fv $(OBJS) $(EXE) $(LIBA) $(LIBSO) $(DYLIB) $(DEPS)

do_distclean: do_clean
	rm -Rfv doc/doxygen/* doc/coverage/* build/* bin/* Makefile.rules



# DOC

doc:
	./doc/input/regen
	doxygen Doxyfile

tarball:
	./scripts/tarball . $(PROJ)



# SELF

sinclude $(DEPS)

dependency_rule = $(BUILD_DIR)/$(notdir $(1:.cc=.o)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))

Makefile.rules:
	./configure $(CONFIGURE_ARGS)

conf:
	./configure $(CONFIGURE_ARGS)



# MISC

flower:
	@cat ./scripts/flower

todo:
	@./scripts/todo



# SPECIALS

.PHONY: conf todo flower doc $(SUB_DIRS)
