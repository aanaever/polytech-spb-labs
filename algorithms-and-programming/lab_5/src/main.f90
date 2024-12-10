program lab_5_v23
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, N = 0
   integer, allocatable    :: A(:), B(:), C(:)
   integer, allocatable    :: D(:), F(:)

   open (file=input_file, newunit=In)
      read (In, *) N
      allocate (A(N))
      read (In, *) A
      allocate (B(N))
      read (In, *) B
      allocate (C(N))
      read (In, *) C
   close (In)

   
    D = min(A, B, C)
    F = max(A, B, C)
    
    if(all(D.eq.F)) then
       write(*,*) 'D=F'
    else
       write(*,*) 'D/=F'
    end if

   open (file=output_file, newunit=Out)
     write (Out, *) A
     write (Out, *) B
     write (Out, *) C
     write (Out, *) D
     write (Out, *) F
   close (Out)

end program lab_5_v23
