//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc:     AsyncTaskQueue - Thread safe queue of tasks to execute        |
// | By:       Nuroferatu - https://github.com/Nuroferatu                    |
// '-------------------------------------------------------------------------'
// ----= Change log =---------------------------------------------------------
//   2. 2017.11.23, 10:30    [+] isEmpty - it's not synchronized! must be used with cautions
//   1. 2017.11.23, 10:30    [+] Initial
// ---------------------------------------------------------------------------
#pragma once
#ifndef __ASYNCTASKQUEUE_H__
#define __ASYNCTASKQUEUE_H__

#include "itask.h"
#include <condition_variable>
#include <deque>
#include <mutex>

// ---------------------------------------------------------------------------
// AsyncTaskQueue
// ---------------------------------------------------------------------------
class AsyncTaskQueue {
public:
    AsyncTaskQueue();
    ~AsyncTaskQueue();

    ITaskPtr    get( void );
    void        put( ITaskPtr task );
    void        terminate( void );
    bool        isEmpty(void) const { return (taskQueue.size() == 0); }

protected:
    volatile bool    running;

    std::condition_variable cvDataReady;
    std::mutex  mtxDataReady;
    std::mutex  mtxBufferAccess;

    std::deque<ITaskPtr> taskQueue;
};

#endif /* ndef __ASYNCTASKQUEUE_H__ */
/* EOF */