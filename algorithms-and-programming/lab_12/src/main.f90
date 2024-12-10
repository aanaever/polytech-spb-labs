program lab_12_v8_27
   use Environment
   use Matrix_IO
   use Matrix_process
   
   implicit none
   
   character(*), parameter :: input_file = "../data/input.txt", input_file2 = "../data/input2.txt", output_file = "output.txt"
   integer                 :: Norm = 0, D = 0, N = 0
   integer, allocatable    :: Y(:), A(:, :),B(:,:), Sum(:)
 
   
   D = ReadSizeVector(input_file2)
   Y = ReadVector(input_file2)
   Norm = Norma(Y)
   call OutputNorma(output_file, Norm)
  
   
   A = ReadMatrix(input_file)
   Sum = Summa(A, Y)
   call OutputSum(output_file, Sum)

  contains
     pure function Summa(A, Y) result (Sum)
        integer, allocatable :: Sum(:)
        integer, intent(in)  :: A(:, :), Y(:) ! D, N

        integer, allocatable :: B(:, :), X(:)
        integer i, D, N
        D = Ubound(Y, 1)
        N = Ubound(A, 1)
        allocate (Sum(D))
        allocate (B(N, N))
        allocate (X(D))
        
        Sum = ArrayMulVec(A, Y)
        B = ArrayMul(A, A)   
       
        do i = 1, 3  
           X = ArrayMulVec(B, Y) 
           Sum = Sum + X
           B = ArrayMul(B, A) 
        end do
        x = ArrayMulVec(B, Y)
        Sum = Sum + X
    end function Summa 

end program lab_12_v8_27
