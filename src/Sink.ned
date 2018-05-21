// Sink.ned
//
// Author: Leonardo Bonati
// Created on Mar. 2018
//

package slotted_aloha;

//
// Consumes received messages and collects statistics
//
simple Sink
{
    parameters:
        @display("i=block/sink");
    gates:
        input in[];
}
