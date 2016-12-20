# sonic-common-utils

## Description

This repo contains a utilities library used by the OPX project for thread queues, mutex
support, and  other items. 
It is recommended that all utility code - used by more then one OPX component -
be placed in this repo.

Example - the
event service used by the CPS. The API that starts, stops, and the
infrastructure for events are in the "event" sources while the user
code is in the opx-cps repo.

## Build
See [opx-nas-manifest](https://github.com/open-switch/opx-nas-manifest) for complete
information on common build tools.

### Build dependencies
- `sonic-logging`
- `libxml2-dev`

### Package dependencies
- `libsonic-logging1` 
- `libsonic-logging-dev`

BUILD CMD: opx_build libsonic-logging1 libsonic-logging-dev -- clean
binary

(c) Dell 2016
