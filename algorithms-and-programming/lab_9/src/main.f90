program lab_9_v7_17a
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, N = 0, M = 0, i = 0
   real(R_), allocatable   :: C(:, :)
   real(R_)                :: max_val = 0
   integer, allocatable    :: Indexes(:, :), Ind_max_val(:, :)
   logical, allocatable    :: Mask(:)

   open (file=input_file, newunit=In)
      read (In, *) N, M
      allocate (C(N, M))
      read (In, *) (C(i, :), i = 1, N)
   close (In)

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, '('//M//'f6.2)') (C(i, :), i = 1, N)
   close (Out)

   allocate (Indexes(N*M, 2))
   allocate (Mask(N*M), source=.false.)
  
   call MaxValAndIndexes(C, max_val, Mask, Indexes, Ind_max_val)
   
   open (file=output_file, encoding=E_, newunit=Out, position='append')
      write (Out, '(a, f6.2)') "Max value in array", max_val
      write (Out, *) "Indexes :"
      write (Out, '(2i3)') (Ind_max_val(i, :), i = 1, UBound(Ind_max_val, 1))
  close (Out)

contains
   pure subroutine MaxValAndIndexes(C, max_val, Mask, Indexes, Ind_max_val)
      real(R_), intent(in)    :: C(:, :)
      real(R_), intent(out)   :: max_val
      integer, intent(out)    :: Indexes(:, :)
      integer, allocatable, intent(out) :: Ind_max_val(:, :)
      logical, intent(out)    :: Mask(:)

      integer N_max_val, i, j

      Indexes(:, 1) = [((i, i = 1, N), j = 1, M)]
      Indexes(:, 2) = [((j, i = 1, N), j = 1, M)]

      max_val = MaxVal(C)
      Mask        = [C == max_val]
      N_max_val   = Count(Mask)

      allocate(Ind_max_val(N_max_val, 2))

      Ind_max_val(:, 1) = Pack(Indexes(:, 1), Mask)
      Ind_max_val(:, 2) = Pack(Indexes(:, 2), Mask)
      
   end subroutine MaxValAndIndexes
end program lab_9_v7_17a
