program lab_7_v13
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, N = 0, i = 0, min_str = 0, min_ind =0, max_ind = 0, max_el = 0, min_el = 0
   integer, allocatable    :: Z(:, :)

   open (file=input_file, newunit=In)
   read (In, *) N
   allocate (Z(N, N))
   read(In, *) (Z(i, :), i = 1, N)
   close (In)

 
min_str = MinLoc((Sum(Z,dim = 2)), dim = 1)
min_ind = MinLoc(Z(min_str,:),dim = 1)
max_ind = MaxLoc(Z(min_str,:), dim = 1)
max_el = Z(min_str, max_ind)
min_el = Z(min_str, min_ind)
 
open(file=output_file, newunit=Out)
 write(Out, '('//N//'i3)') (Z(i, :), i = 1, N)
 write(Out, *)'The minimum amount is equal to in the line:', min_str
 write(Out, *)'The maximum element of this line:'
 write(Out, *) Z(min_str, max_ind) 
 write(Out, *) 'and its index', max_ind
 write(Out, *)'The minimum element of this line :' 
 write(Out, *) Z(min_str, min_ind) 
 write(Out, *) 'and its index',  min_ind
 close (Out)

end program lab_7_v13
