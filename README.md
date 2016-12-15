opx-common-utils

Common utilities for the OPX project.

Description

This repo contains a utilities library used by the OPX project for thread queues, mutex support and many many other items.
If the code is a utility and used by more then one opx component, then the code utility should be placed here.
Some exampels of this are the event service used by the opx-cps. The API that starts, stops and the infrastructure for events are in the "event" sources while the user is in the opx-cps.
