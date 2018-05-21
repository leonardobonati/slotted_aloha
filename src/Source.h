/* Source.h
 *
 * Author: Leonardo Bonati
 * Created on Mar. 2018
 *
 */

#ifndef SLOTTED_ALOHA_SOURCE_H
#define SLOTTED_ALOHA_SOURCE_H

#include <omnetpp.h>

using namespace omnetpp;

namespace slotted_aloha {

/**
 * Generates messages; see NED file for more info.
 */
class Source : public cSimpleModule
{
  private:
    cMessage *new_slot;
    cMessage *decrease_collision_counter;

    int tot_slots;
    int slot_num;

    double slot_time;
    double p;
    double eps;

  public:
     Source();
     virtual ~Source();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

}; // namespace

#endif
