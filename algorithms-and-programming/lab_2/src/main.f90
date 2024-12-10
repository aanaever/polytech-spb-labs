program lab_2_v12
   use Environment
   use IEEE_Arithmetic
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0
   real(R_)                :: x = 0, x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, y = 0

   open (file=input_file, newunit=In)
      read (In, *) x, x1, x2, x3, y1, y2, y3
   close (In)
   
   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "(7(a, f0.2/))") "x = ", x, "x1 = ", x1, "x2 = ", x2, "x3 = ", x3, "y1 = ", y1, "y2 = ", y2, "y3 = ", y3
   close (Out)
   
   y = F(x, x1, x2, x3, y1, y2, y3)

   open (file=output_file, encoding=E_, newunit=Out, position='append')
      write (Out, "('y = ', f0.2)") y
   close (Out)

contains
   pure function F(x, x1, x2, x3, y1, y2, y3)
      real(R_) F, x, x1, x2, x3, y1, y2, y3
      intent(in)  x, x1, x2, x3, y1, y2, y3
 
      if (x>=x1 .and. x<=x2) then
         F = y1 + ((x - x1)/(x2 - x1))*(y2 -y1)
      else if (x>=x2 .and. x<=x3) then
         F = y2 + ((x - x2)/(x3 -x2))*(y3 - y2)
      else
         F = IEEE_Value(x, IEEE_Quiet_NaN)
      end if
   end function F
end program lab_2_v12
