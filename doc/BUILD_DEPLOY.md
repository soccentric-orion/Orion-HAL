# Orion-HAL Build and Deployment

## 1. Purpose and Scope
Orion-HAL is the CMake/Ninja C++ hardware-abstraction library set with protobuf contracts, module libraries, tests, CPack packaging, Doxygen, and an ARM64 Docker cross-build. The root Makefile is authoritative and writes native output to `build/native` and cross output to `build/cross`.

## 2. Prerequisites
- Linux, GNU Make, CMake, Ninja, a C++ compiler, and CTest.
- `clang-format` for `make format`, `cppcheck` for `make cppcheck`, and `doxygen` plus Graphviz for `make doc`.
- Docker Buildx/QEMU for ARM64 targets and `sshpass` for remote deployment.
- A Raspberry Pi 5/ARM64 target reachable over SSH for device checks.

## 3. Setup
```bash
make help
make configure
```
Native configuration runs `cmake -GNinja $(CURDIR)`. Docker setup is pulled in by `make docker-image`; `make docker-install` may install Docker with sudo. The CMake tree includes `src/`, `tests/`, and `protos/` module definitions.

## 4. Build and Compile
```bash
make build
make docker-configure
make docker-build
```
Native builds use `ninja -j$(JOBS)`. Docker uses the `orion` image, `linux/arm64`, `/workspace`, and a ccache volume. Set `JOBS=N` when needed. `make all` aliases the Docker build, not the native build.

## 5. Test and Lint
```bash
make test
make docker-test
make format
make cppcheck
make doc
```
Native and Docker tests run CTest with failure output; formatting invokes the Ninja format target and optionally `cmake-format`; static analysis invokes the Ninja cppcheck target; documentation invokes `doc_doxygen`. The Makefile explicitly checks required formatter/analyzer/documentation executables before those operations.

## 6. Packaging and Artifacts
```bash
make package
make package-deb
make package-ipk
make package-rpm
make docker-package
```
Native CPack outputs are placed in `build/native`; the package targets generate DEB, IPK, and optionally RPM artifacts. RPM requires `rpmbuild`. Docker package targets generate ARM64 DEB/IPK/RPM artifacts in `build/cross`; `docker-package` includes DEB and IPK. The exact package filenames are printed by native targets and use the project package metadata.

## 7. Deploy, Install, and Run
```bash
make deploy-a IP_A=192.168.1.3 HAL_SSH_USER=pi HAL_SSH_PASS='<target-password>'
make deploy-b IP_B=192.168.1.13 HAL_SSH_USER=pi HAL_SSH_PASS='<target-password>'
make run-a
make run-b
make run APP_NAME arg1
```
Deployment builds the ARM64 tree first, clears `/tmp/acu-test`, and copies `build/cross/lib` and `build/cross/bin` to the target. `run` uses native binaries and `LD_LIBRARY_PATH`; `run-a`/`run-b` execute remote applications after deployment. Default addresses and credentials are development placeholders; override them and never commit real passwords. Packaging itself does not install system packages or register services.

## 8. Cleanup
```bash
make clean
make docker-clean
make docker-shell
```
`clean` removes both build trees. `docker-clean` removes the Docker cross build; `docker-shell` opens the ARM64 image for inspection.

## 9. Hardware, Cloud, and Manual Verification Caveats
Unit/CTest coverage and generated contracts do not prove electrical behavior. On a real board, verify module discovery, GPIO/I2C/SPI/UART/device permissions, timing, error paths, ABI compatibility, and service integration. Deployment is direct SSH/SCP, with no cloud target. Remote run-all suppresses individual application failures, so collect and inspect device logs and results manually.
