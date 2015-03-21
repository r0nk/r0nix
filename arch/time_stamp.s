/*this ignores the high part of the time stamp */
.global time_stamp
time_stamp:
	rdtsc
	ret
