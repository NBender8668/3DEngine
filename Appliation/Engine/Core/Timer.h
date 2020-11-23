#pragma once
#include <chrono>

namespace nc
{
	class Timer
	{
	public:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = std::chrono::duration<clock::rep, std::nano>;
	
	public:
		Timer() : m_timepoint(clock::now()) {}

		void Reset();
		clock::rep ElapsedTicks();
		clock::rep TickPerSecond();

		double ElapsedSeconds();

	protected:
		clock::time_point m_timepoint;
	};

	class FrameTimer : public Timer
	{
	public:
		void Tick();
		float DeltaTimer() { return m_dt; }

	protected:
		float m_dt{0};

	};
}