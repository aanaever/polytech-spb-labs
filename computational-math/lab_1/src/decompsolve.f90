program task33
use Environment
     implicit none
     integer :: N = 5, I, J, NDIM = 5
     real(R_) :: cond = 0, E
     integer, allocatable :: IPVT(:)
     real(R_), allocatable :: matrix1(:,:), matrix2(:,:), matrix3(:,:)
     real(R_), allocatable :: invMatrix1(:,:), invMatrix2(:, :)
     real(R_), allocatable :: WORK(:), B(:)
     real(R_), allocatable :: R(:,:) 
     real(R_)              :: Norm
     
 allocate (matrix1(N, N))
 allocate (matrix2(N, N))
 allocate (matrix3(N, N))
 allocate (R(N,N))
 allocate (invMatrix1(N, N))
 allocate (invMatrix2(N, N))
 allocate(B(N))
 allocate (WORK(N))
 allocate (IPVT(N))
 
 E = 0.001
 !E = 0.00001
 !E = 0.000001
 
 do i = 1, N
  do j = 1, N
  if(j < N) then
   matrix1(i, j) = ((1 +cos(real(j)))/(sin(real(j))*sin(real(j))))**(i-1)
    else if (j==N) then
     matrix1(i,j) = ((1+cos(1.0))/(sin(1+E)*sin(1+E)))**(i-1)
    end if
   end do
  end do
  
  matrix2 = matrix1
  matrix3 = matrix1
  
  write(*,'(A)') "Exp = 0.000001"
  do i = 1, n
  write(*, *) matrix1(i, :)
  end do
  
  call inversionMatrix(NDIM, N, matrix2, cond, IPVT, WORK, B, invMatrix1)
  
  invMatrix2 = invMatrix1
  
  write(*,*)
  write(*,'(A)') "Inversion Matrix:"
  
  do i = 1, N
   write (*, *) invMatrix1(i, :)
  end do
  
  write(*,*)
  write(*, '(A)')"COND = :"
  write(*,*) cond
  
  write(*,*)
 R = matrixR(matrix3, invMatrix2)
 write(*,'(A)') " Matrix R: "
 do i = 1, N
  write (*, *) R(i, :)
 end do
 write(*,*)
 
 Norm = NormR(R)
 
 write(*,'(A)') " Norm ||R1|| = "
 write (*,*) Norm
 
 deallocate (matrix2)
 deallocate (matrix3)
 deallocate (R)
 deallocate (invMatrix1)
 deallocate (invMatrix2)
 deallocate(B)
 deallocate (WORK)
 deallocate (IPVT)
 deallocate (matrix1)
 
 contains
 !Функция вычисления нормы матрицы R
 function NormR(A) result(R)
  real(R_), intent(In) :: A(:,:)
  real(R_), allocatable :: B(:)
  real(R_) :: R
  integer :: N
 N = size(A)
 allocate(B(N))
  do i = 1, size(A, 1)
  B(i) = sum(abs(A(i, :)))
  end do
  R = maxval(B)
 end function NormR
 ! Функция вычисления матрицы R (по формуле)
 function matrixR(A, invMatrix) result(R)
 real(R_), intent(in) :: A(:,:)
 real(R_), intent(in) :: invMatrix(:,:)
 real(R_), allocatable :: R(:,:)
 real(R_), allocatable :: E(:,:)
 integer :: N 
 N = size(A)
 allocate(R(N,N))
 allocate(E(N,N))
 E = 0
 do i = 1, size(A,1)
 do j = 1, size(A,2)
 if(i == J) E(i, j) = 1
 end do
 end do
 R = matmul(invMatrix,A) - E
 end function matrixR
 
 ! Процедура вычисления обратной матрицы A
 subroutine inversionMatrix(NDIM, N, A, cond, IPVT, WORK, B, invMatrix)
 real(R_) :: A(N,N), B(N), WORK(N)
 integer  :: IPVT(N)
 real(R_) :: cond
 integer  :: N, NDIM
 real(R_) :: invMatrix(N,N)
 
 call DECOMP(NDIM, N, A, cond, IPVT, WORK)
 
 do i = 1, N
  do j = 1, N
   b(j)=0.0
    if(j == i) b(j) = 1.0
  end do
  
  call SOLVE(NDIM, N, A, B, IPVT)
  do j = 1, N
   invMatrix(j, i) = b(j)
  end do
end do
end
end program task33
