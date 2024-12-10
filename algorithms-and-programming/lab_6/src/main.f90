program lab_6_v4
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0
   real(R_)                :: a = 0, y = 0

   open (file=input_file, newunit=In)
      read (In, *) a
   close (In)
   

y = Foo(a)
   open (file=output_file, newunit=Out)
      write (Out, *) 'a =', a
      write (Out, *) 'y =', y
      write (Out, *) '1/a =', 1/a
   close (Out)
contains
real(R_) pure function Foo(a) result(y_np1)
  real(R_), intent(in) :: a
   real(R_) y_n
      y_n =2./3/a
      y_np1 = y_n
      do
         y_n = y_np1
         y_np1 = y_n - (1/y_n -a) / (-1/y_n**2)
         if(Abs(y_n - y_np1) < epsilon(1.0)) exit
      end do
end function Foo
end program lab_6_v4
