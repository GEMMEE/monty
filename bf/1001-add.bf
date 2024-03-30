
++++++		#initialize cell 0 to 6
[>++++++++<-]	#store 48 in cell 1
>>,		#read digit 1 into cell 2
>,		#read digit 2 into cell 3
<<[>->-<<-]	#Subtract 48 from cell 2 and 3
>[>+<-]		#while cell 2 is positive add 1 to cell 3 and subtract 1 from cell 2

<<++++++
[>++++++++<-]	#store 48 in cell 1
>[>>+<<-]	#while cell 1 is positive add 1 to cell 3 and subract 1 from cell 1
		#It adds 48 to cell 3
>>.		#print content of cell 3

