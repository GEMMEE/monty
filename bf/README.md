#Program to print 'School' using brainf*ck
The language has only 8 instruction yet turing complete - its goal was to reduce memory use
How cool is that! 
Everything except those 8 instructions are ignored

+++++ +++++  (loop variable @0 = 10)
[            (begins the loop as @0 is greater than 0)
> 
+++++ +++++
>
+++++ +++++
>
+++++ +++++
>
+++++ +++++
>
+++++ +++++
>
+++++ +++++
<<<<<<
-
]             (ends the loop)

At the end of the above loop the cells will look like:
0  |  1  |  2  |  3  |  4  |  5  |  6  |
0    100   100   100   100   100   100
^
And the print 'School' the desired value at each cell
should be:
@1 = 83 ascii for 'S'
@2 = 99 ascii for 'c'
@3 = 104 ascii for 'h'
@4 = 111 ascii for 'o'
@5 = 111 ascii for 'o'
@6 = 108 ascii for 'l'

#Let's make @1 value 83 first
My pointer is @0 which I used as my loop variable
I will subtract 15 using loop from 100 and then add 2

+++++  (loop for 5 times)
[>---<-]  (subtract 3 from @1 5 times and decrement @0)
>--     (move pointer to @1 and subtract 2)
Now the cells look like:

0  |  1  |  2  |  3  |  4  |  5  |  6  |
0     83   100   100   100   100   100
      ^
Now to make @2 value 99 just move pointer one position
to the right and subtract 1

>-
The result is:
0  |  1  |  2  |  3  |  4  |  5  |  6  |
0     83    99   100   100   100   100
            ^
>++++
The result is:
0  |  1  |  2  |  3  |  4  |  5  |  6  |
0     83    99   104   100   100   100
                  ^
<<<++[>>>>+++++ >+++++ <<<<<-]
The result is:
0  |  1  |  2  |  3  |  4  |  5  |  6  |
0     83    99   104   110   110   100
^

>>>>+>+
0  |  1  |  2  |  3  |  4  |  5  |  6  |
0     83    99   104   111   111   100
                              ^
>++++ ++++
0  |  1  |  2  |  3  |  4  |  5  |  6  |
0     83    99   104   111   111   108
                                    ^
Now let's print them starting from @1
<<<<<.  (prints 'S')
>.      (prints 'c')
>.      (prints 'h')
>.      (prints 'o')
>.      (prints 'o')
>.      (prints 'l')






