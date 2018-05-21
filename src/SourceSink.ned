// SourceSink.ned
//
// Author: Leonardo Bonati
// Created on Mar. 2018
//

package slotted_aloha;

//
// Sample network, consisting of a source and a sink.
//
network SourceSink
{
    parameters:
        int n = default(5);
        int concurrent_tx = default(0);
    submodules:
        source[n]: Source;
        sink: Sink;
    connections:
        for i=0..n-1 {
            source[i].out --> sink.in++;
        }
}
