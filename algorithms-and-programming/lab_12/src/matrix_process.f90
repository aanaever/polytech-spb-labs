module Matrix_process
   use Environment
   
   implicit none
   contains

   pure function Norma(Y) result(Norm)
      integer, intent(in) :: Y(:)
      integer :: Norm, D

      integer :: i
   
      D = (Ubound(Y, 1))
      do i = 2,  D
        if(Abs(Y(i)) > Norm) Norm = Abs(Y(i))
      end do
    
   end function Norma

  pure function ArrayMul(A, B) result(C)
     integer, allocatable :: C(:, :)
     integer, intent(in)  :: A(:, :), B(:, :)

     integer :: i, j, k, N

     N = Ubound(A, 1)
     
     allocate(C(N,N))

     do j = 1, N
        do i = 1, N
           C(j, i) = 0
           do k = 1, N
              C(j, i) = C(j, i) + A(k, i)*B(j, k)
           end do
        end do
     end do

     end function ArrayMul

   pure function ArrayMulVec(A, Y) result (S)
      integer, allocatable :: S(:)
      integer, intent(in)  ::A(:, :), Y(:)
 !     integer, allocatable :: X(:, :)
      integer :: i, j, N
       N = Ubound(Y, 1)
      allocate(S(N))
      
      do i = 1, N
      S(i)=0
      do j = 1, N
      S(i) = S(i) + A(i, j)*Y(j)
      end do
      end do
end function ArrayMulVec
end module Matrix_process
