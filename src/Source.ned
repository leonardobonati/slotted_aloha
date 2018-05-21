// Source.ned
//
// Author: Leonardo Bonati
// Created on Mar. 2018
//

package slotted_aloha;

//
// Generates messages with a configurable interarrival time.
//
simple Source
{
    parameters:
        double slot_time @unit(s) = default(1.0s);
        double tx_prob = default(0.5);
        int tot_slots = default(100000);
        @display("i=block/source");
    gates:
        output out;
}
