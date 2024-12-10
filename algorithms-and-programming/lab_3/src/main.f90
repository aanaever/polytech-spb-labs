program lab_3_v23
   use Environment
   
   implicit none
   character(*), parameter  :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                  :: In = 0, Out = 0, N = 0
   integer                  :: i = 1
   integer, allocatable     :: arr(:), arr2(:)

   open (file=input_file, newunit=In)
      read (In, *) N
      allocate (arr(N))
      read (In, *) arr
   close (In)

 arr2 =[sum(arr(i:i+2)), N, 3]


  ! do i = 1, N, 3
   !  x = (sum(arr(i: i+2)))
    !arr2 = [(sum(arr(i: i+2)))]
    ! write(*,*) arr2
    ! arr2(i)=x
  !  write (*,*) x 
  ! end do
   
   open (file=output_file, newunit=Out)
    write (Out, *) arr
    write (Out, *) arr2
  close (Out)

end program lab_3_v23
