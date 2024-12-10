program lab_7_v1b
   use Environment

   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, M = 0
   integer , allocatable   :: A(:), OldA(:)

   open (file=input_file, newunit=In)
      read (In, *) M
      allocate (A(M))
      read (In, *) A
   close (In)

   OldA = A

call SortedA(A, M)

 open (file=output_file, newunit=Out)
      write (Out, *)'OldA =', OldA
      write (Out, *) 'SortedA = ', A
   close (Out)
 
contains

   subroutine SortedA(A, M)
   intent(in) :: M
   integer    :: A
   integer    :: i, j, B
      do i=1, M
         do j = i+1, M
      if(A(I)>= A(j)) then
         B = A(i)
         A(i) = A(j)
         A(j) = B
    
      end if
      end do
   end do
   end subroutine SortedA

end program lab_7_v1b
