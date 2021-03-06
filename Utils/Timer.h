//
// Copyright (C) 2013, Alojz Kovacik, http://kovacik.github.com
//
// This file is part of Geometry Debugger.
//
// Geometry Debugger is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Geometry Debugger is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Geometry Debugger. If not, see <http://www.gnu.org/licenses/>.
//


#pragma once

#ifdef _DEBUG

#define DEBUG_TIMER_START(timerName) \
{ \
    Timer _myDebugTimer;           \
    _myDebugTimer.Start(timerName) \

#define DEBUG_TIMER_STOP \
    _myDebugTimer.Stop(); \
}

#else

#define DEBUG_TIMER_START(timerName)
#define DEBUG_TIMER_STOP

#endif


class Timer
{
private:
    LARGE_INTEGER m_TicksDifference;
    LARGE_INTEGER m_StartTicks;
    LARGE_INTEGER m_Frequency;
    LPCWSTR m_Text;

public:
    Timer();
    BOOL Start(LPCWSTR szTimerName);
    BOOL Stop();
};