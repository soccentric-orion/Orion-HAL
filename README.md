# Orion-HAL

## Project Summary

Orion-HAL is the C++17 hardware-abstraction and validation library for Orion's ST STM32MP157F platform and Cortex-M4 companion environment. It presents a common `TestBase` and `TestResult` model to module libraries that probe system interfaces and report status, severity, reasons, metrics, monitoring data, and event data. The source has separate libraries for compute, memory, thermal, power, networking, USB/PCIe, GPIO, camera, display, audio/video, sensors, safety, debug, storage, and MCU-facing functions.

The `protos/` layer defines stable Protocol Buffers and gRPC contracts, generates static protocol libraries, provides client and server wrappers, and includes a standalone HAL gRPC server. `module_registry_all.cpp` registers typed handlers, while shared code separates protobuf conversion from module execution. CMake builds the base, module, protocol, and test targets; Make and Docker provide native and ARM64-oriented workflows. Doxygen, clang-format, and cppcheck configuration are included.

Every major module has a test directory with a CMake target, generally an executable that exercises the module against target interfaces. The repository contains 35-plus module test targets and protocol code. Most tests require Linux device nodes or peripherals, so a host build passing does not establish hardware behavior.

## Feature Inventory

| # | Name / Description | Implemented? | Test Coverage? | Manual Test |
|---:|---|---|---|---|
| 1 | Shared `TestBase` and structured result model | Implemented | Partial: used throughout module tests | [ ] Manual verification required |
| 2 | CPU, GPU, vision, and DLA libraries | Implemented | Partial: dedicated targets exist | [ ] Manual verification required |
| 3 | Memory, storage, thermal, and environmental libraries | Implemented | Partial: dedicated targets exist | [ ] Manual verification required |
| 4 | Ethernet, switch, USB, PCIe, GPIO, connectors | Implemented | Partial: dedicated targets exist | [ ] Manual verification required |
| 5 | Camera, display, audio, video, and sensors | Implemented | Partial: dedicated targets exist | [ ] Manual verification required |
| 6 | Safety, reliability, security, watchdog, debug | Implemented | Partial: dedicated targets exist | [ ] Manual verification required |
| 7 | MCU, PoE HAT, Sense HAT, SerDes libraries | Implemented | Partial: dedicated targets exist | [ ] Manual verification required |
| 8 | Protobuf common, HAL, and client-service contracts | Implemented | Unknown: compile path present | [ ] Manual verification required |
| 9 | Typed registry and standalone gRPC server | Implemented | Unknown: service integration unverified | [ ] Manual verification required |
| 10 | CMake, Make, Docker, Doxygen, format, cppcheck | Implemented | Unknown: toolchain dependent | [ ] Manual verification required |

## Build and Test

```bash
make build
make run
```
