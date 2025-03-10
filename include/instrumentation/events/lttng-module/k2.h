#undef TRACE_SYSTEM
#define TRACE_SYSTEM k2

#if !defined(K2_LTTNG_MODULES_K2_H) || defined(TRACE_HEADER_MULTI_READ)
#define K2_LTTNG_MODULES_K2_H


#include <lttng/tracepoint-event.h>
#include <linux/tracepoint.h>
#include <linux/blkdev.h>

LTTNG_TRACEPOINT_EVENT(
        // Name - the name of the tracepoint to be created
        k2_completed_request,
        // Prototype - the prototype for the tracepoint callbacks
        TP_PROTO(struct request* rq, s64 real_latency),
        // Arguments - the arguments that match the prototype
        TP_ARGS(rq, real_latency),

        // Struct - the structure that a tracer could use (but is not required to) to store the data passed into the tracepoint
        TP_FIELDS(
                ctf_integer(u32, request_size, (u32)(blk_rq_stats_sectors(rq) << SECTOR_SHIFT))
                ctf_integer(s64, estimated_latency, (s64)(uintptr_t)rq->elv.priv[0])
                ctf_integer(s64, real_latency, real_latency)
                ctf_integer(s32, pid, (s32)(uintptr_t)rq->elv.priv[1])
                ctf_integer(s16, req_opf, (s16)(req_op(rq) & REQ_OP_MASK))
        )
)


#endif //K2_LTTNG_MODULES_K2_H
#include <lttng/define_trace.h>
