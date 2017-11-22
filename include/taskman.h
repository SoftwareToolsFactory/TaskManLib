//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc:     TaskMan                                                       |
// | By:       Nuroferatu - https://github.com/Nuroferatu                    |
// '-------------------------------------------------------------------------'
// ----= Change log =---------------------------------------------------------
//   1. 2017.11.22, 19:10    [+] Initial
// ---------------------------------------------------------------------------
#pragma once
#ifndef __TASKMAN_H__
#define __TASKMAN_H__

// ---------------------------------------------------------------------------
// TaskMan
// ---------------------------------------------------------------------------
class TaskMan {
public:
    void onInit( int workersCount );
    void onShutdown( void );
};

#endif /* ndef __TASKMAN_H__ */
/* EOF */