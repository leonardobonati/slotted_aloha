/* Sink.cc
 *
 * Author: Leonardo Bonati
 * Created on Mar. 2018
 *
 */

#include "Sink.h"
#include "Source.h"

namespace slotted_aloha {

Define_Module(Sink);

void Sink::initialize()
{
    collided = 0;
    tot_pkts = 0;
    succ_rx = 0;
}

void Sink::handleMessage(cMessage *msg)
{
    cModule* c = getModuleByPath("SourceSink");
    double conc_tx = c->par("concurrent_tx");

    // check if collison happened
    if (conc_tx > 1)
    {
        EV << "Collision" << endl;

        collided++;
    }
    else
    {
        EV << "Packet successfully received" << endl;

        succ_rx++;
    }

    tot_pkts++;

    delete(msg);
}

void Sink::finish()
{
    cModule* c = getModuleByPath("SourceSink");
    int nodes_num = (int) c->par("n");

    cModule *src = getModuleByPath("SourceSink.source[0]");
    int slots = (int) src->par("tot_slots");

    // print statistics
    EV << "Correctly received per slot: " << ((double) succ_rx) / ((double) slots) << endl;
    EV << "Collided per slot: " << ((double) collided) / ((double) (slots * nodes_num)) << endl;

    EV << endl;
    EV << "Total number of packets: " << tot_pkts << endl;
    EV << "Total number of slots: " << slots << endl;
}

}; // namespace
