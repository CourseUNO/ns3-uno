//
// Created by Tiffany Zhang on 11/1/24.
//

#ifndef NS3_UNO_RESULTS_H
#define NS3_UNO_RESULTS_H

#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-layout-module.h"
#include "ns3/traffic-control-module.h"
#include "ns3/assert.h"
#include "ns3/data-rate.h"
#include "ns3/config-store.h"
#include <cstdint>

using namespace ns3;
namespace uno{

// records bytes received for a packet sink
// for example, m_sinkBytes[0][1] records the packets
// received during the first duration for the second
// packet sink
static std::vector<std::vector<uint64_t>> m_sinkBytes;
static int m_numSinks;
static Time m_throughputDuration;
void SinkTrace(int idx, Ptr<const Packet> p, const Address&);
void SetupSinkTrace(std::vector<Ptr<PacketSink>>);
void SetupThroughputRecording(Time interval,Time start,Time end);



}


#endif // NS3_UNO_RESULTS_H
