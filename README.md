# opx-common-utils
This repository contains a utilities library used by the OPX project for thread queues, mutex support, and  other items. It is recommended that all utility code - used by more then one OPX component - be placed in this repository.

For example, the event service used by the CPS. The API that starts, stops, and the infrastructure for events are in the _event_ sources, while the user code is in the `opx-cps` repo.

## Build
See [opx-nas-manifest](https://github.com/opwn-switch/opx-nas-manifest) for complete information on common build tools.

### Build dependencies

- `opx-logging`
- `libxml2-dev`

Dependent packages: libopx-logging1 libopx-logging-dev

(c) Dell 2017
