# options

ifdef VERBOSE
N_OPTS = -v
endif


# release

R_OPTS = -DCMAKE_BUILD_TYPE=release -DCMAKE_INSTALL_PREFIX=$(PREFIX)

release:
	mkdir -p build/release
	cd build/release && cmake -G Ninja ../.. $(R_OPTS) && ninja $(N_OPTS)

install: release
	cd build/release && ninja $(N_OPTS) check && ninja $(N_OPTS) install


# debug

D_OPTS = -DCMAKE_BUILD_TYPE=debug

debug:
	mkdir -p build/debug
	cd build/debug && cmake -G Ninja ../.. $(D_OPTS) && ninja $(N_OPTS)

check: debug
	cd build/debug && ninja $(N_OPTS) check


# misc

distclean:
	rm -Rvf build doc/doxygen doc/coverage

doc:
	./doc/input/regen
	doxygen Doxyfile

flower:
	@cat ./scripts/flower


# special

.PHONY: doc flower
