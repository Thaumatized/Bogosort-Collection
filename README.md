Bogosort implementations in different languages. Honestly the only reason for the existence of this is to have simple fun.  
  
I have decided that array randomisation, generation and checking for order are to be implemented, so no built-in functions.  
  
The program must time itself to the millisecond, if array is not defined.  
  
Sorted array is printed only if starting array is defined.  
  
Each bogosort implementation must be able to run with the following command line arguments:  
	-l length, how long of a list is used. default 10.  
	-m max, biggest number allowed in the list. default 255.  
	-c count, how many times the bogosort is run. default 1.  
	-v , verbose, print individual times as well and some additional stats.  
	-a values..., values used to specify an array to sort. overrides all others.  

Currently implemented:  
- Python  
- C
- JavaScript
	- No command line, can use included html
