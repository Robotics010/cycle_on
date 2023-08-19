# CycleOn (cycle_on)

CycleOn is a flexible end-to-end scenario-based verification and validation tool. It is cross-platform, simulator and middleware agnostic. Currently the main focus application is an autonomous driving software validation, but it can be used in other applications as well.

Typically a software team has a production code to be tested; a simulation tool to emulate inputs to the code modules and to consume an output; and some CI/CD solution to execute tests periodically and automatically. CycleOn is a simple-to-use scenario execution engine, which could effectively utilize all available computation power to execute test scenarios and check whether a module-under-test fullfills it's requirements.

## State

Current project is under active development and is not ready yet to be in use.

## Notes

### service notes

```
~/cycle_on/service$ cmake -S . -B build
~/cycle_on/service$ cmake --build build

~/cycle_on/service$ (cd build && ctest)
~/cycle_on/service$ ./build/src/hello_world
```
