/*
 * SYSTICK.hpp
 *
 *  Created on: Apr 2, 2025
 *      Author: ziad
 */

#ifndef CORE_SYSTICK_SYSTICK_HPP_
#define CORE_SYSTICK_SYSTICK_HPP_


/* --------------- includes --------------- */
#include "../../LIB/common.hpp"

namespace SYSTICK {

	namespace CSR{
		constexpr StdType::uint32 Register = 0xE000E010;

		enum class PIN : StdType::uint8 {
			ENABLE, TICKINT, CLKSOURCE, COUNTFLAG = 16,
		};
	}

	namespace RVR {
		constexpr StdType::uint32 Register = 0xE000E014;

		enum class PIN : StdType::uint32 {
			RELOAD
		};
	}

	namespace CVR {
		constexpr StdType::uint32 Register = 0xE000E018;

		enum class PIN : StdType::uint32 {
			CURRENT
		};
	}

	namespace CALIB {
		constexpr StdType::uint32 Register = 0xE000E01C;

		enum class PIN : StdType::uint32 {
			TENMS, SKEW = 30, NOREF
		};
	}

	class SYSTICK {
    private:
        StdType::uint32 clockFrequency; ///< System clock frequency in Hz
        StdType::uint32 tickTimeMs;     ///< Time per tick in milliseconds

    public:
        SYSTICK(StdType::uint32 systemClockHz, StdType::uint32 tickMs);

        void start();
        void stop();
        bool hasElapsed();
        void delayMs(StdType::uint32 ms);
	};
}

#endif /* CORE_SYSTICK_SYSTICK_HPP_ */
