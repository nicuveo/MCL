include Makefile.rules



# VARS

PROJ = mcl



# MAIN

all: run analysis coverage

run:
	@./test run      $(TESTS)

analysis:
	@./test analyse  $(ANALYSE_OPTS) $(CFIL)

coverage:
	@./test coverage $(COVERAGE_OPTS) $(COVERAGE_OUT) $(TESTS)



# CLEAN

clean:
	for e in $(TESTS) ; do (cd $$e && make clean) ; done
	rm -Rfv */cov.info analysis.log coverage.log test.log coverage.info $(COVERAGE_OUT)

distclean:
	for e in $(TESTS) ; do (cd $$e && make distclean) ; done
	rm -f Makefile.rules default/Makefile.rules



# SPECIALS

.PHONY: $(TESTS)
