#include "ns3/uno-results.h"

namespace uno{

void SinkTrace(int idx, Ptr<const ns3::Packet> p, const Address&)
{
    m_sinkBytes.back()[idx] += p->GetSize();
}

void SetupSinkTrace(std::vector<Ptr<PacketSink>> sinks)
{
    m_numSinks = sinks.size();
    for (int i=0; i < sinks.size(); i++)
    {
        sinks[i]->TraceConnectWithoutContext("Rx", MakeBoundCallback(&SinkTrace,i));
    }
}

void ScheduleThroughput( Time end)
{
    std::vector<uint64_t> throughput(m_numSinks);
    m_sinkBytes.push_back(throughput);
    if (Simulator::Now() < end || end == Time(0)) {
        Simulator::Schedule(m_throughputDuration, &ScheduleThroughput, end);
    }
}

void SetupThroughputRecording(
    Time interval = Time(1),
    Time start = Time(0),
    Time end = Time(0)
){
    m_throughputDuration = interval;
    Simulator::Schedule(start, &ScheduleThroughput, end);
}


}