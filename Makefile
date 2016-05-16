all: build

build: clean
	mkdir -p build/debug
	cd build/debug && \
	cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_BUILD_TYPE=Debug ../.. && \
	make

build-release: clean-release
	mkdir -p build/release
	cd build/release && \
	cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_BUILD_TYPE=Debug ../.. && \
	make

clean:
	rm -rf build/debug

clean-release:
	rm -rf build/release

run:
	build/debug/GhostHunter

run-release:
	build/release/GhostHunter