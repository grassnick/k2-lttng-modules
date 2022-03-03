#include <linux/module.h>
#include <lttng/tracer.h>

/*
 * Build-time verification of mismatch between mainline
 * TRACE_EVENT() arguments and the LTTng-modules adaptation
 * layer LTTNG_TRACEPOINT_EVENT() arguments.
 */
#include <trace/events/k2.h>
//#include <trace/events/k2.h>

/* Create LTTng tracepoint probes */
#define LTTNG_PACKAGE_BUILD
#define CREATE_TRACE_POINTS
//#define TRACE_INCLUDE_PATH ../instrumentation/events/lttng-module
#define TRACE_INCLUDE_PATH ../instrumentation/events/lttng-module

#include "instrumentation/events/lttng-module/k2.h"

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Georg Grassnick <georg.grassnick@tu-dresden.de>");
MODULE_DESCRIPTION("LTTng k2 probes");
MODULE_VERSION(__stringify(LTTNG_MODULES_MAJOR_VERSION) "."
__stringify(LTTNG_MODULES_MINOR_VERSION) "."
__stringify(LTTNG_MODULES_PATCHLEVEL_VERSION)
LTTNG_MODULES_EXTRAVERSION);