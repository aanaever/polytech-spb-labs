program task_1_v8
   use Environment
   
   implicit none
   character(*), parameter    :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                    :: In = 0, Out = 0
   integer                    :: a = 0, b = 0, c = 0
   integer, parameter         :: n = 3
   integer                    :: arr(n)
   arr = 0
   open (file=input_file, newunit=In)
      read (In, * ) a, b, c
   close (In)
   
   open (file=input_file, newunit=In)
      read(In, *)arr
   close (In)
   a = arr(3)
   b = arr(1)
   c = arr(2)
   open(file=output_file, newunit=Out)
   write(Out, * ) "a = " ,a , "b = ", b, "c = ", c
   close(Out)

end program task_1_v8
