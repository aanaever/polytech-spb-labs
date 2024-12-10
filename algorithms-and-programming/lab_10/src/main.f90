program lab_10_v7_32v
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, N = 0, M = 0, i = 0, j = 0, k = 0
   real(R_), allocatable   :: B(:, :)
   real(R_)                :: prom = 0

   open (file=input_file, newunit=In)
   read (In, *) N, M
   allocate (B(M, N))  !b(j,i) j-stolb, i-nomer str
      read (In, *) B
   close (In)
   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, '('//M//'f6.2)') B
   close (Out)

do concurrent (i = 1:N)
   do j = 1, M
        do k = 1, M-j
            if(Abs(B(k, i)) > Abs(B(k+1, i))) then
               prom = B(k, i)
               B(k, i) = B(k+1, i)
               B(k+1, i) = prom
            end if
         end do
     end do
   end do

   open (file=output_file, encoding=E_, newunit=Out, position='append')
     write (Out, *) "Sorted array"
     write (Out, '('//M//'f6.2)') B
  close (Out)

end program lab_10_v7_32v
