#Brainf*ck script that prints 'School' followed by a new line

+++++ +++++  (use cell 0 as loop variable)
[>+++++ +++++
 >+++++ +++++
 >+++++ +++++
 >+++++ +++++
 >+++++ +++++
 <<< << -
]  (initialize 5 cells to 100 using loop)
+++++
[>---
 <-
]     (at the end of loop cell 1 will have 85)
>--.  (set cell 1 to 83 using loop and print it)
>-.   (set cell 2 to 99 and print it)
>++++. (set cell 3 to 104 and print it)
>+++++ +++++ +.. (set cell 4 to 111 and print it twice)
>++++ ++++.    (set cell 5 to 108 and print it)
>+++++ +++++.   (set cell 6 to 10 for new line and print it)
