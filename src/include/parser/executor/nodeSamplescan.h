//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// nodeSamplescan.h
//
// Identification: src/include/parser/executor/nodeSamplescan.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//


/*-------------------------------------------------------------------------
 *
 * nodeSamplescan.h
 *
 *
 *
 * Portions Copyright (c) 1996-2014, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/executor/nodeSamplescan.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef NODESAMPLESCAN_H
#define NODESAMPLESCAN_H

#include "parser/nodes/execnodes.h"

extern SampleScanState *ExecInitSampleScan(SampleScan *node, EState *estate, int eflags);
extern TupleTableSlot *ExecSampleScan(SampleScanState *node);
extern void ExecEndSampleScan(SampleScanState *node);
extern void ExecReScanSampleScan(SampleScanState *node);

#endif   /* NODESAMPLESCAN_H */
