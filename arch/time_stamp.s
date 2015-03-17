/*this ignores the high bit of the time stamp */
.global time_stamp
time_stamp:
	rdtsc
	ret
