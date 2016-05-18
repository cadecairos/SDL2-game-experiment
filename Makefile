all: build

build: clean
	mkdir -p build/debug
	cd build/debug && \
	cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_BUILD_TYPE=Debug ../../src && \
	make

build-release: clean-release
	mkdir -p build/release
	cd build/release && \
	cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_BUILD_TYPE=Release ../../src && \
	make

clean:
	rm -rf build/debug

clean-release:
	rm -rf build/release

run:
	build/debug/GhostHunter

run-release:
	build/release/GhostHunter