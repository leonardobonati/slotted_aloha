/* Sink.h
 *
 * Author: Leonardo Bonati
 * Created on Mar. 2018
 *
 */

#ifndef SLOTTED_ALOHA_SINK_H
#define SLOTTED_ALOHA_SINK_H

#include <omnetpp.h>

using namespace omnetpp;

namespace slotted_aloha {

/**
 * Message sink; see NED file for more info.
 */
class Sink : public cSimpleModule
{
  private:
    int collided;
    int tot_pkts;
    int succ_rx;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

}; // namespace

#endif
