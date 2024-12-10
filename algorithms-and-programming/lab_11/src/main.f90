program lab_11_v7_37
use Environment

implicit none
character(*), parameter   :: input_file = "../data/input.txt", output_file = "output.txt"
integer                   :: In = 0, Out = 0, M = 0, O = 0, P = 0, Q = 0, i = 0, j = 0
character(:), allocatable :: fmt
real(R_), allocatable     :: A(:), C(:, :, :)

open (file=input_file, newunit=In)
   read (In, *) M
   allocate (A(M))
   read (In, *) A
   read (In, *) O, P, Q
   allocate (C(O, P, Q))
close (In)

open (file=output_file, newunit=Out)
   write (Out, *) A
close (Out)

C = reshape(A, ([O, P, Q]))

open(file=output_file, newunit=Out)
write(Out, '(/,"3D-array:")')
fmt = "("//O//"("//P//"f7.2,/))"
write(Out, fmt) ((C(i, :,j), i = 1, O), j = 1, Q)

end program lab_11_v7_37
