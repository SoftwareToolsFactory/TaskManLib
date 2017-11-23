//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc:     TaskMan - Async Task Manager                                  |
// | By:       Nuroferatu - https://github.com/Nuroferatu                    |
// '-------------------------------------------------------------------------'
// ----= Change log =---------------------------------------------------------
//   1. 2017.11.22, 19:10    [+] Initial
// ---------------------------------------------------------------------------
#pragma once
#ifndef __TASKMAN_H__
#define __TASKMAN_H__

#include "itask.h"
#include <list>
#include <thread>

// ---------------------------------------------------------------------------
// TaskMan
// ---------------------------------------------------------------------------
class TaskMan {
public:
    TaskMan();
    ~TaskMan();

    void onInit( int workersCount );
    void onShutdown( void );

    void addTask( ITask* task );
    volatile bool isRunning( void ) const;

protected:
    static void threadWorker( TaskMan* taskMan );

    volatile bool   running;
    std::list<std::thread*> threadList;
};

#endif /* ndef __TASKMAN_H__ */
/* EOF */