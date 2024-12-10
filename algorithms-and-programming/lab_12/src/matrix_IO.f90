module Matrix_IO
   use Environment
   
   implicit none
   
   contains
   
   function ReadMatrix(input_file) result(A)
      character(*), intent(in)   :: input_file
      integer, allocatable       :: A(:, :)

      integer :: In = 0, i = 0, N = 0

      open (file=input_file, newunit=In)
         read (In, *) N
         allocate (A(N, N))
         read (In, *) (A(i, :), i = 1, N)
      close (In)
   end function ReadMatrix
  
  function ReadSizeMatrix(input_file) result (N)
      character(*), intent(in)   :: input_file
      integer    :: In = 0, N
      
      open(file=input_file, newunit=In)
      read (In, *) N
      close (In)
   end function ReadSizeMatrix

   function ReadVector(input_file2) result(Y)
      character(*), intent(in)   :: input_file2
      integer, allocatable       :: Y(:)

      integer :: In = 0, M = 0

      open (file=input_file2, newunit=In)
         read (In, *) M
         allocate (Y(M))
         read (In, *) Y
      close (In)
   end function ReadVector
  
 
  function ReadSizeVector(input_file2) result (D)
      character(*), intent(in)   :: input_file2
      integer    :: In = 0, D
      
      open(file=input_file2, newunit=In)
      read (In, *) D
      close (In)
  end function ReadSizeVector

   subroutine OutputNorma(output_file, Norm)
      character(*), intent(in)   :: output_file
      integer, intent(in)        :: Norm

      integer :: Out = 0

      open (file=output_file, newunit=Out)
         write (Out, *) "Norma vectora"
         write(Out, *) Norm
      close (Out)
   end subroutine OutputNorma
   
   subroutine OutputSum(output_file, Sum)
      character(*), intent(in)   :: output_file
      integer, intent(in)       :: Sum(:)
      integer  :: Out = 0

      open (file=output_file, newunit=Out, position='append')
         write (Out, *) "Sum"
         write (Out, *) Sum
      close (Out)
   end subroutine OutputSum

   subroutine OutputArray(output_file, C, N)
      character(*), intent(in)  :: output_file
      integer, intent(in)       :: C(:, :)
      integer, intent(in)       :: N

      integer  :: Out = 0, i = 0

      open(file=output_file, newunit=Out)
      write (Out, '('//N//'i3)') (C(i, :), i = 1, N)
      close(Out)
      end subroutine OutputArray

end module Matrix_IO
