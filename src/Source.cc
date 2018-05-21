/* Source.cc
 *
 * Author: Leonardo Bonati
 * Created on Mar. 2018
 *
 */

#include "Source.h"

namespace slotted_aloha {

Define_Module(Source);

Source::Source()
{
    new_slot = nullptr;
    decrease_collision_counter = nullptr;
}

Source::~Source()
{
    if (new_slot != nullptr) {
        cancelAndDelete (new_slot);
    }

    if (decrease_collision_counter != nullptr) {
        cancelAndDelete (decrease_collision_counter);
    }
}

void Source::initialize()
{
    // get parameters
    slot_time = par("slot_time");
    p = par("tx_prob");

    tot_slots = par("tot_slots");

    // initialize variables
    slot_num = 0;
    eps = 0.000001;

    if (slot_num < tot_slots)
    {
        // enter new slot
        new_slot = new cMessage("new_slot");
        scheduleAt(simTime(), new_slot);
    }



}

void Source::handleMessage(cMessage *msg)
{
    cModule* c = getModuleByPath("SourceSink");

    if (msg == new_slot)
    {
        // compute transmission prob
        double rv = uniform(0, 1);

        if (rv < p)
        {
            // transmit
            cMessage *data_pkt = new cMessage("data_pkt");
            sendDelayed(data_pkt, eps, "out");

            // update collision conter
            c->par("concurrent_tx") = ((int) c->par("concurrent_tx")) + 1;

            // decrease collision counter
            if (decrease_collision_counter != nullptr) {
                cancelAndDelete (decrease_collision_counter);
            }
            decrease_collision_counter = new cMessage("decrease_collision_counter");
            scheduleAt(simTime() + slot_time - eps, decrease_collision_counter);
        }

        // increase slot counter
        slot_num++;

        // schedule new slot
        if (slot_num < tot_slots)
        {
            if (new_slot != nullptr) {
                cancelAndDelete (new_slot);
            }
            new_slot = new cMessage("new_slot");
            scheduleAt(simTime() + slot_time, new_slot);
        }
    }
    else if (msg == decrease_collision_counter)
    {
        // decrease collision counter
        c->par("concurrent_tx") = ((int) c->par("concurrent_tx")) - 1;
    }
}

}; // namespace
